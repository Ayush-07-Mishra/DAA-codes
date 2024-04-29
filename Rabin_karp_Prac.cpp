#include<iostream>
#include<climits>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

void RK(const string& text,const string& pattern,int q){
    int n = text.length();
    int m = pattern.length();
    int d = 10;
    int h = 1;
    for(int i = 0;i<m-1;i++){
        h = (d*h)%q;
    }

    int p =0;
    int t =0;
    int matches =0;
    int spurious_hits =0;

    for(int i =0;i<m;i++){
        p = (d * p + (pattern[i] - '0'))%q;
        t = (d * t + (text[i] - '0'))%q;
    }

    for(int i =0;i<n-m+1;i++){
        if(p==t){
            int j;
            for(j =0;j<m;j++){
                if(text[i+j] != pattern[j]){
                    break;
                }
            }
            if(j==m){
                cout<<"pattern found at index : "<< i << endl;
                matches++;
            }else{
                spurious_hits++;
            }
        }

        if(i < n-m){
            t = (d * (t - (text[i] - '0') * h) + (text[i+m] - '0'))%q;
            if(t<0){
                t = (t+q)%q;
            }
        }
    }
    cout << "Total matches: " << matches << endl;
    cout << "Total spurious hits: " << spurious_hits << endl; 
}

int main() {
    string text = "2359023141526739921";
    string pattern = "31415";
    int q = 13;

    RK(text, pattern, q);

    return 0;
}
