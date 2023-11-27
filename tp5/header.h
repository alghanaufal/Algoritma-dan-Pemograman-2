/*
Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TP 5
dalam mata kuliah algoritma dan pemrograman 1 untuk keberkahanNya maka 
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//libary yang digunakan
#include <stdio.h>
#include <string.h>

// membuat bungkusan untuk menyimpan data waktunya
typedef struct
{
    int jam;        //var jam
    int menit;      //var menit
    int total;      //var total waktu yg dibutuhkannya
} header;

void quick(header [],  int, int ,char[][51], char);     //void untuk membuat quick sort
void bubble(header [], int, int, char[][51], char);     //void untuk membuat bubble sort
void tulis(header [], int, int, char[][51], char);      //void untuk menprint quick sort