																	Estruturas dinâmicas de dados
		Usadas quando não se sabe a priori quantas variáveis serão necessárias.
								
				--Ponteiro
		-Um ponteiro é uma variável cujo conteúdo é o endereço de uma posição de memória
		-Cada ponteiro aponta para um determinado tipo de variável
		
				--Declarando variável ponteiro
		tipo *nomevariavel;
		
	Ex:
		int *p;//No exemplo p é uma variável ponteiro para o int
		
	NULL: Constante ponteiro nulo. Usada para indicar que um ponteiro não aponta para nenhuma área de memória. Null é uma constante definida no arquivo stdio.h como 0;
	
				(Para melhor definição dos desenhos abaixo ver: Imagem1)
	
	P | |--> variável p sem incializar 
	P | |----	p=(int *)NULL; //p aponta para nada
			|
		    --
		    
	OBS: Para usar NULL é necessário #include<stdio.h>
	
	Alocando memória: A função malloc()
		Meio pelo qual uma porção de memória é alocada:
			p=(int *)malloc(sizeof (int));
	
	sizeof() produz um inteiro igual ao tamanho, em bytes, da variável ou do tipo de dado que está operando.
	Ex: sizeof (float) retornará o valor 4, pois float tem 4 bytes
			P | |--> |		|*p
			
	OBS: 
		p: variável ponteiro (endereço de memória)
		*p: conteúdo de memória apontada pela variável ponteiro p
		
				--A função free()
		A função free() é o complemento da malloc(). Aceita, como argumento, um ponteiro para uma área de memória previamente alocada por malloc() e então libera
	esta área para uma possível utilização futura.
		É importante liberar a memória alocada após seu uso, pois esta técnica pode resultar numa quantidade significativa de memória reutilizável.
		Ex:free(p);
		
	Ex:
		#include<stdio.h>
		int *p1,*p2;
		main(){
			p1= (int *) NULL;
			p2= (int *) malloc(sizeof(int));
			p1= (int *) malloc(sizeof(int));
			*p2=20;
			*p1=*p2;
			p2=p1; 
		}

