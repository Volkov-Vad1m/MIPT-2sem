#include <stdio.h>
#include <malloc.h>
//#include <conio.h>

char* fromHEXtoBIN(long a, char *bin);

int main()
{
    long a = 0;
    scanf("%lx", &a);
    char *bin = NULL;
    bin = fromHEXtoBIN(a, bin);
    int i = 0;
    while (bin[i] != '\0')
        printf("%c", bin[i++]);
    free(bin);
    //_getch();
    return 0;
}


char* fromHEXtoBIN(long a, char *bin)
{
    long tmp = a;
    int N;
    if (a == 0)
        N = 1;
    else
    {
        N = 0;
        while (tmp != 0)
        {
            N++;
            tmp = tmp / 16;
        }
    }
    bin = (char*)malloc((4 * N + 1)*sizeof(char));
    for (int i = N - 1; i >= 0; i--)
    {
        switch (a % 16)
        {
            case 0:
            {
                bin[4 * i] = '0';
                bin[4 * i + 1] = '0';
                bin[4 * i + 2] = '0';
                bin[4 * i + 3] = '0';
                break;
            }
            case 1:
            {
                bin[4 * i] = '0';
                bin[4 * i + 1] = '0';
                bin[4 * i + 2] = '0';
                bin[4 * i + 3] = '1';
                break;
            }
            case 2:
            {
                bin[4 * i] = '0';
                bin[4 * i + 1] = '0';
                bin[4 * i + 2] = '1';
                bin[4 * i + 3] = '0';
                break;
            }
            case 3:
            {
                bin[4 * i] = '0';
                bin[4 * i + 1] = '0';
                bin[4 * i + 2] = '1';
                bin[4 * i + 3] = '1';
                break;
            }
            case 4:
            {
                bin[4 * i] = '0';
                bin[4 * i + 1] = '1';
                bin[4 * i + 2] = '0';
                bin[4 * i + 3] = '0';
                break;
            }
            case 5:
            {
                bin[4 * i] = '0';
                bin[4 * i + 1] = '1';
                bin[4 * i + 2] = '0';
                bin[4 * i + 3] = '1';
                break;
            }
            case 6:
            {
                bin[4 * i] = '0';
                bin[4 * i + 1] = '1';
                bin[4 * i + 2] = '1';
                bin[4 * i + 3] = '0';
                break;
            }
            case 7:
            {
                bin[4 * i] = '0';
                bin[4 * i + 1] = '1';
                bin[4 * i + 2] = '1';
                bin[4 * i + 3] = '1';
                break;
            }
            case 8:
            {
                bin[4 * i] = '1';
                bin[4 * i + 1] = '0';
                bin[4 * i + 2] = '0';
                bin[4 * i + 3] = '0';
                break;
            }
            case 9:
            {
                bin[4 * i] = '1';
                bin[4 * i + 1] = '0';
                bin[4 * i + 2] = '0';
                bin[4 * i + 3] = '1';
                break;
            }
            case 10:
            {
                bin[4 * i] = '1';
                bin[4 * i + 1] = '0';
                bin[4 * i + 2] = '1';
                bin[4 * i + 3] = '0';
                break;
            }
            case 11:
            {
                bin[4 * i] = '1';
                bin[4 * i + 1] = '0';
                bin[4 * i + 2] = '1';
                bin[4 * i + 3] = '1';
                break;
            }
            case 12:
            {
                bin[4 * i] = '1';
                bin[4 * i + 1] = '1';
                bin[4 * i + 2] = '0';
                bin[4 * i + 3] = '0';
                break;
            }
            case 13:
            {
                bin[4 * i] = '1';
                bin[4 * i + 1] = '1';
                bin[4 * i + 2] = '0';
                bin[4 * i + 3] = '1';
                break;
            }
            case 14:
            {
                bin[4 * i] = '1';
                bin[4 * i + 1] = '1';
                bin[4 * i + 2] = '1';
                bin[4 * i + 3] = '0';
                break;
            }
            case 15:
            {
                bin[4 * i] = '1';
                bin[4 * i + 1] = '1';
                bin[4 * i + 2] = '1';
                bin[4 * i + 3] = '1';
                break;
            }
        }
        a = a / 16;
    }
    bin[4 * N] = '\0';
    return bin;
}
