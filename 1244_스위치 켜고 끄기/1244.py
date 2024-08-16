import sys

sys.stdin = open("input.txt")
"""
switch_cnt : 스위치 개수
switches : 스위치 번호가 1번부터 주어지므로, 인덱스와 번호를 일치시키기 위해 더미 스위치를 맨 앞에 추가한 뒤, extend사용
student_cnt : 학생 숫자
학생 전부를 따로 저장할 필요 없음 : 학생의 성별과 번호를 입력받을 때마다 스위치의 상태를 바꾸면 되므로 굳이 리스트 사용 안해도 됨 + 메모리 절약
스위치는 0 또는 1이므로, 상태를 바꾸려면 1에서 빼면 됨
남학생의 경우 : 자기 번호부터 시작해서 마지막 번호까지 자기 번호만큼 건너뛰면서 스위치를 바꿈
여학생의 경우 : 자기 번호 스위치는 바꿔놓고 시작, 인덱싱 검사하면서 스위치의 대칭이 깨질 때 까지 스위치를 바꿈
"""


def solution():
    switch_cnt = int(input().strip())
    switches = [-1]  #
    switches.extend(list(map(int, input().strip().split())))
    student_cnt = int(input().strip())
    for _ in range(student_cnt):
        gender, switch_num = map(int, input().strip().split())
        if gender == 1:  # male
            for i in range(switch_num, switch_cnt + 1, switch_num):
                switches[i] = 1 - switches[i]
        else:  # gender == 2: # female
            i = switch_num - 1
            j = switch_num + 1
            switches[switch_num] = 1 - switches[switch_num] # 자기 자리는 항상 바꿈
            while 1 <= i <= switch_cnt and 1 <= j <= switch_cnt:
                if switches[i] == switches[j]:
                    switches[i] = 1 - switches[i]
                    switches[j] = 1 - switches[j]
                    i -= 1
                    j += 1
                else:
                    break

    for i in range(1, switch_cnt + 1):
        print(switches[i], end=" ")
        if not (i % 20):  # i 가 20의 배수가 되면 줄바꿈
            print()


if __name__ == "__main__":
    solution()
