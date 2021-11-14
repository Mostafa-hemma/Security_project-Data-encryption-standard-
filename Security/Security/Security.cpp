#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;
class key_64bit
{
public:
	string key_as_string_56;
	string sub_keys[16];
	string key_as_binary;
	string sub_sub_key[16];
	string key_left[28], key_right[28];
	stringstream hexa;
	string leftkey, rightkey;
	int premited_choice_1[56] = { 57, 49, 41, 33, 25, 17, 9,1, 58, 50, 42, 34, 26, 18,10, 2, 59, 51, 43, 35, 27,19, 11, 3, 60, 52, 44, 36,63, 55, 47, 39, 31, 23, 15,7, 62, 54, 46, 38, 30, 22,14, 6, 61, 53, 45, 37, 29,21, 13, 5, 28, 20, 12, 4 };
	int premited_choice_key_2[48] = { 14, 17, 11, 24, 1, 5,3, 28, 15, 6, 21, 10,23, 19, 12, 4, 26, 8,16, 7, 27, 20, 13, 2,41, 52, 31, 37, 47, 55,30, 40, 51, 45, 33, 48,44, 49, 39, 56, 34, 53,46, 42, 50, 36, 29, 32 };
	string binaryToHex(string sBinary)
	{
		string rest = "", tmp, chr = "0000";
		int len = sBinary.length() / 4;
		chr = chr.substr(0, len);
		for (int i = 0; i < sBinary.length(); i += 4)
		{
			tmp = sBinary.substr(i, 4);
			if (!tmp.compare("0000"))
			{
				rest = rest + "0";
			}
			else if (!tmp.compare("0001"))
			{
				rest = rest + "1";
			}
			else if (!tmp.compare("0010"))
			{
				rest = rest + "2";
			}
			else if (!tmp.compare("0011"))
			{
				rest = rest + "3";
			}
			else if (!tmp.compare("0100"))
			{
				rest = rest + "4";
			}
			else if (!tmp.compare("0101"))
			{
				rest = rest + "5";
			}
			else if (!tmp.compare("0110"))
			{
				rest = rest + "6";
			}
			else if (!tmp.compare("0111"))
			{
				rest = rest + "7";
			}
			else if (!tmp.compare("1000"))
			{
				rest = rest + "8";
			}
			else if (!tmp.compare("1001"))
			{
				rest = rest + "9";
			}
			else if (!tmp.compare("1010"))
			{
				rest = rest + "A";
			}
			else if (!tmp.compare("1011"))
			{
				rest = rest + "B";
			}
			else if (!tmp.compare("1100"))
			{
				rest = rest + "C";
			}
			else if (!tmp.compare("1101"))
			{
				rest = rest + "D";
			}
			else if (!tmp.compare("1110"))
			{
				rest = rest + "E";
			}
			else if (!tmp.compare("1111"))
			{
				rest = rest + "F";
			}
			else
			{
				continue;
			}
		}
		return rest;
	}
	string converting_string_binary(string key_as_string)
	{
		int i = 0;
		while (key_as_string[i])
		{
			switch (key_as_string[i])
			{
			case '0':
				key_as_binary += "0000";
				break;
			case '1':
				key_as_binary += "0001";
				break;
			case '2':
				key_as_binary += "0010";
				break;
			case '3':
				key_as_binary += "0011";
				break;
			case '4':
				key_as_binary += "0100";
				break;
			case '5':
				key_as_binary += "0101";
				break;
			case '6':
				key_as_binary += "0110";
				break;
			case '7':
				key_as_binary += "0111";
				break;
			case '8':
				key_as_binary += "1000";
				break;
			case '9':
				key_as_binary += "1001";
				break;
			case 'A':
			case 'a':
				key_as_binary += "1010";
				break;
			case 'B':
			case 'b':
				key_as_binary += "1011";
				break;
			case 'C':
			case 'c':
				key_as_binary += "1100";
				break;
			case 'D':
			case 'd':
				key_as_binary += "1101";
				break;
			case 'E':
			case 'e':
				key_as_binary += "1110";
				break;
			case 'F':
			case 'f':
				key_as_binary += "1111";
				break;
			default:
				cout << "--Invalid Hex Digit (" << key_as_string[i] << ")--";
			}
			i++;
		}
		return key_as_binary;
	}
	string left_shifting(string arr)
	{
		char temp1 = arr[0];
		for (int i = 0; i < 27; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[27] = temp1;
		return arr;
	}
	char XOR(char x1, char x2) {
		char result = ' ';
		if (x1 == '1' && x2 == '1')
		{
			result = '0';
		}
		else if (x1 == '0' && x2 == '0')
		{
			result = '0';
		}
		else if (x1 == '0' && x2 == '1')
		{
			result = '1';
		}
		else if (x1 == '1' && x2 == '0')
		{
			result = '1';
		}
		return result;
	}
	string decimal_to_hexa(int x) {
		string y;
		switch (x)
		{
		case 0:y = "0000";
			break;
		case 1:y = "0001";
			break;
		case 2:y = "0010";
			break;
		case 3:y = "0011";
			break;
		case 4:y = "0100";
			break;
		case 5:y = "0101";
			break;
		case 6:y = "0110";
			break;
		case 7:y = "0111";
			break;
		case 8:y = "1000";
			break;
		case 9:y = "1001";
			break;
		case 10:y = "1010";
			break;
		case 11:y = "1011";
			break;
		case 12:y = "1100";
			break;
		case 13:y = "1101";
			break;
		case 14:y = "1110";
			break;
		case 15:y = "1111";
			break;
		}
		return y;
	}
	string permutation_function(string arr, int permutation_arr[], int j)
	{
		string result;
		for (int i = 0; i < j; i++)
		{
			result += arr[(permutation_arr[i]) - 1];
		}
		return result;
	}
	void key_bit(string key_as_string_64)
	{
		string temp;
		key_as_binary = converting_string_binary(key_as_string_64);
		key_as_string_56 = permutation_function(key_as_binary, premited_choice_1, 56);
		for (int i = 0; i < 28; i++)
		{
			key_left[i] = key_as_string_56[i];
			key_right[i] = key_as_string_56[i + 28];
		}
		for (int i = 0; i < 28; i++)
		{
			leftkey += key_left[i];
			rightkey += key_right[i];
		}
		for (int round = 0; round <= 15; round++)
		{
			if ((round == 0) || (round == 1) || round == 8 || round == 15)
			{
				leftkey = left_shifting(leftkey);
				rightkey = left_shifting(rightkey);
			}
			else {
				leftkey = left_shifting(leftkey);
				leftkey = left_shifting(leftkey);
				rightkey = left_shifting(rightkey);
				rightkey = left_shifting(rightkey);
			}
			sub_keys[round] = leftkey + rightkey;
			sub_sub_key[round] = permutation_function(sub_keys[round], premited_choice_key_2, 48);
			sub_keys[round] = sub_sub_key[round];
		}
	}
};
class plain : public key_64bit
{
public:
	string temperoray = "";
	int round = -1;
	string input_sbox;
	int SBOX[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
							0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
							4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
							15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
						{ 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
							3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
							0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
							13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

						{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
							13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
							13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
							1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
						{ 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
							13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
							10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
							3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
						{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
							14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
							4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
							11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
						{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
							10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
							9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
							4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
						{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
							13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
							1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
							6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
						{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
							1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
							7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
							2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };;
	string   plaintext_binary;
	string plainleft, plainright, new_expansion_48bit;
	int initial_permutation[64] = { 58, 50, 42, 34, 26, 18, 10, 2,60, 52, 44, 36, 28, 20, 12, 4,62, 54, 46, 38, 30, 22, 14, 6,64, 56, 48, 40, 32, 24, 16, 8,57, 49, 41, 33, 25, 17, 9, 1,59, 51, 43, 35, 27, 19, 11, 3,61, 53, 45, 37, 29, 21, 13, 5,63, 55, 47, 39, 31, 23, 15, 7 };
	int expansion_permutation[48] = {32, 1, 2, 3, 4, 5, 4, 5,6, 7, 8, 9, 8, 9, 10, 11,12, 13, 12, 13, 14, 15, 16, 17,16, 17, 18, 19, 20, 21, 20, 21,22, 23, 24, 25, 24, 25, 26, 27,28, 29, 28, 29, 30, 31, 32, 1};
	string SBOX_output = "";
	int final_permutation[64] = { 40, 8, 48, 16, 56, 24, 64, 32,39, 7, 47, 15, 55, 23, 63, 31,38, 6, 46, 14, 54, 22, 62, 30,37, 5, 45, 13, 53, 21, 61, 29,36, 4, 44, 12, 52, 20, 60, 28,35, 3, 43, 11, 51, 19, 59, 27,34, 2, 42, 10, 50, 18, 58, 26,33, 1, 41, 9, 49, 17, 57, 25 };
	string FUNCTION_OUTBUT = "";
	string right_after_xor = "";
	int permutation[32] = { 16, 7, 20, 21,29, 12, 28, 17,1, 15, 23, 26,5, 18, 31, 10,2, 8, 24, 14,32, 27, 3, 9,19, 13, 30, 6,22, 11, 4, 25 };
public:
	string showing(string plaintext_hexa)
	{
		string plaintext_binary_new;
		plaintext_binary = key_64bit::converting_string_binary(plaintext_hexa);
		plaintext_binary_new = permutation_function(plaintext_binary, initial_permutation, 64);
		return plaintext_binary_new;
	}
	string manger_function(string sub_keys[], string plaintext_binary_new, int roundsubkey)
	{
		string result;
		plainleft = "";
		plainright = "";
		for (int i = 0; i < 32; i++)
		{
			plainleft += plaintext_binary_new[i];
			plainright += plaintext_binary_new[i + 32];
		}
		new_expansion_48bit = "";
		new_expansion_48bit = permutation_function(plainright, expansion_permutation, 48);
		input_sbox = "";
		for (int i = 0; i < 48; i++)   //E table XOR subkey///////////////
		{
			input_sbox += XOR(new_expansion_48bit[i], sub_keys[roundsubkey][i]);
		}
		SBOX_output = "";
		temperoray = "";
		for (int i = 0; i <= 48; i++)  //SBOX 48-->32
		{
			if (i % 6 == 0)
			{
				if (i == 0) {
					temperoray += input_sbox[i];
					round = -1;
					continue;
				}
				round++;
				if (temperoray[0] == '0' && temperoray[5] == '0')
				{
					SBOX_output += decimal_to_hexa(SBOX[round][0][stoi(temperoray.substr(1, 4), 0, 2)]);
				}
				else  if (temperoray[0] == '0' && temperoray[5] == '1')
				{
					SBOX_output += decimal_to_hexa(SBOX[round][1][stoi(temperoray.substr(1, 4), 0, 2)]);
				}
				else  if (temperoray[0] == '1' && temperoray[5] == '0')
				{
					SBOX_output += decimal_to_hexa(SBOX[round][2][stoi(temperoray.substr(1, 4), 0, 2)]);
				}
				else  if (temperoray[0] == '1' && temperoray[5] == '1')
				{
					SBOX_output += decimal_to_hexa(SBOX[round][3][stoi(temperoray.substr(1, 4), 0, 2)]);
				}
				temperoray = "";
			}
			temperoray += input_sbox[i];
		}
		FUNCTION_OUTBUT = "";
		right_after_xor = "";
		FUNCTION_OUTBUT = permutation_function(SBOX_output, permutation, 32);
		for (int i = 0; i < 32; i++)
		{
			right_after_xor += XOR(plainleft[i], FUNCTION_OUTBUT[i]);
		}
		result = plainright + right_after_xor;
		return result;
	}
	void printing(string result)
	{
		string result_new, plainleft, plainright;
		for (int i = 0; i < 32; i++)
		{
			plainleft += result[i];
			plainright += result[i + 32];
		}
		result = plainright + plainleft;
		result_new = permutation_function(result, final_permutation, 64);
		cout << binaryToHex(result_new) << endl;
	}
};
int main()
{
	string input, text, key;
	getline(cin, input);
	text = input.substr(20, 16);
	key = input.substr(37);
	key_64bit key1;
	key1.key_bit(key);
	plain plaintext1;
	string plaintextenterance = "";
	plaintextenterance = plaintext1.showing(text);
	string result;
	if (input[12] == 'e' || input[12] == 'E')
	{
		for (int i = 0; i < 16; i++)
		{
			if (i == 0)
			result = plaintextenterance;
			result = plaintext1.manger_function(key1.sub_keys, result, i);
		}
		plaintext1.printing(result);
	}
	else if (input[12] == 'd' || input[12] == 'D')
	{
		for (int i = 15; i >= 0; i--)
		{
			if (i == 15)
				result = plaintextenterance;

			result = plaintext1.manger_function(key1.sub_keys, result, i);
		}
		plaintext1.printing(result);
	}
	return 0;
}

