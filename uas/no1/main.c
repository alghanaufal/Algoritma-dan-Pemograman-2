#include "header.h"

int main()
{   
    int n = 0, t = 0, x = 0, y = 0;
    char temp;
    char pita[501];
    char save[501];

    scanf("%d", &t);
    scanf(" %c %500[^\n]s",&temp, &pita);
    
    start(pita);
    save[y] = getcc();
    y++;
    while (eop() == 0)
    {
        n++;
        inc(pita);
        if (getcc() == ' ')
        {
            inc(pita);
            save[y] = getcc();
            y++;
            if (n == t)
            {
                n = 0;
                x++;
            }
        }
        else
        {   
            save[y] = getcc();
            y++;
            if (n == t)
            {
                
                n = 0;
                x++;
            } 
        }       
    }

    int hasil = 0;
    hasil = y / x;
    hasil *= x;
    int u = 0, p = 0, q = 0;  

    for (int i = 0; i < hasil; i++)
    {    
        // printf("%c", save[i]);
        u++;
        if (save[i] == temp)
        {
            p = 1;
        }
        if (u == t)
        {
            // printf("\n");
            
            if (p == 1)
            {
                q++;
                // printf("%d", q);
                p = 0;
            }
            u = 0;
        }
        
    }    
    printf("%d\n", q);   
    return 0;
}