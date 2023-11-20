#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_DIM 5
int seed = 0;

struct plane {
    int velx, vely;
};

struct plane *grid[10][10];

struct plane *new_plane() {
    struct plane *plane = malloc(sizeof(plane));

    plane->velx = random() % 10;
    plane->vely = random() % 10;

    return plane;
}

void display() {
    for (int row = 0; row < GRID_DIM; row++) {
        for (int col = 0; col < GRID_DIM; col++) {
            printf("%d ", !!grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    srandom(time(NULL));

    for (int row = 0; row < GRID_DIM; row++) {
        for (int col = 0; col < GRID_DIM; col++) {
            if (random() % 10 == 0) {
                grid[row][col] = new_plane();
            } else {
                grid[row][col] = NULL;
            }
        }
    }

    while (1) {
        system("clear");
        display();
    }

}