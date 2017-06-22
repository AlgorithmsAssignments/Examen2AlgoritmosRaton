#include "Test.h"
#include <iostream>
#include <map>
#include <climits>
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
}

vector<int> getPath(int **DAG, int size, int source, int destination)
{
  vector<int> answer;
  std::vector<int> alterAnswer;
  /*
    0->4
    graph1[0][1]=10; //[FROM][TO]
    graph1[1][2]=20;
    graph1[2][3]=30;
    graph1[3][4]=40;
  */
  /*
    0->4
    graph2[0][1]=40;
    graph2[0][2]=30;
    graph2[1][3]=20;
    graph2[2][4]=10;
  */
  int currentNode = source;
  int alterPath = source;
  int firstPathTakenBySource = -1;
  bool foundPath = false;
  while (foundPath) {
    int firstTime = true;
    int diffVal = 0;
    for (int i = 0; i < size; i++)
    {
      for (int k = 0; k < size; k++)
      {
        int cost = DAG[i][k];
        if(cost != -1)
        {
          if(k == firstPathTakenBySource)
          {
            continue;
          }
          if(i == currentNode)
          {
            answer.push_back(k);
            currentNode = k;
            if(firstPathTakenBySource == -1)
            {
              firstPathTakenBySource = k;
            }

            if(currentNode == destination)
            {
              printVector(answer);
              cout<<endl;
              foundPath = true;
              return answer;
            }
          }
        }
      }
      if(!foundPath)
      {
        firstTime = true;
        diffVal++;
      }
    }
  }

  return answer;
}


int main ()
{
    test();
    return 0;
}
