// panggil header
#include "header.h"

// membuat input sesuai panjang n
void input(list mhs[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s %s %d", mhs[i].nim, mhs[i].nama, &mhs[i].nilai);
    }
}

// melakukan sorting dengan bubble
void bubble(list mhs[], int n)
{
    int tukar, i, temp3;
    char temp1[51], temp2[11]; 

    do
    {
        tukar = 0;
        for (i = 0; i < n - 1; i++)
        {
            // membandingkan nim
            if (strcmp(mhs[i].nim, mhs[i + 1].nim) > 0)
            {
                strcpy(temp2, mhs[i].nim);
                strcpy(mhs[i].nim, mhs[i + 1].nim);
                strcpy(mhs[i + 1].nim, temp2);

                strcpy(temp1, mhs[i].nama);
                strcpy(mhs[i].nama, mhs[i + 1].nama);
                strcpy(mhs[i + 1].nama, temp1);

                temp3 = mhs[i].nilai;
                mhs[i].nilai = mhs[i + 1].nilai;
                mhs[i + 1].nilai = temp3;

                tukar = 1;
            }
        }   
    } while (tukar == 1);
}

// gabungkan arr dan rapikan
void gabung(list mhs1[], list mhs2[], list mhs[], int n1, int n2)
{
    int i = 0,
        j = 0,
        k = 0,
        h = 0;

    while(i < n1 && j < n2)
    {   //bila anan 1 lebih kecil dari ana 2
        if(strcmp(mhs1[i].nim, mhs2[j].nim) < 0)
        {
            strcpy(mhs[k].nim, mhs1[i].nim);
            mhs[k].nilai = mhs1[i].nilai;
            strcpy(mhs[k].nama, mhs1[i].nama);
            k++;
            i++;
        }
        //bila ana 2 lebih kecil dari ana 1
        else if(strcmp(mhs2[j].nim, mhs1[i].nim) < 0)
        {
            strcpy(mhs[k].nim, mhs2[j].nim);
            mhs[k].nilai = mhs2[j].nilai;
            strcpy(mhs[k].nama, mhs2[j].nama);
            k++;
            j++;
        }
        //bila keduanya sama nilainya
        else
        {
            strcpy(mhs[k].nim, mhs1[i].nim);
            mhs[k].nilai = mhs1[i].nilai;
            strcpy(mhs[k].nama, mhs1[i].nama);
            k++;
            i++;
            strcpy(mhs[k].nim, mhs2[j].nim);
            mhs[k].nilai = mhs2[j].nilai;
            strcpy(mhs[k].nama, mhs2[j].nama);
            k++;
            j++;
        }
    }
    //jika ana 1 memiliki sisa
    if (i < n1)
    {
        for (h = i; h < n1; h++)
        {
            strcpy(mhs[k].nim, mhs1[h].nim);
            mhs[k].nilai = mhs1[h].nilai;
            strcpy(mhs[k].nama, mhs1[h].nama);
            k++;
        }
    }
    //jika ana 2 memiliki sisa
    else if (j < n2)
    {
        for (h = j; h < n2; h++)
        {
            strcpy(mhs[k].nim, mhs2[h].nim);
            mhs[k].nilai = mhs2[h].nilai;
            strcpy(mhs[k].nama, mhs2[h].nama);
            k++;
        }
    }
}

// print semua yang sudah di sorting 
void semua(list mhs[], int n)
{
    printf("====================\n");
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s %s %d\n", mhs[i].nim, mhs[i].nama, mhs[i].nilai);
    }
}

// print sorting nilai bagian 1
void nilai1(list mhs[], int n)
{
    int i;
    int tukar, temp3;
    char temp1[51], temp2[11]; 

    do
    {
        tukar = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (mhs[i].nilai < mhs[i + 1].nilai)
            {
                strcpy(temp2, mhs[i].nim);
                strcpy(mhs[i].nim, mhs[i + 1].nim);
                strcpy(mhs[i + 1].nim, temp2);

                strcpy(temp1, mhs[i].nama);
                strcpy(mhs[i].nama, mhs[i + 1].nama);
                strcpy(mhs[i + 1].nama, temp1);

                temp3 = mhs[i].nilai;
                mhs[i].nilai = mhs[i + 1].nilai;
                mhs[i + 1].nilai = temp3;

                tukar = 1;
            }
        }   
    } while (tukar == 1);
    printf("====================\n");
    for (i = 0; i < n; i++)
    {
        printf("%s %s %d\n", mhs[i].nim, mhs[i].nama, mhs[i].nilai);
    }
}

// print sorting nilai bagian 2
void nilai2(list mhs[], int n)
{
    int i;
    int tukar, temp3;
    char temp1[51], temp2[11]; 

    do
    {
        tukar = 0;
        for (i = n/2; i < n - 1; i++)
        {
            if (mhs[i].nilai < mhs[i + 1].nilai)
            {
                strcpy(temp2, mhs[i].nim);
                strcpy(mhs[i].nim, mhs[i + 1].nim);
                strcpy(mhs[i + 1].nim, temp2);

                strcpy(temp1, mhs[i].nama);
                strcpy(mhs[i].nama, mhs[i + 1].nama);
                strcpy(mhs[i + 1].nama, temp1);

                temp3 = mhs[i].nilai;
                mhs[i].nilai = mhs[i + 1].nilai;
                mhs[i + 1].nilai = temp3;

                tukar = 1;
            }
        }   
    } while (tukar == 1);
    printf("====================\n");
    for (i = n/2; i < n; i++)
    {
        printf("%s %s %d\n", mhs[i].nim, mhs[i].nama, mhs[i].nilai);
    }
    printf("====================\n");
}