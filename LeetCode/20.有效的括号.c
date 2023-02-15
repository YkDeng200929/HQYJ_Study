/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.36%)
 * Likes:    3729
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.1M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// @lc code=start


bool isValid(char * s){
    char buff[10000];
    int top = 1;
    int i = 0;
    while (s[i])
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            buff[top] = s[i];
            top += 1;
        }
        else 
        {
            if (s[i] - buff[top-1] == 1 || s[i] - buff[top-1] == 2)
            {
                top -= 1;
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    if (top == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// @lc code=end

