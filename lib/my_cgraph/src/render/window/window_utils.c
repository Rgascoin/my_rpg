/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Window Utils Management
*/

#include "my_cgraph.h"

bool set_window_icon(sfRenderWindow *win, const char *icon)
{
    sfImage *image = sfImage_createFromFile(icon);
    sfVector2u img_size = sfImage_getSize(image);
    const sfUint8 *img_pixels = sfImage_getPixelsPtr(image);

    if (!win)
        return (false);
    sfRenderWindow_setIcon(win, img_size.x, img_size.y, img_pixels);
    return (true);
}

bool set_mouse_cursor(sfRenderWindow *win, textures_t *texture)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);
    sfVector2f pos = {mouse_pos.x, mouse_pos.y};

    if (!win || !texture)
        return (false);
    set_texture_visible(texture, true);
    sfRenderWindow_setMouseCursorVisible(win, sfFalse);
    sfSprite_setPosition(texture->sf_sprite, pos);
    return (true);
}
