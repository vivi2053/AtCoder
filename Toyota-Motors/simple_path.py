import sys
import collections
sys.setrecursionlimit(10**6)


def LIST(): return list(map(int, input().split()))


class SimplePath:
    def __init__(self) -> None:
        self.node_conns = collections.defaultdict(list)
        self.queue = []
        self.target = None

    def dfs(self, cur, pre=-1):
        if cur == self.target:
            self.queue.append(cur)
            return True

        for conn in self.node_conns[cur]:
            if conn == pre:
                continue
            if self.dfs(conn, cur):
                self.queue.append(cur)
                return True

        return False

    def find_path(self):
        N, x, y = LIST()
        self.target = y
        for _ in range(N-1):
            u, v = LIST()
            self.node_conns[u].append(v)
            self.node_conns[v].append(u)

        self.dfs(x)
        print(*self.queue[::-1])


simple_path = SimplePath()
simple_path.find_path()
