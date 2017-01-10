#include <stdio.h>

/*
 - Author:  Brian Miller
 - Comment: Count minimal number of jumps from position X to Y.
*/

int solution(int X, int Y, int D);

void main(void)
{
    printf("%i\n", solution(10,79,10));
}

int solution(int X, int Y, int D)
{
    int J = (Y - X) / D;
    int R = (Y - X) % D;

    return R ? J+1 : J;
}
