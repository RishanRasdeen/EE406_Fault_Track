#include <regex>
#include <string>

using namespace std;

string extractModuleName(const string &line)
{
    smatch match;
    if (regex_search(line, match, regex("module\\s+([^\\s(]+)\\s*\\(")))
    {
        return match[1];
    }
    return "";
}