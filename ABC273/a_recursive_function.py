def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()

def main():
    N = I()
    if N == 0: print(1)
    else:
        value = 1
        for i in range(1, N+1):
            value *= i
        print(value)


if __name__ == "__main__":
    main()
