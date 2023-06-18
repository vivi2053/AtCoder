def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    N = I()
    heights = LIST()

    min_cost = [0 for _ in range(N)]
    for i in range(1, N):
        prev_diff = min_cost[i-1] + abs(heights[i] - heights[i-1])
        bef_prev_diff = min_cost[i-2] + \
            abs(heights[i] - heights[i-2]) if i-2 >= 0 else float('inf')
        min_cost[i] = min(prev_diff, bef_prev_diff)
    print(min_cost[-1])


if __name__ == "__main__":
    main()
