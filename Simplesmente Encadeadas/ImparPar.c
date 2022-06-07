//Faça um programa que leia um número inteiro e diga se ele é par ou ímpar; OBS: Todas as variáveis devem ser do tipo ponteiro

#include <stdio.h>
int *n;
main(){
	printf("Entre com um numero:\t");
	n=(int*)malloc(sizeof(int));
	scanf("%d",n);
	if((*n%2)==0)
		printf("%d e par",*n);
	else
		printf("%d e impar",*n);
}
