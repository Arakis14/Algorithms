#include <iostream>
#include <string>
#include <vector>
#include <iterator>


/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".\
Input: strs = ["flower","flow","flight"]
Output: "fl"    q
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/
template<typename T>
void printVec (const std::vector<T>& vec) {
    for (const auto &i : vec) {
        std::cout << i;
    }
}

std::string FindCommonPrefix(const std::string& str1, const std::string& str2) {
    std::string res{""};
    for (long unsigned int i = 0; i < str1.size(); i++) {
        for (long unsigned int j = 0; j < str2.size(); j++) {
            if (i == j) {
                if (str1.at(i) == str2.at(j)) {
                    /*
                    std::cout << "Same Char!" <<'\n';
                    std::cout << str1.at(i) << " " << str2.at(j) << '\n';
                    */
                    res+=str1.at(i);
                } else { return res; }
            }
        }
    }
    return res;
}

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    std::string res{""};
    int counter = 0;
    int tempcounter = 0;
    if (strs.at(0).size() == 1) {
        return strs.at(0);
    }
    for (auto itr1 = std::begin(strs); itr1 != strs.end(); itr1++) {
        for (auto itr2 = std::next(itr1); itr2 != strs.end(); itr2++) {
            auto temp = FindCommonPrefix(*itr1, *itr2);
            if (temp.size() > 0) {
                 counter++;
                 tempcounter++;
            } else { counter++; }
            //std::cout << "Temp: " << temp << '\n';
            if (res.length() != 0) {
                if (res == temp) { continue; }
                else if (  res.length() > temp.length()) {
                    res = temp;
                }
            } else { res+=temp; }
        }
    }
    if (tempcounter == counter) {
        return res;
    } else { return ""; }
}

int main()
{
    std::vector<std::string> strs {"flower","flow","flight"};
    std::vector<std::string> strs2 = {"dog","racecar","car"};
    std::vector<std::string> strs4 = {"flower","flower","flower"};
}