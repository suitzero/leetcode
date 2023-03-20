def generateMatrix(n):
    A = [[n*n]]
    while A[0][0] > 1:
        print(A)
        print("#",list(zip(*A[::-1])))
        A = [list(range(A[0][0] - len(A), A[0][0]))] + list(zip(*A[::-1]))
    return A * (n>0)

print(generateMatrix(3))