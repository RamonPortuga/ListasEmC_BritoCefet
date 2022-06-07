void inverso(){
	struct ptr*aux;
	int valor;
	inicio=(struct ptr*)NULL;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	while(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->prox=inicio;
		inicio=aux;
		printf("Entre com o valor:\t");
		scanf("%d",&valor);
	}
	aux=(struct ptr*)NULL;
}
void mostra(){
	struct ptr*aux;
	aux=inicio;
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux!=(struct ptr*)NULL){
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}
	}
}
void contador(){
	struct ptr*aux;
	int cont;
	cont=0;
	aux=inicio;
	while(aux!=(struct ptr*)NULL){
		cont++;
		aux=aux->prox;
	}
	printf("\nA lista possui %d elementos",cont);
}
void media(){
	struct ptr* aux;
	float m;
	int cont;
	cont=0;
	aux=inicio;
	while(aux!=(struct ptr*)NULL){
		m+=aux->valor;
		cont++;
		aux=aux->prox;
	}
	if(cont==0)
		printf("\nMedia\t=\t0");
	else{
		printf("\nMedia\t=%2f",m/cont);
	}
}
void maior_menor(){
	struct ptr*aux;
	int maior, menor;
	aux=inicio;
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		maior=aux->valor;
		menor=maior;
		while(aux!=(struct ptr*)NULL){
			if(aux->valor>maior)
				maior=aux->valor;
			if(aux->valor<menor)
				menor=aux->valor;
			aux=aux->prox;
		}
	printf("\nMaior\t=\t%d\tmenor\t=\t%d",maior,menor);
	}
}
void inserir_fim(){
	struct ptr *aux;
	int valor;
	printf("Entre com o valor a ser adicionado ao fim da lista: ");
	scanf("%d", &valor);
	aux=inicio;
	if(inicio==(struct ptr*)NULL){
		inicio=(struct ptr *)malloc(sizeof(struct ptr));
		inicio->prox=(struct ptr *)NULL;
		inicio->valor=valor;
	}
	else{
		while(aux->prox!=(struct ptr *)NULL)
			aux=aux->prox;
		aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
		aux=aux->prox;
		aux->prox=(struct ptr *)NULL;
		aux->valor=valor;
		aux=(struct ptr *)NULL;
	}
}
void inserir_ordenado(){
	struct ptr *aux, *ant;
	int valor;
	printf("Entre com um valor: ");
	scanf("%d", &valor);
	if(inicio==(struct ptr *)NULL){
		inicio=(struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor=valor;
		inicio->prox=(struct ptr*)NULL;
	}
	else{
		aux=inicio;
		if(inicio->valor>valor){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->prox=aux;
			inicio->valor=valor;
			aux=(struct ptr*)NULL;
		}
		else{
			while((valor>aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
				ant=aux;
				aux=aux->prox;
			}
			if(valor>aux->valor){
				aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=(struct ptr*)NULL;
			}
			else{
				aux=(struct ptr *)malloc(sizeof(struct ptr));
				aux->valor=valor;
				aux->prox=ant->prox;
				ant->prox=aux;
			}
			aux=(struct ptr *)NULL;
			ant=(struct ptr *)NULL;
		}
	}
}
void remover(){
	struct ptr *aux, *ant;
	int valor;
	printf("Entre com o valor a ser removido: ");
	scanf("%d", &valor);
	if(inicio==(struct ptr *)NULL)
		printf("Lista vazia.");
	else{
		if(inicio->prox==(struct ptr *)NULL){
			if(inicio->valr!=valor)
				printf("Valor não consta.");
			else{
				free(inicio);
				inicio=(struct ptr *)NULL;
			}
		}
		else{
			if(inicio->valor==valor){
				aux=inicio;
				inicio=inicio->prox;
				aux->prox=(struct ptr *)NULL;
				free(aux);
				aux=(struct ptr *)NULL;
			}
			else{
				aux=inicio;
				while((valor!=aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					aux=aux->prox;
				}
				if(aux->valor!=valor)
					printf("O valor não existe.");
				else{
					if(aux->prox==(struct ptr *)NULL){
						ant->prox=(struct ptr *)NULL;
						free(aux);
						aux=(struct ptr *)NULL;
						ant=aux;
					}
					else{
						ant->prox=aux->prox;
						aux->prox=(struct ptr *)NULL;
						free(aux);
						aux=(struct ptr *)NULL;
						ant=aux;
					}
				}
			}
		}
	}
}
