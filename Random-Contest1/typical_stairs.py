def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    N, n = LIST()
    to_skip = set()
    for i in range(n):
        to_skip.add(I())
    modulo_num = 1000000007
    values = [0]*(N+1)

    # initializing array which will hold intermediate results
    values[N-1] = 1 if (N-1) not in to_skip else 0
    if N-2 not in to_skip:
        values[N-2] = 2 if (N-1) not in to_skip else 1
    else:
        values[N-2] = 0

    for i in range(N-3, -1, -1):
        if i not in to_skip:
            values[i] = (values[i+1] + values[i+2]) % modulo_num

    print(values[0] % modulo_num)


if __name__ == "__main__":
    main()
