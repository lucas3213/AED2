#include <stdio.h>
#include <stdlib.h>
typedef int** MatrizAdjacencia;
MatrizAdjacencia CriaGrafo(int vertices){
	int i,j;
	
	MatrizAdjacencia M;
	
	M = malloc(vertices * sizeof(int*));
	for(i = 0;i<vertices;i++){
		M[i] = malloc(vertices * sizeof(int));
		for(j=0;j<vertices;j++){
			M[i][j] = 0;
		}
	}	
	return M;
	
	
}

void mostra_matriz(int vertices,MatrizAdjacencia m){
    int i,j;
    for(i = 0;i<vertices;i++){
		for(j=0;j<vertices;j++){
			printf("%d", m[i][j] );
		}
         printf("\n");
	}	
       
}


int main(){
	MatrizAdjacencia G;
	int vertices = 4;
	G = CriaGrafo(vertices);
    mostra_matriz(vertices,G);
}