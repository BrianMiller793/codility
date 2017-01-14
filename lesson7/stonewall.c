/*
 - Author:  Brian Miller
 - Comment: Cover "Manhattan skyline" using the minimum number of rectangles.
*/

#include <stdio.h>

int solution(int H[], int N);

void main(void)
{
    int H[] = {8,7,7,8,9,4,5,8,8};
    int N = sizeof(H)/sizeof(int);

    printf("%i\n", solution(H,N));
}

int depth;
int stack[100002];
void push(int c)
{
    if (depth > sizeof(stack))
        return;
    stack[depth] = c;
    depth++;
}
int pop()
{
    if (depth == 0)
        return -1;
    depth--;
    return stack[depth];
}
int solution(int H[], int N)
{
    int blocks = 0;
    int height = 0;

    for (int i=0; i<N; i++)
    {
        while (H[i] < height)
        {
            height -= pop();
        }
        if (H[i] > height)
        {
            blocks++;
            push(H[i] - height);
            height = H[i];
        }
    }

    return blocks;
}
