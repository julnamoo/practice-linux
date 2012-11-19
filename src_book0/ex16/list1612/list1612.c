#define swap(x, y) { int v; v = x; x = y; y = v; }

void sort (int a[], int n) {
  int i, j;
  for (i = 0; i < n-1; i++) {
    for ( j = n-1; j > i; j--) {
      if (a[j-1] > a[j]) swap(a[j], a[j-1]);
    }
  }
}
