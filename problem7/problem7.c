#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>     

#define sizeof_jump 5  // сколько байт занимает jump
#define jump_addres 0xe9

void Honest_func_1(); // честная функция 1
void Honest_func_2(); // честная функция 2
void Hacker_func();
void Changing_access(); // изменение прав доступа

int main()
{
    Honest_func_1();
    Honest_func_2();

    Hacker_func();
    printf("\tAfter hacking.\n");

    Honest_func_1();
    Honest_func_2();


}
/////////////////////////////////////////////////////
void Honest_func_1()
{
    printf("It's over, Anakin! I have the high ground!\n");
    return;
}

void Honest_func_2()
{
    printf("You underestimate my power!\n");
    return;
}

void Hacker_func()
{
    Changing_access();
    
    void* pointer = &Honest_func_1; 
    
    long long offset = &Honest_func_2 - &Honest_func_1 - sizeof_jump; // 0x21
    offset = offset << 8; //0x2100
    long long change = offset + jump_addres; // 0x21eb

    *(long long*)pointer = change;
    
}

void Changing_access() // изменение прав доступа
{
    void* base = (void*) (((size_t)(&Honest_func_1) >> 12) << 12); // обнуляем последние 3 цифры адреса в 16-м представлении

    size_t page_size = sysconf(_SC_PAGE_SIZE); // узнаём размер страницы
    int res = mprotect(base, page_size, PROT_WRITE | PROT_READ | PROT_EXEC);  // предоставляем права для памяти
    if(res != 0) 
    {
        perror("problems with mprotect");
        exit(errno);
        
    } 
    return;
}

