#include <stdio.h>
#include <linux/reboot.h>

int main(){
  printf("Print maginc numbers for reboot() syscal...\n");
  printf("LINUX_REBOOT_MAGIC1: %x\n", LINUX_REBOOT_MAGIC1);
  printf("LINUX_REBOOT_MAGIC2: %x\n", LINUX_REBOOT_MAGIC2);
  printf("LINUX_REBOOT_MAGIC2A: %x\n", LINUX_REBOOT_MAGIC2A);
  printf("LINUX_REBOOT_MAGIC2B: %x\n", LINUX_REBOOT_MAGIC2B);
  printf("LINUX_REBOOT_MAGIC2C: %x\n", LINUX_REBOOT_MAGIC2C);

  return 0;
}
