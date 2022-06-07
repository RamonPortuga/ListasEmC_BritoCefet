#include <stdio.h>
int *n,i,aux;
main(){
	printf("Entre com um numero:\t");
	n=(int*)malloc(sizeof(int));
	scanf("%d",n);
	printf("EI\n\n");
	i=0;
	while(i!=n){
		printf("EI\n\n");
		if((*n%i)!=0){
			printf("EI\n\n");
			aux++;
		}
		i++;
	}
	if(aux==0)
		printf("Primo");
	else
		printf("Nao e primo");
}
