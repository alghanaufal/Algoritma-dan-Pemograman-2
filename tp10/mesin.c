// memanggil header
#include "header.h"
// var global yg ada di header
int idx, wlen;
char cw[101];

// Prosedur untuk memulai mesin kata
void start(char str[])
{
    // Inisialisasi indeks dan panjang kata memidx=0;wlen-0;
    idx = 0;
    wlen = 0;

    // jika karkater dalam pita adalah spasi, indeks e=terus maju
    while (str[idx] == ';')
    {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ';') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    // Mengatur agar kata  saat ini indeks terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Prosedur untuk mengosongkan kata yang dibaca dalam mesin kata
void reset()
{
    // inisialisasi panjang kata dan kata saat ini agar NULL
    wlen = 0;
    cw[wlen] = '\0';
}

// Fungsi untuk memeriksa akhir dari proses (End Of Process)
int eop(char str[])
{
    // Memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (str[idx] == '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Prosedur untuk memajukan kata
void inc(char str[])
{
    // Inisialisasi ulang panjang kata
    wlen = 0;

    // jika karkater dalam pita adalah spasi, indeks e=terus maju
    while (str[idx] == ';')
    {
        idx++;
        if (str[idx] == ' ')
        {
            idx++;
        }
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ';') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    // Mengatur agar kata  saat ini indeks terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// fungsi untuk mendapatkan panjang kata saat ini
int getlen()
{
    return wlen;
}

// fungsi untuk mendapatkan kata saat ini
char *getcw()
{
    return cw;
}

// prosedur untuk print kata pendek
void pendek(data kata[], int a)
{
    // gunakan shorting
    int tukar, i, j;
    char temp[110]; 
    do
    {
        tukar = 0;
        for (i = 0; i < a - 1; i++)
        {
            if (strcmp(kata[i].pendek, kata[i + 1].pendek) > 0)
            {
                strcpy(temp, kata[i].pendek);
                strcpy(kata[i].pendek, kata[i + 1].pendek);
                strcpy(kata[i + 1].pendek, temp);
                tukar = 1;
            }
        }   
    } while (tukar == 1);

    printf("KATA PENDEK\n");
    // print output
    for (i = 0; i < a; i++)
    {
        printf("- %s\n", kata[i].pendek);
    }
    printf("\n");   // memberi new line
}

// prosedur untuk print kata menengah
void tengah(data kata[], int b)
{
    // gunakan shorting
    int tukar, i, j;
    char temp[110]; 
    do
    {
        tukar = 0;
        for (i = 0; i < b - 1; i++)
        {
            if (strcmp(kata[i].tengah, kata[i + 1].tengah) > 0)
            {
                strcpy(temp, kata[i].tengah);
                strcpy(kata[i].tengah, kata[i + 1].tengah);
                strcpy(kata[i + 1].tengah, temp);
                tukar = 1;
            }
        }   
    } while (tukar == 1);

    printf("KATA MENENGAH\n");
    //  print output
    for (i = 0; i < b; i++)
    {
        printf("- %s\n", kata[i].tengah);
    }
    printf("\n");
}

// prosedur untuk print kata panjang
void panjang(data kata[], int c)
{
    // gunakan shorting
    int tukar, i, j;
    char temp[110]; 
    do
    {
        tukar = 0;
        for (i = 0; i < c - 1; i++)
        {
            if (strcmp(kata[i].panjang, kata[i + 1].panjang) > 0)
            {
                strcpy(temp, kata[i].panjang);
                strcpy(kata[i].panjang, kata[i + 1].panjang);
                strcpy(kata[i + 1].panjang, temp);
                tukar = 1;
            }
        }   
    } while (tukar == 1);

    printf("KATA PANJANG\n");
    //  print output
    for (i = 0; i < c; i++)
    {
        printf("- %s\n", kata[i].panjang);
    }
}