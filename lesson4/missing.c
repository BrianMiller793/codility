#include <stdio.h>
#include <stdlib.h>
#include <values.h>

/*
 - Author:  Brian Miller
 - Comment: Find the minimal positive integer not occurring in a given sequence.
*/

int solution(int A[], int N);

void main(void)
{
    int A[] = {-1,-3,-6,-4,1,2};
    int N = sizeof(A) / sizeof(int);

    printf("%i\n", solution(A,N));
}

int compare(const void *a, const void *b)
{
    if (*(int*)a <  *(int*)b) return -1;
    if (*(int*)a == *(int*)b) return  0;
    return  1;
}

int solution(int A[], int N)
{
    if (A == NULL || N < 1)
        return 0;

    qsort(A, N, sizeof(int), compare);

    int i = 0;
    int j = 1;
    while (i < N)
    {
        if (A[i] > 0)
        {
            if (A[i] != j)
                return j;
            if (A[i] == A[i+1])
            {
                i++;
                continue;
            }

            j++;
        }

        i++;
    }

    return j;
}
