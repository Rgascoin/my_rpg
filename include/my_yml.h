/*
** EPITECH PROJECT, 2020
** RPG_NORM_MDR
** File description:
** my_yml
*/

#ifndef MY_YML_H_
#define MY_YML_H_

// Parser
void *get_function(const char *name, const char *data);
char *get_field(const char *name, const char *data);
bool load_audios(audios_t **audios, const char *path);
bool load_buttons(buttons_t **buttons, textures_t **textures, const char *path);
bool load_scene(scenes_t *scene, const char *path);
bool load_texts(texts_t **texts, const char *path);
bool load_textures(textures_t **textures, const char *path);
bool load_error_audio(audios_t *audio, const char **assets);
bool load_error_button(buttons_t *button, const char **assets);
bool load_error_text(texts_t *text, const char **assets);
bool load_error_texture(textures_t *texture, const char **assets);
#endif /* !MY_YML_H_ */
