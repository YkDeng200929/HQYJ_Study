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
    bool judge = false;
    int i = 0, len = sizeof(s)/sizeof(s[0]);
    while(*(s+i))
    {
        if (s[i+1] - s[i] == 1 || s[i+1] - s[i] == 2)
        {
            judge = true;
        }
        else if (i%2 == 1)
        {
            i += 1;
            continue;
        }
        else
        {
            judge = false;
        }
        i += 1;
    }
    for (i = 0; i < len/2; i++)
    {
        // if (s[len] - s[i] == 1 || s[len] - s[i] == 2)
        if (1)
        {
            judge = true;
        }
        else
        {
            judge = false;
        }
        len--;
    }

    return judge;
}
// @lc code=end

