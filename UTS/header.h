/*
Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal UTS
dalam mata kuliah algoritma dan pemrograman 1 untuk keberkahanNya maka 
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[51];
    int kalori, lemak, harga, kl, sup;
    double hasil;
}minyak;

void insertion(minyak[], int);
void selection(minyak[], int);
void bubble(minyak[], int);
void quick(minyak[], int, int);
//void marge
void gabung(minyak[], minyak[], minyak[], int, int);
void input(minyak[], int, int);
void print(minyak[], int, int);
void semua(minyak[], int);