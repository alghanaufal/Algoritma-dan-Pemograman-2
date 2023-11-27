/*
Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal eval
dalam mata kuliah algoritma dan pemrograman 2 untuk keberkahanNya maka 
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//libary yang digunakan
#include <stdio.h>
#include <string.h>

// membuat bungkusan untuk menyimpan nama, nim, dan nilai
typedef struct
{
    char nama[51];
    char nim[11];
    int nilai;
}list;

//void sorting
void bubble(list[], int);

//void marge
void gabung(list[], list[], list[], int, int);

//input
void input(list[], int);

//outpur
void semua(list[], int);
void nilai1(list[], int);
void nilai2(list[], int);