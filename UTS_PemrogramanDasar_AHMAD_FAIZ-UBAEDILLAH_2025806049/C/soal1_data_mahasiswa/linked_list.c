#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

char hitung_mutu(float na) {
    if (na >= 85) return 'A';
    else if (na >= 70) return 'B';
    else if (na >= 55) return 'C';
    else if (na >= 40) return 'D';
    else return 'E';
}

Mahasiswa* buat_node(char* nama, char* nim, float tugas, float uts, float uas) {
    Mahasiswa* baru = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(baru->nama, nama);
    strcpy(baru->nim, nim);
    baru->tugas = tugas;
    baru->uts   = uts;
    baru->uas   = uas;
    baru->nilai_akhir = (0.30f * tugas) + (0.30f * uts) + (0.40f * uas);
    baru->mutu  = hitung_mutu(baru->nilai_akhir);
    baru->next  = NULL;
    return baru;
}

void tambah(Mahasiswa** head, char* nama, char* nim, float tugas, float uts, float uas) {
    Mahasiswa* baru = buat_node(nama, nim, tugas, uts, uas);
    if (*head == NULL) {
        *head = baru;
    } else {
        Mahasiswa* curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = baru;
    }
}

void tampilkan(Mahasiswa* head) {
    printf("\n%-20s %-12s %6s %6s %6s %10s %5s\n",
           "Nama", "NIM", "Tugas", "UTS", "UAS", "NilaiAkhir", "Mutu");
    printf("%-20s %-12s %6s %6s %6s %10s %5s\n",
           "--------------------", "------------",
           "------", "------", "------", "----------", "-----");
    Mahasiswa* curr = head;
    while (curr) {
        printf("%-20s %-12s %6.1f %6.1f %6.1f %10.2f %5c\n",
               curr->nama, curr->nim,
               curr->tugas, curr->uts, curr->uas,
               curr->nilai_akhir, curr->mutu);
        curr = curr->next;
    }
}

Mahasiswa* cari(Mahasiswa* head, char* nim) {
    Mahasiswa* curr = head;
    while (curr) {
        if (strcmp(curr->nim, nim) == 0) return curr;
        curr = curr->next;
    }
    return NULL;
}

void hapus(Mahasiswa** head, char* nim) {
    if (*head == NULL) return;
    if (strcmp((*head)->nim, nim) == 0) {
        Mahasiswa* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Data NIM %s berhasil dihapus.\n", nim);
        return;
    }
    Mahasiswa* curr = *head;
    while (curr->next) {
        if (strcmp(curr->next->nim, nim) == 0) {
            Mahasiswa* temp = curr->next;
            curr->next = temp->next;
            free(temp);
            printf("Data NIM %s berhasil dihapus.\n", nim);
            return;
        }
        curr = curr->next;
    }
    printf("NIM %s tidak ditemukan.\n", nim);
}

void simpan_csv(Mahasiswa* head, char* filename) {
    FILE* f = fopen(filename, "w");
    if (!f) { printf("Gagal membuka file!\n"); return; }
    fprintf(f, "Nama,NIM,Tugas,UTS,UAS,NilaiAkhir,Mutu\n");
    Mahasiswa* curr = head;
    while (curr) {
        fprintf(f, "%s,%s,%.1f,%.1f,%.1f,%.2f,%c\n",
                curr->nama, curr->nim,
                curr->tugas, curr->uts, curr->uas,
                curr->nilai_akhir, curr->mutu);
        curr = curr->next;
    }
    fclose(f);
    printf("Data disimpan ke %s\n", filename);
}

void bebaskan(Mahasiswa** head) {
    Mahasiswa* curr = *head;
    while (curr) {
        Mahasiswa* temp = curr;
        curr = curr->next;
        free(temp);
    }
    *head = NULL;
}