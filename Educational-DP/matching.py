def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()

def main():
    N = I()
    tree = {i:[] for i in range(1, N+1)}
    for i in range(N-1):
        x, y = LIST()
    tree[x] = y
    tree[y] = x
    


if __name__ == "__main__":
    main()