#include <stdio.h>
#include <stdlib.h>
#include "merge.c"
#include "quick.c"
#include "heap.c"

void imprime(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    
    int v[8] = {3,4,8,9,1,5,7,8};
    printf("\n Vetor antes: ");
    imprime(v,8);

    /* Merge Sort */
    // printf(" *** Merge Sort *** \n");
    //meu_mergesort(0,8,v);
    /* Quick Sort */
    // v = vetor, p = indice do pivo, r = ultimo indice valido
    printf(" *** Quick Sort *** \n");
    meu_quicksort(v,0,7);

    printf("\n Vetor Ordenado: ");
    imprime(v,8);

    /* Heap Sort comeca do indice 1 */
    /* int v[9] = {0,3,4,8,9,1,5,7,8};
    printf("\n Vetor antes: ");
    imprime(v,9);
    printf(" *** Heap Sort *** \n");
    meu_heapsort(8,v);    
    printf("\n Vetor Ordenado: ");
    imprime(v,9);
    */

    return 0;
}

