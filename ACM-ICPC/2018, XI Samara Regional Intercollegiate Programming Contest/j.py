n = int(input())
arr = [int(x) for x in input().split(' ')]
freq = {}

for i in arr:
	if freq.get(i):
		freq[i] += 1
	else:
		freq[i] = 1
sumf = 0
for item,freq in freq.items():
	sumf += freq//2
print(sumf//2)
