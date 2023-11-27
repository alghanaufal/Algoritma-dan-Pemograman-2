//memanggil libaty
#include "header.h"

#include "header.h"
int main()
{
    int a, b, c, d;         // ini baris dan kolom untuk matriks 1 dan 2, a dan b untuk matriks 1, c dan d untuk matriks 2
    scanf("%d %d", &a, &b); // scan baris kolom matriks 1

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d %d", &matriks1[i][j].a, &matriks1[i][j].b); // scan matriks satu sesuai baris kolom matriks 1
        }
    }
    scanf("%d %d", &c, &d); // scan baris kolom matriks 2
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < d; j++)
        {
            scanf("%d %d", &matriks2[i][j].a, &matriks2[i][j].b); // scan matriks dua sesuai baris kolom matriks 2
        }
    }
    int idx1, idx2;                // indeks yang buat nandain
    scanf("%d %d", &idx1, &idx2);  // scann
    index1 = idx1, index2 = idx2;  // ini copy dulu, karena nanti index1 bakal di iterasi, jadi harus dicopy awalnya
    solve(a, b, c, d, idx1, idx2); // panggil prosedurnya
    
    return 0;
}
