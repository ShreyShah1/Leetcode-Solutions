
/**
 * AUTHOR: Shrey Shah
 * Language: Cpp
 * LeetCode Question No: 23
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its comp * lexity.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct MyNode {
    int index;
    ListNode * node;
    MyNode(int x, ListNode * node): index(x), node(node) {}
};

class myCompare {
public:
    bool operator()(MyNode t1, MyNode t2)
    {
       if (t1.node->val < t2.node->val ) {
       		return false;
       }
       return true;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
    
        std::priority_queue<MyNode, std::vector<MyNode>, myCompare> pQueue;
        
        for (int i = 0 ; i < k ; i++) {
            ListNode * temp = lists[i];
            if (temp) {
                lists[i] = lists[i]->next;
                temp->next = NULL;
                pQueue.push(MyNode(i, temp));
           }
        }    
        ListNode * head = NULL;
        ListNode * tail = NULL;
        
        while (!pQueue.empty()) {
            MyNode temp = pQueue.top();
            pQueue.pop();
            
            if (head == NULL) {
                head = tail = temp.node;
            } else {
                tail->next = temp.node;
                tail = tail->next;
            }
            // Put In the Queue.
            int nextIndex = temp.index;
            ListNode * newNode = lists[nextIndex];
            if (newNode) {
                lists[nextIndex] = lists[nextIndex]->next;
                newNode->next = NULL;
                pQueue.push(MyNode(nextIndex, newNode));
           }
        }
        return head;
    }
};
