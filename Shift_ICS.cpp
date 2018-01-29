#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string to_string(int n, int len)
{
	string result(len--, '0');
	for (int val=(n<0)?-n:n; len>=0&&val!=0; --len,val/=10)
	   result[len]='0'+val%10;
	if (len>=0&&n<0) result[0]='-';
	return result;
}

void shiftDateBy(int shiftBy)
{
	//TODO
}

void shift(string fileName, int shiftBy)
{
	string line;
	ifstream inputFile(fileName);
	ofstream outputFile;
	outputFile.open("SHIFTED_" + fileName);
	if (inputFile.is_open() && outputFile.is_open() )
	{
		while ( getline(inputFile,line) )
		{
			if (line.find("DTEND") == 0 || line.find("DTSTART") == 0)
			{
				int newTime = stoi( line.substr(line.length()-7, 2) ) + shiftBy;
				if (newTime < 0)
				{
					newTime += 24;
					shiftDateBy(-1);
				}
				else if (newTime >= 24)
				{
					newTime %= 24;
					shiftDateBy(1);
				}
				line.replace(line.length()-7,2,to_string(newTime, 2));
			}
			outputFile << line;
		}
		inputFile.close();
		outputFile.close();
	}
	else cout << "The filename oyu entered is not valid" << endl;
}

string getFileName()
{
	string fileName;
	cout << "Enter filename: ";
	cin >> fileName;
	return fileName;
}

int getTimeZone()
{
	int timeZone = 13;
	while (abs(timeZone) >= 12 )
	{
		string input;
		cout << "Enter your timezone: (eg. UTC+1, UTC-11)" << endl << "UTC";
		cin >> input;
		timeZone = stoi(input);
	}
	return timeZone;
}

int main()
{
	shift(getFileName(), -getTimeZone());
	return 0;
}
