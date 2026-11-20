#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

enum direction { UP, DOWN, LEFT, RIGHT };     
#define MAP_SIZE 10 

// Functions
void init_map(char map[][MAP_SIZE]);
bool set_cord(enum direction dir, char letter, char map[][MAP_SIZE], int *x, int *y);
void print_map(char map[][MAP_SIZE]);

int main(void) {
    char map[MAP_SIZE][MAP_SIZE];
    init_map(map);
    srand(time(NULL));

    // Initialize a starting point
    int x = rand() % MAP_SIZE;
    int y = rand() % MAP_SIZE;
    map[x][y] = 'A';


    // Fill the rest of the alphabet
    bool found;
    for (char letter = 'B'; letter <= 'Z'; letter++) {
        found = false;
        enum direction dir = rand() % 4;
        
        // Try to see if it succeeds with a random number
        if (set_cord(dir, letter, map, &x, &y)) {
            found = true;
        } else {
            //for (dir = UP; dir <= RIGHT; dir++) {
            for (int i = 0; i < 3; i++) {
                dir = (dir + 1) % 4;
                if (set_cord(dir, letter, map, &x, &y)) {
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            break;            
        }
    }

    if (found) {
        print_map(map);
    } else {
        print_map(map);
        printf("All four directions got blocked");
    }
    return 0;
}

bool set_cord(enum direction dir, char letter, char map[][MAP_SIZE], int *x, int *y) {
    switch (dir) {
        case UP:
            if (*x - 1 < 0 || map[*x-1][*y] != '.') {
                return false;
            } 
            (*x)--;
            map[*x][*y] = letter;
            break;
        case DOWN:
            if (*x + 1 >= MAP_SIZE || map[*x+1][*y] != '.') {
                return false;
            }
            (*x)++;
            map[*x][*y] = letter;
            break;
        case LEFT: 
            if (*y - 1 < 0 || map[*x][*y-1] != '.') {
                return false;
            }
            (*y)--;
            map[*x][*y] = letter;
            break;
        case RIGHT:
            if (*y + 1 >= MAP_SIZE || map[*x][*y+1] != '.') {
                return false;
            }
            (*y)++;
            map[*x][*y] = letter;
            break;
    }
    return true;
}

void init_map(char map[][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '.';
        }
    }
}

void print_map(char map[][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}