//This program is used two find two strings with the same hash value
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>

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

string hashToText(int out[], int count) {				//function to convert out[] to text
	string output;
	for (int i = 0; i < count; i++) {					//checking for each number in the array
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
	int out[5], grid[5][5], counter = 5, ran[1];				//initializing variables
	string t1, t2, t3, t4, t5, t6, f1, f2, f3, f4, f5, f6, th1, th2, th3, th4, th5, th6, fh1, fh2, fh3, fh4, fh5, fh8;

	srand(time(0));												//using time as the seed value
	for (int l = 0; l < 30; l++) {								//generating 5 random strings
		ran[0] = rand() % 26;
		t1 += hashToText(ran, 1);
	}
	memset(out, 0, sizeof(out));								//finding hash values of 5 random strings
	hashFun(t1, out);	
	th1 = hashToText(out, 5);
	for (int l = 0; l < 30; l++) {
		ran[0] = rand() % 26;
		t2 += hashToText(ran, 1);
	}
	memset(out, 0, sizeof(out));
	hashFun(t2, out);
	th2 = hashToText(out, 5);
	for (int l = 0; l < 30; l++) {
		ran[0] = rand() % 26;
		t3 += hashToText(ran, 1);
	}
	memset(out, 0, sizeof(out));
	hashFun(t3, out);
	th3 = hashToText(out, 5);
	for (int l = 0; l < 30; l++) {
		ran[0] = rand() % 26;
		t4 += hashToText(ran, 1);
	}
	memset(out, 0, sizeof(out));
	hashFun(t4, out);
	th4 = hashToText(out, 5);
	for (int l = 0; l < 30; l++) {
		ran[0] = rand() % 26;
		t5 += hashToText(ran, 1);
	}
	memset(out, 0, sizeof(out));
	hashFun(t5, out);
	th5 = hashToText(out, 5);
	const char * h1 = th1.c_str();								//converting hash values from strings to constant char pointer
	const char * h2 = th2.c_str();
	const char * h3 = th3.c_str();
	const char * h4 = th4.c_str();
	const char * h5 = th5.c_str();
	while (1) {													//keep looping
		counter += 5;											//counting number of strings generated for collision
		f1 = "";
		f2 = "";
		f3 = "";
		f4 = "";
		f5 = "";
		
		for (int l = 0; l < 30; l++) {							//keep generating 5 more strings for comparison
			ran[0] = rand() % 26;
			f1 += hashToText(ran, 1);
		}
		memset(out, 0, sizeof(out));							//keep finding hash values of generated strings
		hashFun(f1, out);
		fh1 = hashToText(out, 5);
		for (int l = 0; l < 30; l++) {
			ran[0] = rand() % 26;
			f2 += hashToText(ran, 1);
		}
		memset(out, 0, sizeof(out));
		hashFun(f2, out);
		fh2 = hashToText(out, 5);
		for (int l = 0; l < 30; l++) {
			ran[0] = rand() % 26;
			f3 += hashToText(ran, 1);
		}
		memset(out, 0, sizeof(out));
		hashFun(f3, out);
		fh3 = hashToText(out, 5);
		for (int l = 0; l < 30; l++) {
			ran[0] = rand() % 26;
			f4 += hashToText(ran, 1);
		}
		memset(out, 0, sizeof(out));
		hashFun(f4, out);
		fh4 = hashToText(out, 5);
		for (int l = 0; l < 30; l++) {
			ran[0] = rand() % 26;
			f5 += hashToText(ran, 1);
		}
		memset(out, 0, sizeof(out));
		hashFun(f5, out);
		fh5 = hashToText(out, 5);
		
		const char * g1 = fh1.c_str();							//converting from string to const char*
		const char * g2 = fh2.c_str();
		const char * g3 = fh3.c_str();
		const char * g4 = fh4.c_str();
		const char * g5 = fh5.c_str();
		if (strcmp(h1, g1) == 0) {									//compare each generated hash value with initial 5 values for equality
			cout << "The first text is: " << t1 << endl;			// if equal, print the plaintexts
			cout << "The second text is: " << f1 << endl;
			cout << "The count of texts: " << counter << endl;		//print the number of strings generated to find similar plaintexts
			break;
		}
		else if (strcmp(h1, g2) == 0) {
			cout << "The first text is: " << t1 << endl;
			cout << "The second text is: " << f2 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h1, g3) == 0) {
			cout << "The first text is: " << t1 << endl;
			cout << "The second text is: " << f3 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h1, g4) == 0) {
			cout << "The first text is: " << t1 << endl;
			cout << "The second text is: " << f4 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h1, g5) == 0) {
			cout << "The first text is: " << t1 << endl;
			cout << "The second text is: " << f5 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h2, g1) == 0) {
			cout << "The first text is: " << t2 << endl;
			cout << "The second text is: " << f1 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h2, g2) == 0) {
			cout << "The first text is: " << t2 << endl;
			cout << "The second text is: " << f2 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h2, g3) == 0) {
			cout << "The first text is: " << t2 << endl;
			cout << "The second text is: " << f3 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h2, g4) == 0) {
			cout << "The first text is: " << t2 << endl;
			cout << "The second text is: " << f4 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h2, g5) == 0) {
			cout << "The first text is: " << t2 << endl;
			cout << "The second text is: " << f5 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h3, g1) == 0) {
			cout << "The first text is: " << t3 << endl;
			cout << "The second text is: " << f1 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h3, g2) == 0) {
			cout << "The first text is: " << t3 << endl;
			cout << "The second text is: " << f2 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h3, g3) == 0) {
			cout << "The first text is: " << t3 << endl;
			cout << "The second text is: " << f3 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h3, g4) == 0) {
			cout << "The first text is: " << t3 << endl;
			cout << "The second text is: " << f4 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h3, g5) == 0) {
			cout << "The first text is: " << t3 << endl;
			cout << "The second text is: " << f5 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h4, g1) == 0) {
			cout << "The first text is: " << t4 << endl;
			cout << "The second text is: " << f1 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h4, g2) == 0) {
			cout << "The first text is: " << t4 << endl;
			cout << "The second text is: " << f2 << endl;
			cout << "The count of texts: " << counter << endl;
			break;
		}
		else if (strcmp(h4, g3) == 0) {
		cout << "The first text is: " << t4 << endl;
		cout << "The second text is: " << f3 << endl;
		cout << "The count of texts: " << counter << endl;
		break;
		}
		else if (strcmp(h4, g4) == 0) {
		cout << "The first text is: " << t4 << endl;
		cout << "The second text is: " << f4 << endl;
		cout << "The count of texts: " << counter << endl;
		break;
		}
		else if (strcmp(h4, g5) == 0) {
		cout << "The first text is: " << t4 << endl;
		cout << "The second text is: " << f5 << endl;
		cout << "The count of texts: " << counter << endl;
		break;
		}
		else if (strcmp(h5, g1) == 0) {
		cout << "The first text is: " << t5 << endl;
		cout << "The second text is: " << f1 << endl;
		cout << "The count of texts: " << counter << endl;
		break;
		}
		else if (strcmp(h5, g2) == 0) {
		cout << "The first text is: " << t5 << endl;
		cout << "The second text is: " << f2 << endl;
		cout << "The count of texts: " << counter << endl;
		break;
		}
		else if (strcmp(h5, g3) == 0) {
		cout << "The first text is: " << t5 << endl;
		cout << "The second text is: " << f3 << endl;
		cout << "The count of texts: " << counter << endl;
		break;
		}
		else if (strcmp(h5, g4) == 0) {
		cout << "The first text is: " << t5 << endl;
		cout << "The second text is: " << f4 << endl;
		cout << "The count of texts: " << counter << endl;
		break;
		}
		else if (strcmp(h5, g5) == 0) {
		cout << "The first text is: " << t5 << endl;
		cout << "The second text is: " << f5 << endl;
		cout << "The count of texts: " << counter << endl;
		break;
		}
	}
	return 0;
}