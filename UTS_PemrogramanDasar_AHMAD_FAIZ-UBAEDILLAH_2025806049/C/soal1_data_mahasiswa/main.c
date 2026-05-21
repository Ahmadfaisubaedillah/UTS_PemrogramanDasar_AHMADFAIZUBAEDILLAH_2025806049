#include <stdio.h>
#include <string.h>
#include "linked_list.h"

int main() {
    Mahasiswa* head = NULL;
    int pilihan;

    do {
        printf("\n=== SISTEM DATA MAHASISWA ===\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampilkan Semua\n");
        printf("3. Cari Mahasiswa\n");
        printf("4. Hapus Mahasiswa\n");
        printf("5. Simpan ke CSV\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            char nama[50], nim[20];
            float tugas, uts, uas;
            printf("Nama : "); scanf("%s", nama);
            printf("NIM  : "); scanf("%s", nim);
            printf("Tugas: "); scanf("%f", &tugas);
            printf("UTS  : "); scanf("%f", &uts);
            printf("UAS  : "); scanf("%f", &uas);
            tambah(&head, nama, nim, tugas, uts, uas);
            printf("Data ditambahkan!\n");

        } else if (pilihan == 2) {
            tampilkan(head);

        } else if (pilihan == 3) {
            char nim[20];
            printf("NIM yang dicari: "); scanf("%s", nim);
            Mahasiswa* m = cari(head, nim);
            if (m) printf("Ditemukan: %s | NA: %.2f | Mutu: %c\n",
                          m->nama, m->nilai_akhir, m->mutu);
            else printf("Tidak ditemukan.\n");

        } else if (pilihan == 4) {
            char nim[20];
            printf("NIM yang dihapus: "); scanf("%s", nim);
            hapus(&head, nim);

        } else if (pilihan == 5) {
            simpan_csv(head, "data_mahasiswa.csv");
        }

    } while (pilihan != 0);

    bebaskan(&head);
    return 0;
}