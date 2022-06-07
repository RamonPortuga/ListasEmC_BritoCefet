10) Criação de uma L.S.E. na ordem em que os
elementos foram inseridos

EX.: 5	13	9	4	-1

---ver img1.png---

void cria_lista()
{
	int valor
	struct ptr *fim;
	printf("Entre com o valor:");
	scanf("%d",&valor);
	inicio=(struct ptr*)NULL;
	fim=inicio;
	if(valor>=0)
		{
			inicio=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->prox=(struct ptr*)NULL;
			printf("Entre com uno valor:");
			scanf("%d",&valor);
			fim=inicio;
			while(valor>=0)
				{
					fim->prox=(struct ptr*)malloc(sizeof(struct ptr));
					fim=fim->prox;
					fim->valor=valor;
					fim->prox=(struct ptr*)NULL;
					printf("Entre com um valor muchacho:");
					scanf("%d",&valor);
				}
				fim=(struct ptr*)NULL;
			
		}
}
---------------------------------------------------------------------------------------------------------
11) Apagar a L.S.E. da memória.

---ver img2.png---

void apaga_lista()
{
	struct ptr*aux;
	aux=inicio;
	while(aux!=(struct ptr*)NULL)
		{
			inicio=inicio->prox;
			aux->prox=(struct ptr*)NULL;
			free(aux);
			aux=inicio;
		}
}
---------------------------------------------------------------------------------------------------------
12)CRIAR DUAS L.S.E. EM QUALQUER ORDEM E 
JUNTAR AS DUAS EM UMA SÓ L.S.E. EM ORDEM
CRESCENTE (COM E SEM RECURSÃO) SEU MERDA (VAI CAIR)

L1+L2->L3

-------------------------------------------

Listas duplamente encadeadas

Uma L.D.E é aquela em que cada nó da lista possui referências. A primeira é usada
para indicar o antecessor, enquanto que a segunda aponta para o nó sucessor.

Ex:
	(EX DE LDE)
	
struct ptr{
	int valor;
	struct ptr *ant,*prox;
};	
struct ptr *inicio;

1)Criar uma L.D.E onde os elementos serão inseridos na ordem inversa em que
são obtidos.  O fim é dado quando o elemento for menor que zero.

23 4 11 7 -1

/*(jogo da forca, usuario insere uma palavra. armazenar cada letra em uma lista encadeada)

O L A
_ _ _

5 tentativas 
se o usuario tiver errado, aparece "restam n tentativas"
se acertar, a letra aparece
se tentar novamente, fala que a tal letra ja foi

*/

void cria_lista_dupla_inv(){
	struct ptr*aux;
	int valor;
	inicio=(struct ptr *NULL);
	printf("Entre com o valor:");
	scanf("%d",&valor);
	if(valor>=0){
		inicio=(struct ptr*)malloc(sizeof(struct ptr));
		inicio->valor=valor;
		inicio->ant=(struct ptr *)NULL;
		inicio->prox=inicio->ant;
		printf("Entre com o valor:");
		scanf("%a",&valor);
		while(valor>=0){
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=valor;
			aux->ant=(struct ptr*)NULL;
			aux->prox=inicio;
			inicio->ant=aux;
			inicio=aux;
			printf("Entre com o valor:");
			scanf("%d",&valor);
		}
		aux=(struct ptr*)NULL;
	}
}

2)Criar L.D.E na ordem em que os elementos são inseridos. 

void criar_lista_dupla(){
	struct ptr *aux;
	int valor;
	inicio=(struct ptr*)NULL;
	printf("Entre com o valor:");
	scanf("%d",&valor);
	if(valor>=0){
		inicio=(struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor=aux;
		inicio->ant=(struct ptr*)NULL;
		inicio->prox=inicio->ant;
		printf("Entre com o valor:");
		scanf("%d",&valor);
		aux=inicio;
		while(valor>=0){
			aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
			aux->prox->ant=aux;
			aux=aux->prox;
			aux->valor=valor;
			aux->prox=(struct ptr*)NULL;
			printf("Entre com o valor:");
			scanf("%d",&valor);
		}
		aux=(struct ptr*)NULL;
	}
}

3)Inserção de um elemento na L.D.E mantendo a mesma ordenada. Supor que a L.D.E  está em ordem crescente.

/*
	situações possiveis:
	- Lista Vazia
	- Lista não vazia
		- inserir inicio
		- "" meio
		- "" fim
		
		*/

void inserir_ordenado_dupla(){
	struct ptr* aux;
	int valor;
	printf("Entre com o valor:");
	scanf("%d",&valor);
	aux=inicio;
	if(inicio==(struct ptr*)NULL){
		inicio=(struct ptr*)malloc(sizeof(struct ptr));
		inicio->valor=valor;
		inicio->ant=(struct ptr*)NULL;
		inicio->prox=inicio->ant;
	}	
	else{
		if(valor<inicio->valor){
			inicio->ant=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ant->valor=valor;
			inicio->ant->prox=inicio;
			inicio=inicio->ant;
			inicio->ant=(struct ptr*)NULL;
		}
		else{
			while((valor>aux->valor)&&(aux->prox!=(struct ptr*)NULL){
				aux=aux->prox;
			}
			if(valor>aux->valor){
				aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
				aux->prox->ant=aux;
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=(struct ptr*)NULL;
				aux=(struct ptr*)NULL;
			}
			else{
				aux->ant->prox=(struct ptr*)malloc(sizeof(struct ptr));
				aux->ant->prox->prox=aux;
				aux->ant->prox->ant=aux->ant;
				aux->ant=aux->ant->prox;
				aux->ant->valor=valor;
				aux=(struct ptr*)NULL;
			}
		}
	}
}

4) Criação de uma L.D.E em ordem crescente

void cria_lista_dupla_ordenada(){
	int valor;
	inicio=(struct ptr*)NULL;
	printf("Entre com o valor:");
	scanf("%d",&valor);
	aux=inicio;
	// chamar o 3 varias vezes
	if(inicio==(struct ptr*)NULL){
		inicio=(struct ptr*)malloc(sizeof(struct ptr));
		
	}
}

5) Remover elemento da l.d.e (com e sem recursão)

6) Criar 2 l.d.e e juntar em uma única l.d.e em ordem crescente (com e sem recursão)

7) Apagar a L.D.E da memória (com e sem recursão)

Listas com descritor

Um nó descritor é um elemento que reúne as referências do início e do fim da lista. 
O acesso aos elementos da lista será sempre efetuado através do seu descritor.

(desenho)

O nó descritor de uma lista pode conter outras informações
sobre a lista, a critério do projetista, tais como: quantidade
de nós da lista, maior valor, menor valor, media e etc.

ex: L.S.E.D no qual foi incluido um campo que indica
 a quantidade de nós existentes na lista.
 
 (desenho 2)
 
struct ptr{
	int valor;
	struct ptr *prox;
};

struct desc{
	int quant;
	struct ptr *primeiro, *ultimo;
};

struct desc *lista;

Uma lista vazia passa a ser representada, agora, da seguinte forma:
	
(desenho 3)

Ex:
	1) Fazer uma função que crie uma L.S.E.D
	
	void cria_lista_vazia(){
		lista=(struct desc*)malloc(sizeof(struct desc));
		lista->primeiro=(struct ptr*)NULL;
		lista->ultimo=lista->primeiro;
		lista->quant=0;
	}
	
Listas duplamente encadeadas 

ex:

(desenho 4)

struct ptr{
	int valor;
	struct ptr *ant,*prox;
};	

struct desc{
	int quant;
	struct ptr *primeiro, *ultimo;
};

struct desc *lista;

ex:
	1) Criar uma L.D.E.D onde os elementos são inseridos na mesma ordme em que foram digitados.
	
	void cria_lista_dupla_desc(){
		int valor;
		cria_lista_vazia();
		printf("Entre com o valor:");
		scanf("%d",&valor);
		if(valor<0)
			printf("lista vazia");
		else{
			lista->primeiro=(struct ptr*)malloc(sizeof(struct ptr));
			lista->ultimo=lista->primeiro;
			lista->quant++;
			lista->primeiro->valor=valor;
			lista->primeiro->ant=(struct ptr*)NULL;
			lista->primeiro->prox=(struct ptr*)NULL;
			printf("entre com um valor:");
			scanf("%d",&valor);
			while(valor>=0){
				lista->ultimo->prox=(struct ptr*)malloc(sizeof(struct ptr));
				lista->ultimo->prox->ant=lista->ultimo;
				lista->ultimo=lista->ultimo->prox;
				lista->ultimo->prox=(struct ptr *)NULL;
				lista->ultimo->valor=valor;
				lista->quant++;
				printf("Entre com o valor:");
				scanf("%d",&valor);	
			}
		}	
	}
	
Listas duplamente encadeadas circulares com descritor

(desenho 5)

struct ptr{
	int valor;
	struct ptr *ant,*prox;
};

struct desc{
	int quant;
	struct ptr *primeiro,*ultimo;
};

struct desc *lista;

ex: L.D.E.C.D com apenas um elemento

(desenho 6)

Lista duplamente encadeada circular

(desenho 7)

Lista simplesmente encadeada circular

(desenho 8)

12 exercicios - L.S.E (com ou sem recursao)
12 L.D.E (com ou sem recursao)
12 L.S.E.D (com ou sem recursao)
12 L.D.E.D (com ou sem recursao)
12 L.S.E.C (com ou sem recursao)
12 L.D.E.C (com ou sem recursao)
12 L.S.E.C.D (com ou sem recursao)
12 L.D.E.C.D (com ou sem recursao)

	
