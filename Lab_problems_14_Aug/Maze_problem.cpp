#include <iostream>
#include <vector>

const int N = 5; // Size of the maze

std::vector<std::vector<int>> maze = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}
};

std::vector<std::vector<int>> visited(N, std::vector<int>(N, 0));
std::vector<std::pair<int, int>> path;

bool is_valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 && visited[x][y] == 0;
}

bool solve_maze(int x, int y) {
    if (x == N - 1 && y == N - 1) {
        path.push_back({x, y});
        return true; // Reached the end of the maze
    }

    if (is_valid(x, y)) {
        visited[x][y] = 1;
        path.push_back({x, y});

        // Try moving in all four directions: up, right, down, left
        if (solve_maze(x - 1, y) || solve_maze(x, y + 1) || solve_maze(x + 1, y) || solve_maze(x, y - 1)) {
            return true;
        }

        // If no path found, backtrack
        path.pop_back();
        return false;
    }

    return false;
}

int main() {
    if (solve_maze(0, 0)) {
        std::cout << "Path found!" << std::endl;
        for (const auto& p : path) {
            maze[p.first][p.second] = 2; // Mark the path
            for (const auto& row : maze) {
                for (int val : row) {
                    if (val == 0) std::cout << ".";
                    else if (val == 1) std::cout << "#";
                    else std::cout << "*";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No path found!" << std::endl;
    }

    return 0;
}
