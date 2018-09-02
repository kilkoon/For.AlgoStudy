#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> seat);

void main()
{
	vector<vector<int>> input;

	// Test Case 1
	//input.resize(6);
	//input[0].emplace_back(1);
	//input[0].emplace_back(1);
	//input[1].emplace_back(2);
	//input[1].emplace_back(1);
	//input[2].emplace_back(1);
	//input[2].emplace_back(2);
	//input[3].emplace_back(3);
	//input[3].emplace_back(4);
	//input[4].emplace_back(2);
	//input[4].emplace_back(1);
	//input[5].emplace_back(2);
	//input[5].emplace_back(1);

	// Test Case 2
	//input.resize(3);
	//input[0].emplace_back(1);
	//input[0].emplace_back(1);
	//input[1].emplace_back(2);
	//input[1].emplace_back(2);
	//input[2].emplace_back(3);
	//input[2].emplace_back(3);

	// Test Case 3 // ´ä : 4
	//input.resize(6);
	//input[0].emplace_back(100);
	//input[0].emplace_back(100);
	//input[1].emplace_back(200);
	//input[1].emplace_back(200);
	//input[2].emplace_back(500);
	//input[2].emplace_back(500);
	//input[3].emplace_back(200);
	//input[3].emplace_back(200);
	//input[4].emplace_back(100);
	//input[4].emplace_back(100);
	//input[5].emplace_back(700);
	//input[5].emplace_back(700);


	// Test Case 4 // ´ä : 10
	//input.resize(10);
	//input[0].emplace_back(1);
	//input[0].emplace_back(3);
	//input[1].emplace_back(3);
	//input[1].emplace_back(1);
	//input[2].emplace_back(5);
	//input[2].emplace_back(2);
	//input[3].emplace_back(2);
	//input[3].emplace_back(5);
	//input[4].emplace_back(8);
	//input[4].emplace_back(8);
	//input[5].emplace_back(2);
	//input[5].emplace_back(3);
	//input[6].emplace_back(4);
	//input[6].emplace_back(3);
	//input[7].emplace_back(6);
	//input[7].emplace_back(3);
	//input[8].emplace_back(7);
	//input[8].emplace_back(3);
	//input[9].emplace_back(8);
	//input[9].emplace_back(3);

	// Test Case 5 // ´ä : 1
	input.resize(10);
	input[0].emplace_back(1);
	input[0].emplace_back(1);
	input[1].emplace_back(1);
	input[1].emplace_back(1);
	input[2].emplace_back(1);
	input[2].emplace_back(1);
	input[3].emplace_back(1);
	input[3].emplace_back(1);
	input[4].emplace_back(1);
	input[4].emplace_back(1);
	input[5].emplace_back(1);
	input[5].emplace_back(1);
	input[6].emplace_back(1);
	input[6].emplace_back(1);
	input[7].emplace_back(1);
	input[7].emplace_back(1);
	input[8].emplace_back(1);
	input[8].emplace_back(1);
	input[9].emplace_back(1);
	input[9].emplace_back(1);

	cout << solution(input)<< endl;
}

int solution(vector<vector<int>> seat)
{
	sort(seat.begin(), seat.end(), 
		[](auto iterFirst, auto iterSecond) {
		if (iterFirst[0] < iterSecond[0])
			return true;
		else if (iterFirst[0] == iterSecond[0])
		{
			return iterFirst[1] < iterSecond[1];
		}
		return false;
	});

	int count = 1;
	size_t inputSize = seat.size();
	for (size_t i = 0; i < inputSize - 1; ++i)
	{
		if (seat[i][0] == seat[i + 1][0] && seat[i][1] == seat[i + 1][1])
			continue;
		++count;
	}

	return count;
}