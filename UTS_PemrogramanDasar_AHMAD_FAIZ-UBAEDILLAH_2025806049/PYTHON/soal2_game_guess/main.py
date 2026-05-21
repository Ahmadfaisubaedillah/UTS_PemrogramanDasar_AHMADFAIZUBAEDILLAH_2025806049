from game import play_game
from scoreboard import (
    save_score,
    show_top_scores
)

print("=== GAME GUESS BATTLE ===")

name = input("Masukkan nama: ")

print("\nPilih level")
print("1. Easy")
print("2. Medium")
print("3. Hard")

level = int(input("Level: "))

score = play_game(level)

print(f"\nScore akhir: {score}")

save_score(name, score)

show_top_scores()