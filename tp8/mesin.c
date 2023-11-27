// panggil header
#include "header.h"

// prosedur print
void printfinal(data film[], int n, int max1, int max2, int max3, int max4)
{
    // print data final dalam bentuk table
    printf("List Semua Film :\n");
    for (int i = 0; i < max1 + max2 + max3 + max4 + 20; i++)
    {
        printf("=");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("| %d |", i + 1);
        printf(" %s", film[i].nama);
        for (int j = 0; j < max1 - strlen(film[i].nama); j++)     // membuat spasi
        {
            printf(" ");
        }
        printf(" | %s ", film[i].sutradara);
        for (int j = 0; j < max2 - strlen(film[i].sutradara); j++)     // membuat spasi
        {
            printf(" ");
        }
        printf(" | %s ", film[i].genre);
        for (int j = 0; j < max3 - strlen(film[i].genre); j++)     // membuat spasi
        {   
            printf(" ");
        }
        printf(" | %s ", film[i].bioskop);
        for (int j = 0; j < max4 - strlen(film[i].bioskop); j++)     // membuat spasi
        {
            printf(" ");
        }
        printf(" |\n");
    }
    for (int i = 0; i < max1 + max2 + max3 + max4 + 20; i++)
    {
        printf("=");
    }
}

// prosedur cari sutradara
int carisutradara(char search[])
{
    int j = 0;
    
    FILE *ffilm;
    // buka file sutradara.dat dan baca
    ffilm = fopen("sutradara.dat", "r");
    data sutradara[20];
    // baca data pertama
    fscanf(ffilm, "%s %s", sutradara[j].id, sutradara[j].sutradara);
    // bila data pertama sama dengan #### maka file kosong
    if(strcmp(sutradara[j].id, "####") == 0)
    {
        printf("File kosong!\n");
    }
    else
    {
        // bila tidak sama
        while(strcmp(sutradara[j].id, "####") != 0)
        {
            // ingkremenkan
            j++;
            // dan baca file
            fscanf(ffilm, "%s %s", sutradara[j].id, sutradara[j].sutradara);
        }
    }

    int index = 0;
    int lookat = 0;
    int found = 0;

    // binary search
    while ((index <= j) && (found == 0))
    {
        lookat =(int)((index + j) / 2);
        //bila id dengna serch sama
        if (strcmp(sutradara[lookat].id, search) == 0)
        {
            // found diubah menjadi 1 dan print data
            found = 1;
            printf("%s\n", sutradara[lookat].sutradara);
        }
        else    // bila tidak sama
        {
            if (strcmp(sutradara[lookat].id, search) > 0)
            {
                j = lookat - 1;
            }
            else
            {
                index = lookat + 1;
            }
        }
    }
    return found;   // mengembalikan ke found 
    fclose(ffilm);  // tutup file
}

// prosedur cari data genre
int carigenre(char search[])
{
    int f = 0;
    
    FILE *ffilm;
    // buka file genre.dat dan baca
    ffilm = fopen("genre.dat", "r");
    data genre[20];
    // baca data pertama
    fscanf(ffilm, "%s %s", genre[f].id, genre[f].genre);
    // bila data pertama sama dengan #### maka file kosong
    if(strcmp(genre[f].id , "####") == 0)
    {
        printf("File kosong!\n");
    }
    else    // bila tida sama
    {
        while(strcmp(genre[f].id, "####") != 0)
        {   
            // ingkremenkan
            f++;
            // baca semua data
            fscanf(ffilm, "%s %s", genre[f].id, genre[f].genre);
        }
    }

    int index = 0;
    int lookat = 0;
    int found = 0;
    // binary search
    while ((index <= f) && (found == 0))
    {
        lookat =(int)((index + f) / 2);
        // bila id sama dengan search
        if (strcmp(genre[lookat].id, search) == 0)
        {
            // jadikan found menjadi 1
            found = 1;
            // print hasilnya
            printf("%s\n", genre[lookat].genre);
        }
        else    // bila tidak sama
        {
            if (strcmp(genre[lookat].id, search) > 0)
            {
                f = lookat - 1;
            }
            else
            {
                index = lookat + 1;
            }
        }
    }
    return found;   // kembali ke found
    fclose(ffilm);  //tutup file
}

// prosedur cari data bioskop
int caribioskop(char search[])
{
    FILE *ffilm;
    int k = 0;
    // buka data bioskop.dat dan baca
    ffilm = fopen("bioskop.dat", "r");
    data bioskop[20];
    // baca data pertama
    fscanf(ffilm, "%s %s", bioskop[k].id, bioskop[k].bioskop);
    // bila sama dengan #### maka file kosong
    if(strcmp(bioskop[k].id , "####") == 0)
    {
        printf("File kosong!\n");
    }
    else    
    {   
        // bila tidak sama
        while(strcmp(bioskop[k].id, "####") != 0)
        {
            // ingkremenkan
            k++;
            // baca semua data
            fscanf(ffilm, "%s %s", bioskop[k].id, bioskop[k].bioskop);
        }
    }

    int index = 0;
    int lookat = 0;
    int found = 0;
    // binary search
    while ((index <= k) && (found == 0))
    {
        lookat =(int)((index + k) / 2);
        // bila id bioskop dan search sama
        if (strcmp(bioskop[lookat].id, search) == 0)
        {
            // ubah found jadi 1
            found = 1;
            // print data bioskop
            printf("%s\n", bioskop[lookat].bioskop);
        }
        else    // bila tidak sama
        {
            if (strcmp(bioskop[lookat].id, search) > 0)
            {
                k = lookat - 1;
            }
            else
            {
                index = lookat + 1;
            }
        }
    }
    return found;   // kembalikn ke found
    fclose(ffilm);  // tutup file
}

// prosedur tambah file film
void tambahfilm()
{
    printf("Masukan data : \n");
    data film[20];
    int i, n = 0;
    FILE *ffilm;
    // buka list film
    ffilm = fopen("listfilm.dat", "r");
    // baca data pertama
    fscanf(ffilm, "%s %s %s", film[n].nama, film[n].sutradara, film[n].genre);
    fscanf(ffilm, "%s", film[n].bioskop);
    // bila sama maka file kosong
    if (strcmp(film[n].nama, "####") == 0)
    {
        printf("File Kosong!\n");
    }
    else
    {   
        // bila tidak
        while (strcmp(film[n].nama, "####") != 0)
        {
            // ingkremenkan
            n++;
            // baca semua data
            fscanf(ffilm, "%s %s %s", film[n].nama, film[n].sutradara, film[n].genre);
            fscanf(ffilm, "%s", film[n].bioskop);
        }  
    }
    fclose(ffilm);  // tutup file film
    
    // masukan imput data film
    scanf("%s %s %s", film[n].nama, film[n].sutradara, film[n].genre);
    scanf("%s", film[n].bioskop);
    // bila tidak sama 
    while(strcmp(film[n].nama, "####") != 0)
    {
        // ingkremenkan
        n++;
        // masukan input sampai menginput ####
        scanf("%s %s %s", film[n].nama, film[n].sutradara, film[n].genre);
        scanf("%s", film[n].bioskop);
    }
    // buka file film untuk menulis 
    ffilm = fopen("listfilm.dat", "w");
    for (i = 0; i < n; i++)
    {
        // tulis semua inputan ke file
        fprintf(ffilm, "%s %s %s", film[i].nama, film[i].sutradara, film[i].genre);
        fprintf(ffilm, " %s\n", film[i].bioskop);
    } 

    fprintf(ffilm, "#### #### #### ####\n");
    fclose(ffilm);  // tutup file 
}

// prosedur tambah sutradara
void tambahsutradara()
{
    printf("Masukan data : \n");
    data sutradara[20];
    int i, j = 0;
    FILE *ffilm;
    // buka file sutradara untuk dibaca
    ffilm = fopen("sutradara.dat", "r");
    //baca data pertama
    fscanf(ffilm, "%s %s", sutradara[j].id, sutradara[j].sutradara);
    // bila data tidak sama dengan ####
    if(strcmp(sutradara[j].id, "####") == 0)
    {
        printf("File kosong!\n");
    }
    else    
    {   
        // bila tidak sama 
        while(strcmp(sutradara[j].id, "####") != 0)
        {
            // ingkremenkan
            j++;
            // baca semua data
            fscanf(ffilm, "%s %s", sutradara[j].id, sutradara[j].sutradara);
        }
    }
    fclose(ffilm);  // tutup file
    // masukan inputan pertama
    scanf("%s %s", sutradara[j].id, sutradara[j].sutradara);
    // bila tidak sama
    while(strcmp(sutradara[j].id, "####") != 0)
    {
        // ingkremenkan
        j++;
        // input data
        scanf("%s %s", sutradara[j].id, sutradara[j].sutradara);
    }

    // buka file sutradara untuk ditulis
    ffilm = fopen("sutradara.dat", "w");
    for (i = 0; i < j; i++)
    {   
        // print input ke file
        fprintf(ffilm, "%s %s\n", sutradara[i].id, sutradara[i].sutradara);
    } 

    fprintf(ffilm, "#### #### #### ####\n");
    fclose(ffilm);  // tutup file
}

// prosedur tambah file genre
void tambahgenre()
{
    printf("Masukan data : \n");
    data genre[20];
    int i, f = 0;
    FILE *ffilm;
    // buka file genre.dat dan baca
    ffilm = fopen("genre.dat", "r");
    // baca data pertama 
    fscanf(ffilm, "%s %s", genre[f].id, genre[f].genre);
    // bila idnya sama dengan #### maka file kosong
    if(strcmp(genre[f].id , "####") == 0)
    {
        printf("File kosong!\n");
    }
    else
    {
        // bila tidak 
        while(strcmp(genre[f].id, "####") != 0)
        {
            // ingkremenkan
            f++;
            // baca semua data
            fscanf(ffilm, "%s %s", genre[f].id, genre[f].genre);
        }
    }
    fclose(ffilm);  // tutup file
    // masukan input data
    scanf("%s %s", genre[f].id, genre[f].genre);
    // bila data input tidak sama dengan ####
    while(strcmp(genre[f].id, "####") != 0)
    {
        // ingkremenkan
        f++;
        // berikan input semua data
        scanf("%s %s", genre[f].id, genre[f].genre);
    }

    // buka file genre.dat dan baca
    ffilm = fopen("genre.dat", "w");
    for (i = 0; i < f; i++)
    {
        // masukan semua data ke file
        fprintf(ffilm, "%s %s\n", genre[i].id, genre[i].genre);
    } 

    fprintf(ffilm, "#### #### #### ####\n");
    fclose(ffilm);  // tutup file
}

// tambah bioskop
void tambahbioskop()
{
    printf("Masukan data : \n");
    data bioskop[20];
    int i, k = 0;
    FILE *ffilm;
    // buka file bioskop.dat
    ffilm = fopen("bioskop.dat", "r");
    // baca file pertama
    fscanf(ffilm, "%s %s", bioskop[k].id, bioskop[k].bioskop);
    // bila tidak sama dengan #### maka file kosong
    if(strcmp(bioskop[k].id , "####") == 0)
    {
        printf("File kosong!\n");
    }
    else
    {
        // bila tidak sama
        while(strcmp(bioskop[k].id, "####") != 0)
        {
            // ingkremenkan
            k++;
            // baca semua data
            fscanf(ffilm, "%s %s", bioskop[k].id, bioskop[k].bioskop);
        }
    }
    fclose(ffilm);  // tutup file

    // masukan inputan pertama
    scanf("%s %s", bioskop[k].id, bioskop[k].bioskop);
    // bila tidak sama dengan ####
    while(strcmp(bioskop[k].id, "####") != 0)
    {
        // ingkremenkan
        k++;
        // masukan input semua data
        scanf("%s %s", bioskop[k].id, bioskop[k].bioskop);
    }

    // buka file dan tulis
    ffilm = fopen("bioskop.dat", "w");
    for (i = 0; i < k; i++)
    {
        // tulis semua inputan
        fprintf(ffilm, "%s %s\n", bioskop[i].id, bioskop[i].bioskop);
    } 

    fprintf(ffilm, "#### #### #### ####\n");
    fclose(ffilm);  // tutup data;
}