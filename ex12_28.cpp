//
//  ex12_28.cpp
//  Exercise 12.28
//
//  Created by pezy on 1/1/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Write a program to implement text queries without defining classes to manage
//  the data.
//  Your program should take a file and interact with a user to query for words
//  in that file.
//  Use vector, map, and set containers to hold the data for the file and
//  to generate the results for the queries.

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

int main()
{
    std::ifstream file("china");
    vector<string> input;
    std::map<string, std::multiset<decltype(input.size())>> dictionary;
    decltype(input.size()) lineNo{0};

    for (string line; std::getline(file, line); ++lineNo) {
        input.push_back(line);
        std::istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(),
                back_inserter(word), ispunct);
            dictionary[word].insert(lineNo);
        }
    }

    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        auto found = dictionary.find(s);
        if (found != dictionary.end()) {
            std::cout << s << " occurs " << found->second.size()
                      << (found->second.size() > 1 ? " times" : " time")
                      << std::endl;
            for (auto i : found->second)
                std::cout << "\t(line " << i + 1 << ") " << input.at(i)
                          << std::endl;
        }
        else
            std::cout << s << " occurs 0 time" << std::endl;
    }
}