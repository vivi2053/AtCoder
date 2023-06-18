def I(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def TPL(): return tuple(map(int, input().split()))
def S(): return input()
from collections import Counter

def binary_search(arr, low, high, x):
 
    # Check base case
    if high >= low:
 
        mid = (high + low) // 2
 
        # If element is present at the middle itself
        if arr[mid] == x:
            return mid
 
        # If element is smaller than mid, then it can only
        # be present in left subarray
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
 
        # Else the element can only be present in right subarray
        else:
            return binary_search(arr, mid + 1, high, x)
 
    else:
        # Element is not present in the array
        return -1


def main():
    N = I()
    A = LIST()
    uniq_a = list(set(A))
    uniq_a_len = len(uniq_a)
    uniq_a.sort()

    a_count = Counter(A)
    a_count = {k: [v, 0] for k, v in a_count.items()}

    for a in A:
        index_of_a = binary_search(uniq_a, 0, uniq_a_len - 1, a)
        a_count[a][1] = uniq_a_len - index_of_a - 1

    for K in range(N):
        exactly_K = sum([v[0] for v in a_count.values() if v[1] == K])
        print(exactly_K)
    
    

if __name__ == "__main__":
    main()
