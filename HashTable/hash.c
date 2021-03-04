#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "hash.h"

/* funcao: void createHT(Node *hashtable,int size)
   *  acao:        funcao que cria uma hashtable
   *  entrada:     vetor representando a hashtable
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void createHT(Hash *hashtable[],int sizeht)
{
	int i;
    for (i=0; i<sizeht; i++){
      	hashtable[i]=aux();
    }
}
Hash *aux(){
    Hash *ht=(Hash*)malloc(sizeof(Hash));
    ht->first=NULL;
    ht->size=0;
    return ht;
}

/* funcao: Node *createNodeHT(char *inf)
   *  acao:        funcao que cria um novo no e aloca
   					espaco para a string inf, armazenando uma
   					copia dela no novo no criado
   *  entrada:     elemento de informacao do novo no
   *  saida:       ponteiro para um no
   *  suposicoes:  nenhuma
*/
Node *createNodeHT(char *inf)
{
    Node *ptr;
    if((ptr=(Node *)malloc(sizeof(Node)))){
        ptr->info=(char *)malloc(sizeof(char)*(strlen(inf)+1));
        strcpy(ptr->info,inf);
        ptr->next=NULL;
        return ptr;
    }
    return NULL;
}

/* funcao: int functionHT(char *inf)
   *  acao:        funcao que calcula o valor hash de uma chave
   *  entrada:     chave
   *  saida:       inteiro representando o valor hash de uma chave
   *  suposicoes:  nenhuma
*/
int functionHT(char *inf,int sizeht)
{
	int i,sum=0;

	for(i=0;i<strlen(inf);i++)	sum+=inf[i];
	if(sum<0) sum+=256;
	return fmod(sum,sizeht);;
}

/* funcao: void printHT(Node *hashtable[])
   *  acao:        funcao que imprime o conteudo de uma tabela hash
   *  entrada:     tabela hash
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void printHT(Hash *hashtable[],int sizeht)
{
	int i;
	for (i=0; i<sizeht; i++)
	{
		printf("\nIndice: %d ->", i);
		//getchar();
		Node *ptr = hashtable[i]->first;
		while (ptr != NULL)
		{
			printf("\t%s", ptr->info);
			ptr = ptr->next;
		}
		printf("\n\n");
		//getchar();
	}

}

/* funcao: void insertHT(Node *hashtable[], char *name)
   *  acao:        funcao que insere uma chave na tabela hash
   *  entrada:     tabela hash e chave a ser inserida
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void insertHT(Hash *hashtable[],int sizeht, char *word)
{

	Node *ptr = createNodeHT(word);
	if(!ptr) printf("erro");

	int pos = functionHT(word,sizeht);

	Node *aux=hashtable[pos]->first;

    if(aux==NULL){
        hashtable[pos]->first=ptr;
        hashtable[pos]->size++;
    }

    //Inserir no início
	else if(strcmp(word,aux->info)<=0){
        //printf("\nigual\n");
        hashtable[pos]->first=ptr;
        ptr->next=aux;
        hashtable[pos]->size++;
        return;
	}
	else if(hashtable[pos]->size==1){
        aux->next=ptr;
        hashtable[pos]->size++;
	}
	else{
        //Node *aux3;
        while( strcmp(aux->info,word)<0 && aux->next!=NULL){
            aux=aux->next;
        }
        Node *aux2=aux->next;
        aux->next=ptr;
        ptr->next=aux2;
        hashtable[pos]->size++;
	}
}


/* funcao: void searchHT(Node *hashtable[], char *wd)
   *  acao:        funcao que busca uma chave na tabela hash
   *  entrada:     tabela hash e chave a ser buscada
   *  saida:       void
   *  suposicoes:  nenhuma
*/
Node *meio(Node *ptr, int size){
    Node *aux=ptr;
    int i;
    int meio=size/2;
    for(i=0;i<meio;i++){
        aux=aux->next;
    }
    return aux;
}

Node *final(Node *ptr){
    Node *aux;
    for(aux=ptr;aux->next!=NULL;aux=aux->next);
    return aux;
}

int tamanhoList(Node *ini, Node *fim){
    int i=1;
    Node *aux;
    for(aux=ini;aux!=fim;aux=aux->next){
        i++;
    }
    return i;
}


Node *searchHT(Node *inicio, Node *meioht, Node *fim, char *word)
{
	clock_t Ticks[2];
	Ticks[0] = clock();

	int pos = functionHT(word,11);


	if(inicio == NULL)
	{
		Ticks[1] = clock();
        double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("\nNAO ENCONTREI!");
        printf("\nTempo gasto: %g ms.", Tempo);
        return NULL;
	}

	if(strcmp(word,inicio->info) == 0){
		printf("\nENCONTREI! Indice: %d ->  %s", pos,inicio->info);
        Ticks[1] = clock();
        double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("\nTempo gasto: %g ms.", Tempo);
        return inicio;
	}

	if(strcmp(word,fim->info) == 0){
		printf("\nENCONTREI! Indice: %d ->  %s", pos,fim->info);
        Ticks[1] = clock();
        double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("\nTempo gasto: %g ms.", Tempo);
        return fim;
	}

	else if((strcmp(word,inicio->info)<0 || strcmp(fim->info,word)<0)||(strcmp(inicio->info,meioht->info) == 0 && strcmp(inicio->info,word)!=0)){
        Ticks[1] = clock();
        double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("\nNAO ENCONTREI!");
        printf("\nTempo gasto: %g ms.", Tempo);
        return NULL;
	}

	else if(strcmp(meioht->info,word)==0){
        printf("\nENCONTREI! Indice: %d ->  %s", pos,meioht->info);
        Ticks[1] = clock();
        double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("\nTempo gasto: %g ms.", Tempo);
        return meioht;
	}

	else{
        if(strcmp(meioht->info,word)<0){
            searchHT(meioht,meio(meioht,tamanhoList(meioht,fim)),fim,word);
        }
        else{
            searchHT(inicio,meio(inicio,tamanhoList(inicio,meioht)),meioht,word);
        }

	}
}

/* funcao: void deleteHT(Node *hashtable[], char *wd)
   *  acao:        funcao que deleta uma chave da tabela hash
   *  entrada:     tabela hash e chave a ser deletada
   *  saida:       void
   *  suposicoes:  nenhuma
*/


void deleteHT(Hash *hashtable[],int sizeht, char *wd)
{
	int pos = functionHT(wd,sizeht);
	Node *ptr = hashtable[pos]->first;
	Node *middle = NULL,*end = NULL;
	Node *aux;

	if(ptr==NULL)
		printf("\n\nErro\n\n");
	else
	{
		middle = meio(hashtable[pos]->first,tamanhoList(hashtable[pos]->first,NULL));
		end = final(hashtable[pos]->first);
		aux = searchHT(ptr,middle,end,wd);
		if(aux)
		{
			if(strcmp(aux->info,ptr->info)==0)
			{
				hashtable[pos]->first = aux->next;
				free(aux);
			}
			else
			{
				for(ptr;ptr->next!=aux;ptr = ptr->next);
				ptr->next = aux->next;
				free(aux);
			}
		}
		else
			printf("\n\nElemento nao encontrado\n\n");
	}
		getchar();
	return;
}

