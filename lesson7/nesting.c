/*
 - Author:  Brian Miller
 - Comment: Determine whether given string of parentheses is properly nested.
*/

#include <stdio.h>

int solution(char *S);

void main()
{
    char *S = ")";
    printf("%i\n", solution(S));
}


int solution(char *S)
{
    int depth = 0;

    while (*S != 0x00)
    {
        switch (*S)
        {
            case '(':
                depth++;
                break;
            case ')':
                depth--;
                if (depth < 0)
                    return 0;
                break;
        }
        S++;
    }

    return depth == 0;
}
