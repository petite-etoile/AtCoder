def main():
    N = int(input())
    p = [int(i) for i in input().split()]
    scores = set([0])
    for p_ in p:
        for score_ in list(scores):
            scores.add(score_ + p_)
    print(len(scores))


if __name__ == '__main__':
    main()
