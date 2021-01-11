#pragma once
#ifndef BMPModule_H
#define BMPModule_H

char getLine(char CommandStr[501]);
char getLineParams(char str[501]);
double rotate(double img);
double flip(double img);
double upscale(double img);
double downscale(double img);
double bright(double img);

#endif
