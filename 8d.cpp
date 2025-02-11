//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//November 7, 2022
//Lab 8d

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

void readImage(int image[MAX_H][MAX_W], int &height, int &width) 
{
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}

void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

int main() 
{
	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); 
	int out[MAX_H][MAX_W];

	int topL = w / 4;
  	int topR = 3 * w / 4;
  	int lowL = h / 4;
  	int lowR = 3 * h / 4;

	for(int row = 0; row < h; row++) 
	{
		for(int col = 0; col < w; col++) 
		{
			if (((row == lowL || row == lowR) && (col >= topL && col <= topR)) || ((row >= lowL && row <= lowR) && (col == topL || col == topR))) 
	  		{
				out[row][col] = 255;
      		} 
      		else 
      		{
				out[row][col] = img[row][col];
      		}
		}
	}
	writeImage(out, h, w);
}
