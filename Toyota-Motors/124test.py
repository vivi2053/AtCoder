def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


score_dist = {1: 1, 2: 2, 3: 4}
A, B = LIST()


def main():
    score_2_prob = {v: [k] for k, v in score_dist.items()}
    score_2_prob[0] = []
    score_2_prob[3] = [1, 2]
    score_2_prob[5] = [1, 3]
    score_2_prob[6] = [2, 3]
    score_2_prob[7] = [1, 2, 3]

    a_and_b = set(score_2_prob[A]+score_2_prob[B])
    C = sum([score_dist[k] for k in a_and_b])
    print(C)


if __name__ == "__main__":
    main()
