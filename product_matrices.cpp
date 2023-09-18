#include<iostream>
#include <bits/stdc++.h>
using namespace std;

const int nROWS_1= 3;
const int n= 4;
const int nCOLUMNS_2= 3;


double A[nROWS_1][n];
double B[n][nCOLUMNS_2];

double product_A_B[nROWS_1][nCOLUMNS_2];


//Clasical Product:

void classical_matrices_product(){
    
    //Initializing Product A x B
    for(int i=0;i<nROWS_1;i++){
        for(int j=0;j<nCOLUMNS_2;j++){
            product_A_B[i][j]=0;
        }
        
    }



    
    //Product:

    for(int i=0;i<nROWS_1;i++){
        for(int j=0;j<nCOLUMNS_2;j++){

            for(int k=0;k<n;k++){

                product_A_B[i][j]+=A[i][k]*B[k][j];
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

    cout<<"A: "<<endl;
    //Initializing A
    for(int i=0;i<nROWS_1;i++){
        for(int j=0;j<n;j++){
            A[i][j]=rand()%5;
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    cout<<"B: "<<endl;

    //Initializing B
    for(int i=0;i<n;i++){
        for(int j=0;j<nCOLUMNS_2;j++){
            B[i][j]=rand()%5;
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
        
    }

    //Make product
    classical_matrices_product();

    cout<<"Product"<<endl;
    
    for(int i=0;i<nROWS_1;i++){
        for(int j=0;j<nCOLUMNS_2;j++){

            

            cout<<product_A_B[i][j]<<" ";
            


        }
        cout<<endl;
    
    }
    


    clock_t start, end;
 
    /* Recording the starting clock tick.*/
    start = clock();
 
    
    // Recording the end clock tick.
    end = clock();
 


    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by first nested loop is : " << fixed<< time_taken << setprecision(5);
    cout << " sec " << endl;
    
    


    /* Recording the starting clock tick.*/
    start = clock();
 
    
    // Recording the end clock tick.
    end = clock();
 
    // Calculating total time taken by the program.
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by second nested loop is : " << fixed<< time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;

    // Time taken by first nested loop is : 0.330000 sec 
    // Time taken by second nested loop is : 0.99800 sec 
}