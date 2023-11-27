#include "header.h"

void bubble(header waktu[], int n, int max, char nama[][51], char penentu)
{   
    //var tukar dan var menimpan waktu dan nama 
    int tukar, i, j, temp, temp2, temp3;
    char temp1[51]; 
    if (penentu == 'a')     //bila secara asc akan diprint dari terkecil
    {
        do
        {
            tukar = 0;
            for (i = 0; i < n - 1; i++)
            {
                if (waktu[i].total > waktu[i + 1].total)
                {
                    temp = waktu[i].total;
                    waktu[i].total = waktu[i + 1].total;
                    waktu[i + 1].total = temp;

                    strcpy(temp1, nama[i]);
                    strcpy(nama[i], nama[i + 1]);
                    strcpy(nama[i + 1], temp1);

                    temp2 = waktu[i].jam;
                    waktu[i].jam = waktu[i + 1].jam;
                    waktu[i + 1].jam = temp2;

                    temp3 = waktu[i].menit;
                    waktu[i].menit = waktu[i + 1].menit;
                    waktu[i + 1].menit = temp3;
                    
                    tukar = 1;
                }
            }   
        } while (tukar == 1);
    }
        
    else if (penentu == 'd')    //bila secara desc akan diprint dari terbesar
    {
        do
        {
            tukar = 0;
            for (i = 0; i < n - 1; i++)
            {
                if (waktu[i].total < waktu[i + 1].total)
                {
                    temp = waktu[i].total;
                    waktu[i].total = waktu[i + 1].total;
                    waktu[i + 1].total = temp;

                    strcpy(temp1, nama[i]);
                    strcpy(nama[i], nama[i + 1]);
                    strcpy(nama[i + 1], temp1);

                    temp2 = waktu[i].jam;
                    waktu[i].jam = waktu[i + 1].jam;
                    waktu[i + 1].jam = temp2;

                    temp3 = waktu[i].menit;
                    waktu[i].menit = waktu[i + 1].menit;
                    waktu[i + 1].menit = temp3;
                    
                    tukar = 1;
                }
            }   
        } while (tukar == 1);
    }  
    
    //membuat output
    printf("Data Film Terurut :\n");

    for (i = 0; i < n; i++)
    {
        printf("%s", nama[i]);
        for (j = 0; j < max - strlen(nama[i]); j++)     // membuat spasi
        {
            printf(" ");
        }
        printf("  %dj %dm\n", waktu[i].jam, waktu[i].menit);
    }
    printf("\n");
}

void quick(header waktu[],  int l, int r, char nama[][51], char penentu)
{
    //var menyimpan waktu dan nama
    int i, j, temp, temp1, temp2, pivot;
    char temp3[51];

    if (penentu == 'a')     //bila asc akan diprint dari yang terkecil
    {   
        i = l;  j = r;
        pivot = waktu[(r + l) / 2].total;
        do
        {
            while ((waktu[i].total < pivot) && (i <= j))
            {
                i++;
            }
            while ((waktu[j].total > pivot) && (i <= j))
            {
                j--;
            }
            
            if (i < j)
            {   
                temp2 = waktu[i].total;
                strcpy(temp3, nama[i]);
                temp = waktu[i].jam;
                temp1 = waktu[i].menit;

                waktu[i].total = waktu[j].total;
                strcpy(nama[i], nama[j]);
                waktu[i].jam = waktu[j].jam;
                waktu[i].menit = waktu[j].menit;

                waktu[j].total = temp2;
                strcpy(nama[j], temp3);
                waktu[j].jam = temp;
                waktu[j].menit = temp1;
                
                i++;
                j--;
            }
        } while (i < j);

        //rekursif 
        if ((l < j) && (j < r))
        {
            quick(waktu, l, j, nama, penentu);
        }
        if ((i < r) && (i > l))
        {
            quick(waktu, i, r, nama, penentu);
        } 
    }

    else if (penentu == 'd')    //bila desc akan diprint dari yang terbesar
    {
        i = l;  j = r;
        do
        {
            while ((waktu[i].total > waktu[r].total) && (i <= j))
            {
                i++;
            }
            while ((waktu[j].total < waktu[l].total) && (i <= j))
            {
                j--;
            }
            
            if (i < j)
            {   
                temp2 = waktu[i].total;
                strcpy(temp3, nama[i]);
                temp = waktu[i].jam;
                temp1 = waktu[i].menit;

                waktu[i].total = waktu[j].total;
                strcpy(nama[i], nama[j]);
                waktu[i].jam = waktu[j].jam;
                waktu[i].menit = waktu[j].menit;

                waktu[j].total = temp2;
                strcpy(nama[j], temp3);
                waktu[j].jam = temp;
                waktu[j].menit = temp1;
                
                i++;
                j--;
            }
        } while (i < j);  

        //rekursif
        if (l < j)
        {
            quick(waktu, l, j, nama, penentu);
        }
        if (i < r)
        {
            quick(waktu, i, r, nama, penentu);
        }      
    }
}

void tulis(header waktu[], int n, int max, char nama[][51], char penentu)
{
    //membuat output
    int i, j;
    printf("Data Film Terurut :\n");

        for (i = 0; i < n; i++)
        {
            printf("%s", nama[i]);
            for (j = 0; j < max - strlen(nama[i]); j++)     // membuat spasi
            {
                printf(" ");
            }
            printf("  %dj %dm\n", waktu[i].jam, waktu[i].menit);
        }             
    printf("\n");
}