import pytest

LETTER_TO_NUM = {
    'A': (0, 0), 'B': (0, 1), 'C': (0, 2), 'D': (0, 3),
    'E': (1, 0), 'F': (1, 1), 'G': (1, 2), 'H': (1, 3),
    'I': (2, 0), 'J': (2, 1), 'K': (2, 2), 'L': (2, 3),
    'M': (3, 0), 'N': (3, 1), 'O': (3, 2), '.': (3, 3)
}


def NPuzzle():
    board = list()
    total = 0
    for i in range(4):
        board.append(input())
    for i in range(4):
        for j in range(4):
            if board[i][j] != '.':
                total += abs(i - LETTER_TO_NUM[board[i][j]][0]) + abs(j - LETTER_TO_NUM[board[i][j]][1])
    return total


if __name__ == "__main__":
    print(NPuzzle())


def test_NPuzzle(monkeypatch):
    inputs = iter([
        "ABCD",
        "EFGH",
        "IJKL",
        "M.NO"
    ])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    result = NPuzzle()
    assert result == 2

def test_NPuzzle2(monkeypatch):
    inputs = iter([
        ".BCD",
        "EAGH",
        "IJFL",
        "MNOK"
    ])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    result = NPuzzle()
    assert result == 6