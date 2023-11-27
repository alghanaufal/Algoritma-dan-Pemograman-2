/*
    Saya Alghaniyu Naufal Hamid mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah 
    Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//library yang digunakan
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Deklarasi tipe bungkusan data table
typedef struct
{   
    char id[16];        // Primary key
    char value1[51];    // Value pertama
    char value2[51];    // Value kedua
    char value3[51];    // Value ketiga
}data;                                     

extern int idx,     // index dari karakter terakhir kata
           wlen;    // panjang kata
extern char cw[201];    // karakter "saat ini" (current word)
// var simpan data file
extern FILE *fdata;
// var simpan data table
extern data thp[201];       // data file thp
extern data tspek[201];     // data file tspek
extern data tcam[201];      // data file tcam
// var menyimpan panjang mesin kata dan data table
extern int nquery,  // index query
           nhp,     // index hp
           nspek,   // index spek
           ncam;    // index cam
// var untuk menyimpan panjang string
extern int lenidh, lenhp1, lenhp2, lenhp3;          // panjang string tabel hp
extern int lenids, lenspek1, lenspek2, lenspek3;    // panjang string tabel spek
extern int lenidc, lencam1, lencam2, lencam3;       // panjang string tabel cam
// var untuk menyimpan Query
extern char query[201][201];

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
// Prosedur mengscan(membaca isi file)
void scan();
// Prosedur mengsave(menulis isi file)
void save();
// Prosedur sorting dengan quick sort 
void sort(data[], int, int);
// Prosedur cari kata
int search(data[], int, char[]);
// Prosedur Query
void insert();      // insert data
void update();      // update data
void dell();        // delete data
void select();      // melihat data

// Prosedur menentukan panjang spasi untuk membuat table
void getspace();
// Prosedur menampung bantuan query
void help(int);
// Prosedur menampung peringatan eror query
void error(int);