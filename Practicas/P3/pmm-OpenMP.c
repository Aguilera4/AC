#include <stdio.h>
#include <stdlib.h>
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

	int main (int argc, char **argv){

		int i, j, k;

		if (argc < 2){
			fprintf(stderr, "FALTA TAMAÑO\n");
			exit(-1);
		}


		unsigned int N = atoi(argv[1]);

		int **a, **b, **c;

		a = (int **) malloc(N*sizeof(int*));
		b = (int **) malloc(N*sizeof(int*));
		c = (int **) malloc(N*sizeof(int*));

		for ( i=0; i<N; i++){
			a[i] = (int *) malloc(N*sizeof(int));
			b[i] = (int *) malloc(N*sizeof(int));
			c[i] = (int *) malloc(N*sizeof(int));
		}

		for( i=0; i<N; i++){
			for( int j=0; j<N; j++){
				a[i][j] = 0;
				b[i][j] = 2;
				c[i][j] = 2;
			}
		}

		double comienzo, fin, total;
		comienzo = omp_get_wtime();



		#pragma omp parallel for private(k,j)
		for(  i=0; i<N; i++){
			for(  j=0; j<N; j++){
				for (  k=0; k<N; k++){
					a[i][j] += b[i][k] * c[k][j];
				}
			}
		}

		fin = omp_get_wtime();

		total = fin - comienzo;
	

		
		printf("Tiempo: %11.9F\t Primera: %d\t Ultima: %d\n",total,a[0][0], a[N-1][N-1]);

		for(int i=0; i<N; i++){
			free(a[i]);
			free(b[i]);
			free(c[i]);
		}

		free(a);
		free(b);
		free(c);

		return 0;
	}
