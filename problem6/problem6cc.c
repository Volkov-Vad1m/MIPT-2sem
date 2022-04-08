#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

#define Replacement "Sapere aude!"

long int GetSize(FILE* file);  // возвращает размер файла
long int Find(char* buffer, long int sizefile); // возвращает смещение от начала файла, где встретилась строка Hello world!

int main(int argc, char** argv)
{
    FILE* fin;
    // проверка на колличество аргументов командной строки 
    if ( argc < 2 || argc >= 3) 
    {
        printf("Incorrect input\n");
        exit(1);
    }
    fin = fopen(argv[1], "rb+wb");
    // проверка если при открытии файла произошли ошибки
    if(errno) 
    {
        perror("Problems opening a file");
        exit(1);
    }
    long int filesize = GetSize(fin); // узнали колличество символов в файле
    char* buffer = (char*)calloc(filesize, sizeof(char)); // выделяем буфер для содержимого файла 
    fread(buffer, filesize, sizeof(char), fin); // переносим содержимое файла в буфер 
    
    
    long int offset = Find(buffer, filesize);// узнаём смещение каретки от начала файла, где встретилась Hello World
    if(offset == -1)
    {
        printf("I did not find\n");
        exit(1);
    }

    fseek(fin, offset, SEEK_SET); // переставляем курсор к найденной подстроке
    fprintf(fin, Replacement); // заменяем Hello world на Replacement
    
    // очищаем закрываем
    free(buffer); 
    fclose(fin);
    return 0;
}

long int GetSize(FILE* file)
{
    int seekResult = fseek(file, 0L, SEEK_END); // переставляем каретку в конец файла
    assert(seekResult == 0); // fseek возвращет 0 при успешном завершении 
    long int filesize = ftell(file); // ftell возвращает значение текущего смещения
    rewind(file); // возвращаем каретку на начало файла
    return filesize; 
}

long int Find(char* buffer, long int sizefile) 
{   
    long int offset = 0; 
    for(offset = 0; offset < sizefile - 2; offset++)
    {
        if( strcmp(buffer + offset, "Hello world!") == 0 )
            return offset;
    }
    return -1; // если не нашли, возвращаем -1
}