
using namespace std;
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
template <class T>
vector<T> split(T str, T delimiter) {
	size_t pos = 0;
	str.append(" ");
	vector<T> words{};
	while ((pos = str.find(delimiter)) != string::npos)
	{
		words.push_back(str.substr(0, pos));
		str.erase(0, pos + delimiter.length());
	}
	return words;
}

void DontClose() {
	string str;
	cout << "Enter to continue";
	getline(cin, str);
	system("CLS");
}
int main() {

	vector<string> Stringlist;
	vector<string>::iterator it;
	vector<int> IntString{};
	vector<int> Inttransactions;


	string str;
	string delimeter = " ";

	while (true)
	{

		cout << "type exit to exit: " << endl;
		cout << "or write what is to be calculated(please leave a space between): ";
		getline(cin, str);
		if (str == "exit")
		{
			exit(1);
		}
		Stringlist = split<string>(str, delimeter);

		for (const auto &obj : Stringlist)
		{
			try
			{
				int num = stoi(obj);
				IntString.push_back(num);
			}
			catch (const std::exception&)
			{
				if (obj == "+")
				{
					Inttransactions.push_back(1);
				}
				if (obj == "-")
				{
					Inttransactions.push_back(2);
				}
				if (obj == "*")
				{
					Inttransactions.push_back(3);
				}
				if (obj == "/")
				{
					Inttransactions.push_back(4);
				}
			}
		}

		sort(Inttransactions.begin(), Inttransactions.end(),greater<int>());

	
		float a;
		float b;
		int pos;
		try
		{
			for (const int& obj : Inttransactions) {
				float result;
				switch (obj)
				{
				case 1:
					it = find(Stringlist.begin(),Stringlist.end(),"+");
					pos = it - Stringlist.begin();
					a = (float)stof(Stringlist[pos - 1]);
					b = (float)stof(Stringlist[pos + 1]);
					result =a + b;
					Stringlist.erase(Stringlist.begin() + pos - 1, Stringlist.begin() + pos + 2);
					Stringlist.insert(Stringlist.begin() + (pos - 1), to_string(result));
					break;
				case 2:
					it = find(Stringlist.begin(), Stringlist.end(), "-");
					pos = it - Stringlist.begin();
					a = (float)stof(Stringlist[pos - 1]);
					b = (float)stof(Stringlist[pos + 1]);
					result = a - b;
					Stringlist.erase(Stringlist.begin() + pos - 1, Stringlist.begin()+ pos + 2);
					Stringlist.insert(Stringlist.begin() + (pos - 1), to_string(result));
					break;
				case 3:
					it = find(Stringlist.begin(), Stringlist.end(), "*");
					pos = it - Stringlist.begin();
					a = (float)stof(Stringlist[pos - 1]);
					b = (float)stof(Stringlist[pos + 1]);
					result = a * b;
					Stringlist.erase(Stringlist.begin() + pos - 1, Stringlist.begin() + pos + 2);
					Stringlist.insert(Stringlist.begin()+(pos - 1), to_string(result));
					break;
				case 4:
					it = find(Stringlist.begin(), Stringlist.end(), "/");
					pos = it - Stringlist.begin();
					a = (float)stof(Stringlist[pos - 1]);
					b = (float)stof(Stringlist[pos + 1]);
					result = a / b;
					Stringlist.erase(Stringlist.begin() + pos - 1, Stringlist.begin() + pos + 2);
					Stringlist.insert(Stringlist.begin() + (pos - 1), to_string(result));
					break;
				default:
					string str;
					cout << "unidentified error : "<< endl;
					cout << "enter to try again";
					getline(cin, str);
					system("CLS");
					break;
				}
			}
		}
		catch (const std::exception& err)
		{
			string str;
			cout << "Something went wrong this is the error: " << err.what() << endl;
			cout << "enter to exit";
			getline(cin, str);
			system("CLS");
			exit;
		}
		if (Inttransactions.size() == 0)
		{
			string str;
			cout << "unidentified error !!!";
			getline(cin, str);
			system("CLS");
		}
		else
		{
			cout << setprecision(10);
			for (const auto& obj : Stringlist) {
				cout << obj<<endl;
			}
		}

		DontClose();
		Stringlist.clear();
		IntString.clear();
		Inttransactions.clear();
	}
}

