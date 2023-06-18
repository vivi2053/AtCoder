def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    a, b, c, d = LIST()
    print(str((a+b)*(c-d)))
    print("Takahashi")


if __name__ == "__main__":
    main()
