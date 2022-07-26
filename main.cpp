#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cmath>
#include <regex>
#include <algorithm>
#include <stack>

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

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
Input: s = "()"
Output: true
Input: s = "()[]{}"
Output: true
Input: s = "(]"
Output: false
1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'.
*/

bool checkAllowedChars(const std::string& s) {
    const std::regex allowedChars("[\\(||\\)||\\[||\\]||\\{||\\}]+");
    return (std::regex_match(s, allowedChars));
}

bool hasValidParenthesis(const std::string& s) {
    std::stack<char> parenthesisSequence;
    for (auto &i : s) {
        if      (i == '(') { parenthesisSequence.push('a'); }
        else if (i == '[') { parenthesisSequence.push('b'); }
        else if (i == '{') { parenthesisSequence.push('c'); }
        else if (i == ')' && parenthesisSequence.top() == 'a') { parenthesisSequence.pop(); }
        else if (i == ']' && parenthesisSequence.top() == 'b') { parenthesisSequence.pop(); }
        else if (i == '}' && parenthesisSequence.top() == 'c') { parenthesisSequence.pop(); }
        else { return false; }
    }
    return parenthesisSequence.size() == 0;
}

bool checkStringLength (const std::string& s) {
    double sLength = static_cast<double>(s.length());
    return (sLength >= 1 && sLength < pow(10,4));
}
bool isValid(const std::string& s) {

    return hasValidParenthesis(s) && checkAllowedChars(s) && checkStringLength(s);
}

int main()
{

}