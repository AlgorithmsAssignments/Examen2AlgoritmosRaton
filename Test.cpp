#include "Test.h"

int** _initGraph(int size)
{
    int **answer = new int* [size];
    for(int i=0;i<size;i++)
    {
        answer[i]=new int[size];
        for(int j=0;j<size;j++)
        {
            answer[i][j]=-1;
        }
    }
    return answer;
}

bool _checkPath(int**DAG, int source, int destination, vector<int> path)
{
    for(int i=0;i<(int)path.size();i++)
    {
        if(DAG[source][path[i]] == -1)
          return false;
        source = path[i];
    }
    return source == destination;
}

void test()
{

    if(longestPalindromicSubsequence("BBABCBCAB") == 7
       && longestPalindromicSubsequence("LAZORRAARROZCONFRIJOLES") == 12
       && longestPalindromicSubsequence("AZULITODECORAZON") == 5
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

    int** graph1 = _initGraph(5);

    graph1[0][1]=10;
    graph1[1][2]=20;
    graph1[2][3]=30;
    graph1[3][4]=40;

    vector<int> answer1 = getPath(graph1, 5, 0, 4);

    int** graph2 = _initGraph(5);

    graph2[0][1]=40;
    graph2[0][2]=30;
    graph2[1][3]=20;
    graph2[2][4]=10;

    vector<int> answer2 = getPath(graph2, 5, 0, 4);

    int** graph3 = _initGraph(7);

    graph3[0][1]=10;
    graph3[1][2]=30;
    graph3[1][3]=10;
    graph3[1][4]=20;
    graph3[2][6]=10;
    graph3[3][5]=10;
    graph3[4][5]=50;
    graph3[5][6]=30;

    vector<int> answer3 = getPath(graph3, 7, 0, 6);

    if(_checkPath(graph1, 0, 4, answer1)
       && _checkPath(graph2, 0, 4, answer2)
       && _checkPath(graph3, 0, 6, answer3)
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
