#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
//#include "BMPModule.h"

using namespace std;

void rotate(char* filesStr, char* Angle) {
	printf("commandStr %s\n", Angle);
}

void flip(char* filesStr, char* DIR) {
	printf("commandStr %s\n", DIR);
}

void upscale(char* filesStr, char* VH) {
	printf("commandStr %s\n", VH);
}

void downscale(char* filesStr, char* VH) {
	printf("commandStr %s\n", VH);
}

void bright(char* filesStr, char* f) {
	printf("commandStr %s\n", f);
}

int main()
{
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
				break;
			}
		}
		
	}

	if (!strcmp(commandStr, "rotate")) {
		rotate(filesStr, paramsStr);
	}
	else if (!strcmp(commandStr, "flip")) {
		flip(filesStr, paramsStr);
	}
	else if (!strcmp(commandStr, "upscale")) {
		upscale(filesStr, paramsStr);
	}
	else if (!strcmp(commandStr, "downscale")) {
		downscale(filesStr, paramsStr);
	}
	else if (!strcmp(commandStr, "bright")) {
		bright(filesStr, paramsStr);
	}
	else {
		printf("commandStr %s\n", "ti loh");
	}
	system("pause");
}