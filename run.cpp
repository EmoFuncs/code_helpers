#include <cassert>
#include "cmd_tools.h"
#include <tclap/CmdLine.h>
using namespace std;

// try to commit
int main(int argc, char *argv[]) {
    try {
        TCLAP::CmdLine parser("compile and run programs", ' ', "0.1");

        TCLAP::UnlabeledValueArg<string> problem_id_arg("id", "The id of program you want to complile and run", true, "", "string", parser);
        TCLAP::ValueArg<string> input_file_arg("i", "in", "Input file", false, "", "string", parser);
        TCLAP::ValueArg<string> output_file_arg("o", "out", "Output file", false, "", "string", parser);

        parser.parse(argc, argv);

        string problem_id = problem_id_arg.getValue();
        string input_file = input_file_arg.getValue();
        string output_file = output_file_arg.getValue();

        command_line_tool cmd;

        cmd.execute("g++-10", "--std=c++20", "-O2", "-o", problem_id, problem_id+".cpp");
        
        string line = "./" + problem_id;
        if (input_file != "") line += " < " + input_file;
        if (output_file != "") line += " > " + output_file;
        cmd.execute(line);

    } catch (TCLAP::ArgException &e) {
        cerr << "Error: " << e.error() << endl;
    }

    return 0;
}