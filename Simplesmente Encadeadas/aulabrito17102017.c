10->	Criação de uma LSE na ordem em que os elementos foram inseridos

Ex:5,13,9,4,-1(o -1 estará fora);

void cria_lista(){
	int valor;
	struct ptr*aux,*fim;
	printf("Entre com o valor:");
	scanf("%d",&valor);
	inicio=(struct ptr*aux)NULL;
	fim=inicio;
	if(valor>=0){//O if é para caso o primeiro valor seja negativo (Lista Vazia);
		inicio=(struct ptr*)malloc(struct ptr));
		inicio->valor=valor;
		inicio->prox=(struct ptr*)NULL;
		printf("Entre com o valor:\t");
		scanf("%d",&valor);
		fim=inicio;
		while(valor>=0){
			fim->prox=(struct ptr*)malloc(sizeof(struct ptr));
			fim=fim->prox;
			fim->prox=(struct ptr*)NULL;
			printf("Entre com o valor:\t");
			scanf("%d",&valor);
		}
		fim=(struct ptr*)NULL;
	}
}

11->	Apagar a LSE da memória

void apaga_lista(){
	struct ptr*aux;
	aux=inicio;
	while(aux!=(struct ptr *)NULL){
		inicio=inicio->prox;
		aux->prox=(struct ptr*)NULL;
		free(aux);
		aux=inicio;
	}
}

12-> Para Casa: Criar duas LSE em qualquer ordem em seguida juntas as duas em uma só LSE em ordem crescente.(com e sem recursão).






											Listas Duplamente Encadeadas
1->		Criar uma LDE onde os elementos serão inseridos na ordem inversa em que são obtidos e o fim é dado quando o elemento for menor que 0.

void cria_lista_dupla_inv(){
	struct ptr* aux;
	int valor;
	inicio=(struct ptr *)NULL;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		inicio=(struct ptr*)malloc(sizeof(struct ptr));
		inicio->valor=valor;
	//	inicio->valor=valor;
		inicio->ant=(struct ptr*)NULL;
		inicio->prox=inicio->ant;
		printf("Entre com o valor:\t");
		while(valor>=0){
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=valor;
			aux->ant=(struct ptr *)NULL;
			aux->prox=inicio;
			inicio->ant=aux;
			inicio=aux;
			printf("Entre com o valor:\t");
			scanf("%d",&valor);
		}
		aux=(struct ptr*)NULL;
	}
}

2->		Criar LDE na ordem em que os elementos são inseridos

void cria_lista_dupla(){
	struct ptr*aux;
	int valor;
	inicio=(struct ptr*)NULL;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		inicio=(struct ptr*)malloc(sizeof(struct ptr));
		inicio->valor=valor;
		inicio->ant=(struct ptr*)NULL;
		inicio->prox=inicio->ant;
		printf("entre com o valor:\t");
		scanf("%d",&valor);
		aux=inicio;
		while(valor>=0){
			aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
			aux->prox->ant=aux;
			aux=aux->prox;
			aux->valor=valor;
			aux->prox=(struct ptr*)NULL;
			printf("Entre com o valor:\t");
			scanf("%d",&valor);
		}
		aux=(struct ptr*)NULL;
	}
}

3->		Inserção de um elemento na LDE mantendo a mesma ordenada. Supor que a LDE está em ordem crescente

void inserir_ordenado_dupla(){
	struct ptr* aux;
	int valor;
		printf("Entre com o valor:\t");
		scanf("%d",&valor);
		aux=inicio;
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr*)malloc(sizeof(struct ptr));
			
		}
}
