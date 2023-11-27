// memanggil header
#include "header.h"

// kode utama
int main()
{
    data kata[101];       // simpat kata
    char pita[101];       // var input kata
    int in1 = 0, in2 = 0; // var input int
    int len = 0, sho = 0; // simpat jarak kata

    scanf("%d %d %100[^\n]s", &in1, &in2, &pita); // input

    // tentukan jarak katanya
    if (in1 < in2) // bila in1 nya yg lebih kecil
    {
        sho = in1;
        len = in2;
    }
    else if (in2 < in1) // bila in2 nya yg lebih kecil
    {
        sho = in2;
        len = in1;
    }
    // var jumlah kata saat dipisah nanti
    int a = 0, b = 0, c = 0;

    start(pita); // mulai mesin

    if (getlen() <= sho) // bila panjang katanya lebih kecil dari jarak kecil
    {
        strcpy(kata[a].pendek, getcw()); // copy ke data kata
        a++;                             // ingkremenkan
    }
    if (getlen() > sho) // bila panjang katanya lebih dari jarak kecil
    {
        if (getlen() <= len) // tapi lebih kecil dari jarak besar
        {
            strcpy(kata[b].tengah, getcw()); // copy ke data kata
            b++;                             // ingkremenkan
        }
        else if (getlen() > len) // tapi bila lebih besar dari jarak besar
        {
            strcpy(kata[c].panjang, getcw()); // copy ke data kata
            c++;                              // ingkremenkan
        }
    }

    while (eop(pita) == 0) // mulai baca mesin sampai menemukan eop
    {
        inc(pita);           // ingkremenkan pita
        if (getlen() <= sho) // bila panjang katanya lebih kecil dari jarak kecil
        {
            strcpy(kata[a].pendek, getcw()); // copy ke data kata
            a++;                             // ingkremenkan
        }
        if (getlen() > sho) // bila panjang katanya lebih dari jarak kecil
        {
            if (getlen() <= len) // tapi lebih kecil dari jarak besar
            {
                strcpy(kata[b].tengah, getcw()); // copy ke data kata
                b++;                             // ingkremenkan
            }
            else if (getlen() > len) // tapi bila lebih besar dari jarak besar
            {
                strcpy(kata[c].panjang, getcw()); // copy ke data kata
                c++;                              // ingkremenkan
            }
        }
    }
    if (a == 0) // bila a nya masih 0 tandanya tidak ada
    {
        printf("KATA PENDEK\nTIDAK ADA.\n\n");
    }
    else if (a != 0) // bila tidak 0 maka print
    {
        pendek(kata, a); // masukan ke prosedur pendek
    }

    if (b == 0) // bila b nya masih 0 tandanya tidak ada
    {
        printf("KATA MENENGAH\nTIDAK ADA.\n\n");
    }
    else if (b != 0) // bila tidak 0 maka print
    {
        tengah(kata, b); // masukan ke prosedur tengah
    }

    if (c == 0) // bila c nya masih 0 tandanya tidak ada
    {
        printf("KATA PANJANG\nTIDAK ADA.\n");
    }
    else if (c != 0) // bila tidak 0 maka print
    {
        panjang(kata, c); // masukan ke prosedur panjang
    }

    return 0; // akhir program
}