#define _CRT_SECURE_NO_WARNINGS

#include "BMPModule.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#pragma pack(push, 2)
struct BmpStruct {
	unsigned char b1, b2;
	unsigned long size;
	unsigned short notUse1;
	unsigned short notUse2;
	unsigned long massPos;

	unsigned long headerLength;
	unsigned long width;
	unsigned long height;
	unsigned short colorPlaneNumber;
	unsigned short bitPixel;
	unsigned long compressMethod;
	unsigned long massLength;
	unsigned long massWidth;
	unsigned long massHeight;
	unsigned long colorNumber;
	unsigned long generalColorNumber;
} BMP;

#pragma pack(pop)

unsigned char* img;

int readBMP(const char* path) {
	FILE* file;
	file = fopen(path, "rb");
	if (file == NULL) return 0;
	fread(&BMP, sizeof(BMP), 1, file);

	if (BMP.b1 != 'B' || BMP.b2 != 'M' || BMP.bitPixel != 8) {
		printf("Wrong type of file!");
		return 0;
	}

	int mx = BMP.width;
	int my = BMP.height;

	img = (unsigned char*)calloc(BMP.size, 1);
	fread(img, 1, BMP.size, file);
	fclose(file);

	return 1;
}

int saveBMP(const char* path) {
	FILE* file;
	int i, j;
	file = fopen(path, "wb");
	if (file == NULL) return 0;

	int mx = BMP.width;
	int my = BMP.height;

	fwrite(&BMP, sizeof(BMP), 1, file);
	fwrite(img, 1, BMP.size, file);
	fclose(file);
	return 1;
}

int cfileexists(const char* filename) {
	struct stat buffer;
	int exist = stat(filename, &buffer);
	if (exist == 0) {
		return 1;
	} else
		return 0;
}

void rotate(char* filesStr, char* Angle) {

	int count, j, c;

	if (!strcmp(filesStr, "00")) {

		char inFileName[50] = "./Testcase10/input00.bmp";
		char outFileName[50] = "./Testcase10/output00.bmp";

		for (int f = 0; f < 100; ++f) {

			if (f < 10) {
				inFileName[18] = f + '0';
				outFileName[19] = f + '0';
			}
			else {
				int a = f / 10;
				int b = f % 10;
				inFileName[18] = a + '0';
				inFileName[19] = b + '0';
				outFileName[19] = a + '0';
				outFileName[20] = b + '0';
			}

			int exist = cfileexists(inFileName);
			if (exist) {
				readBMP(inFileName);

				if (!strcmp(Angle, "0") || !strcmp(Angle, "360")) {
					count = 0;
				}
				else if (!strcmp(Angle, "90")) {
					count = 1;
				}
				else if (!strcmp(Angle, "180")) {
					count = 2;
				}
				else if (!strcmp(Angle, "270")) {
					count = 3;
				}
				else {
					printf("Wrong param!");
				}

				for (int i = 0; i < count; i++) {
					int s = BMP.height * BMP.width;

					for (c = 0; c < BMP.height * BMP.width / 2; c++) {
						for (j = 2; j >= 0; j--) {
							unsigned char t = img[(s - 1) - c - j];
							img[(s - 1) - c - j] = img[c + (2 - j)];
							img[c + (2 - j)] = t;
						}
					}

					if (count % 2 != 0) {
						int w = BMP.width;
						int h = BMP.height;
						/*BMP.width = h;
						BMP.height = w;*/
						//BMP.size = something;
					}
				}

				saveBMP(outFileName);
			}
		}
	}
	else {
		printf("Only for all channels!");
	}
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