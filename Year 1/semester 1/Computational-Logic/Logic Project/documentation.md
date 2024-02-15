# Welcome to Operations and Conversions

This is the documentation for the project Operations and Conversion in different bases, made by Borodi Bogdan.
## Description of the application implementation
  The project implements the following:
  - Addition of two numbers in a base b
  - Subtraction of two numbers in a base b
  - Multiplication of two numbers in a base b by a digit
  - Division of two numbers in a base b by a digit
  - Rapid conversions (executable form) between two bases p,q 
  - Algorithm for the method of successive divisions  
  - Algorithm for the substitution method 
  - Algorithm for conversion using 10 as an intermediate base 

  The project has also some extra functionalities like:
  - Algorithm for the method of successive multiplications
  - Addition, Subtraction, Multiplication and Division for numbers with a fractionary part
  - Conversion algorithms for subunitary for numbers with a fractionary part
  - The listed  methods work also for bases 11, 12, 13, 14, 15 not just for 2 .. 10 and 16

For implementing all these functionalities we built a class Number that retains informations about the base of the number, digits of the number stored in a vector and where we need to place the comma in case the number is subunitary.

```
typedef vector<int> BigNumber;

class Number{
  public:
    setters and getter
    ..
    some functions
    ...
    
  private:
    BigNumber DigitValue;//Here we store the digits values
    int PositionOfTheSeparator = 0;//where we put the comma, to separate the fractionary part from the integer part
    int base;//the base we are working in

    ...

    some functions
}

```

## Project layout

        src/     // The source folder.
        main.cpp  // The source code file that you have to run in order to execute the application.
        ui.h   // The source code file that has the part of the user interaction. It proccesses the input and performs the operations.
        number.h // The source code file that has the Number class neccessary to perform these operations. The most important one are documented below.

## Starting the project

In order to start this project, you have to run `main.cpp` or open the `main.exe` file

## Functions For Conversions

### 1) `Convert_Using_Substitution_Method`

### Statement: Given a number in base _b_, convert it to base _h_ using substitution method

#### Usage

-This method is useful when we convert from a greater base to a smaller one.

```
void Convert_Using_Substitution_Method(int new_base){
  if(new_base < base)
  /*
    The method is purposefully implemented as follows to work also with subunitary numbers

    We use the exact definition of the substitution method algorithm and represent all the digits into the destination base and then we compute the according sum in the destination base 
  */
    throw invalid_argument("New base must be greater than the current base");//we handel the exception

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

  *this = result;//we change the number
}

```

### 2) `Succesive_Division`

### Statement: Given a number in base _b_, convert it to base _h_ using successive division method

#### Usage

- This method is useful when we convert from a smaller base to a greater base, because we have to perform only multiplications and divisions by one digit.

```


map <int, string> hexa = {{10, "A"}, {11, "B"}, {12, "C"}, {13, "D"}, {14, "E"}, {15, "F"}};//this helps us to convert a number to bases > 10

  string Succesive_Division(Number a, int new_base){
    //we use this function to convert a number to another base using succesive division
    //we use it just for the integer part
    string resulting_number = "";//here we store the result

    while(a.to_str() != "0"){
      int carry = a.Divide_By_One_Digit(new_base);
      //we use an already implemented method to make things easier

      if(carry >= 10)
        resulting_number += hexa[carry];
      else
      resulting_number += to_string(carry);
    }
    reverse(resulting_number.begin(), resulting_number.end());//we take the reminders in reverse order
        
    return resulting_number;
}
```

### 3)  `Convert_Using_Base_10_as_an_intermediary_base`

### Statement: Given a number in base _b_, convert it to base 10, and after that, convert it to base _h_

#### Usage

- This method requires multiple steps, but it is easier to work with because we can perform operations in base 10, that are easier to compute.

```
void Convert_Using_Base_10_as_an_intermediary_base(int new_base){
  //There is not to much to explain here
  //We convert the number to base 10 and then to the desired base
  //We look dor the best method to convert between bases and apply it
  if(base < 10)
    Convert_Using_Substitution_Method(10);
  else      Convert_Using_Succesive_Multiplication_And_Succesive_Division(10);

  cout << "Intermediate base 10 result: " << to_str() << "\n";//we display the result in the console

  if(new_base > 10)
    Convert_Using_Substitution_Method(new_base);
  else  Convert_Using_Succesive_Multiplication_And_Succesive_Division(new_base);

  cout << "Final base " << new_base << " result: " << to_str() << "\n";
}
```
### 4) `Rapid_Conversion_To_Base_2`

### Statement: Given a number in base _h_, convert it to base 2, where h is from the set {4, 8, 16}

#### Usage

- This method uses an already implementented algorithm succesive division and multiplications, for converting a group of digits from base q in base 2. 
  We could also implement a map to retain the corresponding result when converting the digit q from base b to base 2

```
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
```

### 5) `Rapid_Conversion_To_Desired_Base`

### Statement: Given a number in base 2, convert it to base _h_, where h is from the set {4, 8, 16}

#### Usage

-  This method uses an already implementented method (substitution method), for converting a group of digits from base 2 in base q. 
  We could also implement a map to retain the corresponding result when converting the digits  from base 2 to base q 

```

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
```
## Functions For Operations

### 1) `Add`

### Statement: Given two numbers in base _p_, find the sum of them.

```
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

```

### 2) `Subtract`

### Statement: Given two numbers in base _p_, find the difference of them.

```
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
    --DigitValue[0]//Unnecesarry 0's

  DigitValue[0] = max(DigitValue[0],      PositionOfTheSeparator + 1);
}
```

### 3) `Multiply_By_One_Digit`

### Statement: Given a numbers _nr_ in base _p_, and a digit _dig_, in the same base, multiply _nr_ with _dig_.

```
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
```

### 4) `Divide_By_One_Digit`

### Statement: Given a numbers _nr_ in base _p_, and a digit _dig_, in the same base, divide _nr_ to _dig_, and display the result of the division and the remainder .

```
int Divide_By_One_Digit(int digit){
  int carry = 0;

  for(int i = DigitValue[0]; i >= 1; --i){
    DigitValue[i] += carry * base;
    carry = DigitValue[i] % digit;
    DigitValue[i] /= digit;
  }

  while(DigitValue[0] > 1 && DigitValue[DigitValue[0]] == 0)
    --DigitValue[0];

  return carry;//we need the carry to find the fractionary part
  //for more details consult number.h
}
```

## Extra informations:
- The project uses these methods to build an app that can also work with subunitary numbers
- If you want to see the implementation for the Number class that can perform conversions and operations through any base <= 16 consult the source code of Number.h
- The app works for all bases >= 2 and <= 16
