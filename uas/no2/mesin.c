// memanggil header
#include "header.h"
// var global yg ada di header
int idx, wlen;
char cw[501];

// Prosedur untuk memulai mesin kata
void start(char str[])
{
    // Inisialisasi indeks dan panjang kata memidx=0;wlen-0;
    idx = 0;
    wlen = 0;

    // jika karkater dalam pita adalah spasi, indeks e=terus maju
    while (str[idx] == '$')
    {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != '$') && (eop(str) == 0))
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
    if (str[idx] == '$')
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
    while (str[idx] == '$')
    {
        idx++;
        if (str[idx] == ' ')
        {
            idx++;
        }
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != '$') && (eop(str) == 0))
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