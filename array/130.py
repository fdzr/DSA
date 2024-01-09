from queue import PriorityQueue


class SeatManager:
    def __init__(self, n: int):
        self.pq = PriorityQueue()
        for item in range(1, n + 1):
            self.pq.put(item)

    def reserve(self) -> int:
        minSeat = self.pq.get()
        return minSeat

    def unreserve(self, seatNumber: int) -> None:
        self.pq.put(seatNumber)
