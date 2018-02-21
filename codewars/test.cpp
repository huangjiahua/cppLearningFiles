#include <sstream>
#include <cctype>
#include <utility>
#include <vector>
#include <string>
class UpAndDown
{
private:
    static std::string arrange(std::vector<std::string> &v);
    static void upper(std::string& s);
    static void lower(std::string& s);
    static void swap(std::string &s1, std::string &s2);
public:
    static std::string arrange(const std::string &strng);
};

std::string UpAndDown::arrange(const std::string &strng)
{
   std::istringstream is(strng);
   std::vector<std::string> vs;
   std::string word;
   while (is >> word)
      vs.push_back(word);
   return arrange(vs);
}

std::string UpAndDown::arrange(std::vector<std::string> &v)
{
   for (int i = 0; i < v.size() - 1; ++i) {
      if (i % 2) {
          if (v[i].size() < v[i+1].size())
              swap(v[i], v[i+1]);
      }
      else {
          if (v[i].size() > v[i+1].size())
              swap(v[i], v[i+1]);
      }
   }

   std::string ret;
   for (int i = 0; i < v.size(); ++i) {
      i % 2 ? upper(v[i]) : lower(v[i]);
      ret += v[i] + " ";
   }
   if (!ret.empty())
      ret.pop_back();
   return ret;
}

void UpAndDown::upper(std::string& s)
{
    for (auto& c : s)
        c = toupper(c);
}

void UpAndDown::lower(std::string& s)
{
    for (auto& c : s)
        c = tolower(c);
}

void UpAndDown::swap(std::string& s1, std::string& s2)
{
    std::string temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}
