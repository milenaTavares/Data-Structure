/*Arquivo: Heapsort.c
Objetivo:
Autor(a):Milena TR

/*Importa��o de bibliotecas*/
#include <stdio.h>
#include <conio.h>

/*Defini��o das estruturas*/

/*Fun��o que retorna o filho � esquerda de um n� 'i'*/
int esquerdo(int i){
    return 2*i+1;
}

/*Fun��o que retorna o filho � direita de um n� 'i'*/
int direito(int i){
    return 2*i+2;
}

/*Fun��o que mant�m a propriedade de heap m�ximo*/
void maxHeapFy(int *A,int i,int tam){
    int l,r,maior,aux;

    l=esquerdo(i);
    r=direito(i);

    if(l<=(tam-1) && A[l]>A[i]) maior=l;
    else maior=i;

    if(r<=(tam-1) && A[r]>A[maior]) maior=r;
//    else continue;

    if(maior=!i){
        aux=A[i];
        A[i]=A[maior];
        A[maior]=aux;
        maxHeapFy(A,maior,tam);
    }
    //printf("\ni=%d\nfim",i);
}

/*Fun��o que constr�i um heap*/
void construirHeapMax(int *A, int tam){
    int i=tam/2;
    while(i>=1){
        maxHeapFy(A,i,tam);
        i--;
    }
}

/*Fun��o Heapsort*/
int *heapSort(int *A,int tam){
    int aux,i=tam;

    construirHeapMax(A,tam);
    while(i<=2){
        aux=A[i];
        A[i]=A[1];
        A[1]=A[i];
        i--;
        tam--;
        maxHeapFy(A,1,tam);
    }
    return A;

}


/*Fun��o principal*/
int main(){

	int i, tam, elem;

	printf("Informe o tamanho do heap: ");
	scanf("%d", &tam);

	int heap[tam];

	//Preenche o vetor
	for(i=0; i<tam; i++){
		printf("\nElemento %d do heap: ", i+1);
		scanf("%d", &elem);
		heap[i]= elem;
	}

	printf("\n");

	heapSort(heap,tam);

	//Print do Heap
	printf("\nHeap Maximo: ");
	for(i=0; i<tam; i++){
    printf("[%d] ", heap[i]);
	}

	getch();
	return 0;
}
