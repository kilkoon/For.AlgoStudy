#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int GetMaxLen(vector<vector<int>>& board, size_t initRow, size_t initCol, size_t row, size_t col);
int solution(vector<vector<int>> board);

void main()
{
	vector<vector<int>> input;
	input.resize(2);
	input[0].emplace_back(0);
	input[0].emplace_back(0);
	input[0].emplace_back(1);
	input[0].emplace_back(1);

	input[1].emplace_back(1);
	input[1].emplace_back(1);
	input[1].emplace_back(1);
	input[1].emplace_back(1);


	int answer = solution(input);
}

int solution(vector<vector<int>> board)
{
	size_t row = board.size();
	size_t col = board[0].size();

	size_t maxLen = min(row, col);

	vector<int> area;
	area.resize(row*col, 0);

	// 전체 사각형이 정사각형인 경우
	for (size_t i = 0; i < maxLen; ++i)
	{
		size_t eachRow = i;
		size_t eachCol = i;

		if (row > col)
			eachRow += row - col;
		else if(row < col)
			eachCol += col - row;

		for (size_t j = 0; j < eachCol; ++j)
		{
			area[i*row + j] = GetMaxLen(board, eachRow, j, row, col);
		}

		area[eachRow*row + eachCol] = GetMaxLen(board, eachRow, eachCol, row, col);

		for (size_t j = 0; j < eachRow; ++j)
		{
			area[j*row + i] = GetMaxLen(board, j, eachCol, row, col);
		}
	}


	int maxRow = *max_element(area.begin(), area.end());
	return pow(maxRow, 2);
}

int GetMaxLen(vector<vector<int>>& board, size_t initRow, size_t initCol, size_t row, size_t col)
{
	int sum = 0;
	size_t maxLen = min(row - initRow, col - initCol);

	for (size_t i = initRow; i < initRow + maxLen; ++i)
	{
		for (size_t j = initCol; j < initCol + maxLen; ++j)
		{
			sum += board[i][j];
		}
	}

	return int(sqrt(sum));
}
