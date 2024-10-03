import re


def numDifferentIntegers(word: str) -> int:
    res = set()
    for number in re.findall(r"\d+", word):
        res.add(int(number))

    return len(res)


print(numDifferentIntegers("1212121212121212121212121212"))
