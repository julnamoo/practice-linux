# Julie Kim (julie114.kim@gmail.com)
# Build tlpi_hdr.h
echo "Build *.c"
gcc -Wall -fPIC -c error_functions.c get_num.c
echo "Build libtlpi_hdr.so"
gcc -shared -Wl,-soname,libtlpi_hdr.so -o libtlpi_hdr.so *.o
echo "Move libtlpi_hdr.so to /usr/lib"
sudo cp libtlpi_hdr.so /usr/lib
