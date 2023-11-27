#include <stdio.h>                            // memanggil header, yang digunakan hanya stdio.h

void solve(int n, int m, int a, char kode[]); // ini ada lah prosedur untuk memecahkan problem(nantinya akan memakai switch)
void swap();                                  // prosedur untuk menyimpan hasil matriks yang sudah di operasikan di temp
void swap2();                                 // prosedur untuk menukar baris dan kolom

int baris, kolom, index1, index2;                              // deklarasi variabel global
char matriksbaru[101][101], temp[101][101], matriks[101][101]; // matriks adalah yg ori, temp adalah tempat untuk menyimpan, dan matriks baru adalah untuk di pritn