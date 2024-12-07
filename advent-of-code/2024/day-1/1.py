from collections import Counter


def read_data():
    nums1, nums2 = [], []

    with open("input.txt", "r") as f_in:
        for line in f_in:
            a, b = map(int, line.split())
            nums1.append(a)
            nums2.append(b)

    return nums1, nums2


def min_diff():
    a, b = read_data()
    a.sort()
    b.sort()

    diff = list(map(lambda x: abs(x[0] - x[1]), zip(a, b)))
    return sum(diff)


def get_similarity_score():
    a, b = read_data()
    simiarity_score = 0

    freq_b = Counter(b)

    for val in a:
        simiarity_score += val * freq_b[val]

    return simiarity_score


print(min_diff())
print(get_similarity_score())
