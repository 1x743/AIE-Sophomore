#include <stdio.h>
int main()
{
    int i, j = 8;
    for (i = 1; i <=5; i+=2){
        printf("%d %d \n",i,j );
        j -= 2;
    }
    return 0;
}