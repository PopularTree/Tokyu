#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 97  // 東急線の全駅数
#define M 256 // 最大バイト数

static int used_check[N]; //同じ駅名は一度だけしか使うことができないと仮定する

/* 母音チェック */
/* テスト済み */
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

void find_next_word(char *name, char **station, char *next_word, int i)
{
  find_end_of_word(name, strlen(name), next_word);
  if (next_word[0] != '\0')
  {
    for (int j = 0; j < N; j++)
    {
      if (used_check[j] && strncmp(next_word, station[j], strlen(next_word)) == 0)
      {
        printf("%s\n", station[j]);
        used_check[j] = 0;
        find_next_word(station[j], station, next_word, j);
      }
    }
  }
}

int find_longest_siritori(char **station)
{
  char next_word[3];

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
    printf("%s\n", station[i]);
    find_next_word(station[i], station, next_word, i);
    printf("\n");
  }
}

int main(int argc, char **argv)
{
  int i, j;
  char c;
  char **station;
  FILE *fp;

  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    printf("file not found.\n");
    return (0);
  }

  /* 2次元の駅名配列を用意 */
  station = (char **)calloc(N, sizeof(char *));
  for (int i = 0; i < N; i++)
    station[i] = (char *)calloc(M, sizeof(char));

  i = 0;
  j = 0;
  while ((c = fgetc(fp)) != EOF)
  {
    if (c != '\n')
    {
      station[i][j] = c;
      j++;
    }
    else
    {
      j = 0;
      i++;
    }
  }

  find_longest_siritori(station);

  /* メモリの開放 */
  for (int i = 0; i < N; i++)
    free(station[i]);
  free(station);

  return (0);
}
