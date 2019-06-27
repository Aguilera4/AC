#!/bin/bash

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

