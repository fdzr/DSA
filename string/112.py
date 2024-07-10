def applyBackspace(s: str):
    stack = []

    for ch in s:
        if ch.isalpha():
            stack.append(ch)
        elif ch == "#" and len(stack) > 0:
            stack.pop()

    return "".join(stack)


def backspaceCompare(s: str, t: str) -> bool:
    return applyBackspace(s) == applyBackspace(t)


print(backspaceCompare("a#c", "b"))
