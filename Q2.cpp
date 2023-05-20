//This program is used to find the MAC value of a given plaintext with key
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void toGrid(char arr[], int grid[5][5]) {										//function to convert block to grid(2-d array)
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[count] == 'a' || arr[count] == 'A')							//checking for character to convert to the particular binary block
				grid[i][j] = 0;
			else if (arr[count] == 'b' || arr[count] == 'B')
				grid[i][j] = 1;
			else if (arr[count] == 'c' || arr[count] == 'C')
				grid[i][j] = 2;
			else if (arr[count] == 'd' || arr[count] == 'D')
				grid[i][j] = 3;
			else if (arr[count] == 'e' || arr[count] == 'E')
				grid[i][j] = 4;
			else if (arr[count] == 'f' || arr[count] == 'F')
				grid[i][j] = 5;
			else if (arr[count] == 'g' || arr[count] == 'G')
				grid[i][j] = 6;
			else if (arr[count] == 'h' || arr[count] == 'H')
				grid[i][j] = 7;
			else if (arr[count] == 'i' || arr[count] == 'I')
				grid[i][j] = 8;
			else if (arr[count] == 'j' || arr[count] == 'J')
				grid[i][j] = 9;
			else if (arr[count] == 'k' || arr[count] == 'K')
				grid[i][j] = 10;
			else if (arr[count] == 'l' || arr[count] == 'L')
				grid[i][j] = 11;
			else if (arr[count] == 'm' || arr[count] == 'M')
				grid[i][j] = 12;
			else if (arr[count] == 'n' || arr[count] == 'N')
				grid[i][j] = 13;
			else if (arr[count] == 'o' || arr[count] == 'O')
				grid[i][j] = 14;
			else if (arr[count] == 'p' || arr[count] == 'P')
				grid[i][j] = 15;
			else if (arr[count] == 'q' || arr[count] == 'Q')
				grid[i][j] = 16;
			else if (arr[count] == 'r' || arr[count] == 'R')
				grid[i][j] = 17;
			else if (arr[count] == 's' || arr[count] == 'S')
				grid[i][j] = 18;
			else if (arr[count] == 't' || arr[count] == 'T')
				grid[i][j] = 19;
			else if (arr[count] == 'u' || arr[count] == 'U')
				grid[i][j] = 20;
			else if (arr[count] == 'v' || arr[count] == 'V')
				grid[i][j] = 21;
			else if (arr[count] == 'w' || arr[count] == 'W')
				grid[i][j] = 22;
			else if (arr[count] == 'x' || arr[count] == 'X')
				grid[i][j] = 23;
			else if (arr[count] == 'y' || arr[count] == 'Y')
				grid[i][j] = 24;
			else if (arr[count] == 'z' || arr[count] == 'Z')
				grid[i][j] = 25;
			else if (arr[count] == ' ')
				grid[i][j] = 26;
			count++;																	//incrementing block
		}
	}

}

void addcolumn(int grid[5][5], int out[]) {				//function to add values of columns
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			out[i] += grid[j][i];
		}
		out[i] = out[i] % 27;
	}
}

void shiftrow(int grid[5][5], int out[]) {				//function to shift rows in the grid
	int temp;
	for (int i = 0; i < 4; i++) {
		for (int j = -1; j < i; j++) {
			temp = grid[i][0];
			grid[i][0] = grid[i][1];
			grid[i][1] = grid[i][2];
			grid[i][2] = grid[i][3];
			grid[i][3] = grid[i][4];
			grid[i][4] = temp;
		}
	}
	addcolumn(grid, out);								//calling function to add values of columns
}
void addrow(int grid[5][5], int out[]) {				//function to add values of rows
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			out[i] += grid[i][j];
		}
		out[i] = out[i] % 27;							//value mod 27
	}
}

void shiftcolumn(int grid[5][5], int out[]) {			//function to shift columns
	int temp;
	for (int i = 0; i < 4; i++) {
		for (int j = -1; j < i; j++) {
			temp = grid[4][i];
			grid[4][i] = grid[3][i];
			grid[3][i] = grid[2][i];
			grid[2][i] = grid[1][i];
			grid[1][i] = grid[0][i];
			grid[0][i] = temp;
		}
	}
	addrow(grid, out);									//calling function to add values of rows
}

string hashToText(int out[]) {							//function to convert out[] to text
	string output;
	for (int i = 0; i < 5; i++) {						// checking for each number in the array
		if (out[i] == 0)
			output += 'a';
		else if (out[i] == 1)
			output += 'b';
		else if (out[i] == 2)
			output += 'c';
		else if (out[i] == 3)
			output += 'd';
		else if (out[i] == 4)
			output += 'e';
		else if (out[i] == 5)
			output += 'f';
		else if (out[i] == 6)
			output += 'g';
		else if (out[i] == 7)
			output += 'h';
		else if (out[i] == 8)
			output += 'i';
		else if (out[i] == 9)
			output += 'j';
		else if (out[i] == 10)
			output += 'k';
		else if (out[i] == 11)
			output += 'l';
		else if (out[i] == 12)
			output += 'm';
		else if (out[i] == 13)
			output += 'n';
		else if (out[i] == 14)
			output += 'o';
		else if (out[i] == 15)
			output += 'p';
		else if (out[i] == 16)
			output += 'q';
		else if (out[i] == 17)
			output += 'r';
		else if (out[i] == 18)
			output += 's';
		else if (out[i] == 19)
			output += 't';
		else if (out[i] == 20)
			output += 'u';
		else if (out[i] == 21)
			output += 'v';
		else if (out[i] == 22)
			output += 'w';
		else if (out[i] == 23)
			output += 'x';
		else if (out[i] == 24)
			output += 'y';
		else if (out[i] == 25)
			output += 'z';
		else if (out[i] == 26)
			output += ' ';
	}
	return output;										//returning hashed value
}

int checkrem(int length, int* count) {					//function to check for blocks of plaintext
	int rem = 0;
	if (length % 25 == 0)								//checking for plaintext blocks
		*count = length / 25;
	else {
		*count = length / 25;							//if not divisible by 25(block size)
		rem = (length % 25);
	}
	return rem;
}

void hashFun(string text, int out[]) {							//function to hash the plaintext
	char block[25];
	int grid[5][5], x = 0;
	int rem = 0, count = 0;
	rem = checkrem(text.length(), &count);						//calling function to check for blocks
	for (int k = 0; k < count; k++) {
		for (int i = 0; i < 25; i++) {
			block[i] = text[x];									//dividing into blocks of 25
			x++;
		}
		toGrid(block, grid);									//converting block to grid
		addcolumn(grid, out);									//adding values of columns
		shiftrow(grid, out);									//shifting rows and adding rows
		shiftcolumn(grid, out);									//shifting columns and adding columns
	}
	if (rem != 0) {
		memset(block, ' ', sizeof(block));						//padding for block size
		for (int i = 0; i < rem; i++) {
			block[i] = text[x];
			x++;
		}
		toGrid(block, grid);									//hashing the padded block
		addcolumn(grid, out);
		shiftrow(grid, out);
		shiftcolumn(grid, out);
	}
}

int main() {
	string plaintext = "the birthday attack can be performed for any hash functions including sha three";		//given plaintext
	int out[5], grid[5][5];
	string key = "fries";																						//given key
	cout << "The plaintext is: " << plaintext << endl;															//output key and plaintext
	cout << "The key is: " << key << endl;
	string hashed;
	string text = key + plaintext;																				//implementing MAC function
	memset(out, 0, sizeof(out));
	hashFun(text, out);
	hashed = hashToText(out);
	text = key + hashed;
	memset(out, 0, sizeof(out));
	hashFun(text, out);
	hashed = hashToText(out);
	cout << "\nThe MAC value is: " << hashed << endl;
	return 0;
}