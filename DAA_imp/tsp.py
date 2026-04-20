import heapq
import math

def tsp_a_star(graph, start_node):
    """
    Solves the Traveling Salesman Problem (TSP) using the A* search algorithm.

    TSP: Given a set of cities (nodes) and distances between them,
         the goal is to find the shortest possible route that visits
         every city exactly once and returns to the starting city.

    A*: A graph search algorithm that expands paths by combining:
         - g(n): actual cost from start to current node
         - h(n): heuristic estimate of remaining cost
         so f(n) = g(n) + h(n).
    """

    num_nodes = len(graph)

    # Priority queue elements:
    # (f_score, g_score, path, current_node, unvisited_nodes)
    # - f_score = g_score + heuristic
    # - g_score = actual cost so far
    # - path = nodes visited in order
    # - current_node = last node in path
    # - unvisited_nodes = set of cities not visited yet
    priority_queue = [(0, 0, [start_node], start_node, frozenset(graph.keys()))]

    # Keep track of visited states to avoid recomputation
    visited_states = set()

    best_tour = None      # Final tour path
    min_cost = float('inf')  # Best cost found so far

    step_count = 0  # Just for debugging output

    while priority_queue:
        step_count += 1
        f_score, cost, path, current_node, unvisited_nodes = heapq.heappop(priority_queue)

        print(f"\n--- Step {step_count} ---")
        print(f"Popped from queue: f_score={f_score}, cost={cost}, path={path}, current_node={current_node}")
        print(f"Unvisited nodes: {list(unvisited_nodes)}")

        # Define the current search state
        state = (current_node, unvisited_nodes)

        # Skip repeated states
        if state in visited_states:
            print("  -> State already visited, skipping.")
            continue
        visited_states.add(state)

        # If path covers all nodes, check for return to start
        if len(path) == num_nodes:
            return_cost = graph[current_node].get(start_node, float('inf'))
            if return_cost == float('inf'):
                # If no edge back to start, this path is invalid
                print(f"  -> No path back to start node {start_node}, cannot complete tour.")
                continue

            # Total tour cost = cost so far + cost to return to start
            total_cost = cost + return_cost
            print(f"  -> All nodes visited. Tour candidate found: {path + [start_node]}. Total cost: {total_cost}")

            # Update best tour if this one is better
            if total_cost < min_cost:
                min_cost = total_cost
                best_tour = path + [start_node]
                print(f"  -> New best tour found! Cost: {min_cost}")
            continue

        # Explore neighbors (unvisited cities)
        print(f"  -> Exploring neighbors of {current_node}:")
        for neighbor, weight in graph[current_node].items():
            if neighbor in unvisited_nodes:
                # Extend the current path
                new_path = path + [neighbor]
                new_cost = cost + weight
                new_unvisited_nodes = unvisited_nodes - {neighbor}

                # Heuristic = MST (Minimum Spanning Tree) over remaining unvisited nodes
                h_score = mst_heuristic(graph, new_unvisited_nodes)

                # A* evaluation function
                f_score = new_cost + h_score

                print(f"    - To neighbor {neighbor}: g={new_cost}, h={h_score}, f={f_score}")

                # Push new state into the priority queue
                heapq.heappush(priority_queue, (f_score, new_cost, new_path, neighbor, new_unvisited_nodes))

    return best_tour, min_cost


def mst_heuristic(graph, nodes):
    """
    Heuristic function for A*:
    Estimate the remaining cost by calculating the MST (Minimum Spanning Tree)
    of the unvisited nodes.

    - MST gives a lower bound of the cost needed to connect all unvisited nodes.
    - Admissible heuristic: Never overestimates, ensures A* finds the optimal solution.
    """

    if len(nodes) <= 1:
        return 0

    mst_cost = 0
    visited = set()
    
    if not nodes:
        return 0
    
    # Start MST from an arbitrary unvisited node
    start_node = next(iter(nodes))
    priority_queue = [(0, start_node)]

    while priority_queue and len(visited) < len(nodes):
        weight, current_node = heapq.heappop(priority_queue)

        if current_node in visited:
            continue

        visited.add(current_node)
        mst_cost += weight

        # Add edges from this node to other unvisited nodes
        for neighbor, edge_weight in graph.get(current_node, {}).items():
            if neighbor in nodes and neighbor not in visited:
                heapq.heappush(priority_queue, (edge_weight, neighbor))

    return mst_cost


if __name__ == "__main__":
    graph = {
        'A': {'B': 10, 'C': 5, 'D': 15},
        'B': {'A': 10, 'C': 4, 'D': 6},
        'C': {'A': 5, 'B': 4, 'D': 7},
        'D': {'A': 15, 'B': 6, 'C': 7}
    }

    start_node = 'A'
    tour, cost = tsp_a_star(graph, start_node)

    print("\n--- Final Result ---")
    if tour:
        print(f"Optimal tour found: {tour}")
        print(f"Total cost: {cost}")
    else:
        print("No solution found.")
