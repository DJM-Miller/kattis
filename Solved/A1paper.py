
def A1paper(N):
    pieces_per_size = list(map(int, input().split()))
    needed_pieces = 1
    total_length = 0
    for i in range(len(pieces_per_size)):
        piece_length = pow(2,-(3+(2*i))/4)
        total_length += piece_length * needed_pieces
        needed_pieces = (needed_pieces * 2) - pieces_per_size[i]
        if needed_pieces <= 0: break
    if needed_pieces > 0:
        return "impossible"
    return total_length


if __name__ == "__main__":
    N = int(input())
    results = A1paper(N)
    print(results)




# --------TEST------------
def test_A1paper(monkeypatch):
    inputs = iter([
        "1 0 5"
    ])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    result = A1paper(4)
    assert abs(result - 1.60965532263) < 1e-5

def test_A1paper2(monkeypatch):
    inputs = iter([
        "0 3"
    ])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    result = A1paper(3)
    assert result == "impossible"

def test_A1paper3(monkeypatch):
    inputs = iter([
        "0 4"
    ])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    result = A1paper(3)
    assert abs(result - 1.435499972755075) < 1e-5
