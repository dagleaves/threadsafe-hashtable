[[ -e build/ ]] && rm -r build/
mkdir -p build/
cd build
cmake ..
make
cp src/mapper ../
cp test/MapperTests ../
