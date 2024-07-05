#include <iostream>
#include "ui.h"
using namespace std;

int main(){
    while(true){
        try{
            int Option;

            Print_Menu();//we print the menu
            Read_Option(Option);//we read the desired option
            //here we execute the desired option
            if(Option == 1)
                Compute_Sum();
            if(Option == 2)
                Compute_Difference();
            else if(Option == 3)
                Compute_Product();
            else if(Option == 4)
                Compute_Division();
            else if(Option == 5)
                Compute_Conversion_Using_Succesive_Multiplication_And_Succesive_Division();
            else if(Option == 6)
                Compute_Conversion_Using_Substitution_Method();
            else if(Option == 7)
                Compute_Using_Rapid_Conversion();
            else if(Option == 8)
                Compute_Using_Base_10_As_An_Intermediary_Base();
            else if(Option == 9){
                cout << "Goodbye!\n";
                return 0;
            }
        }
        catch(invalid_argument &e){//Oops, something went wrong
            cout << e.what() << "\n";
        }
    }

 }