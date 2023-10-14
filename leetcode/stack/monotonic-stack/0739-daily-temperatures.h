class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size());
        stack<int> s; // store index
        for (int i=temp.size()-1; i>=0; i--) {
            while (!s.empty() && temp[i] >= temp[s.top()]) {
                s.pop();
            }
            ans[i] = s.empty() ? 0 : s.top()-i;
            s.push(i);
        }
        return ans;
    }
};