import re

RED = 12
GREEN = 13
BLUE = 14


def get_number(string):
    pattern = r"\d+"
    return int(re.search(pattern, string)[0])


def get_color(string):
    return re.search(r"(red|green|blue)", string)[0]


def parse_line(line: str):
    game, data = line.split(":")
    samples = []

    for chunk in data.split(";"):
        colors = {"blue": 0, "green": 0, "red": 0}
        for part in chunk.split(","):
            colors[get_color(part)] += get_number(part)

        samples.append(colors)

    return get_number(game), samples


def is_valid_game(samples: list[dict]):
    for sample in samples:
        if sample["green"] > GREEN or sample["red"] > RED or sample["blue"] > BLUE:
            return False
    return True


def part1(lines: list[str]):
    cont = 0

    for line in lines:
        id, samples = parse_line(line)
        if is_valid_game(samples) is True:
            cont += id

    return cont


def get_power(samples: list[dict]):
    max_red = 0
    max_green = 0
    max_blue = 0

    for sample in samples:
        max_blue = max(max_blue, sample["blue"])
        max_green = max(max_green, sample["green"])
        max_red = max(max_red, sample["red"])

    return max_green * max_red * max_blue


def part2(lines: list[str]):
    cont = 0

    for line in lines:
        _, samples = parse_line(line)
        cont += get_power(samples)

    return cont


if __name__ == "__main__":
    with open("input.txt", "r") as f_in:
        print(part2(f_in.readlines()))