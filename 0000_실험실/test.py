# def solution(i):
#     nums = list(map(int, input().split(" ")))
#     ans = sum(nums[i] for i in range(0, len(nums)) if nums[i] % 2 != 0)
#     print(f"#{i} {ans}")

# if __name__ == "__main__":
#     T = int(input())
#     for i in range(T):
#         solution(i+1)


input_str = input()
map_input = map(int, input_str.split())
print(map_input)
print(list(map_input))
