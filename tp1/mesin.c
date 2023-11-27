#include "header.h"

void swap()
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            temp[i][j] = matriksbaru[i][j];
        }
    }
}
// ini prosedur untuk menukar baris dan kolom, karena pada kode B,C,D, baris dan kolomnya pasti berubah sehingga memerlukan prosedur ini
void swap2()
{
    int temp3 = baris;
    baris = kolom;
    kolom = temp3;
}
void solve(int n, int m, int a, char kode[])
{
    index1 = 0; // awalnya mengatur index1 dan index2 menjadi 0
    index2 = 0;
    for (int k = 0; k < a; k++)
    {
        switch (kode[k])
        {
        case 'A': // case A adalah refleksi ke atas

            for (int i = baris - 1; i >= 0; i--) // sehingga hanya perlu menukar barisnya saja, dari indeks terakhir
            {
                for (int j = 0; j < kolom; j++)
                {
                    matriksbaru[index1][index2] = temp[i][j]; // fungsi indeks adalah agar tetap menyimpan dari 0,0
                    index2++;
                }
                index2 = 0; // reset indeks2 agar tidak terus bertambah
                index1++;
            }
            index1 = 0; // reset lagi kedua indeks ini karena akan digunakan di case berikutnya
            index2 = 0;
            swap(); // sebelum diakhiri, simpan matriks baru tadi yg sudah diubah ke dalam temp, jadi tempnya direplace

            break;
        case 'B':                           // case B rotasi ke kanan
                                            // caranya adalah di transpose dulu lalu refleksi ke samping
            for (int i = 0; i < kolom; i++) // pertama kita transpose dulu matriksnya
            {
                for (int j = 0; j < baris; j++)
                {
                    matriksbaru[index1][index2] = temp[j][i];
                    index2++;
                }
                index2 = 0;
                index1++;
            }
            index1 = 0;
            index2 = 0;
            swap2(); // lalu tukar baris dengan kolomnya
            swap();  // simpan matriks yang telah di transpose tadi
            for (int i = 0; i < baris; i++)
            {
                for (int j = kolom - 1; j >= 0; j--) // lalu refleksi ke samping(jadi kolomnya dari akhir)
                {
                    matriksbaru[index1][index2] = temp[i][j];
                    index2++;
                }
                index2 = 0;
                index1++;
            }
            index1 = 0;
            index2 = 0;
            swap(); // simpan lagi matriks yang telah di rotasi ke kanan ke temp

            break;
        case 'C':                           // case c rotasi ke kiri
            for (int i = 0; i < kolom; i++) // sama seperti yang tadi, kita transpose dulu matriksnya
            {
                for (int j = 0; j < baris; j++)
                {
                    matriksbaru[index1][index2] = temp[j][i];
                    index2++;
                }
                index2 = 0;
                index1++;
            }
            index1 = 0;
            index2 = 0;
            swap2();                             // tukar baris degan kolom
            swap();                              // simpan matriks yang telah di transpose
            for (int i = baris - 1; i >= 0; i--) // setelah itu refleksi ke atas(tukar barisnya dari yg akhir)
            {
                for (int j = 0; j < kolom; j++)
                {
                    matriksbaru[index1][index2] = temp[i][j];
                    index2++;
                }
                index2 = 0;
                index1++;
            }
            index1 = 0;
            index2 = 0;
            swap(); // lalu simpan lagi matriks yang sudah di rotasi ke kiri ini
            break;
        case 'D': // case D adalah transpose matrix

            for (int i = 0; i < kolom; i++)
            {
                for (int j = 0; j < baris; j++)
                {
                    matriksbaru[index1][index2] = temp[j][i]; // disini hanya perlu menukar baris dan kolomnya saja
                    index2++;
                }
                index2 = 0; // reset indeks 2
                index1++;
            }
            index1 = 0; // reset kedua indeks
            index2 = 0;
            swap2(); // tukar baris dan kolomnya
            swap();  // simpan matriks baru ke temp

            break;

        default:
            break;
        }
    }
    // ini adalah print matriks baru tadi
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            printf("%c%c", matriksbaru[i][j], j == kolom - 1 ? '\n' : ' '); // memakai ternary operator agar tidak ada spasi di akhir
        }
    }
    int count = 0;
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            if (matriks[i][j] == matriksbaru[i][j]) // menyamakan matriks yang sudah diubah dengan matriks awal
            {
                count++; // tambahkan count
            }
        }
    }
    if (count == baris * kolom) // jika count ==baris kali kolom, artinya matriks sama persis
    {
        printf("Main lagi besok!\n"); // print ini
    }
    else
    {
        printf("Keren! Ayo kita main lagi!\n"); // jika tidak, print ini
    }
}
