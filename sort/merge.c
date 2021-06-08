#include <stdio.h>
#include <stdlib.h>
// https://www.ime.usp.br/~pf/algoritmos/aulas/mrgsrt.html

/* A função intercala1 consiste essencialmente em movimentar elementos do vetor v 
de um lugar para outro (primeiro de v para w e depois de w para v).  
A função executa 2n dessas movimentações, sendo n o tamanho do vetor v[p..r-1].   
O tempo que intercala1 consome é proporcional ao número de movimentações.  
Portanto, o consumo de tempo da função é proporcional a n.  
Assim, o algoritmo é linear.*/

// A função recebe vetores crescentes v[p..q-1] 
// e v[q..r-1] e rearranja v[p..r-1] em ordem 
// crescente.
static void intercala1 (int p, int q, int r, int v[]) 
{
   int *w;                                 //  1
   w = malloc ((r-p) * sizeof (int));     //  2
   int i = p, j = q;                       //  3
   int k = 0;                              //  4

   while (i < q && j < r) {                //  5
      if (v[i] <= v[j])  w[k++] = v[i++];  //  6
      else  w[k++] = v[j++];               //  7
   }                                       //  8
   while (i < q)  w[k++] = v[i++];         //  9
   while (j < r)  w[k++] = v[j++];         // 10
   for (i = p; i < r; ++i)  v[i] = w[i-p]; // 11
   free (w);                               // 12
}

/*Sedgewick escreve o algoritmo de intercalação de uma maneira mais interessante.  
Primeiro, copia o vetor v[p..q-1] para o espaço de trabalho w[0..q-p-1];  
depois, copia v[q..r-1] para o espaço w[q-p..r-p-1] em ordem inversa.  
Com isso, a metade esquerda de w serve de sentinela para a metade direita durante o 
processo de intercalação, e vice-versa.  Assim, a intercalação de w[0..q-p-1] 
com w[q-p..r-p-1] pode ser feita com base na comparação  w[i] <= w[j]  
sem que seja preciso verificar, a cada iteração, as condições  i < q-p  e  j ≥ q-p.
Tal como a versão anterior, esta consome tempo proporcional ao tamanho do vetor v[p..r-1].*/

// Esta função recebe vetores crescentes 
// v[p..q-1] e v[q..r-1] e rearranja
// v[p..r-1] em ordem crescente.
static void intercala2 (int p, int q, int r, int v[])
{
   int i, j, *w;
   w = malloc ((r-p) * sizeof (int));

   for (i = p; i < q; ++i) w[i-p] = v[i];
   for (j = q; j < r; ++j) w[r-p+q-j-1] = v[j];
   i = 0; j = r-p-1;
   for (int k = p; k < r; ++k)
      if (w[i] <= w[j]) v[k] = w[i++];
      else v[k] = w[j--];
   free (w);
}

void meu_mergesort (int p, int r, int v[])
{
   if (p < r-1) {                 // 1
      int q = (p + r)/2;          // 2
      meu_mergesort (p, q, v);        // 3
      meu_mergesort (q, r, v);        // 4
      //intercala1 (p, q, r, v);     // 5
      intercala2 (p, q, r, v);     // 5
   }
}

