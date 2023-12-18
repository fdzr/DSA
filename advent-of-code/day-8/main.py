from collections import namedtuple
import math


coord = namedtuple("coord", ["left", "right"])
data = open("input.txt").read().split("\n")
directions = data[2:]
information = data[0]
cont = 0
instructions = {}
starts = []

for direction in directions:
    addr = direction.split("=")[1].strip().split(",")
    left  = addr[0][1:].strip()
    right = addr[1].strip()[:-1].strip()
    beg = direction.split("=")[0].strip()
    instructions[beg] = coord(left, right)
    if beg.endswith("A"):
        starts.append(beg)

node = "AAA"
pos = 0
while node != "ZZZ":
    if information[pos] == "L":
        node = instructions[node].left
    else:
        node = instructions[node].right

    pos = (pos + 1) % len(information)
    cont += 1

print(cont)

number_steps = []
for start in starts:
    node = start
    pos = 0
    cont = 0
    while node.endswith("Z") is False:
        if information[pos] == "L":
            node = instructions[node].left
        else:
            node = instructions[node].right

        pos = (pos + 1) % len(information)
        cont += 1

    number_steps.append(cont)

print(math.lcm(*number_steps))