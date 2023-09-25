#include<iostream>
#include <bits/stdc++.h>
using namespace std;

const int nROWS_1= 110;
const int n= 120;
const int nCOLUMNS_2=85;


double A[nROWS_1][n];
double B[n][nCOLUMNS_2];

double standard_product_A_B[nROWS_1][nCOLUMNS_2];

double blocks_product_A_B[nROWS_1][nCOLUMNS_2];

const int MAX_SIZE = 100; // Define el tamaño máximo de las matrices
// 
// Tamaño del bloque para la multiplicación por bloques



int cacheSize = 32768; // Tamaño de la caché en bytes (ajusta esto según tu hardware)
int elementSize = sizeof(double); // Tamaño de cada elemento en bytes

// Calcula el tamaño máximo de bloque basado en el tamaño de la caché
int MAX_BLOCK_SIZE = std::sqrt(cacheSize / (elementSize * 3));

// Asegúrate de que el tamaño del bloque no exceda las dimensiones de las matrices
const int BLOCK_SIZE  = std::min({MAX_BLOCK_SIZE, nROWS_1, nCOLUMNS_2, n});



//block product

void multiplyMatrixBlocks() {
    //Initializing Product A x B
    for(int i=0;i<nROWS_1;i++){
        for(int j=0;j<nCOLUMNS_2;j++){
            blocks_product_A_B[i][j]=0;
        }
        
    }

    //Product:

    for (int i = 0; i < nROWS_1; i += BLOCK_SIZE) {
        for (int j = 0; j < nCOLUMNS_2; j += BLOCK_SIZE) {
            for (int k = 0; k < n; k += BLOCK_SIZE) {
                // Multiplicación de bloques
                for (int ii = i; ii < std::min(i + BLOCK_SIZE, nROWS_1); ii++) {
                    for (int jj = j; jj < std::min(j + BLOCK_SIZE, nCOLUMNS_2); jj++) {
                        double sum = 0;
                        for (int kk = k; kk < std::min(k + BLOCK_SIZE, n); kk++) {
                            sum += A[ii][kk] * B[kk][jj];
                        }
                        blocks_product_A_B[ii][jj] += sum;
                    }
                }
            }
        }
    }
}


//Clasical Product:

void classical_matrices_product(){
    
    //Initializing Product A x B
    for(int i=0;i<nROWS_1;i++){
        for(int j=0;j<nCOLUMNS_2;j++){
            standard_product_A_B[i][j]=0;
        }
        
    }



    
    //Product:

    for(int i=0;i<nROWS_1;i++){
        for(int j=0;j<nCOLUMNS_2;j++){

            for(int k=0;k<n;k++){

                standard_product_A_B[i][j]+=A[i][k]*B[k][j];
            }


        }
    
    }
}




 
int main()
{
    srand(time(0));
    /* clock_t clock(void) returns the number of clock ticks
       elapsed since the program was launched.To get the number
       of seconds used by the CPU, you will need to divide by
       CLOCKS_PER_SEC.where CLOCKS_PER_SEC is 1000000 on typical
       32 bit system.  */

  
    // Initializing A
    for(int i=0;i<nROWS_1;i++){
        for(int j=0;j<n;j++){
            A[i][j]=rand()%5;
        }
        
    }
    

    // Initializing B
    for(int i=0;i<n;i++){
        for(int j=0;j<nCOLUMNS_2;j++){
            B[i][j]=rand()%5;
        }
        
    }
    

    //Measuring the execution time 
    //of the classic method 

    clock_t start, end;
    double time_taken ;
    
    start = clock();
    classical_matrices_product();
    end = clock();
   
    
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by classic method is : " << fixed<< time_taken << setprecision(5);
    cout << " sec " << endl;
    
    
    //Measuring the execution time 
    //of the blocks method 
    start = clock();
    multiplyMatrixBlocks();
    end = clock();
 

    // Calculating total time taken by the program.
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by block method is : " << fixed<< time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;

}
