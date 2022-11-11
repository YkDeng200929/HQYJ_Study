/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.53%)
 * Likes:    2781
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两个链表的节点数目范围是 [0, 50]
 * -100 
 * l1 和 l2 均按 非递减顺序 排列
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


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *find = list1;
    for (find; find->next != NULL; find = find->next)
    {}
    find->next = list2->next;
    int i, j, num = 0;
    struct ListNode * prev = NULL, * target = NULL, *temp = NULL;
    for (temp = list1; temp != NULL; temp = temp->next, num++)
    {}
    for (i = 0; i < num; i++)
    {
        for (prev = head, target = prev->next, j = 0; j < num - i - 1; j++, prev = prev->next, target = prev->next)
        {
            if (target->data > target->next->data)
            {
                prev->next = target->next;
                target->next = prev->next->next;
                prev->next->next = target;
            }
        }
    }

}
// @lc code=end

