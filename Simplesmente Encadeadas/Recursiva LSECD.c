//146) Geração de uma L.S.E.C.D onde os elementos serão inseridos na ordem inversa em que forem obtidos em recursão
struct ptr{
	int cont,valor;
	struct ptr*ant,*prox;
};
struct desc{
	int cont,valor;
	struct desc* ini,*fim;
};
struct desc* inicio;
void criar_lista(struct ptr*aux);
main(){
	inicio=(struct desc*)malloc(sizeof(struct desc));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	criar_lista(inicio->ini);
}
void criar_lista(struct ptr* aux){
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=valor;
			inicio->ini->ant=inicio;
			inicio->ini->prox=inicio;
			else{
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=valor;
			aux->prox=inicio;
			inicio=aux;
//			fim->prox=inicio;
		}
		aux=(struct ptr*)NULL;
		fim=(struct ptr*)NULL;
	}
}
void mostra(struct ptr*aux){
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio->ini){
			printf("%d\t",aux->valor);
			mostra(aux->prox);
		}
		else{
			printf("%d\t",aux->valor);
		}
	}
}
