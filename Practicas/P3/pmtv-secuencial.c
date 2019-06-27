#include <stdlib.h>
#include <stdio.h>
#include <time.h>

	int main ( int argc, char **argv ){
		if( argc < 2 ){
			fprintf(stderr, "Falta tamaño\n");
			exit(-1);
		}

		unsigned int N = atoi(argv[1]);

		int *vector, *result, **matriz;
		vector = (int *) malloc(N*sizeof(int));
		result = (int *) malloc(N*sizeof(int));
		matriz = (int **) malloc(N*sizeof(int*));

		for( int i=0; i<N; i++ ){
			matriz[i] = (int*) malloc(N*sizeof(int));
		}

		for( int i=0; i<N; i++){
			for( int j=i; j<N; j++){
				matriz[i][j] = 4;
				vector[i] = 2;
				result[i] = 0;
			}
		}

		printf("\nMATRIZ\n");
		for( int i=0; i<N; i++ ){
			for( int j=0; j<N; j++ ){
				if (j>= i){
					printf("%d ", matriz[i][j]);
				}
				else{
					printf("0 ");
				}
			}
			printf("\n");
		}
	

		printf("\nVECTOR\n");
		for ( int i=0; i<N; i++ ){
			printf("%d ", vector[i] );
		}
		printf("\n");


		for (int i = 0; i < N; i++){
			for ( int j=i; j<N; j++ ){
				result[i] += matriz[i][j] * vector[j];
			}
			
		}

		printf("\nRESULTADOS\n");
		for ( int i=0; i<N; i++ ){
			printf("%d ", result[i]);
		}
			printf("\n\n");

	    printf("Primera: %d\t Ultima: %d\n", result[0], result[N-1]);

	    printf("\n\n");

		for (int i = 0; i < N; ++i){
			free(matriz[i]);
		}
		
		free(matriz);
		free(vector);
		free(result);

		return 0;

	}