def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    strings = []
    for i in range(10):
        strings.append(str(input()))

    for i, s in enumerate(strings):
        if '#' in s:
            a = i + 1
            c = s.index('#') + 1
            break

    strings.reverse()
    for i, s in enumerate(strings):
        if '#' in s:
            b = 10-i
            d = 10 - s[::-1].index('#')
            break
    print(a, b)
    print(c, d)


if __name__ == "__main__":
    main()
