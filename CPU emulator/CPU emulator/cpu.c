#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int* who_is1(char* buf, int* e_x);
int* who_is2(char* buf, int* e_x, int* tmp);
void print_array(int* arr);

int main()
{
    int e_x[4] = {0};
    char buf[10];
    int tmp = 0;
    int* ptmp1;
    int* ptmp2;
    while(1)
    {
        scanf("%s", buf);
        if(strcmp(buf, "ret") == 0)
            break;
        if(strcmp(buf, "add") == 0)
        {
            scanf("%s", buf);
            ptmp1 = who_is1(buf, e_x);
            scanf("%s", buf);
            ptmp2 = who_is2(buf, e_x, &tmp);
            *ptmp1 += *ptmp2;
        }
        if(strcmp(buf, "sub") == 0)
        {
            scanf("%s", buf);
            ptmp1 = who_is1(buf, e_x);
            scanf("%s", buf);
            ptmp2 = who_is2(buf, e_x, &tmp);
            *ptmp1 -= *ptmp2;
        }
        if(strcmp(buf, "mov") == 0)
        {
            scanf("%s", buf);
            ptmp1 = who_is1(buf, e_x);
            scanf("%s", buf);
            ptmp2 = who_is2(buf, e_x, &tmp);
            *ptmp1 = *ptmp2;
        }
        print_array(e_x);
    }
    printf("good bye :)");
    return 0;
}


int* who_is1(char* buf, int* e_x)
{
    if(strcmp(buf, "eax,") == 0 )
        return e_x;
    if(strcmp(buf, "ebx,") == 0 )
        return (e_x + 1);
    if(strcmp(buf, "ecx,") == 0 )
        return (e_x + 2);
    if(strcmp(buf, "edx,") == 0 )
        return (e_x + 3);
}

int* who_is2(char* buf, int* e_x, int* tmp)
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
        printf("%d ", arr[i]);
    printf("\n");
}
