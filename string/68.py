

def isSumEqual(firstWord: str, secondWord: str, targetWord: str) -> bool:
    fw = [str(ord(ch) - 97) for ch in firstWord]
    sw = [str(ord(ch) - 97) for ch in secondWord]
    tw = [str(ord(ch) - 97) for ch in targetWord]

    if int("".join(fw)) + int("".join(sw)) == int("".join(tw)):
        return True

    return False


if __name__ == "__main__":
    first_word = "jjjjjjjj"
    second_word = "jjjjjjjj"
    target_word = "jjjjjjjj"
    print(isSumEqual(first_word, second_word, target_word))
