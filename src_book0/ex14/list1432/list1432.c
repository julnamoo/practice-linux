#include <libimobiledevice/libimobiledevice.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  char** devices;
  idevice_t device;
  int i, count;

  /* get device list */
  if (idevice_get_device_list(&devices, &count) != 0) {
    fprintf(stderr, "Cannot get device list\n");
    return 1;
  }
  printf("%d device(s) found.\n", count);

  for (i = 0; i < count; ++i) {
    /* create device */
    if (idevice_new(&device, devices[i]) != 0) {
      fprintf(stderr, "Cannot create device[%s]\n", devices[i]);
      return 1;
    }

    printf("device %d [%s] is ready\n", i, devices[i]);

    /* release device */
    if (idevice_free(device) != 0) {
      fprintf(stderr, "Cannot free device[%s]\n", devices[i]);
      return 1;
    }
  }

  /* release device list */
  if (idevice_free(device) != 0) {
    fprintf(stderr, "Cannot free device list\n");
    return 1;
  }

  return 0;
}
