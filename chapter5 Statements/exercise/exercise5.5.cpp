#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{	
	const string grades[] = {"reach", "good", "good", "perfect"};
	int score;
	cout << "> ";
	while (cin >> score && score >= 0 && score <= 100) {
		string result;
		if (score >= 60) {
			if (score != 100) {
				result += grades[(score - 60) / 10];
				int rem = score % 10;
				if (rem <= 3)
					result += "-";
				else if (rem >= 7)
					result += "+";
			} else
				result += grades[3] + "++";
		} else 
			result += "failed";
		
		cout << result << endl;
		cout << "> ";
	}



	return 0;
}