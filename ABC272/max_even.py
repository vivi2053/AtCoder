def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def check(num, first, second):
    if num > first:
        return num, first
    if num >= second:
        return first, num
    return first, second


def check_odd():
    pass


def main():
    N = I()
    nums = LIST()

    evens = []
    max_even = -1
    second_even = -2
    max_odd = -1
    second_odd = -2

    for num in nums:
        if num % 2 == 0:
            max_even, second_even = check(num, max_even, second_even)
        else:
            max_odd, second_odd = check(num, max_odd, second_odd)

    result_even = max_even+second_even if max_even >= 0 and second_even >= 0 else -1
    result_odd = max_odd+second_odd if max_odd >= 0 and second_odd >= 0 else -1
    print(max(result_odd, result_even))


if __name__ == "__main__":
    main()
