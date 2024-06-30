from typing import List


def countSeniors(details: List[str]) -> int:
    cont = 0
    for information in details:
        if int(information[11:13]) > 60:
            cont += 1

    return cont


print(countSeniors(["1313579440F2036", "2921522980M5644"]))
