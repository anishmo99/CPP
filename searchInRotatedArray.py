for _ in range(int(input())) :
    n = int(input())
    arr = list(map(int,input().strip().split()))
    k=int(input())

    if k in arr:
        print(arr.index(k))
    else:
        print(-1)