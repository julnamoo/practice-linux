// Julie Kim (julie114.kim@gmail.com)
// Simple program printing magic numbers of reboot systemcall.
// It prints hexadecimal values of magic numbers.
#include <stdio.h>
#include <linux/reboot.h>

int main(){
  printf("Print maginc numbers for reboot() syscal...\n");
  printf("LINUX_REBOOT_MAGIC1: %x\n", LINUX_REBOOT_MAGIC1);
  printf("LINUX_REBOOT_MAGIC2: %x: Linus Torvalds was born Dec.28, 1969\n", LINUX_REBOOT_MAGIC2);
  printf("Remains are birthdays of Linus's daughters..\n");
  printf("LINUX_REBOOT_MAGIC2A: %x: Patricia Miranda was born Dec.5 1996\n", LINUX_REBOOT_MAGIC2A);
  printf("LINUX_REBOOT_MAGIC2B: %x: Daniela Yolanada was born Apr.16 1998\n", LINUX_REBOOT_MAGIC2B);
  printf("LINUX_REBOOT_MAGIC2C: %x: Celeste Amanda was born Dec.12 2000\n", LINUX_REBOOT_MAGIC2C);

  return 0;
}
