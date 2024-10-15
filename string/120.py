def removeDigit(number: str, digit: str) -> str:
    ans = ""

    for index, ch in enumerate(number):
        if ch == digit:
            ans = max(ans, number[:index] + number[index + 1 :])

    return ans


print(removeDigit("887685", "8"))
