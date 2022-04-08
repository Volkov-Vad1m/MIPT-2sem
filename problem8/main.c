#include <stdio.h>

int func(int a, int b, int c)
{   
    a = 7; 
    b = 8; 
    c = a + b; 
    return c; 
}

int x = 0;

int main()
{
    x = func(1, 2, 3);
    printf("%d\n", x);

}