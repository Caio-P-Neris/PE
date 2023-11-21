def comb(n):
    if n ==1:
        return [1]
    else:
        comb(n-1) + n
        comb(n-1)
        print(n)


def main():
    n = int(input("Qual n?"))

    comb(n)

    return 0