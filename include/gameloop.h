/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** gameloop
*/

#ifndef GAMELOOP_H_
#define GAMELOOP_H_

typedef struct my_sprite_s {
    sfSprite *sprite;
    sfIntRect rect;
    int type;
    bool solid;
    bool animation;
    int w;
    int max_x;
} my_sprite_t;

typedef struct health_bar_s {
    sfTexture *bg_texture;
    sfSprite *bg;
    sfTexture *fr_texture;
    sfSprite *front;
    sfRectangleShape *bar;
} health_bar_t;

typedef struct monster_s {
    my_sprite_t sprite;
    sfTexture *texture;
    bool alive;
    char type;
    char dir;
    int hp;
    int max_hp;
    int gold;
    int score;
    sfVector2i center;
    float speed;
    int slow;
    health_bar_t heatlh_bar;
    struct monster_s *next;
} monster_t;

typedef struct my_texture_s {
    sfTexture *texture;
    int w;
    int h;
    int max_w;
} my_texture_t;

/*
Attack speed : time between each attack
radius : distance in block around the tower
*/
typedef struct tower_s {
    my_sprite_t sprite;
    char type;
    int damage;
    int up;
    int slow;
    int lvl;
    int sell;
    bool is_empty;
    sfClock *attack_clock;
    float attack_speed;
    float radius;
    sfRectangleShape *po;
} tower_t;

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *bg;
    sfText *text;
    sfIntRect rect;
    float scale;
} button_t;

typedef struct anim_texture_s {
    sfTexture *texture;
    int w;
    int max_w;
    int h;
} anim_texture_t;

typedef struct text_s {
    int nb;
    sfFont *font;
    sfText *text;
} text_t;

typedef struct tower_info_s {
    text_t txt_attack;
    text_t txt_range;
    text_t txt_atk_spd;
    text_t txt_slow;
    text_t txt_level;
    sfVector2i select;
} tower_info_t;

typedef struct music_s {
    sfMusic *buy;
    sfMusic *click;
    sfMusic *die;
    sfMusic *tool;
    sfMusic *tower;
    sfMusic *tp;
    sfMusic *game_over;
} music_t;

//Main gameloop structure
typedef struct gameloop_s {
    sfRenderWindow *window;
    monster_t *monster;
    sfClock *spawn_clock;
    music_t music;
    text_t hp;
    text_t gold;
    text_t score;
    my_sprite_t **map;
    my_sprite_t *button_tower;
    my_sprite_t drag_tower;
    my_sprite_t tool_bar;
    my_sprite_t portal1;
    my_sprite_t portal2;
    sfVector2f pos_spawn;
    bool drag;
    int select_tower;
    my_texture_t *tower_texture;
    sfRectangleShape *pos_tower;
    tower_t **tower_map;
    sfClock *anim_clock;
    anim_texture_t *monster_tex;
    tower_info_t tower_info;
    int status;
    float time_monster;
    float live_multi;
} gameloop_t;

//Main function
int gameloop(sfRenderWindow *win, char *path_map);

//Set
int set_gameloop(char *path_map, gameloop_t *gameloop);
int load_map(char *path, my_sprite_t ***map, tower_t ***tower);
int map_parser(sfVector2f pos, char flag, my_sprite_t *sprite);
int tower_parser(char flag, tower_t *tower);
my_sprite_t *set_tower_button(void);
my_sprite_t set_tower_preview(void);
my_texture_t *set_tower_texture(void);
int set_tool_bar(my_sprite_t *tool_bar);
sfVector2f set_pos_spawn(my_sprite_t **map);
anim_texture_t *load_monster_texture(void);
my_sprite_t set_portal(my_sprite_t **map, int mode);
void set_music(music_t *music);

//Map element
my_sprite_t set_grass1(sfVector2f pos);
my_sprite_t set_grass2(sfVector2f pos);
my_sprite_t set_ground(sfVector2f pos);
my_sprite_t set_portal1(sfVector2f pos);
my_sprite_t set_portal2(sfVector2f pos);

//Event
int event_gameloop(gameloop_t *gameloop, sfEvent event);
int mouse_pressed_drag(gameloop_t *gameloop, sfMouseButtonEvent mouse);
int mouse_move_drag(sfRenderWindow *win, gameloop_t *gameloop);
int move_drag_indicator(gameloop_t *gameloop, sfVector2f mouse);
int mouse_released_drag(gameloop_t *gameloop, sfMouseMoveEvent event);
sfRectangleShape *create_po(int po, sfColor color, sfSprite *sprite);
int event_tower_click(gameloop_t *gameloop, sfMouseButtonEvent mouse);
int event_upgrade(gameloop_t *gameloop, sfMouseButtonEvent mouse);
void reset_tower_info(tower_info_t info);
void change_tower_info(tower_info_t info, tower_t tower);
int parser_upgrade(gameloop_t *gameloop, tower_t *tower);

//Data
int data(gameloop_t *gameloop);
void spawn(gameloop_t *gameloop);
monster_t *new_monster(sfVector2f pos, monster_t *llist, anim_texture_t *tex);
void move_monster(gameloop_t *gameloop);
void die_monster(gameloop_t *gameloop, monster_t **monst_l, anim_texture_t *t);
void scale_button(gameloop_t *gameloop);
void tool_bar_data(gameloop_t *gameloop);
void remove_monster(monster_t **monst, monster_t *prev, monster_t **lis);
void despawn(gameloop_t *gameloop);
void set_dir(monster_t *, anim_texture_t *, my_sprite_t **, sfVector2i);
sfVector2i set_pa(sfVector2f pos, sfVector2i c);
sfVector2i set_pb(sfVector2f pos, sfVector2i c);

//Animation
int animation_gameloop(gameloop_t *gameloop);
int animation_tower(gameloop_t *game_data);
int animation_map(my_sprite_t **map);
void animate_monster(monster_t *monster);
int animation_portal(my_sprite_t *portal1, my_sprite_t *portal2);

//Dislay
int display_gameloop(gameloop_t *gameloop);
int display_map(sfRenderWindow *window, my_sprite_t **sprite, tower_t **tower);
int display_gui(gameloop_t *gameloop);
void display_drag(gameloop_t *gameloop);
void display_monster(gameloop_t *gameloop);
int display_po(sfRenderWindow *window, my_sprite_t **sprite, tower_t **tower);
void display_portal(gameloop_t *gameloop);
int display_twr(sfRenderWindow *window, my_sprite_t **sprite, tower_t **tower);
void display_tower_info(sfRenderWindow *win, tower_info_t info);
void display_text(gameloop_t *gameloop);

// Tower
int generate_tower(gameloop_t *gameloop);
int tower_attack(tower_t **tower, monster_t *monster);
void load_data_tower(gameloop_t *gameloop, int x, int y);
void ice_attack(tower_t *tower, monster_t *monster);
void poison_attack(tower_t *tower, monster_t *monster);
void storm_attack(tower_t *tower, monster_t *monster);
void fire_attack(tower_t *tower, monster_t *monster);
int tower_a(float time, float attack);
int get_monster_speed(int tower, int monster);

// Health bar
health_bar_t set_health_bar(void);
void display_health_bar(sfRenderWindow *win, health_bar_t bar);
void move_health_bar(health_bar_t bar, sfVector2f pos);
void update_health_bar(health_bar_t bar, int value, int max_value);
void free_health_bar(health_bar_t bar);

// Tower info
int set_tower_info(tower_info_t *tower_info);

// Free
void free_gameloop(gameloop_t gameloop);
void free_tower(tower_t tower);
void free_music(music_t music);

// Pause menu
int pause_menu(sfRenderWindow *win, int *status);

#endif /* !GAMELOOP_H_ */
