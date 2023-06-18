def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    rows = []
    H, W = LIST()
    dp = [[0 for i in range(W)] for j in range(H)]
    dp[0][0] = 1
    for i in range(H):
        row = list(S())
        row = [1 if val == "#" else 0 for val in row]
        rows.append(row)

    for i in range(H):
        for j in range(W):
            if (i, j) == (0, 0) or rows[i][j] == 1:
                continue
            prev_left = dp[i-1][j] if i-1 >= 0 else 0
            prev_up = dp[i][j-1] if j-1 >= 0 else 0
            dp[i][j] = (prev_left + prev_up) % 1000000007
    print(dp[-1][-1])


if __name__ == "__main__":
    main()
