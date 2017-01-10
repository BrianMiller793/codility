/*
 - Author:  Brian Miller
 - Comment: Count the number of passing cars on the road.
*/

#include <stdio.h>

int solution(int A[], int N);

void main(void)
{
    int A[] = {0,1,0,1,1};
    int N = sizeof(A)/sizeof(int);

    printf("%i\n", solution(A,N));
}

int solution(int A[], int N)
{
    long int pairinc = 0;
    long int pairs = 0;

    if (A == NULL || N < 1)
        return -1;

    for (int i=0; i<N; i++)
    {
        if (A[i] == 0)
            pairinc++;
        else
            pairs += pairinc;
    }

    return pairs <= 1000000000L ? (int)pairs : -1;
}
