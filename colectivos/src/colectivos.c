/*
 ============================================================================
 Name        : colectivos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define FILAS 4
#define COLUMNAS 13


void mostrarMatriz(int mat[4][13],int filas);
void totalizar(int mat[4][13],int filas);

int main(void) {
	setbuf(stdout,NULL);

	char seguir;
	int mat[FILAS][COLUMNAS]={0};
	int linea;
	int interno;
	int recaudacion;



	do{

        //LINEAS
		printf("HOLA MUNDOOOOOOOOO\n");
		printf("Ingrese linea 1/2/3:");
		scanf("%d",&linea);
		while(linea<=0 || linea>3){
			printf("Opcion invalida. Ingrese 1/2/3:");
			scanf("%d",&linea);
		}


		//INTERNOS
		printf("Ingrese interno (1-12):");
		scanf("%d",&interno);
          while(interno<=0 || interno>12){
		  printf("Opcion invalida. Ingrese rango (1-12):");
		  scanf("%d",&interno);
		}


        //RECAUDACION
        printf("Ingrese recaudacion: ");
        scanf("%d",&recaudacion);


        //HAGO LA RECAUDACION
        mat[linea-1][interno-1]+=recaudacion;


        //BUCLE
		printf("Desea agregar otra recaudacion? s/n:");
		fflush(stdin);
		scanf("%c",&seguir);
		while(seguir!='s' && seguir!='n'){
			printf("Opcion invalida. Ingrese s o n:");
			fflush(stdin);
			scanf("%c",&seguir);
		}
	}while(seguir=='s');



	mostrarMatriz(mat,FILAS);
	return EXIT_SUCCESS;
}

void mostrarMatriz(int mat[4][13],int filas){

	printf("                                             RECAUDACIONES \n");
	printf("                                               Internos\n");
	printf("           1      2      3      4      5      6      7      8      9      10     11     12     Total\n");
	printf("\n");
	for(int f=0; f<filas; f++){
		if(f==3){
			printf("Total: ");
		}
		else
		{
			printf("Linea %d",f+1);
		}
		for(int c=0; c<13; c++){
			printf("    %d  ",mat[f][c]);

		}
		printf("\n");
	}
}


void totalizar(int mat[4][13],int filas){

	for(int i=0; i<filas-1; i++){
		for(int j=0; j<12; j++){
			mat[i][12]+=mat[i][j];
		}
	}
}
