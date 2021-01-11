#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
//#include "BMPModule.h"

using namespace std;

//char* getLine() {
//	char *line;
//	int len = 1001;
//	line = (char*)malloc(len);
//	gets_s(line, 1000);
//	return line;
//}

//void getLineParams(char* str) {
//	int i = 0;
//	int j = 0;
//	int variableChanger = 0;
//	char *filesStr;
//	char commandStr;
//	char paramsStr;
//	while (str[i] != '\0') {
//		switch (variableChanger) {
//			case 0: {
//				if (str[i] != ':') {
//					filesStr[j] = str[i];
//				} else {
//					variableChanger++;
//					j = 0;
//				}
//				break;
//			}
//			case 1: {
//				if (str[i] != ':') {
//					commandStr[j] = str[i];
//				}
//				else {
//					variableChanger++;
//					j = 0;
//				}
//				break;
//			}
//			default: break;
//		}
//		i++;
//		j++;
//	}
//	printf("%s\n", filesStr);
//	printf("%s\n", commandStr);
//	//return;
//}

//double rotate(double img) {
//	return img;
//}
//
//double flip(double img) {
//	return img;
//}
//
//double upscale(double img) {
//	return img;
//}
//
//double downscale(double img) {
//	return img;
//}
//
//double bright(double img) {
//	return img;
//}

void bright(char* degree) {
	printf("commandStr %s\n", degree);
}

int main()
{
	//char* inputLine = getLine();
	//getLineParams(inputLine);
	char filesStr[301];
	char commandStr[100];
	char paramsStr[100];
	int i = 0;
	int stop = 0;
	int VAR_charger = 0;
	char c;
	while (stop != 1)
	{
		c = getchar();
		switch (VAR_charger) {
			case 0: {
				if (c != ':') {
					filesStr[i] = c;
					i++;
				} else {
					filesStr[i - 1] = '\0';
					VAR_charger++;
					i = 0;
				}
				break;
			}
			case 1: {
				if (c != ':') {
					if (c != ' ') {
						commandStr[i] = c;
						i++;
					}
				}
				else {
					commandStr[i] = '\0';
					VAR_charger++;
					i = 0;
				}
				break;
			}
			case 2: {
				if ((int)(c) != 10 || c != '\n') {
					if (c != ' ') {
						paramsStr[i] = c;
						i++;
					}
				}
				else {
					paramsStr[i] = '\0';
					stop = 1;
				}

				//if (c != '\0') {
				//	if (c != ' ') {
				//		paramsStr[i] = c;
				//		i++;
				//	}
				//}
				//else {
				//	paramsStr[i - 1] = '\0';
				//	i = 0;
				//}
				break;
			}
		}
		
	}

	printf("filesStr %s\n", filesStr);
	printf("commandStr %s\n", commandStr);
	printf("paramsStr %s\n", paramsStr);

	if (!strcmp(commandStr, "bright")) {
		//printf("commandStr %s\n", commandStr);
		bright(paramsStr);
	}
	else if (!strcmp(commandStr, "flip")) {
		printf("commandStr %s\n", commandStr);
	}
	else {
		printf("commandStr %s\n", "ti loh");
	}
	system("pause");
}