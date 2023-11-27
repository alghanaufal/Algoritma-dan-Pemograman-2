#include "header.h"

int main()
{
    int n, m;                   // n dan m untuk baris dan kolom
    scanf("%d %d", &n, &m);     // scan baris dan kolom
    baris = n, kolom = m;       // n dan m dimasukkan ke variabel baris dan kolom karena nantinya akan di operasikan di mesin
    for (int i = 0; i < n; i++) // scan matriks sesuai baris dan kolom
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &matriks[i][j]);
        }
    }
    for (int i = 0; i < n; i++) // menyimpan matriks awal kedalam temp, fungsinya agar matriks ori tetap ada, untuk di operasikan di akhir, dan temp akan diubah ubah
    {
        for (int j = 0; j < m; j++)
        {
            temp[i][j] = matriks[i][j];
        }
    }

    int a;
    scanf("%d", &a); // scan banyaknya perubahan
    char kode[a];
    for (int i = 0; i < a; i++) // isi dari perubahan
    {
        scanf(" %c", &kode[i]);
    }
    solve(n, m, a, kode); // panggil prosedur
}