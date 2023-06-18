def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    nums = LIST()
    unique = set()
    for num in nums:
        unique.add(num)
    print(len(unique))


if __name__ == "__main__":
    main()
