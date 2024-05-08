#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

pair<int,string> LCS(const string& seq1 , const string& seq2){
    int m = seq1.length();
    int n = seq2.length();

    vector<vector<int> >dp(m+1,vector<int>(n+1,0));

    for(int i = 1;i<m+1;i++){
        for(int j = 1;j<n+1;j++){
            if(seq1[i-1] == seq2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
            }
        }
    }

    string lcs;
    int i = m;int j = n;
    while( i > 0 && j > 0){
        if(seq1[i-1] == seq2[j-1]){
            lcs =seq1[i-1] + lcs;
            i--;
            j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }

    return make_pair(dp[m][n] , lcs);
}

int main(){
    string seq1 = "malpractice";
    string seq2 = "racial";
    pair<int ,string>result =  LCS(seq1,seq2);
    cout << result.first << endl;
    cout << result.second<< endl;
}