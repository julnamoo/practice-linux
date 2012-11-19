#include <qrencode.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s STRING\n", argv[0]);
    return 1;
  }

  QRcode* qrcode = QRcode_encodeString8bit(argv[1], 0, QR_ECLEVEL_L);

  int width = qrcode->width;
  int x, y, i = 0;
  unsigned char* data = qrcode->data;

  printf("P1\n%d %d\n", width, width);
  for (y = 0; y < width; ++y) {
    for (x = 0; x < width; ++x, ++data) {
      printf((data[i] & 1) ? "1" : "0");
    }
    printf("\n");
  }

  QRcode_free(qrcode);

  return 0;
}
