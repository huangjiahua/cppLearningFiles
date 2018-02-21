#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    multimap<string, string> authors = {
        {"luxun", "nahan"},
        {"luxun", "panghuang"}
    };
    authors.insert({"luxun", "gushixinbian"});
    authors.insert({"wangxiaobo", "huangjinshidai"});
    authors.insert({"wangxiaobo", "baiyinshidai"});
    authors.emplace("caoxueqin", "hongloumeng");

    for (auto iter = authors.cbegin();
         iter != authors.cend(); ) {
        cout << iter->first << ": " << endl;
        for (auto end = authors.upper_bound(iter->first);
             iter != end; ++iter)
             cout << "\t" << iter->second << endl;
        if (iter == authors.end())
            break;
    }
    cout << "\n\n" << endl;
    for (const auto &pr : authors)
        cout << pr.first << "   " << pr.second << endl;

    return 0;
}
