#!/bin/bash
#Se asigna al trabajo el nombre pmm_OpenMP_atcgrid
#PBS -N pmm_OpenMP_atcgrid
#Se asigna al trabajo la cola ac
#PBS -q ac
#Se imprime información del trabajo usando variables de entorno de PBS
echo "Id. usuario del trabajo: $PBS_O_LOGNAME"
echo "Id. del trabajo: $PBS_JOBID"
echo "Nombre del trabajo especificado por usuario: $PBS_JOBNAME"
echo "Nodo que ejecuta qsub: $PBS_O_HOST"
echo "Directorio en el que se ha ejecutado qsub: $PBS_O_WORKDIR"
echo "Cola: $PBS_QUEUE"
echo "Nodos asignados al trabajo:"
cat $PBS_NODEFILE


export OMP_DYNAMIC=FALSE

echo "\nTiempo secuencial con 100"
./pmm-secuencial 100

echo "Tiempo secuencial con 500"
./pmm-secuencial 500

echo "\nTiempo secuencial con 1000"
./pmm-secuencial 1000

echo "Tiempo secuencial con 1500"
./pmm-secuencial 1500





export OMP_NUM_THREADS=2
echo "\nTiempo con dos threads con 100"
./pmm-OpenMP 100


echo "Tiempo con dos threads con 500"
./pmm-OpenMP 500


echo "Tiempo con dos threads con 1000"
./pmm-OpenMP 1000


echo "Tiempo con dos threads con 1500"
./pmm-OpenMP 1500




export OMP_NUM_THREADS=4
echo "\nTiempo con cuatro threads con 100"
./pmm-OpenMP 100


echo "Tiempo con cuatro threads con 500"
./pmm-OpenMP 500

echo "Tiempo con cuatro threads con 1000"
./pmm-OpenMP 1000


echo "Tiempo con cuatro threads con 1500"
./pmm-OpenMP 1500

