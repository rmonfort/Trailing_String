#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;

// Returns 1 if the string b occurs at the end of string a
bool rear_compare(const string& a, const string& b)
{
	if (a.length() < b.length())
	{
		return 0;
	}
	else if (a == b)
	{
		return 1;
	}
	else
	{
		// A reverse iterator and an index used to compare a and b
		int index_a = a.length() - 1;
		for (auto i = b.crbegin(); i != b.crend(); i++)
		{
			if (*i == a[index_a])
			{
				index_a--;
			}
			else
			{
				return 0;
			}
		}
	}
	return 1;
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		// Ignore empty lines
		if (line == "")
		{
			continue;
		}

		// Get each part of the line and compare them accordingly
		istringstream iss(line);
		string a, b;
		getline(iss, a, ',');
		getline(iss, b, ',');
		bool result = rear_compare(a, b);
		cout << result << endl;
	}

	return 0;
}