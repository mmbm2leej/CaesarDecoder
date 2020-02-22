#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

using std::string; using std::vector; using std::cout; using std::endl; using std::sort; using std::vector;

#pragma region freqs in english language
static vector<double> engFreqs = { .08167, .01492, .02782, .04253, .12702,
									.02228, .02015, .06094, .06966, .00153,
									.00772, .04025, .02406, .06749, .07507,
									.01929, .00095, .05987, .06327, .09056,
									.02758, .00978, .02360, .00150, .01974,
									.00074 };



#pragma endregion

int letterCorrect(int x, int y) { //in case it wraps around Z backward
	return ((x - y) >= 0) ? (x - y) : (x - y + 26);
}

int letterCorrectFwd(int x, int y) {
	return ((x + y) <= 90) ? (x + y) : (x + y - 26);
}

double findStandardFreq(int x) {
	return engFreqs.at(x);
}

void printString(std::string x) {
	cout << x << endl;
}

int main() {

/*
cout << "Please enter the cipher message without punctuation marks." << endl;
cin >> testStr;

*/


	string testStr = "ASEGFUDGMVFAFW";

	// convert string to upper case
	std::for_each(testStr.begin(), testStr.end(), [](char& c) {
		c = ::toupper(c);
		});


	for (size_t i = 0; i < testStr.size(); ++i) {
		if (testStr[i] == ' ') {
			testStr.erase(testStr.begin() + i);
		}
	}

	printString(testStr);


	size_t cipherLength = testStr.size();
	cout << "cipherLength: " << cipherLength << "\n";
	string strCopy = testStr;

	size_t strCopyLength = strCopy.size();




	strCopy = testStr;

	//cout << "strCopy.size(): " << strCopy.size() << "\n";

	//index 0 = A, index 1 = B... index 25 = Z;
	vector<int> letterCount(26, 0);
	vector<int> letterSpare(26, 0);

	for (size_t i = 0; i < strCopy.size(); ++i) {

		switch (strCopy[i]) {
			case 'A': letterCount[0]++; break;
			case 'a': letterCount[0]++; break;
			case 'B': letterCount[1]++; break;
			case 'b': letterCount[1]++; break;
			case 'C': letterCount[2]++; break;
			case 'c': letterCount[2]++; break;
			case 'D': letterCount[3]++; break;
			case 'd': letterCount[3]++; break;
			case 'E': letterCount[4]++; break;
			case 'e': letterCount[4]++; break;
			case 'F': letterCount[5]++; break;
			case 'f': letterCount[5]++; break;
			case 'G': letterCount[6]++; break;
			case 'g': letterCount[6]++; break;
			case 'H': letterCount[7]++; break;
			case 'h': letterCount[7]++; break;
			case 'I': letterCount[8]++; break;
			case 'i': letterCount[8]++; break;
			case 'J': letterCount[9]++; break;
			case 'j': letterCount[9]++; break;
			case 'K': letterCount[10]++; break;
			case 'k': letterCount[10]++; break;
			case 'L': letterCount[11]++; break;
			case 'l': letterCount[11]++; break;
			case 'M': letterCount[12]++; break;
			case 'm': letterCount[12]++; break;
			case 'N': letterCount[13]++; break;
			case 'n': letterCount[13]++; break;
			case 'O': letterCount[14]++; break;
			case 'o': letterCount[14]++; break;

			case 'P': letterCount[15]++; break;
			case 'p': letterCount[15]++; break;
			case 'Q': letterCount[16]++; break;
			case 'q': letterCount[16]++; break;
			case 'R': letterCount[17]++; break;
			case 'r': letterCount[17]++; break;
			case 'S': letterCount[18]++; break;
			case 's': letterCount[18]++; break;
			case 'T': letterCount[19]++; break;
			case 't': letterCount[19]++; break;

			case 'U': letterCount[20]++; break;
			case 'u': letterCount[20]++; break;
			case 'V': letterCount[21]++; break;
			case 'v': letterCount[21]++; break;
			case 'W': letterCount[22]++; break;
			case 'w': letterCount[22]++; break;
			case 'X': letterCount[23]++; break;
			case 'x': letterCount[23]++; break;
			case 'Y': letterCount[24]++; break;
			case 'y': letterCount[24]++; break;
			case 'Z': letterCount[25]++; break;
			case 'z': letterCount[25]++;
		}
	}

	/*Print the letterCount

	for (size_t i = 0; i < letterCount.size(); ++i) {
		cout << letterCount.at(i) << " ";

	}
	*/

	letterSpare = letterCount;

	//Find top 5 characters
	vector<char> topfiveLetters(5, ' ');
	vector<int> topfiveCounts(5, 0);
	vector<double> topfiveFreqs(5, 0.0);

	//65 > A, 90 > Z
	for (int i = 0; i < topfiveLetters.size(); ++i) {
		double highestfreqratio = 0.0;
		int highestLetter = 0;
		int highestCount = 0;
		for (int j = 0; j < letterCount.size(); ++j) {
		
			if (letterCount.at(j) > highestCount) {
				highestCount = letterCount.at(j);
				highestLetter = j;
			}

		}

		topfiveCounts[i] = highestCount;
		topfiveFreqs[i] = highestCount / ((double)strCopyLength);
		topfiveLetters[i] = (char)highestLetter+65;
		letterCount[highestLetter] = 0;
		cout << topfiveLetters.at(i) << " has a frequency of " << topfiveCounts.at(i) << " with ratio " << topfiveFreqs.at(i) << "\n";
	
	}

	std::vector<bool> topfiveFlags(5, true);
	//true means unique and nonzero, false will mean to ignore
	

	
	//erase zeroes freqs and duplicates
	for (int i = 1; i < topfiveFlags.size(); ++i) {
		if (topfiveCounts[i - 1] == topfiveCounts[i]) {
			topfiveFlags[i] = false;
		}
		else if (topfiveCounts[i] == 0) topfiveFlags[i] = false;
	}

	cout << "\n\n\n";
	
	/*
	for (int i = 0; i < topfiveFlags[i]; ++i) {
		if (topfiveFlags[i] == false) {
			topfiveCounts.erase(topfiveCounts.begin() + i);
			topfiveLetters.erase(topfiveLetters.begin() + i);
			topfiveFreqs.erase(topfiveFreqs.begin() + i);
			topfiveFlags.erase(topfiveFlags.begin() + i);
		}

	}
	*/


	/*
	Correlation(i) = (freq1) * ( p(18-i) + p(4-i) + p(20-i) + p(3-i) + p(22-i) + p(21-i) + p(12-i)) + (freq2) * ( p(0-i) + p(6-i) ) + (freq3) * ( p(5-i) )
	
	*/

	vector<int> firstfreqletterints = {};
	vector<int> secondfreqletterints = {};
	vector<int> thirdfreqletterints = {};

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < letterSpare.size(); ++j) {
			if (letterSpare[j] == topfiveCounts[i]) {
				//cout << "Found match: " << letterSpare[j] << " with " << topfiveCounts[i] << "\n";
				if (i == 0) firstfreqletterints.emplace_back(j);
				else if (i == 1) secondfreqletterints.emplace_back(j);
				else if (i == 2) thirdfreqletterints.emplace_back(j);
			}
		}
	}

	
	//Show the letters of matching leading counts
	cout << "First Highest Freq Letter Ints:\n";
	for (size_t i = 0; i < firstfreqletterints.size(); ++i) {
		cout << (char)(firstfreqletterints[i] + 65) << "\n";
	}
	cout << "\n\n\n";
	cout << "Second Highest Freq Letter Ints:\n";
	for (size_t i = 0; i < secondfreqletterints.size(); ++i) {
		cout << (char)(secondfreqletterints[i] + 65) << "\n";
	}
	cout << "\n\n\n";
	cout << "Third Highest Freq Letter Ints:\n";
	for (size_t i = 0; i < thirdfreqletterints.size(); ++i) {
		cout << (char)(thirdfreqletterints[i] + 65) << "\n";
	}
	cout << "\n\n\n";

	double firstcoeff;
	double secondcoeff;
	double thirdcoeff;
	double correlationcoeff;
	vector<double> intervalFreqs = {};

	for (int i = 0; i < 3; ++i) {
		cout << topfiveFreqs.at(i) << "\n";
	}

	for (int i = 0; i < 26; ++i) {	//for each letter in the Alphabet
		firstcoeff = 0.0;
		secondcoeff = 0.0;
		thirdcoeff = 0.0;
		correlationcoeff = 0.0;

		for (int j = 0; j < firstfreqletterints.size(); ++j) {
			firstcoeff += findStandardFreq(letterCorrect(j,i));
		}
		for (int j = 0; j < secondfreqletterints.size(); ++j) {
			secondcoeff += findStandardFreq(letterCorrect(j, i));
		}
		for (int j = 0; j < thirdfreqletterints.size(); ++j) {
			thirdcoeff += findStandardFreq(letterCorrect(j, i));
		}
		/*
		cout << "firstcoeff is for " << (char)(i + 65) << ": " << firstcoeff << "\n";
		cout << "secondcoeff is for " << (char)(i + 65) << ": " << secondcoeff << "\n";
		cout << "thirdcoeff is for " << (char)(i + 65) << ": " << thirdcoeff << "\n";
		*/

		correlationcoeff = (topfiveFreqs.at(0) * firstcoeff) + (topfiveFreqs.at(1) * secondcoeff) + (topfiveFreqs.at(2) * thirdcoeff);
		cout << "Correlation Factor at interval " << i << ": " << correlationcoeff << "\n";
		intervalFreqs.emplace_back(correlationcoeff);
	}
	cout << "\n\n\n";

	int highint, sechighint, thirdhighint, fourthhighint, fifthhighint;
	double highestratio = 0.0;
	int highestindex = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < intervalFreqs.size(); ++j) {
			if (intervalFreqs.at(j) > highestratio) {
				highestratio = intervalFreqs.at(j);
				highestindex = j;
			}
		}
		intervalFreqs[highestindex] = 0.0;
		
		if (i == 0) {
			highint = highestindex;
			cout << highint << "\n";
		}
		else if (i == 1) {
			sechighint = highestindex; 
			cout << sechighint << "\n";
		}
		else if (i == 2) {
			thirdhighint = highestindex;
			cout << thirdhighint << "\n";
		}
		else if (i == 3) {
			fourthhighint = highestindex;
			cout << fourthhighint << "\n";
		}
		else if (i == 4) {
			fifthhighint = highestindex; 
			cout << fifthhighint << "\n";
		}

		highestratio = 0.0;
		highestindex = 0;
	}

	//cout << strCopy << "\n";
	cout << "\n\n\n\n";
	cout << "Possible Plaintext Translations:" << "\n\n";
	
	for (int i = 0; i < strCopy.size(); ++i) {
		cout << (char)letterCorrectFwd((int)strCopy.at(i), highint);	
	}
	cout << "\n\n";
	for (int i = 0; i < strCopy.size(); ++i) {
		cout << (char)letterCorrectFwd((int)strCopy.at(i), sechighint);
	}
	cout << "\n\n";
	for (int i = 0; i < strCopy.size(); ++i) {
		cout << (char)letterCorrectFwd((int)strCopy.at(i), thirdhighint);
	}
	cout << "\n\n";
	for (int i = 0; i < strCopy.size(); ++i) {
		cout << (char)letterCorrectFwd((int)strCopy.at(i), fourthhighint);
	}
	cout << "\n\n";
	for (int i = 0; i < strCopy.size(); ++i) {
		cout << (char)letterCorrectFwd((int)strCopy.at(i), fifthhighint);
	}
	cout << "\n\n";
	for (int i = 0; i < strCopy.size(); ++i) {
		cout << (char)letterCorrect((int)strCopy.at(i), highint);
	}
	cout << "\n\n";
	for (int i = 0; i < strCopy.size(); ++i) {
		cout << (char)letterCorrect((int)strCopy.at(i), sechighint);
	}
	cout << "\n\n";
	for (int i = 0; i < strCopy.size(); ++i) {
		cout << (char)letterCorrect((int)strCopy.at(i), thirdhighint);
	}
	cout << "\n\n";
	for (int i = 0; i < strCopy.size(); ++i) {
		cout << (char)letterCorrect((int)strCopy.at(i), fourthhighint);
	}
	cout << "\n\n";
	for (int i = 0; i < strCopy.size(); ++i) {
		cout << (char)letterCorrect((int)strCopy.at(i), fifthhighint);
	}
	cout << "\n\n";

	



	system("Pause");
	return 0;
} 