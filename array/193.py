from typing import List


class Item:
    def __init__(self, freq, value, index):
        self.freq = freq
        self.value = value
        self.index = index

    def __lt__(self, other):
        if other.freq == self.freq:
            return self.index <= other.index

        return self.freq > other.freq

    def __repr__(self):
        return f"value: {self.value}, freq: {self.freq}, index: {self.index}"


def sort_elements_by_frequency_indexe(nums: List):
    freq = {}
    answer = []

    for index, item in enumerate(nums):
        if not item in freq:
            freq[item] = [1, index]
        else:
            freq[item] = [freq[item][0] + 1, freq[item][1]]

    for key in freq.keys():
        answer.append(Item(freq=freq[key][0], value=key, index=freq[key][1]))

    answer.sort()

    final_answer = [item.value for item in answer for f in range(item.freq)]
    return final_answer


nums = [3, 3, 1, 1, 1, 8, 3, 6, 8, 7, 8]
print(sort_elements_by_frequency_indexe(nums))
