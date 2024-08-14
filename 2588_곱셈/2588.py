if __name__ == "__main__":
    a = int(input())
    b = input()
    nums = []
    for i in range(3):
        nums.append(a * int(b[i]))
    nums.append(a * int(b))

    for i in range(4):
        print(nums[2 - i])
