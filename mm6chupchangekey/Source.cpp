#include <stdio.h>
#include <stdlib.h>
#include <string>
//#include <conio.h>
#include <algorithm>
#include <iterator>
//#include <iostream>
#include <fstream>

typedef std::string string;

const unsigned short functionArrayLength = 14;
const unsigned short keyArrayLength = 74;

const string functionStrings[functionArrayLength] = {
	"forward",
	"back",
	"turn left",
	"turn right",
	"yell",
	"jump",
	"toggle turnbase",
	"inspect",
	"skip character",
	"cast quick spell",
	"attack",
	"fly up",
	"fly down",
	"land"
};

const unsigned long functionAddresses[functionArrayLength] = {
	213622,
	213636,
	213650,
	213664,
	213706,
	213720,
	213734,
	213748,
	213776,
	213692,
	213678,
	98934,
	98961,
	98907
};

const string keyStrings[keyArrayLength] = {
	"backspace",
	"tab",
	"enter",
	"shift",
	"ctrl",
	"alt",
	"capslock",
	"space",
	"page up",
	"page down",
	"end",
	"home",
	"left",
	"up",
	"right",
	"down",
	"insert",
	"delete",
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"a",
	"b",
	"c",
	"d",
	"e",
	"f",
	"g",
	"h",
	"i",
	"j",
	"k",
	"l",
	"m",
	"n",
	"o",
	"p",
	"q",
	"r",
	"s",
	"t",
	"u",
	"v",
	"w",
	"x",
	"y",
	"z",
	"f1",
	"f2",
	"f3",
	"f4",
	"f5",
	"f6",
	"f7",
	"f8",
	"f9",
	"f10",
	"f11",
	"f12",
	"=",
	",",
	"-",
	".",
	"/",
	"`",
	"\\",
	"'"
};

const unsigned char keyCodes[keyArrayLength] = {
	0x08,
	0x09,
	0x0D,
	0x10,
	0x11,
	0x12,
	0x14,
	0x20,
	0x21,
	0x22,
	0x23,
	0x24,
	0x25,
	0x26,
	0x27,
	0x28,
	0x2D,
	0x2E,
	0x30,
	0x31,
	0x32,
	0x33,
	0x34,
	0x35,
	0x36,
	0x37,
	0x38,
	0x39,
	0x41,
	0x42,
	0x43,
	0x44,
	0x45,
	0x46,
	0x47,
	0x48,
	0x49,
	0x4A,
	0x4B,
	0x4C,
	0x4D,
	0x4E,
	0x4F,
	0x50,
	0x51,
	0x52,
	0x53,
	0x54,
	0x55,
	0x56,
	0x57,
	0x58,
	0x59,
	0x5A,
	0x70,
	0x71,
	0x72,
	0x73,
	0x74,
	0x75,
	0x76,
	0x77,
	0x78,
	0x79,
	0x7A,
	0x7B,
	0xBB,
	0xBC,
	0xBD,
	0xBE,
	0xBF,
	0xC0,
	0xDC,
	0xDE
};

bool isFunctionOrKeyString(bool functionOrKey, string stringToTest) {//true = function; false = key
	const string * strings;
	const unsigned short * arrayLength;
	if (functionOrKey == true) {//function
		strings = functionStrings;
		arrayLength = &functionArrayLength;
	} else {//key
		strings = keyStrings;
		arrayLength = &keyArrayLength;
	}
	if (std::find(strings, strings + *arrayLength, stringToTest) != strings + *arrayLength) {
		return true;
	} else {
		return false;
	}
}

unsigned long getFunctionAddress(string functionString) {
	short index = std::distance(functionStrings, std::find(functionStrings, functionStrings + functionArrayLength, functionString));
	return functionAddresses[index];
}

unsigned char getKeyCode(string keyString) {
	short index = std::distance(keyStrings, std::find(keyStrings, keyStrings + keyArrayLength, keyString));
	return keyCodes[index];
}

void writeCharAtAddress(FILE * fileStream, unsigned long address, unsigned char charToWrite) {
	unsigned char buffer[1] = { charToWrite };
	fseek(fileStream, address, SEEK_SET);
	fwrite(buffer, sizeof(unsigned char), sizeof(buffer), fileStream);
}

void changeKey(string functionString, string keyString, FILE * fileStream) {
	writeCharAtAddress(fileStream, getFunctionAddress(functionString), getKeyCode(keyString));
}

void flipOnExit(bool b, FILE * fileStream) {
	unsigned char char1, char2;
	if (b == true) {
		char1 = 0xA3;
		char2 = 0xEC;
	}
	else {
		char1 = 0xEB;
		char2 = 0x03;
	}
	writeCharAtAddress(fileStream, 62959, char1);
	writeCharAtAddress(fileStream, 62960, char2);
}

void alwaysRun(bool b, FILE * fileStream) {
	unsigned char char1;
	if (b == true) {
		char1 = 0x75;
	}
	else {
		char1 = 0x74;
	}
	writeCharAtAddress(fileStream, 98866, char1);
}

void wrongArgumentsAlert(void) {
	printf("Wrong arguments.\nUsage: mm6chupchangekey.exe file function1 key1 function2 key2 ...");
}

bool copyFile(const char *SRC, const char* DEST) {
	std::ifstream src(SRC, std::ios::binary);
	std::ofstream dest(DEST, std::ios::binary);
	dest << src.rdbuf();
	return src && dest;
}

int main(int argc, char * argv[]) {

	if (argc >= 3) {

		int i;
		string arg, content;

		char backupExt[8] = ".backup";
		char * backupPath;
		backupPath = (char *)malloc(strlen(argv[1]) + strlen(backupExt) + 1);
		backupPath[0] = '\0';
		strcat(backupPath, argv[1]);
		strcat(backupPath, backupExt);
		copyFile(argv[1], backupPath);

		FILE * f;
		f = fopen(argv[1], "r+b");
		if (f == NULL) {
			printf("Error opening file!\n");
			exit(1);
		}

		for (i = 2; i < argc - 1; i += 2) {
			string arg(argv[i]);
			string content(argv[i + 1]);
			std::transform(arg.begin(), arg.end(), arg.begin(), ::tolower);
			std::transform(content.begin(), content.end(), content.begin(), ::tolower);
			//std::cout << "arg: " << arg << "; content: " << content << '\n';
			if (arg.compare("fliponexit") == 0) {//compare equal
				if (content.compare("true") == 0 || content.compare("1") == 0) {
					flipOnExit(true, f);
				}
				else if (content.compare("false") == 0 || content.compare("0") == 0) {
					flipOnExit(false, f);
				}
				else {
					wrongArgumentsAlert();
					fclose(f);
					return 0;
				}
			}
			else if (arg.compare("alwaysrun") == 0) {//compare equal
				if (content.compare("true") == 0 || content.compare("1") == 0) {
					alwaysRun(true, f);
				}
				else if (content.compare("false") == 0 || content.compare("0") == 0) {
					alwaysRun(false, f);
				}
				else {
					wrongArgumentsAlert();
					fclose(f);
					return 0;
				}
			}
			else {
				if (isFunctionOrKeyString(true, arg) && isFunctionOrKeyString(false, content)) {
					changeKey(arg, content, f);
				}
				else {
					wrongArgumentsAlert();
					fclose(f);
					return 0;
				}
			}
		}

		fclose(f);
	} else {
		wrongArgumentsAlert();
	}

	return 0;
}
