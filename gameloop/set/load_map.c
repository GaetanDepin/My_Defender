/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** load_map
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "defender.h"

//NORM

static int verif_map(FILE *fd, int *height)
{
    char *line = NULL;
    size_t len = 0;
    int size = 0;
    int line_w = 0;

    while ((line_w = getline(&line, &len, fd)) != -1) {
        line[line_w - 1] == '\n' ? line_w-- : line_w;
        if (line_w != MAP_W) {
            mputerror("Error: map width\n");
            return (ERROR);
        }
        size++;
    }
    *height = size;
    free(line);
    return (SUCCESS);
}

static int verif_file(const char *const path, int *height)
{
    FILE* fd = NULL;

    if ((fd = fopen(path, "r")) == NULL) {
        mputerror("Error: can't load file\n");
        return (ERROR);
    }
    if (verif_map(fd, height) == ERROR)
        return (ERROR);
    if (fclose(fd) != 0)
        return (ERROR);
    if (*height != MAP_H ) {
        mputerror("Error: map height\n");
        return (ERROR);
    }
    return (SUCCESS);
}

int gene_line(char *line, sfVector2f pos, my_sprite_t **sprite, tower_t **tow)
{
    int size = mstrlen(line);

    line[size - 1] == '\n' ? size-- : size;
    if ((*sprite = malloc(sizeof(my_sprite_t) * (size + 1))) == NULL)
        return (ERROR);
    if ((*tow = malloc(sizeof(tower_t) * (size + 1))) == NULL)
        return (ERROR);
    (*sprite)[size].sprite = NULL;
    for (int i = 0 ; line[i] != '\0' && line[i] != '\n' ; i++) {
        pos.x = i * TILE_SIZE;
        map_parser(pos, line[i], &((*sprite)[i]));
        tower_parser(line[i], &((*tow)[i]));
    }
    return (SUCCESS);
}

int generate_map(char *path, int height, my_sprite_t ***map, tower_t ***tower)
{
    char *line = NULL;
    FILE *fd = NULL;
    size_t len = 0;
    sfVector2f pos = ini_vector(0, 0);

    if ((*map = malloc(sizeof(my_sprite_t*) * (height + 1))) == NULL)
        return (ERROR);
    if ((*tower = malloc(sizeof(tower_t) * (height + 1))) == NULL)
        return (ERROR);
    if ((fd = fopen(path, "r")) == NULL)
        return (ERROR);
    (*map)[height] = NULL;
    for (int i = 0 ; getline(&line, &len, fd) != -1 ; i += 1) {
        gene_line(line, pos, &((*map)[i]), &((*tower)[i]));
        pos.y += TILE_SIZE;
    }
    if (fclose(fd) != 0)
        return (ERROR);
    return (SUCCESS);
}

int load_map(char *path, my_sprite_t ***map, tower_t ***tower)
{
    int height = 0;
    sfTexture *texture = NULL;
    my_sprite_t **temp_map = NULL;

    if (verif_file(path, &height) == ERROR)
        return (ERROR);
    if (generate_map(path, height, &temp_map, tower) == ERROR) {
        mputerror("Error: can't generate map sprite\n");
        return (ERROR);
    }
    *map = temp_map;
    return (SUCCESS);
}
