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
    long unsigned int size = (str1.length() > str2.length()) ? str1.length()/2 : str2.length()/2;
    for (const auto &i : str1) {
        long unsigned int index1 = 0;
        if ( size >= index1) { 
            index1++;
            long unsigned int index2 = index1;
            for (const auto &j : str2) {
                std::cout << i << " " << j << '\n';
                if (index1 == index2) {
                    if (i == j) {
                    res+=i;
                    }
                } else { 
                index2++;
                continue;
                }
            }
        }
        else { break; }
    }
    return res;

}

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    std::string res{""};
    for (auto itr1 = std::begin(strs); itr1 != strs.end(); itr1++) {
        for (auto itr2 = std::next(itr1); itr2 != strs.end(); itr2++) {
            auto temp = FindCommonPrefix(*itr1, *itr2);
            std::cout << "Temp: " << temp << '\n';
            if (res.length() != 0) {
                if (res == temp) { continue; }
                else if ( temp.length() > res.length()) {
                    res = temp;
                }
            } 
            else res+=temp;
        }
    }
    return res;
}

int main()
{
    std::vector<std::string> strs {"flower","flow","flight"};
    //printVec(strs);
    std::vector<std::string> strs2 = {"dog","racecar","car"};
    std::cout << longestCommonPrefix(strs) << '\n';
    std::cout << longestCommonPrefix(strs2) << '\n';
}