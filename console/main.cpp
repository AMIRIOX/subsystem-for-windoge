#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#ifdef _WIN32
   #include <windows.h>
   #include <direct.h>
   #include <shlwapi.h>
#elif __APPLE__
    #if TARGET_OS_MAC
        #include <mach-o/dyld.h>
    #endif
#elif __linux__
    #include <unistd.h>
    #include <linux/limits.h>
#endif
enum os{
    WINDOWS,
    MACOS,
    LINUX,
    UNIX,
    IOS
}platform;
std::vector<std::string> ent_graph;
// TODO: support UNIX.
void initEnv() {
#ifdef _WIN32
   platform = os::WINDOWS;
#elif __APPLE__
    #if TARGET_IPHONE_SIMULATOR
        platform = os::IOS;
    #elif TARGET_OS_IPHONE
        platform = os::IOS;
    #elif TARGET_OS_MAC
        platform = os::MACOS;
    #else
    #   error "Unknown Apple platform, not supported."
    #endif
#elif __linux__
    platform = os::LINUX;
#endif
}
std::string getCurPath() {
    if(platform == os::WINDOWS) {
        #ifdef WIN32
        // get current executable file dir
        wchar_t szExePath[MAX_PATH] = {0};
        GetModuleFileNameW(NULL, szExePath, sizeof(szExePath));
        PathRemoveFileSpecW(szExePath);
        // convert to c_str
        size_t len = wcslen(szExePath) + 1;
        size_t converted = 0;
        char *CStr;
        CStr=(char*)malloc(len*sizeof(char));
        wcstombs(CStr,szExePath, len);
       return std::string(CStr);
       #endif
    }else if(platform == os::MACOS) {
        #ifdef __APPLE__
        char _path[512];
        unsigned size = 512;
            #if TARGET_OS_MAC
            _NSGetExecutablePath(_path, &size);
            #endif // TARGET_OS_MAC
        _path[size] = '\0';
        return std::string(_path);
        #endif
    } else if(platform == os::LINUX) {
        #if __linux__
        char _path[512];
        int size = readlink("/proc/self/exe", _path, 512);
        _path[size] = '\0';
        std::string resPath(_path);
        for(int i=0;i<9;i++) resPath.pop_back();
        return resPath;
        #endif
    }
    return "";
}
std::string currentDir = "~";
std::string currentUser = "amiriox";
// TODO: 把currentUser等全局变量放入一个头文件
// TODO: 使用一些数据结构
// TODO: 把输出文字颜色抽象出函数
// TODO: 使用一个class表达路径
#define OUTPUT_ORIGIN                                   \
    do {                                                \
        cout << "\033[32m ➜ \033[0m "                 \
             << "\033[32m" << currentDir << "\033[0m "; \
    } while (false);
#define OUTPUT_ORIGIN_WITH_USER                         \
    do {                                                \
        cout << "\033[32m ➜ \033[0m "                 \
             << "\033[33m" << currentUser << "\033[0m " \
             << "\033[32m" << currentDir << "\033[0m "; \
    } while (false);
using namespace std;
int main(int argc, char const *argv[]) {
    initEnv();
    currentDir=getCurPath();
    while (1) {
        OUTPUT_ORIGIN_WITH_USER;
        string command;
        cin >> command;
        if(command=="exit") return 0;
        string exe = getCurPath()+"/../rootfs/bin/"+command;
        if(platform==os::WINDOWS) exe+=".exe";
        system(exe.c_str());
    }
    return 0;
}
