from typing import List


def divideString(s: str, k: int, fill: str) -> List[str]:
    index = 0
    ans = []
    while index < len(s):
        cad = s[index: index + k]
        if len(cad) < k:
            cad = cad + abs(len(cad) - k) * fill
            
        ans.append(cad)
        index += k

    return ans


if __name__ == "__main__":
    print(divideString("ctoyjrwtngqwt", 8, "n"))
