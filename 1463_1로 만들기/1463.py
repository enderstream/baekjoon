import sys

input = sys.stdin.readline
N = 0
N = int(input())
nums = [0] * (N + 1)

for i in range(2, N + 1):
    nums[i] = nums[int(i - 1)] + 1
    if i % 2 == 0:
        nums[i] = min(nums[i], nums[int(i / 2)] + 1)
    if i % 3 == 0:
        nums[i] = min(nums[i], nums[int(i / 3)] + 1)
print(nums[N])
