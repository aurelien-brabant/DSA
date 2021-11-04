#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

size_t find_square_size(char** grid, int x, int y, int grid_x, int grid_y) {
    size_t size = 1;

    while (y + size != grid_y && x + size != grid_x &&
           grid[y + size][x + size] == '1') {

        for (int x2 = x, y2 = y; x2 < size && y2 < size; ++x2, ++y2) {
            if (grid[y + size][x2] == '0' || grid[y2][x + size] == '0') {
                return size;
            }
        }

        ++size;
    }

    return size;
}

size_t solve_bsq(char** grid, size_t grid_x, size_t grid_y, size_t* bsq_x,
                 size_t* bsq_y) {
    size_t square_size = 0;

    for (size_t y = 0; y != grid_y; ++y) {
        for (size_t x = 0; x != grid_x; ++x) {
            if (grid[y][x] == '1') {
                size_t s = find_square_size(grid, x, y, grid_x, grid_y);

                if (s > square_size) {
                    square_size = s;
                    *bsq_x = x;
                    *bsq_y = y;
                }
            }
        }
    }

    return square_size;
}

int main(void) {
    size_t x, y;

    scanf("%lux%lu\n", &x, &y);

    char** grid = calloc(y, sizeof(*grid));

    /* get map's content */
    size_t lc;
    for (lc = 0; lc != y; ++lc) {
        grid[lc] = calloc(x + 2, sizeof(*grid[lc]));

        fgets(grid[lc], x + 2, stdin);

        if (grid[lc][x] != '\n') {
            fprintf(stderr,
                    "FATAL: invalid line length, expected %lu characters per "
                    "line.\n",
                    x);
            exit(EXIT_FAILURE);
        }

        /* remove trailing newline if there is one */
        if (grid[lc][x] == '\n') {
            grid[lc][x] = 0;
        }
    }

    /* solve and print */

    size_t bsq_x, bsq_y, size;

    if ((size = solve_bsq(grid, x, y, &bsq_x, &bsq_y))) {
        for (size_t y2 = 0; y2 != y; ++y2) {
            for (size_t x2 = 0; x2 != y; ++x2) {
                if (y2 >= bsq_y && y2 < bsq_y + size && x2 >= bsq_x &&
                    x2 < bsq_x + size) {
                    grid[y2][x2] = '*';
                }
            }
        }
    }

    for (size_t i = 0; i != y; ++i) {
        puts(grid[i]);
    }

    /* cleanup */

    for (size_t i = 0; i != y; ++i) {
        free(grid[i]);
    }
    free(grid);

    return EXIT_SUCCESS;
}
