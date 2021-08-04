#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

//O primeiro nó que aponta para a lista que será criada
struct lista{
	ListaNo* prim;
};

//Será a lista com valores inteiros que guarda os elementos do tipo inteiro
struct listano {
	int info;
	ListaNo* prox;
};

//Cria a lista que aponta para o primeiro elemento da lista com valores
Lista* criar_lista(void){
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->prim = NULL;
	return l;
}

//Recebe como parametro a lista para apontar o inicio da lista e depois o valor que será inserido no novo nó da lista
void lista_insere(Lista* l, int v){
	ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
	novo->info = v;
	novo->prox = l->prim;
	l->prim = novo;
}

//Função que imprime os valores dos nós na Lista encadeada
void imprime(Lista* l){
	for(ListaNo* p=l->prim;p!=NULL;p=p->prox){
		printf("Valor: %d\n", p->info);
	}
}

//Verifica se um elemento está na lista. Caso esteja ele retorna 1, caso não ele retorna 0
int buscar(Lista* l, int v){
	for(ListaNo* p = l->prim;p!=NULL;p = p->prox){
		if(p->info == v){
			return 1;
		}
	}
	return 0;
}

void insere_ordenado(Lista* l, int v){
	ListaNo* ant = NULL;
	ListaNo* p = l->prim;
	//localiza o elemento na lista e guarda a posição anterior
	while(p!=NULL && p->info < v){
		ant = p;
		p = p->prox;
	}

	//cria um novo elemento na lista
	ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
	novo->info = v;//insere o valor v

	//insere elemento no inicio da lista
	if(ant == NULL){
		novo->prox = l->prim;
		l->prim = novo;
	}else{
		//insere elemento no meio da lista
		novo -> prox = ant->prox;
		ant->prox = novo;
	}

}




int main(void) {
	//Gera o inicio da lista
  Lista* l = criar_lista();

	//Insere os valores nos nós da lista no inicio 
	lista_insere(l,10);
	lista_insere(l,15);

	//Coloca os elementos de forma ordenada
	insere_ordenado(l, 20);
	insere_ordenado(l, 5);
	
	//Mostra os valores
	imprime(l);

	free(l);
	
  return 0;
}