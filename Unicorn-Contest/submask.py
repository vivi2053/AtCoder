from itertools import chain, combinations
def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))


def main():
    N = I()
    N_bin = bin(N)[2:][::-1]

    activ_pos = [idx for idx, val in enumerate(N_bin) if val == '1']

    print_nums = []
    for activ_idxs in powerset(activ_pos):
        prototype = "".join(
            ['1' if i in activ_idxs else '0' for i in range(64)])
        prototype = prototype[::-1]
        print_nums.append(int(prototype, 2))

    print_nums.sort()
    for num in print_nums:
        print(num)


if __name__ == "__main__":
    main()
