#include "utils.h"
int random(int l, int r)
{
	return rand() % (r - l) + l;
}

int* random(int l, int r, int k, bool re)
{
	int* res = new int[k];
	int ind = 0;
	while (ind != k)
	{
		res[ind] = random(l, r);
		if (re)
		{
			bool flag = true;
			for (int i = 0; i < ind; ++i)
				if (res[ind] == res[i])
					flag = false;
			if (!flag)
				ind--;
		}
		ind++;
	}
	return res;
}

int random(std::vector<int>& weights)
{
	int n = weights.size();
	int k = 0, su = 0;
	for (int i = 0; i < n; ++i) su += weights[i];
	int rd = random(0, su);
	for (int i = 0; i < n; ++i)
	{
		k += weights[i];
		if (k >= rd) return i;
	}
	return -1;
}
