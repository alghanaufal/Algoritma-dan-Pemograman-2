#include "header.h"

// fungsi untuk mencari string di dalam matrix, terus return pointer dari data yang cocok
data* cari_tim(char str[], data tim[][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // fungsi cuma bisa return 1 kali, jadi kalo namanya cocok fungsi langsung berhenti
            if (strcmp(str, tim[i][j].nama) == 0) return &tim[i][j];
        }
    }
    return NULL;
}

float rata2(int a, int b)
{
    return ((float)a + (float)b) / 2;
}

void tukar_tim(data *a, data *b)
{
    // tukernya pake dereferencing pointer
    data temp = *a;
    *a = *b;
    *b = temp;
}

void print_drawing(data tim[][m])
{
    int spasi, longest[m];  // local variables buat ngerapihin output

    // pertama cari dulu jumlah char string terpanjang di setiap kolom
    for (int j = 0; j < m; j++)
    {
        longest[j] = 0;
        for (int i = 0; i < n; i++)
        {
            if (strlen(tim[i][j].nama) > longest[j]) longest[j] = strlen(tim[i][j].nama);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // print nama, print spasi atau new line tergantung nilai j
            printf("%s", tim[i][j].nama);
            if (j < m - 1)
            {
                spasi = longest[j] - strlen(tim[i][j].nama) + 2;
                for (int k = 0; k < spasi; k++) printf(" ");
            }
            else printf("\n");
        }
    }
}