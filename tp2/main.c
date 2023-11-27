#include "header.h"

int main()
{
    scanf("%i %i", &n, &m); // scan ukuran matrix

    data awal[n][m];    // matrix buat drawing awal
    data tim[n][m];     // matrix buat drawing akhir

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%s %i %i", tim[i][j].nama, &tim[i][j].atk, &tim[i][j].def);  
            awal[i][j] = tim[i][j];                                             // salin matrix tim ke matrix awal
        }
    }

    char kiri[30], kanan[30];   // nama tim yang bakal dituker
    data *tim_kiri, *tim_kanan; // pointer tim yang bakal dituker

    do
    {
        scanf("%s", kiri);
        if (strcmp(kiri, "stop") == 0) break;
        scanf("%s", kanan);
        tim_kiri = cari_tim(kiri, tim);
        tim_kanan = cari_tim(kanan, tim);
        if (rata2((*tim_kiri).atk, (*tim_kiri).def) > rata2((*tim_kanan).atk, (*tim_kanan).def)) tukar_tim(tim_kiri, tim_kanan);
    }
    while (0 == 0);

    printf("Drawing Awal:\n");
    print_drawing(awal);

    printf("\nDrawing Akhir:\n");
    print_drawing(tim);

    return 0;
}