#include <popt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
  int opt;
  char* greeting = "Hello, ";
  char* target = "world";
  poptContext optCon;

  struct poptOption optionTable[] = {
    {"bye", 'b', POPT_ARG_NONE, NULL, 'b', "say good-bye", NULL},
    {"name", 'n', POPT_ARG_STRING, &target, 'n', "greeting to <NAME>", "NAME"},
    POPT_AUTOHELP
    POPT_TABLEEND
  };

  optCon = poptGetContext(NULL, argc, argv, optionTable, 0);
  poptSetOtherOptionHelp(optCon, "[OPTIONS]*");

  while ( (opt = poptGetNextOpt(optCon)) >= 0){
    switch (opt) {
      case 'b':
        greeting = "Good bye, ";
        break;
      case 'n': break;
      default: return EXIT_FAILURE;
    }
  }
  printf("%s%s!\n", greeting, target);
  return EXIT_SUCCESS;
}
