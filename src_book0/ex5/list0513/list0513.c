#include <dlfcn.h>

int main() {
  void* handle = dlopen("./list0513.so", RTLD_LAZY);
  void (*func)(void) = dlsym(handle, "function");
  (*func)();
  dlclose(handle);
  return 0;
}
