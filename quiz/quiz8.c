#include <stdio.h>
#include <stdlib.h>

int f(int n,int * count1, int * count2){
    (* count1) ++;
    if (n<=1)
    {
       return 1; 
    }
    (* count2) ++;
    int a = f(n-1, count1, count2);
    int a = f(n-1, count1, count2);
    return n + a + b;
}

int main(int argc, char * * argv)
{
    int count1 = 0;
    int count2 = 0;
    int x = f(5, &count1, &count2);
    printf("f(5) = %d, count1 = %d, count2 = %d\n", x, count1,count2);
    return EXIT_SUCCESS;
}