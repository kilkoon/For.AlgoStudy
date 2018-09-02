#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(int i, vector<int> v);

void main()
{
	// Test Case 1
	//int i = 15;
	//vector<int> v;
	//v.emplace_back(15);
	//v.emplace_back(5);
	//v.emplace_back(3);
	//v.emplace_back(7);
	//v.emplace_back(9);
	//v.emplace_back(14);
	//v.emplace_back(0);

	// Test Case 2
	//int i = 5;
	//vector<int> v;
	//v.emplace_back(2);
	//v.emplace_back(5);

	// Test Case 3 // 답 : 1
	//int i = 10;
	//vector<int> v;
	//v.emplace_back(10);
	//v.emplace_back(9);
	//v.emplace_back(8);
	//v.emplace_back(7);
	//v.emplace_back(6);
	//v.emplace_back(5);
	//v.emplace_back(4);
	//v.emplace_back(3);
	//v.emplace_back(2);
	//v.emplace_back(1);
	//v.emplace_back(0);

	// Test Case 4 // 답 : 15
	int i = 30;
	vector<int> v;
	v.emplace_back(25);
	v.emplace_back(27);
	v.emplace_back(18);
	v.emplace_back(20);
	v.emplace_back(23);
	v.emplace_back(15);
	v.emplace_back(16);
	v.emplace_back(29);
	v.emplace_back(30);


	cout << solution(i, v)<< endl;
}


int solution(int i, vector<int> v)
{
	sort(v.begin(), v.end(), less<int>()); // 오름차순

	size_t inputSize = v.size();
	vector<int> dist;
	dist.reserve(inputSize - 1);

	int initDist = v[0];
	int endDist = i - v[inputSize-1];

	if (inputSize == 1)
	{
		return max(initDist, endDist);
	}
	else
	{
		for (size_t i = 0; i < inputSize - 1; ++i)
		{
			dist.emplace_back(v[i+1] - v[i]);
		}
	}

	int interDist = *max_element(dist.begin(), dist.end());

	if (0 == interDist % 2)
		interDist = interDist / 2;
	else
		interDist = interDist / 2 + 1;

	int initEnd = max(initDist, endDist);

	return max(initEnd, interDist);
}