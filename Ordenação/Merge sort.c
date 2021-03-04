/*
Arquivo: mergeSort.c
Objetivo:
Autor(a):Milena TR
Versão:1.0*/

/*Importação de bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Procedimento Merge
void merge (int *V, int ini, int meio, int fim){

    int *aux=(int*)malloc((fim-ini)*sizeof(int));
    if (!aux) return;

    int i=ini;
    int j=meio+1;
    int k=0;
    int tamanho=fim-ini+1;

    for(k=0;k<tamanho;k++){
        if(i<meio && j<fim){
            if(V[i]<=V[j]){
                aux[k]=V[i];
                i++;
            }
            else{
                if(i>=meio){
                    aux[k]=V[j];
                    j++;
                }
            }
        }
        else{
            if(i>=meio){
                aux[k]=V[j];
                j++;
            }
            else{
                aux[k]=V[i];
                i++;
            }
        }
    }
   //for(int x=0, k=ini; j<tamanho; j++,k++){
      //  V[k]=aux[j];
   }
    memcpy (&(V[ini]),aux,(fim-ini)*sizeof(int));
free(aux);
}

/*mem_cpy (&(V[ini]),aux,(fim-ini)*sizeof(int));
free(aux);*/

//Merge sort
void mergeSort(int *V,int ini, int fim){
    if((fim-ini)>1){
        int meio=(ini+fim)/2;
        mergeSort(V,ini,meio);
        mergeSort(V,meio+1,fim);
        merge(V,ini,meio,fim);
    }
}




/*Função principal*/
int main(){

    /*Declaração de variáveis*/
    int A[6]={8,3,9,4,6,7};
    int i,j;

    printf("-----Vetor Original-----\n");
    for(i=0;i<6;i++){
        printf("[%d]",A[i]);
    }

    //Função que ordena o vetor
    mergeSort(A,1,6);

    printf("\n\n-----Vetor Ordenado-----\n");
    for(i=0;i<6;i++){
        printf("[%d]",A[i]);
    }
    return 0;
}

