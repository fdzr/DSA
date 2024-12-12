import heapq
from collections import Counter


def reorganizeString(s: str) -> str:
    c = Counter(s)
    heap = []
    ans = []

    for item in c.items():
        heapq.heappush(heap, [-item[1], item[0]])

    while len(heap) >= 2:
        first_element = heapq.heappop(heap)
        second_element = heapq.heappop(heap)

        ans.append(first_element[1])
        ans.append(second_element[1])

        if first_element[0] + 1 != 0:
            heapq.heappush(heap, [first_element[0] + 1, first_element[1]])
        if second_element[0] + 1:
            heapq.heappush(heap, [second_element[0] + 1, second_element[1]])

    aux = None

    if len(heap) > 0:
        aux = heapq.heappop(heap)

        if abs(aux[0]) > 1:
            return ""
        else:
            ans.append(aux[1])

    return "".join(ans)


print(reorganizeString("aaaaaaabbbbb"))
