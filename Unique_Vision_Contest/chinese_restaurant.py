def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


N = I()


def main():
    dishes = LIST()
    movements = [0 for _ in range(N)]
    for i, dish in enumerate(dishes):
        movements[(dish-i) % N] += 1
        movements[(dish-i-1) % N] += 1
        movements[(dish-i+1) % N] += 1

    print(max(movements))


if __name__ == "__main__":
    main()
