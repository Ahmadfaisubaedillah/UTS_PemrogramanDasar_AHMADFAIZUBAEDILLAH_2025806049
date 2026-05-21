# 🎓 UTS Pemrograman Dasar — "Data, Game, dan Analisis Otomatis"

## 👤 Identitas Mahasiswa

| Keterangan | Detail |
|---|---|
| **Nama** | Ahmad Faiz Ubaedillah |
| **NIM** |2025806049|
| **Mata Kuliah** | Pemrograman Dasar |
| **Dosen** | Rintis Mardika Sunarto |
| **Program Studi / Semester** | Teknik Informatika / 2 Pagi |
| **Tahun Akademik** | 2025/2026 |

---

## 📁 Struktur Repository

```
UTS_PemrogramanDasar_AhmadFaizUbaedillah/
│
├── C/
│   ├── soal1_data_mahasiswa/
│   │   ├── main.c
│   │   ├── linked_list.c
│   │   ├── linked_list.h
│   │   └── data_mahasiswa.csv        ← output program
│   └── soal4_csv_json/
│       ├── convert_csv_json.c
│       └── data_mahasiswa.json       ← output konversi
│
├── Python/
│   ├── soal2_game_guess/
│   │   ├── main.py
│   │   ├── game.py
│   │   ├── scoreboard.py
│   │   └── scores.json               ← output skor pemain
│   ├── soal3_text_analyzer/
│   │   ├── main.py
│   │   ├── analyzer.py
│   │   ├── utils.py
│   │   ├── input.txt                 ← file teks input
│   │   └── report.txt                ← output laporan
│   └── soal4_csv_to_json/
│       ├── convert.py
│       ├── data_mahasiswa.csv
│       └── data_mahasiswa.json
│
├── docs/
│   ├── screenshot_soal1.png
│   ├── screenshot_soal2.png
│   ├── screenshot_soal3.png
│   ├── screenshot_soal4.png
│   └── laporan_uts.pdf
│
└── README.md
```

---

## 📝 Penjelasan Singkat Tiap Program

### 📌 Soal 1 — Sistem Data Mahasiswa (C)
**Konsep:** struct, pointer, dynamic memory, linked list, file I/O

Program manajemen data mahasiswa menggunakan **linked list dinamis**. Setiap node menyimpan nama, NIM, nilai tugas, UTS, dan UAS. Program menghitung nilai akhir secara otomatis dengan rumus:

```
Nilai Akhir = (30% × Tugas) + (30% × UTS) + (40% × UAS)
```

Huruf mutu ditentukan berdasarkan nilai akhir:
- A → ≥ 85
- B → 70–84
- C → 55–69
- D → 40–54
- E → < 40

Fitur: tambah, tampilkan, cari, hapus mahasiswa berdasarkan NIM, dan simpan ke CSV.

---

### 📌 Soal 2 — Game Guess Battle (Python)
**Konsep:** loop, conditional, modularisasi, JSON, colorama

Game tebak angka berbasis CLI dengan 3 level kesulitan:

| Level | Rentang | Percobaan |
|-------|---------|-----------|
| 1 | 1 – 10 | 3x |
| 2 | 1 – 50 | 5x |
| 3 | 1 – 100 | 7x |

Skor dihitung dari sisa percobaan × 10 + level × 20. Hasil skor disimpan ke `scores.json` dan menampilkan TOP 5 pemain terbaik. Menggunakan **colorama** untuk efek warna terminal.

---

### 📌 Soal 3 — Analisis Teks Otomatis (Python)
**Konsep:** file I/O, string, dictionary, Counter, grafik ASCII

Program membaca file `input.txt` dan menghasilkan laporan statistik lengkap:
- Jumlah baris dan kata
- Jumlah huruf vokal dan konsonan
- 5 kata yang paling sering muncul
- Grafik frekuensi kata dalam format ASCII

Hasil laporan disimpan ke `report.txt`.

---

### 📌 Soal 4 — Konversi Data CSV ke JSON (C + Python)
**Konsep:** integrasi lintas bahasa, file format, manipulasi string

Menggunakan output CSV dari program C (Soal 1) sebagai input, lalu program Python membaca CSV tersebut, menampilkan data dalam tabel rapi, menghitung rata-rata nilai akhir, dan mengonversi ke format JSON.

---

## ⚙️ Persiapan & Instalasi

### Kebutuhan Sistem
- GCC (MinGW untuk Windows)
- Python 3.x
- Git

### Install Library Python
```bash
pip install colorama
```

### Cek Instalasi
```bash
gcc --version
python --version
git --version
```

---

## 🚀 Instruksi Menjalankan Program

### ▶️ Soal 1 — Sistem Data Mahasiswa (C)

```bash
# 1. Masuk ke folder
cd C/soal1_data_mahasiswa

# 2. Compile
gcc main.c linked_list.c -o program

# 3. Jalankan
# Windows:
.\program.exe
# Linux/macOS:
./program
```

**Menu program:**
```
=== SISTEM DATA MAHASISWA ===
1. Tambah Mahasiswa
2. Tampilkan Semua
3. Cari Mahasiswa
4. Hapus Mahasiswa
5. Simpan ke CSV
0. Keluar
```

> Pilih **5** untuk menghasilkan file `data_mahasiswa.csv` sebelum menjalankan Soal 4.

---

### ▶️ Soal 2 — Game Guess Battle (Python)

```bash
# 1. Masuk ke folder
cd Python/soal2_game_guess

# 2. Jalankan
python main.py
```

**Alur permainan:**
```
=== WELCOME TO GUESS BATTLE ===
Masukkan nama pemain: Ahmad
=== Level 1 | Tebak 1-10 | 3 percobaan ===
Tebakan kamu: 5
Terlalu kecil! Sisa: 2
Tebakan kamu: 8
Benar! +40 poin
...
=== TOP 5 SCORE ===
1. Ahmad – 120 pts
```

---

### ▶️ Soal 3 — Analisis Teks Otomatis (Python)

```bash
# 1. Masuk ke folder
cd Python/soal3_text_analyzer

# 2. Jalankan
python main.py
```

**Contoh output:**
```
=== LAPORAN ANALISIS TEKS ===
Jumlah Baris  : 15
Jumlah Kata   : 120
Huruf Vokal   : 380
Huruf Konsonan: 290

--- Top 5 Kata Terbanyak ---
pemrograman     #################### (8)
python          ################ (6)
belajar         ############ (5)
data            ######## (3)
bahasa          ###### (2)
```

---

### ▶️ Soal 4 — Konversi CSV ke JSON (Python)

```bash
# 1. Pastikan data_mahasiswa.csv sudah ada (dari Soal 1)
# Salin CSV ke folder soal4:
# Windows:
Copy-Item C\soal1_data_mahasiswa\data_mahasiswa.csv Python\soal4_csv_to_json\

# 2. Masuk ke folder
cd Python/soal4_csv_to_json

# 3. Jalankan
python convert.py
```

**Contoh output:**
```
Nama                 NIM          Nilai Akhir   Mutu
-------------------- ------------ ------------ ------
Rina                 2310001             85.50      A
Doni                 2310002             61.50      C

Rata-rata Nilai Akhir: 73.50
Data disimpan ke data_mahasiswa.json
```

---

## 📊 Contoh Output File

### `data_mahasiswa.csv` (Output Soal 1)
```
Nama,NIM,Tugas,UTS,UAS,NilaiAkhir,Mutu
Rina,2310001,80,85,90,85.50,A
Doni,2310002,60,55,70,61.50,C
Ahmad,2310003,75,80,85,80.50,B
```

### `data_mahasiswa.json` (Output Soal 4)
```json
[
  {"nama": "Rina", "nim": "2310001", "nilai_akhir": 85.5, "mutu": "A"},
  {"nama": "Doni", "nim": "2310002", "nilai_akhir": 61.5, "mutu": "C"},
  {"nama": "Ahmad", "nim": "2310003", "nilai_akhir": 80.5, "mutu": "B"}
]
```

### `scores.json` (Output Soal 2)
```json
{
  "Rina": 230,
  "Budi": 200,
  "Ahmad": 170
}
```

---

## 🔁 Riwayat Commit

```
feat: init struktur repository UTS
feat: tambah modul struct mahasiswa dan linked list (Soal 1)
fix: perbaiki perhitungan nilai akhir di linked_list.c
update: hasil file output CSV dari program C
feat: tambah game tebak angka multi-level dengan skor JSON (Soal 2)
feat: tambah analisis teks otomatis dengan grafik ASCII (Soal 3)
feat: konversi data CSV ke JSON dari output C (Soal 4)
docs: tambah README, screenshot output, dan laporan UTS
```

---

## 📸 Screenshot Output

Tersimpan di folder `/docs/`:

| File | Isi |
|------|-----|
| `screenshot_soal1.png` | Output program C manajemen mahasiswa |
| `screenshot_soal2.png` | Tampilan game guess battle dan TOP 5 |
| `screenshot_soal3.png` | Laporan analisis teks dan grafik ASCII |
| `screenshot_soal4.png` | Tabel konversi CSV ke JSON |

---

## 🏫 Universitas Insan Pembangunan Indonesia
**Fakultas Ilmu Komputer** — Jl. Raya Serang KM. 10 Pos Bitung, Tangerang
