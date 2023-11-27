// menganggil header
#include "header.h"

// kode utama
int main()
{
    // var seberapa panjang arr 1, 2, dan 3
    int n1, n2, n3,
    // ingkremen
        i;

    // input 1
    scanf("%d", &n1);
    list mhs1[n1];
    input(mhs1, n1);

    // input 2
    scanf("%d", &n2);
    list mhs2[n2];
    input(mhs2, n2);

    // input 3
    scanf("%d", &n3);
    list mhs3[n3];
    input(mhs3, n3);

    // var gabung antar input 1 dan 2
    list mhs12[n1 + n2];
    // var gabung antara semua input
    list mhs[n1 + n2 + n3];

    // sorting dengan bubble
    bubble(mhs1, n1);
    bubble(mhs2, n2);
    // gabungkan kedua sorting
    gabung(mhs1, mhs2, mhs12, n1, n2);
    // sorting input 3 dengan bubble
    bubble(mhs3, n3);
    // gabung semuanya
    gabung(mhs12, mhs3, mhs, n1 + n2, n3);

    // print semuanya
    semua(mhs, n1 + n2 + n3);

    // print setengah dan urut nilai
    nilai1(mhs, (n1 + n2 + n3) / 2);

    // print setengah dan urut nilai
    nilai2(mhs, n1 + n2 + n3);

    // akhir program
    return 0;
}