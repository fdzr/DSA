import math
from dataclasses import dataclass


@dataclass
class Range:
    source: int
    destination: int
    size: int


def parse_line():
    maps = {
        "seed-to-soil": [],
        "soil-to-fertilizer": [],
        "fertilizer-to-water": [],
        "water-to-light": [],
        "light-to-temperature": [],
        "temperature-to-humidity": [],
        "humidity-to-location": [],
    }
    flow = [mapping for mapping in maps.keys()]
    conversion = None

    with open("input.txt", "r") as f_in:
        for line in f_in.readlines():
            if line == "\n":
                continue
            if "seeds:" in line:
                seeds = [*map(int, line.split(":")[1].strip().split())]
                continue
            if "map:" in line:
                line = line.strip()
                conversion = line.split(" ")[0]
            else:
                destination, source, size = map(int, line.split())
                maps[conversion].append(
                    Range(source=source, destination=destination, size=size)
                )

    return seeds, maps, flow


def findLowestLocation():
    seeds, maps, directions = parse_line()
    transformation = None
    location = math.inf
    
    for seed in seeds:
        transformation = seed

        for to in directions:
            for conversion in maps[to]:
                if conversion.source <= transformation <= conversion.source + conversion.size - 1:
                    transformation = conversion.destination + (transformation - conversion.source)
                    break

        location = min(location, transformation)

    return location


if __name__ == "__main__":
    print(findLowestLocation())
