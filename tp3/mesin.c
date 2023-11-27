//memanggil header
#include "header.h"

//kode perulangan menggukan fungsi
int ulang(int n)
{
    int a, b, x;
    //bila naik akan masuk ke fungsi bernama posisi
    posisi(a, b, x, n);
    //memberi masukan
    scanf("%d %d %d", &a, &b, &x);
    //base kondisi
    if (n == 1)
    {
        return 1;
    }
    //kode rekursif
    else
    { 
        return n * ulang(n - 1);
    }
}

int posisi(int a, int b, int x, int n)
{
    int jumlah, satu, dua, f, f1;
    //bila n sudah menjadi 0 maka akan di print
    if(n == 0)
    printf("%d %d %d", a, b, x);
    //base kondisi
    if (n == 1)
    {
        return 1;
    }
    //kode rekursif
    else
    {
        //rumus mencari virus
        jumlah = 2*x;
        f = x - 1;
        f1 = ((x - 2) * (x - 2)) - 1;

        jumlah *= f;
        jumlah += f1;
        jumlah= satu + dua;
        return n * posisi(a, b, x, n - 1);
    }
}
