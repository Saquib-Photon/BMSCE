# ASTAR case 2:
import heapq

goal = (1, 2, 3,
        4, 5, 6,
        7, 8, 0)


def heuristic(state):
    distance = 0

    for i in range(9):
        tile = state[i]

        if tile != 0:
            current_row = i // 3
            current_col = i % 3

            goal_index = goal.index(tile)
            goal_row = goal_index // 3
            goal_col = goal_index % 3

            distance += abs(current_row - goal_row)
            distance += abs(current_col - goal_col)

    return distance


def get_neighbors(state):
    neighbors = []

    blank = state.index(0)

    row = blank // 3
    col = blank % 3

    moves = [
        (-1, 0),
        (1, 0),
        (0, -1),
        (0, 1)
    ]

    for dr, dc in moves:

        new_row = row + dr
        new_col = col + dc

        if 0 <= new_row < 3 and 0 <= new_col < 3:

            new_blank = new_row * 3 + new_col

            new_state = list(state)

            new_state[blank], new_state[new_blank] = \
                new_state[new_blank], new_state[blank]

            neighbors.append(tuple(new_state))

    return neighbors


def print_state(state):
    for i in range(9):

        if state[i] == 0:
            print("_", end=" ")
        else:
            print(state[i], end=" ")

        if (i + 1) % 3 == 0:
            print()

    print()


def a_star(initial):
    open_list = []

    g = {initial: 0}
    parent = {initial: None}

    h = heuristic(initial)
    f = h

    heapq.heappush(open_list, (f, 0, initial))

    closed = set()

    while open_list:

        f, cost, current = heapq.heappop(open_list)

        if current in closed:
            continue

        if current == goal:

            path = []

            while current is not None:
                path.append(current)
                current = parent[current]

            path.reverse()

            return path

        closed.add(current)

        for next_state in get_neighbors(current):

            new_g = cost + 1

            if next_state in closed:
                continue

            if next_state not in g or new_g < g[next_state]:

                g[next_state] = new_g
                parent[next_state] = current

                h = heuristic(next_state)
                f = new_g + h

                heapq.heappush(
                    open_list,
                    (f, new_g, next_state)
                )

    return None


initial = (
    1, 2, 3,
    4, 0, 6,
    7, 5, 8
)

print("Initial State:")
print_state(initial)

print("Manhattan Distance =", heuristic(initial))

solution = a_star(initial)

if solution:

    print("Solution Found!")

    print("Number of moves:", len(solution) - 1)

    print("\nSolution Path:")

    for step, state in enumerate(solution):

        print("Step", step)
        print_state(state)

else:

    print("No solution found.")
