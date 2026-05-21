import csv, json

CSV_FILE  = "data_mahasiswa.csv"
JSON_FILE = "data_mahasiswa.json"

mahasiswa_list = []
total_na = 0

with open(CSV_FILE, newline="", encoding="utf-8") as f:
    reader = csv.DictReader(f)
    for row in reader:
        obj = {
            "nama":        row["Nama"],
            "nim":         row["NIM"],
            "nilai_akhir": float(row["NilaiAkhir"]),
            "mutu":        row["Mutu"],
        }
        mahasiswa_list.append(obj)
        total_na += obj["nilai_akhir"]

rata_rata = total_na / len(mahasiswa_list) if mahasiswa_list else 0

print(f"{'Nama':<20} {'NIM':<12} {'Nilai Akhir':>12} {'Mutu':>6}")
print("-" * 55)
for m in mahasiswa_list:
    print(f"{m['nama']:<20} {m['nim']:<12} {m['nilai_akhir']:>12.2f} {m['mutu']:>6}")

print(f"\nRata-rata Nilai Akhir: {rata_rata:.2f}")

with open(JSON_FILE, "w") as f:
    json.dump(mahasiswa_list, f, indent=2)
print(f"Data disimpan ke {JSON_FILE}")