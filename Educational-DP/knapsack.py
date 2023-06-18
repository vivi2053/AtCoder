def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():

    N, MAX_W = LIST()

    inputs = [[0, 0]]
    for _ in range(N):
        inputs.append(LIST())

    dp = [[0 for j in range(MAX_W+1)] for i in range(N+1)]
    for i in range(1, N+1):
        for j in range(1, MAX_W+1):
            if j < inputs[i][0]:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j-inputs[i][0]] +
                               inputs[i][1], dp[i-1][j])
    print(dp[-1][-1])


if __name__ == "__main__":
    main()
