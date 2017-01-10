/*
 - Author:  Brian Miller
 - Comment: Find the earliest time when a frog can jump to the other
 -          side of a river.
 -          I used a bit array to store whether a leaf was present.
 -          For large input data, this compressed and sped up the
 -          solution's O() space and operation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_X         100000
/* Size of byte array */
#define BASIZE(BITS)  ((BITS)/64 + ((BITS)%64 ? 1 : 0))
/* Array byte containing bits */
#define BABYTE(BIT)   ((BIT)/64)
/* Individual bit */
#define BABIT(BIT)    (((uint64_t)1)<<((BIT)%64))
/* Check most significant byte in array if all bits set */
#define BACHECKMSB(N) ((uint64_t)(UINT64_MAX >> (64-((N) % 64))))

int solution(int X, int A[], int N);

void main(void)
{
    int A[] = {1,2,1,4,2,3,5,4};
    int X = 5;
    int N = sizeof(A) / sizeof(int);

    printf("%i\n", solution(X, A, N));
}

int isReady(uint64_t leaves[], int X)
{
    for (int i=0; i<BASIZE(X)-1; i++)
    {
        if (leaves[i] & UINT64_MAX != UINT64_MAX)
            return 0;
    }

    return (leaves[BASIZE(X)-1] & BACHECKMSB(X)) == BACHECKMSB(X);
}

int solution(int X, int A[], int N)
{
    uint64_t *leaves = calloc(BASIZE(MAX_X), sizeof(uint64_t));
    int target = X;
    int doCheck = 0;

    if (leaves == NULL || A == NULL || N < 1 || X < 1)
        return -1;

    for (int i=0; i<N; i++)
    {
        leaves[BABYTE(A[i] - 1)] |= BABIT(A[i]-1);
        doCheck = A[i] == target ? 1 : doCheck;
        if (doCheck == 1)
        {
            if (isReady(leaves, X) == 1)
                return i;
        }
    }

    return -1;
}
