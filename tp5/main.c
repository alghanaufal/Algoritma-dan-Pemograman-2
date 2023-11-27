#include "header.h"

int main()
{
    int n,              //var untuk menentukan banyak film
        i,              //var looping
        j,              //var looping
        panjang[201],   //menyimpan string nama yg akan dijadikan spasi
        max = 0;        //menyimpan panjang spasi nama film

    // memasukan berapa banyak film
    scanf("%d", &n);

    char penentu1;  //var mengisi penentu akan di urut bubble atau quick
    char penentu;   //var mengisi penentu akan dilakukan secara desc atau asc

    char nama[n][51];   //var mengisi nama film
    header waktu[n];    //var waktu film

    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d", nama[i], &waktu[i].jam, &waktu[i].menit);   //memberi input
        panjang[i] = strlen(nama[i]);       //setiap string nama akan diubah menjadi int dan dimasukan ke panjang
        if (panjang[i] > max)               //bila panjang lebih besar dari max
        {                                   //maka max akan menyimpan panjang
            max = panjang[i];
        }
    }

    scanf(" %c", &penentu1);      //input penentu bubble atau quick
    scanf(" %c", &penentu);       //input penentu asc atau desc

    //var menghitung total waktu yang dibutuhkan
    int simpan = 0;
    int hasil = 0;
    int hasil1 = 0;

    for (i = 0; i < n; i++)
    {
        simpan = waktu[i].jam * 60;                 //simpan jumlah menit
        waktu[i].total = simpan + waktu[i].menit;   //simpan berapa jumlah total waktu dalam bentuk menit
    }    
    for (i = 0; i < n; i++)
    {
        hasil += waktu[i].menit;       //simpan hasil penjumlahan setiap menit
    }
    for (i = 0; i < n; i++)
    {
        hasil1 += waktu[i].jam;        //simpan hasil penjumlahan setiap jam
    }

    int h = hasil / 60;         //hasil penjumlahan menit diubah menjadi jam
    h += hasil1;                //jumlah jamnya akan ditambah hasil jam 
    int menit = hasil % 60;     //lalu hasil di mod 60 agar menemukan berapa menit

    if (penentu1 == 'b')        //bila bubble
    {
        bubble(waktu, n, max, nama, penentu);
    }

    else if(penentu1 == 'q')     //bila quick
    {
        quick(waktu, 0, n - 1, nama, penentu);
        tulis(waktu, n, max, nama, penentu);
    }
    
    //print hasilnya
    printf("Total Durasi : %d jam %d menit\n", h, menit);
            
    return 0;
}