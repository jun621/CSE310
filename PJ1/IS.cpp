#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include "IS.h" 

int  insertionSort(int * A, int p, int r,  int flag, int printArray) 

{ 

int key ;
int i;  
int EWC = 0; 

 for (int i=2 ;i<= r; i++)
  {

     key = A[i];
      int j = i-1; 

    while (j>0)
   {    EWC++;

      if(flag == 1)
        {

         printf("EWC: %d > %d?\n",A[j],key);

        }
    
       if (A[j] > key ) 

       {
        A[j+1] = A[j];
         j--;
         if (printArray == 1)
          {
           printf("A[%d:%d]:",p,r);
             for (int i=p; i<=r; i++)      
              printf(" %d", A[i]);
              printf("\n");
      
           }
         
       }
       else 
       {
        break;
       }

  }

   A[j+1] = key;

     if (printArray == 1)
       {
        printf("A[%d:%d]:",p,r);
             for (int i=p ;i <=r ;i ++)
             printf(" %d", A[i]);
             printf("\n");

      }
 

}

  return EWC; 
 
}

