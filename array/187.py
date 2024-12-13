from typing import List


def leastInterval(tasks: List[str], n: int) -> int:
    freq = [0] * 26
    max_freq = 0
    max_numbers_with_most_frequency = 0

    for t in tasks:
        freq[ord(t) - 65] += 1

        if max_freq < freq[ord(t) - 65]:
            max_freq = freq[ord(t) - 65]
            max_numbers_with_most_frequency = 1

        elif max_freq == freq[ord(t) - 65]:
            max_numbers_with_most_frequency += 1

    parts = max_freq - 1
    cant_blocks = parts * (n - max_numbers_with_most_frequency + 1)
    availableTasks = len(tasks) - max_numbers_with_most_frequency * max_freq
    idles = max(0, cant_blocks - availableTasks)

    return len(tasks) + idles


tasks = ["A", "C", "A", "B", "D", "B"]
n = 1
print(leastInterval(tasks, n))
