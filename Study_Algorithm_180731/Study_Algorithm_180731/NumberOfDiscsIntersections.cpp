#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> &A)
{
	size_t inputSize = A.size();
	size_t count = 0;

	if (0 == inputSize)
		return 0;

	for (size_t i = 0; i < inputSize-1; ++i)
	{
		for (size_t j = i+1; j < inputSize; ++j)
		{
			if (j - i <= A[j] + A[i])
			{
				++count;
			}
		}
	}
	return count;
}

int solution(vector<int> &A)
{
	size_t inputSize = A.size();
	size_t count = 0;

	if (0 == inputSize)
		return 0;

	for (size_t i = 0; i < inputSize - 1; ++i)
	{
		if (i + A[i] > inputSize - 1)
			count += inputSize - 1 - i;
		else
			count += A[i];

		for (size_t j = i + A[i] + 1; j < inputSize; ++j)
		{
			if (j - i <= size_t(A[j] + A[i]))
			{
				++count;
			}
		}
	}
	return count;
}

int solution(vector<int> &A)
{
	size_t inputSize = A.size();
	size_t count = 0;

	if (0 == inputSize)
		return 0;

	for (size_t i = 0; i < inputSize; ++i)
	{
		int left = A[i];
		int right = A[i];

		if (i - A[i] < 0)
			left = i;

		if (i + A[i] >= inputSize)
			left = inputSize - i;

		count += left;
	}
	return count;
}

int solution(vector<int> &A)
{
	vector<vector<int>> discs;
	discs.resize(A.size());

	sort(A.begin(), A.end(), greater<int>());

	for (size_t i = 0; i < A.size(); ++i)
	{
		for (size_t j = 0; j < A[i]; ++j)
		{
			if (i - j >=0 && A[i-j] < A[i])
				discs[i].emplace_back(i - j);
			if (i + j >= 0 && A[i - j] < A[i])
				discs[i].emplace_back(i + j);
		}
	}

	return discs.size();
}

int solution(vector<int> &A)
{
	size_t inputSize = A.size();
	vector<pair<int, int>> discPair;

	for (size_t i = 0; i < inputSize; ++i)
	{
		discPair.emplace_back(pair<int, int>(i-A[i], i+A[i]));
	}

	size_t count = 0;
	for (size_t i = 0; i < inputSize - 1; ++i)
	{
		for (size_t j = 0; j < inputSize; ++j)
		{
			if (max(discPair[i].first, discPair[j].first) <= min(discPair[i].second, discPair[j].second))
				++count;
		}
	}

	return count;
}
