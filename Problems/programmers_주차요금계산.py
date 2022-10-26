#https://school.programmers.co.kr/learn/courses/30/lessons/92341
#Implemetation

from collections import defaultdict

def getTime(t):
    time = 0
    if len(t)%2==1:
        t.append('23:59')
    for i in range(len(t)-1, -1, -2):
        hour = int(t[i][:2]) - int(t[i-1][:2])
        minute = int(t[i][3:]) - int(t[i-1][3:])
        time += hour*60 + minute
    return time

def getFee(bt, bf, ut, uf, time):
    if time <= bt:
        return bf
    else:
        otf = (time-bt)/ut
        if int(otf) != otf:
            otf = int(otf) + 1
        return bf + otf*uf
    
def solution(fees, records):
    plist = defaultdict(list)
    for record in records:
        time, car, inout = record.split()
        plist[car].append(time)
    rlist = sorted(plist.items(), key=lambda x: x[0])
    
    tlist = []
    for i in rlist:
        tlist.append(getTime(i[1]))
        
    flist = []
    for i in tlist:
        flist.append(getFee(*fees, i))
    
    return flist