#include "header.h"

void insertion(minyak toko[], int n)
{
    int i, j, data2, data3, data4, data5;
    double data;
    char data1[51];
    //kode insertion secara asc
    for (i = 0; i < n; i++)
    {
        data = toko[i].hasil;
        strcpy(data1, toko[i].nama);
        data2 = toko[i].kalori;
        data3 = toko[i].lemak;
        data4 = toko[i].harga;
        data5 = toko[i].sup;
        j = i - 1;

        while ((data < toko[j].hasil) && (j >= 0))
        {
            toko[j + 1].hasil = toko[j].hasil;
            strcpy(toko[j + 1].nama, toko[j].nama);
            toko[j + 1].kalori = toko[j].kalori;
            toko[j + 1].lemak = toko[j].lemak;
            toko[j + 1].harga = toko[j].harga;
            toko[j + 1].sup = toko[j].sup;
            j--;
        }
        toko[j + 1].hasil = data;
        strcpy(toko[j + 1].nama, data1);
        toko[j + 1].kalori = data2;
        toko[j + 1].lemak = data3;
        toko[j + 1].harga = data4;
        toko[j + 1].sup = data5;
    }
}

void selection(minyak toko[], int n)
{
    char data[51];
    int i, j, min, temp1, temp2, temp3, temp5;
    double temp4;
    
    // kode selection secara asc
    for (i = 0; i < (n - 1); i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (toko[min].hasil > toko[j].hasil)
            {
                min = j;
            }
        }
        temp1 = toko[i].harga;
        toko[i].harga = toko[min].harga; 
        toko[min].harga = temp1;

        strcpy(data, toko[i].nama);
        strcpy(toko[i].nama, toko[min].nama);
        strcpy(toko[min].nama, data);

        temp4 = toko[i].hasil;
        toko[i].hasil = toko[min].hasil; 
        toko[min].hasil = temp4;

        temp3 = toko[i].kalori;
        toko[i].kalori = toko[min].kalori; 
        toko[min].kalori = temp3;

        temp2 = toko[i].lemak;
        toko[i].lemak = toko[min].lemak; 
        toko[min].lemak = temp2;

        temp5 = toko[i].sup;
        toko[i].sup = toko[min].sup; 
        toko[min].sup = temp5;
    } 
}

void bubble(minyak toko[], int n)
{
    int tukar, i, j, temp2, temp3, temp4, temp5;
    double temp;
    char temp1[51]; 

    do
    {
        tukar = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (toko[i].hasil > toko[i + 1].hasil)
            {
                temp2 = toko[i].harga;
                toko[i].harga = toko[i + 1].harga;
                toko[i + 1].harga = temp2;

                strcpy(temp1, toko[i].nama);
                strcpy(toko[i].nama, toko[i + 1].nama);
                strcpy(toko[i + 1].nama, temp1);

                temp3 = toko[i].lemak;
                toko[i].lemak = toko[i + 1].lemak;
                toko[i + 1].lemak = temp3;

                temp4 = toko[i].kalori;
                toko[i].kalori = toko[i + 1].kalori;
                toko[i + 1].kalori = temp4;

                temp = toko[i].hasil;
                toko[i].hasil = toko[i + 1].hasil;
                toko[i + 1].hasil = temp;

                temp5 = toko[i].sup;
                toko[i].sup = toko[i + 1].sup;
                toko[i + 1].sup = temp5;
                    
                tukar = 1;
            }
        }   
    } while (tukar == 1);
}

void quick(minyak toko[],  int l, int r)
{
    int i, j, temp1, pivot, temp2, temp4, temp5;
    double temp;
    char temp3[51];
   
    i = l;  j = r;
    pivot = toko[(r + l) / 2].hasil;
    do
    {
        while ((toko[i].hasil < pivot) && (i <= j))
        {
            i++;
        }
        while ((toko[j].hasil > pivot) && (i <= j))
        {
            j--;
        }
            
        if (i < j)
        {   
            temp1 = toko[i].harga;
            strcpy(temp3, toko[i].nama);
            temp2 = toko[i].lemak;
            temp = toko[i].hasil;
            temp4 = toko[i].kalori;
            temp5 = toko[i].sup;

            toko[i].harga = toko[j].harga;
            strcpy(toko[i].nama, toko[j].nama);
            toko[i].lemak = toko[j].lemak;
            toko[i].hasil = toko[j].hasil;
            toko[i].kalori = toko[j].kalori;
            toko[i].sup = toko[j].sup;

            toko[j].harga = temp1;
            strcpy(toko[j].nama, temp3);
            toko[j].lemak = temp2;
            toko[j].hasil = temp;
            toko[j].kalori = temp4;
            toko[j].sup = temp5;
                
            i++;
            j--;
        }
    } while (i < j);

    //rekursif 
    if ((l < j) && (j < r))
    {
        quick(toko, l, j);
    }
    if ((i < r) && (i > l))
    {
        quick(toko, i, r);
    } 
}

void input(minyak toko[], int n, int supplier)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", toko[i].nama, &toko[i].kalori, &toko[i].lemak, &toko[i].harga);
        toko[i].kl= toko[i].kalori + toko[i].lemak;
        toko[i].hasil = (double)toko[i].harga / toko[i].kl;
        toko[i].sup = supplier;
    }
}

void gabung(minyak toko1[], minyak toko2[], minyak toko[], int n1, int n2)
{
    int i = 0,
        j = 0,
        k = 0,
        h = 0;

    while(i < n1 && j < n2)
    {   //bila anan 1 lebih kecil dari ana 2
        if(toko1[i].hasil < toko2[j].hasil)
        {
            toko[k].hasil = toko1[i].hasil;
            toko[k].harga = toko1[i].harga;
            strcpy(toko[k].nama, toko1[i].nama);
            toko[k].kalori = toko1[i].kalori;
            toko[k].lemak = toko1[i].lemak;
            toko[k].sup = toko1[i].sup;
            k++;
            i++;
        }
        //bila ana 2 lebih kecil dari ana 1
        else if(toko2[j].hasil < toko1[i].hasil)
        {
            toko[k].hasil = toko2[j].hasil;
            toko[k].harga = toko2[j].harga;
            strcpy(toko[k].nama, toko2[j].nama);
            toko[k].kalori = toko2[j].kalori;
            toko[k].lemak = toko2[j].lemak;
            toko[k].sup = toko2[j].sup;
            k++;
            j++;
        }
        //bila keduanya sama nilainya
        else
        {
            toko[k].hasil = toko1[i].hasil;
            toko[k].harga = toko1[i].harga;
            strcpy(toko[k].nama, toko1[i].nama);
            toko[k].kalori = toko1[i].kalori;
            toko[k].lemak = toko1[i].lemak;
            toko[k].sup = toko1[i].sup;
            k++;
            i++;
            toko[k].hasil = toko2[j].hasil;
            toko[k].harga = toko2[j].harga;
            strcpy(toko[k].nama, toko2[j].nama);
            toko[k].kalori = toko2[j].kalori;
            toko[k].lemak = toko2[j].lemak;
            toko[k].sup = toko2[j].sup;
            k++;
            j++;
        }
    }
    //jika ana 1 memiliki sisa
    if (i < n1)
    {
        for (h = i; h < n1; h++)
        {
            toko[k].hasil = toko1[h].hasil;
            toko[k].harga = toko1[h].harga;
            strcpy(toko[k].nama, toko1[h].nama);
            toko[k].kalori = toko1[h].kalori;
            toko[k].lemak = toko1[h].lemak;
            toko[k].sup = toko1[h].sup;
            k++;
        }
    }
    //jika ana 2 memiliki sisa
    else if (j < n2)
    {
        for (h = j; h < n2; h++)
        {
            toko[k].hasil = toko2[h].hasil;
            toko[k].harga = toko2[h].harga;
            strcpy(toko[k].nama, toko2[h].nama);
            toko[k].kalori = toko2[h].kalori;
            toko[k].lemak = toko2[h].lemak;
            toko[k].sup = toko2[h].sup;
            k++;
        }
    }
}

void print(minyak toko[], int n, int supplier)
{
    int i;
    printf("\nSupplier %d:\n", supplier);
    for (i = 0; i < n; i++)
    {
        printf("%s %d %d %d ", toko[i].nama, toko[i].kalori, toko[i].lemak, toko[i].harga);
        if (toko[i].harga % toko[i].kl == 0) 
        {
            printf("%.0f\n", toko[i].hasil);
        }
        else
        {
        printf("%.2f\n", toko[i].hasil);
        }
    }
}

void semua(minyak toko[], int n)
{
    printf("\nSemua:\n");
    int i;
    for (i = 0; i < n; i++)
    {
        toko[i].kl= toko[i].kalori + toko[i].lemak;
        toko[i].hasil = (double)toko[i].harga / toko[i].kl;
        printf("%s %d %d %d - ", toko[i].nama, toko[i].kalori, toko[i].lemak, toko[i].harga);
        if (toko[i].harga % toko[i].kl == 0) 
        {
            printf("%.0f Supplier %d\n", toko[i].hasil, toko[i].sup);
        }
        else
        {
        printf("%.2f Supplier %d\n", toko[i].hasil, toko[i].sup);
        }
    }
}