/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** path
*/

#ifndef PATH_H_
#define PATH_H_

typedef struct img_data_s {
    const char *filepath;
    const int w;
    const int h;
    const int img_w;
    const int img_h;
} img_data_t;

static const char *IMG_BUTTON_TOWER = "resource/UI/TowerButton.png";
static const int BUTTON_TOWER_W = 114;
static const int BUTTON_TOWER_H = 133;
static const img_data_t POISON_IDLE = {"resource/Towers/poison_idle.png",
80, 144, 3440, 144};
static const img_data_t STORM_IDLE = {"resource/Towers/storm_idle.png",
80, 144, 1200, 144};
static const img_data_t ICE_IDLE = {"resource/Towers/ice_idle.png",
80, 144, 2800, 144};
static const img_data_t FIRE_IDLE = {"resource/Towers/fire_idle.png",
80, 144, 2160, 144};
static const img_data_t BUTTON_IMG = {"resource/UI/MenuButtons.png",
250, 109, 250, 328};
static const img_data_t IMG_THUMBNAIL = {"resource/UI/Thumbnail.png",
543, 238, 543, 238};

static const img_data_t BG_HEATLH_BAR = {"resource/UI/Healthbar.png",
70, 10, 70, 10};
static const img_data_t FR_HEATLH_BAR = {"resource/UI/HealthbarFront.png",
70, 10, 70, 10};

// Monster img
static const img_data_t MONSTER_BLUE_U = {"resource/Monsters/blue_up.png",
60, 79, 840, 79};
static const img_data_t MONSTER_BLUE_D = {"resource/Monsters/blue_down.png",
60, 79, 837, 79};
static const img_data_t MONSTER_BLUE_L = {"resource/Monsters/blue_left.png",
60, 79, 837, 79};
static const img_data_t MONSTER_BLUE_R = {"resource/Monsters/blue_right.png",
60, 79, 837, 79};
static const img_data_t MONSTER_BLUE_DEATH =
{"resource/Monsters/blue_death.png", 60, 29, 2040, 29};
static const img_data_t MONSTER_GREEN_U = {"resource/Monsters/green_up.png",
78, 80, 1092, 80};
static const img_data_t MONSTER_GREEN_D = {"resource/Monsters/green_down.png",
78, 80, 1092, 79};
static const img_data_t MONSTER_GREEN_L = {"resource/Monsters/green_left.png",
35, 80, 490, 80};
static const img_data_t MONSTER_GREEN_R = {"resource/Monsters/green_right.png",
35, 80, 490, 80};
static const img_data_t MONSTER_GREEN_DEATH =
{"resource/Monsters/green_death.png", 60, 29, 2040, 29};
static const img_data_t MONSTER_PURPLE_U = {"resource/Monsters/purple_up.png",
72, 69, 1008, 69};
static const img_data_t MONSTER_PURPLE_D = {"resource/Monsters/purple_down.png",
72, 69, 1008, 69};
static const img_data_t MONSTER_PURPLE_L = {"resource/Monsters/purple_left.png",
72, 69, 1008, 69};
static const img_data_t MONSTER_PURPLE_R =
{"resource/Monsters/purple_right.png", 72, 69, 1008, 69};
static const img_data_t MONSTER_PURPLE_DEATH =
{"resource/Monsters/purple_death.png", 60, 29, 2040, 29};
static const img_data_t MONSTER_RED_U = {"resource/Monsters/red_up.png",
70, 70, 980, 70};
static const img_data_t MONSTER_RED_D = {"resource/Monsters/red_down.png",
70, 70, 980, 70};
static const img_data_t MONSTER_RED_L = {"resource/Monsters/red_left.png",
70, 70, 980, 70};
static const img_data_t MONSTER_RED_R = {"resource/Monsters/red_right.png",
70, 70, 980, 70};
static const img_data_t MONSTER_RED_DEATH = {"resource/Monsters/red_death.png",
58, 28, 2040, 28};


#endif /* !PATH_H_ */
