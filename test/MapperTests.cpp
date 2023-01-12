/**
 * @author Daniel Gleaves
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <gtest/gtest.h>
#include "program.cpp"


TEST(MapperCorrectness, sample) {
    run("data/input/basicTests10.txt", "data/output/sample_out.txt");
    std::ifstream ifs("data/expected/basicTests10_expected.txt");
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2("data/output/sample_out.txt");
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, st_sample) {
    run("data/input/st_basicTests10.txt", "data/output/st_sample_out.txt");
    std::ifstream ifs("data/expected/st_basicTests10_expected.txt");
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2("data/output/st_sample_out.txt");
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, insertTests) {
    run("data/input/insertTests.txt", "data/output/insertTests_out.txt");
    std::ifstream ifs("data/expected/insertTests_expected.txt");
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2("data/output/insertTests_out.txt");
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, st_insertTests) {
    run("data/input/st_insertTests.txt", "data/output/st_insertTests_out.txt");
    std::ifstream ifs("data/expected/st_insertTests_expected.txt");
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2("data/output/st_insertTests_out.txt");
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, insertLookupTests) {
    run("data/input/insertLookupTests.txt", "data/output/insertLookupTests_out.txt");
    std::ifstream ifs("data/expected/insertLookupTests_expected.txt");
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2("data/output/insertLookupTests_out.txt");
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, st_insertLookupTests) {
    run("data/input/st_insertLookupTests.txt", "data/output/st_insertLookupTests_out.txt");
    std::ifstream ifs("data/expected/st_insertLookupTests_expected.txt");
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2("data/output/st_insertLookupTests_out.txt");
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, SingleThreadedReadHeavy) {
    std::string inp = "data/input/stRead.txt";
    std::string out = "data/output/st_read_output.txt";
    std::string exp = "data/expected/st_read_expected.txt";
    run(inp, out);
    std::ifstream ifs(exp);
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2(out);
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, MultiThreadedReadHeavy) {
    std::string inp = "data/input/read.txt";
    std::string out = "data/output/read_output.txt";
    std::string exp = "data/expected/read_expected.txt";
    run(inp, out);
    std::ifstream ifs(exp);
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2(out);
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, SingleThreadedWriteHeavy) {
    std::string inp = "data/input/st_write.txt";
    std::string out = "data/output/st_write_output.txt";
    std::string exp = "data/expected/st_write_expected.txt";
    run(inp, out);
    std::ifstream ifs(exp);
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2(out);
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, MultiThreadedWriteHeavy) {
    std::string inp = "data/input/write.txt";
    std::string out = "data/output/write_output.txt";
    std::string exp = "data/expected/write_expected.txt";
    run(inp, out);
    std::ifstream ifs(exp);
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2(out);
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, SingleThreadedAlternatingCommands) {
    std::string inp = "data/input/st_alternating.txt";
    std::string out = "data/output/st_alternating_output.txt";
    std::string exp = "data/expected/st_alternating_expected.txt";
    run(inp, out);
    std::ifstream ifs(exp);
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2(out);
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, MultiThreadedAlternatingCommands) {
    std::string inp = "data/input/alternating.txt";
    std::string out = "data/output/alternating_output.txt";
    std::string exp = "data/expected/alternating_expected.txt";
    run(inp, out);
    std::ifstream ifs(exp);
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2(out);
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, SingleThreadedLarge) {
    std::string inp = "data/input/stLarge.txt";
    std::string out = "data/output/st_large.txt";
    std::string exp = "data/expected/st_large_expected.txt";
    run(inp, out);
    std::ifstream ifs(exp);
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2(out);
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

TEST(MapperCorrectness, MultiThreadedLarge) {
    std::string inp = "data/input/large.txt";
    std::string out = "data/output/large_output.txt";
    std::string exp = "data/expected/large_expected.txt";
    run(inp, out);
    std::ifstream ifs(exp);
    std::string output;
    output.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    std::ifstream ifs2(out);
    std::string expectedOutput;
    expectedOutput.assign((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));

    EXPECT_TRUE(output == expectedOutput);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
