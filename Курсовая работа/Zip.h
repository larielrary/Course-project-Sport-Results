#pragma once
#define  MAX_NODE 511 

struct NODE
{
	char   c;
	int     freq;
	bool    flag;
	int     left;
	int     right;
};

#define  MAX_BIT 10000

struct BITCODE
{
	char*   bits;
	int     soBit;
};

void	Init(NODE huffTree[]);
int		getSize(char* FileIn);
void	CountNode(int &SoNode, NODE huffTree[]);
void	Frequency(char* FileName, NODE huffTree[]);
void	Swap(int &a, int &b);
bool	Find2Min(int &min1, int &min2, int SoNode, NODE huffTree[]);
int		BuildHuffmanTree(NODE huffTree[]);
void	TravelHuffmanTree(int Root, char BITCODE[], int nBITCODE, NODE huffTree[]);
void	CreateBitCode(int nRoot, NODE huffTree[]);
void	WriteToFileHuf(FILE *&fo, int SoNode, NODE huffTree[]);
void	Encode(char* FileIn, char *FileOut, NODE huffTree[]);
int		getbit(char n, int i);
void	LoadHuffmanTree(FILE *&fi, NODE huffTree[]);
int		CountCharacter(NODE huffTree[]);
void	Decode(int nRoot, FILE *& fo, char *FileOut, NODE huffTree[]);
void	encodef(char inFile[], char onFile[]);
void	decodef(char file_cod[], char file_out[]);