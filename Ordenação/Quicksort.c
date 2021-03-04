#include<stdio.h>

int particiona(int *A, int p, int r){
    int x,i,j,aux;
    x=A[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(A[j]<=x){
            i++;
            aux=A[i];
            A[i]=A[j];
            A[j]=A[i];
        }
    }
    aux=A[i+1];
    A[i+1]=A[r];
    A[r]=aux;
    return i+1;
}



void quickSort(int *A, int p, int r){
    int q;
    if(p<r){
        q = particiona(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q,r);
    }
}


int main(){
    int A[6]={8,3,9,4,6,7};
    int i,j;

    quickSort(A,0,5);

    for(i=0;i<6;i++){
        printf("[%d]\n",A[i]);
    }
    return 0;

}
