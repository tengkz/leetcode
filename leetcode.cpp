#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int> idx(nums.size());
        std::iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&nums](int i1,int i2){return nums[i1]<nums[i2];});
        sort(nums.begin(),nums.end());
        for(int i=0,j=nums.size()-1;i<nums.size();i++){
            while(nums[i]+nums[j]>target && i<j)
                j--;
            if(nums[i]+nums[j]==target){
                result.push_back(idx[i]);
                result.push_back(idx[j]);
                return result;
            }
        }
        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *pre = head;
        int a,b=0;
        while(l1!=NULL && l2!=NULL){
            a = l1->val+l2->val+b;
            b = a/10;
            a = a%10;
            ListNode *n = new ListNode(a);
            pre->next = n;
            pre = n;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            a = l1->val+b;
            b = a/10;
            a = a%10;
            ListNode *n = new ListNode(a);
            pre->next = n;
            pre = n;
            l1 = l1->next;
        }
        while(l2!=NULL){
            a = l2->val+b;
            b = a/10;
            a = a%10;
            ListNode *n = new ListNode(a);
            pre->next = n;
            pre = n;
            l2 = l2->next;
        }
        if(b>0){
            ListNode *n = new ListNode(b);
            pre->next = n;
        }
        return head->next;
    }

    int countCharacters(vector<string>& words, string chars) {
        vector<int> vec(26);
        for(int i=0;i<chars.size();i++)
            vec[chars[i]-'a']++;
        int result = 0;
        for(int i=0;i<words.size();i++){
            vector<int> t(26);
            for(int j=0;j<26;j++){
                t[j] = vec[j];
            }
            int flag=1;
            for(int j=0;j<words[i].size();j++){
                t[words[i][j]-'a']--;
                if(t[words[i][j]-'a']<0){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                result+=words[i].size();
            }
        }
        return result;
    }

    int lengthOfLongestSubstring(string s) {
        vector<int> chars(1024);
        for(int i=0;i<1024;i++){
            chars[i]=-1;
        }
        int result = 0;
        int last = 0;
        int maxlen = 0;
        for(int i=0;i<s.size();i++){
            int x = (int)s[i];
            if(chars[x]<last){
                maxlen+=1;
            }
            else{
                last = chars[x]+1;
                maxlen = i-last+1;
            }
            chars[x] = i;
            if(maxlen>result){
                result=maxlen;
            }
        }
        return result;
    }

    int reverse(int x) {
        int y=0;
        while(x){
            if(y>214748364 || y<-214748364){
                return 0;
            }
            y=y*10+x%10;
            x/=10;
        }
        return y;
    }

};

int main()
{
    Solution s; 
    vector<int> nums{2,7,11,15};
    int target = 9;
    vector<int> result = s.twoSum(nums,target);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl;
    return 0;
}
