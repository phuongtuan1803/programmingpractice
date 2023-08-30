import io, os, time
from sys import stdin, stdout

# COUNT TIME
start = time.perf_counter() # Stores the start time
end = time.perf_counter()   # Stores the end time
# print("\nTaken time:", end - start)
stdout.write("Taken time: " + str(end - start) + "\n")

# NORMAL I/O
s = input().strip();
print(s)

# FAST I/O
# Input
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = stdin.readline()
arr = [int(x) for x in stdin.readline().split()]

def get_ints(): return map(int, stdin.readline().strip().split())
def get_list(): return list(map(int, stdin.readline().strip().split()))
def get_string(): return stdin.readline().strip()

a,b,c,d = get_ints()
Arr = get_list()
string = get_string()

# Output
stdout.write(str(12313))
stdout.write(" ".join(map(str, arr)) + "\n")
stdout.write("".join([1,2,3]) + "\n")

# I/O via file
# Solution 1:
stdin = open('input.txt', 'r')
stdout = open('output.txt', 'w')
# Solution 2:
# python test_code.py < input.txt > output.txt 2> error.txt

# I/O method

# USEFUL LIBRARY
# list :    Dynamic Sized Array that allows insertions and deletions without caring of size of the array. 
#           It also has advantages of plain arrays like random access  and cache friendliness.  
#           A list can be used as a queue and stack also.
#
# deque :   Dequeue supports insertions and deletions at both ends in O(1) time.  
#           Since it is implemented using array, it allows random access also. 
#           We can use dequeue to implement Queue and Stack both.  
#
# set:      implement hashing. We use set when we have collection of keys. 
#           Useful when we wish to have fast search, insert and delete (all three operations are O(1)). 
# dict:     implement hashing. we use dictionary when we have key value pairs.
#           Useful when we wish to have fast search, insert and delete (all three operations are O(1)). 
#
# heapq :   Implement Min Heap by default.
# sorted :  Does sorting of a sequence like list.
# bisect :  Used for binary search.
#           to keep a set of sorted data. 
# rbtree:   implementation of red black tree
# pyavl:    implementation of AVL tree

# String
# arr[start:stop]         # items start through stop-1
# arr[start:]             # items start through the rest of the array
# arr[:stop]              # items from the beginning through stop-1
# arr[:]                  # a copy of the whole array
# arr[start:stop:step]    # start through not past stop, by step
import math
print(math.trunc(a))
print(math.ceil(a))
print(math.floor(a))
print(round(a, 2))

print('%.2f' % a)
print("{0:.3f}".format(a))
print(f"{a:0,.2f}")
