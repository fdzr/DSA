class CustomStack:
    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.stack = []

    def push(self, x: int) -> None:
        if len(self.stack) < self.maxSize:
            self.stack.append(x)

    def pop(self) -> int:
        x = -1
        if self.stack:
            x = self.stack.pop()

        return x

    def increment(self, k: int, val: int) -> None:
        for i in range(0, min(len(self.stack), k)):
            self.stack[i] += val


if __name__ == "__main__":
    c = CustomStack(3)
    c.push(1)
    c.push(2)
    c.push(3)
    c.increment(5, 10)
    print(c.stack)
