// memanggil header
#include "header.h"

// var global yang ada di header
int idx, wlen;
char cw[201];

FILE *fdata;
data thp[201];
data tspek[201];
data tcam[201];

int nquery, nhp, nspek, ncam;
int lenidh, lenhp1, lenhp2, lenhp3;
int lenids, lenspek1, lenspek2, lenspek3;
int lenidc, lencam1, lencam2, lencam3;

char query[201][201];

// Prosedur untuk memulai mesin kata
void start(char pita[])
{
    // Inisialisasi indeks dan panjang kata memidx=0;wlen-0;
    idx = 0;
    wlen = 0;

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
    system("cls"); // Membersihkan cmd

    char pita[501]; // var input mesin kata

    printf("      #####       ##         #######        #####    \n");
    printf("     ### ###      ##         ###           ### ###   \n");
    printf("    ###   ###     ##         ##   ###     ###   ###  \n");
    printf("   ###     ###    ##    ##   ###    ##   ###     ### \n");
    printf("  ###       ###   ########   ########   ###       ###\n\n");

    printf("Selamat Datang di ALGHA DB\nKetik '/HELP' atau '/H?' Untuk Info lebih Lanjut\nKetik '/EXIT' untuk keluar dari DB\n\n");

    int keluar = 1;

    // jika angka tetap 1 maka akan terus berjalan
    while (keluar == 1)
    {
        printf("ALGHA [DB]> ");
        scanf(" %500[^\n]s", pita); // Memberikan input

        nquery = 0; // membuat pita memulai dari 0 (pita[0])
        // mulai mesin kata
        start(pita);
        strcpy(query[nquery], getcw()); // copy kata saat ini ke query
        nquery++;                       // inkremenkan

        while (eop(pita) == 0) // lakukan looping hingga sama dengan eop
        {
            inc(pita);                      // inkremenkan mesin
            strcpy(query[nquery], getcw()); // copy kata saat ini ke query
            nquery++;                       // inkremenkan
        }

        if (strcmp(pita, "EXIT;") == 0) // jika pita sama dengan "EXIT" sama maka
        {
            printf("Terimakasih telah menggunakan ALGHA [DB]\nDadahhhhh\n"); // print salam perpisahan
            keluar = 0;                                                      // mengubah angkanya menjadi 0 dan keluar dari program
        }
        else if (strcmp(pita, "HELP;") == 0 || strcmp(pita, "H?;") == 0) // jika pita sama dengan "HELP" / "H?" maka
        {
            // print bantuan query
            help(1);
        }
        else
        {
            // bila memasukan query dan di index ke 2 ada kata ini dan panjang nya sesuai                 // bila memasukan query dan di index ke 2 tidak sama dengan ini dan panjang nya sesuai
            if (((strcmp(query[1], "UPDATE") == 0 || strcmp(query[1], "DELETE") == 0)) || ((strcmp(query[1], "UPDATE") != 0 || strcmp(query[1], "DELETE") != 0) && nquery <= 7)) // maka
            {
                // cek index pertama querynya
                if (strcmp(query[0], "INSERT") == 0) // bila insert maka akan
                {
                    insert(); // masuk ke prosedur insert
                }
                else if (strcmp(query[0], "UPDATE") == 0) // bila update maka akan
                {
                    update(); // masuk ke prosedur update
                }
                else if (strcmp(query[0], "DELETE") == 0) // bila delete maka akan
                {
                    dell(); // masuk ke prosedur delete
                }
                else if (strcmp(query[0], "SELECT") == 0) // bila select maka akan
                {
                    select(); // masuk ke prosedur select
                }
                else // bila query yang dimaksud tidak ada maka
                {
                    error(3); // masukan error kode error
                }
            }
            else if ((strcmp(query[0], "INSERT") == 0) || (strcmp(query[0], "UPDATE") == 0) || (strcmp(query[0], "DELETE") == 0) || (strcmp(query[0], "SELECT") == 0) && (strcmp(query[1], "INSERT") == 0) || (strcmp(query[1], "UPDATE") == 0) || (strcmp(query[1], "DELETE") == 0) || (strcmp(query[1], "SELECT") == 0) && (strcmp(query[2], "INSERT") == 0) || (strcmp(query[2], "UPDATE") == 0) || (strcmp(query[2], "DELETE") == 0) || (strcmp(query[2], "SELECT") == 0) && (strcmp(query[3], "INSERT") == 0) || (strcmp(query[3], "UPDATE") == 0) || (strcmp(query[3], "DELETE") == 0) || (strcmp(query[3], "SELECT") == 0) && (nquery > 7))
            {
                error(1);
            }
        }
    }
}

// Prosedur untuk mengscan(fscanf)/ read
void scan()
{
    nhp = 0,       // index tabel hp
        nspek = 0, // index tabel spek
        ncam = 0;  // index tabel cam

    // Baca thp.dat
    fdata = fopen("thp.dat", "r");
    // scan apakah data pertama "####" atau tidak
    fscanf(fdata, "%s %s %s %s", thp[nhp].id, thp[nhp].value1, thp[nhp].value2, thp[nhp].value3);

    while (strcmp(thp[nhp].id, "####") != 0) // bila tidak "####"
    {
        nhp++; // inkremenkan
        // scan semua data
        fscanf(fdata, "%s %s %s %s", thp[nhp].id, thp[nhp].value1, thp[nhp].value2, thp[nhp].value3);
    }
    fclose(fdata); // menutup file

    // Baca tspek.dat
    fdata = fopen("tspek.dat", "r");
    // scan apakah data pertama "####" atau tidak
    fscanf(fdata, "%s %s %s %s", tspek[nspek].id, tspek[nspek].value1, tspek[nspek].value2, tspek[nspek].value3);

    while (strcmp(tspek[nspek].id, "####") != 0) // bila tidak "####"
    {
        nspek++; // inkremenkan
        // scan semua data
        fscanf(fdata, "%s %s %s %s", tspek[nspek].id, tspek[nspek].value1, tspek[nspek].value2, tspek[nspek].value3);
    }
    fclose(fdata); // menutup file

    // Baca tcam.dat
    fdata = fopen("tcam.dat", "r");
    // scan apakah data pertama "####" atau tidak
    fscanf(fdata, "%s %s %s %s", tcam[ncam].id, tcam[ncam].value1, tcam[ncam].value2, tcam[ncam].value3);

    while (strcmp(tcam[ncam].id, "####") != 0) // bila tidak "####"
    {
        ncam++; // inkremenkan
        // scan semua data
        fscanf(fdata, "%s %s %s %s", tcam[ncam].id, tcam[ncam].value1, tcam[ncam].value2, tcam[ncam].value3);
    }
    fclose(fdata); // menutup file
}

// prosedur untuk membaca(fprintf)/ write
void save()
{
    int i; // index tabel

    sort(thp, 0, nhp - 1);     // sort data thp
    sort(tspek, 0, nspek - 1); // sort data tspek
    sort(tcam, 0, ncam - 1);   // sort data tcam

    // Buka file thp.dat
    fdata = fopen("thp.dat", "w");
    for (i = 0; i < nhp; i++) // lakukan looping
    {
        // print semua data ke thp.dat
        fprintf(fdata, "%s %s %s %s\n", thp[i].id, thp[i].value1, thp[i].value2, thp[i].value3);
    }
    fprintf(fdata, "#### #### #### ####\n"); // print penutup
    fclose(fdata);                           // menutup file

    // Buka file tspek.dat
    fdata = fopen("tspek.dat", "w");
    for (i = 0; i < nspek; i++) // lakukan looping
    {
        // print semua data ke tspek.dat
        fprintf(fdata, "%s %s %s %s\n", tspek[i].id, tspek[i].value1, tspek[i].value2, tspek[i].value3);
    }
    fprintf(fdata, "#### #### #### ####\n"); // print penutup
    fclose(fdata);                           // menutup file

    // Buka file tcam.dat
    fdata = fopen("tcam.dat", "w");
    for (i = 0; i < ncam; i++) // lakukan looping
    {
        // print semua data ke tcam.dat
        fprintf(fdata, "%s %s %s %s\n", tcam[i].id, tcam[i].value1, tcam[i].value2, tcam[i].value3);
    }
    fprintf(fdata, "#### #### #### ####\n"); // print penutup
    fclose(fdata);                           // menutup file
}

// prosedur untuk mengurutkan data dengan quick sort agar dapat dicari
void sort(data str[], int l, int r)
{
    char temp[201]; // var simpan
    int i = l,      // var kiri
        j = r;      // var kanan

    // melakukan quick sort
    do
    {
        while (strcmp(str[i].id, str[r].id) < 0 && i <= j)
        {
            i++;
        }
        while (strcmp(str[j].id, str[l].id) > 0 && i <= j)
        {
            j--;
        }
        if (i < j) // copy data
        {
            strcpy(temp, str[i].id);
            strcpy(str[i].id, str[j].id);
            strcpy(str[j].id, temp);

            strcpy(temp, str[i].value1);
            strcpy(str[i].value1, str[j].value1);
            strcpy(str[j].value1, temp);

            strcpy(temp, str[i].value2);
            strcpy(str[i].value2, str[j].value2);
            strcpy(str[j].value2, temp);

            strcpy(temp, str[i].value3);
            strcpy(str[i].value3, str[j].value3);
            strcpy(str[j].value3, temp);

            i++;
            j--;
        }
    } while (i < j);

    if (l < j)
    {
        sort(str, l, j); // rekursif
    }
    if (i < r)
    {
        sort(str, i, r); // rekursif
    }
}

// Prosedur untuk mencari dengan sequential search data dari id
int search(data str[], int n, char search[])
{
    int i = 0,     // index id
        found = 0; // tandai bila menemukan data

    while (i < n && found == 0) // bila data masih 0 dan masih kurang dari n
    {
        if (strcmp(str[i].id, search) == 0) // sudah menemukan id
        {
            found = 1; // ubah found menjadi 1
        }
        else
        {
            i++; // inkremenkan terus bila else
        }
    }
    if (found == 1) // bila found sudah 1 maka
    {
        return i; // kembali ke indexnya
    }
    else
    {
        return 9; // menentukan nilai bila tidak bertemu
    }
}

// Prosedur Query INSERT
void insert()
{
    int index, // var index
        i;     // var untuk looping

    scan();                              // masukan ke prosedur scan untuk membaca file
    if (strcmp(query[1], "UPDATE") == 0) // bila setelah INSERT ada UPDATE
    {
        if (strcmp(query[2], "thp") == 0)
        {
            index = search(thp, nhp, query[3]); // tentukan angka index
            if (index == 9)                     // artinya data tidak ada dan lakukan INSERT
            {
                printf("\n%s Berhasil dan data yg anda masukan adalah :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);
                strcpy(thp[nhp].id, query[3]);
                strcpy(thp[nhp].value1, query[4]);
                strcpy(thp[nhp].value2, query[5]);
                strcpy(thp[nhp].value3, query[6]);
                nhp++;
            }
            else // bila ada update data
            {
                printf("\n%s selesai data berhasil diperbaharui :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);
                strcpy(thp[index].value1, query[4]);
                strcpy(thp[index].value2, query[5]);
                strcpy(thp[index].value3, query[6]);
            }
        }
        else if (strcmp(query[2], "tspek") == 0)
        {
            index = search(tspek, nspek, query[3]);
            if (index == 9)
            {
                printf("\n%s Berhasil dan data yg anda masukan adalah :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);
                strcpy(tspek[nspek].id, query[3]);
                strcpy(tspek[nspek].value1, query[4]);
                strcpy(tspek[nspek].value2, query[5]);
                strcpy(tspek[nspek].value3, query[6]);
                nspek++;
            }
            else
            {
                printf("\n%s selesai data berhasil diperbaharui :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);
                strcpy(tspek[index].value1, query[4]);
                strcpy(tspek[index].value2, query[5]);
                strcpy(tspek[index].value3, query[6]);
            }
        }
        else if (strcmp(query[2], "tcam") == 0)
        {
            index = search(tcam, ncam, query[3]);
            if (index == 9)
            {
                printf("\n%s Berhasil dan data yg anda masukan adalah :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);
                strcpy(tcam[ncam].id, query[3]);
                strcpy(tcam[ncam].value1, query[4]);
                strcpy(tcam[ncam].value2, query[5]);
                strcpy(tcam[ncam].value3, query[6]);
                ncam++;
            }
            else
            {
                printf("\n%s selesai data berhasil diperbaharui :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);
                strcpy(tcam[index].value1, query[4]);
                strcpy(tcam[index].value2, query[5]);
                strcpy(tcam[index].value3, query[6]);
            }
        }
        else
        {
            error(2); // bila tabel tidak ditemukan
        }
    }
    else if (strcmp(query[1], "DELETE") == 0)
    {
        if (strcmp(query[2], "thp") == 0)
        {
            index = search(thp, nhp, query[3]); // tentukan angka index
            if (index == 9)                     // artinya data tidak ada dan lakukan INSERT
            {
                printf("\n%s Berhasil dan data yg anda masukan adalah :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);
                strcpy(thp[nhp].id, query[3]);
                strcpy(thp[nhp].value1, query[4]);
                strcpy(thp[nhp].value2, query[5]);
                strcpy(thp[nhp].value3, query[6]);
                nhp++;
            }
            else // bila bertemu maka lakukan DELETE
            {
                printf("\n%s Berhasil menghapus data :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);

                for (i = index; i < nhp; i++)
                {
                    strcpy(thp[i].id, thp[i + 1].id);
                    strcpy(thp[i].value1, thp[i + 1].value1);
                    strcpy(thp[i].value2, thp[i + 1].value2);
                    strcpy(thp[i].value3, thp[i + 1].value3);
                }
                nhp--;
            }
        }
        else if (strcmp(query[2], "tspek") == 0)
        {
            index = search(tspek, nspek, query[3]);
            if (index == 9)
            {
                printf("\n%s Berhasil dan data yg anda masukan adalah :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);
                strcpy(tspek[nspek].id, query[3]);
                strcpy(tspek[nspek].value1, query[4]);
                strcpy(tspek[nspek].value2, query[5]);
                strcpy(tspek[nspek].value3, query[6]);
                nspek++;
            }
            else
            {
                printf("\n%s Berhasil menghapus data :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);

                for (i = index; i < nspek; i++)
                {
                    strcpy(tspek[i].id, tspek[i + 1].id);
                    strcpy(tspek[i].value1, tspek[i + 1].value1);
                    strcpy(tspek[i].value2, tspek[i + 1].value2);
                    strcpy(tspek[i].value3, tspek[i + 1].value3);
                }
                nspek--;
            }
        }
        else if (strcmp(query[2], "tcam") == 0)
        {
            index = search(tcam, ncam, query[3]);
            if (index == 9)
            {
                printf("\n%s Berhasil dan data yg anda masukan adalah :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);
                strcpy(tcam[ncam].id, query[3]);
                strcpy(tcam[ncam].value1, query[4]);
                strcpy(tcam[ncam].value2, query[5]);
                strcpy(tcam[ncam].value3, query[6]);
                ncam++;
            }
            else
            {
                printf("\n%s Berhasil menghapus data :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);

                for (i = index; i < ncam; i++)
                {
                    strcpy(tcam[i].id, tcam[i + 1].id);
                    strcpy(tcam[i].value1, tcam[i + 1].value1);
                    strcpy(tcam[i].value2, tcam[i + 1].value2);
                    strcpy(tcam[i].value3, tcam[i + 1].value3);
                }
                ncam--;
            }
        }
        else
        {
            error(2);
        }
    }
    else // bila query hanya INSERT maka lakukan perintahnya
    {
        if (strcmp(query[1], "thp") == 0)
        {
            printf("\n%s Berhasil dan data yg anda masukan adalah :\n", query[0]);
            printf("('%s', '%s', '%s', '%s')\n", query[2], query[3], query[4], query[5]);
            strcpy(thp[nhp].id, query[2]);
            strcpy(thp[nhp].value1, query[3]);
            strcpy(thp[nhp].value2, query[4]);
            strcpy(thp[nhp].value3, query[5]);
            nhp++;
        }
        else if (strcmp(query[1], "tspek") == 0)
        {
            printf("\n%s Berhasil dan data yg anda masukan adalah :\n", query[0]);
            printf("('%s', '%s', '%s', '%s')\n", query[2], query[3], query[4], query[5]);
            strcpy(tspek[nspek].id, query[2]);
            strcpy(tspek[nspek].value1, query[3]);
            strcpy(tspek[nspek].value2, query[4]);
            strcpy(tspek[nspek].value3, query[5]);
            nspek++;
        }
        else if (strcmp(query[1], "tcam") == 0)
        {
            printf("\n%s Berhasil dan data yg anda masukan adalah :\n", query[0]);
            printf("('%s', '%s', '%s', '%s')\n", query[2], query[3], query[4], query[5]);
            strcpy(tcam[ncam].id, query[2]);
            strcpy(tcam[ncam].value1, query[3]);
            strcpy(tcam[ncam].value2, query[4]);
            strcpy(tcam[ncam].value3, query[5]);
            ncam++;
        }
        else
        {
            error(2);
        }
    }
    save();
}

// Prosedur untuk UPDATE
void update()
{
    int i,     // var looping
        index; // var index

    scan(); // melakukan ke prosedur scan

    if (strcmp(query[1], "DELETE") == 0) // jika setelah UPDATE terdapat DELETE
    {
        if (strcmp(query[2], "thp") == 0)
        {
            index = search(thp, nhp, query[3]); // tentukan angka index
            if (index == 9)                     // artinya data tidak ada
            {
                error(4); // kode error
            }
            else // bila ditemukan maka lakukan DELETE
            {
                printf("\n%s Data terupdate dan terhapus :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);

                for (i = index; i < nhp; i++)
                {
                    strcpy(thp[i].id, thp[i + 1].id);
                    strcpy(thp[i].value1, thp[i + 1].value1);
                    strcpy(thp[i].value2, thp[i + 1].value2);
                    strcpy(thp[i].value3, thp[i + 1].value3);
                }
                nhp--;
            }
        }
        else if (strcmp(query[2], "tspek") == 0)
        {
            index = search(tspek, nspek, query[3]);
            if (index == 9)
            {
                error(4);
            }
            else
            {
                printf("\n%s Data terupdate dan terhapus :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);

                for (i = index; i < nspek; i++)
                {
                    strcpy(tspek[i].id, tspek[i + 1].id);
                    strcpy(tspek[i].value1, tspek[i + 1].value1);
                    strcpy(tspek[i].value2, tspek[i + 1].value2);
                    strcpy(tspek[i].value3, tspek[i + 1].value3);
                }
                nspek--;
            }
        }
        else if (strcmp(query[2], "tcam") == 0)
        {
            index = search(tcam, ncam, query[3]);
            if (index == 9)
            {
                error(4);
            }
            else
            {
                printf("\n%s Data terupdate dan terhapus :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[3], query[4], query[5], query[6]);

                for (i = index; i < ncam; i++)
                {
                    strcpy(tcam[i].id, tcam[i + 1].id);
                    strcpy(tcam[i].value1, tcam[i + 1].value1);
                    strcpy(tcam[i].value2, tcam[i + 1].value2);
                    strcpy(tcam[i].value3, tcam[i + 1].value3);
                }
                ncam--;
            }
        }
        else
        {
            error(2);
        }
    }
    else // bila query hanya UPDATE
    {
        if (strcmp(query[1], "thp") == 0)
        {
            index = search(thp, nhp, query[2]); // menentukan angka index
            if (index == 9)
            {
                error(4);
            }
            else
            {
                printf("\n%s selesai data berhasil diperbaharui :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[2], query[3], query[4], query[5]);
                strcpy(thp[index].value1, query[3]);
                strcpy(thp[index].value2, query[4]);
                strcpy(thp[index].value3, query[5]);
            }
        }
        else if (strcmp(query[1], "tspek") == 0)
        {
            index = search(tspek, nspek, query[2]);
            if (index == 9)
            {
                error(4);
            }
            else
            {
                printf("\n%s selesai data berhasil diperbaharui :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[2], query[3], query[4], query[5]);
                strcpy(tspek[index].value1, query[3]);
                strcpy(tspek[index].value2, query[4]);
                strcpy(tspek[index].value3, query[5]);
            }
        }
        else if (strcmp(query[1], "tcam") == 0)
        {
            index = search(tcam, ncam, query[2]);
            if (index == 9)
            {
                error(4);
            }
            else
            {
                printf("\n%s selesai data berhasil diperbaharui :\n", query[0]);
                printf("('%s', '%s', '%s', '%s')\n", query[2], query[3], query[4], query[5]);
                strcpy(tcam[index].value1, query[3]);
                strcpy(tcam[index].value2, query[4]);
                strcpy(tcam[index].value3, query[5]);
            }
        }
        else
        {
            error(2);
        }
    }
    save();
}

void dell()
{
    int index,
        i;

    scan();

    if (strcmp(query[1], "thp") == 0)
    {
        index = search(thp, nhp, query[2]);
        if (index == 9)
        {
            error(4);
        }
        else
        {
            printf("\n%s Berhasil menghapus data :\n", query[0]);
            printf("('%s')\n", query[2]);
            for (i = index; i < nhp; i++)
            {
                strcpy(thp[i].id, thp[i + 1].id);
                strcpy(thp[i].value1, thp[i + 1].value1);
                strcpy(thp[i].value2, thp[i + 1].value2);
                strcpy(thp[i].value3, thp[i + 1].value3);
            }
            nhp--;
        }
    }
    else if (strcmp(query[1], "tspek") == 0)
    {
        index = search(tspek, nspek, query[2]);
        if (index == 9)
        {
            error(4);
        }
        else
        {
            printf("\n%s Berhasil menghapus data :\n", query[0]);
            printf("('%s')\n", query[2]);
            for (i = index; i < nspek; i++)
            {
                strcpy(tspek[i].id, tspek[i + 1].id);
                strcpy(tspek[i].value1, tspek[i + 1].value1);
                strcpy(tspek[i].value2, tspek[i + 1].value2);
                strcpy(tspek[i].value3, tspek[i + 1].value3);
            }
            nspek--;
        }
    }
    else if (strcmp(query[1], "tcam") == 0)
    {
        index = search(tcam, ncam, query[2]);
        if (index == 9)
        {
            error(4);
        }
        else
        {
            printf("\n%s Berhasil menghapus data :\n", query[0]);
            printf("('%s')\n", query[2]);
            for (i = index; i < ncam; i++)
            {
                strcpy(tcam[i].id, tcam[i + 1].id);
                strcpy(tcam[i].value1, tcam[i + 1].value1);
                strcpy(tcam[i].value2, tcam[i + 1].value2);
                strcpy(tcam[i].value3, tcam[i + 1].value3);
            }
            ncam--;
        }
    }
    else
    {
        error(2);
    }
    save();
}

void select()
{
    int i, j;
    scan();
    getspace();

    if ((strcmp(query[1], "thp") == 0) && (strcmp(query[2], "tspek") == 0) && (strcmp(query[3], "tcam") == 0) && nquery == 4 ||
        (strcmp(query[1], "thp") == 0) && (strcmp(query[2], "tcam") == 0) && (strcmp(query[3], "tspek") == 0) && nquery == 4)
    {
        int index, indexs;
        char temp[100][100][100];
        for (i = 0; i < nhp; i++)
        {
            strcpy(temp[i][0], thp[i].id);
            strcpy(temp[i][1], thp[i].value1);
            strcpy(temp[i][2], thp[i].value2);
            strcpy(temp[i][3], thp[i].value3);
            index = search(tspek, nspek, temp[i][3]);
            strcpy(temp[i][4], tspek[index].value1);
            strcpy(temp[i][5], tspek[index].value2);
            strcpy(temp[i][6], tspek[index].value3);
            indexs = search(tcam, ncam, temp[i][3]);
            strcpy(temp[i][7], tcam[indexs].value1);
            strcpy(temp[i][8], tcam[indexs].value2);
            strcpy(temp[i][9], tcam[indexs].value3);
        }

        printf("\n+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        printf("| ID");
        for (i = 0; i < lenidh - strlen("ID"); i++)
        {
            printf(" ");
        }
        printf(" | Brand");
        for (i = 0; i < lenhp1 - strlen("Brand"); i++)
        {
            printf(" ");
        }
        printf(" | Seri");
        for (i = 0; i < lenhp2 - strlen("Seri"); i++)
        {
            printf(" ");
        }
        printf(" | Kode Spek");
        for (i = 0; i < lenhp3 - strlen("Kode Spek"); i++)
        {
            printf(" ");
        }
        printf(" | Prosessor");
        for (i = 0; i < lenspek1 - strlen("Prosessor"); i++)
        {
            printf(" ");
        }
        printf(" | GPU");
        for (i = 0; i < lenspek2 - strlen("GPU"); i++)
        {
            printf(" ");
        }
        printf(" | Tanggal Rilis");
        for (i = 0; i < lenspek3 - strlen("Tanggal Rilis"); i++)
        {
            printf(" ");
        }
        printf(" | Kamera Depan");
        for (i = 0; i < lencam1 - strlen("Kamera Depan"); i++)
        {
            printf(" ");
        }
        printf(" | Kamera Belakang");
        for (i = 0; i < lencam2 - strlen("Kamera Belakang"); i++)
        {
            printf(" ");
        }
        printf(" | Memori");
        for (i = 0; i < lencam3 - strlen("Memori"); i++)
        {
            printf(" ");
        }
        printf(" |\n");
        printf("+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        for (i = 0; i < nhp; i++)
        {
            printf("| %s", temp[i][0]);
            for (j = 0; j < lenidh - strlen(temp[i][0]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][1]);
            for (j = 0; j < lenhp1 - strlen(temp[i][1]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][2]);
            for (j = 0; j < lenhp2 - strlen(temp[i][2]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][3]);
            for (j = 0; j < lenhp3 - strlen(temp[i][3]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][4]);
            for (j = 0; j < lenspek1 - strlen(temp[i][4]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][5]);
            for (j = 0; j < lenspek2 - strlen(temp[i][5]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][6]);
            for (j = 0; j < lenspek3 - strlen(temp[i][6]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][7]);
            for (j = 0; j < lencam1 - strlen(temp[i][7]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][8]);
            for (j = 0; j < lencam2 - strlen(temp[i][8]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][9]);
            for (j = 0; j < lencam3 - strlen(temp[i][9]); j++)
            {
                printf(" ");
            }
            printf(" |\n");
        }
        printf("+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam3; i++)
        {
            printf("-");
        }
        printf("-+\n");
    }
    else if ((strcmp(query[1], "thp") == 0) && (strcmp(query[2], "tspek") == 0) && nquery == 3 ||
             (strcmp(query[1], "tspek") == 0) && (strcmp(query[2], "thp") == 0) && nquery == 3)
    {
        int index;
        char temp[100][100][100];
        for (i = 0; i < nhp; i++)
        {
            strcpy(temp[i][0], thp[i].id);
            strcpy(temp[i][1], thp[i].value1);
            strcpy(temp[i][2], thp[i].value2);
            strcpy(temp[i][3], thp[i].value3);
            index = search(tspek, nspek, temp[i][3]);
            strcpy(temp[i][4], tspek[index].value1);
            strcpy(temp[i][5], tspek[index].value2);
            strcpy(temp[i][6], tspek[index].value3);
        }

        printf("\n+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        printf("| ID");
        for (i = 0; i < lenidh - strlen("ID"); i++)
        {
            printf(" ");
        }
        printf(" | Brand");
        for (i = 0; i < lenhp1 - strlen("Brand"); i++)
        {
            printf(" ");
        }
        printf(" | Seri");
        for (i = 0; i < lenhp2 - strlen("Seri"); i++)
        {
            printf(" ");
        }
        printf(" | Kode Spek");
        for (i = 0; i < lenhp3 - strlen("Kode Spek"); i++)
        {
            printf(" ");
        }
        printf(" | Prosessor");
        for (i = 0; i < lenspek1 - strlen("Prosessor"); i++)
        {
            printf(" ");
        }
        printf(" | GPU");
        for (i = 0; i < lenspek2 - strlen("GPU"); i++)
        {
            printf(" ");
        }
        printf(" | Tanggal Rilis");
        for (i = 0; i < lenspek3 - strlen("Tanggal Rilis"); i++)
        {
            printf(" ");
        }
        printf(" |\n");
        printf("+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        for (i = 0; i < nhp; i++)
        {
            printf("| %s", temp[i][0]);
            for (j = 0; j < lenidh - strlen(temp[i][0]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][1]);
            for (j = 0; j < lenhp1 - strlen(temp[i][1]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][2]);
            for (j = 0; j < lenhp2 - strlen(temp[i][2]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][3]);
            for (j = 0; j < lenhp3 - strlen(temp[i][3]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][4]);
            for (j = 0; j < lenspek1 - strlen(temp[i][4]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][5]);
            for (j = 0; j < lenspek2 - strlen(temp[i][5]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][6]);
            for (j = 0; j < lenspek3 - strlen(temp[i][6]); j++)
            {
                printf(" ");
            }
            printf(" |\n");
        }
        printf("+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek3; i++)
        {
            printf("-");
        }
        printf("-+\n");
    }
    else if ((strcmp(query[1], "thp") == 0) && (strcmp(query[2], "tcam") == 0) && nquery == 3 ||
             (strcmp(query[1], "tcam") == 0) && (strcmp(query[2], "thp") == 0) && nquery == 3)
    {
        int index;
        char temp[100][100][100];
        for (i = 0; i < nhp; i++)
        {
            strcpy(temp[i][0], thp[i].id);
            strcpy(temp[i][1], thp[i].value1);
            strcpy(temp[i][2], thp[i].value2);
            strcpy(temp[i][3], thp[i].value3);
            index = search(tcam, ncam, temp[i][3]);
            strcpy(temp[i][4], tcam[index].value1);
            strcpy(temp[i][5], tcam[index].value2);
            strcpy(temp[i][6], tcam[index].value3);
        }

        printf("\n+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        printf("| ID");
        for (i = 0; i < lenidh - strlen("ID"); i++)
        {
            printf(" ");
        }
        printf(" | Brand");
        for (i = 0; i < lenhp1 - strlen("Brand"); i++)
        {
            printf(" ");
        }
        printf(" | Seri");
        for (i = 0; i < lenhp2 - strlen("Seri"); i++)
        {
            printf(" ");
        }
        printf(" | Kode Spek");
        for (i = 0; i < lenhp3 - strlen("Kode Spek"); i++)
        {
            printf(" ");
        }
        printf(" | Kamera Depan");
        for (i = 0; i < lencam1 - strlen("Kamera Depan"); i++)
        {
            printf(" ");
        }
        printf(" | Kamera Belakang");
        for (i = 0; i < lencam2 - strlen("Kamera Belakang"); i++)
        {
            printf(" ");
        }
        printf(" | Memori");
        for (i = 0; i < lencam3 - strlen("Memori"); i++)
        {
            printf(" ");
        }
        printf(" |\n");
        printf("+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        for (i = 0; i < nhp; i++)
        {
            printf("| %s", temp[i][0]);
            for (j = 0; j < lenidh - strlen(temp[i][0]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][1]);
            for (j = 0; j < lenhp1 - strlen(temp[i][1]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][2]);
            for (j = 0; j < lenhp2 - strlen(temp[i][2]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][3]);
            for (j = 0; j < lenhp3 - strlen(temp[i][3]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][4]);
            for (j = 0; j < lencam1 - strlen(temp[i][4]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][5]);
            for (j = 0; j < lencam2 - strlen(temp[i][5]); j++)
            {
                printf(" ");
            }
            printf(" | %s", temp[i][6]);
            for (j = 0; j < lencam3 - strlen(temp[i][6]); j++)
            {
                printf(" ");
            }
            printf(" |\n");
        }
        printf("+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam3; i++)
        {
            printf("-");
        }
        printf("-+\n");
    }
    else if ((strcmp(query[1], "thp") == 0) && nquery == 2)
    {
        printf("\n+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        printf("| ID");
        for (i = 0; i < lenidh - strlen("ID"); i++)
        {
            printf(" ");
        }
        printf(" | Brand");
        for (i = 0; i < lenhp1 - strlen("Brand"); i++)
        {
            printf(" ");
        }
        printf(" | Seri");
        for (i = 0; i < lenhp2 - strlen("Seri"); i++)
        {
            printf(" ");
        }
        printf(" | Kode Spek");
        for (i = 0; i < lenhp3 - strlen("Kode Spek"); i++)
        {
            printf(" ");
        }
        printf(" |\n");
        printf("+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        for (i = 0; i < nhp; i++)
        {
            printf("| %s", thp[i].id);
            for (j = 0; j < lenidh - strlen(thp[i].id); j++)
            {
                printf(" ");
            }
            printf(" | %s", thp[i].value1);
            for (j = 0; j < lenhp1 - strlen(thp[i].value1); j++)
            {
                printf(" ");
            }
            printf(" | %s", thp[i].value2);
            for (j = 0; j < lenhp2 - strlen(thp[i].value2); j++)
            {
                printf(" ");
            }
            printf(" | %s", thp[i].value3);
            for (j = 0; j < lenhp3 - strlen(thp[i].value3); j++)
            {
                printf(" ");
            }
            printf(" |\n");
        }
        printf("+-");
        for (i = 0; i < lenidh; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenhp3; i++)
        {
            printf("-");
        }
        printf("-+\n");
    }
    else if ((strcmp(query[1], "tspek") == 0) && nquery == 2)
    {
        printf("\n+-");
        for (i = 0; i < lenids; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        printf("| Kode Spek");
        for (i = 0; i < lenids - strlen("Kode Spek"); i++)
        {
            printf(" ");
        }
        printf(" | Prosessor");
        for (i = 0; i < lenspek1 - strlen("Prosessor"); i++)
        {
            printf(" ");
        }
        printf(" | GPU");
        for (i = 0; i < lenspek2 - strlen("GPU"); i++)
        {
            printf(" ");
        }
        printf(" | Tanggal Rilis");
        for (i = 0; i < lenspek3 - strlen("Tanggal Rilis"); i++)
        {
            printf(" ");
        }
        printf(" |\n");
        printf("+-");
        for (i = 0; i < lenids; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        for (i = 0; i < nspek; i++)
        {
            printf("| %s", tspek[i].id);
            for (j = 0; j < lenids - strlen(tspek[i].id); j++)
            {
                printf(" ");
            }
            printf(" | %s", tspek[i].value1);
            for (j = 0; j < lenspek1 - strlen(tspek[i].value1); j++)
            {
                printf(" ");
            }
            printf(" | %s", tspek[i].value2);
            for (j = 0; j < lenspek2 - strlen(tspek[i].value2); j++)
            {
                printf(" ");
            }
            printf(" | %s", tspek[i].value3);
            for (j = 0; j < lenspek3 - strlen(tspek[i].value3); j++)
            {
                printf(" ");
            }
            printf(" |\n");
        }
        printf("+-");
        for (i = 0; i < lenids; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lenspek3; i++)
        {
            printf("-");
        }
        printf("-+\n");
    }
    else if ((strcmp(query[1], "tcam") == 0) && nquery == 2)
    {
        printf("\n+-");
        for (i = 0; i < lenidc; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        printf("| Kode Spek");
        for (i = 0; i < lenidc - strlen("Kode Spek"); i++)
        {
            printf(" ");
        }
        printf(" | Prosessor");
        for (i = 0; i < lencam1 - strlen("Prosessor"); i++)
        {
            printf(" ");
        }
        printf(" | GPU");
        for (i = 0; i < lencam2 - strlen("GPU"); i++)
        {
            printf(" ");
        }
        printf(" | Memori");
        for (i = 0; i < lencam3 - strlen("Memori"); i++)
        {
            printf(" ");
        }
        printf(" |\n");
        printf("+-");
        for (i = 0; i < lenidc; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam3; i++)
        {
            printf("-");
        }
        printf("-+\n");
        for (i = 0; i < ncam; i++)
        {
            printf("| %s", tcam[i].id);
            for (j = 0; j < lenidc - strlen(tcam[i].id); j++)
            {
                printf(" ");
            }
            printf(" | %s", tcam[i].value1);
            for (j = 0; j < lencam1 - strlen(tcam[i].value1); j++)
            {
                printf(" ");
            }
            printf(" | %s", tcam[i].value2);
            for (j = 0; j < lencam2 - strlen(tcam[i].value2); j++)
            {
                printf(" ");
            }
            printf(" | %s", tcam[i].value3);
            for (j = 0; j < lencam3 - strlen(tcam[i].value3); j++)
            {
                printf(" ");
            }
            printf(" |\n");
        }
        printf("+-");
        for (i = 0; i < lenidc; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam1; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam2; i++)
        {
            printf("-");
        }
        printf("-+-");
        for (i = 0; i < lencam3; i++)
        {
            printf("-");
        }
        printf("-+\n");
    }
    else if ((strcmp(query[1], "thp") != 0) && ((strcmp(query[2], "tspek") != 0) || (strcmp(query[2], "tcam"))) && nquery == 3)
    {
        error(2);
    }
    else if ((strcmp(query[1], "thp") != 0) && (strcmp(query[1], "tspek") != 0) && nquery == 2)
    {
        error(2);
    }
    else if ((strcmp(query[1], "thp") != 0) && (strcmp(query[1], "tcam") != 0) && nquery == 2)
    {
        error(2);
    }
    else
    {
        error(5);
    }
}

void getspace()
{
    int i;

    lenidh = 0, lenhp1 = 0, lenhp2 = 0, lenhp3 = 0;
    for (i = 0; i < nhp; i++)
    {
        if (strlen(thp[i].id) > lenidh)
        {
            lenidh = strlen(thp[i].id);
            if (strlen("ID") > lenidh)
            {
                lenidh = strlen("ID");
            }
        }

        if (strlen(thp[i].value1) > lenhp1)
        {
            lenhp1 = strlen(thp[i].value1);
            if (strlen("Brand") > lenhp1)
            {
                lenhp1 = strlen("Brand");
            }
        }

        if (strlen(thp[i].value2) > lenhp2)
        {
            lenhp2 = strlen(thp[i].value2);
            if (strlen("Seri") > lenhp2)
            {
                lenhp2 = strlen("Seri");
            }
        }

        if (strlen(thp[i].value3) > lenhp3)
        {
            lenhp3 = strlen(thp[i].value3);
            if (strlen("Kode Spek") > lenhp3)
            {
                lenhp3 = strlen("Kode Spek");
            }
        }
    }

    lenids = 0, lenspek1 = 0, lenspek2 = 0, lenspek3 = 0;
    for (i = 0; i < nspek; i++)
    {

        if (strlen(tspek[i].id) > lenids)
        {
            lenids = strlen(tspek[i].id);
            if (strlen("Kode Spek") > lenids)
            {
                lenids = strlen("Kode Spek");
            }
        }

        if (strlen(tspek[i].value1) > lenspek1)
        {
            lenspek1 = strlen(tspek[i].value1);
            if (strlen("Prosessor") > lenspek1)
            {
                lenspek1 = strlen("Prosessor");
            }
        }

        if (strlen(tspek[i].value2) > lenspek2)
        {
            lenspek2 = strlen(tspek[i].value2);
            if (strlen("GPU") > lenspek2)
            {
                lenspek2 = strlen("GPU");
            }
        }

        if (strlen(tspek[i].value3) > lenspek3)
        {
            lenspek3 = strlen(tspek[i].value3);
            if (strlen("Tanggal Rilis") > lenspek3)
            {
                lenspek3 = strlen("Tanggal Rilis");
            }
        }
    }

    lenidc = 0, lencam1 = 0, lencam2 = 0, lencam3 = 0;
    for (i = 0; i < ncam; i++)
    {

        if (strlen(tcam[i].id) > lenidc)
        {
            lenidc = strlen(tcam[i].id);
            if (strlen("Kode Spek") > lenidc)
            {
                lenidc = strlen("Kode Spek");
            }
        }

        if (strlen(tcam[i].value1) > lencam1)
        {
            lencam1 = strlen(tcam[i].value1);
            if (strlen("Kamera Depan") > lencam1)
            {
                lencam1 = strlen("Kamera Depan");
            }
        }

        if (strlen(tcam[i].value2) > lencam2)
        {
            lencam2 = strlen(tcam[i].value2);
            if (strlen("Kamera Belakang") > lencam2)
            {
                lencam2 = strlen("Kamera Belakang");
            }
        }

        if (strlen(tcam[i].value3) > lencam3)
        {
            lencam3 = strlen(tcam[i].value3);
            if (strlen("Memori") > lencam3)
            {
                lencam3 = strlen("Memori");
            }
        }
    }
}

void help(int help)
{
    switch (help)
    {
    case 1:
        printf("\n- INSERT (UPDATE/DELETE) tabel key input1 input2 input3\n- UPDATE (DELETE) tabel key input1 input2 input3\n- DELETE tabel key\n- SELECT tabel1 (tabel2 / tabel2 tabel3)\n\n");
        break;
    case 2:
        printf("\n Table yg tersedia :\n- thp\n- tspek\n- tcam\n\n");
        break;
    case 3:
        printf("\nKetik 'SELECT (nama tabel)' untuk melihat idnya\n\n");
        break;
    }
}

void error(int error)
{
    switch (error)
    {
    case 1:
        printf("Error : pilih query apa yg ingin anda masukan INSERT, UPDATE, DELETE, SELECT atau query anda kurang sesuai\n");
        help(1);
        break;
    case 2:
        if ((strcmp(query[1], "UPDATE") == 0) || (strcmp(query[1], "DELETE") == 0))
        {
            printf("'%s' Error : '%s' tabel ini tidak ada.\n", query[3], query[3]);
            help(2);
        }
        else
        {
            printf("'%s' Error : '%s' tabel ini tidak ada.\n", query[2], query[2]);
            help(2);
        }
        break;
    case 3:
        printf("'%s' Error : Query ini tidak ada bisa ketik 'HELP'/'H?' untuk cek query yg ada.\n\n", query[0]);
        break;
    case 4:
        if ((strcmp(query[1], "UPDATE") == 0) || (strcmp(query[1], "DELETE") == 0))
        {
            printf("Error : Id('%s') tidak ditemukan.\n", query[3]);
            help(3);
        }
        else
        {
            printf("Error : Id('%s') tidak ditemukan.\n", query[2]);
            help(3);
        }
        break;
    case 5:
        printf("Error : Query join salah silahkan cek kembali.\n");
        help(2);
        break;
    }
}