/*
Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal Kuis 2
dalam mata kuliah algoritma dan pemrograman 2 untuk keberkahanNya maka 
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

// libary yg digunakan
#include <stdio.h>      // untuk input output
#include <string.h>     // untuk string

// bungkusan
typedef struct
{
    char nama[51];      
    int harga;
    char tempat[51];
    int kalori;
} data;

// prosedur input
void input(data[], int);
// prosedur sorting
void selection(data[], int, char[]);
// binary search
int cari(data[], int, int, char[]);