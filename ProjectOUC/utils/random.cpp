#include "random.h"
#include <iostream>

int random(int l, int r)
{
	if (l > r) return 0;
	return rand() % (r - l + 1) + l;
}

std::vector<int> random(int l, int r, int k, bool re)
{
	if (k > r - l + 1) k = r - l + 1;
	std::vector<int> res(k, l - 1);
	int ind = 0;
	while (ind != k)
	{
		res[ind] = random(l, r);
		if (!re && count(res.begin(), res.end(), res[ind]) > 1) res[ind] = l - 1;
		else ind++;
	}
	return res;
}

int random(std::vector<int>& weights)
{
	int size = (int)weights.size();
	if (size == 0) return 0;
	return weights[random(0, size - 1)];
}

int randInd(std::vector<int>& weights)
{
	int size = (int)weights.size();
	return random(0, size-1);
}

int randIndByWeights(std::vector<int>& weights)
{
	int su = 0;
	for (int w : weights) su += w;
	int rd = random(0, su - 1);
	int k = 0;
	for (int i = 0; i < weights.size(); ++i)
	{
		k += weights[i];
		if (k > rd) return i;
	}
	return -1;
}

bool oneIn(int facet)
{
	return random(1, facet) == 1;
}

bool aInb(int a, int b)
{
	return random(1, b) <= a;
}

int roll(int diceNum, int facet)
{
	int res = 0;
	for (int i = 0; i < diceNum; ++i) res += random(1, facet);
	return res;
}