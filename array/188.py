import heapq


class Item:
    def __init__(self, value, index_of_list, index):
        self.value = value
        self.index_of_list = index_of_list
        self.index = index

    def __lt__(self, other):
        return self.value < other.value


def merge_k_sorted_lists(lists):
    answer = []
    heap = []

    for index, row in enumerate(range(len(lists))):
        heapq.heappush(
            heap,
            Item(
                lists[row][0],
                index,
                0,
            ),
        )

    while heap:
        item = heapq.heappop(heap)

        if item.index < len(lists[item.index_of_list]):
            if item.index + 1 < len(lists[item.index_of_list]):
                heapq.heappush(
                    heap,
                    Item(
                        value=lists[item.index_of_list][item.index + 1],
                        index_of_list=item.index_of_list,
                        index=item.index + 1,
                    ),
                )

            answer.append(item.value)

    return answer


lists = [
    [10, 20, 30, 40],
    [15, 25, 35, 45],
    [27, 29, 37, 48],
    [32, 33, 39, 50],
    [16, 18, 22, 28],
]

print(merge_k_sorted_lists(lists))
