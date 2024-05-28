#pragma once
#include <iostream>
#include <vector>

int random(int l, int r);

std::vector<int> random(int l, int r, int k, bool re = false);

int random(std::vector<int>& weights);

int randInd(std::vector<int>& weights);

int randIndByWeights(std::vector<int>& weights);


bool oneIn(int facet);

bool aInb(int a, int b);

int roll(int diceNum, int facet);