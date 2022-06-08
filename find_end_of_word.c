#include "tokyu.h"

/* 語尾を抽出 */
void find_end_of_word(char *word, size_t size, char *next_word)
{
    // 初期化
    for (int i = 0; i < 3; i++)
        next_word[i] = '\0';

    if (check_vowel(word, size - 1))
    {
        if (check_vowel(word, size - 2)) // 駅名の最後が「あ行」の場合 => 1word
        {
            next_word[0] = word[size - 1] - 32;
        }
        else // 駅名の最後が「あ行」以外の場合 => 2word or 3word
        {
            if ((word[size - 2] == 'y' || word[size - 2] == 'h') && !check_vowel(word, size - 3)) // 3word ver
            {
                next_word[0] = word[size - 3] - 32;
                next_word[1] = word[size - 2];
                next_word[2] = word[size - 1];
            }
            else if (word[size - 3] == 't' && word[size - 2] == 's' && word[size - 1] == 'u') // "tsu" ver
            {
                next_word[0] = 't' - 32;
                next_word[1] = 's';
                next_word[2] = 'u';
            }
            else if (word[size - 1] == 'n') // しりとり終了
                ;
            else // 2word ver
            {
                next_word[0] = word[size - 2] - 32;
                next_word[1] = word[size - 1];
            }
        }
    }
}