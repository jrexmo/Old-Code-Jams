def is_possible(P, D):
    min_damage = 0
    for letter in P:
        if letter == 'S':
            min_damage += 1
    if min_damage <= D:
        return True
    else:
        return False

def score(P):
    p_list = [i for i in P]
    current_damage = 0
    current_power = 1
    for letter in p_list:
        if letter == 'S':
            current_damage += current_power
        else:
            current_power = 2*current_power
    return(current_damage)

#6 SCCSSC
def hacking(P, D):
    strlist = [i for i in P]
    n = len(P)
    num = 0
    index = n - 1
    current = P
    while(score(current) > D and index > 0):
        strlist = [i for i in current]

        if((strlist[index] == 'S') and (strlist[index - 1] == 'C')):
            strlist[index] = 'C'
            strlist[index - 1] = 'S'
            empty = ''
            for i in range(n):
                empty += strlist[i]
            current = empty
            #print(current)
            index = n - 1
            num += 1
        else:
            index = index - 1

    return num


t = int(input())  # read a line with a single integer
list_ans = t*[0]

for i in range(1, t + 1):
  D, P = [str(s) for s in input().split(" ")]  # read a list of integers, 2 in this case
  D = int(D)
  if is_possible(P, D) == True:
      output = hacking(P, D)
  else:
      output = "IMPOSSIBLE"
  list_ans[i - 1] = output


for i in range(1, t + 1):
    print("Case #{}: {}".format(i, list_ans[i - 1]))
