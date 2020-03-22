from random import randint
s = "a"
N = 10
print("a")
print(N)
for i in range(N):
    a = randint(0,1)
    if a==1:
        print(a+1,(randint(0,1))+1,randint(0,9)) 
    else:
        print(a+1)