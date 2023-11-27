//memanggil libary header di file 1
#include "header.h"

//kode utama
int main()
{
    int no1,    //input 1
        no2,    //input 2
        no3,    //input 3
        n;      //jumlah penjumlahan

    //var masukan 
    scanf("%d %d %d", &no1, &no2, &no3);
    scanf("%d", &n);

    //memasukannnya ke prosedur
    posisi(no1, no2, no3, n);
    printf("\n");
    
    return 0;
}