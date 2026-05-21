#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nama[50];
    char nim[20];
    float nilai_akhir;
    char mutu;
} Mahasiswa;

int baca_csv(char* filename, Mahasiswa data[]) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Error: File %s tidak ditemukan!\n", filename);
        return 0;
    }

    char baris[200];
    int jumlah = 0;

    // Skip header
    fgets(baris, sizeof(baris), f);

    while (fgets(baris, sizeof(baris), f)) {
        char tugas[10], uts[10], uas[10], na[10], mutu[5];

        sscanf(baris, "%49[^,],%19[^,],%9[^,],%9[^,],%9[^,],%9[^,],%c",
               data[jumlah].nama,
               data[jumlah].nim,
               tugas, uts, uas, na, &data[jumlah].mutu);

        data[jumlah].nilai_akhir = atof(na);
        jumlah++;
    }

    fclose(f);
    return jumlah;
}

void tulis_json(char* filename, Mahasiswa data[], int jumlah) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        printf("Error: Gagal membuat file JSON!\n");
        return;
    }

    fprintf(f, "[\n");
    for (int i = 0; i < jumlah; i++) {
        fprintf(f, "  {\n");
        fprintf(f, "    \"nama\": \"%s\",\n", data[i].nama);
        fprintf(f, "    \"nim\": \"%s\",\n", data[i].nim);
        fprintf(f, "    \"nilai_akhir\": %.2f,\n", data[i].nilai_akhir);
        fprintf(f, "    \"mutu\": \"%c\"\n", data[i].mutu);

        if (i < jumlah - 1)
            fprintf(f, "  },\n");
        else
            fprintf(f, "  }\n");
    }
    fprintf(f, "]\n");

    fclose(f);
    printf("Berhasil disimpan ke %s\n", filename);
}

void tampilkan_tabel(Mahasiswa data[], int jumlah) {
    float total = 0;
    printf("\n%-20s %-12s %12s %6s\n", "Nama", "NIM", "Nilai Akhir", "Mutu");
    printf("%-20s %-12s %12s %6s\n",
           "--------------------", "------------",
           "------------", "------");

    for (int i = 0; i < jumlah; i++) {
        printf("%-20s %-12s %12.2f %6c\n",
               data[i].nama, data[i].nim,
               data[i].nilai_akhir, data[i].mutu);
        total += data[i].nilai_akhir;
    }

    printf("\nRata-rata Nilai Akhir: %.2f\n", total / jumlah);
}

int main() {
    Mahasiswa data[MAX];

    char csv_file[100] = "data_mahasiswa.csv";
    char json_file[100] = "data_mahasiswa.json";

    printf("=== KONVERSI CSV KE JSON ===\n");

    int jumlah = baca_csv(csv_file, data);

    if (jumlah == 0) {
        printf("Tidak ada data yang dibaca.\n");
        return 1;
    }

    printf("Berhasil membaca %d data dari %s\n", jumlah, csv_file);

    tampilkan_tabel(data, jumlah);
    tulis_json(json_file, data, jumlah);

    return 0;
}