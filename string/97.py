def decodeString(s: str) -> str:
    stack = []
    pattern = ""
    open = 0
    for ch in s:
        if ch == "[":
            open += 1
            stack.append(ch)
        elif ch == "]":
            open -= 1
            current_character = stack.pop()
            pattern = pattern + current_character
            while current_character != "[":
                current_character = stack.pop()
                if current_character != "[":
                    pattern = current_character + pattern

            current_character = stack.pop()
            number = ""

            while current_character.isdigit():
                number = current_character + number
                if len(stack) == 0:
                    break
                if stack[len(stack) - 1].isdigit() is False:
                    break
                current_character = stack.pop()

            cad = pattern * int(number)
            pattern = ""
            stack.append(cad)
        else:
            stack.append(ch)

    answer = ""
    answer = stack.pop()
    while len(stack) > 0:
        answer = stack.pop() + answer

    return answer


if __name__ == "__main__":
    print(decodeString("2[a2[b]3[r]]"))
