#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix){
    vector<int> temp;
    
    if(matrix.empty())
        return temp;

    int top = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
    int dir = 0;

    while(top <= down and left <= right){
    	if(dir == 0){
    		for(int i = left; i <= right; i++){
    			temp.push_back(matrix[top][i]);
    		}
    		top++;
    	}
    	else if(dir == 1){
    		for(int i = top; i <= down; i++){
    			temp.push_back(matrix[i][right]);
    		}
    		right--;
    	}
    	else if(dir == 2){
    		for(int i = right; i >= left; i--){
    			temp.push_back(matrix[down][i]);
    		}
    		down--;
    	}
    	else if(dir == 3){
    		for(int i = down; i >= top; i--){
    			temp.push_back(matrix[i][left]);
    		}
    		left++;
    	}

    	dir = (dir + 1) % 4;
    }
    return temp;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int row, col;
        cin >> row >> col;
        
        vector<vector<int>> matrix(row,vector<int> (col,0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin >> matrix[i][j];
            }
        }
        
        for(int& i : spiralOrder(matrix))
            cout << i << " ";
        cout << endl;
    }
}
