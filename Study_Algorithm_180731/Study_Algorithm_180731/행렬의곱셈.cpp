#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	
	size_t row = arr1.size();
	size_t col = arr2[0].size();

	vector<vector<int>> answer;
	answer.resize(row);


	for (size_t i = 0; i < row; ++i)
	{
		answer[i].resize(col);
		for (size_t j = 0; j < col; ++j)
		{
			answer[i][j] = ;
		}
	}

	return answer;
}