from collections import Counter

def analyze_text(text):

    lines = text.splitlines()

    words = text.lower().split()

    vowels = "aiueo"

    vowel_count = 0
    consonant_count = 0

    for char in text.lower():

        if char.isalpha():

            if char in vowels:
                vowel_count += 1
            else:
                consonant_count += 1

    word_counter = Counter(words)

    top_words = word_counter.most_common(5)

    return {
        "lines": len(lines),
        "words": len(words),
        "vowels": vowel_count,
        "consonants": consonant_count,
        "top_words": top_words
    }