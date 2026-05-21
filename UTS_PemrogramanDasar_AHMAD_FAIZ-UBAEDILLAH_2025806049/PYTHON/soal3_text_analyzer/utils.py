def ascii_chart(top_words):

    chart = "\n--- Top 5 Kata ---\n"

    for word, count in top_words:

        chart += (
            f"{word:15} "
            + "#" * count
            + f" ({count})\n"
        )

    return chart