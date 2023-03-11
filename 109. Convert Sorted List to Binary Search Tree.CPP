/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //convert the linked list into an array
        vector<int>v;
        while(head)
        {
            v.push_back(head->val);
            head=head->next;//when the head become NULL that's mean all the value was stored
            
        }
        return func(v,0,v.size()-1);
        
    }
    TreeNode* func(vector<int> v, int l,int r){
            if(l>r) return NULL;
            int mid = l+ (r-l)/2;
            TreeNode* node=new TreeNode(v[mid]);
            node->left= func(v,l,mid-1);
            node->right= func(v,mid+1,r);
            return node;
        }
};