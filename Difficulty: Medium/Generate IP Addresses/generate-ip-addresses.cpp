class Solution {
public:

    bool valid(string s){
        if(s.size() > 1 && s[0] == '0') return false;

        int num = stoi(s);

        return num >= 0 && num <= 255;
    }

    void solve(int index, string &s, int parts, string curr, vector<string> &ans){

        if(parts == 4 && index == s.size()){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        if(parts >= 4) return;

        for(int len = 1; len <= 3; len++){

            if(index + len > s.size()) break;

            string segment = s.substr(index, len);

            if(valid(segment)){
                solve(index + len, s, parts + 1, curr + segment + ".", ans);
            }
        }
    }

    vector<string> generateIp(string s) {

        vector<string> ans;

        solve(0, s, 0, "", ans);

        return ans;
    }
};