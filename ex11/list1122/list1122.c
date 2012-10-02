#include <stdio.h>
#include <stdlib.h>
#include <wand/MagickWand.h>

#define QUALITY 90

int main(int argc, char* argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s IN_FILE OUT_FILE", argv[0]);
    exit(1);
  }

  MagickWand* m_wand;
  int w, h;

  // Initialize
  MagickWandGenesis();
  m_wand = NewMagickWand();

  // read image
  if (MagickReadImage(m_wand, argv[1]) == MagickFalse) {
    fprintf(stderr, "Cannot read image: %s\n", argv[1]);
    exit(1);
  }
  w = MagickGetImageWidth(m_wand);
  h = MagickGetImageHeight(m_wand);

  // resize
  MagickResizeImage(m_wand, w/2, h/2, LanczosFilter, 1.0);
  MagickSetImageCompressionQuality(m_wand, QUALITY);

  // write image data to file
  if (MagickWriteImage(m_wand, argv[2]) == MagickFalse) {
    fprintf(stderr, "Cannot write image: %s\n", argv[2]);
    exit(1);
  }

  // finalize to finish
  if (m_wand) {
    m_wand = DestroyMagickWand(m_wand);
  }
  MagickWandTerminus();
  return 0;
}
