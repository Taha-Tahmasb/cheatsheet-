#include <stdio.h>

char puzzle[9][9];

void make_puzzle() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int p;
            printf("Enter the value for puzzle[%d][%d]: ", i, j);
            scanf("%d", &p);
            puzzle[i][j] = p;
        }
    }
}

void draw() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

char find_free(int *a, int *b) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (puzzle[i][j] == 0) {
                *a = i;
                *b = j;
                return 1;
            }
        }
    }
    return 0;
}

char is_valid(int n, int x, int y) {
    for (int i = 0; i < 9; i++) {
        if (puzzle[x][i] == n || puzzle[i][y] == n) {
            return 0;
        }
    }
    int x_square = (x / 3) * 3;
    int y_square = (y / 3) * 3;
    for (int i = x_square; i < x_square + 3; i++) {
        for (int j = y_square; j < y_square + 3; j++) {
            if (puzzle[i][j] == n) {
                return 0;
            }
        }
    }
    return 1;
}

int solve() {
    int x, y;
    if (find_free(&x, &y) == 0) {
        return 1;
    }
    for (int i = 1; i <= 9; i++) {
        if (is_valid(i, x, y)) {
            puzzle[x][y] = i;
            if (solve()) {
                return 1;
            }
            puzzle[x][y] = 0;
        }
    }
    return 0;
}

int main() {
    make_puzzle();
    if (solve()) {
        draw();
    } else {
        printf("Can't solve this puzzle\n");
    }
    return 0;
}