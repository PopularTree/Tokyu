#include "tokyu.h"

/* 母音チェック */
int check_vowel(char *word, size_t size)
{
    if (word[size] == 'a')
        return (1);
    else if (word[size] == 'i')
        return (1);
    else if (word[size] == 'u')
        return (1);
    else if (word[size] == 'e')
        return (1);
    else if (word[size] == 'o')
        return (1);
    else
        return (0);
}