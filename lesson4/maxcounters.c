/*
 - Author:  Brian Miller
 - Comment: Calculate the values of counters after applying all
 -          alternating operations: increase counter by 1; set value of
 -          all counters to current maximum.
 -
 -          While there are possible improvements, they don't pass testing
 -          for random data.  This solution is 0.01 seconds slower than
 -          what is allowed for Codility's tests.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Results {
    int *C;
    int L;
};

struct Results solution(int N, int A[], int M);

void printArray(int A[], int N)
{
    for (int i=0; i<N; i++)
        printf("%02i ", A[i]);
    printf("\n");
}

/*
Test Cases:
    int A[] = {1,3,4,4,6,1,4,4};
    int N = 5;
    int A[] = {6,6,6,6,6,6};
    int N = 5;
*/

void main(void)
{
    int N = 10;
    int A[20];
    int M = sizeof(A)/sizeof(int);
    int numMax = 0;
    for (int i=0; i<M; i++)
    {
        A[i] = rand() % (N+1) +1;
        numMax = A[i] > N ? numMax+1 : numMax;
    }

    struct Results answer = solution(N, A, M);
    printArray(A, M);
    printArray(answer.C, answer.L);
}

struct Results solution(int N, int A[], int M)
{
    int max = 0;
    int newmax = 0;
    struct Results answer;
    answer.C = calloc(N, sizeof(int));
    answer.L = N;

    if (answer.C == NULL || N < 1 || A == NULL || M < 1)
        return answer;

    for (int i=0; i<M; i++)
    {
        if (A[i] > N && newmax == 1)
        {
            newmax = 0;
            for (int j=0; j<N; j++)
                answer.C[j] = max;
        } else if (A[i] <= N) {
            int t = ++answer.C[A[i]-1];
            if (t > max)
            {
                max = t;
                newmax = 1;
            }
        }
    }

    return answer;
}
