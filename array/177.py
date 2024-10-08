def numberOfChild(n: int, k: int) -> int:
    no_child = 0
    sec = 0
    forward, backward = True, False

    while sec < k:
        sec += 1

        if forward is True:
            no_child += 1
            if no_child == n - 1:
                forward = False
                backward = True

        elif backward is True:
            no_child -= 1
            if no_child == 0:
                forward = True
                backward = False

    return no_child


print(numberOfChild(28, 49))
