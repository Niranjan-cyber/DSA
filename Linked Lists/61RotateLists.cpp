#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while (temp != NULL){
            n++;
            temp = temp->next;
        }
        ListNode* ntemp = head;
        ListNode* newHead;
        for (int i = 0; i < n - k; i++){
            if (i == n - k - 1){
                newHead = ntemp->next;
                ntemp->next = NULL;
                break;
            }
            ntemp = ntemp -> next;
        }
        ListNode* temp2 = newHead;
        for (int i = 0; i < k - 1; i++){
            temp2 = temp2->next;
        }
        temp2->next = head;
        return newHead;
    }
};