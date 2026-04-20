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


cont_2part = 0
start = 50
cont = 0

with open("input.txt", "r") as f_in:
    for dial in f_in.read().split():
        if dial[0] == "R":
            cont_2part = int(dial[1:]) // 100
            start = start + (int(dial[1:]) % 100)

            if start > 100:
                cont += cont_2part + 1

            start %= 100
            if start == 0:
                cont += 1

        else:
            reminder = 100 - start
            if int(dial[1:]) - reminder > 0:
                cont += 1
                new_dial = int(dial[1:]) - reminder
                cont_2part = new_dial // 100
                cont += cont_2part
                start = 100 - (new_dial % 100)
            else:
                start = (start - int(dial[1:]) + 100) % 100
                if start == 0:
                    cont += 1

    print(cont)
