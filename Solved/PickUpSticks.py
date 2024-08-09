# import pytest

from collections import deque, defaultdict

def main():
    n, m = map(int,input().split())
    in_degree = [0] * (n+1)
    graph = dict()
    for i in range(1,n+1):
        graph[i] = []

    

    for _ in range(m):
        a, b = map(int,input().split())
        graph[a].append(b)
        in_degree[b] += 1
    

    que = list()
    for i in range(1,n+1):
        if in_degree[i] == 0:
            que.append(i)
    result = list()
    
    while que:
        node = que[0]
        del que[0]
        result.append(node)
        for edge in graph[node]:
            in_degree[edge] -= 1
            if in_degree[edge] == 0:
                que.append(edge)
    
    if len(result) != n:
        return "IMPOSSIBLE"
    return result

# def main():
#     # n = number of sticks, m = number of relations
#     n, m = map(int, input().split())

#     # Graph representation and in-degree count
#     graph = defaultdict(list)
#     in_degree = [0] * (n + 1)

#     # Read the relations and build the graph
#     for _ in range(m):
#         a, b = map(int, input().split())
#         graph[a].append(b)
#         in_degree[b] += 1

#     # Queue for nodes with zero in-degree
#     queue = deque()
    
#     # Enqueue all nodes with zero in-degree
#     for i in range(1, n + 1):
#         if in_degree[i] == 0:
#             queue.append(i)

#     result = []

#     while queue:
#         node = queue.popleft()
#         result.append(node)

#         # Decrease the in-degree of adjacent nodes
#         for neighbor in graph[node]:
#             in_degree[neighbor] -= 1
#             # If in-degree becomes zero, add it to the queue
#             if in_degree[neighbor] == 0:
#                 queue.append(neighbor)

#     # Check if there was a cycle (i.e., not all nodes are processed)
#     if len(result) != n:
#         return "IMPOSSIBLE"
#     else:
#         return result




#--------TESTS-------------------------

def test_case1(monkeypatch):
    inputs = iter(["3 2", "1 2", "2 3"])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    result = main()
    assert result == [1, 2, 3]

def test_case2(monkeypatch):
    inputs = iter(["5 4", "1 2", "2 3", "4 5", "5 1"])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    result = main()
    assert result == [4, 5, 1, 2, 3]

def test_case3(monkeypatch):
    inputs = iter(["7 4", "1 2", "2 3", "4 5", "5 1"])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    result = main()
    assert result == [4, 5, 1, 2, 3, 6, 7]

def test_case4(monkeypatch, capsys):
    inputs = iter(["5 4", "1 2", "2 1", "4 5", "5 1"])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    result = main()
    assert result == "IMPOSSIBLE"





if __name__ == "__main__":
    result = main()
    if result == "IMPOSSIBLE":
        print("IMPOSSIBLE")
    else:
        for stick in result:
            print(stick)






