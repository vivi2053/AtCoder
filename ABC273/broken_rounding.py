def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()

def main():
    N, K = LIST()
    for i in range(1, K+1):
        div = 10**i
        rem = div if (N % div) >= 5*(10**(i-1)) else 0
        N = N//div
        N = N * div + rem
    print(N)


if __name__ == "__main__":
    main()
