def canBeTypedWords(text: str, brokenLetters: str) -> int:
    list_of_words = text.split()
    answer = 0
    flag = False
    for word in list_of_words:
        for ch in brokenLetters:
            if ch in word:
                flag = True

        if flag is False:
            answer += 1
        else:
            flag = False

    return answer


if __name__ == "__main__":
    print(canBeTypedWords("leet code", "e"))
