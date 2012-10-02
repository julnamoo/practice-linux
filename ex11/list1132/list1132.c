#include <stdio.h>
#include <stdlib.h>
#include <wand/MagickWand.h>
#include <aalib.h>

#define WIDTH 160
#define HEIGHT 50

int main(int argc, char* argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s IN_FILE OUT_FILE", argv[0]);
    exit(1);
  }

  MagickWand* m_wand;

  // Initialize
  MagickWandGenesis();
  m_wand = NewMagickWand();

  // read image
  if (MagickReadImage(m_wand, argv[1]) == MagickFalse) {
    fprintf(stderr, "Cannot read image: %s\n", argv[1]);
    exit(1);
  }

  // resize
  MagickResizeImage(m_wand, WIDTH, HEIGHT, LanczosFilter, 1.0);

  // ready for using AAlib
  aa_context* c;
  aa_savedata save_data = {
    argv[2],
    &aa_text_format,
    NULL
  };
  // Initialize AAlib
  c = aa_init(&save_d, &aa_defparams, (const void*) &save_data);
  if (c == NULL) {
    fprintf(stderr, "Cannot initialize AA-lib\n");
    exit(1);
  }

  // record image data to AAlib image buffer
  PixelIterator* iter = NewPixelIterator(m_wand);
  PixelWand** pix;
  unsigned long num_wands;
  double h, s, l;
  int x, y;

  y = 0;
  while ((pix = PixelGetNextIteratorRow(iter, &num_wands)) != NULL) {
    for (x = 0; x < num_wands; ++x) {
      PixelGetHSL(pix[x], &h, &s, &l);
      aa_putpixel(c, x, y, 256*l);
    }
    y++;
  }

  // rendering ascii and print file
  aa_fastrender(c, 0, 0, aa_scrwidth(c), aa_scrheight(c));
  aa_flush(c);

  // terminate
  aa_close(c);

  // finalize to finish
  if (m_wand) {
    m_wand = DestroyMagickWand(m_wand);
  }
  MagickWandTerminus();
  return 0;
}
