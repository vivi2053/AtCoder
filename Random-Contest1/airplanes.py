def MAP(): return list(map(int, input().split()))


def main():
    times = MAP()
    min_ = float('inf')
    for i in range(len(times)):
        for j in range(len(times)):
            if times[i]+times[j] < min_ and i != j:
                min_ = times[i]+times[j]

    print(min_)


if __name__ == "__main__":
    main()
