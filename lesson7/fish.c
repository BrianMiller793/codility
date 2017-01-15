/*
 - Auhtor:  Brian Miller
 - Comment: N voracious fish are moving along a river.
 -          Calculate how many fish are alive.
*/

#include <stdio.h>

int solution(int A[], int B[], int N);

void main()
{
    int A[] = {4,3,2,1,5};
    int B[] = {0,1,0,0,0};
    //int A[] = {9,8,2,1,3};
    //int B[] = {1,1,1,1,0};
    int N = sizeof(A)/sizeof(int);

    printf("%i\n", solution(A,B,N));
}

#define STACKSIZE 100001
typedef struct IntStack
{
    int depth;
    int stack[STACKSIZE];
} IntStack;
void push(IntStack *s, int c)
{
    if (s->depth > STACKSIZE)
        return;
    s->stack[s->depth] = c;
    s->depth++;
}
int pop(IntStack *s)
{
    if (s->depth == 0)
        return 0;
    s->depth--;
    return s->stack[s->depth];
}
int peek(IntStack *s)
{
    if (s->depth > 0)
        return s->stack[s->depth-1];
    else
        return 0;
}
int isempty(IntStack *s)
{
    return s->depth == 0;
}
int init(IntStack *s)
{
    s->depth = 0;
}

#define UPSTREAM   0
#define DOWNSTREAM 1
int solution(int A[], int B[], int N)
{
    IntStack stack;
    init(&stack);
    int alive = N;

    for (int i=0; i<N; i++)
    {
        if (B[i] == UPSTREAM)
        {
            while (!isempty(&stack) && A[i] > peek(&stack))
            {
                alive--;
                pop(&stack);
            }
            if (!isempty(&stack) && A[i] < peek(&stack))
                alive--;
        }
        else
        {
            push(&stack, A[i]);
        }
    }

    return alive;
}

