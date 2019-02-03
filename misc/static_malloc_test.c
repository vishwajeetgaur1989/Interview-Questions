#include <stdio.h> 
#include <stdlib.h> 

  

int main(void) 
{ 

   int a = 10;
   static int *p = &a; 

   //*p = 10; 

   printf("%d", *p); 
} 
