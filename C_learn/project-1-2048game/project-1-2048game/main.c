#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int board[SIZE][SIZE];

void add_new_number() {
    int empty_cells[SIZE * SIZE][2];
    int empty_count = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                empty_cells[empty_count][0] = i;
                empty_cells[empty_count][1] = j;
                empty_count++;
            }
        }
    }

    if (empty_count > 0) {
        int random_index = rand() % empty_count;
        int new_value = (rand() % 10 == 0) ? 4 : 2; // 10% 概率为4，90% 为2
        board[empty_cells[random_index][0]][empty_cells[random_index][1]] = new_value;
    }
}

void init_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
    // 添加两个初始数字
    add_new_number();
    add_new_number();
}



void print_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf(".\t");
            }
            else {
                printf("%d\t", board[i][j]);
            }
        }
        printf("\n");
    }
}

int merge_line(int* line) {
    int merged = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        if (line[i] != 0 && line[i] == line[i + 1]) {
            line[i] *= 2;
            line[i + 1] = 0;
            merged = 1;
        }
    }
    return merged;
}

void compress_line(int* line) {
    int target = 0;
    for (int i = 0; i < SIZE; i++) {
        if (line[i] != 0) {
            if (i != target) {
                line[target] = line[i];
                line[i] = 0;
            }
            target++;
        }
    }
}

void move_left() {
    int moved = 0;
    for (int i = 0; i < SIZE; i++) {
        int line[SIZE];
        for (int j = 0; j < SIZE; j++) {
            line[j] = board[i][j];
        }
        compress_line(line);
        moved |= merge_line(line);
        compress_line(line);
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = line[j];
        }
    }
    if (moved) {
        add_new_number();
    }
}

void rotate_board() {
    int temp_board[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp_board[i][j] = board[j][SIZE - 1 - i];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = temp_board[i][j];
        }
    }
}

void move_right() {
    rotate_board();
    rotate_board();
    move_left();
    rotate_board();
    rotate_board();
}

void move_up() {
    rotate_board();
    rotate_board();
    rotate_board();
    move_left();
    rotate_board();
}

void move_down() {
    rotate_board();
    move_left();
    rotate_board();
    rotate_board();
    rotate_board();
}

int main() {
    srand(time(NULL));
    char command;
    init_board();
    while (1) {
        print_board();
        printf("Enter a command (w/a/s/d to move, q to quit): ");
        scanf(" %c", &command);
        switch (command) {
        case 'w': move_up(); break;
        case 'a': move_left(); break;
        case 's': move_down(); break;
        case 'd': move_right(); break;
        case 'q': return 0;
        default: printf("Invalid command!\n");
        }
    }
    return 0;
}
