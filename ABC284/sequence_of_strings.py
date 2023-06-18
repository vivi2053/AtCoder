def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()
from collections import Counter



def main():
    N = I()
    sequence = []
    for _ in range(N):
        sequence.append(S())
    sequence = sequence[::-1]
    for seq in sequence:
        print(seq)


if __name__ == "__main__":
    main()