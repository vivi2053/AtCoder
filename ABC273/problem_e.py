def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()


def main():
    result = []
    Notebook = {}
    A = []
    Q = I()
    for _ in range(Q):
        command, *num = (S()+' '+'0').split()
        num = int(num[0])
    
        if command == "ADD":
            A.append(num)
            if len(A)>0: result.append(A[-1])
            else: result.append(-1)
        elif command == "DELETE":
            if len(A)>0: A.pop()
            if len(A)>0: result.append(A[-1])
            else: result.append(-1)
        elif command == "SAVE":
            Notebook[num] = [_ for _ in A]
            if len(A)>0: result.append(A[-1])
            else: result.append(-1)
        else:
            A = Notebook.get(num, [])
            if len(A)>0: result.append(A[-1])
            else: result.append(-1)
    print(" ".join([str(r) for r in result]))
    
    

if __name__ == "__main__":
    main()
