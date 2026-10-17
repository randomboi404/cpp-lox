#include <iostream>
#include <vector>
#include <string>
#include <fstream>

static int run(const std::string& s) {
    return 0;
}

static int runInteractive() {
    std::string line;

    while (1) {
        std::cout << "> ";
        std::cin >> line;

        if (std::cin.eof()) break;
        run(line);
    }

    return 0;
}

static int runFile(const std::string& file) {
    std::ifstream scriptFile(file);
    std::string program(std::istreambuf_iterator<char>(scriptFile), {});

    return run(program);
}

int main(const int argc, char** argv) {
    std::vector<std::string> args(argv, argv + argc);

    if (args.size() > 2) {
        std::cout << "Usage: jlox [script]";
        return -1;
    }

    if (args.size() == 1) return runInteractive();
    else return runFile(args.front());
}
