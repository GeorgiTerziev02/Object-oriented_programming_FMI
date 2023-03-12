#include "startUp.h"
#include "file.h"
#include "helperFunctions.h"
#include "commands.h"
#include "stringHelperFunctions.h"
#include "fileOperations.h"
#include <iostream>

using namespace std;

void startMenu(File& file) {
	while (true)
	{
		char input[INPUT_BUFFER_SIZE];
		printInputCharacter();
		cin.getline(input, INPUT_BUFFER_SIZE);

		char command[COMMAND_SIZE];
		int index = 0;

		while (input[index] != ' ' && input[index] != '\0')
		{
			command[index] = input[index++];
		}
		command[index++] = '\0';

		if (strCmp(command, VIEW_COMMAND))
		{
			viewFile(file);
		}
		else if (strCmp(command, CHANGE_COMMAND))
		{
			int indexToChange = 0;
			while (input[index] != ' ')
			{
				indexToChange += input[index++] - '0';
			}
			index++;
			int inputLength = strLength(input);
			char* hexStr = subStr(input, index, inputLength - 1);
			if (!isValidHex(hexStr))
			{
				printOperationResultMessage(false);
				delete[] hexStr;
				continue;
			}

			int newValue = hexToDecimal(hexStr);
			delete[] hexStr;

			bool result = changeByteAtIndex(file, newValue, indexToChange);
			printOperationResultMessage(result);
		}
		else if (strCmp(command, REMOVE_COMMAND))
		{
			bool result = removeByteFromEnd(file);
			printOperationResultMessage(result);
		}
		else if (strCmp(command, ADD_COMMAND))
		{
			int inputLength = strLength(input);
			char* hexStr = subStr(input, index, inputLength - 1);
			if (!isValidHex(hexStr))
			{
				printOperationResultMessage(false);
				delete[] hexStr;
				continue;
			}
			int newValue = hexToDecimal(hexStr);
			delete[] hexStr;

			bool result = addByteToEnd(file, newValue);
			printOperationResultMessage(result);
		}
		else if (strCmp(command, SAVE_COMMAND))
		{
			int inputLength = strLength(input);
			bool result = false;

			// check if just save
			if (input[index - 1] == '\0')
			{
				result = saveToFile(file, file.name);
			}
			else
			{
				moveIndexToNextSeparator(input, index, ' ');
				moveIndexToNextSeparator(input, index, ' ');

				char* newFileName = subStr(input, ++index, inputLength - 1);
				result = saveToFile(file, newFileName);
				delete[] newFileName;
			}

			printOperationResultMessage(result);
			if (result) return;
		}
	}
}

void run(){
	File file;
	cout << "Enter a file path:" << endl;
	printInputCharacter();
	cin.getline(file.name, FILE_NAME_SIZE);

	bool success = readFile(file);
	if (!success) return;

	cout << "File loaded successfully! Size: " << file.size << " bytes" << endl;

	startMenu(file);
}