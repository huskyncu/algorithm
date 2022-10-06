f = []
def ff(n):
    #print("n=", n)
    #print("before if f[n]=", f[n])
    if f[n] == n:
        #print("equal n", n)
        return n
    else:
        #print("f[n]=", f[n])
        f[n] = ff(f[n])
        #print("f[n]=", f[n])
        return f[n]
c = int(input())
ii = 0
for i in range(c):
    sum = 0
    es = []
    cors = []
    f = []
    tmp = [[0 for i in range(3)]]
    p = int(input())
    edge = int(p*(p-1)/2)
    for j in range(edge):
        es += [[0 for i in range(3)]]
    for j in range(p):
        cors += [[0 for i in range(2)]]
    j = 0
    for j in range(p):
        x, y = list(map(int, input().split()))
        cors[j][0] = x
        cors[j][1] = y
        f.append(j)
    j = 0
    num = 0
    for j in range(p):
        for k in range(j+1, p):
            es[num][0] = j
            es[num][1] = k
            es[num][2] = abs(cors[j][0]-cors[k][0])+abs(cors[j][1]-cors[k][1])
            num += 1
    #for i in range(edge):
        #print(es[i][0], es[i][1], es[i][2])
    '''for i in range(edge):
        min = i
        for j in range(i+1, edge):
            if es[j][2] < es[min][2]:
                min=j
        tmp = es[i]
        es[i] = es[min]
        es[min] = tmp'''
    es.sort(key= lambda x : x[2])
    #for i in range(edge):
       # print(es[i][0], es[i][1], es[i][2])
    num = 0
    j = 0
    for j in range(edge):
        vv1 = es[j][0]
        vv2 = es[j][1]
        #print(vv1, vv2)
        #print(sum)
        #print("ff",ff(vv1), ff(vv2))
        if ff(vv1) != ff(vv2):
            num += 1
            f[ff(vv1)] = ff(vv2)
            sum += es[j][2]
            #print("es[j][2]=",es[j][2])
            #print(1)
        if num == p - 1:
            break
    print(sum)
    #ii += 1
