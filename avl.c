#include <stdio.h>
#include <stdlib.h>

struct no 
{
int chave;
int autura;
struct no *filhoEsquerdo;
struct no *filhoDireito;
};

void alocaNo(struct no **no,int chave)
{
(*no)=malloc(sizeof (struct no));
(*no)->chave=chave;
(*no)->autura=0;
(*no)->filhoDireito=NULL;
(*no)->filhoEsquerdo=NULL;
}


void imprimeArvore(struct no *no){
	if(no==NULL)
	{
	 printf("%s\n","Nao exitem dados na arvore:" );
	}
	else
	{
		if(no->filhoEsquerdo!=NULL)
		{
			imprimeArvore(no->filhoEsquerdo);
		}
		printf("%i => %i\n",no->chave,no->autura);
		if(no->filhoDireito!=NULL)
		{
			imprimeArvore(no->filhoDireito);
		}
	}
}

void auturaNO(struct no *raiz)
{
	if (raiz->filhoDireito!=NULL && raiz->filhoEsquerdo!=NULL)
	{
		raiz->autura=(raiz->filhoDireito->autura+1)+(raiz->filhoEsquerdo->autura-1);		
	}
	else
	{
		if (raiz->filhoDireito!=NULL)
		{
			raiz->autura=(raiz->filhoDireito->autura+1);	
		}
		if (raiz->filhoEsquerdo!=NULL)
		{
			raiz->autura=(raiz->filhoEsquerdo->autura-1);	
		}
	}
	printf("%i\n", raiz->autura);
}

int insereNoArevore(struct no **raiz,int chave)
{
	int retorno;
	if((*raiz)==NULL)
	{
	  alocaNo(raiz,chave);
	  auturaNO(*raiz);
	  return 1;
	}
	else
	{

		if((*raiz)->chave == chave)
		{
			return -1;
		}
		if((*raiz)->chave > chave)
		{
			retorno=insereNoArevore(&(*raiz)->filhoEsquerdo,chave);
			auturaNO(*raiz);
			return retorno;
		}
		
		else
		{
			retorno =insereNoArevore(&(*raiz)->filhoDireito,chave);	
			auturaNO(*raiz);
			return retorno;
		}	
	}
}




int main(int argc, char const *argv[])
{
	/* code */
	struct no *raiz;
	int chave,retorno=1;
	printf("Inicio Projeto AVL\n");
	while(retorno==1)
	{
		printf("%s","digite um numero:\n");
		scanf("%d",&chave);
		retorno=insereNoArevore(&raiz,chave);
		printf("%i\n",retorno);	
	}
	imprimeArvore(raiz);
	return 0;
}

