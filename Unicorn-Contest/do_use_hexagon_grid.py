from itertools import chain, combinations
def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


N = I()
points = []

points = set()
visited = set()

combis = [(-1, -1), (-1, 0), (0, -1), (0, 1), (1, 0), (1, 1)]


def explore(point):

    for c in combis:
        new_point = (point[0]+c[0], point[1] + c[1])
        if new_point in visited:
            continue
        if new_point in points:
            visited.add(new_point)
            explore(new_point)


def main():

    for _ in range(N):
        points.add(TPL())

    total = 0
    for p in points:
        if p not in visited:
            visited.add(p)
            explore(p)
            total += 1
    print(total)


if __name__ == "__main__":
    main()
