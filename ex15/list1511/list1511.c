#include <barcode.h>

int main(int argc, char* argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s CODE_NO EPS_FILE\n", argv[0]);
    return 1;
  }

  struct Barcode_Item* bcode = Barcode_Create(argv[1]);
  if (bcode == NULL) {
    fprintf(stderr, "Can not create barcode: %s\n", argv[1]);
    return 1;
  }

  FILE* fp = NULL;
  if ((fp = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Can not open file: %s\n", argv[2]);
    return 1;
  }

  if (Barcode_Encode(bcode, BARCODE_ISBN) < 0) {
    fprintf(stderr, "Can not encode barcode\n");
    return 1;
  }

  if (Barcode_Print(bcode, fp, BARCODE_OUT_EPS) < 0) {
    fprintf(stderr, "Can not print barcode\n");
    return 1;
  }

  if (fclose(fp) != 0) {
    fprintf(stderr, "Can not close file\n");
    return 1;
  }

  Barcode_Delete(bcode);
  return 0;
}
