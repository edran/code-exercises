from functools import cmp_to_key


class Player:
    def __init__(self, name, score):
        self.name = name
        self.score = score

    def __repr__(self):
        return "({}, {})".format(self.name, self.score)

    def comparator(a, b):
        l = [(1, a), (2, b)]
        if a.score == b.score:
            l = sorted(l, key=lambda player: player[1].name)
            return l[0][0] - l[1][0]
        else:
            l = sorted(l, key=lambda player: player[1].score)
            return l[1][0] - l[0][0]


if __name__ == "__main__":
    n = int(input())
    data = []
    for i in range(n):
        name, score = input().split()
        score = int(score)
        player = Player(name, score)
        data.append(player)

    data = sorted(data, key=cmp_to_key(Player.comparator))
    for i in data:
        print(i.name, i.score)
