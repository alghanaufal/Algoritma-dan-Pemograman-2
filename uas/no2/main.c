#include "header.h"

int main()
{
    char pita[501];
    char temp[501];
    scanf("%s %500[^\n]s",&temp , &pita);
    
    start(pita);
    printf("%s\n", getcw());
    while (eop(pita) == 0 )
    {
        inc(pita);
        printf("%s\n", getcw());
    }

    return 0;
}