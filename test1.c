#include<stdio.h>
int main(){
    int i, j, k, l;
    float a,b;
    i =2;
    j =3;
    k = (i/j)*j;
    l = (j/i)*i;
    a = (i/j)*j;
    b = (j/i)*i;

    printf("k = %d, l = %d, a = %f, b = %f",k,l,a,b);

    return 0;

}