/*
Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal eval
dalam mata kuliah algoritma dan pemrograman 2 untuk keberkahanNya maka 
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

// Deklarasi tipe bungkusan data table
typedef struct
{   
    char nama[51];        // Primary key
    char harga[51];    // Value pertama
    char status[51];    // Value kedua
}data;                                     

extern data brg[201];

extern int max1, max2, max3;
extern int panjang1[201], panjang2[201], panjang3[201];

extern int idx,     // index dari karakter terakhir kata
           wlen;    // panjang kata
extern char cw[201];    // karakter "saat ini" (current word)
// Prosedur memulai mesin kata
void start(char[]);
// Prosedur mereset mesin kata
void reset();
// (End Of Process) mesin kata
int eop(char[]);
// Peosedur inkremenkan mesin kata
void inc(char[]);
// Prosedur untuk mendapatkan atribut mesin kata
int getlen();   // mendapatkan panjang kata
char *getcw();  // mendapatkan kata

// Prosedur input
void input();
// Prosedur tentukan query
void inquery(char[], data[], int);
// Prisedur cari spasi
void getspace(int);