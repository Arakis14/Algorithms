#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cmath>
#include <regex>
#include <algorithm>
#include <stack>
#include <cctype>

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
    std::cout << '\n';
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
        else if (i == ')' && parenthesisSequence.size() != 0 && parenthesisSequence.top() == 'a') 
            { parenthesisSequence.pop(); }
        else if (i == ']' && parenthesisSequence.size() != 0 && parenthesisSequence.top() == 'b') 
            { parenthesisSequence.pop(); }
        else if (i == '}' && parenthesisSequence.size() != 0 && parenthesisSequence.top() == 'c') 
            { parenthesisSequence.pop(); }
        else { return false; }
    }
    return parenthesisSequence.size() == 0;
}

bool checkStringLength (const std::string& s) {
    double sLength = static_cast<double>(s.length());
    return (sLength >= 1 && sLength < pow(10,4));
}
bool isValid(const std::string& s) {

    return  checkStringLength(s) && checkAllowedChars(s) && hasValidParenthesis(s);
}

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:
Input: list1 = [], list2 = []
Output: []
Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
Constraints:
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool checkVal(const ListNode* list) {
    return (list->val >= -100 && list->val <= 100);
}

bool checkNodeRange(const ListNode* list) {
    auto counter = 0;
    auto tempList = list;
    while (tempList->next != nullptr) {
        counter++;
        tempList=tempList->next;
    }
    return (counter >= 0 && counter <= 50);
}

bool checkIsListNodeSorted(const ListNode* list) {
    auto tempList = list;
    while (tempList->next != nullptr) {
        if (tempList->val <= tempList->next->val) {
            tempList=tempList->next;
            continue;
        }
        else { return false; }
    }
    return true;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    auto tempList = list1;
    auto headList = list2;
    tempList->next = nullptr;
    headList->next = nullptr;
    if (checkNodeRange(list1) && checkNodeRange(list2) && checkVal(list1) && checkVal(list2) &&
        checkIsListNodeSorted(list1) && checkIsListNodeSorted(list2)) {
            while (list1->next != nullptr && list2->next != nullptr)
            {
                if(list1->val > list2->val) {
                    tempList->val = list2->val;
                    tempList->next = list2;
                    list2 = list2->next;
                } else {
                    tempList->val = list1->val;
                    tempList->next = list1;
                    list1 = list1->next;
                }
            }
        } else { return tempList; }
    return tempList;
}
/*
Given an integer array nums sorted in non-decreasing order,
remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.
Since it is impossible to change the length of the array in some languages, 
you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates, then the first k elements of nums should 
hold the final result. It does not matter what you leave beyond the first k elements.
Return k after placing the final result in the first k slots of nums.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

*/
long unsigned int removeDuplicates(std::vector<int>& nums) {
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    auto res = nums.size();
    return res;
}

/*
Implement strStr().
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to 
C's strstr() and Java's indexOf().
Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/
long unsigned int strStr(const std::string& haystack, const std::string& needle) {
    return haystack.find(needle, 0);
}

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/
long unsigned int searchInsert(std::vector<int>& nums, const int& target) {
    auto pos = std::lower_bound(nums.begin(), nums.end(), target);
    if (pos != nums.end()) {
        return std::distance(nums.begin(), pos);
    } else {
        int delta = pow(10,4);
        int index = 0;
        int counter = 0;
        for (auto &i : nums) {
            counter++;
            auto tempDelta = target - i;
            if (abs(tempDelta) < delta ) {
                delta = tempDelta;
                index = counter;
            }
        }
        return index;
    }
}

/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/
long int lengthOfLastWord(const std::string& s) {
    auto itr = std::find_if(s.rbegin(), s.rend(), [&](char c) { return std::isalpha(c); });
    auto dd = std::find(itr, s.rend(),  ' ');
    auto distance = std::distance(itr, dd);
    return distance;
}

int main()
{

}