#include <stdio.h>

/*
 - Author:  Brian Miller
 - Comment: Find the missing element in a given permutation.
*/

int solution(int A[], int N);

void main(void)
{
    int A[] = {2,3,1,5};
    int N = sizeof(A)/sizeof(int);
    printf("%i\n", solution(A,N));
}

int solution(int A[], int N)
{
    long int s1 = 0L;
    long int s2 = 0L;

    for (int i=0; i<N; i++)
    {
        s1 += A[i];
        s2 += i+1;
    }

    s2 += N+1;

    return (int)(s2 - s1);
}
