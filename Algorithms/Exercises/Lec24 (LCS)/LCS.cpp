/*
*
* Problem description:
* Implement the longest common subsequent problem algorithm.
*
*/

#include <iostream>
#include <vector>
#include <stdexcept> 
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <climits>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::priority_queue;
using std::unordered_map;

/************************* Declarations **************************/
/****************************************************************/

void get_string(string & inStr);
/////////////////////////////////////////////////////////////////////
int longestCommonSubsequenceNum(string text1, string text2);
/////////////////////////////////////////////////////////////////////
string longestCommonSubsequenceStr(string text1, string text2);
/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");
	
	string txt1{""};
	string txt2{""};
	int LCS_Num{0};
	string LCS_Str{""};
	
	cout << "\n Enter the first string: ";
	get_string(txt1);
	
	cout << "\n Enter the second string: ";
	get_string(txt2);
	
	LCS_Num = longestCommonSubsequenceNum(txt1, txt2);
	
	cout << "\n The longest common subsequence length is: " << LCS_Num ;
	
	LCS_Str = longestCommonSubsequenceStr(txt1, txt2);
	
	cout << "\n The longest common subsequence string is: " << LCS_Str ;
	
    return 0;

}
/********************* Function definitions *********************/
/****************************************************************/

void get_string(string & inStr)
{
    std::getline(cin, inStr);
}
/*---------------------------------------------------------------------------*/
int longestCommonSubsequenceNum(string text1, string text2)
{
	
	int result{0};
	int tx1Len{0};
	int tx2Len{0};
	
	tx1Len = text1.length();
	tx2Len = text2.length();
	
	text1 = " " + text1;
	text2 = " " + text2;
	
	vector<vector<int>> graph(tx2Len + 1, vector<int>(tx1Len + 1, 0));
	
	for(int i = 1; i <= tx2Len; ++i)
	{
		
		for(int j = 1; j <= tx1Len; ++j)
		{
			
			if(text2[i] == text1[j])
			{
				graph[i][j] = 1 + graph[i-1][j-1]; // 1 + top left corner
			}
			else
			{
				graph[i][j] = std::max(graph[i][j-1], graph[i-1][j]); // max(left, top)
			}
		}
		
	}
	
	result = graph[tx2Len][tx1Len];
	
	return result;
	
}
/*---------------------------------------------------------------------------*/
string longestCommonSubsequenceStr(string text1, string text2)
{
	
	string result{""};
	int tx1Len{0};
	int tx2Len{0};
	
	tx1Len = text1.length();
	tx2Len = text2.length();
	
	text1 = " " + text1;
	text2 = " " + text2;
	
	vector<vector<int>> graph(tx2Len + 1, vector<int>(tx1Len + 1, 0));
	
	for(int i = 1; i <= tx2Len; ++i)
	{
		
		for(int j = 1; j <= tx1Len; ++j)
		{
			
			if(text2[i] == text1[j])
			{
				graph[i][j] = 1 + graph[i-1][j-1]; // 1 + top left corner
			}
			else
			{
				graph[i][j] = std::max(graph[i][j-1], graph[i-1][j]); // max(left, top)
			}
		}
		
	}
	
	int i{tx2Len};
	int j{tx1Len};
	
	while(i > 0 && j > 0)
	{
		
		if(graph[i][j] > graph[i][j-1]) // Num in row > left
		{
			if(graph[i][j] == graph[i-1][j]) // Num in row == top
			{
				i--; // Move to the upper row
			}
			else
			{
				result = text2[i] + result;
				i--;
				j--;
			}
		}
		else
		{
			j--; // Move in the row tfrom right to left till hit a num > left 
		}
		
	}
	
	return result;
}

/****************************************************************/
/****************************************************************/