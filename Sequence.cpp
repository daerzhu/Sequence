#include "Sequence.h"
#include<string.h>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
Sequence::Sequence(char* filename)
{
	a = 0, g = 0, c = 0, t = 0, count = 0;
	ifstream myFile;
	myFile.open(filename);
	char temp;
	if (!myFile)
	{
		cout << "can not be read" << endl;
	}
	while (myFile >> temp)
	{
		if (temp != '\n'&&temp)
		{
			switch (temp)
			{
			case'A':a++;
				break;
			case'G':g++;
				break;
			case'C':c++;
				break;
			case'T':t++;
				break;
			default:break;
			}
			s += temp;

		}
	}
	count = a + g + c + t;

}

int Sequence::length()
{
	return count;
}

int Sequence::numberOf(char base)
{
	switch (base)
	{
	case'A':return a;
		break;
	case'G':return g;
		break;
	case'C':return c;
		break;
	case'T':return t;
		break;
	default:cout << "error";
		    
	}
}

string Sequence::longestConsecutive()
{
	int lon =1;
	int tlon = 1;
	int pos = 0;
	char zimu = s[0];
	for (int i = 1;i < count;i++)
	{
		if (s[i] != zimu)
		{
			if (tlon > lon)
			{
				lon = tlon;
				pos = i - tlon;
				zimu = s[i];
				tlon = 1;
				
			}
			else
			{
				tlon = 1;
				zimu = s[i];

			}
		}
		else tlon++;
	}
	if (tlon > lon)
	{
		lon = tlon;
		pos = count - tlon;
	}
return s.substr(pos,lon);
}


int comlen(char *p, char *q)
{
	int i = 0;
	while (*p && (*p++ = *q++))
	{
		i++;
	}
	return i;
}

int pstrcmp(const void*p1, const void *p2)
{
	return strcmp(*(char* const *)p1, *(char*const*)p2);
}
string Sequence::longestRepeated()
{
#define MAXCHAR 1000005
	int temp;
	int max_len = 0,maxi = 0;
        char *cn;
	cn = new char[MAXCHAR];
	char**an;
	an = new char*[MAXCHAR];
	for (int n = 0; n <= count; n++)
	{      if( n < count)
		{cn[n] = s[n];
		an[n] = &cn[n];}
               if(n == count)
                {
                  cn[n] = '\0'; 
                }
	}

        qsort(an, count, sizeof(char*), pstrcmp);
	for (int i = 0; i < count - 1;i++)
	{
		temp = comlen(an[i], an[i + 1]);
		if (temp > max_len)
		{
	         max_len = temp;
			maxi = i;
		}
	}
        delete[]cn;
        delete[]an;
	return s.substr(maxi,max_len);
}

