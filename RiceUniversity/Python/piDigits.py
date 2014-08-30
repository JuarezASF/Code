n = int(raw_input('Enter the number of numbers of PI you want to know:'))
print "I'll calculate", n, "digits of pi."
size = 10.0*n/3.0 + 1
size = int(size)
print "A vector of size", size, "will be utilized for the spigot algorithm"
A = range(0, size, 1)
preDigits = []
piDigits = []
for i in range(len(A)):
	A[i] = 2
for i in range(n+1):
	A = [x*10 for x in A]
	for j in range(len(A)-1):
		k = len(A)-1-j
		q = A[k]/(2*j-1)
		r = A[k]%(2*j-1)
		A[k] = q
		A[k-1] = A[k-1] + q*(i-1)
	q = A[0]/10
	A[0] = A[0]%10
	if q == 9:
		preDigits.append(q)
	elif q == 10:
		q = 0		 
		

