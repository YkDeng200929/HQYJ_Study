/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (53.27%)
 * Likes:    940
 * Dislikes: 0
 * Total Accepted:    536.6K
 * Total Submissions: 1M
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,1,2]
 * 输出：[1,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,1,2,3,3]
 * 输出：[1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围 [0, 300] 内
 * -100 <= Node.val <= 100
 * 题目数据保证链表已经按升序 排列
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    int sig = 0;
    
    struct ListNode* index = NULL, *bak = NULL;
    for (index = head; (NULL != index->next) || (NULL == index); index = index->next)
    {//x '[1,1,2,2,2]'
    // x access'[1,1,2,2,2,3,4,5,5]'
        sig = index->val;
        if (sig == index->next->val)
        {
            bak = index;
            index->next = index->next->next; //x
        }
        else if (sig == index->val)
        {
            bak->next = index->next;
            index = bak;
            bak = index->next;
        }
        else
        {
            bak = index;
        }
    }
    
    return head;
}
// @lc code=end

