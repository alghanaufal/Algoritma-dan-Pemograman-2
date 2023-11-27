#include "header.h"

void solve(int a, int b, int c, int d, int idx1, int idx2)
{
    if ((a * b) > (c * d)) // kondisi jika matriks 1 lebih besar, baris kolomnya kita kalikan
    {
        for (int i = 0; i < a; i++) // pertama tama, kita masukkin dulu matriks 1nya ke matriks 3,
        {
            for (int j = 0; j < b; j++)
            {
                matriks3[i][j].a = matriks1[i][j].a;
                matriks3[i][j].b = matriks1[i][j].b;
            }
        }
        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < d; j++)
            {
                matriks3[index1][index2].a = matriks2[i][j].a * matriks1[index1][index2].a; // kalikan
                matriks3[index1][index2].b = matriks2[i][j].b * matriks1[index1][index2].b;
                index2++; // iterasi index2 atau kolom
            }
            index2 = idx2; // reset index 2 ke nilai awal idx2
            index1++;      // iterasi index1
        }
        print(a, b); // panggil prosedur print
    }
    else // kebalikan dari yang tadi
    {
        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < d; j++)
            {
                matriks3[i][j].a = matriks2[i][j].a; // jadi yang di copy adalah matriks 2, karena matriks 2 lebih besar
                matriks3[i][j].b = matriks2[i][j].b;
            }
        }
        // lalu kondisinya ini sesuai matriks kecil/matriks 1
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {

                matriks3[index1][index2].a = matriks1[i][j].a * matriks2[index1][index2].a; // proses perkaliannya sama juga kaya tadi, cuman kebalikannya
                matriks3[index1][index2].b = matriks1[i][j].b * matriks2[index1][index2].b;
                index2++; // iterasi index kolom
            }
            index2 = idx2; // reset indeks kolom
            index1++;
        }
        print(c, d); // panggil prosedur print
    }
}
void print(int baris, int kolom)
{
    for (int i = 0; i < baris; i++) // ini prosedur print, dia print matriks 3 karena matriks 3 var global
    {
        for (int j = 0; j < kolom; j++) // baris dan kolom menyesuaikan kondisinya
        {
            printf("%d %d\n", matriks3[i][j].a, matriks3[i][j].b);
        }
    }
}