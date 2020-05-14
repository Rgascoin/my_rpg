/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Button Utils Management
*/

#include "my_cgraph.h"

bool init_button(buttons_t *button, sfVector2f pos, sfVector2f size,
    void *callback)
{
    if (!button)
        return (false);
    sfRectangleShape_setPosition(button->sf_rect, pos);
    sfRectangleShape_setSize(button->sf_rect, size);
    button->callback = callback;
    return (true);
}

bool set_button_outline(buttons_t *button, sfColor color, int thickness)
{
    if (!button)
        return (false);
    sfRectangleShape_setOutlineThickness(button->sf_rect, thickness);
    sfRectangleShape_setOutlineColor(button->sf_rect, color);
    return (true);
}

bool set_button_texture(buttons_t *button, textures_t *texture)
{
    if (!button || !texture)
        return (false);
    sfRectangleShape_setTexture(button->sf_rect, texture->sf_texture, sfTrue);
    return (true);
}

bool set_button_text(buttons_t *button, texts_t *text, const char *str)
{
    sfFloatRect text_pos;
    sfVector2f text_newpos;
    sfVector2f btn_size;

    if (!button || !text)
        return (false);
    btn_size = sfRectangleShape_getSize(button->sf_rect);
    sfText_setString(text->sf_text, str);
    text_pos = sfText_getGlobalBounds(text->sf_text);
    text_newpos.x = (btn_size.x / 2) - (text_pos.width / 3);
    text_newpos.y = text_pos.height + (btn_size.y / 2);
    sfText_setPosition(text->sf_text, text_newpos);
    sfText_setString(text->sf_text, str);
    button->text = text;
    return (true);
}

int count_buttons(buttons_t *buttons)
{
    int count = 0;
    buttons_t *element = buttons;

    while (element != NULL) {
        count++;
        element = element->next;
    }
    return (count);
}
