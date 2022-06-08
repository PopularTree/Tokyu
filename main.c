#include "tokyu.h"

int main(int argc, char **argv)
{
  int i, j, index;
  char c;
  char **station;
  FILE *fp;

  fp = fopen(argv[argc - 1], "r");
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

  index = find_longest_siritori(station);

  show_longest_pattern(station, index);

  /* メモリの開放 */
  for (int i = 0; i < N; i++)
    free(station[i]);
  free(station);

  return (0);
}
