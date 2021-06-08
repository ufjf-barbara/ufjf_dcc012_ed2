#include <stdio.h>
#include <stdlib.h>
// https://www.ime.usp.br/~pf/algoritmos/aulas/quick.html

// Recebe vetor v[p..r] com p <= r. Rearranja
// os elementos do vetor e devolve j em p..r
// tal que v[p..j-1] <= v[j] < v[j+1..r].
static int separa (int v[], int p, int r) {
   int c = v[r]; // pivô
   int t, j = p;
   for (int k = p; /*A*/ k < r; ++k)
      if (v[k] <= c) {
         t = v[j], v[j] = v[k], v[k] = t;
         ++j; 
      } 
   t = v[j], v[j] = v[r], v[r] = t;
   return j; 
}

// Esta função rearranja qualquer vetor
// v[p..r] em ordem crescente.
void meu_quicksort (int v[], int p, int r)
{
   while (p < r) {                // 1
      int j = separa (v, p, r);   // 2
      meu_quicksort (v, p, j-1);  // 3
      p = j + 1;
   }
}

