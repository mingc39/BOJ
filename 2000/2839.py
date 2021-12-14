import sys
n = int(input())
if n == 4 or n == 7:
  print(-1)
  sys.exit(0)
r = n // 5
t = n % 5
if t == 1 or t == 3:
  r = r + 1
elif t == 2 or t == 4:
  r = r + 2
print(r)