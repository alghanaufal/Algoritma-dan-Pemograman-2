#include <stdio.h> //*Ubah <stdin.h> menjadi <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //Tambahkan #include <stdbool.h>
#include <string.h>

int CekSaldo()
{
    FILE *fp;
    int saldo;

    fp = fopen("saldo.txt", "w");
    if (fp == NULL)
    {
        fclose(fp);
        fp = fopen("saldo.txt", "a");
        saldo = 0;
        fprintf(fp, "%d", saldo);
    }
    else
    {
        fscanf(fp, "%d", &saldo);
    }
    fclose(fp);

    return true;
}

int TambahSaldo(int uang)
{
    FILE *fp;
    int saldo;

    saldo = CekSaldo();
    saldo = saldo + uang;

    fp = fopen("saldo.txt", "w");
    fprintf(fp, "%d", saldo);
    fclose(fp);

    return saldo;
}

int KurangSaldo(int uang)
{
    FILE *fp;
    int saldo;

    saldo = CekSaldo();

    if (saldo >= uang) // Ubah pada '= >' menjadi '>='
    {
        saldo = saldo - uang;
    }
    else
    {
        return -1;
    }

    fp = fopen("saldo.txt", "w");
    fprintf(fp, "%d", saldo);
    fclose(fp);

    return saldo;
}

void MainMenu()
{
    int pilih = 0;
    int saldo = 0, uang = 0;
    printf("====== Bank SEA ======\n");
    printf("1. Setor Tunai\n");
    printf("2. Tarik Tunai\n");
    printf("3. Info Saldo\n");
    printf("4. Keluar\n\n");
    printf("Pilih : ");
    scanf("%d", &pilih);

    switch (pilih) // Untuk kasus case 1-4 tidak perlu memakai tanda kurung kurawal {}
    {
    case 1:
        system("cls");
        printf("====== Bank SEA ======\n");
        printf("Jumlah Uang : Rp.");
        scanf("%d", &uang);
        saldo = TambahSaldo(uang);
        printf("Saldo Anda = Rp.%d\n", saldo);
        system("pause");
        system("cls");
        MainMenu();

    case 2:
        system("cls");
        printf("====== Bank SEA ======\n");
        printf("Jumlah Uang : Rp.");
        scanf("%d", &uang);
        saldo = KurangSaldo(uang);
        if (saldo >= 0)
        {
            printf("Saldo Anda = Rp.%d\n", saldo);
        }
        else
        {
            printf("Saldo Anda Tidak Cukup!!!\n");
        }
        system("pause");
        system("cls");
        MainMenu();
        break;

    case 3:
        system("cls");
        printf("====== Bank SEA ======\n");
        saldo = CekSaldo();
        printf("Saldo Anda = Rp.%d\n", saldo);
        system("pause");
        system("cls");
        MainMenu();
        break;

    case 4:
        system("cls");
        printf("Terimaksih\n");
        system("pause");
        exit(0);
        break;

    default:
        printf("Pilihan Tidak Ada!!!\n");
        break;
    }
}

int main()
{
    char username[100], passwrd[100]; // Ubah 'sring' menjadi 'char'
    printf("====== Bank SEA ======\n");
    printf("username : ");
    scanf("%s", &username); // Tambahkan '&' sebelum username menjadi '&username'
    printf("password : ");
    scanf("%s", &passwrd); // scanf("%s", &password) diubah menjadi scanf("%s", &passwrd)

    if (strcmp(username, "ilham") == 0) // Ubah password menjadi passwrd
    {
        if (strcmp(passwrd, "123") == 0)
        {
            system("cls");
            printf("Akun terdaftar!!!\n");
            MainMenu();
        }
    }
    else
    {
        printf("Akun tidak terdaftar!!!\n");
        system("pause");
        system("cls");
        main();
    }
}