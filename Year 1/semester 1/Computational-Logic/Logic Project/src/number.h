/*
Here we store the number class and all the functions that we need to work with numbers
We implemented a class that can compute the sum, difference, product and division of two numbers in differente bases <= 16
We can also convert a number from a base to another base <= 16
The methods used for conversion are the following:
    - succesive multiplication and succesive division
    - subtitution method
    - rapid conversion
    - base 10 as an intermediary base

We used substitution method and succesive multiplication and succesive division for the recommended cases
    - substitution method for the cases when the destination base is greater than the source base
    - succesive multiplication and succesive division for the cases when the destination base is smaller than the source base

We used rapid conversion for the cases when the bases are powers of 2
We used base 10 as an intermediary base for all cases

For subtraction, the first number must be greater or equal than the second number
*/

#define DIM 10001
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef vector<int> BigNumber;

map <int, string> hexa = {{10, "A"}, {11, "B"}, {12, "C"}, {13, "D"}, {14, "E"}, {15, "F"}};//this helps us to convert a number to bases > 10
map <string, int> hexa_to_int = {{"A", 10}, {"B", 11}, {"C", 12}, {"D", 13}, {"E", 14}, {"F", 15}};//this helps us to convert a number to bases > 10

class Number{
    public:
        //constructors, not to much to be explained here
        Number(){
            PositionOfTheSeparator = 0;
            DigitValue.resize(DIM);
            fill(DigitValue.begin(), DigitValue.end(), 0);
            base = 10;//lets say thats the standard base
        }
        Number(int base){
            if(base > 16)
                throw invalid_argument("Base must be smaller than 16");

            DigitValue.resize(DIM);
            fill(DigitValue.begin(), DigitValue.end(), 0);
            DigitValue[0] = 1;
            this->base = base;
        }
        Number(string number, int base){
            if(base > 16)
                throw invalid_argument("Base must be smaller than 16");
                
            DigitValue.resize(DIM);
            fill(DigitValue.begin(), DigitValue.end(), 0);
            this->base = base;
            Convert_To_Number(number);
            DigitValue[0] = number.length();
        }
        Number(string number, int base, int PositionOfTheSeparator){
            if(base > 16)
                throw invalid_argument("Base must be smaller than 16");

            DigitValue.resize(DIM);
            fill(DigitValue.begin(), DigitValue.end(), 0);
            this->base = base;
            Convert_To_Number(number);
            DigitValue[0] = number.length();
            this->PositionOfTheSeparator = PositionOfTheSeparator;
        }
        Number(BigNumber number, int base, int comma_p){
            if(base > 16)
                throw invalid_argument("Base must be smaller than 16");
            
            DigitValue.resize(DIM);
            fill(DigitValue.begin(), DigitValue.end(), 0);
            this->base = base;
            DigitValue = number;
            PositionOfTheSeparator = comma_p;
        }
        //setters and getters to set and get informations about the number
        int get_length(){
            return DigitValue[0];
        }
        int get_base(){
            return base;
        }
        BigNumber get_number(){
            return DigitValue;
        }
        string get_digit(int pos){
            if(DigitValue[pos] >= 10)
                return hexa[DigitValue[pos]];
            else
                return to_string(DigitValue[pos]);
        }
        //here we can change informations about the number
        void set_base(int base){
            this->base = base;
        }
        void set_number(BigNumber number){
            DigitValue = number;
            DigitValue[0] = number[0];
        }
        void set_length(int len){
            DigitValue[0] = len;
        }
        void set_digit(int pos, int digit){
            DigitValue[pos] = digit;
        }
        string to_str(){//here we convert the number to a string
            //we take each digit and put it in a result string
            string result = "";
            while(DigitValue[0] > 1 && DigitValue[DigitValue[0]] == 0 && DigitValue[0] > PositionOfTheSeparator + 1)
                --DigitValue[0];

            for(int i = DigitValue[0]; i >= 1; --i){
                if(i == PositionOfTheSeparator)
                    result += '.';

                if(DigitValue[i] >= 10)
                    result += hexa[DigitValue[i]];
                else
                    result += DigitValue[i] + '0';
            }
            return result;
        }
        //supra operators
        Number operator * (Number a){//we overload the multiplication operator
            pair <BigNumber, BigNumber> res = decide_comma_pos_and_regulize_numbers(*this, a);
            Number result(res.first, base, max(PositionOfTheSeparator, a.PositionOfTheSeparator));
            Number multiplicator(res.second, base, max(PositionOfTheSeparator, a.PositionOfTheSeparator));
            result.Multiply(multiplicator);//we multiply the numbers
            result.PositionOfTheSeparator = max(PositionOfTheSeparator,a.PositionOfTheSeparator) * 2;
            return result;
        }
        Number operator + (Number a){//we overload the addition operator
            pair <BigNumber, BigNumber> res = decide_comma_pos_and_regulize_numbers(*this, a);
            Number result(res.first, base, max(PositionOfTheSeparator, a.PositionOfTheSeparator));
            Number adder(res.second, base, max(PositionOfTheSeparator, a.PositionOfTheSeparator));
            result.Add(adder);//we add the numbers
            return result;
        }
        Number operator = (Number a){//we overload the assignment operator to copy a number
            PositionOfTheSeparator = a.PositionOfTheSeparator;
            base = a.get_base();
            DigitValue = a.get_number();
            return *this;
        }
        Number operator - (Number a){//we overload the substraction operator
            pair <BigNumber, BigNumber> res = decide_comma_pos_and_regulize_numbers(*this, a);
            Number result(res.first, base, max(PositionOfTheSeparator, a.PositionOfTheSeparator));
            Number subtract_auxiliary_number(res.second, base, max(PositionOfTheSeparator, a.PositionOfTheSeparator));
            result.Subtract(subtract_auxiliary_number);//we subtract the numbers
            return result;
        }
        Number operator / (int a){//we overload the division operator to divide by a digit
            Number result(DigitValue, base, PositionOfTheSeparator);

            if(a == 0)
                throw invalid_argument("Division by 0");//oops, something went wrong
            
            if(a > base)
                throw invalid_argument("must provide a digit smaller than the base");//oops, something went wrong

            result.Divide_By_One_Digit_With_Fractionary_Part(a);//we divide the number by the digit
            return result;
        }
        //function section
        void shift_left(int exp){//helpfull for division and multiplication

            // Here we shift the number left and make 0's at the beginning
            for(int i = get_length() + exp, j = get_length(); i > exp && j >= 1; --i, --j)
                DigitValue[i] = DigitValue[j];
            
            for(int i = 1; i <= exp; ++i)
                DigitValue[i] = 0;

            DigitValue[0] += exp;
        }
        void shift_right(int exp){//helpfull for division 

            //Here we shift the number right and make 0's at the end
            for(int i = 1; i <= get_length() - exp; ++i)
                DigitValue[i] = DigitValue[i + exp];
            
            for(int i = get_length() - exp + 1; i <= get_length(); ++i)
                DigitValue[i] = 0;

            DigitValue[0] -= exp;
        }
        void Add(Number a){
            //Here we add two numbers
            if(a.get_base() != base)
                throw invalid_argument("Bases are not equal");//oops, something went wrong

            int carry = 0, len = max(DigitValue[0], a.get_length());

            //we add each digit and keep the carry
            //we do it as we do it on paper
            for(int i = 1; i <= len; ++i){
                DigitValue[i] += a.get_number()[i] + carry;
                carry = DigitValue[i] / base;
                DigitValue[i] %= base;
            }
            //that's the final length of the number
            DigitValue[0] = max(DigitValue[0], a.get_length());

            if(carry)// in case we have a carry left
                DigitValue[++DigitValue[0]] = carry;
            
            
        }
        void Subtract(Number a){
            //Here we subtract two numbers
            if(Compare_Two_Numbers(*this, a) == false)
                throw invalid_argument("The first number must be greater or equal than the second number");//oops, something went wrong

            if(a.get_base() != base)
                throw invalid_argument("Bases are not equal");//oops, something went wrong

            int carry = 0, len = max(DigitValue[0], a.get_length());

            //we subtract each digit and keep the carry <---> borrow
            //we do it as we do it on paper
            for(int i = 1; i <= len; ++i){
                DigitValue[i] -= a.get_number()[i] + carry;
                carry = 0;
                if(DigitValue[i] < 0)
                    DigitValue[i] += base, carry = 1;
            }

            while(DigitValue[0] > 1 && DigitValue[DigitValue[0]] == 0)
                --DigitValue[0];

            DigitValue[0] = max(DigitValue[0], PositionOfTheSeparator + 1);
        }
        void Multiply_By_One_Digit(int digit){
            //Here we multiply a number by a digit
            int carry = 0;

            //we multiply each digit by the digit and we keep the carry, as we do it on paper
            for(int i = 1; i <= DigitValue[0]; ++i){
                DigitValue[i] = DigitValue[i] * digit + carry;
                carry = DigitValue[i] / base;
                DigitValue[i] %= base;
            }

            while(carry)
                DigitValue[++DigitValue[0]] = carry % base, carry /= base;
        }
        void Multiply(Number a){
            //Here we multiply two numbers

            if(a.get_base() != base)
                throw invalid_argument("Bases are not equal");//oops, something went wrong

            Number b(base), result(base);

            for(int i = 1; i <= a.get_length(); ++i){
                b.set_number(DigitValue);//b is equal to our number
                b.Multiply_By_One_Digit(a.get_number()[i]);//we multiply by each digit of a
                b.shift_left(i - 1);//we shift left to make the product as we do it on papaer
                
                result.Add(b);
            }
            DigitValue = result.get_number();//we update the number
        }
        void Divide_By_One_Digit_With_Fractionary_Part(int digit){
            //Here we divide a number by a digit, and we also have a fractionary part
            int carry = 0;

            for(int i = DigitValue[0]; i >= 1; --i){
                DigitValue[i] += carry * base;
                carry = DigitValue[i] % digit;
                DigitValue[i] /= digit;
            }
            int PRECISION = 20;//how many digits we can add after the comma

            shift_left(PRECISION);//we shift the number left PRECISION times to make space for the fractionary part
            PositionOfTheSeparator += PRECISION;//we update the position of the comma

            for(int i = 1; i <= PRECISION && i <= PositionOfTheSeparator; ++i){//we divide the reminder PRECISION times
                carry *= base;
                DigitValue[PRECISION - i + 1] = carry / digit;
                carry = carry % digit;
            }
            while(DigitValue[0] > 1 && DigitValue[DigitValue[0]] == 0)
                --DigitValue[0];

            int shift_counter = 0;

            while(DigitValue[shift_counter + 1] == 0 || shift_counter < PositionOfTheSeparator - PRECISION)
                shift_counter++;//we have unnecessary 0s, so we shift the number right

            shift_right(shift_counter);    
            PositionOfTheSeparator -= shift_counter;//the position of the comma is updated

            if(DigitValue[0] == PositionOfTheSeparator)//if the integer part is 0
                DigitValue[0]++;
        }
        int Divide_By_One_Digit(int digit){
            int carry = 0;

            for(int i = DigitValue[0]; i >= 1; --i){
                DigitValue[i] += carry * base;
                carry = DigitValue[i] % digit;
                DigitValue[i] /= digit;
            }

            while(DigitValue[0] > 1 && DigitValue[DigitValue[0]] == 0)
                --DigitValue[0];

            return carry;
        }
        void Convert_Using_Succesive_Multiplication_And_Succesive_Division(int new_base){
            //we use this function to convert a number to another base using succesive multiplication and succesive division
            if(new_base == base)
                return;

            if(new_base > base)
                throw invalid_argument("New base must be smaller than the current base");

            pair <string, string> parts_of_number = split_number(to_str()); 

            Number integerPart(parts_of_number.first, base);
            Number fractionaryPart(parts_of_number.second, base);

            string i_part = Succesive_Division(integerPart, new_base);//succesive division for the integer part
            string f_part = Succesive_Multiplication(fractionaryPart, new_base);//succesive multiplication for the fractionary part

            string number = i_part + f_part;//the result
            Number result(number, new_base);

            *this = result;
            PositionOfTheSeparator = f_part.length();//where we put the comma
        }
        void Convert_Using_Substitution_Method(int new_base){
            if(new_base < base)
                throw invalid_argument("New base must be greater than the current base");

            pair <string, string> inf = split_number(to_str());
            string integerPart = inf.first, fractionaryPart = inf.second;
            string number = integerPart + fractionaryPart;
            
            Number base_Pow("1", new_base);//b^n in order to use subtitution method

            string real_base = to_string(base);

            if(base >= 10)
                real_base = hexa[base];//to handle base >= 10

            Number mul(real_base, new_base);
            Number result = Number("0", new_base);

            for(int i = number.length() - 1; i >= 0; --i){   
                Number Auxiliary_Number(to_string(number[i] - '0'), new_base);
                Auxiliary_Number.Multiply(base_Pow);
                result.Add(Auxiliary_Number);
                base_Pow.Multiply(mul);
            }//here we have the number in the correct base, but we supposed it didn t have a fractionary part

            //now we need to divide by the base fractionarypart.length() times

            for(int i = 0; i < fractionaryPart.length(); ++i)
                result.Divide_By_One_Digit_With_Fractionary_Part(base);

            *this = result;
        }
        void Convert_Using_Rapid_Conversion(int new_base){
            if(base != 2 && base != 4 && base != 8 && base != 16)
                throw invalid_argument("Invalid base\n");

            if(new_base != 2 && new_base != 4 && new_base != 8 && new_base != 16)
                throw invalid_argument("Invalid base\n");

            //first part --> here we convert to base 2
            pair <string, string> parts_of_number = split_number(to_str()); 

            string integerPart = parts_of_number.first, fractionaryPart = parts_of_number.second;

            integerPart = Rapid_Conversion_To_Base_2(new_base, integerPart);
            fractionaryPart = Rapid_Conversion_To_Base_2(new_base, fractionaryPart);

            while(fractionaryPart.length() > 0 && fractionaryPart[fractionaryPart.length() - 1] == '0')
                fractionaryPart.erase(fractionaryPart.end() - 1);//we delete unncecessary 0s

            while(integerPart.length() > 0 && integerPart[0] == '0')
                integerPart.erase(integerPart.begin());//we delete unncecessary 0s

            int Separator_Position_For_Result = fractionaryPart.length();

            if(fractionaryPart.length() == 0)
                Separator_Position_For_Result = 0;

            Number result(integerPart + fractionaryPart, 2, Separator_Position_For_Result);//here we have the number converted in base 2

            //second part --> here we convert to the desired base
            //we group the digit in pairs of 1, 2, 3 or 4 depending on the desired base

            parts_of_number = split_number(result.to_str());
            integerPart = parts_of_number.first, fractionaryPart = parts_of_number.second;//we divide the number in integer part and fractionary part
            int power_of_2_base = Find_K_From_2_To_K_Power(new_base);//how many elements in a pair

            if(integerPart.length() % power_of_2_base != 0)
                integerPart = string(power_of_2_base - integerPart.length() % power_of_2_base, '0') + integerPart;//we add 0s to the left if the number of digits is not a multiple of power_of_2_base

            if(fractionaryPart.length() % power_of_2_base != 0)
                fractionaryPart = fractionaryPart + string(power_of_2_base - fractionaryPart.length() % power_of_2_base, '0');//we add 0s to the right if the number of digits is not a multiple of power_of_2_base
            
            //now we can make groups of power_of_2_base digits and convert them to the desired base

            integerPart = Rapid_Conversion_To_Desired_Base(new_base, integerPart);
            fractionaryPart = Rapid_Conversion_To_Desired_Base(new_base, fractionaryPart);
            
            Separator_Position_For_Result = fractionaryPart.length();
            
            Number final_result(integerPart + fractionaryPart, new_base, Separator_Position_For_Result);

            *this = final_result;
        }
        void Convert_Using_Base_10_as_an_intermediary_base(int new_base){
            //There is not to much to explain here
            //We convert the number to base 10 and then to the desired base
            //We look dor the best method to convert between bases and apply it
            if(base < 10)
                Convert_Using_Substitution_Method(10);
            else Convert_Using_Succesive_Multiplication_And_Succesive_Division(10);

            cout << "Intermediate base 10 result: " << to_str() << "\n";

            if(new_base > 10)
                Convert_Using_Substitution_Method(new_base);
            else Convert_Using_Succesive_Multiplication_And_Succesive_Division(new_base);

            cout << "Final base " << new_base << " result: " << to_str() << "\n";
        }
        //ui section
        void Read_Base(){
            cin >> base;
        }
        void Read_Number(){
            string number;

            cout << "Enter the number: ";
            cin >> number;

            for(int i = 0 ; i < number.length(); ++i)
                if(number[i] >= 'a' && number[i] <= 'f')
                    number[i] = number[i] - 'a' + 'A';//we convert all the letters to uppercase

            string integerPart = split_number(number).first;
            string fractionaryPart = split_number(number).second;
            number = integerPart + fractionaryPart;
            Convert_To_Number(number);
        }
        void Print_Number(){
            cout << to_str() << "\n";
        }
    private:
        BigNumber DigitValue;//Here we store the digits values
        int PositionOfTheSeparator = 0;//where we put the comma, to separate the fractionary part from the integer part
        int base;//the base we are working in

        void Convert_To_Number(string number){//we take a string and convert it to a number
            int len = number.length(), mdigit = 0;
            fill(DigitValue.begin(), DigitValue.end(), 0);
            DigitValue[0] = len;

            for(int i = 1; i <= len; ++i){
                int cmp = number[len - i] - '0';//using this we find the value of the biggest digit
                
                if(number[len - i] >= 'A' && number[len -i] <= 'F')
                    cmp = hexa_to_int[to_string(number[len - i])];

                mdigit = max(mdigit, cmp);

                if(number[len - i] >= '0' && number[len - i] <= '9')
                    DigitValue[i] = number[len - i] - '0';
                else if(number[len - i] >= 'A' && number[len -i] <= 'F')
                    DigitValue[i] = hexa_to_int[number.substr(len - i, 1)];
                else throw invalid_argument("Invalid number");//we have a non-digit character
            }
           if(mdigit >= base)//the digit is greater then the base
                throw invalid_argument("Invalid number ");
        }
        string Rapid_Conversion_To_Desired_Base(int new_base, string number){
            //here is the second part of the rapid conversion
            //we take the number in base two and convert it to the desired base
            if(new_base == 2)
                return number;

            string result = "";
            int power_of_2_base = Find_K_From_2_To_K_Power(new_base);

            for(int i = 0; i < number.length(); i += power_of_2_base){
                //we take groups of power_of_2_base digits and convert them to the desired base, power_of_2_base is 1, 2, 3 or 4 depending on the desired base(2^k) 
                string a = number.substr(i, power_of_2_base);

                Number Auxiliary_Number(a, 2);
                Auxiliary_Number.Convert_Using_Substitution_Method(new_base);
                
                string add = Auxiliary_Number.to_str();

                result += add;
            }

            return result;
        }
        string Rapid_Conversion_To_Base_2(int new_base, string number){
            //first part of the rapid conversion
            //we take the number and convert it to base 2
            string result = "";
            int power_of_2_base = Find_K_From_2_To_K_Power(base);

            for(int i = 0; i < number.length(); i++){//we take each digit and convert it to base 2
                string a = number.substr(i, 1);

                Number Auxiliary_Number(a, base);
                //we replace the digit with the correscponding number in base 2
                Auxiliary_Number.Convert_Using_Succesive_Multiplication_And_Succesive_Division(2);
                
                string add = Auxiliary_Number.to_str();

               if(add.length() < power_of_2_base)
                    add = string(power_of_2_base - add.length(), '0') + add;
                result += add;
            }

            return result;
        }
        pair <string, string > split_number(string number){
            //we split the number in integer part and fractionary part
            //we need this function to make multiplication and division easier
            //and also to know where to put the comma when we convert a number to another base
            int pos = number.find('.');
            PositionOfTheSeparator = number.length() - pos - 1;
            string integerPart = number.substr(0, pos);
            string fractionaryPart = number.substr(pos + 1, number.length() - pos - 1);

            if(pos == -1){
                PositionOfTheSeparator = 0;
                fractionaryPart = "";
            }

            return make_pair(integerPart, fractionaryPart);
        }
        pair <BigNumber, BigNumber> decide_comma_pos_and_regulize_numbers(Number a, Number b){
            //we use this function to decide where to put the comma when we make operations with two numbers
            //used when dividing, multiplying in case the comma is not at the same position
            if(a.PositionOfTheSeparator > b.PositionOfTheSeparator)
                b.shift_left(a.PositionOfTheSeparator - b.PositionOfTheSeparator);
            else
                a.shift_left(b.PositionOfTheSeparator - a.PositionOfTheSeparator);

            return make_pair(a.get_number(), b.get_number());
        }
        string Succesive_Division(Number a, int new_base){
            //we use this function to convert a number to another base using succesive division
            //we use it just for the integer part
            string resulting_number = "";//here we store the result

            while(a.to_str() != "0"){
                int carry = a.Divide_By_One_Digit(new_base);

                if(carry >= 10)
                    resulting_number += hexa[carry];
                else
                    resulting_number += to_string(carry);
            }
            reverse(resulting_number.begin(), resulting_number.end());//we take the reminders in reverse order
        
            return resulting_number;
        }
        string Succesive_Multiplication(Number a, int new_base){
            //we use this function to compute the fractionary part of a number using succesive multiplication
            Number multiplicator = a;
            string resulting_number = "";
            int Precision = 0;
            int l = a.get_length();
            
            while(multiplicator.to_str() != "0" && Precision < 10){
                

                multiplicator.Multiply_By_One_Digit(new_base);//we multiply the number by the base

                resulting_number = multiplicator.get_digit(l + 1) + resulting_number;//we take the first digit after the comma

                multiplicator.set_digit(l + 1, 0);//we set it to 0 to repeat the process again
                multiplicator.set_length(l);//the length is l, because we have l digits after the comma

                Precision++;
            }
            while(resulting_number[0] == '0')
                resulting_number.erase(resulting_number.begin());

            reverse(resulting_number.begin(), resulting_number.end());
            return resulting_number;
        }
        bool Compare_Two_Numbers(Number a, Number b){//1 if a >= b, 0 if a < b
            if(a.get_base() != b.get_base())
                throw invalid_argument("Bases are not equal");//oops, something went wrong

            if(a.get_length() != b.get_length())//we compare the length of the numbers
                return a.get_length() > b.get_length();//th longest is the biggest
            
            for(int i = a.get_length(); i >= 1; --i)//we compare each digit
                if(a.get_number()[i] != b.get_number()[i])//if we find a digit that is different <-> biggest digit, biggest number
                    return a.get_number()[i] > b.get_number()[i];
            
            return true;
        }
        int Find_K_From_2_To_K_Power(int n){//this helps us to find how many digits we have in a pair at rapid conversions
            int cnt = -1;

            while(n > 0)
                n /= 2, cnt++;//we divide n by 2 until we get 0

            return cnt;//the number of digits in a pair is cnt if n = 2^ k, cnt will be k
        }
};