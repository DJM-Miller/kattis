def dijkstras(graph, start, size):
    distances = [float('inf')] * size
    distances[start] = 0
    visited = [False] * size

    for _ in range(size):
        min_dist = float('inf')
        u = None
        for i in range(size):
            if not visited[i] and distances[i] < min_dist:
                min_dist = distances[i]
                u = i
        
        if u is None:
            break

        visited[u] = True

        for v in range(size):
            if graph[u][v] != None and not visited[v]:
                alt = distances[u] + graph[u][v][0]
                if alt < distances[v]:
                    distances[v] = alt
    
    return distances