/*
 - Author:  Brian Miller
 - Comment: Compute the number of integers divisible by k in range [a..b].
*/

#include <stdio.h>

int solution(int A, int B, int K);

void main(void)
{
    printf("%i\n", solution(6,11,2));
}

int solution(int A, int B, int K)
{
    return (B / K) - (A / K) + (A % K ? 0 : 1);
}
