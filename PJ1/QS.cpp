

#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include"QS.h" 


int partition(int *A, int p, int r ,int& EWC,   int flag, int printArray) 
{ 

 
int i = p-1 ; 

for (int j= p; j <r ; j++)
{
  
  EWC++; 
  if (flag ==1)
  {
  printf("EWC: %d <= %d?\n", A[j], A[r]);
    
 }

  if (A[j] <= A[r])
  {
    i++;
    int temp = A[j];
        A[j] = A[i];
        
    if ( printArray ==1) 
    { 
    printf("A[%d:%d]:" ,p,r);
    for (int i=p; i<= r; i++)
    printf(" %d", A[i]);
    printf("\n");
    }
   A[i] = temp; 
   
   if(printArray == 1) 
    { 
     printf("A[%d:%d]:", p,r);
     for (int i=p; i<=r; i++)
     printf(" %d", A[i]);
     printf("\n");
     }

  }
}

  int temp = A[i+1] ;
     A[i+1] = A[r];
    if (printArray==1)
    {
    printf("A[%d:%d]:",p,r);
    for (int i =p; i<= r ;i++)
     printf(" %d", A[i]);
     printf("\n");

    }
   A[r] = temp; 
    if (printArray ==1)
    { 
    printf("A[%d:%d]:", p,r) ;
    for (int i=p; i<= r ;i++)
    printf(" %d", A[i]) ;
    printf("\n");
 
    }
   return i+1; 
}

 int  quickSort ( int *A , int p , int r ,  int flag, int printArray ) 
{ 
   if (p >=r)
  {
  return 0;  
  }
  int EWC =0;
  int q = partition(A , p ,r ,EWC, flag , printArray) ; 
  int left=    quickSort( A ,p , q -1,  flag, printArray) ;
  int right =   quickSort( A, q+1 , r , flag , printArray) ; 
  

    return  EWC + left + right ; 

} 
