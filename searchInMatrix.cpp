#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    if(matrix.empty())
        return false;
    
    int row = -1;
    
    for(int i = 0; i < matrix.size() - 1; i++){
        if(target == matrix[i][0])
            return true;
    
        if(target > matrix[i][0] and target < matrix[i + 1][0])
            row = i;
    }
    
    if(row == -1)
        row = matrix.size() - 1;
    
    for(int j = 0; j < matrix[0].size(); j++){
        if(target == matrix[row][j])
            return true;
    }
    
    return false;
}

int main() {
	int cases;
	cin >> cases;
	while(cases--){
		int r,c;
		cin >> r >> c;
		vector<vector<int>> matrix(r, vector<int> (c,0));
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				cin >> matrix[i][j];
			}
		}
		int target;
		cin >> target;
		cout << searchMatrix(matrix, target) << endl;
	}
	return 0;
}