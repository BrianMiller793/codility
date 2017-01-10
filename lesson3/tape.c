#include <stdio.h>
#include <stdlib.h>
#include <values.h>

/*
 - Author:  Brian Miller
 - Comment: Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.
*/

int solution(int A[], int N);

void main(void)
{
    int A[] = {1,2,3,4,5};
    int N = sizeof(A)/sizeof(int);

    printf("%i\n", solution(A,N));
}


int solution(int A[], int N)
{
    long int sum1 = 0;
    long int sum2 = 0;
    int diff = 0;

    if (A == NULL || N < 2)
        return -1;

    for (int i=0; i<N; i++)
        sum1 += A[i];

    diff = MAXINT;
    for (int i=0; i<N-1; i++)
    {
        int tdiff;
        sum2 += A[i];
        sum1 -= A[i];
        tdiff = (int)labs(sum1 - sum2);
        diff = tdiff < diff ? tdiff : diff;
    }

    return diff;
}
