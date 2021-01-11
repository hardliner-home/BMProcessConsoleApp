#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
//#include "BMPModule.h"

using namespace std;

#pragma pack(push, 2)
struct BmpHeader {
	unsigned char b1, b2; // Символы BM (2 байта)
	unsigned long size; // Размер файла (4 байта)
	unsigned short notUse1; // (2 байта)
	unsigned short notUse2; // (2 байта)
	unsigned long massPos; // Местанахождение данных растрового массива (4 байта)

	unsigned long headerLength; // Длинна этого заголовка (4 байта)
	unsigned long width; // Ширина изображения (4 байта)
	unsigned long height; // Высота изображения (4 байта)
	unsigned short colorPlaneNumber; // Число цветовых плоскостей (2 байта)
	unsigned short bitPixel; // Бит/пиксель (2 байта)
	unsigned long compressMethod; // Метод сжатия (4 байта)
	unsigned long massLength; // Длинна массива с мусоро (4 байта)
	unsigned long massWidth; // Ширина массива с мусором (4 байта)
	unsigned long massHeight; // Высота массива с мусором (4 байта)
	unsigned long colorNumber; // Число цветов изображения (4 байта)
	unsigned long generalColorNumber; // Число основных цветов (4 байта)
} bmpHeader;

#pragma pack(pop)

unsigned char* img;

int readBMP(const char* path) {
	FILE* file;
	long long i, j, u;
	long long v;
	file = fopen(path, "rb");
	if (file == NULL) return 0;
	fread(&bmpHeader, sizeof(bmpHeader), 1, file);
	if (bmpHeader.b1 != 'B' || bmpHeader.b2 != 'M' || bmpHeader.bitPixel != 8) {
		printf("corrupted file");
		return 0;
	}

	int mx = bmpHeader.width;
	int my = bmpHeader.height;
	int mx3 = (3 * mx + 3) & (-4);
	img = (unsigned char*)calloc(mx3 * my, sizeof(char));
	fread(img, 1, mx3 * my, file);
	int s = bmpHeader.height * bmpHeader.width;
}

int saveBMP(const char* path) {
	FILE* file;
	int i, j;
	file = fopen(path, "wb");
	if (file == NULL) return 0;

	int mx = bmpHeader.width;
	int my = bmpHeader.height;
	int mx3 = (1 * mx + 1) & (-4);
	int filesize = 54 + my * mx3;

	fwrite(&bmpHeader, sizeof(bmpHeader), 1, file);
	fwrite(img, sizeof(char), mx3 * my, file);
	fclose(file);
	return 1;
}

void rotate(char* filesStr, char* Angle) {

	readBMP("./Testcase1/input06.bmp");
	saveBMP("./Testcase1/output007.bmp");
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