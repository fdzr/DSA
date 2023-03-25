from typing import List


def fizzBuzz(n: int) -> List[str]:
    ans = [0] * n
    for elem in range(n + 1):
        if elem % 3 == 0 and elem % 5 == 0:
            ans[elem - 1] = "FizzBuzz"
        elif elem % 3 == 0:
            ans[elem - 1] = "Fizz"
        elif elem % 5 == 0:
            ans[elem - 1] = "Buzz"
        else:
            ans[elem - 1] = str(elem)

    return ans


if __name__ == '__main__':
    print(fizzBuzz(1))
