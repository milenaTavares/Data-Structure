#include "arvoreB.c" // Substituir por arvoreB.h

//Função Principal
int main(){
	int aux = 0;
	int op;
	int resp;
	int cont = 0;
	int help = 0;

	infoArvore *arv = criaArvore();
	
	int pt, chave, f, g;
	
	FILE *arq = fopen(fileName, "rb+");
	if(arq == NULL)
		aux= 0;
	else aux= 1;
	
	artigo *art= (artigo*)malloc(sizeof(artigo));
	pag *pagina= (pag*)malloc(sizeof(pag));
	
	

	//void insereArvoreB(FILE *arq, artigo *art, int existeArq)
	//int buscaArvoreB(FILE *arq, int *pt, int chave, int *f, int *g)
	
	do{
		printf("Informe a operacao desejada: \n(1) - Inserir na arvore\n(2) - Buscar na arvore\n::: ");
		scanf("%d", &op);
		
//		printf("\n          ***          \n\n");
		if(op!=1 && op!=2){
			printf("\nOperacao invalida!");
			break;
		}
			
		if(aux==0){
			if(op==1){
				pedeArtigo(art);
				arq = fopen(fileName, "wb+");
				if(!arq){
					printf("\nErro ao abrir o arquivo!");
					return 0;
				}
				insereArvoreB(arq, art, 0);
				cont=1;
				aux= 1;
			}
			else
				printf("\nNao foi possivel buscar, pois a arvore esta vazia!");
		}
		else{
			if(op==1){
				pedeArtigo(art);
	        	insereArvoreB(arq, art, 1);
	        	cont++;
			}
			else{
				printf("\nInforme o id do artigo buscado: ");
				scanf("%d", &chave);
				
				buscaArvoreB(arq, &pt, chave, &f, &g);
				if(f==0)
					printf("\nArtigo nao encontrado!");
				else
					printf("\nO artigo foi encontrado na pagina %d, na posicao %d", pt, g);
			}
		}
		printf("\n\n\nDeseja realizar outra operacao? \n(1) - Sim\n(2) - Nao\n::: ");
		scanf("%d", &resp);
	}while(resp==1);
	
//	if(cont!=0){
//		fclose(arq);
//		arq= fopen(fileName, "rb");
//	}
//	else{
//		fclose(arq);
//		return 0;
//	}
	if(aux==0){
		fclose(arq);
		return 0;
	}
	printf("\nTentando ler...");
	fseek(arq, 0, SEEK_SET);
	fread(arv, sizeof(infoArvore), 1, arq);

	printf("\nO arquivo corrente tem %d paginas: ", arv->numPags);
	
	int i, j;

	
	for(i=1; i<=arv->numPags; i++){
		pagina= lePagina(arq, i, pagina);
		for(j=0; j<pagina->m; j++){
			printf("\nChave do artigo %d da pagina %d: %d", j, i, pagina->s[j].id);
		}
	}
	
	return 0;
}
