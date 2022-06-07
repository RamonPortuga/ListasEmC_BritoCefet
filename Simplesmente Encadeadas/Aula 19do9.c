																	Estruturas din�micas de dados
		Usadas quando n�o se sabe a priori quantas vari�veis ser�o necess�rias.
								
				--Ponteiro
		-Um ponteiro � uma vari�vel cujo conte�do � o endere�o de uma posi��o de mem�ria
		-Cada ponteiro aponta para um determinado tipo de vari�vel
		
				--Declarando vari�vel ponteiro
		tipo *nomevariavel;
		
	Ex:
		int *p;//No exemplo p � uma vari�vel ponteiro para o int
		
	NULL: Constante ponteiro nulo. Usada para indicar que um ponteiro n�o aponta para nenhuma �rea de mem�ria. Null � uma constante definida no arquivo stdio.h como 0;
	
				(Para melhor defini��o dos desenhos abaixo ver: Imagem1)
	
	P | |--> vari�vel p sem incializar 
	P | |----	p=(int *)NULL; //p aponta para nada
			|
		    --
		    
	OBS: Para usar NULL � necess�rio #include<stdio.h>
	
	Alocando mem�ria: A fun��o malloc()
		Meio pelo qual uma por��o de mem�ria � alocada:
			p=(int *)malloc(sizeof (int));
	
	sizeof() produz um inteiro igual ao tamanho, em bytes, da vari�vel ou do tipo de dado que est� operando.
	Ex: sizeof (float) retornar� o valor 4, pois float tem 4 bytes
			P | |--> |		|*p
			
	OBS: 
		p: vari�vel ponteiro (endere�o de mem�ria)
		*p: conte�do de mem�ria apontada pela vari�vel ponteiro p
		
				--A fun��o free()
		A fun��o free() � o complemento da malloc(). Aceita, como argumento, um ponteiro para uma �rea de mem�ria previamente alocada por malloc() e ent�o libera
	esta �rea para uma poss�vel utiliza��o futura.
		� importante liberar a mem�ria alocada ap�s seu uso, pois esta t�cnica pode resultar numa quantidade significativa de mem�ria reutiliz�vel.
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

