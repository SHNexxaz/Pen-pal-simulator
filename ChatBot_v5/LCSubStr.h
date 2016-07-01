#pragma once
#include <string>
#include <vector>


std::string LCSubstr(std::string& x, std::string& y)
{
	size_t m = x.length();
    size_t n = y.length();

	//int** LCSuff = new int*[m];
	//auto array = new int[m][n]();
	int *LCSuff = new int[m*n];

	for (int i = 0; i <= m; i++)
		LCSuff[i] = 0;
	for (int j = 0; j <= n; j++)
		LCSuff[j] = 0;


	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
				LCSuff[j*m + i] = LCSuff[(j - 1)*m + (i - 1)];
			else
				LCSuff[j*m + 1] = 0;
		}
	}

	std::string longest = "";
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (LCSuff[j*m + i] > longest.length())
				longest = x.substr((i - LCSuff[j*m + i]), LCSuff[j*m + 1]);
		}
	}
	return longest;
}


//string.subsur: you can use this function to return a substring of the invoking string object. 
//string substr(int pos = 0, int n = string::npos) const;
//It returns a string copied starting at index pos for n characters or up to the end of the invoking string object, whichever comes first.
//If only pos is supplied, the function returns the string copied starting at index pos until the end of the invoking string object.
//If no arguments are supplied, the function simply returns a string identical to the invoking string object.


