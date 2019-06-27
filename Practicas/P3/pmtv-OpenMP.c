#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
	#define omp_get_num_threads() 1
	#define omp_set_num_threads(int)
	#define omp_in_parallel() 0
	#define omp_set_dynamic(int)
#endif

	int main ( int argc, char **argv ){

		int j,debug = 0;

		if( argc < 2 ){
			fprintf(stderr, "Falta tamaño\n");
			exit(-1);
		}

		if ( argc == 3 ){
			debug = atoi(argv[2]);
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
			for(  j=i; j<N; j++){
				matriz[i][j] = 2;
				vector[i] = 4;
				result[i] = 0;
			}
		}

		if ( debug == 1 ){

			printf("\nMATRIZ\n");
			for( int i=0; i<N; i++ ){
				for(  j=0; j<N; j++ ){
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
		
		}

		double comienzo, fin, total;
		comienzo = omp_get_wtime();


		#pragma omp parallel for private(j) schedule(runtime)
		for (int i = 0; i < N; i++){
			for ( int j=i; j<N; j++ ){
				result[i] += matriz[i][j] * vector[j];
			}
		}

		fin = omp_get_wtime();
		total = fin - comienzo;

		if ( debug == 1 ){
			printf("\nRESULTADOS\n");
			for ( int i=0; i<N; i++ ){
				printf("%d ", result[i]);
			}
				printf("\n\n");
		}


		printf("Tiempo: %11.9f\t Primera: %d\t Ultima: %d\n", total, result[0], result[N-1]);


		for (int i = 0; i < N; ++i){
			free(matriz[i]);
		}
		
		free(matriz);
		free(vector);
		free(result);

		return 0;

	}