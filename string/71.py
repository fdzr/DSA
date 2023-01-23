def largestOddNumber(num: str) -> str:
    ind = -1
    for index in range(len(num) - 1, -1, -1):
        if int(num[index]) % 2:
            ind = index
            break
    
    return num[:ind + 1]


if __name__ == "__main__":
    print(largestOddNumber("35472"))