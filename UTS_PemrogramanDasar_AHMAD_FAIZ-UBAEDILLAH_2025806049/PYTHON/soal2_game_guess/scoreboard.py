import json
import os

FILE = "scores.json"

def save_score(name, score):

    data = []

    if os.path.exists(FILE):

        with open(FILE, "r") as file:

            try:
                data = json.load(file)
            except:
                data = []

    data.append({
        "name": name,
        "score": score
    })

    data = sorted(
        data,
        key=lambda x: x["score"],
        reverse=True
    )

    with open(FILE, "w") as file:

        json.dump(data, file, indent=4)

def show_top_scores():

    print("\n=== TOP 5 SCORE ===")

    if not os.path.exists(FILE):
        return

    with open(FILE, "r") as file:

        data = json.load(file)

    for item in data[:5]:

        print(
            f"{item['name']} - {item['score']}"
        )