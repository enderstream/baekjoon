import sys, heapq

input = lambda: sys.stdin.readline().strip()
sys.stdin = open("./input.txt", "r")


def solution(ST: list) -> int:
    classroom = []
    heapq.heapify(ST)
    heapq.heappush(classroom, heapq.heappop(ST)[1])
    while ST:
        next_class = heapq.heappop(ST)
        if classroom[0] <= next_class[0]:  # 빈 강의실이 있음
            heapq.heappop(classroom)
        heapq.heappush(classroom, next_class[1])

    return len(classroom)


if __name__ == "__main__":
    N = int(input())
    ST = [tuple(map(int, input().split())) for _ in range(N)]
    print(f"{solution(ST)}")
