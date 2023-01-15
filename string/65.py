def minimum(num):
    cad = str(num)
    cad = sorted(cad)

    sum = int(cad[0] + cad[2]) + int(cad[1] + cad[3])

    return sum


if __name__ == "__main__":
    print(minimum("1536"))
