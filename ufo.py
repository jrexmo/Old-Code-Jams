import math

def gground(x, n):
    if x == 0:
        return 0
    else:
        return round(x, n)
#for now, c3 stays fixed
def get_centers(A):
    c1 = (.5, 0, 0)
    c2 = (0, .5, 0)
    c3 = (0, 0, .5)
    theta = math.asin(1/A)
    c1 = (gground((.5)*math.cos(theta), 20), gground((-.5)*math.sin(theta), 20), 0)
    c2 = (gground((-.5)*math.sin(theta), 20), gground((-.5)*math.cos(theta), 20), 0)

    print(c1[0],  ' ', c1[1], ' ', c1[2])
    print(c2[0],  ' ', c2[1], ' ', c2[2])
    print(c3[0],  ' ', c3[1], ' ', c3[2])
    return([c1, c2, c3])




t = int(input())
list_ans = t*[0]

for i in range(1, t + 1):
  A = float(input())
  #nums = [int(s) for s in input().split(" ")]

  list_ans[i - 1] = A


for i in range(1, t + 1):
    print("Case #{}:".format(i))
    get_centers(list_ans[i - 1])
