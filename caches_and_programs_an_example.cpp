//Book: http://www.e-tahtam.com/~turgaybilgin/2013-2014-guz/ParalelProgramlama/ParallelProg.pdf

// #include<iostream>
// #include<ctime>
// 
// #define MAX 200

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAX= 10000;

double A[MAX][MAX];
double x[MAX];
double y[MAX];





void first_pair_loop(){

    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            y[i]+=A[i][j]*x[j];
        }


    }
}


void second_pair_loop(){
    for(int j=0;j<MAX;j++){
        for(int i=0;i<MAX;i++){
            y[i]+=A[i][j]*x[j];
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

    //Initializing A
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            A[i][j]=rand();
        }
    }
    //Initializing x and y
    for(int i=0;i<MAX;i++){
        x[i]=rand();
        y[i]=0;
    }


    
    
    
    
    clock_t start, end;
 
    /* Recording the starting clock tick.*/
    start = clock();
 
    first_pair_loop();
 
    // Recording the end clock tick.
    end = clock();
 


    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by first nested loop is : " << fixed<< time_taken << setprecision(5);
    cout << " sec " << endl;
    
    
    //Initializing y with 0s
    for(int i=0;i<MAX;i++){
        
        y[i]=0;
    }


    /* Recording the starting clock tick.*/
    start = clock();
 
    second_pair_loop();
 
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