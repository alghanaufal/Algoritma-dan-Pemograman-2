// panggil header
#include "header.h"

// global variables
int indeks;
char cc; 

// memulai mesin
void start(char pita[])
{
    indeks = 0;         // buat indeks 0
    cc = pita[indeks];
}

// maju 1 karakter
void inc(char pita[])
{
    indeks++;           // tambah indeks
    cc = pita[indeks];
}

// prosedur mematikan mesin
int eop()
{
    if (cc == '$')  // bila menemukan titik
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

// maju sampai ditemukan karekter berikutnya (spasi dilewat)
void adv(char pita[])
{
    indeks++;           // tambah indeks
    cc = pita[indeks];
    while ((cc == ' ') && (eop() == 0))     // bila menemukan spasi dan titik tidak di lanjutkan
    {
        indeks++;           // tambah indeks
        cc = pita[indeks];
    }
}

// ambil karakter
char getcc()
{
    return cc;
}

// ambil indeks
int getindeks()
{
    return indeks;
}