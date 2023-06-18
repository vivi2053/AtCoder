def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


N, M = LIST()


def dist(x, y):
    return ((x[0] - y[0])**2 + (x[1]-y[1])**2)


def is_valid(x):
    return (x[0] >= 0 and x[0] < N-1) and (x[1] >= 0 and x[1] < N-1)


def main():
    grid = [[-1 for i in range(N)] for j in range(N)]
    grid[0][0] = 0

    origin = (0, 0)
    to_explore = [(origin, 0)]
    while to_explore:
        origin, cur_dist = to_explore.pop(0)
        for i in range(N):
            for j in range(N):
                cur = (i, j)
                if origin == cur:
                    continue
                dist_ = dist(cur, origin)
                if dist_ == M:
                    if grid[i][j] == -1:
                        grid[i][j] = cur_dist+1
                        to_explore.append((cur, grid[i][j]))
                    elif cur_dist+1 < grid[i][j]:
                        grid[i][j] = cur_dist+1
                        to_explore.append((cur, grid[i][j]))

    for i in range(N):
        print(" ".join([str(grid[i][j]) for j in range(N)]))


if __name__ == "__main__":
    main()
