#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> matrix, int r);

void main()
{
	vector<vector<int>> input;

	// Test Case 1 
	// 3차원 배열
	//input.resize(3);
	//input[0].emplace_back(4);
	//input[0].emplace_back(1);
	//input[0].emplace_back(2);
	//input[1].emplace_back(7);
	//input[1].emplace_back(3);
	//input[1].emplace_back(4);
	//input[2].emplace_back(3);
	//input[2].emplace_back(5);
	//input[2].emplace_back(6);

	// Test Case 2
	// 2차원 배열
	input.resize(2);
	input[0].emplace_back(1);
	input[0].emplace_back(2);
	input[1].emplace_back(3);
	input[1].emplace_back(4);



	input = solution(input, 2);

	for (vector<int> vec : input)
	{
		for (int num : vec)
		{
			cout << num << ", ";
		}
		cout << endl;
	}
}



vector<vector<int>> solution(vector<vector<int>> matrix, int r)
{
	size_t lineNum = matrix.size(); // 행의 개수 == 열의 개수
	
	size_t maxCnt = r % 4;

	vector<vector<int>> buffer = matrix;	

	for (size_t cnt = 0; cnt < maxCnt; ++cnt)
	{
		for (size_t col = 0; col < lineNum; ++col)
		{
			for (size_t row = 0; row < lineNum; ++row)
			{
				buffer[row][(lineNum - 1) - col] = matrix[col][row];
			}
		}

		matrix = buffer;
	}

	return matrix;
}