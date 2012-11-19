#include <hid.h>
#include <stdio.h>

#define VENDOR_ID 0x0e0f;
#define PRODUCT_ID 0x0003;

int main(int argc, char* argv[]) {
  HIDInterface* hid = NULL;
  int if_no = 0;
  HIDInterfaceMatcher matcher = { VENDOR_ID, PRODUCT_ID, NULL, NULL, 0 };
  
  /* init */
  if (hid_init() != 0) {
    fprintf(stderr, "Cannot initialize HID Library\n");
    return 1;
  }

  /* create interface */
  if ((hid = hid_new_HIDInterface()) == NULL) {
    fprintf(stderr, "Cannot access HID interface\n");
    return 1;
  }

  /* open device */
  if (hid_force_open(hid, if_no, &matcher, 3) != 0) {
    fprintf(stderr, "Cannot open HID device\n");
    return 1;
  }

  /* print device info */
  if (hid_write_identification(stdout, hid) != 0) {
    fprintf(stderr, "Cannot write identification\n");
    return 1;
  }

  /* close device */
  if (hid_close(hid) != 0) {
    fprintf(stderr, "Cannot close HID device\n");
    return 1;
  }

  /* terminate */
  if (hid_cleanup() != 0) {
    fprintf(stderr, "Cannot cleanup HID library\n");
    return 1;
  }

  return 0;
}
