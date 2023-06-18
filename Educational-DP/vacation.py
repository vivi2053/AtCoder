def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    N = I()
    a_val, b_val, c_val = LIST()
    A_best = [0 for _ in range(N)]
    A_best[0] = a_val
    B_best = [0 for _ in range(N)]
    B_best[0] = b_val
    C_best = [0 for _ in range(N)]
    C_best[0] = c_val

    for i in range(1, N):
        a_val, b_val, c_val = LIST()
        A_best[i] = max(B_best[i-1]+a_val, C_best[i-1]+a_val)
        B_best[i] = max(C_best[i-1]+b_val, A_best[i-1]+b_val)
        C_best[i] = max(A_best[i-1]+c_val, B_best[i-1]+c_val)

    print(max(A_best[-1], B_best[-1], C_best[-1]))


if __name__ == "__main__":
    main()
