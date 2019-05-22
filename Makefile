##
## EPITECH PROJECT, 2018
## MUL_my_defender_2018 | Makefile
## File description:
## Makefile
##

SRC	=	main.c					\
		defender.c				\
		base/set_base.c				\
		base/set_window.c			\
		gameloop/gameloop.c			\
		gameloop/free_gameloop.c		\
		gameloop/set/set_gameloop.c		\
		gameloop/set/load_map.c			\
		gameloop/set/set_map_sprite.c		\
		gameloop/set/tower_button.c		\
		gameloop/set/set_tower_preview.c	\
		gameloop/set/set_tower_texture.c	\
		gameloop/set/set_tool_bar.c		\
		gameloop/set/map_parser.c		\
		gameloop/set/tower_parser.c		\
		gameloop/set/set_pos_spawn.c		\
		gameloop/set/load_monster_texutre.c	\
		gameloop/set/set_portal.c		\
		gameloop/set/set_tower_info.c		\
		gameloop/set/set_music.c		\
		gameloop/event/event_gameloop.c		\
		gameloop/event/event_drag.c		\
		gameloop/event/move_drag_indicator.c	\
		gameloop/event/create_po.c		\
		gameloop/event/event_tower_click.c	\
		gameloop/event/event_upgrade.c		\
		gameloop/event/upgrade.c		\
		gameloop/data/data.c			\
		gameloop/data/move_monster.c		\
		gameloop/data/set_direction.c		\
		gameloop/data/set_pos_a_b.c		\
		gameloop/data/new_monster.c		\
		gameloop/data/die_monster.c		\
		gameloop/data/scale_button.c		\
		gameloop/data/spawn.c			\
		gameloop/data/despawn.c			\
		gameloop/data/tool_bar_data.c		\
		gameloop/animation/animation_gameloop.c	\
		gameloop/animation/animation_tower.c	\
		gameloop/animation/animation_map.c	\
		gameloop/animation/animation_monster.c	\
		gameloop/animation/animation_portal.c	\
		gameloop/display/display.c		\
		gameloop/display/display_drag.c		\
		gameloop/display/display_gui.c		\
		gameloop/display/display_map.c		\
		gameloop/display/display_monster.c	\
		gameloop/display/display_po.c		\
		gameloop/display/display_tower.c	\
		gameloop/display/display_portal.c	\
		gameloop/display/display_text.c		\
		gameloop/display/display_tower_info.c	\
		gameloop/tower/generate_tower.c		\
		gameloop/tower/load_data_tower.c	\
		gameloop/tower/tower_attack.c		\
		gameloop/tower/calcul_attack.c		\
		gameloop/tower/tower_calc.c		\
		gameloop/health_bar.c			\
		gameloop/pause_menu/pause_menu.c	\
		gameloop/pause_menu/pause_event.c	\
		tool/create_sprite.c			\
		tool/move_rect.c			\
		tool/ini_color.c			\
		tool/ini_rectangle.c			\
		tool/ini_rect.c				\
		tool/ini_vector.c			\
		tool/mstrlen.c				\
		tool/mputstr.c				\
		tool/time_to_second.c			\
		tool/button.c				\
		tool/ini_text.c				\
		tool/mitoa.c				\
		tool/str_cat.c				\
		tool/set_origin_text.c			\
		start_menu/start_menu.c			\
		start_menu/start_event.c		\
		start_menu/set_start_menu.c		\
		start_menu/free_start_menu.c		\
		start_menu/map_menu.c			\
		start_menu/how2play.c			\
		start_menu/map_event.c			\
		end_menu/end_menu.c			\
		end_menu/display_end_menu.c		\
		end_menu/end_event.c			\
		end_menu/end_anim.c			\
		end_menu/end_anim2.c			\
		end_menu/set_end_menu.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -lm

CSFML	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

NAME	=	my_defender

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(CSFML) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
