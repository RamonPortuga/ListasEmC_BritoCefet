//Fa�a um programa que leia um n�mero inteiro e diga se ele � par ou �mpar; OBS: Todas as vari�veis devem ser do tipo ponteiro

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
