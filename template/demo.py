# template begins
#####################################

# import libraries for input/ output handling
# on generic level
import atexit, io, sys

# A stream implementation using an in-memory bytes
# buffer. It inherits BufferedIOBase.
buffer = io.BytesIO()
sys.stdout = buffer

# print via here
@atexit.register
def write():
	sys.stdout.write(buffer.getvalue())

#####################################
# template ends

# normal method followed
# input N
n = int(input())

# input the array
arr = [int(x) for x in input().split()]

# initialize variable
summation = 0

# calculate sum
for x in arr:
	summation += x

# print answer
print(summation)
