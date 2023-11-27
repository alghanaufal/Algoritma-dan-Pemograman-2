// panggil header
#include "header.h"

// kode utama
int main()
{
    char pita[101];     // var pita
    int n = 0;          // var n
    // masukan input
    scanf("%100[^\n]s", &pita);

    // mulai mesin
    start(pita);
    while (eop() == 0)  // jika eop blm hidup mesin terus dijalankan
    {
        if (getindeks() == 0)       // bila indeks sama dengan 0
        {
            printf("%c", getcc());  // print tampa spasi
        }
        if (getindeks() != 0)       // bila lebih dari 0
        {   
            if (getcc() >= 'A' && getcc() <= 'Z')   // bila kapital
            {
                if (n == 0)     // bila n sama dengan 0
                {   
                    back(pita); // cek indeks sebelumnya
                    if (getcc() >= 'A' && getcc() <= 'Z')   // bila indeks sebelumnya kapital
                    {
                        inc(pita);  // majukan indeks dan print
                        printf("%c", getcc());
                    }             
                    if (getcc() >= 'a' && getcc() <= 'z')   // bila indeks sebelumnya kecil
                    {
                        inc(pita);  // majukan indeks dan print 
                        printf(" %c", getcc());
                    }
                }
                if (n == 1)     // bila n sama dengan 1
                {
                    printf("%c", getcc());
                }
                
            }
            if (getcc() >= 'a' && getcc() <= 'z')   // bila kecil
            {
                if (n == 1)     // bila n sama dengan 1
                {   
                    back(pita);     // cek indeks sebelumnya
                    if (getcc() >= 'A' && getcc() <= 'Z')
                    {
                        inc(pita);  // majukan indeks dan print
                        printf("%c ", getcc());
                    }             
                    if (getcc() >= 'a' && getcc() <= 'z')   // bila indeks sebelumnya kecil
                    {
                        inc(pita);  // majukan indeks dan print
                        printf("%c", getcc());
                    }
                }
                if (n == 0)     // bila n sama dengan 0
                {
                    printf("%c", getcc());
                }
            }   
        }
        inc(pita);  // majukan indeks

        if (getcc() >= 'A' && getcc() <= 'Z')       // bila indeks setelahnya kapital
        {
            inc(pita);  // majukan indeks
            if (getcc() >= 'A' && getcc() <= 'Z')   // bila indeks setelahnya kapital
            {
                n = 0;
            }
            if (getcc() >= 'a' && getcc() <= 'z')   // bila indeks setelahnya kecil
            {
                n = 1;
                printf(" ");    // barikan spasi
            }
            back(pita); // mundurkan indeks
        }
        if (getcc() >= 'a' && getcc() <= 'z')       // bila indeks setelahnya kecil
        {
            inc(pita);  // majukan indeks
            if (getcc() >= 'A' && getcc() <= 'Z')   // bila indeks setelahnya kapital
            {
                n = 1;
            }
            if (getcc() >= 'a' && getcc() <= 'z')   // bila indeks setelahnya kecil
            {
                n = 0;
            }
            back(pita);  // mundurkan indeks
        }
    }

    printf("\n");   // berikan new line

    return 0;   // kembali ke 0
}