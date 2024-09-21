from typing import List


def evalRPN(tokens: List[str]) -> int:
    stack = []
    operators = ["/", "*", "+", "-"]

    for token in tokens:
        if token in operators:
            operand2 = stack.pop()
            operand1 = stack.pop()

            if token == "+":
                stack.append(operand1 + operand2)
            elif token == "-":
                stack.append(operand1 - operand2)
            elif token == "*":
                stack.append(operand1 * operand2)
            elif token == "/":
                stack.append(int(operand1 / operand2))
        else:
            stack.append(int(token))

    return stack[0]


print(evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))
