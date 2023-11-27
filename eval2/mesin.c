#include "header.h"

data brg[201];
int idx,     // index dari karakter terakhir kata
           wlen;    // panjang kata
char cw[201];    // karakter "saat ini" (current word)

int max1, max2, max3;
int panjang1[201], panjang2[201], panjang3[201];

// Prosedur untuk memulai mesin kata
void start(char pita[])
{
    // Inisialisasi indeks dan panjang kata memidx=0;wlen-0;
    idx=0;
    wlen=0;

    // jika karkater dalam pita adalah spasi, indeks e=terus maju
    while (pita[idx] == ' ')
    {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((pita[idx] != ' ') && (eop(pita) == 0))
    {
        cw[wlen] = pita[idx];
        idx++;
        wlen++;
    }

    // Mengatur agar kata  saat ini indeks terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Prosedur untuk mengosongkan kata yang dibaca dalam mesin kata
void reset()
{
    // inisialisasi panjang kata dan kata saat ini agar NULL
    wlen = 0;
    cw[wlen] = '\0';
}

// Fungsi untuk memeriksa akhir dari proses (End Of Process)
int eop(char pita[])
{
    // Memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (pita[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Prosedur untuk memajukan kata
void inc(char pita[])
{
    // Inisialisasi ulang panjang kata
    wlen = 0;

    // jika karkater dalam pita adalah spasi, indeks e=terus maju
    while (pita[idx] == ' ')
    {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while (pita[idx] != ' ' && eop(pita) == 0)
    {
        cw[wlen] = pita[idx];
        idx++;
        wlen++;
    }

    // Mengatur agar kata  saat ini indeks terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// fungsi untuk mendapatkan panjang kata saat ini
int getlen()
{
    return wlen;
}

// fungsi untuk mendapatkan kata saat ini
char *getcw()
{
    return cw;
}

// Prosedur untuk memberikan input ke mesin kata
void input()
{
    char pita[501];     // var input
    int n = 0;          // menentukan banyak inputan
    int keluar = 1;     // menentukan akhir kata
    while (keluar == 1)
    {
        scanf(" %500[^\n]s", pita);     // masukan input
        if (strcmp(pita, "SELESAI;") == 0)  // bila ingin mengakhiri program
        {
            keluar = 0;
        }
        else
        {
            n++;        // ingkremenkan
            inquery(pita, brg, n);  // menentukan query
        }
    }
    
    int j = 0;
    int i;
    int total = 0;
    getspace(n);    // tentukan spasi
    printf("=");
    for ( i = 1; i < max1 + max2 + max3 + 12; i++)
    {
        printf("=");
    }
    printf("=\n");
    printf("| BARANG");
    for ( i = 1; i < max1 - 5; i++)
    {
        printf(" ");
    }
    printf(" | HARGA");
    for ( i = 1; i < max2 - 1; i++)
    {
        printf(" ");
    }
    printf(" | STATUS");
    for ( i = 1; i < max3 - 5; i++)
    {
        printf(" ");
    }
    printf(" |\n");
    printf("=");
    for ( i = 1; i < max1 + max2 + max3 + 12; i++)
    {
        printf("=");
    }
    printf("=\n");
    for ( i = 1 ; i < n + 1; i++)
    {
        // bila data sama dengan "###" maka print berakhir
        if (strcmp(brg[i].nama, "###") != 0) 
        {
            total++;    // tentukan banyak barang
            printf("| %s", brg[i].nama);
            for ( j = 0; j < max1 - strlen(brg[i].nama); j++)
            {
                printf(" ");
            }
            printf(" | Rp.%s", brg[i].harga);
            for ( j = 0; j < max2 - strlen(brg[i].harga); j++)
            {
                printf(" ");
            }
            printf(" | %s", brg[i].status);
            for ( j = 0; j < max3 - strlen(brg[i].status); j++)
            {
            printf(" ");
            }
            printf(" |\n");
        }
    }
    printf("=");
    for ( i = 1; i < max1 + max2 + max3 + 12; i++)
    {
        printf("=");
    }
    printf("=\n");
    // tampilkan total barang
    printf("%d data ditampilkan.\n", total);
}

// prosedur insert dan update
void inquery(char pita[], data brg[], int i)
{
    // memulai mesin kata
    start(pita);

    // untuk insert data
    if (strcmp(getcw(), "INSERT") == 0)
    {   
        inc(pita);
        strcpy(brg[i].nama, getcw());
        inc(pita);
        strcpy(brg[i].harga, getcw());
        inc(pita);
        strcpy(brg[i].status, getcw());
    }
    // bila data update
    else if (strcmp(getcw(), "UPDATE") == 0)
    {
        inc(pita);
        // dan yg dipilih status
        if (strcmp(getcw(), "STATUS") == 0)
        {
            inc(pita);
            for (int j = 0; j < i; j++) 
            {
                if(strcmp(brg[j].nama, getcw()) == 0) 
                {
                    inc(pita);
                    strcpy(brg[j].status, getcw());  
                }
            }
            strcpy(brg[i].nama, "###");
            strcpy(brg[i].harga, "###");
            strcpy(brg[i].status, "###");
        }
        // dan yg dipilih harga
        else if (strcmp(getcw(), "HARGA") == 0)
        {
            inc(pita);
            for (int j = 0; j < i; j++) 
            {
                if(strcmp(brg[j].nama, getcw()) == 0) 
                {
                    inc(pita);
                    strcpy(brg[j].harga, getcw());  
                }
            }
            strcpy(brg[i].nama, "###");
            strcpy(brg[i].harga, "###");
            strcpy(brg[i].status, "###");
        }
    }
}

// Prosedur untuk mendapat spasi
void getspace(int n)
{
    max1 = 0, max2 = 0, max3 = 0;
    for (int i = 1; i < n + 1; i++)     
    {
        if (strlen(brg[i].nama) > max1 ) 
        {
            max1 = strlen(brg[i].nama);
            if (strlen("BARANG") > max1 ) 
            {
                max1 = 6;
            }
        }
        
        if (strlen(brg[i].harga) > max2)
        {
            max2 = strlen(brg[i].harga);
            if (strlen("HARGA") > max2)
            {
                max2 = 8;
            }
        }
        
        if (strlen(brg[i].status) > max3)
        {
            max3 = strlen(brg[i].status);
            if (strlen("STATUS") > max3)
            {
                max3 = 6;
            }
        }
    }
}