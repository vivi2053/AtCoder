def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    N = I()
    values = LIST()
    print(sum(values))


if __name__ == "__main__":
    main()
