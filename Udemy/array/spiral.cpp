vector<int> spiralmatrix(vector<vector<int> >&mat){
    int n = mat.size();    // n*m matrix
    int m = mat[0].size();
    int left = 0,right = m - 1;
    int top = 0 , bottom = n -1;

    vector<int> ans;

    while(top<=bottom && left<= right){
        //right
        for(int i = left; i <= right;i++){
            cout << a[top][i] << endl;
        }

        
        top++;

        //down 
        for(int i = top;i<=bottom;i++){
            cout << a[i][right] << endl;
        }
        right--;

        //left  
        if(top<=bottom){
            for(int i = right;i>=left;i--){
                cout << a[bottom][i] << endl;
            }
            bottom--;
        }

        //up
        if(left<= right){
            for(int i = bottom; i>=top;i--){
                cout << a[i][left] << endl;
            }
            left++;
        }
    }

}