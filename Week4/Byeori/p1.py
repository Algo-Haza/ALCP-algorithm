N=int(input())
k5=N//5
for i in range(k5+1):
    if (N-k5*5)%3==0:
        k3=(N-k5*5)//3
        break
    else:
        k5=k5-1
try:
   print(k5+k3)
except NameError:
    print(-1)
