/*
 - Author:  Brian Miller
 - Comment: Compute number of distinct values in an array.
*/

#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N);

void main(void)
{
    int A[] = {2,1,1,2,3,1};
    int N = sizeof(A)/sizeof(int);

    printf("%i\n", solution(A, N));
}

int compare(const void *a, const void *b)
{
    if (*(int*)a <  *(int*)b) return -1;
    if (*(int*)a == *(int*)b) return  0;
    return  1;
}

int solution(int A[], int N)
{
    int dup = 0;

    qsort(A, N, sizeof(int), compare);

    for (int i=1; i<N; i++)
    {
        if (A[i-1] == A[i])
            dup++;
    }

    return N - dup;
}
