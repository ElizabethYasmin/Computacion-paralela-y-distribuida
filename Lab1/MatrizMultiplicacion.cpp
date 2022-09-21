#include <iostream>
//#include <bits/stdc++.h>
#include <stdlib.h>
#include <iomanip> 
//#include <sys/time.h> 
#include <chrono>


using namespace std;

//#define RAND_MAX 10
#define MAX 4096

double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

int main() { 
    
    
    auto start = std::chrono::high_resolution_clock::now();
    // Inicializacion de Matrices
    
    for(int i = 0; i < MAX; ++i)
        for(int j = 0; j < MAX; ++j)
        {
            A[i][j] = (double)rand()/ (double)RAND_MAX;
            B[i][j] = (double)rand()/ (double)RAND_MAX;
            C[i][j] = 0;
        }

    //Con chrono


    //struct timeval start, end; 
  
    // Empezando el contador de tiempo 
    //gettimeofday(&start, NULL); 
  
    // unsync the I/O of C and C++. 
    ios_base::sync_with_stdio(false);

    // Multiplicacion de matrices
    for(int i = 0; i < MAX; ++i)
        for(int j = 0; j < MAX; ++j)
            for(int k = 0; k < MAX; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
    
    //gettimeofday(&end, NULL); 
  
/*     // Calculating total time taken by the program. 
    double time_taken; 
  
    time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
    time_taken = (time_taken + (end.tv_usec -  
                              start.tv_usec)) * 1e-6; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(6); 
    cout << " sec" << endl; */

    auto end = std::chrono::high_resolution_clock::now();
    auto int_s = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << int_s << " microseconds\n";
    return 0;
}
