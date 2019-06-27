#include <stdlib.h>
#include <stdio.h>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thead_num() 0
#endif

#define MAX 1000

int main (int argc, char** argv)
{
   
    double tiempo1, tiempo2, total;
    int p;
    
    
    if (argc<2)
    {
        printf("Falta tamaño de la matriz y del vector\n");
        exit(-1);
    }
    
      unsigned int N = atoi(argv[1]);
    
    double *vector1, *vector2, **matriz;
    vector1 = (double*) malloc(N*sizeof(double));
    vector2 = (double*) malloc(N*sizeof(double));
    matriz = (double**) malloc(N*sizeof(double *));
    
    if ( (vector1==NULL) || (vector2==NULL) || (matriz==NULL) ){
        printf("Error en la reserva de memoria para los vectores");
        exit(-2);
    }
    
    for ( int i=0; i<N; i++ ){
        matriz[i] = (double*) malloc(N*sizeof(double));
        if(matriz[i]==NULL){
            printf("Error en la reserva de memoria para los vectores");
            exit(-2);
        }
    }
   
    
    
    
    
    for(int m=0; m<N; m++){
        
        vector1[m]=m;
        vector2[m]=0;
        
        #pragma omp parallel for
        for ( int k=0; k<N; k++){
            matriz[m][k]=m+k;
        }
    }
    
    tiempo1= omp_get_wtime();
    
    for ( int t=0; t<N; t++){
        #pragma omp parallel
        {
            double tmp=0;
            #pragma omp for
            for(int n=0; n<N; n++){
                tmp+=matriz[t][n] * vector1[n];
        }
            
        #pragma omp critical
            vector2[t]+=tmp;
        }
    }
    
    tiempo2= omp_get_wtime();
    
    total = tiempo2 - tiempo1;
        
    printf("Tiempo: %11.9f\t / Tamaño:%u\t/ vector2[0]=%8.6f vector2[%d]=%8.6f\n", total,N,vector2[0], N-1, vector2[N-1]);
    
    
    if (N<20)
    {
        for(int m=0; m<N; m++)
        {
            printf(" vector2[%d]=%5.2f\n", m, vector2[m]);
        }
    }
    
    free(vector1);
    free(vector2);
    
    for(int z=0; z<N; z++)
    {
        free(matriz[z]);
    }
    
    free(matriz);
    
    return 0;
    
    
}
