// Felipe Silvestre Cardoso Roberto
// RA: 170 425

#include <stdio.h>
#include <stdlib.h>

// Função para calcular o indice da mediana
int media_de_tres(int *lista, int p, int q) {
    int media = (p + q) / 2;

    int mediana;
    if (lista[p] < lista[q]) {
    if (lista[q] < lista[media]) {

            mediana = q;
        
        } else {
        if (lista[p] < lista[media]) {
                mediana = media;
        } else {
                mediana = p;
            }
        }
    } else {
    if (lista[q] > lista[media]) {
    
            mediana = q;
    
    } else {
        if (lista[p] > lista[media]) {
        
                mediana = media;
        
        } else {
        
                mediana = p;
            }
        }
    }
    return mediana;
}





// Faz a partição
int particao(int *lista, int p, int pivo) {
  int x = lista[pivo];
  int i = p - 1;
  for (int j = p; j <= pivo-1; j++) { 
    if (lista[j] < x) {
      i++;
      int aux = lista[i];
      lista[i] = lista[j];
      lista[j] = aux;
    }
  }
  int aux2 = lista[i + 1];
  lista[i + 1] = lista[pivo];
  lista[pivo] = aux2;
  return (i + 1);
}

//quicksort com o pivo sendo sempre o ultimo 
void quicksort(int *lista, int p, int n, int k, int *min, int *max) {
    
  if (p < n) { 
    int q = particao(lista, p, n);
    quicksort(lista, p, q - 1, k+1, min, max);
    quicksort(lista, q + 1, n, k+1, min, max);
  } else {
    if (*min == 0){
        *min = k;
        *max = k;
    } 
    if (k >= *max){
        *max =k;
    }
    if (k<=*min){
        *min=k;
    }
    
  }
}

// quicksort com a mediana de 3
void quicksort3(int *lista, int p, int n, int k, int *min2, int *max2) {

        if (p < n) {
            int index = media_de_tres(lista,p,n);
            int aux = lista[n];
            lista[n] = lista[index];
            lista[index] = aux;
            int q = particao(lista, p, n); 
            quicksort3(lista, p, q - 1, k+1, min2, max2);
            quicksort3(lista, q + 1, n, k+1, min2, max2);
        } else {
            if (*min2 == 0){
        *min2 = k;
        *max2 = k;
    } 
    if (k >= *max2){
        *max2 =k;
    }
    if (k<=*min2){
        *min2=k;
    }
    
  }
}
    

int main() {
    int n;
    int *lista, *lista2;
    scanf("%d", &n);
    lista = malloc(sizeof(int) * n);
    lista2 = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &lista[i]); 
        lista2[i] = lista[i];
    }

    int min = 0;
    int max = 0;
    int k = 0;

    int min2 = 0;
    int max2 = 0;
    int k2 = 0;

    quicksort(lista, 0, n-1, k, &min, &max); 
    quicksort3(lista2, 0, n-1, k2, &min2, &max2); 
    printf("%d", (max-min));
    printf("\n");
    printf("%d", (max2-min2));
    free(lista);
    free(lista2);
    return 0;
}
