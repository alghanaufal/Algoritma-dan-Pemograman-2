// panggil header
#include "header.h"

//kode utama
int main()
{
    // var untuk data film yang blm final
    int i, n = 0;
    // var untuk data list film
    data film[50];
    // var untuk menyimpan panjang spasi
    int panjang1[51], panjang2[51], panjang3[51], panjang4[51];
    int max1 = 0, max2 = 0, max3 = 0, max4 = 0;

    // buat var ffilm
    FILE *ffilm;
    // buka file listfilm.dat untuk dibaca
    ffilm = fopen("listfilm.dat", "r");
    // baca data pertama di dlm file
    fscanf(ffilm, "%s %s %s", film[n].nama, film[n].sutradara, film[n].genre);
    fscanf(ffilm, "%s", film[n].bioskop);
    //jika nama film sama dengan #### maka file kosong
    if (strcmp(film[n].nama, "####") == 0)
    {
        printf("File Kosong!\n");
    }
    else
    {   
        // bila tida sama maka akan dibaca
        while (strcmp(film[n].nama, "####") != 0)
        {
            // ingkremenkan n
            n++;
            // baca file
            fscanf(ffilm, "%s %s %s", film[n].nama, film[n].sutradara, film[n].genre);
            fscanf(ffilm, "%s", film[n].bioskop);
            // hitung panjang string terbanyak untuk dijadikan spasi
            panjang1[n] = strlen(film[n].nama);
            if (panjang1[n] > max1)
            {
                max1 = panjang1[n];
            }
        }  
    }
    fclose(ffilm);  // tutup file listfilm

    int j = 0;
    // buka file sutradara.dat dan baca
    ffilm = fopen("sutradara.dat", "r");
    // var untuk data sutradara
    data sutradara[20];
    // baca data pertama di dlm file
    fscanf(ffilm, "%s %s", sutradara[j].id, sutradara[j].sutradara);
    // jika isi file sama dengan #### maka file kosong
    if(strcmp(sutradara[j].id, "####") == 0)
    {
        printf("File kosong!\n");
    }
    else
    {
        // jika isi file tidak sama dengna #### maka baca
        while(strcmp(sutradara[j].id, "####") != 0)
        {
            // ingkremenkan
            j++;
            // baca isi file
            fscanf(ffilm, "%s %s", sutradara[j].id, sutradara[j].sutradara);
        }
    }
    fclose(ffilm);  // tutup file sutradara

    int z;
    // lakukan pengcopyan 
    for (i = 0; i < n; i++)
    {
        for (z = 0; z < j; z++)
        {
            // bila id di file film sama dengan id di file sutradara
            if(strcmp(film[i].sutradara, sutradara[z].id) == 0)
            {
                // copy isi data dari file sutradara ke file list film
                strcpy(film[i].sutradara, sutradara[z].sutradara);
                // hitung string terpanjang terbanyak untuk spasi
                panjang2[i] = strlen(film[i].sutradara);
                if (panjang2[i] > max2)
                {
                    max2 = panjang2[i];
                }
                break;
            }
        }
    }

    int f = 0;
    // buka file genre.dat dan baca
    ffilm = fopen("genre.dat", "r");
    // var data genre
    data genre[20];
    // baca data pertama file genre
    fscanf(ffilm, "%s %s", genre[f].id, genre[f].genre);
    // bila data pertama sama dengan #### maka file kosong 
    if(strcmp(genre[f].id , "####") == 0)
    {
        printf("File kosong!\n");
    }
    else
    {
        // bila datanya tidak sama dengan #### maka baca data file
        while(strcmp(genre[f].id, "####") != 0)
        {
            // ingkremenkan
            f++;
            // baca data file genre
            fscanf(ffilm, "%s %s", genre[f].id, genre[f].genre);
        }
    }
    fclose(ffilm);  // tutup file genre

    for (i = 0; i < n; i++)
    {
        for (z = 0; z < f; z++)
        {
            //bila id pada file film sama dengan id file genre
            if(strcmp(film[i].genre, genre[z].id) == 0)
            {
                // copy genre di file genre ke file film
                strcpy(film[i].genre, genre[z].genre);
                // menentukan spasi dengan hitung string terpanjang
                panjang3[i] = strlen(film[i].genre);
                if (panjang3[i] > max3)
                {
                    max3 = panjang3[i];
                }
                break;
            }
        }
    }

    int k = 0;
    // buka file bioskop.dat dan baca
    ffilm = fopen("bioskop.dat", "r");
    // var data biosko
    data bioskop[20];
    // baca data pertama di dlm file bioskop.dat
    fscanf(ffilm, "%s %s", bioskop[k].id, bioskop[k].bioskop);
    // bila data pertama sama dengan #### maka file kosong
    if(strcmp(bioskop[k].id , "####") == 0)
    {
        printf("File kosong!\n");
    }
    else
    {
        // bila data pertama di id genre tidak sama dengan ####
        while(strcmp(bioskop[k].id, "####") != 0)
        {
            // ingkremenkan
            k++;
            // baca data pada file bioskop
            fscanf(ffilm, "%s %s", bioskop[k].id, bioskop[k].bioskop);
        }
    }
    fclose(ffilm);  // tutup file bioskop

    for (i = 0; i < n; i++)
    {
        for (z = 0; z < k; z++)
        {
            //bila id pada bioskop file film sama dengan id file bioskop
            if(strcmp(film[i].bioskop, bioskop[z].id) == 0)
            {
                // copy bioskop ke bioskop di file film
                strcpy(film[i].bioskop, bioskop[z].bioskop);
                // hitung string terpanjang untuk spasi
                panjang4[i] = strlen(film[i].bioskop);
                if (panjang4[i] > max4)
                {
                    max4 = panjang4[i];
                }
                break;
            }
        }
    }

    // buka file listfilmfinal untuk menuliskan hasil dari data semua file
    ffilm = fopen("listfilmfinal.dat", "w");
    for (i = 0; i < n; i++)
    {
        // lakukan print ke file list film final
        fprintf(ffilm, "%s \t%s \t%s", film[i].nama, film[i].sutradara, film[i].genre);
        fprintf(ffilm, " \t%s\n", film[i].bioskop);
    } 
    // print juga #### ini untuk
    fprintf(ffilm, "#### #### #### ####\n");
    fclose(ffilm);  // tutu file list film final

    int penentu = 0;    // menentukan perintah
    char search1[51];   // var cari data sutradara
    char search2[51];   // var cari data genre
    char search3[51];   // var cari data bioskop
    int pilih = 0;      // pilih perintah yang ingin dicarai atau ditambah
    printf("Pilih dan ketik :\n1. Lihat List Film\n2. Cari Data\n3. Tambah Data\nPilihan : ");
    scanf("%d", &penentu);  //masukan penentu

    // isi penentu masuk ke switch
    switch (penentu)
    {
        case 1: // bila penentu 1
            // masuk ke prosedru print
            printfinal(film, n, max1, max2, max3, max4);
        break;

        case 2: // bila penentu 2
            printf("Pilih data yang ingin dicari :\n1. Data Sutradara\n2. Data Genre\n3. Data Bioskop\n");
            printf("Pilihan : ");
            scanf("%d", &pilih);    // pilih file apa yg ingin dicari
            if (pilih == 1)
            {    
                printf("cari : ");
                scanf("%s", search1);   // masukan id untuk mencari
                carisutradara(search1); // masuk ke prosedur cari sutradara
            }
            else if (pilih == 2)
            {
                printf("cari : ");
                scanf("%s", search2);   // masukan id untuk mencari
                carigenre(search2);     // masuk ke prosedur cari genre
            }
            else if (pilih == 3)
            {
                printf("cari : ");      
                scanf("%s", search2);   // masukan id untuk mencari
                caribioskop(search2);   // masuk ke prosedur cari bioskop
            }
        break;

        case 3:
            printf("Pilih data yang ingin ditambah :\n1. Data List Film\n2. Data Sutradara\n3. Data Genre\n4. Data Bioskop\n");
            printf("Pilihan : ");
            scanf("%d", &pilih);    // tentukan data yag ingin di tambah
            if (pilih == 1)
            {
                tambahfilm();       // prosedur tambah film
            }
            else if (pilih == 2)
            {    
                tambahsutradara();  // prosedur tambah sutradara
            }
            else if (pilih == 3)
            {
                tambahgenre();      // prosedur tambah genre
            }
            else if (pilih == 4)
            {           
                tambahbioskop();    // prosedur tambah bioskop
            }
        break;
    }
    // akhir kode
    return 0;
}