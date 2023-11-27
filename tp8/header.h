/*
Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TP 8
dalam mata kuliah algoritma dan pemrograman 2 untuk keberkahanNya maka 
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

// libary yang digunakan
#include <stdio.h>
#include <string.h>

// bungkusan film
typedef struct
{
    char id[10];        //simpan id untuk mencocokan dan dijadikan hasil film final
    char nama[50];
    char sutradara[50];
    char genre[50];
    char bioskop[50];
} data; // nama bungkusan

// prosedur untuk mencari data dengan binary
int carisutradara(char[]);
int carigenre(char[]);
int caribioskop(char[]);

// prosedur untuk mengprint list film final
void printfinal(data[], int, int, int, int, int);

// menambah data
void tambahfilm();
void tambahsutradara();
void tambahgenre();
void tambahbioskop();