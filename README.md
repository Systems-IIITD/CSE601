install cmake and ninja by running,
sudo apt install cmake ninja-build
git clone https://github.com/piyus/CSE601.git
cd CSE601
mkdir build
cd build
cp ../scripts/build.sh .
sh build.sh
ninja
** it will take a while **
** after the build completes **
cd ../tests
make
