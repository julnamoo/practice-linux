!#/bin/sh
sudo apt-get install -y thinkfiger-tools
echo "Start tf-tool\n"
tf-tool --acquire --verbose
tf-tool --verify --verbose

sudo apt-get install -y libthinkfinger-dev
echo "running thinkfinger example\n"
gcc list1431/list1431.c -o list1431/list1431 -lthinkfinger

echo "Please check *.bir file and running list1431\n"

sudo apt-get install -y libimobiledevice-dev libgpod
gcc list1432/list1432.c -o list1432/list1432 -limobiledevice
