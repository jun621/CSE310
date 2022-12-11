#include <stdlib.h> 
#include <stdio.h>
#include"MS.h" 


int  Merge( int *A  , int p, int q , int r , int flag, int printArray ) { 
  
 int nL = q-p + 1; 
 int nR = r-q ; 
 int EWC = 0;

int leftA[nL];
int rightA[nR];


for (int i=0 ; i< nL ; i++)
{ 

leftA[i] = A[p+i];

}
 
for (int j=0 ; j< nR ;j++)
{
rightA[j] = A[q+1+j];

}

int a=0;
int b=0;
int k=p ;


 while (a <nL && b < nR)
   
  {  EWC++;
     if (flag == 1)
     {
     printf("EWC: %d <= %d?\n", leftA[a],rightA[b]);
    
     }

    if (leftA[a] <= rightA[b])
    
    {
      A[k] = leftA[a];
      a++; 
      
      if (printArray == 1)
      {

      printf("A[%d:%d]:", p, r);
        for(int i=p; i<=r ;i++)
        printf(" %d", A[i]);
        printf("\n");
    
      }

       
     }
     else 
     { 
    
     A[k] = rightA[b];
      b++;
       if (printArray ==1)
       {
        printf("A[%d:%d]:",p,r);
         for (int i=p; i<=r; i++)
         printf(" %d", A[i]);
          printf("\n");
        }
     }
      k++; 
    }

   while (a <nL)
      {  
     
      A[k] = leftA[a];
         a++;
         k++;
          if (printArray ==1 )
            {
             printf("A[%d:%d]:",p, r);
               for (int i=p; i<=r ;i++)
                  printf("%d",A[i]);
                  printf("\n");
             }
                
        }

         while (b < nR)

         {
         A[k] = rightA[b];
           b++;
           k++;
           if (printArray== 1)
           {
              printf("A[%d:%d]:", p, r);
    
               for (int i=p; i<=r ;i++)
                printf(" %d", A[i]);

                printf("\n");
            }
         }   


     return EWC++; 
}

 
 






 int  mergeSort ( int *A , int p, int r ,   int flag , int printArray )  
 {
   
 if (p >= r ) 
  { 
 return 0; 
  
  }  
 
int mid = p + (r-p) /2;

int leftmerge  =  mergeSort( A, p, mid , flag, printArray) ; // mergesort left half 
int rightmerge =  mergeSort( A, mid+1, r ,  flag, printArray) ; // mergeSort rigth half
int merge =  Merge(A, p ,mid , r , flag , printArray) ;  
  
  
return  leftmerge + rightmerge + merge ; 

 

} 





