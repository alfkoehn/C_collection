/**
 * Author:      Alf Köhn-Seemann
 * Email:       koehn@igvp.uni-stuttgart.de
 * Copyright:   University of Stuttgart
 *
 * This is an example on how to parallilize nested for loops using OpenMP.
 * Compile with
 *  gcc -fopenmp
 *
 * Initial release on github: 2022-08-22
 *
 **/

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() {
    int ii, jj, kk,
        a, b, c; 

    a   = 3;
    b   = 2;
    c   = 5;

#pragma omp parallel for collapse(3)
    for (ii=1 ; ii<=a ; ++ii)
        for (jj=1; jj<=b ; ++jj)
            for (kk=1; kk<=c ; ++kk)
                printf( "ii=%1d, jj=%1d, kk=%1d, thread=%1d\n",
                        ii, jj, kk, omp_get_thread_num() );

    return 0;
}

