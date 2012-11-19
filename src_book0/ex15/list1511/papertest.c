#include <paper.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  const struct paper* p = NULL;

  printf("Default paper name is %s]n", defaultpapername());
  printf("System paper name is %s]n", systempapername());
  printf("Default size file is %s]n", defaultpapersizefile());
  printf("System size file is %s]n", systempapersizefile());

  if ((p = paperinfo(argv[1])) == NULL) {
    fprintf(stderr, "Can not find paper %s \n", argv[1]);
    return 1;
  }

  printf("------------------\nPaper \"%s\":\n", papername(p));
  printf("\twidth:%6.3f pt\n", paperpswidth(p));
  printf("\theight:%6.3f pt\n", paperpsheight(p));

  return 0;
}
