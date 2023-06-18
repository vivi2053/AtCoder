from collections import defaultdict
def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


class Node:
    def __init__(self, val):
        self.val = val
        self.children = []
        self.parent = None


node_dict = {}


def find_common_ancestor(x, y):
    x = node_dict[x]
    y = node_dict[y]
    x_ances, y_ances = [], []
    while (x.parent):
        x_ances.append(x.val)
        x = x.parent
    x_ances.append(x.val)

    while (y.parent):
        y_ances.append(y.val)
        y = y.parent
    y_ances.append(y.val)

    ya_set = set(y_ances)
    for i in range(len(x_ances)):
        if x_ances[i] in ya_set:
            y_index = y_ances[::-1].index(x_ances[i])
            res = x_ances[:i] + y_ances[::-1][y_index:]
            print(' '.join([str(r) for r in res]))
            return


def main():
    N, x, y = LIST()
    node_conns = defaultdict(list)
    for _ in range(N-1):
        u, v = LIST()
        node_conns[u].append(v)
        node_conns[v].append(u)

    start = next(iter(node_conns))
    queue = [start]
    visited = set()
    node_dict[start] = Node(start)
    while queue:
        cur = queue.pop(0)
        visited.add(cur)
        for child in node_conns[cur]:
            if child in visited:
                continue
            queue.append(child)
            node_dict[child] = Node(child)
            node_dict[child].parent = node_dict[cur]
            node_dict[cur].children.append(node_dict[child])
    find_common_ancestor(x, y)


if __name__ == "__main__":
    main()
