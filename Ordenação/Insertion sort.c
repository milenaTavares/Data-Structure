#include<stdio.h>

//Função que ordena o vetor
void insertionSort(int vetor[], int tamanhoVetor) {

int aux, j, i;

    for (int i = 1; i < tamanhoVetor; i++) {
		aux = vetor[i];
		j = i - 1;

		while ((j >= 0) && (vetor[j] > aux)) {
			vetor[j + 1] = vetor[j];
			j--;
		}

		vetor[j + 1] = aux;
	}
}

//Função Principal
int main(){

    int A[6]={8,3,9,4,6,7};
    int i,j;

    printf("-----Vetor Original-----\n");
    for(i=0;i<6;i++){
        printf("[%d]",A[i]);
    }

    //Função que ordena o vetor
    insertionSort(A,6);

    printf("\n\n-----Vetor Ordenado-----\n");
    for(i=0;i<6;i++){
        printf("[%d]",A[i]);
    }
    return 0;

}
