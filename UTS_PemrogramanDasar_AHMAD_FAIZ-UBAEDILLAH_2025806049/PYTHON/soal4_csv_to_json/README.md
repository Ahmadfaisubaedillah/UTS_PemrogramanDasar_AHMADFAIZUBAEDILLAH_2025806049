### 📌 Soal 4 — Konversi Data CSV ke JSON (C + Python)
**Konsep:** integrasi lintas bahasa, file format, manipulasi string

Menggunakan output CSV dari program C (Soal 1) sebagai input, lalu program Python membaca CSV tersebut, menampilkan data dalam tabel rapi, menghitung rata-rata nilai akhir, dan mengonversi ke format JSON.

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
Nama                 NIM           Nilai Akhir   Mutu
-------------------------------------------------------
jajang               1314                69.00      C
bahlil               1415                61.00      C

Rata-rata Nilai Akhir: 65.00
Data disimpan ke data_mahasiswa.jsonn
```

---