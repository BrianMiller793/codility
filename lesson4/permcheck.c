#include <stdio.h>
#include <stdlib.h>

/*
 - Author:  Brian Miller
 - Comment: Check whether array A is a permutation.
*/

int solution(int A[], int N);

void main(void)
{
    int A[] = {1,2,3,4,7,4,7,8,9,10};
    int N = sizeof(A)/sizeof(int);

    printf("%i\n", solution(A, N));
}

int solution(int A[], int N)
{
    long int sum1 = 0;
    long int sum2 = 0;
    int *checks = calloc(N, sizeof(int));

    if (A == NULL || N < 1 || checks == NULL)
        return -1;

    for (int i=0; i<N; i++)
    {
        if (A[i] < 1 || A[i] > N)
            return 0;
        if (N > 1 && A[i] == A[(i+1) % N])
            return 0;
        checks[A[i] - 1]++;
        if (checks[A[i] - 1] != 1)
            return 0;

        sum1 += A[i];
        sum2 += i+1;
    }

    return sum1 == sum2;
}
