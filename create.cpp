#include "cmd_tools.h"
#include <cassert>
#include <filesystem>

using namespace std;

int main(int argc, char *argv[]) {
	assert(argc == 2);

	command_line_tool cmd;

	string problem_id(argv[1]);

	string problem_root = "problem_" + problem_id;
	string problem_cpp = problem_root + "/" + problem_id + ".cpp";
	string problem_in = problem_root + "/" + problem_id + ".in";

	if (!filesystem::exists(problem_root)) {
		cmd.execute("mkdir", problem_root);
	}
	
	if (!filesystem::exists(problem_cpp)) {
		cmd.execute("cp", "~/code/programming-contest-codes/template.cpp", problem_cpp);
	}
	
	if (!filesystem::exists(problem_in)) {
		cmd.execute("touch", problem_in);
	}
	
	return 0;
}
