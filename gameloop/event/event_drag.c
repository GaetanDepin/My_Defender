/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Drag and drop function use during event
*/

#include "defender.h"

static int switch_tower_button(gameloop_t *gameloop, int index)
{
    sfIntRect rect;
    sfVector2f pos;

    gameloop->drag = true;
    gameloop->select_tower = index;
    sfSprite_setTexture(gameloop->drag_tower.sprite,
    gameloop->tower_texture[index].texture, sfTrue);
    gameloop->drag_tower.w = gameloop->tower_texture[index].w;
    gameloop->drag_tower.max_x = gameloop->tower_texture[index].max_w;
    rect = ini_rect(0, 0, gameloop->tower_texture[index].w,
    gameloop->tower_texture[index].h);
    gameloop->drag_tower.rect = rect;
    pos = ini_vector(rect.width / 2, rect.height * 2 / 3);
    sfSprite_setOrigin(gameloop->drag_tower.sprite, pos);
    sfSprite_setTextureRect(gameloop->drag_tower.sprite, rect);
}

int mouse_pressed_drag(gameloop_t *gameloop, sfMouseButtonEvent mouse)
{
    sfFloatRect rect;
    my_sprite_t *button = gameloop->button_tower;

    for (int i = 0 ; button[i].sprite != NULL && i < 4 ; i++) {
        rect = sfSprite_getGlobalBounds(button[i].sprite);
        if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
            switch_tower_button(gameloop, i);
            return (1);
        }
    }
    return (SUCCESS);
}

int mouse_move_drag(sfRenderWindow *win, gameloop_t *gameloop)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfVector2f pos;

    if (gameloop->drag == true) {
        pos = ini_vector(mouse.x, mouse.y);
        sfSprite_setPosition(gameloop->drag_tower.sprite, pos);
        move_drag_indicator(gameloop, pos);
    }
    return (SUCCESS);
}

int mouse_released_drag(gameloop_t *gameloop, sfMouseMoveEvent event)
{
    if (gameloop->drag == true) {
        generate_tower(gameloop);
    }
    gameloop->drag = false;
    return (SUCCESS);
}
