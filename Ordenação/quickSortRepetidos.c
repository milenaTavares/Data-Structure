// Erika Barbosa Gomes
//Procedimento de partição e QuickSort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura Result
typedef struct{
    int i;
    int j;
}Result;

//Algoritmo da função particiona para resolver problema de elementos repetidos
/*Função: int particiona(int *v, int p, int r)
   *  ação:		aplica procedimento de partição para resolver problema de elementos repetidos
   *  entrada:  vetor de inteiros, inteiros com posições do primeiro e último elementos do vetor
   *  saída:    inteiro índice do pivô */

Result particionaRepetidos(int *v, int p, int r){
    Result resp;
	int i= p;
	int j= r-1;
	int A= p-1;
	int B= r;
	int aux;

	while(i < j){
        if(v[i] == v[r]){
            aux= v[i];
            v[i]= v[A+1];
            v[A+1]= aux;
            A++;
            i++;
        }
        else if(v[i] > v[r]){
            aux= v[i];
            v[i]= v[j];
            v[j]= aux;
            j--;
        }
        else i++;
        if(v[j] == v[r]){
            aux= v[j];
            v[j]= v[B-1];
            v[B-1]= aux;
            j--;
            B--;
        }
        else if(v[j] < v[r]){
            aux= v[j];
            v[j]= v[i];
            v[i]= aux;
            i++;
        }
        else j--;
        if(i==j){
            if(v[i] == v[r]){
                aux= v[i];
                v[i]= v[A+1];
                v[A+1]= aux;
                A++;
                i++;
            }
            else if(v[i] > v[r]) j--;
            else i++;
        }
	}

	while(A > p-1){
        aux= v[A];
        v[A]= v[j];
        v[j]= aux;
        j--; A--;
	}
	while(B < r+1){
        aux= v[B];
        v[B]= v[i];
        v[i]= aux;
        i++; B++;
	}
	//printf("A= %d\nB= %d\ni= %d\nj= %d\n", A, B, i, j);
	resp.i= i; resp.j= j;
	return resp;
}

/*Função: void quickSortRepetidos(int *v, int p, int r)
   *  ação:		aplica ordenação quickSort
   *  entrada:  vetor de inteiros, inteiros com posições do primeiro e último elementos do vetor
   *  saída:    void */

void quickSortRepetidos(int *v, int p, int r){
    Result resp;
	if(p<r){
		resp= particionaRepetidos(v, p, r);
		quickSortRepetidos(v, p, resp.j);
		quickSortRepetidos(v, resp.i, r);
	}
}

//Função Principal
int main(){

	int i, tam, elem;

	printf("Informe o tamanho do vetor a ser ordenado: ");
	scanf("%d", &tam);

	int vetor[tam];

	//Preenche o vetor
	for(i=0; i<tam; i++){
		printf("\nElemento vetor[%d]: ", i+1);
		scanf("%d", &elem);
		vetor[i]= elem;
	}

	//Ordena o vetor
    quickSortRepetidos(vetor, 0, tam-1);

	//Printa o vetor ordenado
	printf("\nVetor ordenado: ");
	for(i=0; i<tam; i++){
		printf("[%d] ", vetor[i]);
	}

	return 0;
}
