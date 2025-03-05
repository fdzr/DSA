def check_duplicate_parentheses(cad: str):
    stack = []

    for ch in cad:
        if len(stack) > 0 and ch == ")" and stack[-1] == ")":
            return True
        else:
            stack.append(ch)

    return False


if __name__ == "__main__":
    cads = ["((x+y))+z", "(x+y)", "((x+y)+((z)))"]

    for cad in cads:
        print(check_duplicate_parentheses(cad))
