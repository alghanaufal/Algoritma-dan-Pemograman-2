/*
Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal uas soal 2
dalam mata kuliah algoritma dan pemrograman 2 untuk keberkahanNya maka 
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

// libary yang digunakan
#include <stdio.h>
#include <string.h>

// deklarasi variabel
extern int idx;         // indeks dari karakter terakhir kata
extern int wlen;        // Panjang kata
extern char cw[501];    // karakter "saat ini" (current word)

// Bagian untuk memulai mereset, dan mengakhiri mesin kata
void start(char str[]);
void reset();
int eop(char str[]);

// Bagian memajukan mesin kata
void inc(char str[]);

// Bagian mendapatkan atribut mesin kata
int getlen();
char *getcw();