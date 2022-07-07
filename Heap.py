import heapq

l = [1,2,7,3,6,9,0,7,3,5,4,6,3,1]
h = []
sortedh = []

for v in l:
    heapq.heappush(h, v) #-v (for max heap)

for j in range(len(h)):
    sortedh.append(heapq.heappop(h)) #-heapq.heappop(h) (for max heap)
    
print(sortedh)