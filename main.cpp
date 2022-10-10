#include <iostream> 
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "IS.h"
#include "MS.h"
#include "QS.h" 
#include <fstream> 
#include <string>

using namespace std; 
int mergeSort(int *A,int p,int r,int  flag ,int printArray );
int quickSort(int *A,int p,int r,int flag,int printArray ) ;
int insertionSort(int * A, int p,int r,int  flag , int printArray ) ; 


void Error() ; 

int main (int argc, char  *argv[]) { 

  
int *A; 

 int n;
int flag ;
int alg ; 
int EWC ; 
FILE *fp; 
int printResult ,printArray; 
 

 if ( argc !=3)
   { 
   Error() ; 
   exit (1) ; 
   } 

 if (flag !=0 && flag != 1) 
 { 
  Error() ; 
  exit (1) ; 
 }

 if (strcmp(argv[1], "InsertionSort")==0 ) {
     alg = 1 ; 
  }
 else if (strcmp ( argv[1] , "MergeSort" ) ==0 ) 
  {
   alg = 2; 
  }
 else if ( strcmp ( argv[1] , "QuickSort") == 0) 
  {
   alg = 3;
  }
  
 if (strcmp(argv[2], "0") ==0)
  {
   flag = 0;
   
  }
 if (strcmp(argv[2], "1") ==0 )
  { 

   flag = 1; 
  
  }

  fp = fopen("INPUT.txt", "r"); 

  if (fp == NULL)
  { 
  printf("Error: cannot open file INPUT.txt");
 return 0; 

  }

 fscanf(fp, "%d", &printResult);
 fscanf(fp, "%d", &printArray); 
 fscanf(fp, "%d", &n);  

   A = (int*)malloc(n*sizeof(int));
  if (A == NULL) 
  { 
  printf("Error: cannot allocate any memory\n"); 
  exit(1) ;
 }
   
 for (int i = 1; i <= n  ;i++)
   { 
   fscanf(fp,"%d",&A[i]);
   } 
  
 
   fclose(fp); 


  switch (alg)
   { 
  
  case 1 :  EWC = insertionSort(A, 1, n, flag, printArray) ; 
            break; 
  
  case 2:   EWC = mergeSort( A, 1, n , flag , printArray) ;
            break ; 

 
  case 3:   EWC =  quickSort( A, 1,n , flag ,printArray) ;
            break; 
 
   } 
 
if (printResult == 1 ) 
{ 
printf("A[1:%d] after sorting:",n );

for (int i = 1; i<=n ; i++) 
 {
 printf (" %d", A[i]);

 
 }
printf("\n");

}  
  
  printf ("Number of EWCs: %d\n" , EWC) ; 
  free(A); 
  return 0; 

} 

void Error () { 
 printf("Usage: ./PJ1 alg flag\n");
 printf("       alg should be in {InsertionSort, MergeSort, QuickSort}\n");
 printf("       flag should be in {0, 1}\n");

} 

