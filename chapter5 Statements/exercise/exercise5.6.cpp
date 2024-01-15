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

		result += score < 60 ? "failed" : score == 100 ? grades[3] + "++" : grades[(score - 60) / 10] +
			(score <= 3 ? "-" : score >= 7 ? "+" : ""); 
			
		cout << result << endl;
		cout << "> ";
	}



	return 0;
}