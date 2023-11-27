#include "header.h"

int main()
{
    int n1, n2, n3,
        i;
    char penentu[3];
    scanf("%s", penentu);

    scanf("%d", &n1);
    minyak toko1[n1];
    // for (i = 0; i < n1; i++)
    // {
    //     scanf("%s %d %d %d", toko1[i].nama, &toko1[i].kalori, &toko1[i].lemak, &toko1[i].harga);
    //     toko1[i].kl= toko1[i].kalori + toko1[i].lemak;
    //     toko1[i].hasil = (double)toko1[i].harga / toko1[i].kl;
    //     toko1[i].sup = 1;
    input(toko1, n1, 1);
    // }

    scanf("%d", &n2);
    minyak toko2[n2];
    // for (i = 0; i < n2; i++)
    // {
    //     scanf("%s %d %d %d", toko2[i].nama, &toko2[i].kalori, &toko2[i].lemak, &toko2[i].harga);
    //     toko2[i].kl= toko2[i].kalori + toko2[i].lemak;
    //     toko2[i].hasil = (double)toko2[i].harga / toko2[i].kl;
        // toko2[i].sup = 2;
    input(toko2, n2, 2);
    // }

    scanf("%d", &n3);
    minyak toko3[n3];
    // for (i = 0; i < n3; i++)
    // {   
    //     scanf("%s %d %d %d", toko3[i].nama, &toko3[i].kalori, &toko3[i].lemak, &toko3[i].harga);
    //     toko3[i].kl= toko3[i].kalori + toko3[i].lemak;
    //     toko3[i].hasil = (double)toko3[i].harga / toko3[i].kl;
    //     toko3[i].sup = 3;
    input(toko3, n3, 3);
    // }

    minyak toko12[n1 + n2];
    minyak toko[n1 + n2 + n3];

    if (strcmp(penentu, "is") == 0)
    {   
        insertion(toko1, n1);
        insertion(toko2, n2);
        gabung(toko1, toko2, toko12, n1, n2);
        insertion(toko3, n3);
        gabung(toko12, toko3, toko, n1 + n2, n3);
    }
    else if (strcmp(penentu, "ss") == 0)
    {
        selection(toko1, n1);
        selection(toko2, n2);
        gabung(toko1, toko2, toko12, n1, n2);
        selection(toko3, n3);
        gabung(toko12, toko3, toko, n1 + n2, n3);
    }
    else if (strcmp(penentu, "bs") == 0)
    {
        bubble(toko1, n1);
        bubble(toko2, n2);
        gabung(toko1, toko2, toko12, n1, n2);
        bubble(toko3, n3);
        gabung(toko12, toko3, toko, n1 + n2, n3);
    }
    else if (strcmp(penentu, "qs") == 0)
    {
        quick(toko1, 0, n1 - 1);
        quick(toko2, 0, n2 - 1);
        gabung(toko1, toko2, toko12, n1, n2);
        quick(toko3, 0, n3 - 1);
        gabung(toko12, toko3, toko, n1 + n2, n3);
    }
    
    printf("Per Supplier:");
    // printf("\nSupplier %d:\n", toko1[0].sup);
    print(toko1, n1, 1);
    // printf("\nSupplier %d:\n", toko2[0].sup);
    print(toko2, n2, 2);
    // printf("\nSupplier %d:\n", toko3[0].sup);
    print(toko3, n3, 3);

    semua(toko, n1 + n2 + n3);

    return 0;
}