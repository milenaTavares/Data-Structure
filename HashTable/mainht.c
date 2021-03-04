#include<stdio.h>

#include "hash.c"

#define MAXSIZEHT 11
#define MAXSIZEW 23

int main()
{
	Hash *hashtable[MAXSIZEHT];
	char word[MAXSIZEW];
	int resp;
	createHT(hashtable,MAXSIZEHT);
	loadDic(hashtable);

    int pos = functionHT(word,MAXSIZEHT);

	do
	{
		printf("\nDigite a palavra a ser deletada=");
		fflush(stdin);
		gets(word);
		pos = functionHT(word,MAXSIZEHT);
		printf("\nPalavra=%s Posicao=%d",word,pos+1);
		deleteHT(hashtable,MAXSIZEHT,word);
		printf("\nDeletar mais? 1-SIM ou 2-NAO");
		scanf("%d",&resp);
	}while(resp==1);

	printHT(hashtable,MAXSIZEHT);
	return 0;

}


int loadDic(Hash *hashtable[])
{
	FILE *fp=fopen("palavras.txt","a+");
    if(fp==NULL)
	    {
		  printf("\a\a\n\n\n\n\n\nERRO AO ABRIR O ARQUIVO!\n\n\n\n\n\n");
		  system("pause");
		  return -1;
		}

	int pos, x=0;
	char aux[MAXSIZEW];
	while(!feof(fp))
	{
			fgets(aux,MAXSIZEW,fp);
			strtok(aux, "\n");
			pos = functionHT(aux,MAXSIZEHT);
			printf("\nloadDic: Palavra=%s Posicao=%d",aux,pos);
			//printf("\noiiii");
			insertHT(hashtable,MAXSIZEHT,aux);
			x++;
	}
	printf("\nTAMANHO=%d",x);
	return 1;
}
