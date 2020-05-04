def quick_trouble(ints):
    list1 = []
    list2 = []
    for i in range(len(ints)):
        if i%2 ==0:
            list1.append(ints[i])
        else:
            list2.append(ints[i])
    list1 = sorted(list1)
    list2 = sorted(list2)
    a = []
    first_current = 0
    second_current = 0
    for i in range(len(ints)):
        if i%2 == 0:
            a.append(list1[first_current])
            first_current += 1
        else:
            a.append(list2[second_current])
            second_current += 1
    return(a)




def is_sorted(ints):
    trouble = quick_trouble(ints)
    good = sorted(ints)
    n = len(ints)
    for i in range(n):
        if good[i] != trouble[i]:
            return(i)
    return "OK"


t = int(input())
list_ans = t*[0]

for i in range(1, t + 1):
  n = input()
  nums = [int(s) for s in input().split(" ")]

  list_ans[i - 1] = is_sorted(nums)


for i in range(1, t + 1):
    print("Case #{}: {}".format(i, list_ans[i - 1]))
