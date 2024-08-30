
#include <stdio.h>
#include <cstdlib>

int main()
{     
      int *no;
      no = (int*)malloc(sizeof(int));
      printf("Enter a value for n");
      scanf("%d",no);
      
      int *sum;
      sum = (int*)malloc(sizeof(int));
      *sum=0;
      
      int *i;
      i = (int*)malloc(sizeof(int));
      
      int *ptr;
      ptr = (int*)malloc(sizeof(int));
      
      
      for(*i = 0; *i<*no;*i+=1)
      {     scanf("%d",(ptr+ (*i*sizeof(int))));
         *sum+= *(ptr+ *i * sizeof(int));
      }
      
      printf("The sum is %d",*sum);
      
      return 0;
}