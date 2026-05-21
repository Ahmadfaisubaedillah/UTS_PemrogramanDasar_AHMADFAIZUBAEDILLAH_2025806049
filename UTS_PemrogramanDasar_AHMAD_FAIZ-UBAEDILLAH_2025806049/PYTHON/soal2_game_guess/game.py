import random

def play_game(level):

    if level == 1:
        max_num = 10
        attempts = 3

    elif level == 2:
        max_num = 50
        attempts = 5

    else:
        max_num = 100
        attempts = 7

    secret = random.randint(1, max_num)

    print(f"\nTebak angka 1 - {max_num}")

    for i in range(attempts):

        guess = int(input("Masukkan tebakan: "))

        if guess == secret:

            print("Benar!")

            score = (
                (attempts - i) * 10
                + level * 20
            )

            return score

        elif guess < secret:

            print("Terlalu kecil!")

        else:

            print("Terlalu besar!")

    print(f"Game Over! Jawaban: {secret}")

    return 0