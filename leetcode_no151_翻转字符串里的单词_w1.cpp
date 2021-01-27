/* ------------------------------------------------------------------|
给定一个字符串，逐个翻转字符串中的每个单词。

说明：

无空格字符构成一个 单词 。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

示例 1：

输入："the sky is blue"
输出："blue is sky the"
示例 2：

输入："  hello world!  "
输出："world! hello"
解释：输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入："a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
示例 4：

输入：s = "  Bob    Loves  Alice   "
输出："Alice Loves Bob"
示例 5：

输入：s = "Alice does not even like bob"
输出："bob like even not does Alice"
 

提示：

1 <= s.length <= 104
s 包含英文大小写字母、数字和空格 ' '
s 中 至少存在一个 单词
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：20 ms, 在所有 C++ 提交中击败了9.98%的用户
*	内存消耗：6.9 MB, 在所有 C++ 提交中击败了92.89%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

string reverseWords(string s) {
    if (s[0] == ' ') {
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        s.erase(s.begin(), s.begin() + i);
    }
    if (s[s.size() - 1] == ' ') {
        int i = s.size() - 1;
        while (s[i] == ' ') {
            i--;
        }
        s.erase(s.begin() + i + 1, s.end());
    }

    for (int i = 0; i < s.size(); i++) {
        int j = i;
        while (j < s.size() && s[j] != ' ') {
            j++;
        }
        reverse(s.begin() + i, s.begin() + j);
        while (j < s.size() - 1 && s[j + 1] == ' ') {
            s.erase(s.begin() + j);
        }
        i = j;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string s = "  Bob    Loves  Alice   ";
    string res = reverseWords(s);
}