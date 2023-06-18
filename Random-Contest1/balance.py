import math
def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    N = I()
    weights = LIST()
    diffs = []
    for t in range(1, N):
        if sum(weights[:t+1]) > sum(weights[t+1:]):
            diffs.append(abs(sum(weights[:t+1]) - sum(weights[t+1:])))
    print(min(diffs))


if __name__ == "__main__":
    main()
