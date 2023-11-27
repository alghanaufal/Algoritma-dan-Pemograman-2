// memanggil libary
#include "header.h"

// void judul
void judul(int n, int max, int max1, char nama[][51], char ganre[][51], char penentu[],char penentu2[], float rating[])
{
    int i, j, min;
    char data[51];
    char data1[51];
    float data2;
    float temp;
    // bila penentu insertion
    if (strcmp(penentu, "insertion") == 0)
    {
        if (strcmp(penentu2, "asc") == 0)   //bila dilakukan secara asc
        {   //kode insertion secara asc
            for (i = 0; i < n; i++)
            {
                strcpy(data, nama[i]);
                strcpy(data1, ganre[i]);
                data2 = rating[i];
                j = i - 1;

                while (strcmp(data, nama[j]) < 0 && (j >= 0))
                {
                    strcpy(nama[j + 1], nama[j]);
                    strcpy(ganre[j + 1], ganre[j]);
                    rating[j + 1] = rating[j];
                    j = j - 1;
                }
                strcpy(nama[j + 1], data);
                strcpy(ganre[j + 1], data1);
                rating[j + 1] = data2;
            }
        }
        
        else if (strcmp(penentu2, "desc") == 0) //bila dilakukan secara desc
        {   //kode insertion secara desc
            for (i = 0; i < n; i++)
            {
                strcpy(data, nama[i]);
                strcpy(data1, ganre[i]);
                data2 = rating[i];
                j = i - 1;

                while (strcmp(data, nama[j]) > 0 && (j >= 0))
                {
                    strcpy(nama[j + 1], nama[j]);
                    strcpy(ganre[j + 1], ganre[j]);
                    rating[j + 1] = rating[j];
                    j = j - 1;
                }
                strcpy(nama[j + 1], data);
                strcpy(ganre[j + 1], data1);
                rating[j + 1] = data2;
            }
        }
    }
    
    //bila penentu selection
    else if (strcmp(penentu, "selection") == 0)
    {
        if (strcmp(penentu2, "desc") == 0)  // bila dilakukan secara desc
        {   //kode selection secara desc
            for(i = 0; i < (n - 1); i++)
            {
                min = i;
                for(j = i + 1; j < n; j++)
                {
                    if(strcmp(nama[min], nama [j]) < 0)
                    {
                        min = j;
                    }
                }
                strcpy(data, nama[i]);
                strcpy(nama[i], nama[min]);
                strcpy(nama[min], data);

                strcpy(data1, ganre[i]);
                strcpy(ganre[i], ganre[min]);
                strcpy(ganre[min], data1);
            
                temp = rating[i];
                rating[i] = rating[min]; 
                rating[min] = temp;
            }
        }  

        else if (strcmp(penentu2, "asc") == 0)  // bila dilakukan secara asc
        {   //kode selection secara asc
            for(i = 0; i < (n - 1); i++)
            {
                min = i;
                for(j = i + 1; j < n; j++)
                {
                    if(strcmp(nama[min], nama [j]) > 0)
                    {
                        min = j;
                    }
                }
                strcpy(data, nama[i]);
                strcpy(nama[i], nama[min]);
                strcpy(nama[min], data);

                strcpy(data1, ganre[i]);
                strcpy(ganre[i], ganre[min]);
                strcpy(ganre[min], data1);
            
                temp = rating[i];
                rating[i] = rating[min]; 
                rating[min] = temp;
            }
        }
    }
    // print output
    printf("Daftar Film Terurut :\n");
    // perulangan '='
    for (i = 0; i < max + max1 + 7; i++)
    {
        printf("=");
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%s", nama[i]);
        for (j = 0; j < max - strlen(nama[i]); j++)     // membuat spasi
        {
            printf(" ");
        }
        printf("  %s", ganre[i]);
        for (j = 0; j < max1 - strlen(ganre[i]); j++)   // membuat spasi
        {
            printf(" ");
        }
        printf("  %.1f\n", rating[i]);
    }
    for (i = 0; i < max + max1 + 7; i++)
    {
        printf("=");
    }
    printf("\n");
}

// void rating
void rank(int n, int max, int max1, char nama[][51], char ganre[][51], char penentu[], char penentu2[], float rating[])
{
    int i, j, min;
    char data[51];
    char data1[51];
    float temp;
    float data2;
    // bila penentu insertion
    if (strcmp(penentu, "insertion") == 0)
    {   
        if (strcmp(penentu2, "asc") == 0)   // bila dilakukan secara asc
        {   // kode insertion secara asc
            for (i = 0; i < n; i++)
            {
                strcpy(data, nama[i]);
                strcpy(data1, ganre[i]);
                data2 = rating[i];
                j = i - 1;

                while ((j >= 0) && (data2 < rating[j]) )
                {
                    strcpy(nama[j + 1], nama[j]);
                    strcpy(ganre[j + 1], ganre[j]);
                    rating[j + 1] = rating[j];
                    j = j - 1;
                }
                strcpy(nama[j + 1], data);
                strcpy(ganre[j + 1], data1);
                rating[j + 1] = data2;
            }
        }
    
        else if (strcmp(penentu2, "desc") == 0) // bila dilakukan secara desc
        {   //kode insertion secara desc
            for (i = 0; i < n; i++)
            {
                strcpy(data, nama[i]);
                strcpy(data1, ganre[i]);
                data2 = rating[i];
                j = i - 1;

                while ((j >= 0) && (data2 > rating[j]) )
                {
                    strcpy(nama[j + 1], nama[j]);
                    strcpy(ganre[j + 1], ganre[j]);
                    rating[j + 1] = rating[j];
                    j = j - 1;
                }
                strcpy(nama[j + 1], data);
                strcpy(ganre[j + 1], data1);
                rating[j + 1] = data2;
            }
        }
    }

    // bila penentu selection
    else if (strcmp(penentu, "selection") == 0)
    {   
        if (strcmp(penentu2, "asc") == 0)       // bila dilakukan secara asc
        {   // kode selection secara asc
            for (i = 0; i < (n - 1); i++)
            {
                min = i;

                for (j = i + 1; j < n; j++)
                {
                    if (rating[min] > rating[j])
                    {
                        min = j;
                    }
                }
                temp = rating[i];
                rating[i] = rating[min]; 
                rating[min] = temp;

                strcpy(data, nama[i]);
                strcpy(nama[i], nama[min]);
                strcpy(nama[min], data);

                strcpy(data1, ganre[i]);
                strcpy(ganre[i], ganre[min]);
                strcpy(ganre[min], data1);
            } 
        }
        
        else if (strcmp(penentu2, "desc") == 0)     // bila dilakukan secara desc
        {   // kode selecrion secara desc
            for (i = 0; i < (n - 1); i++)
            {
                min = i;

                for (j = i + 1; j < n; j++)
                {
                    if (rating[min] < rating[j])
                    {
                        min = j;
                    }
                }
                temp = rating[i];
                rating[i] = rating[min]; 
                rating[min] = temp;

                strcpy(data, nama[i]);
                strcpy(nama[i], nama[min]);
                strcpy(nama[min], data);

                strcpy(data1, ganre[i]);
                strcpy(ganre[i], ganre[min]);
                strcpy(ganre[min], data1);
            } 
        }     
    } 
    printf("Daftar Film Terurut :\n");
    // print output
    for (i = 0; i < max + max1 + 7; i++)    // membuat '=' sesuai jumlah max, max1, rating
    {
        printf("=");
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%s", nama[i]);
        for (j = 0; j < max - strlen(nama[i]); j++)     // membuat spasi nama
        {         
            printf(" ");
        }
        printf("  %s", ganre[i]);
        for (j = 0; j < max1 - strlen(ganre[i]); j++)   //membuat spasi ganre
        {
            printf(" ");
        }
        printf("  %.1f\n", rating[i]);
    }
    for (i = 0; i < max + max1 + 7; i++)
    {
        printf("=");
    }
    printf("\n");
}
