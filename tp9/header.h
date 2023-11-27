/*
Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TP 9
dalam mata kuliah algoritma dan pemrograman 2 untuk keberkahanNya maka 
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

// libary yang digunakan
#include <stdio.h>  // libary input output
#include <string.h> // libaru string

// var global
extern int indeks;  // var indeks global
extern char cc;     // var cc global

// memulai mesin
void start(char[]);
// maju satu karakter
void inc(char[]);
// mundur satu karakter
void back(char[]);
// maju sampai ditemukan karekter berikutnya (spasi dilewat)
void adv(char[]);
// ambil indeks
int getindeks();
// ambil karakter
char getcc();
// end mesin
int eop();