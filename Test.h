#ifndef EVALUADOR_H
#define EVALUADOR_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void test();
int longestPalindromicSubsequence(string sequence);
vector<int> getPath(int **DAG, int size, int source, int destination);

#endif // EVALUADOR_H
