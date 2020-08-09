#include <stdio.h>
#include <stdlib.h>

typedef int** matriz_adjacencia;

void mostra_matriz(int linhas, int vertices,matriz_adjacencia m){
    int i,j;
    for(i = 1;i < linhas;i++){
		for(j = 0;j < vertices;j++){
			printf("%d", m[i][j]);
		}
         printf("\n");
	}	     
}

matriz_adjacencia cria_grafo(int vertices){
	int i,j;
	matriz_adjacencia m = malloc(vertices * sizeof(int*));
	for(i = 0;i<vertices;i++){
		m[i] = malloc(vertices * sizeof(int));
		for(j=0;j<vertices;j++){
			printf("[] = ");
			scanf("%d",&m[i][j]);
		}
		printf("\n");
		mostra_matriz(i,vertices,m);
	}	
	return m;
}

void confirma_ligacao(int valor_linha, int valor_coluna, matriz_adjacencia m){
	if (m[valor_linha][valor_coluna])
	{
		printf("HÁ INTERLIGACAO \n");
	}else{
		printf("NÃO HÁ INTERLIGACAO \n");
	}
}

int verifica_ligacao(int continuar_processo, matriz_adjacencia m){
	int valor_linha,valor_coluna = 0;
	while(continuar_processo){
		printf("verificacao de interligacao de valores,informe-os:\n");
		printf("valor linha: \n");
		scanf("%d",&valor_linha);
		printf("valor coluna: \n");
		scanf("%d",&valor_coluna);
		printf("############################### RESPOSTA ############################################3\n");
		confirma_ligacao(valor_linha,valor_coluna,m);
		printf("###########################################################################3\n");
		printf("quer continuar com o processo de verificao?\n");
		scanf("%d",&continuar_processo);
		if(continuar_processo > 1 || continuar_processo < 0){
			while(continuar_processo > 1 || continuar_processo < 0){
				printf("erro ao continuar o processo de verificacao. \n");
				printf("insira uma resposta valida. \n");
				printf("quer continuar com o processo de verificao?\n");
				scanf("%d",&continuar_processo);
			}
		}
		return verifica_ligacao(continuar_processo, m);
	}
	return 0 ;
}

int main(){
	matriz_adjacencia g;
	int vertices = 2;
	int f;
	int continuar_processo = 1;
	g = cria_grafo(vertices);
    f=verifica_ligacao(continuar_processo , g);
}

// QUEST 1: Este algoritmo foi escolhido mais por ser de facil entendimento e execução mas estou ciente que o ideal seria a lista adjacencia