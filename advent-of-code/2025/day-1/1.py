start = 50
cont = 0

with open("input.txt", "r") as f_in:
    for dial in f_in.read().split():
        if dial[0] == "R":
            start = (start + int(dial[1:])) % 100
        else:
            start = (start - int(dial[1:]) + 100) % 100

        if start == 0:
            cont += 1


print(cont)
