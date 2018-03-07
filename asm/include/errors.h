/*
** EPITECH PROJECT, 2017
** File Name : errors.h
** File description:
** Rémi BISSON 
*/

#ifndef ERRORS_H
#define ERRORS_H

//Errors that doesn't include a champion
#define NO_FILE "Usage: ./asm file_name[.s] ...."
#define FILE_NOT_EXISTING "Error in function open: No such file or directory."

//Errors in a champion

#define EMPTY_FILE "The file is empty."

//Problems with comments
#define NO_NAME "No name specified."
#define NO_COMMENT_W "Warning: No comment specified."
#define EMPTY_COMMENT "No comment specified."
#define MISPLACED_COMMENT "The comment must be just after the name."
#define MISPLACED_NAME "The name of your program must be the first line."
#define SYNTAX_ERROR "Syntax error."

//Problems with instructions
#define INVALID_INSTRUCTION "Invalid instruction.\n"
#define WRONG_INSTRUCT_ARG "The argument given to the instruction is invalid.\n"
#define WRONG_NB_ARGS "Too many arguments given to the instruction.\n"
#define WRONG_REGISTER_NB "Invalid register number.\n"
#define WRONG_LABEL "Undefined label.\n"

#endif
