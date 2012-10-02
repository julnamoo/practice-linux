#include <stdio.h>
#include <unicap.h>

#define FRAME_COUNT 5

static unicap_data_buffer_t* buf = NULL;

static void callback_func(unicap_event_t event, unicap_handle_t handle,
    unicap_data_buffer_t* buffer, void* data) {
  int *frame_count = (int *) data;
  (*frame_count)--;
  fprintf(stderr, "Captured!\n");

    buf = buffer;
}

int main(int argc, char* argv[]) {
  unicap_handle_t handle;
  unicap_device_t device;
  unicap_format_t format;
  int frame_count = FRAME_COUNT;

  /* search the device */
  if (unicap_enumerate_devices(NULL, &device, 0) != 0) {
    fprintf(stderr, "Camera not found\n");
    return 1;
  }

  /* open the device */
  if (unicap_open(&handle, &device) != 0) {
    fprintf(stderr, "Cannot open device: %s\n", device.identifier);
    return 1;
  }

  /* get format of video */
  if (unicap_enumerate_formats(handle, NULL, &format, 0) != 0) {
    fprintf(stderr, "Cannot get video format\n");
    return 1;
  }

  /* adjust format data and set up video format */
  if (format.size_count > 0) {
    format.size.width = format.sizes[0].width;
    format.size.height = format.sizes[0].height;
  }
  format.buffer_type = UNICAP_BUFFER_TYPE_SYSTEM;

  if (unicap_set_format(handle, &format) != 0) {
    fprintf(stderr, "Cannot set video format\n");
    return 1;
  }

  /* register call back funcs */
  if (unicap_register_callback(handle, UNICAP_EVENT_NEW_FRAME,
        (unicap_callback_t) callback_func,
        (void *) &frame_count) != 0) {
    fprintf(stderr, "Cannot register callback function\n");
    return 1;
  }

  /* start captuer */
  if (unicap_start_capture(handle) != 0) {
    fprintf(stderr, "Cannot start process\n");
    return 1;
  }

  /* sleep while capture some frames */
  while (frame_count > 0) {
    usleep(100000);
  }

  /* stop capture */
  if (unicap_stop_capture(handle) != 0) {
    fprintf(stderr, "Cannot stop capture process\n");
    return 1;
  }

  /* close device */
  if (unicap_close(handle) != 0) {
    fprintf(stderr, "Cannot close device: %s\n", device.identifier);
    return 1;
  }

  fprintf(stderr, "[Image data]\nwidth:\t%d\nheight:\t%d\nbpp:\t%d\n",
      format.size.width, format.size.height, format.bpp);
  fprintf(stderr, "FOURCC:\t%c%c%c%c\nBufferSize:\t%d\n",
      format.fourcc & 0xff, (format.fourcc >> 8) & 0xff, 
      (format.fourcc >> 16) & 0xff, (format.fourcc >> 24) & 0xff,
      format.buffer_size);

  return 0;
}
