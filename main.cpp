#include "Test.h"
#include <iostream>
#include <map>
#include <limits>

using namespace std;

map<int, std::map<int, int> > memoizedTable;
int longestPalindromicSubsequence(string sequence, int begin, int end)
{
   if (begin == end)
     return 1;

   if (sequence[begin] == sequence[end] && begin + 1 == end)
     return 2;

   if(
     memoizedTable.find(begin) == memoizedTable.end() ||
     memoizedTable[begin].find(end) == memoizedTable[begin].end()
   )
   {
      if (sequence[begin] == sequence[end])
      {
        memoizedTable[begin][end] = longestPalindromicSubsequence(sequence, begin+1, end-1) + 2;
        return memoizedTable[begin][end];
      }
      return max( longestPalindromicSubsequence(sequence, begin, end-1),
        longestPalindromicSubsequence(sequence, begin+1, end) );
   }

  return memoizedTable[begin][end];
}

int longestPalindromicSubsequence(string sequence)
{
  memoizedTable.clear();
  return longestPalindromicSubsequence(sequence, 0, sequence.size()-1);
}

void printVector(std::vector<int> v)
{
  for (unsigned int i = 0; i < v.size(); i++) {
    cout<<"V contains: "<<v[i]<<endl;
  }
  cout<<endl;
}

void getPathFromWeights(int **DAG, int size, int source, int destination, std::vector<int>* v)
{
  int nextNode = -1;
  int nextWeight = std::numeric_limits<int>::max();
  for (int i = 0; i < size; ++i)
  {
    if (DAG[source][i] != -1)//if edge exists
    {
      if(i == destination)
      {
        v->push_back(i);
        return;
      }else
      {
        if(DAG[source][i] <= nextWeight)//if weight is lower, take it
        {
          nextNode = i;
          nextWeight = DAG[source][i];
        }
      }
    }
  }
  v->push_back(nextNode);//got the best next node
  getPathFromWeights(DAG, size, nextNode, destination, v);
}

vector<int> getPath(int **DAG, int size, int source, int destination)
{
  vector<int> answer;
  getPathFromWeights(DAG, size, source, destination, &answer);
  return answer;
}


int main ()
{
    test();
    return 0;
}
