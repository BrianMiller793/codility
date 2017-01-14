/*
 - Author:  Brian Miller
 - Comment: Determine whether a given string of parentheses is properly nested.
 -          Includes [] and {}
*/

#include <stdio.h>

int depth;
char stack[200002];
void push(char c)
{
    if (depth > sizeof(stack))
        return;
    stack[depth] = c;
    depth++;
}
char pop()
{
    if (depth == 0)
        return 0;
    depth--;
    return stack[depth];
}
int solution(char *S)
{
    char c;
    depth = 0;

    while (*S != 0)
    {
        switch (*S)
        {
            case '(':
            case '[':
            case '{':
                push(*S);
                break;
            default:
                c = pop();
                switch (*S)
                {
                    case ')':
                       if (c != '(') return 0; 
                       break;
                    case ']':
                       if (c != '[') return 0; 
                       break;
                    case '}':
                       if (c != '{') return 0; 
                       break;
                }
        }
        S++;
    }

    return depth == 0;
}

void main(void)
{
    char *S = "{}()[]{}";
    printf("%i\n", solution(S));
}

