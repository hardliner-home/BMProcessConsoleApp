#include "BMPModule.h"
#include <stdio.h>

using namespace std;

char getLine(char CommandStr) {
	char line[501];
	gets_s(line, 500);
	return line[500];
}

char getLineParams(char str[501]) {
	printf("%s\n", str);

	return {};
}

double rotate(double img) {
	return img;
}

double flip(double img) {
	return img;
}

double upscale(double img) {
	return img;
}

double downscale(double img) {
	return img;
}

double bright(double img) {
	return img;
}