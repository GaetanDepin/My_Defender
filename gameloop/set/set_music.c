/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Set all the music
*/

#include "defender.h"

static const char *BUY = "resource/song/buy.ogg";
static const char *CLICK = "resource/song/click.ogg";
static const char *DIE = "resource/song/die.ogg";
static const char *TOOL = "resource/song/tool.ogg";
static const char *TOWER = "resource/song/tower.ogg";
static const char *TP = "resource/song/tp.ogg";
static const char *GAME_OVER = "resource/song/over.ogg";

void set_music(music_t *music)
{
    music->buy = sfMusic_createFromFile(BUY);
    music->click = sfMusic_createFromFile(CLICK);
    music->die = sfMusic_createFromFile(DIE);
    music->tool = sfMusic_createFromFile(TOOL);
    music->tower = sfMusic_createFromFile(TOWER);
    music->tp = sfMusic_createFromFile(TP);
    music->game_over = sfMusic_createFromFile(GAME_OVER);
}

void free_music(music_t music)
{
    sfMusic_destroy(music.buy);
    sfMusic_destroy(music.click);
    sfMusic_destroy(music.die);
    sfMusic_destroy(music.tool);
    sfMusic_destroy(music.tower);
    sfMusic_destroy(music.tp);
    sfMusic_destroy(music.game_over);
}
