def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    N, M = LIST()
    flags = [[0 for i in range(N)] for j in range(N)]
    attendees_list = []
    for i in range(M):
        _, *attendees = LIST()
        attendees_list.append(attendees)
    for attendees in attendees_list:
        for i in range(len(attendees)):
            for other in attendees[i+1:]:
                flags[attendees[i]-1][other-1] = 1
                flags[other-1][attendees[i]-1] = 1
    if sum([sum(flag) for flag in flags]) == (N*N) - N:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
