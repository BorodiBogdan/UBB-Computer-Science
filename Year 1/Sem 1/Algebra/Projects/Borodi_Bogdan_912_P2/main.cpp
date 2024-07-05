#include <fstream>
#include <queue>
#include <cstring>
#include <queue>
using namespace std;
 
ifstream fin("input1.in");
ofstream fout("output1.out");
 
int A[5][5];
int nr(1);
 
bool verify(int A[5][5], int n){
 
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k)
                if(A[A[i][j]][k] != A[i][A[j][k]])
                    return false;
 
    return true;
}
 
void Display(int A[5][5], int n){
    fout << "Associative Table Operation Number: " << nr << "\n";
    nr++;
 
    for(int i = 1; i <= n; ++i, fout << "\n")
        for(int j = 1; j <= n; ++j)
            fout << 'a' << A[i][j] << " ";
 
    fout << "\n";
}
 
void generate_all(int A[5][5], int n, int row, int column){
    for(int i = 1; i <= n; ++i){
        A[row][column] = i;
 
        if(row == n && column == n){
            if(verify(A,n))
                Display(A, n);
        }
        else
            if(column < n)
                generate_all(A, n, row, column + 1);
        else 
            if(column == n && row < n)
                generate_all(A, n, row + 1, 1);
    }
}
 
int main(){
    int n;

    fin >> n;
    
    generate_all(A, n, 1, 1);

    fout << "The number of associative operations on set A = {";

    for(int i = 1; i <= n; ++i){
        fout << "a" << i;

        if(i != n)
            fout << ", ";
    }


    fout << "} " << "is: " << nr - 1;
}