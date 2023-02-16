// Uses Dynamic Programming
int min_of_three(int a, int b, int c) {
  if(a < b && a < c) return a;
  if(b < a && b < c) return b;
  return c;
}

int minDistance(char * word1, char * word2){
  int len1, len2, i, j;
  for(len1 = 0; word1[len1] != '\0'; len1++);
  for(len2 = 0; word2[len2] != '\0'; len2++);

  int min_d_mx[len1 + 1][len2 + 1];
  memset(min_d_mx, 0, sizeof(min_d_mx));

  //initial fills, separated because len1 might != len2 for some cases
  for(i = 1; i <= len1; i++)
    min_d_mx[i][0] = i;

  for(i = 1; i <= len2; i++)
    min_d_mx[0][i] = i;

  // the main cycling
  for(i = 1; i <= len1; i++)
    for(j = 1; j <= len2; j++) {
      min_d_mx[i][j] = min_of_three(min_d_mx[i - 1][j] + 1, min_d_mx[i][j - 1] + 1, word1[i - 1] != word2[j - 1] ? min_d_mx[i - 1][j - 1] + 1 : min_d_mx[i - 1][j - 1]);
    }
  
  return min_d_mx[len1][len2];
}