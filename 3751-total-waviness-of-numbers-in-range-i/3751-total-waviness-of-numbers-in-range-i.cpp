class Solution {
public:
    int waviness(int n){
        vector<int>digit;
        while(n>0)
        {
            digit.push_back(n%10);
            n=n/10;
            
        }
        reverse(digit.begin(),digit.end());
        int cnt=0;
        for(int i=1;i<digit.size()-1;i++){
            if((digit[i]>digit[i-1]&& digit[i]>digit[i+1])||(digit[i]<digit[i-1]&& digit[i]<digit[i+1])){
                cnt++;
            }
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int sum=0;
        for(int n=num1;n<=num2;n++){
            sum+=waviness(n);
        }
        return sum;
    }
};