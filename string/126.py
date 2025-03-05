def check_balanced_expression(cad: str):
    stack = []

    for ch in cad:
        if len(stack) > 0 and stack[-1] == "[" and ch == "]":
            stack.pop()
            continue
        if len(stack) > 0 and stack[-1] == "(" and ch == ")":
            stack.pop()
            continue
        if len(stack) > 0 and stack[-1] == "{" and ch == "}":
            stack.pop()
            continue

        stack.append(ch)

    return len(stack) == 0


cad = "{[{}{}]}[()]"
print(check_balanced_expression(cad))
cad = "{()}[)"
print(check_balanced_expression(cad))
