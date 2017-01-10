#include <stdio.h>

/*
 - Author:  Brian Miller
 - Comment: Find longest sequence of zeros in binary representation
 -          of an integer.
*/

int solution(int);

void main()
{
    int testVal[] = { 1, 0, 0x2, 0x5, 0xA, 0x14, 0x12, 0x9, 0x29, 0x25, 0x4D };
    int lenTestVal = sizeof(testVal) / sizeof(int);
    for (int i = 0; i < lenTestVal; i++)
    {
        printf("%x, %i\n", testVal[i], solution(testVal[i]));
    }
}

#define INTLEN (sizeof(int) * 8)
int solution(int N)
{
    int maxGap = 0;
    int gapCount = 0;
    int inGap = 0;
    int prevBit = 0;

    if (N < 1)
        return 0;

    while (N > 0)
    {
        int curBit = N & 0x1;
        if (curBit == 0)
        {
            if (prevBit == 1)
            {
                inGap = 1;
            }

            if (inGap == 1)
            {
                gapCount++;
            }
        }
        else /* curBit == 1 */
        {
            if (inGap == 1)
            {
                inGap = 0;
                if (gapCount > maxGap)
                {
                    maxGap = gapCount;
                }
            }
            gapCount = 0;
        }

        prevBit = curBit;
        N = N >> 1;
    }

    return maxGap;
}
