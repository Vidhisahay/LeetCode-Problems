class Solution {
    vector<vector<string>> v;
    void fn(int row, int colmask, int leftdig, int rightdig, vector<string>& temp, int n) {
        if(row == n) {
            v.push_back(temp);
            return;
        }
        
        for(int i = 0; i < n; ++i) { 
            int right = i - row + n; 
            int left = i + row;
            
            if(!(colmask>>i&1) && !(rightdig>>right&1) && !(leftdig>>left&1)) {     
                temp[row][i] = 'Q'; 
                fn(row+1,colmask|(1<<i),leftdig|(1<<left),rightdig|(1<<right),temp,n);
                temp[row][i] = '.'; 
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n, '.')); 
        fn(0, 0, 0, 0, temp, n);
        return v;
    }
};