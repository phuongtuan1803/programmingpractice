import sys
# Input via stdin and file
sys.stdin = open('input.txt', 'r') 
s = input().decode()

# print th ouput to stdout and file
sys.stdout = open('output.txt', 'w') 
sys.stdout.write(s) 

# ======================= list 
li = {}

## copy
## O(n)

## append, insert, extend, remove, pop() pop(x)
## O(1),   O(n),   O(n),   O(n),   O(1), O(n)

## clear, index, count
## O(n),  O(n),  O(n)

## sort O(n log n)
li.sort()
li.sort(reverse=True)
li.sort(key=str.lower)

## reverse
li.reverse()
reversed(li)

## Slicing of a List
## O(k)
li[1:2:-1]

# ======================= Deque
#  import
from collections import deque
de = deque(['x','y'])

## append, appendleft, pop,   popleft
## O(1),   O(1),       O(1),  O(1)

## index, insert, count, remove
## O(n),  O(n),   O(n),  O(n)

## extend, extendleft, reverse, rotate
## O(k),   O(k),       O(n),    O(k)