#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	int main (int argc, char **argv){

		if (argc < 2){
			fprintf(stderr, "FALTA TAMAÑO\n");
			exit(-1);
		}


		unsigned int N = atoi(argv[1]);

		int **a, **b, **c;

		a = (int **) malloc(N*sizeof(int*));
		b = (int **) malloc(N*sizeof(int*));
		c = (int **) malloc(N*sizeof(int*));

		for (int i=0; i<N; i++){
			a[i] = (int *) malloc(N*sizeof(int));
			b[i] = (int *) malloc(N*sizeof(int));
			c[i] = (int *) malloc(N*sizeof(int));
		}

		for(int i=0; i<N; i++){
			for( int j=0; j<N; j++){
				a[i][j] = 0;
				b[i][j] = 2;
				c[i][j] = 2;
			}
		}

		struct timespec cgt1,cgt2; double ncgt;

		clock_gettime(CLOCK_REALTIME, &cgt1);

		for( int i=0; i<N; i++){
			for( int j=0; j<N; j++){
				for ( int k=0; k<N; k++){
					a[i][j] += b[i][k] * c[k][j];
				}
			}
		}

		clock_gettime(CLOCK_REALTIME, &cgt2);

		ncgt = (double) (cgt2.tv_sec - cgt1.tv_sec)+(double) ((cgt2.tv_nsec - cgt1.tv_nsec))/(1.e+9);
		printf("Tiempo: %11.9F\t Primera: %d\t Ultima: %d\n",ncgt,a[0][0], a[N-1][N-1]);

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
