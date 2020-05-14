/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** C Graphical Header
*/

#ifndef MY_CGRAPH_H
#define MY_CGRAPH_H
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

#ifndef MY_CGRAPH_STRUCT_H
#define MY_CGRAPH_STRUCT_H
typedef struct audios_s
{
    const char *name;
    sfMusic *sf_music;
    struct audios_s *next;
} audios_t;

typedef struct texts_s
{
    const char *name;
    sfFont *sf_font;
    sfText *sf_text;
    struct texts_s *next;
} texts_t;

typedef struct textures_s
{
    const char *name;
    const char *tag;
    bool visible;
    sfTexture *sf_texture;
    sfSprite *sf_sprite;
    sfClock *sf_clock;
    float time;
    struct textures_s *next;
} textures_t;

typedef struct buttons_s
{
    const char *name;
    void (*callback)();
    texts_t *text;
    sfRectangleShape *sf_rect;
    struct buttons_s *next;
} buttons_t;

typedef struct scenes_s
{
    const char *name;
    audios_t *audios;
    buttons_t *buttons;
    texts_t *texts;
    textures_t *textures;
    struct scenes_s *next;
} scenes_t;
#endif
void animate_sprite(sfSprite *sprite, int offset, int max);
bool create_audio(audios_t **audios, const char *name, const char *path);
audios_t *get_audio(audios_t *audios, const char *name);
bool destroy_audio(audios_t **audios, const char *name);
bool create_button(buttons_t **buttons, const char *name);
buttons_t *get_button(buttons_t *buttons, const char *name);
void draw_buttons(sfRenderWindow *win, buttons_t *buttons);
bool destroy_button(buttons_t **buttons, const char *name);
bool button_is_clicked(sfRenderWindow *win, buttons_t *button);
bool button_is_hover(sfRenderWindow *win, buttons_t *button);
bool init_button(buttons_t *button, sfVector2f pos, sfVector2f size,
    void *callback);
bool set_button_outline(buttons_t *button, sfColor color, int thickness);
bool set_button_texture(buttons_t *button, textures_t *texture);
bool set_button_text(buttons_t *button, texts_t *text, const char *str);
int count_buttons(buttons_t *buttons);
bool create_text(texts_t **texts, const char *name, const char *font);
texts_t *get_text(texts_t *texts, const char *name);
void draw_texts(sfRenderWindow *win, texts_t *texts);
bool destroy_text(texts_t **texts, const char *name);
bool init_text(texts_t *text, sfVector2f pos, const char *str);
int count_texts(texts_t *texts);
bool create_texture(textures_t **textures, const char *name, const char *path);
bool init_texture(textures_t *texture, sfVector2f pos, bool visible,
    const char *tag);
textures_t *get_texture(textures_t *textures, const char *name);
void draw_textures(sfRenderWindow *win, textures_t *textures);
bool destroy_texture(textures_t **textures, const char *name);
bool set_texture_visible(textures_t *texture, bool visible);
bool set_tag(textures_t *texture, const char *tag);
int count_textures(textures_t *textures);
bool create_scene(scenes_t **scenes, const char *name);
scenes_t *get_scene(scenes_t *scenes, const char *name);
void draw_scene(sfRenderWindow *win, scenes_t *scene);
bool destroy_scene(scenes_t **scenes, const char *name);
int count_scenes(scenes_t *scenes);
sfRenderWindow *create_window(const char *title, int width, int height);
bool destroy_window(sfRenderWindow *win);
bool set_window_icon(sfRenderWindow *win, const char *icon);
bool set_mouse_cursor(sfRenderWindow *win, textures_t *texture);
bool is_in_collision(sfRectangleShape *rect, sfCircleShape *circle);
void *get_function(const char *name, const char *data);
char *get_field(const char *name, const char *data);
#endif
