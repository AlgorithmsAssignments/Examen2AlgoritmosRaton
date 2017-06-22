#include "Test.h"
#include <iostream>
#include <map>
using namespace std;

int longestPalindromicSubsequence(string sequence, int begin, int end)
{
   if (begin == end)
     return 1;

   if (sequence[begin] == sequence[end] && begin + 1 == end)
     return 2;

   if (sequence[begin] == sequence[end])
      return longestPalindromicSubsequence(sequence, begin+1, end-1) + 2;

   return max( longestPalindromicSubsequence(sequence, begin, end-1),
           longestPalindromicSubsequence(sequence, begin+1, end) );
}

int longestPalindromicSubsequence(string sequence)
{
  return longestPalindromicSubsequence(sequence, 0, sequence.size()-1);
}

vector<int> getPath(int **DAG, int size, int source, int destination)
{
  vector<int> answer;
  return answer;
}


int main ()
{
    test();
    return 0;
}
