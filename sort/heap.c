#include <stdio.h>
#include <stdlib.h>

//https://www.ime.usp.br/~pf/algoritmos/aulas/hpsrt.html

// Suporemos que os índices do vetor são  1 . . n  
// e não 0 . . n−1 (como é usual em C) pois essa convenção 
// torna o código um pouco mais simples.


#define troca(A, B) {int t = A; A = B; B = t;}

// Rearranja um vetor v[1..m] de modo a
// transformá-lo em heap.
static void constroiHeap(int m, int v[])
{
   for (int k = 1; k < m; ++k) {                   
      // v[1..k] é um heap
      int f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  // 5
         troca (v[f/2], v[f]);          // 6
         f /= 2;                        // 7
      }
   }
}

// Recebe um vetor v[1..m] que é um heap
// exceto talvez pelos índices 2 e 3 e
// rearranja o vetor de modo a
// transformá-lo em heap.
static void peneira (int m, int v[])
{ 
   int f = 2;
   while (f <= m) {
      if (f < m && v[f] < v[f+1]) ++f;
      // f é o filho mais valioso de f/2
      if (v[f/2] >= v[f]) break;
      troca (v[f/2], v[f]);
      f *= 2;
   }
}

// Rearranja os elementos do vetor v[1..n] 
// de modo que fiquem em ordem crescente.
void meu_heapsort(int n, int v[])
{
   constroiHeap (n, v);
   for (int m = n; m >= 2; --m) {
      troca (v[1], v[m]);
      peneira (m-1, v);
   }
}

void imprime(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){

    int v[9] = {0,3,4,8,9,1,5,7,8};

    printf("\n Vetor antes: ");
    imprime(v,9);

    meu_heapsort(8,v);
    
    printf("\n Vetor Ordenado: ");
    imprime(v,9);

    return 0;
}

