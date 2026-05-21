class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;

        int i;
        for(i = num.length()-1; i>= 0; i--){
            if(num[i] % 2 == 1){
                index = i;
                break;
            }
        }
        i=0;
        while(i <= index && num[i] == '0') i++;

        return num.substr(i, index - i + 1);
    }
};