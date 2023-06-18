def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()
from collections import Counter

def main():
    T = I()
    for i in range(T):
        N = I()
        inputs = LIST()
        print(len([in_ for in_ in inputs if in_ % 2==1]))


if __name__ == "__main__":
    main()