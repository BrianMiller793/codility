/*
 - Author:  Brian Miller
 - Comment: Find the minimal average of any slice containing
 -          at least two elements.
*/

#include <stdio.h>
#include <values.h>

int solution(int A[], int N);

void main(void)
{
    int A[] = {4,2,2,5,1,5,8,1,1};
    int N = sizeof(A)/sizeof(int);

    printf("%i\n", solution(A,N));
}

int solution(int A[], int N)
{
    int position = 0;
    float minimum = 100000;
    for (int i=0; i<N-1; i++)
    {
        float avg2 = ((float)A[i] + (float)A[i+1]) / 2;
        if (i < N-2)
        {
            float avg3 = ((float)A[i] + (float)A[i+1] + (float)A[i+2]) / 3;
            float min = avg3 < avg2 ? avg3 : avg2;
            if (min < minimum)
            {
                minimum = min;
                position = i;
            }
        }
        else
        {
            if (avg2 < minimum)
            {
                minimum = avg2;
                position = i;
            }
        }
    }

    return position;
}
