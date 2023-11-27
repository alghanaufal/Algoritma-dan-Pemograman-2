// memanggil header
#include "header.h"

// kode utama
int main()
{
    int n = 0;  // jumlah data yg ingin di input
    scanf("%d", &n);
    data kuliner[n];    // var kuliner 

    input(kuliner, n);  // masukan ke var prosedur

    // kembali ke 0
    return 0;
}