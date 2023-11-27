// memanggil header
#include "header.h"

// prosedur input
void input(data kuliner[], int n)
{
    // input
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %s %d", kuliner[i].nama, &kuliner[i].harga, kuliner[i].tempat, &kuliner[i].kalori);
    }
    char penentu[51];
    scanf("%s", penentu);   // penentu yg dicari harga atau kalorinya

    // masukan ke prosedur sorting
    selection(kuliner, n, penentu);
    
    int search = 0;
    scanf("%d", &search);   // masukan pencarian
    // cek di prosedur cari ada atau tidak
    if (cari(kuliner, n, search, penentu))
    {
        printf("\n");   // bila ada print new line di akhir
    }
    else
    {
        printf("tidak ditemukan\n");    // print ini bila tidak menemukannya
    }
}

//prosedur sorting dengan selection
void selection(data kuliner[], int n, char penentu[])
{
    char data1[51], data2[51];
    int i, j, min = 0, temp1 = 0, temp2 = 0;    //var simpan

    if (strcmp(penentu, "harga") == 0)     //bila diurut secara harga    
    {   // kode selection secara asc
        for (i = 0; i < n - 1; i++)
        {
            min = i;

            for (j = i + 1; j < n; j++)
            {
                if (kuliner[min].harga > kuliner[j].harga)
                {
                    min = j;
                }
            }
            strcpy(data1, kuliner[i].nama);
            strcpy(kuliner[i].nama, kuliner[min].nama);
            strcpy(kuliner[min].nama, data1);

            temp1 = kuliner[i].harga;
            kuliner[i].harga = kuliner[min].harga; 
            kuliner[min].harga = temp1;

            strcpy(data2, kuliner[i].tempat);
            strcpy(kuliner[i].tempat, kuliner[min].tempat);
            strcpy(kuliner[min].tempat, data2);

            temp2 = kuliner[i].kalori;
            kuliner[i].kalori = kuliner[min].kalori; 
            kuliner[min].kalori = temp2;
        } 
    }
        
    else if (strcmp(penentu, "kalori") == 0)   //bila diurut secara kalori
    {   // kode selecrion secara desc
        for (i = 0; i < n - 1; i++)
        {
            min = i;

            for (j = i + 1; j < n; j++)
            {
                if (kuliner[min].kalori < kuliner[j].kalori)
                {
                    min = j;
                }
            }
            strcpy(data1, kuliner[i].nama);
            strcpy(kuliner[i].nama, kuliner[min].nama);
            strcpy(kuliner[min].nama, data1);

            temp1 = kuliner[i].harga;
            kuliner[i].harga = kuliner[min].harga; 
            kuliner[min].harga = temp1;

            strcpy(data2, kuliner[i].tempat);
            strcpy(kuliner[i].tempat, kuliner[min].tempat);
            strcpy(kuliner[min].tempat, data2);

            temp2 = kuliner[i].kalori;
            kuliner[i].kalori = kuliner[min].kalori; 
            kuliner[min].kalori = temp2;
        } 
    }
}

int cari(data kuliner[], int n, int search, char penentu[])
{

    int i = 0, k = 0, found = 0;
    int status = 0;
    if (strcmp(penentu, "harga") == 0)     // bila yg dicari harga     
    { 
        while ((i <= n) && (found == 0))
        {
            k = (int)((i + n) / 2);
            if (kuliner[k].harga == search)     // bila sudah sama antar yg dicari dengan data maka ditemukan dan print
            {
                found = 1;  // jadikan found menjadi 1 untuk menandakan yg dicari telah ditemukan
                printf("nama makanan: %s\n", kuliner[k].nama);
                printf("harga: %d\n", kuliner[k].harga);
                printf("tempat penjualan: %s\n", kuliner[k].tempat);
                printf("persen kalori: %d", kuliner[k].kalori);
            }
            else       // bila masih blm ditemukan
            {
                if (kuliner[k].harga > search)  // dan kulinernya masih lebih besar dari yg dicari 
                {
                    n = k - 1;
                }
                else
                {
                    i = k + 1;
                }
            }
        }
    }

    else if (strcmp(penentu, "kalori") == 0)   // bila yg dicari adalah kalori
    { 
       while ((i <= n) && (found == 0))
        {
            k = (int)((i + n) / 2);
            if (kuliner[k].kalori == search)    // bila yg dicari sudah sama dengan kalori maka print
            {
                found = 1;      // tandai found dengan 1 agar proses berakhir
                printf("nama makanan: %s\n", kuliner[k].nama);
                printf("harga: %d\n", kuliner[k].harga);
                printf("tempat penjualan: %s\n", kuliner[k].tempat);
                printf("persen kalori: %d", kuliner[k].kalori);
            }
            else
            {
                if (kuliner[k].kalori < search)     // bila yg dicari masih kecil dengan kalori
                {
                    n = k - 1;
                }
                else
                {
                    i = k + 1;
                }
            }
        } 
    }
    return found;   // kembalikan ke found
}