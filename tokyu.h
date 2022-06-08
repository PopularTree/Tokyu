#ifndef TOKYU_H
#define TOKYU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 97  // 東急線の全駅数
#define M 256 // 最大バイト数

int check_vowel(char *word, size_t size);
void find_end_of_word(char *word, size_t size, char *next_word);
int find_next_word(char *name, char **station, char *next_word, int i);
int find_longest_siritori(char **station);
void show_longest_pattern(char **station, int index);

#endif