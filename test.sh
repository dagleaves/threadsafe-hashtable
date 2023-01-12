[[ -e build/ ]] && rm -r build/
mkdir build/
cd build
cmake ..
make
cp test/MapperTests ../