/*给定一个链表数组，每个链表都已经按升序排列。

请将所有链表合并到一个升序链表中，返回合并后的链表。
*/
class Solution {
private:
    // 归并链表
    ListNode* mergeLists(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        int mid = start + ((end - start) >> 1);
        ListNode* head1 = mergeLists(lists, start, mid);
        ListNode* head2 = mergeLists(lists, mid + 1, end);
        return merge(head1, head2);
    }

    // 合并排序链表
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                cur->next = head1;
                head1 = head1->next;
            }
            else {
                cur->next = head2;
                head2 = head2->next;
            }

            cur = cur->next;
        }
        cur->next = (head1 == nullptr) ? head2 : head1;

        ListNode* ret = dummy->next;
        delete dummy;
        dummy = nullptr;
        return ret;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        return mergeLists(lists, 0, lists.size() - 1);
    }

};
