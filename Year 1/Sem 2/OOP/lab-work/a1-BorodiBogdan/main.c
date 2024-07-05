#include <stdio.h>

int **test()
{
    int *p;
    for (int i = 0; i <= 5; ++i)
        *(p + i) = i;

    int **result;
    *result = p; // ponints to p
    int length = 5;
    *(result + 1) = &length;
}
int main()
{

    int **answer = test();
    int *length = *(answer + 1);

    printf("%d", *length);

    return 0;
}