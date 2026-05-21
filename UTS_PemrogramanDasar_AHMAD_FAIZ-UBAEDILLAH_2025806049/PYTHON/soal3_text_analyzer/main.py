from analyzer import analyze_text
from utils import ascii_chart

with open("input.txt", "r") as file:

    text = file.read()

result = analyze_text(text)

report = f"""
=== LAPORAN ANALISIS ===

Jumlah Baris : {result['lines']}
Jumlah Kata : {result['words']}
Huruf Vokal : {result['vowels']}
Huruf Konsonan : {result['consonants']}
"""

report += ascii_chart(result["top_words"])

print(report)

with open("report.txt", "w") as file:

    file.write(report)