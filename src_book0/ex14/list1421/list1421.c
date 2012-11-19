#include <usb.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  usb_init();

  /* get the number of busses and devices */
  int busses = usb_find_busses();
  int devices = usb_find_devices();

  printf("# of bus: %d, # of devices: %d\n", busses, devices);

  /* get list of busses and find device */
  struct usb_bus* bus = usb_get_busses();
  while (bus != NULL) {
    struct usb_device* device = bus->devices;
    while (device != NULL) {
      /* print bus and device */
      printf("Bus %s Device %s : ID %04x:%04x\n",
          bus->dirname, device->filename,
          device->descriptor.idVendor,
          device->descriptor.idProduct);
      device = device->next;
    }
    bus = bus->next;
  }

  return 0;
}
