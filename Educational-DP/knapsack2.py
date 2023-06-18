def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    N, W = LIST()
    inputs = [(0, 0)]
    for _ in range(N):
        inputs.append(TPL())

    VAL_SUM = sum([b for _, b in inputs])
    values = [[float('inf') for i in range(VAL_SUM+1)] for j in range(N+1)]

    for i in range(1, N+1):
        w, v = inputs[i]
        values[i][v] = min(values[i-1][v], w)
        for j in range(1, VAL_SUM+1):
            if j < v:
                values[i][j] = values[i-1][j]
            elif j > v:
                values[i][j] = min(values[i][v] +
                                   values[i-1][j-v+1], values[i-1][j])

    print(values)
    for idx, weight in enumerate(values[-1][::-1]):
        if weight <= W:
            print(len(values[-1]) - idx)
            break


if __name__ == "__main__":
    main()
