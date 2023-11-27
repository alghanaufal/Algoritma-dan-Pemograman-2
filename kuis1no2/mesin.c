//memanggil libary header
#include "header.h"

//kode prosedurnya dengan memaggil no 1-3 dan juga n
int posisi(int no1, int no2, int no3, int n)
{   
    // bila n nya tidak sama dengan 0 maka diakhir akan diberikan spasi
    if(n != 0)
    {
    printf("%d %d %d ", no1, no2, no3);
    }
    //bila n nya sudah sama dengan 0 maka diakhirnya tidak diberi spasi
    if(n == 0)
    {
    printf("%d %d %d", no1, no2, no3);
    }
    //bila n sama dengan 0 maka akan kembali ke 1
    if (n == 0)
    {
        return 1;
    }
    //bila tidak 0 maka akan dilakukan prosedur rekursi
    else
    {
        no2 *= no2; //mengakarkan no 2
        no3 +=no2;  //menambahkan no 3 dengan 2
        return n * posisi(no1, no2, no3, n - 1);//kembali ke prosedur posisi dengan mengurangi nilai n
    } 
}