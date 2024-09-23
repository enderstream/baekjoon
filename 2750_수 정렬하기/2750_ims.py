import sys
input = lambda: sys.stdin.readline().strip()

def iterative_merge_sort(lst: list):
    ir = 1  # 2 4 8 16 ...
    while ir < len(lst):
        ir *= 2
        for idx in range(0, len(lst), ir):
            lst_i, lst_j = lst[idx : idx + ir // 2], lst[idx + ir // 2 : idx + ir]
            i, j, k = 0, 0, idx
            while i < len(lst_i) and j < len(lst_j):
                if lst_i[i] < lst_j[j]:
                    lst[k] = lst_i[i]
                    i += 1
                else:
                    lst[k] = lst_j[j]
                    j += 1
                k += 1

            # 남은 요소 처리
            while i < len(lst_i):
                lst[k] = lst_i[i]
                i += 1
                k += 1

            while j < len(lst_j):
                lst[k] = lst_j[j]
                j += 1
                k += 1
                    


if __name__ == "__main__":
    N = int(input())
    lst = [int(input()) for _ in range(N)]
    iterative_merge_sort(lst)
    for l in lst:
        print(l)
