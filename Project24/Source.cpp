// 1 - int, 2 - float, 3 - char


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

template<typename T>
void insert_text(T massive[], T clone_massive[], int type, int lenth)
{
	FILE* myFile;
	const char file_name[] = "tempary.txt";
	if ((myFile = fopen(file_name, "w")) == NULL)
		std::cout << "File couldn`t be opened"<<std::endl;
	else
		std::cout << "OK. File " << file_name << " is open" << std::endl;

	for (int i = 0; i < lenth; i++)
	{

		switch (type)
		{
		case 2:
			fprintf(myFile, "%d ", massive[i]);
			break;
		case 1:
			fprintf(myFile, "%f ", massive[i]);
			break;
		case 3:
			fprintf(myFile, "%c ", massive[i]);
			break;
		default:
			std::cout << "error\n";
			break;
		}

	}
	if (fclose(myFile) == EOF)
		std::cout << "File " << file_name << " couldn`t be closed" << std::endl;
	else
		std::cout << "File " << file_name << " is closed" << std::endl;
	FILE* out;
	out = fopen(file_name, "r");
	int result = 0;
	for (int i = 0; i < lenth; i++)
	{
		switch (type)
		{
		case 2:
			result += fscanf(out, "%d ", &clone_massive[i]);
			break;
		case 1:
			result += fscanf(out, "%f ", &clone_massive[i]);
			break;
		case 3:
			result += fscanf(out, "%c ", &clone_massive[i]);
			break;
		default:
			std::cout << "error" << std::endl;
			break;
		}

	}
	std::cout << std::endl;
	for (int i = 0; i < lenth; i++)
	{
		std::cout << clone_massive[i] << " ";
	}
	std::cout << std::endl;
}
int main()
{
	const int length = 3;
	char massive[length] = { 'c', 'a','r'};
	char* massive2 = new char[length];
	insert_text(massive, massive2, 3, length);
}