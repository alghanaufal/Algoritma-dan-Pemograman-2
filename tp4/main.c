// memanggil libary header
#include "header.h"

// kode utama
int main()
{
    int n,              //var untuk menentukan banyak film
        i,              //var looping
        j,              //var looping
        panjang[201],   //menyimpan string nama yg akan dijadikan spasi
        panjang1[201],  //menyimpan string ganre yg akan dijadikan spasi
        max = 0,        //menyimpan panjang spasi nama film
        max1 = 0;       //menyimpan panjang spasi nama ganre

    // memasukan berapa banyak film
    scanf("%d", &n);

    char penentu1[51];  //var mengisi penentu akan di urut rating atau judul
    char penentu[51];   //var mengisi penentu akan dilakukan secara insertion atau selection
    char penentu2[51];  //var mengisi penentu akan di urut secara asc atau desc

    char nama[n][51];   //var mengisi nama film
    char ganre[n][51];  //var mengisi ganre
    float rating[n];    //var mengisi rating

    //perulangan inputan film tergantun banyak n
    for (i = 0; i < n; i++)
    {
        scanf("%s %s %f", nama[i], ganre[i], &rating[i]);   //memberi input nama film, ganre, dan rating
        panjang[i] = strlen(nama[i]);       //setiap string nama akan diubah menjadi int dan dimasukan ke panjang
        if (panjang[i] > max)               //bila panjang lebih besar dari max
        {                                   //maka max akan menyimpan panjang
            max = panjang[i];
        }
        panjang1[i] = strlen(ganre[i]);     //setiap string ganre akan diubah menjadi int dan disimpan ke panjang1
        if (panjang1[i] > max1)             //bila panjang1 lebih besar dari max1
        {                                   //maka max1 akan menyimpan panjang1
            max1 = panjang1[i];
        }
    }

    scanf("%s", penentu1);      //input penentu rating atau judul
    scanf("%s", penentu);       //input penentu insertion atau selection
    scanf("%s", penentu2);      //input penentu asc atau desc

    if (strcmp(penentu1, "rating") == 0)        //bila rating
    {
        rank(n, max, max1, nama, ganre, penentu, penentu2, rating);
    }

    else if(strcmp(penentu1, "judul") == 0)     //bila judul
    {
        judul(n, max, max1, nama, ganre, penentu, penentu2, rating);
    }

return 0;
}

