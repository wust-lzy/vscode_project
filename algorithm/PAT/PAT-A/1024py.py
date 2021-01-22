def check(n):
    return n==n2 = n[::-1]

if __name__ == "__main__":
    n, k = input().split()
    cnt=0
    while check(n) == False & cnt < (int)k:
        cnt += 1
        n2 = n[::-1]
        n=str(int(n)+int(n2))
    print(n)
    print(cnt)