#include <fstream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

ifstream fin("input6.in");
ofstream fout("output6.out");


int V[6][6];
int Result_Vector[6], ScalarVector[6];

void Print(int n){//Here we print the base
    fout << "( ";
    for(int i = 1; i <= n; ++i){
        fout << "( ";

        for(int j = 1; j <= n; ++j){
            fout << V[i][j];

            if(j != n)
                fout << ", ";
        }
        
        fout << ") ";
    }
    fout << " )";
    fout << "\n";
}

bool Verify_if_Linear_Independent(int n, int index){//we verify if we can add the new vector
    int k = 0;
    bool CheckIfCombination = 1;

    for(int mask = 0; mask < (1 << n); mask++){//we represent the scalars using a bit mask(we can only hacve 0's and 1's)

        int mask_copy = mask;
        k = 0;


        for(int i = 1; i <= n; ++i)
            Result_Vector[i] = ScalarVector[i] = 0;//we empty the vectors to reconstruct them

        while(mask_copy > 0){
            ScalarVector[++k] = (mask_copy & 1);
            mask_copy = mask_copy / 2;//here we add the scalars(0 or 1)
        }

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= index - 1; ++j)
                Result_Vector[i] += ScalarVector[j] * V[j][i];//in the result vector we store c1*v1 + .... + cn*vn

        bool eZero = 1;

        bool CheckIdentity = 1;

        for(int i = 1; i <= n; ++i)
            if(Result_Vector[i] % 2 != V[index][i])
                CheckIdentity = 0;

        if(CheckIdentity == 1)//the veector is a linear combination of the vectors added previosly
            return 0;//we do not add them

    }
    return CheckIfCombination;//return if it' s ok
}

void GenerateAllVectorsOfLengthN(int n, int k, int index){

        if(k <= n){
            for(int i = 0; i <= 1; ++i){
                V[index][k] = i;
                GenerateAllVectorsOfLengthN(n, k + 1, index);//generate all vectors in Z2
            }
        }
        else
            if(k == n + 1 && Verify_if_Linear_Independent(n, index)){
                
                if(index < n){
                    GenerateAllVectorsOfLengthN(n ,1, index + 1);//we go and generate another vector
                }
                else
                    Print(n);//it's ok, so we can print the answer
            }

}
unsigned long long number_of_basis(int n){//here we calculate the number of bases
    unsigned long long nrOfbases = 1, start_pow = 1ULL, power = 1;

    start_pow = start_pow << n;
    while (start_pow > power)
    {
        nrOfbases *= start_pow - power;
        power <<= 1;
    }

    return nrOfbases;
}

int main() {
    int n;

    fin >> n;
    fout << "The number of bases of the vector space (Z2)^2 over Z2 is " << number_of_basis(n) << "\n";

    if(n <= 4 && n >= 0)
        GenerateAllVectorsOfLengthN(n, 1, 1);//solving the problem for the chosen input
    
    return 0;
}