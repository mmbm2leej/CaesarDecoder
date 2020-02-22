#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

using std::string; using std::vector; using std::cout;

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main() {

#pragma region freqs in english language
	std::array<double, 26> engFreqs = { .08167, .01492, .02782, .04253, .12702,
								.02228, .02015, .06094, .06966, .00153,
								.00772, .04025, .02406, .06749, .07507,
								.01929, .00095, .05987, .06327, .09056,
								.02758, .00978, .02360, .00150, .01974,
								.00074 };



#pragma endregion


//create freq stores in the ciphertext
//index 0 = A, index 1 = B... index 25 = Z;
std::vector<int> cipherCount(26, 0);
int charCountTotal = 0;
//Take the cypher string
string testStr = "Pm ol ohk hufaopun jvumpkluaphs av zhf, ol dyval pa pu jpwoly.\n";

//convert the string to array of char
vector<char> letterArr;

for (int i = 0; i < testStr.size(); i++) {
	if (isalpha(testStr[i])) {
		letterArr.emplace_back(testStr[i]);
		charCountTotal++;
	}
	else if (testStr[i] == ' ') letterArr.emplace_back(' ');
	
}

for (int i = 0; i < letterArr.size(); i++) cout << letterArr[i];

//count the cipherletters and put them in the count vector
for (int i = 0; i < letterArr.size(); i++) {
	if ((letterArr[i] == 'a') || (letterArr[i] == 'A')) cipherCount[0]++;	//A
	if ((letterArr[i] == 'b') || (letterArr[i] == 'B')) cipherCount[1]++;	//B
	if ((letterArr[i] == 'c') || (letterArr[i] == 'C')) cipherCount[2]++;	//C
	if ((letterArr[i] == 'd') || (letterArr[i] == 'D')) cipherCount[3]++;	//D
	if ((letterArr[i] == 'e') || (letterArr[i] == 'E')) cipherCount[4]++;	//E

	if ((letterArr[i] == 'f') || (letterArr[i] == 'F')) cipherCount[5]++;	//F
	if ((letterArr[i] == 'g') || (letterArr[i] == 'G')) cipherCount[6]++;	//G
	if ((letterArr[i] == 'h') || (letterArr[i] == 'H')) cipherCount[7]++;	//H
	if ((letterArr[i] == 'i') || (letterArr[i] == 'I')) cipherCount[8]++;	//I
	if ((letterArr[i] == 'j') || (letterArr[i] == 'J')) cipherCount[9]++;	//J

	if ((letterArr[i] == 'k') || (letterArr[i] == 'K')) cipherCount[10]++;	//K
	if ((letterArr[i] == 'l') || (letterArr[i] == 'L')) cipherCount[11]++;	//L
	if ((letterArr[i] == 'm') || (letterArr[i] == 'M')) cipherCount[12]++;	//M
	if ((letterArr[i] == 'n') || (letterArr[i] == 'N')) cipherCount[13]++;	//N
	if ((letterArr[i] == 'o') || (letterArr[i] == 'O')) cipherCount[14]++;	//O

	if ((letterArr[i] == 'p') || (letterArr[i] == 'P')) cipherCount[15]++;	//P
	if ((letterArr[i] == 'q') || (letterArr[i] == 'Q')) cipherCount[16]++;	//Q
	if ((letterArr[i] == 'r') || (letterArr[i] == 'R')) cipherCount[17]++;	//R
	if ((letterArr[i] == 's') || (letterArr[i] == 'S')) cipherCount[18]++;	//S
	if ((letterArr[i] == 't') || (letterArr[i] == 'T')) cipherCount[19]++;	//T

	if ((letterArr[i] == 'u') || (letterArr[i] == 'U')) cipherCount[20]++;	//U
	if ((letterArr[i] == 'v') || (letterArr[i] == 'V')) cipherCount[21]++;	//V
	if ((letterArr[i] == 'w') || (letterArr[i] == 'W')) cipherCount[22]++;	//W
	if ((letterArr[i] == 'x') || (letterArr[i] == 'X')) cipherCount[23]++;	//X
	if ((letterArr[i] == 'y') || (letterArr[i] == 'Y')) cipherCount[24]++;	//Y	
	if ((letterArr[i] == 'z') || (letterArr[i] == 'Z')) cipherCount[25]++;	//Z
}

//FOR DEBUG - show frequency counts
for (char i = 65; i < 91; i++) {
	cout << i << " has occured" << cipherCount[i - 65] << " times." << "\n";
}
	
//store the frequencies in parts of ONE
vector<double> letterFreqRatios;
	
for (auto count : cipherCount) {
	double ratio = ((count * 1.0) / charCountTotal);
	letterFreqRatios.emplace_back(ratio);
}

double highestFreq = 0, secondHighestFreq = 0, thirdHighestFreq = 0, fourthHighestFreq = 0, fifthHighestFreq = 0;
char highLetter, secHighLetter, thirdHighLetter, fourHighLetter, fifthHighLetter;

#pragma region  Find the five highest freqs and letters

	//show all
	for (char i = 65; i < 91; i++) {
		cout << i << " has frequency of " << letterFreqRatios[i - 65] << "\n";	//show each freq
	}

	//find the highest frequency
	for (char i = 65; i < 91; i++) {
		if (letterFreqRatios[i - 65] > highestFreq) {
			highestFreq = letterFreqRatios[i - 65];
			highLetter = i;
		}
	}

	//Mute the highest in the list
	letterFreqRatios[highLetter - 65] = 0;

	//find the second highest frequency
	for (char i = 65; i < 91; i++) {
		if (letterFreqRatios[i - 65] > secondHighestFreq) {
			secondHighestFreq = letterFreqRatios[i - 65];
			secHighLetter = i;
		}
	}

	//Mute the second highest in the list
	letterFreqRatios[secHighLetter - 65] = 0;

	//find the third highest frequency
	for (char i = 65; i < 91; i++) {
		if (letterFreqRatios[i - 65] > thirdHighestFreq) {
			thirdHighestFreq = letterFreqRatios[i - 65];
			thirdHighLetter = i;
		}
	}

	//Mute the third highest in the list
	letterFreqRatios[thirdHighLetter - 65] = 0;

	//find the fourth highest frequency
	for (char i = 65; i < 91; i++) {
		if (letterFreqRatios[i - 65] > fourthHighestFreq) {
			fourthHighestFreq = letterFreqRatios[i - 65];
			fourHighLetter = i;
		}
	}

	//Mute the fourth highest in the list
	letterFreqRatios[fourHighLetter - 65] = 0;

	//find the fifth highest frequency
	for (char i = 65; i < 91; i++) {
		if (letterFreqRatios[i - 65] > fifthHighestFreq) {
			fifthHighestFreq = letterFreqRatios[i - 65];
			fifthHighLetter = i;
		}
	}

	//Mute the fifth highest in the list
	letterFreqRatios[fifthHighLetter - 65] = 0;

	//Show all of the highest freqs
	/*
	cout << "\n\nHighest freq is " << highestFreq << " with letter " << highLetter << "\n";
	cout << "Second Highest freq is " << secondHighestFreq << " with letter " << secHighLetter << "\n";
	cout << "Third Highest freq is " << thirdHighestFreq << " with letter " << thirdHighLetter << "\n";
	cout << "Fourth Highest freq is " << fourthHighestFreq << " with letter " << fourHighLetter << "\n";
	cout << "Fifth Highest freq is " << fifthHighestFreq << " with letter " << fifthHighLetter << "\n\n";
	*/

	//show all
	for (char i = 65; i < 91; i++) {
		cout << i << " has frequency of " << letterFreqRatios[i - 65] << "\n";	//show each freq
	}

#pragma endregion




	
	/*
	The formula would be:

			Correlation(i) = (freq1) * ( p(18-i) + p(4-i) + p(20-i) + p(3-i) + p(22-i) + p(21-i) + p(12-i)) + (freq2)
			* ( p(0-i) + p(6-i) ) + (freq3) * ( p(5-i) )

			Where p is a function that gives a certain frequency value depending on what the constant minus i will be. 
			The chart provided in the frequencies in the english language was used.

			I have constructed a program in Visual Studio to calculate all correlation values for i = 0(meaning “A”) 
			all the way to i=25(meaning “Z”). The program was tailored specifically this message, although it could have 
			been constructed to handle all possible given ciphertext letters.

	
	
	*/


	system("Pause");
	return 0;
}
