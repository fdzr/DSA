import io


def sortVowels(s: str) -> str:
    vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
    vowels_from_input = []
    ans = io.StringIO()

    for ch in s:
        if ch in vowels:
            vowels_from_input.append(ch)

    if len(vowels_from_input) == 0:
        return s

    vowels_from_input.sort()

    index = 0
    for idx, ch in enumerate(s):
        if ch in vowels:
            ans.write(vowels_from_input[index])
            index += 1
        else:
            ans.write(ch)

    return ans.getvalue()


s = "lYmpH"
print(sortVowels(s))
