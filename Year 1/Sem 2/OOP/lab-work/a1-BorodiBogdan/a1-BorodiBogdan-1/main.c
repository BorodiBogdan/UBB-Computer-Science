#include <stdio.h>

struct pair
{
    int left, right;
};

long long XtoN(int x, int n)
{
    /*
        We compute x^n using rapid multiplication
        Complexity O(log2(n))
    */
    if (n == 0)
        return 1;

    if (n % 2 == 0)
    {
        long long p = XtoN(x, n / 2);
        return p * p;
    }
    else
        return 1LL * x * XtoN(x, n - 1);
}
struct pair longest_continuous_subsequence_with_contrary_signs(int V[], int n)
{
    /*
        We find the longest continuous subsequence with contrary sign
        if the sign of the current element is different then the sign of the last element
        we increment the length by 1, else we start a new subsequence
        the longestest subsequence formed is the result
    */
    struct pair indicators = {1, 1};
    int counter = 1, max_length = 1, left = 1;

    for (int i = 2; i <= n; ++i)
    {
        if ((V[i] < 0 && V[i - 1] > 0) || (V[i - 1] < 0 && V[i] > 0)) // we check if we have opposite signs
            counter++;
        else
        {
            counter = 1;
            left = i;
        }

        if (counter > max_length)
        {
            max_length = counter;
            indicators.left = left;
            indicators.right = i;
        }
    }

    return indicators;
}
// UI Section
void readVector(int V[], int *n)
{
    /*/
        V -> vector
        n -> length of vector
    */
    printf("Enter the length: ");
    scanf("%d", n);

    for (int i = 1; i <= *n; ++i)
        scanf("%d", &V[i]);
}
void displayVector(int V[], int left, int right)
{
    /*
        V -> vector
        left -> left index of the displayed sequence
        right -> right index of the displayed sequence
    */
    printf("The vector is: ");

    for (int i = left; i <= right; ++i)
        printf("%d ", V[i]);

    printf("\n");
}
void print_menu()
{
    // we are just printing our menu
    printf("Choose an option: \n");
    printf("1.Read a vector of numbers from the console\n");
    printf("2.Display x^n\n");
    printf("3.Find the longest continuous subsequence such that any two consecutive elements have contrary signs\n");
    printf("4.Display vector.\n");
    printf("5.Exit\n");
}
void DisplayXtoN()
{
    // Here we solve task 1
    int number, power;
    printf("Enter x: ");
    scanf("%d", &number);
    printf("Enter n: ");
    scanf("%d", &power);

    printf("The result is: %lli\n", XtoN(number, power));
}
int main()
{

    int length = 0, V[1001];

    print_menu();

    while (1 > 0) // infinite loop
    {
        int choose_option = 1;
        int read_vector = 2;
        int display_x_TO_n = 3;
        int display_vector = 4;
        int exit = 5;
        int option;

        printf("Choose option: ");
        scanf("%d", &option);

        if (option == choose_option)
            readVector(V, &length);
        else if (option == read_vector)
            DisplayXtoN();
        else if (option == display_x_TO_n)
        {
            if (length == 0)
            {
                printf("You must read the vector first!!\n");
                continue;
            }
            struct pair longest_subsequence_indices = longest_continuous_subsequence_with_contrary_signs(V, length);
            printf("The longest continuous subsequence such that any two consecutive elements have contrary signs.\n");
            displayVector(V, longest_subsequence_indices.left, longest_subsequence_indices.right);
        }
        else if (option == display_vector)
        {
            if (length == 0)
            {
                printf("You must read the vector first!!\n");
                continue;
            }

            displayVector(V, 1, length);
        }
        else if (option == exit)
            return 0;
        else
            printf("Invalid option!\n");
    }

    return 0;
}