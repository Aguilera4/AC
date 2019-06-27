#!/bin/bash
#Se asigna al trabajo el nombre SumaVectoresC_vlocales
#PBS -N ejercicio11
#Se asigna al trabajo la cola ac
#PBS -q ac
#Se imprime información del trabajo usando variables de entorno de PBS
echo "Id. usuario del trabajo: $PBS_O_LOGNAME"
echo "Id. del trabajo: $PBS_JOBID"
echo "Nombre del trabajo especificado por usuario: $PBS_JOBNAME"
echo "Nodo que ejecuta qsub: $PBS_O_HOST"
echo "Directorio en el que se ha ejecutado qsub: $PBS_O_WORKDIR"
echo "Cola: $PBS_QUEUE"

echo "pmv-OpenMP-a"

$PBS_O_WORKDIR/pmv-OpenMP-a 30000 1
$PBS_O_WORKDIR/pmv-OpenMP-a 30000 2
$PBS_O_WORKDIR/pmv-OpenMP-a 30000 3
$PBS_O_WORKDIR/pmv-OpenMP-a 30000 4
$PBS_O_WORKDIR/pmv-OpenMP-a 30000 5
$PBS_O_WORKDIR/pmv-OpenMP-a 30000 6
$PBS_O_WORKDIR/pmv-OpenMP-a 30000 7
$PBS_O_WORKDIR/pmv-OpenMP-a 30000 8
$PBS_O_WORKDIR/pmv-OpenMP-a 30000 9
$PBS_O_WORKDIR/pmv-OpenMP-a 30000 10
$PBS_O_WORKDIR/pmv-OpenMP-a 30000 11
$PBS_O_WORKDIR/pmv-OpenMP-a 30000 12

