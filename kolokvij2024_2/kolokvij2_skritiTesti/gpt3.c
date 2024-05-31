#include <stdio.h>
#include <stdbool.h>

#define MAX_N 20
#define MAX_EMPTY_CELLS 25

int n, k;
bool board[MAX_N][MAX_N];
int longest_path_length = 0;
int current_path_length = 0;
int longest_path[MAX_EMPTY_CELLS][2];
int current_path[MAX_EMPTY_CELLS][2];

int DVR[] = {1, 2, 2, 1, -1, -2, -2, -1};
int DST[] = {2, 1, -1, -2, -2, -1, 1, 2};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && !board[x][y];
}

void backtrack(int x, int y) {
    if (current_path_length > longest_path_length) {
        longest_path_length = current_path_length;
        for (int i = 0; i < current_path_length; i++) {
            longest_path[i][0] = current_path[i][0];
            longest_path[i][1] = current_path[i][1];
        }
    }

    for (int i = 0; i < 8; i++) {
        int nx = x + DVR[i];
        int ny = y + DST[i];

        if (is_valid(nx, ny)) {
            board[nx][ny] = true;
            current_path[current_path_length][0] = nx;
            current_path[current_path_length][1] = ny;
            current_path_length++;

            backtrack(nx, ny);

            current_path_length--;
            board[nx][ny] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &k);

    // Initialize the board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = false;
        }
    }

    // Read obstacles
    for (int i = 0; i < k; i++) {
        int vi, si;
        scanf("%d %d", &vi, &si);
        board[vi][si] = true;
    }

    // Mark the starting point
    board[0][0] = true;

    // Start the backtracking from (0, 0)
    backtrack(0, 0);

    // Print the longest path
    for (int i = 0; i < longest_path_length; i++) {
        printf("%d/%d\n", longest_path[i][0], longest_path[i][1]);
    }

    return 0;
}

