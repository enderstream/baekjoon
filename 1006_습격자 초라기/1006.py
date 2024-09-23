import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().strip()
sys.stdin = open("./input.txt", "r")


def solution(N: int, W: int, enemies: list) -> int:
    if N == 1:
        return 1
    elif N == 2:
        ...
    else:
        adjacent = defaultdict(tuple)
        
        return 0


if __name__ == "__main__":
    T = int(input())
    for testcase in range(T):
        N, W = map(int, input().split())
        enemies = [list(map(int, input().split())) for _ in range(2)]
        print(solution(N, W, enemies))
