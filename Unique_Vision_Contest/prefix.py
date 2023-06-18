def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    S = input()
    T = input()
    if len(S) > len(T):
        print("No")
        return

    if T[:len(S)] == S:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
