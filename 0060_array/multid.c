#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned char (*p2)[3];
  unsigned char *p1;
  int i, j;

  p2 = (unsigned char (*)[3])malloc(4*3*sizeof(unsigned char));
  p1 = (unsigned char *)p2;

  for (i = 0; i < 12; i++) {
    p1[i] = (unsigned char)i;
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf("(i,j)=(%d,%d) %d %p\n", i, j, p2[i][j], p2[i]);
    }
  }

  free(p2);

  return 0;
}
