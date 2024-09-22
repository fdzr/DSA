def rle(cad: str):
    encoding = []
    candidate = cad[0]
    count = 1

    for index in range(1, len(cad)):
        if cad[index] == candidate:
            count += 1
        else:
            encoding.append(f"{count}{candidate}")
            count = 1
            candidate = cad[index]

    encoding.append(f"{count}{candidate}")

    return "".join(encoding)


def countAndSay(n: int) -> str:
    query = [""] * 30
    query[0] = "1"

    for index in range(1, 30):
        query[index] = rle(query[index - 1])

    return query[n - 1]


print(countAndSay(4))
