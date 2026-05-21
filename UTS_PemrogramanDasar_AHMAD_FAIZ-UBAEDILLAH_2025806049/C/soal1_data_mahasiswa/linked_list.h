#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Mahasiswa {
    char nama[50];
    char nim[20];
    float tugas, uts, uas;
    float nilai_akhir;
    char mutu;
    struct Mahasiswa* next;
} Mahasiswa;

Mahasiswa* buat_node(char* nama, char* nim, float tugas, float uts, float uas);
void tambah(Mahasiswa** head, char* nama, char* nim, float tugas, float uts, float uas);
void tampilkan(Mahasiswa* head);
Mahasiswa* cari(Mahasiswa* head, char* nim);
void hapus(Mahasiswa** head, char* nim);
void simpan_csv(Mahasiswa* head, char* filename);
void bebaskan(Mahasiswa** head);

#endif