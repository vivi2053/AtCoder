def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()

def get_factors(in_num):
    factors = []
    k = 2
    while k*k < in_num:
        if in_num % k == 0:
            factors.append(k)
        k+=1
    return factors


def main():
    T = I()
    for i in range(T):
        num = I()
        k = 2
        while k*k < num:
            if num % k != 0:
                k+=1
                continue
            else:
                k_comp = num // k
                if k_comp % k == 0:
                    print(k, k_comp//k)
                    break
                k+=1



if __name__ == "__main__":
    main()