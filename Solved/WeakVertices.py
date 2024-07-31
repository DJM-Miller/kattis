import pytest


def weakVertices(N):
    
    edgelist =  [set() for _ in range(N)]
    results = list()
    intriangle = set()


    for i in range(N):
        line = input().split()
        for j in range(N):
            if int(line[j]) == 1:
                edgelist[i].add(j)

    for i in range(N):
        if len(edgelist[i]) < 2:
            results.append(i)
        elif i in intriangle:
            continue
        else:
            triangle = False
            for edge1 in edgelist[i]:
                if triangle:
                    break
                for edge2 in edgelist[i]:
                    if edge2 in edgelist[edge1]:
                        triangle = True
                        intriangle.add(i)
                        intriangle.add(edge1)
                        intriangle.add(edge2)
                        break
            if not triangle:
                results.append(i)
    
    return results
    
                    
                
if __name__ == "__main__":
    N = int(input())
    while N != -1:
        results = weakVertices(N)
        print(" ".join(map(str, results)))
        N = int(input())








#TESTS######
def test_weakVertices(monkeypatch):
    inputs = iter([
        "0 1 1 1 0 0 0 0 0",
        "1 0 0 0 0 0 1 0 0",
        "1 0 0 1 0 1 0 0 0",
        "1 0 1 0 0 1 1 0 0",
        "0 0 0 0 0 0 1 1 0",
        "0 0 1 1 0 0 0 0 0",
        "0 1 0 1 1 0 0 1 0",
        "0 0 0 0 1 0 1 0 1",
        "0 0 0 0 0 0 0 1 0"
    ])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    results = weakVertices(9)
    assert results == [1,8]


def test_weakVertices2(monkeypatch):
    inputs = iter([
        "0"
    ])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    results = weakVertices(1)
    assert results == [0]