import collections
import copy
import sys

def bfs(resGraph, s, t, parent):
    """
    @brief Performs a Breadth-First Search (BFS) on the residual graph to find
    an augmenting path from the source 's' to the sink 't'.
    
    This function explores the residual graph level by level, starting from the source.
    It populates a 'parent' array to reconstruct the path if one is found.
    An augmenting path is a simple path from the source to the sink in the
    residual graph where every edge has a capacity greater than 0.
    
    @param resGraph The residual graph represented as an adjacency matrix.
    @param s The source node.
    @param t The sink node.
    @param parent A vector to store the parent of each node in the path.
    @return True if an augmenting path is found, false otherwise.
    """
    n = len(resGraph)
    visited = [False] * n
    q = collections.deque()

    q.append(s)
    visited[s] = True
    parent[s] = -1  # The source has no parent

    while q:
        u = q.popleft()

        for v in range(n):
            # Check if 'v' has not been visited and there is a capacity > 0
            # from 'u' to 'v' in the residual graph.
            if not visited[v] and resGraph[u][v] > 0:
                q.append(v)
                parent[v] = u
                visited[v] = True
                # If we reach the sink, we've found a path.
                if v == t:
                    return True

    # If the queue is empty and we haven't reached the sink, no path exists.
    return False

def printPath(parent, s, t):
    """
    Prints the augmenting path found by the BFS.
    """
    path = []
    v = t
    while v != -1:
        path.append(v)
        v = parent[v]
    path.reverse()

    print("Augmenting Path: ", end="")
    print(" -> ".join(map(str, path)))

def flow(g, s, t):
    """
    @brief Computes the maximum flow from source 's' to sink 't' using the
    Ford-Fulkerson method with a BFS to find augmenting paths (Edmonds-Karp).
    
    @param g The initial graph with capacities, represented as an adjacency matrix.
    @param s The source node.
    @param t The sink node.
    @return The maximum possible flow.
    """
    n = len(g)
    resGraph = copy.deepcopy(g)
    parent = [0] * n
    max_flow = 0
    iteration = 1

    # Loop until no more augmenting paths can be found using BFS.
    while bfs(resGraph, s, t, parent):
        print(f"--- Iteration {iteration} ---")
        
        # Find the minimum residual capacity on the augmenting path found by BFS.
        # This is the bottleneck capacity of the path.
        path_flow = sys.maxsize
        v = t
        while v != s:
            u = parent[v]
            path_flow = min(path_flow, resGraph[u][v])
            v = parent[v]
        
        printPath(parent, s, t)
        print(f"Bottleneck capacity of this path: {path_flow}")

        # Update residual capacities of the edges and reverse edges along the path.
        v = t
        while v != s:
            u = parent[v]
            # Reduce capacity on forward edges
            resGraph[u][v] -= path_flow
            # Increase capacity on reverse edges
            resGraph[v][u] += path_flow
            v = parent[v]

        # Add the path flow to the total maximum flow.
        max_flow += path_flow
        print(f"Current total flow: {max_flow}\n")
        
        iteration += 1

    return max_flow

if __name__ == "__main__":
    # Example graph with capacities
    graph = [
        [0, 10, 5, 15, 0, 0, 0],
        [0, 0, 4, 0, 9, 15, 0],
        [0, 0, 0, 4, 8, 0, 0],
        [0, 0, 0, 0, 0, 0, 16],
        [0, 0, 0, 0, 0, 15, 10],
        [0, 0, 0, 6, 0, 0, 10],
        [0, 0, 0, 0, 0, 0, 0]
    ]

    # Source (s) is node 0, Sink (t) is node 6
    source = 0
    sink = 6

    print(f"Starting maximum flow calculation from source {source} to sink {sink}...")
    max_flow = flow(graph, source, sink)
    print("Calculation finished.")
    print(f"The total maximum possible flow is {max_flow}")