#include <stdio.h>
int main()
{
    int a,b,c;
    printf("Enter first number:");
    scanf("fisrt number %d",&a);
    printf("second number:");
    scanf("Second number %d",&b);
    printf("Before swap""a=%d,b=%d\n",a,b);
    c=a;
    a=b;
    b=c;
    printf("Afer swep""a=%d,b=%d\n",a,b);
    /*int i = 13 ;
    printf("%d\n",i--);
    printf("%d\n",i);*/
 return 0;
}