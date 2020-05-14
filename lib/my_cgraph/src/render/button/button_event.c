/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Button Event Management
*/

#include "my_cgraph.h"

bool button_is_clicked(sfRenderWindow *win, buttons_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);
    sfVector2f btn_pos = sfRectangleShape_getPosition(button->sf_rect);
    sfVector2f btn_size = sfRectangleShape_getSize(button->sf_rect);

    return (((mouse_pos.x >= btn_pos.x && mouse_pos.x <= btn_pos.x + btn_size.x)
        && (mouse_pos.y >= btn_pos.y
        && mouse_pos.y <= btn_pos.y + btn_size.y)));
}

bool button_is_hover(sfRenderWindow *win, buttons_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);
    sfVector2f btn_pos = sfRectangleShape_getPosition(button->sf_rect);
    sfVector2f btn_size = sfRectangleShape_getSize(button->sf_rect);

    return (((mouse_pos.x >= btn_pos.x && mouse_pos.x <= btn_pos.x + btn_size.x)
        && (mouse_pos.y >= btn_pos.y
        && mouse_pos.y <= btn_pos.y + btn_size.y)));
}
