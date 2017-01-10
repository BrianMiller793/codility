#include <stdio.h>

/*
 - Author:  Brian Miller
 - Comment: Rotate an array to the right by a given number of steps.
*/

int* solution(int A[], int N, int K);

void main(void)
{
    int a[] = {1,9,7,3,8,2,5,6};
    int *b;
    int as = sizeof(a)/sizeof(int);
    b = solution(a, as, 0);
    for (int i=0; i<as; i++)
        printf("%i ", b[i]);
    printf("\n");
}

int* solution(int A[], int N, int K)
{
    if (A == NULL || N <= 1 || K < 1)
        return A;

    for (int j=0; j<K; j++)
    {
        int s = A[N-1];
        for (int i=N-1; i>0; i--)
        {
            A[i] = A[i-1];
        }
        A[0] = s;
    }
    return A;
}
