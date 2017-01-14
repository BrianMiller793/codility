/*
 - Author:  Brian Miller
 - Comment: Determine whether a triangle can be built from a given set of edges.
*/

#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N);

/*
Test Data
    int A[] = {10,2,5,1,8,20};
*/

void main(void)
{
    int A[] = {10,10,10};
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
    qsort(A, N, sizeof(int), compare);

    for (int i=0; i<N-2; i++)
        if ((long int)A[i] + (long int)A[i+1] > (long int)A[i+2])
            return 1;

    return 0;
}
