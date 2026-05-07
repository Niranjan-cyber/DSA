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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) return {head};
        vector <ListNode*> v;
        int n = 0;
        ListNode* temp = head;
        while (temp != head){
            n++;
            temp = temp->next;
        }
        if (k > n){
            ListNode* temp1 = head;
            for (int i = 0; i < n; i++){
                v.push_back(temp1);
                temp1 = temp1->next;
            }
            for (int i = 0; i < k - n; i++){
                v.push_back(NULL);
            }
            return v;
        }
        int parts = n / k;
        int rem = n % k;

        ListNode* temp2 = head;
        for (int i = 0; i < rem; i++){
            v.push_back(temp2);
            for (int i = 0; i < parts+1; i++){
                temp2 = temp2->next;
            }
        }
        for (int i = 0; i < k - rem; i++){
            v.push_back(temp2);
            for (int i = 0; i < parts; i++){
                temp2 = temp2->next;
            }
        }
        return v;
    }
};