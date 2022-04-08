#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int* who_is(char* buf, int* e_x, int* tmp)
{
    if(strcmp(buf, "eax") == 0 )
        return e_x;
    if(strcmp(buf, "ebx") == 0 )
        return (e_x + 1);
    if(strcmp(buf, "ecx") == 0 )
        return (e_x + 2);
    if(strcmp(buf, "edx") == 0 )
        return (e_x + 3);
    else
    {
        *tmp = atoi(buf);
        return(tmp);
    }
}

void print_array(int* arr)
{
    for(int i = 0; i < 4; i++)
        printf("%d", arr[i]);
}

int main()
{
    int tmp;
    int e_x[4] = {1, 2, 3, 4};
    char buf[10];
    scanf("%s", buf);
    int* k = who_is(buf, e_x, &tmp);
    printf("%d", *k);

}
