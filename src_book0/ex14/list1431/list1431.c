#include <libthinkfinger.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s BIR_FILE\n", argv[0]);
    return 1;
  }

  /* create auth object */
  libthinkfinger* tf;
  libthinkfinger_init_status init_status;
  if ((tf = libthinkfinger_new(&init_status)) == NULL) {
    fprintf(stderr, "Cannot create ThinkFinger handle:error code = %d\n",
        init_status);
    return 1;
  } 
  
  /* data set for authenticate */
  if (libthinkfinger_set_file(tf, argv[1] < 0)) {
    fprintf(stderr, "Cannot set file: %s\n", argv[1]);
    return 1;
  }

  /* authenticate */
  libthinkfinger_result result = libthinkfinger_verify(tf);

  switch(result) {
    case TF_STATE_VERIFY_SUCCESS :
      fprintf(stderr, "Fingerprint DOES match\n");
      break;
    case TF_STATE_VERIFY_FAILED :
      fprintf(stderr, "Fingerprint does NOT match\n");
      break;
    default :
      fprintf(stderr, "Something Wrong\n");
  }

  /* terminate */
  libthinkfinger_free(tf);
  return 0;
}
