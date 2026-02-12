class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<vector<int>>freq(n,vector<int>(26,0));

        freq[0][s[0]-'a']=1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<26;j++) freq[i][j]=freq[i-1][j];
            freq[i][s[i]-'a']++;
        }

        int ans = 1;

        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                int check = -1;
                int is = true;
                for(int k=0;k<26;k++) {
                    int jfreq = freq[j][k];
                    int ifreq = i>0 ? freq[i-1][k] : 0;
                    int freq = jfreq-ifreq;
                    if(freq==0) continue;
                    if(check==-1) {
                        check=freq;
                    }
                    else if(check!=freq) {
                        is=false;
                        break;
                    }
                }
                if(is) {
                    ans=max(ans,j-i+1);
                }
            }
        }

        return ans;
    }
};