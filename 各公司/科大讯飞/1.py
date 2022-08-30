import math
PI = 3.1415927
def HanWin(n, N):
    return 0.5 * (1 - math.cos(2 * math.pi * n / N))

n = input()
n = int(n)

list1  = []
list1 = input().split()
list2 = []
for i in range(n):
    list2.append(int(list1[i]))

for i in range(n):
    value = HanWin(i, n) * list2[i]
    print("{} ".format(round(value)), end="")