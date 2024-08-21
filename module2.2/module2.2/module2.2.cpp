#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <sys/utsname.h>
#elif __APPLE__
#include <sys/sysctl.h>
#include <mach-o/dyld.h>
#endif



std::string getOSName() {
#ifdef _WIN32
    return "windows";
#elif __linux__
    return  "linux";
#elif __APPLE__
    return "apple";
#else
    return "Unknown OS";
#endif
}

std::string getCompilerName() {
#ifdef __clang__
    return "Clang";
#elif __GNUC__
    return "GCC";
#elif _MSC_VER
    return "MSVC";
#else
    return "Unknown Compiler";
#endif
}

std::string getCompilerVersion() {
#ifdef __clang__
    return string(__clang_version__);
#elif __GNUC__
    stringstream ss;
    return ss.str();
#elif _MSC_VER
    std::stringstream ss;
    ss << _MSC_VER;
    return ss.str();
#else
    return "Unknown Compiler Version";
#endif
}

int main() {
    std::cout << "Name OS: " << getOSName() << std::endl;
    std::cout << "Compiler: " << getCompilerName() << std::endl;
    std::cout << "Compiler Version: " << getCompilerVersion() << std::endl;
    std::cin.get();
    return 0;
}
