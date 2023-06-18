def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def solve():
    X, Y, Z = LIST()

    if X * Y < 0:
        return abs(X)

    if X < 0:
        if X > Y:
            return abs(X)
        else:
            if Z < Y:
                return -1
            else:
                return (2*abs(Z) + abs(X)) if X*Z < 0 else abs(X)
    else:
        if X < Y:
            return X
        else:
            if Z > Y:
                return -1
            else:
                return (2*abs(Z)+X) if X*Z < 0 else X


def main():
    print(solve())


if __name__ == "__main__":
    main()
