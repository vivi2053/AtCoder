def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()
from collections import Counter

def main():
    N, M = LIST()
    graph = {i: [] for i in range(N)}

    for i in range(M):
        u, v = LIST()
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)
    
    def dfs(node):
        for conn_node in graph[node]:
            if conn_node not in visited:
                visited.add(conn_node)
                dfs(conn_node)

    visited = set()
    components = 0

    for i in range(N):
        if i in visited:
            pass
        else:
            components += 1
            dfs(i)
    print(components)
        

        


if __name__ == "__main__":
    main()