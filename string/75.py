def generateTheString(n: int) -> str:
    if n % 2:
        return 's' * n
    else:
        if (n // 2) % 2:
            return f"{'s' * (n // 2)}{'p' * (n // 2)}"
        else:
            return f"{'s' * ((n // 2) -1)}{'p' * ((n // 2) + 1)}"


if __name__ == "__main__":
    print(generateTheString(12))
