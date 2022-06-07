#include <stdio.h>
#include <stdlib.h>
struct ptr{
	int valor;
	struct ptr *prox;
};
struct desc{
	int cont;
	struct ptr *ini, *fim;
};
struct desc *inicio;

void criar_lista();
void mostra();
void media();
void contador();
void maior_menor();
void inserir_fim();
void apaga_lista();
void remover();
main(){
	inicio=(struct desc*)malloc(sizeof(struct desc));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	inicio->cont=0;
	criar_lista();
	mostra();
	inicio->cont=0;
//	contador();
//	media();
//	maior_menor();
//	inserir_fim();
//	mostra();
	remover();
	mostra();
	apaga_lista();
	mostra();
}
void criar_lista(){
	struct ptr*aux;
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	while(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->prox = inicio->ini;
		inicio->ini=aux;
		inicio->cont++;
		printf("Entre com o valor:\t");
		scanf("%d",&valor);
		if(inicio->fim == (struct ptr*)NULL)
			inicio->fim=aux;
		aux=(struct ptr*)NULL;
	}
}
void mostra(){
	struct ptr*aux;
	aux=inicio->ini;
	if(aux==inicio->ini)
		printf("\nQuantidade de nos: %d.\n", inicio->cont);
	if(inicio->ini==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux!=(struct ptr*)NULL){
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}
	}
}
void contador(){
	struct ptr* aux;
	int cont;
	cont=0;
	aux=inicio->ini;
	//if(aux==(struct ptr*)NULL)
	if(inicio->ini==(struct ptr*)NULL)
		printf("\nLista Vazia");
	while(aux!=(struct ptr*)NULL){
		cont++;
		aux=aux->prox;
	}
	if(aux==(struct ptr*)NULL)
		printf("\nA quantidade de elementos nessa lista e de:\t%d",cont);
		
}
void media(){
	int cont;
	float m;
	struct ptr* aux;
	aux=inicio->ini;
	while(aux!=(struct ptr*)NULL){
		m+=aux->valor;
		cont++;
		aux=aux->prox;
	}
	if(cont==0)
		printf("\nMedia\t=\t0");
	if(cont!=0){
		printf("\nMedia\t=%2f",m/cont);
	}
}
void maior_menor(){
	struct ptr* aux;
	int maior,menor;
	aux=inicio->ini;
	if(inicio->ini==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		maior=aux->valor;
		menor=maior;
		while(aux!=(struct ptr*)NULL){
			if(maior>aux->valor)
				maior=aux->valor;
			if(menor<aux->valor)
				menor=aux->valor;
			aux=aux->prox;
		}
	}
	if(aux==(struct ptr*)NULL){
		printf("\nO maior elemento e:\t%d",maior);
		printf("\nO menor elemento e:\t%d",menor);
	}
}
void inserir_fim(){
	struct ptr* aux;
	int valor;
	printf("\nEntre com o valor:\t");
	scanf("%d",&valor);
	aux=inicio->ini;
	if(inicio->ini==(struct ptr*)NULL){
		inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
		inicio->ini->prox=(struct ptr*)NULL;
		inicio->ini->valor=valor;
	}
	else{
		while(aux->prox!=(struct ptr*)NULL)
			aux=aux->prox;
		aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
		aux=aux->prox;
		aux->prox=(struct ptr*)NULL;
		aux->valor=valor;
		aux=(struct ptr*)NULL;
	}
}
void remover(){
	struct ptr* aux,*ant;
	int cont;
	printf("\nEntre com um valor:\t");
	scanf("%d",&cont);
	if(cont>=0){
		if(inicio->ini==(struct ptr *)NULL)
		printf("Lista vazia.");
	else{
		if(inicio->ini->prox==(struct ptr *)NULL){
			if(inicio->ini->valor!=cont)
				printf("Valor não consta.");  //CONSERTAR
			else{
				free(inicio);
				inicio->ini=(struct ptr *)NULL;
			}
		}
		else{
			if(inicio->ini->valor==cont){
				inicio->ini=inicio->ini->prox;
				aux->prox=(struct ptr *)NULL;
				free(aux);
			}
			else{
				while((cont!=aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					aux=aux->prox;
				}
				if(aux->valor!=cont)
					printf("O valor não existe.");
				else{
					if(aux->prox==(struct ptr *)NULL){
						ant->prox=(struct ptr *)NULL;
						free(aux);
					}
					else{
						ant->prox=aux->prox;
						aux->prox=(struct ptr *)NULL;
						free(aux);
					}
				}
			}
		}
		aux=(struct ptr *)NULL;
		ant=aux;
	}
	}
}
void apaga_lista(){
	struct ptr* aux;
	while(inicio->ini!=(struct ptr*)NULL){
		inicio->ini=inicio->ini->prox;
		free(aux);
		inicio->fim=(struct ptr*)NULL;
	}
}
