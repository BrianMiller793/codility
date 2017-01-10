/*
 - Author:  Brian Miller
 - Comment: Find the minimal nucleotide from a range of sequence DNA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Results {
    int *A;
    int M;
};

struct Results solution(char *S, int P[], int Q[], int M);

void printArrayI(int A[], int L)
{
    for (int i=0; i<L; i++)
    {
        printf("%i ", A[i]);
    }
    printf("\n");
}

/*
Test Data:
    char *S = "CAGCCTA";
    int P[] = {2,5,0};
    int Q[] = {4,5,6};
    char *S = "AGGT";
    int P[] = {0,1,2,3};
    int Q[] = {1,2,3,3};
    char *S = "AACC";
    int P[] = {0,1,2};
    int Q[] = {1,2,3};
    char *S = "AAGGTT";
    int P[] = {0,1,2,3,4};
    int Q[] = {1,2,3,4,5};
*/

void main(void)
{
    char *S = "AACC";
    int P[] = {0,1,2};
    int Q[] = {1,2,3};
    int M = sizeof(P)/sizeof(int);

    struct Results q = solution(S, P, Q, M);
    printArrayI(q.A, q.M);
}

/*
  If you think that the optimal solution can be achieved in under two
  hours using C without seeing this problem before, you are seriously deluded.
  Also, O(N) space limitation is completely bogus.  This uses O(3N), and also
  uses the signed bit as a flag for whether a particular location contains
  the nucleotide.
*/
#define MSB 0x80000000
#define NACG(X,Y) *(nACG + (X)*slen + (Y))
struct Results solution(char *S, int P[], int Q[], int M)
{
               /* A B C D E F G H I J K L M N O P Q R S T */
    char map[] = {0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,3};
    size_t slen = strlen(S);
    int *nACG = calloc(1, slen * 3 * sizeof(int));
    int nSums[] = {0,0,0,0};
    struct Results r;
    r.A = calloc(M, sizeof(int));
    r.M = M;

    /* Increment counter for nucleotide, set MSB flag for position */
    for (int i=0; i<slen; i++)
    {
        int mc = map[S[i]-'A'];                /* mapped character */
        nSums[mc]++;                           /* nucleotide sums  */
        for (int j=0; j<3; j++)                /* store sums in arrays */
            NACG(j,i) = nSums[j] | (mc == j ? MSB : 0);
    }

    /* Populate Results for Minimal Nucleotide */
    for (int i=0; i<M; i++) {
        r.A[i] =
/* A */     (NACG(0,Q[i]) & ~MSB) - (NACG(0,P[i]) & ~MSB) ||
             NACG(0,Q[i]) & MSB || NACG(0,P[i]) & MSB ? 1 :
/* C */     (NACG(1,Q[i]) & ~MSB) - (NACG(1,P[i]) & ~MSB) ||
             NACG(1,Q[i]) & MSB || NACG(1,P[i]) & MSB ? 2 :
/* G */     (NACG(2,Q[i]) & ~MSB) - (NACG(2,P[i]) & ~MSB) ||
             NACG(2,Q[i]) & MSB || NACG(2,P[i]) & MSB ? 3 :
/* T */      /* default */                              4;
    }

    return r;
}
