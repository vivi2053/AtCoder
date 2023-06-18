def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    N, K = LIST()
    heights = LIST()

    min_cost = [float('inf') for _ in range(N)]
    min_cost[0] = 0
    for i in range(1, N):
        for j in range(max(i-K, 0), i):
            min_cost[i] = min(min_cost[i], min_cost[j] +
                              abs(heights[i] - heights[j]))
        # prev_diffs = [min_cost[j] for j in range(max(i-K, 0), i)]
        # prev_diffs = [prev + abs(heights[i] - heights[max(i-K+j, 0)])
        #               for j, prev in enumerate(prev_diffs)]
        # min_cost[i] = min(prev_diffs)
    print(min_cost[-1])


if __name__ == "__main__":
    main()
