/*
 - Author:  Brian Miller
 - Comment: Maximize A[P] * A[Q] * A[R] for any triplet (P, Q, R).
*/

#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N);

/*
Test Data
    int A[] = {-3,1,2,-2,5,6};
*/

void main(void)
{
    int A[] = {-5,5,-5,4};
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

    int head = A[0] * A[1] * A[N-1];
    int tail = A[N-3] * A[N-2] * A[N-1];
    return head > tail ? head : tail;
}
