import sys

def hanoi(start, tmp, dest, curr, ans):
    if curr == 1:
        ans.append(f"{start} {dest}")
        return
    
    hanoi(start, dest, tmp, curr - 1, ans)
    ans.append(f"{start} {dest}")
    hanoi(tmp, start, dest, curr - 1, ans)

N = int(sys.stdin.readline())

print(2**N - 1)

if N <= 20:
    ans = []
    hanoi(1, 2, 3, N, ans)
    sys.stdout.write('\n'.join(ans))