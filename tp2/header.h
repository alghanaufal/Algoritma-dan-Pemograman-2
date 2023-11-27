/*
Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan Tugas Praktikum 2
dalam mata kuliah algoritma dan pemrograman 2 untuk keberkahanNya maka 
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

int n, m;   // ukuran matrix

typedef struct data
{
    char nama[30];
    int atk, def;
}
data;

data* cari_tim(char[], data[][m]);
float rata2(int, int);
void tukar_tim(data*, data*);
void print_drawing(data[][m]);
