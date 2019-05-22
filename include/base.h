/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** header for base
*/

#ifndef BASE_H_
#define BASE_H_

static const int WINDOW_W = 1920;
static const int WINDOW_H = 1080;

typedef struct base_s {
    sfRenderWindow *window;
    sfMusic *music;
    char *path_map;
} base_t;

//Main function
int set_basic(base_t *base);

//Set functions
int set_window(sfRenderWindow **window);

#endif /* BASE_H_ */
