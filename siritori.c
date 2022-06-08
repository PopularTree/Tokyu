#include "tokyu.h"

static int used_check[N]; //同じ駅名は一度だけしか使うことができないと仮定する
static int loop;

int find_next_word(char *name, char **station, char *next_word, int i)
{
    find_end_of_word(name, strlen(name), next_word);
    if (next_word[0] != '\0')
    {
        for (int j = 0; j < N; j++)
        {
            if (i != j && used_check[j] && strncmp(next_word, station[j], strlen(next_word)) == 0)
            {
                loop++;
                printf("%s\n", station[j]);
                used_check[j] = 0;
                find_next_word(station[j], station, next_word, j);
            }
        }
    }
    return (loop);
}

int find_longest_siritori(char **station)
{
    int max;
    int tmp;
    int index;
    char next_word[3];

    max = 0;
    for (int i = 0; i < N; i++)
    {
        /* 初期化 */
        for (int j = 0; j < N; j++)
        {
            if (j == i)
                used_check[j] = 0;
            else
                used_check[j] = 1;
        }
        loop = 0;
        printf("%s\n", station[i]);
        tmp = find_next_word(station[i], station, next_word, i);
        if (tmp > max)
        {
            max = tmp;
            index = i;
        }
        printf("\n");
    }
    return (index);
}

void show_longest_pattern(char **station, int index)
{
    char next_word[3];
    /* 初期化 */
    for (int j = 0; j < N; j++)
    {
        if (j == index)
            used_check[j] = 0;
        else
            used_check[j] = 1;
    }
    printf("======== longest pattern ==========\n");
    printf("%s\n", station[index]);
    find_next_word(station[index], station, next_word, index);
}