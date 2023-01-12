/**
 * @author Daniel Gleaves
*/
#include "program.cpp"

int main(int argc, char **argv) {
    assert((argc == 3) && "Must provide input and output filenames");
    run(argv[1], argv[2]);
    return(0);
}
