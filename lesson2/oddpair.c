#include <stdio.h>

/*
 - Author:  Brian Miller
 - Comment: Find value that occurs in odd number of elements.
*/

int solution(int A[], int N);

void main(void)
{
    int A[] = {9,3,9,3,9,7,9};
    int N = sizeof(A)/sizeof(int);
    printf("%i\n", solution(A, N));
}

int solution(int A[], int N)
{
    int r = 0;

    for (int i=0; i<N; i++)
    {
        r ^= A[i];
    }

    return r;
}
