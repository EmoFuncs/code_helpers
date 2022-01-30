#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

class command_line_tool {
private:
    template <typename T>
    void _get_input(stringstream& cmd, const T& first) {
        cmd << first;
    }

    template <typename T, typename... types>
    void _get_input(stringstream& cmd, const T& first, const types&... args) {
        cmd << first << " ";
        _get_input(cmd, args...);
    }

public:
    template <typename... types>
    void execute(const types&... args) {
        stringstream cmd;
        _get_input(cmd, args...);
        cout << cmd.str() << endl;
        system(cmd.str().c_str());
    }
};