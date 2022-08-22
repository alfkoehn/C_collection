/**
 * Author:      Alf Köhn-Seemann
 * Email:       koehn@igvp.uni-stuttgart.de
 * Copyright:   University of Stuttgart
 *
 * This is an example on how to parallilize nested for loops using OpenMP
 * and correctly sum over the loop iteration variables.
 * Compile with
 *  gcc -fopenmp -Wall
 *
 * Initial release on github: 2022-08-22
 *
 **/
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() {
    int ii, jj, kk,
        a, b, c, 
        x;

    a   = 3;
    b   = 2;
    c   = 5;
    x   = 0;

#pragma omp parallel for collapse(3) reduction(+:x)
    for (ii=1 ; ii<=a ; ++ii)
        for (jj=1; jj<=b ; ++jj)
            for (kk=1; kk<=c ; ++kk)
                x += ii+jj+kk;

    printf( "x = %d (should be 195) \n", x );

    return 0;
}

