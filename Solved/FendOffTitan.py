def main():
    #INPUT
    N, M, X, Y = map(int,input().split())
    graph = [[None for _ in range(N)] for _ in range(N)]
    
    for _ in range(M):
        a, b, w, c = map(int,input().split())
        graph[a-1][b-1] = graph[b-1][a-1] = [w,c]

    dist, shamans, titans = dijkstras(graph, X-1, N, Y-1)

    if dist == float('inf'):
        print("IMPOSSIBLE")
    else:
        print(dist, shamans, titans)
    

    pass



def dijkstras(graph, start, size, end):
    distances = [float('inf')] * size
    titans = [float('inf')] * size
    shamans = [float('inf')] * size
    distances[start] = 0
    titans[start] = 0
    shamans[start] = 0
    visited = [False] * size

    for _ in range(size):
        min_dist = float('inf')
        min_titans = float('inf')
        min_shamans = float('inf')
        u = None
        for i in range(size):
            if (not visited[i] and 
                (titans[i] < min_titans or 
                (titans[i] == min_titans and shamans[i] < min_shamans) or
                (titans[i] == min_titans and shamans[i] == min_shamans and distances[i] < min_dist))):
                min_dist = distances[i]
                min_titans = titans[i]
                min_shamans = shamans[i]
                u = i
        
        if u is None:
            break

        visited[u] = True

        for v in range(size):
            if graph[u][v] is not None and not visited[v]:
                alt = distances[u] + graph[u][v][0]
                if graph[u][v][1] == 1:
                    alt_shaman = shamans[u] + 1
                    alt_titans = titans[u]
                elif graph[u][v][1] == 2:
                    alt_shaman = shamans[u]
                    alt_titans = titans[u] + 1
                else:
                    alt_shaman = shamans[u]
                    alt_titans = titans[u]
                
                if (alt_titans < titans[v] or 
                    (alt_titans == titans[v] and alt_shaman < shamans[v]) or 
                    (alt_titans == titans[v] and alt_shaman == shamans[v] and alt < distances[v])):
                    distances[v] = alt
                    titans[v] = alt_titans
                    shamans[v] = alt_shaman
                
    
    return distances[end], shamans[end], titans[end]

    


#test functions
def print_matrix(matrix):
    for line in matrix:
        for element in line:
            print(element,end='-----')
        print()





if __name__ == "__main__":
    main()