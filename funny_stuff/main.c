#include "header.h"
#define my_sizeof(type) (char *)(&type + 1) - (char *)(&type)
int main()
{
    int tmp;
    printf("Evaluating with my own sizeof %d\n", my_sizeof(tmp));
    return 0;
}