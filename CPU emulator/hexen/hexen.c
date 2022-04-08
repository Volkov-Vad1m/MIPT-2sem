#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printmass(int* n1, int size);

int main()
{
    char n1[1000000] = {0};
    scanf("%s", n1);
    int size = strlen(n1);
    //printf("size = %d\n", size);
    int* n2;
    int j = 0;
    n2 = (int*)calloc(4*size, sizeof(int)); // 2 число
    for(int i = 0; i < size; i++)
    {
        j = 4 * i;
        switch(n1[i])
        {
            case '0':
                n2[j] = 0; n2[j+1] = 0; n2[j+2] = 0; n2[j+3] = 0; break;
            case '1':
                n2[j] = 0; n2[j+1] = 0; n2[j+2] = 0; n2[j+3] = 1; break;
            case '2':
                n2[j] = 0; n2[j+1] = 0; n2[j+2] = 1; n2[j+3] = 0; break;
            case '3':
                n2[j] = 0; n2[j+1] = 0; n2[j+2] = 1; n2[j+3] = 1; break;
            case '4':
                n2[j] = 0; n2[j+1] = 1; n2[j+2] = 0; n2[j+3] = 0; break;
            case '5':
                n2[j] = 0; n2[j+1] = 1; n2[j+2] = 0; n2[j+3] = 1; break;
            case '6':
                n2[j] = 0; n2[j+1] = 1; n2[j+2] = 1; n2[j+3] = 0; break;
            case '7':
                n2[j] = 0; n2[j+1] = 1; n2[j+2] = 1; n2[j+3] = 1; break;
            case '8':
                n2[j] = 1; n2[j+1] = 0; n2[j+2] = 0; n2[j+3] = 0; break;
            case '9':
                n2[j] = 1; n2[j+1] = 0; n2[j+2] = 0; n2[j+3] = 1; break;
            case 'A':
                n2[j] = 1; n2[j+1] = 0; n2[j+2] = 1; n2[j+3] = 0; break;
            case 'B':
                n2[j] = 1; n2[j+1] = 0; n2[j+2] = 1; n2[j+3] = 1; break;
            case 'C':
                n2[j] = 1; n2[j+1] = 1; n2[j+2] = 0; n2[j+3] = 0; break;
            case 'D':
                n2[j] = 1; n2[j+1] = 1; n2[j+2] = 0; n2[j+3] = 1; break;
            case 'E':
                n2[j] = 1; n2[j+1] = 1; n2[j+2] = 1; n2[j+3] = 0; break;
            case 'F':
                n2[j] = 1; n2[j+1] = 1; n2[j+2] = 1; n2[j+3] = 1; break;
        }
    }
    printmass(n2, 4*size);
    //free(n1);
    free(n2);
}

void printmass(int* n1, int size)
{
    int i = 0;
    while(n1[i] == 0)
        i++;
    for (int j = i; j < size; j++)
    {
        printf("%d", n1[j]);
    }
}
