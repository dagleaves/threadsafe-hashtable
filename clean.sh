find . -type d -name "lib" -prune -exec rm -rf {} \;
find . -type d -name "CMakeFiles" -prune -exec rm -rf {} \;
find . -type d -name "_deps" -prune -exec rm -rf {} \;

find . -name "*.cmake" | xargs rm
find . -name "BSTTests" | xargs rm
find . -name "NodeTests" | xargs rm
find . -name "Makefile" | xargs rm
find . -name "CMakeCache.txt" | xargs rm
