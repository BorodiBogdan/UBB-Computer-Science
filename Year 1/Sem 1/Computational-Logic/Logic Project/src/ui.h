#include <iostream>
#include <cstring>
#include "number.h"
using namespace std;

//these functions work with the user interface

void Print_Menu(){//we print the menu
    cout << "1. Add Numbers\n";
    cout << "2. Subtract Numbers\n";
    cout << "3. Multiply Numbers\n";
    cout << "4. Divide Numbers\n";
    cout << "5. Convert Number using succesive multiplication and succesive divison\n";
    cout << "6. Convert number using substitution method\n";
    cout << "7. Convert number using rapid conversion(The bases must be the form 2^k, k <= 4)\n";
    cout << "8. Convert using base 10 as an intermediary base\n";
    cout << "9. Exit\n";
}
void readBase(int &arg){//we read the base
    string base;
    cout << "Base: ";
    cin >> base;

    if(base.length() > 2)
        throw invalid_argument("Invalid base\n");//the input is to long, we work with bases <= 16 || >= 2

    if((base[0] == '1' || base[0] == '0') && base.length() == 1)
        throw invalid_argument("Invalid base\n");//Invalid numeration base

    if(base[0] >= '2' && base[0] <= '9' && base.length() == 1){//here it works
        arg = base[0] - '0';
        return;
    }

    if(base[0] == '1' && base[1] >= '0' && base[1] <= '6'){//it works here too
        arg = (base[0] - '0') * 10 + (base[1] - '0');
        return;
    }

    throw invalid_argument("Invalid base\n");//Oops, something went wrong the base is invalid

}

void Read_Option(int &arg){
    //Here we read the option
    //We use string because we want to handle the case when the user inputs a string instead of a number
    string op;
    cout << "Option: ";
    cin >> op;

    if(op.length() > 1)
        throw invalid_argument("Invalid option\n");

    if(op[0] >= '0' && op[0] <= '9')
        arg = op[0] - '0';
    else
        throw invalid_argument("Invalid option\n");
    //in arg we store the base as an integer
}
void Read_Numbers_And_Base(Number &a, Number &b, int &base){
    //read numbers and base for option 1, 2, 3
    readBase(base);
    a.set_base(base);
    b.set_base(base);
    a.Read_Number();
    b.Read_Number();

}
void Compute_Sum(){//we compute the sum
    int base;
    Number a, b;

    Read_Numbers_And_Base(a, b, base);

    Number sum = a + b;

    cout << "The result is:";

    sum.Print_Number();
}
void Compute_Difference(){//we compute the difference
    int base;
    Number a, b;

    Read_Numbers_And_Base(a, b, base);

    Number dif = a - b;

    cout << "The result is:";

    dif.Print_Number();
}
void Compute_Product(){//we compute the product
    int base;
    Number a, b;

    Read_Numbers_And_Base(a, b, base);

    Number mul = a * b;

    cout << "The result is:";

    mul.Print_Number();
}
void Compute_Division(){//we compute the division
    int base;
    string digit;//we read it as a string to handle the possible errors
    readBase(base);
    Number a(base);
    a.Read_Number();

    cout << "digit: ";
    cin >> digit;
                
    int d = 1;

    //we check the digit for bases > 10 and convert to an integer
    if(digit[0] >= '1' && digit[0] <= '9')
        d = digit[0] - '0';
    else if(digit[0] >= 'A' && digit[0] <= 'Z')
        d = digit[0] - 'A' + 10;
    else if(digit[0] >= 'a' && digit[0] <= 'z')
        d = digit[0] - 'a' + 10;
    else
        throw invalid_argument("Invalid digit\n");

    Number div = a / d;

    cout << "The result is:";

    div.Print_Number();
}

void Compute_Conversion_Using_Succesive_Multiplication_And_Succesive_Division(){
    //we compute the conversion using succesive multiplication and succesive division
    int base;
    readBase(base);

    int newBase;
    cout << "New ";
    readBase(newBase);

    Number a(base);
    a.Read_Number();

    a.Convert_Using_Succesive_Multiplication_And_Succesive_Division(newBase);

    cout << "The result is: ";
    a.Print_Number();
}
void Compute_Conversion_Using_Substitution_Method(){
    //we compute the conversion using substitution method
    int base;
    readBase(base);

    int newBase;
    cout << "New ";
    readBase(newBase);

    Number a(base);
    a.Read_Number();

    a.Convert_Using_Substitution_Method(newBase);
    cout << "The result is:";
    a.Print_Number();
}
void Compute_Using_Rapid_Conversion(){
    //we compute the conversion using rapid conversion
    int base;
    readBase(base);

    int newBase;
    cout << "New ";
    readBase(newBase);

    Number a(base);
    a.Read_Number();

    a.Convert_Using_Rapid_Conversion(newBase);
    cout << "The result is:";
    a.Print_Number();

}
void Compute_Using_Base_10_As_An_Intermediary_Base(){
    //we compute the conversion using base 10 as an intermediary base
    int base;
    readBase(base);

    int newBase;
    cout << "New ";
    readBase(newBase);
    Number a(base);
    a.Read_Number();

    a.Convert_Using_Base_10_as_an_intermediary_base(newBase);
}