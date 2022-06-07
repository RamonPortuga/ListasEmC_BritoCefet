//Elabore um algoritmo que preencha uma matriz 5 x 5 com números inteiros e verifique se essa matriz forma o
//chamado quadrado mágico. Um quadrado mágico é formado quando a soma dos elementos de cada linha é igual
//à soma dos elementos de cada coluna dessa linha, é igual à soma dos elementos da diagonal principal e, também
//é igual à soma dos elementos da diagonal secundária (veja desenho acima: diagonal principal e diagonal
//secundária).

#include <stdio.h>
#define TAM 3
#define TAM2 3
int m[TAM][TAM2],i,j,sl[TAM],sc[TAM2],sdp,sds,cont,cont2;
main(){
	cont=0;
	cont2=0;
	for(i=0;i<TAM;i++){
		for(j=0;j<TAM2;j++){
			printf("\nEntre com o elemento da casa [%d][%d] dessa matriz:\t",i,j);
			scanf("%d",&m[i][j]);
		}
	}
	for(i=0;i<TAM;i++){
		for(j=0;j<TAM2;j++){
			sl[i]+=m[j][i];
			sc[i]+=m[i][j];
			if(i==j)
				sdp+=m[i][j];
		}
	}
	for(i=0;i<TAM;i++){
		for(j=TAM2-1;j>=0;j--){
			if(i==(TAM-1-i))
				sds+=m[i][j];
		}
	}
	for(i=0;i<TAM;i++){
		if(sl[i]==sdp)	
			cont++;
	}
	for(i=0;i<TAM2;i++){
		if(sc[i]==sdp)	
			cont2++;
	}
	if((cont==cont2)&&(sds=sdp))
		printf("\nEssa matriz %c um quadrado m%cgico",130,160);
	else
		printf("\nN%co %c um quadrado m%cgico",199,130,160);
}
