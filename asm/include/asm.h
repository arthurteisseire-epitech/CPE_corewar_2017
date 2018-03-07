/*
** EPITECH PROJECT, 2017
** File Name : asm.h
** File description:
** by Arthur Teisseire
*/

#ifndef ASM_H
#define ASM_H

#define FEND 42
#define NB_NOCBYTE 4
#define NB_INDEX 7
#define REG_CHAR 'r'
#define REV_BYTES(num)	((num & 0xff000000) >> 24) + \
			((num & 0x00ff0000) >> 8) + \
			((num & 0x0000ff00) << 8) + \
			((num & 0x000000ff) << 24)

typedef struct label {
	char *label;
	int line;
} label_t;

typedef struct token {
	char *str;
	int type;
	int cbyte;
	int nb_bytes;
} token_t;

typedef struct line {
	int index;
	int nb_bytes;
	int nb_tokens;
	int is_index;
	int is_label;
	token_t *tokens;
} line_t;

typedef struct buffer {
	line_t *line;
	label_t *label;
	int curr_byte;
	int nb_lines;
} buffer_t;

int my_asm(buffer_t *buffer, char *pathname);
int store_and_check_line(int fd, buffer_t *buffer, int index);
int set_line(line_t *line_data, char *line);
void init_buffer(buffer_t *buffer);
void set_token_bytes(line_t *line, token_t *token);
int set_tokens(line_t *line, char **tokens);

extern char const separators[3];

#endif
