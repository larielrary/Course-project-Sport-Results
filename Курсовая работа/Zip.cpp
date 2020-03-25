#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "Zip.h"

BITCODE BITCODETABLE[256];

void Init(NODE huffTree[])
{
	for (int i = 0; i < MAX_NODE; i++)
	{
		huffTree[i].c = i;
		huffTree[i].freq = 0;
		huffTree[i].flag = false;
		huffTree[i].left = -1;
		huffTree[i].right = -1;
	}
}
int getSize(char* FileIn)
{
	FILE* f = fopen(FileIn, "r");
	int pos;
	int end;
	pos = ftell(f);
	fseek(f, 0, SEEK_END);
	end = ftell(f);
	fseek(f, pos, SEEK_SET);
	return end;
}

//================================== ENCODE ========================================
void CountNode(int &SoNode, NODE huffTree[])
{
	for (int i = 0; i < 256; i++)
		if (huffTree[i].freq > 0) SoNode++;
}
void Frequency(char* FileName, NODE huffTree[])
{
	unsigned char c;
	FILE* fi = fopen(FileName, "rb");
	while (true)
	{
		fread(&c, 1, sizeof(char), fi);
		// End of file
		if (feof(fi)) break;
		huffTree[c].freq++;
	}
	fclose(fi);
}
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
bool Find2Min(int &min1, int &min2, int SoNode, NODE huffTree[])
{
	min1 = -1;
	min2 = -1;
	for (int i = 0; i < SoNode; i++)
		if (huffTree[i].flag == false && huffTree[i].freq > 0)
		{
			if (min1 == -1) min1 = i;
			else if (min2 == -1) min2 = i;
			if (huffTree[min1].freq > huffTree[min2].freq)
			{
				if (huffTree[i].freq < huffTree[min1].freq) min1 = i;
			}
			else
				if (huffTree[i].freq < huffTree[min2].freq) min2 = i;
		}
	if (min1 != -1 && min2 != -1)
	{
		if ((huffTree[min1].freq == huffTree[min2].freq) && (huffTree[min1].c > huffTree[min2].c) || huffTree[min1].freq > huffTree[min2].freq)
		{
			Swap(min1, min2);
		}
		return true;
	}
	return false;
}
int BuildHuffmanTree(NODE huffTree[])
{
	int SoNode = 256, i, j;
	bool found = false;
	while (true)
	{
		found = Find2Min(i, j, SoNode, huffTree);
		if (found == false) break;
		if (huffTree[i].c > huffTree[j].c) huffTree[SoNode].c = huffTree[j].c;
		else
			huffTree[SoNode].c = huffTree[i].c;
		huffTree[SoNode].freq = huffTree[i].freq + huffTree[j].freq;
		huffTree[SoNode].left = i;
		huffTree[SoNode].right = j;
		huffTree[i].flag = true;
		huffTree[j].flag = true;
		huffTree[SoNode].flag = false;
		SoNode++;
	}
	return SoNode - 1;
}
void TravelHuffmanTree(int Root, char BITCODE[], int nBITCODE, NODE huffTree[])
{
	if (huffTree[Root].left == -1 && huffTree[Root].right == -1)
	{
		BITCODETABLE[Root].soBit = nBITCODE;
		BITCODETABLE[Root].bits = new char[nBITCODE];
		for (int i = 0; i < nBITCODE; i++)
			BITCODETABLE[Root].bits[i] = BITCODE[i];
		return;
	}
	else
	{
		BITCODE[nBITCODE] = 0;
		TravelHuffmanTree(huffTree[Root].left, BITCODE, nBITCODE + 1, huffTree);
		BITCODE[nBITCODE] = 1;
		TravelHuffmanTree(huffTree[Root].right, BITCODE, nBITCODE + 1, huffTree);
	}
}
void CreateBitCode(int nRoot, NODE huffTree[])
{
	for (int i = 0; i < 256; i++)
	{
		BITCODETABLE[i].soBit = 0;
		BITCODETABLE[i].bits = NULL;
	};
	char BITCODE[MAX_BIT / 8];
	int nBITCODE = 0;
	TravelHuffmanTree(nRoot, BITCODE, nBITCODE, huffTree);
}
void WriteToFileHuf(FILE *&fo, int SoNode, NODE huffTree[])
{
	fwrite(&SoNode, sizeof(int), 1, fo);
	for (int i = 0; i < 256; i++)
	{
		if (huffTree[i].freq > 0)
		{
			char c = i;
			fwrite(&c, 1, sizeof(char), fo);
			int n = huffTree[i].freq;
			fwrite(&n, 1, sizeof(int), fo);
		}
	}
}
void Encode(char* FileIn, char *FileOut, NODE huffTree[])
{
	char out = 0;
	char BitFinalByte = 0;
	unsigned char c;
	char bitpos = 7;
	int SoNode = 0;
	FILE *fo = fopen(FileOut, "wb");
	Init(huffTree);
	Frequency(FileIn, huffTree);
	CountNode(SoNode, huffTree);
	WriteToFileHuf(fo, SoNode, huffTree);
	int Root = BuildHuffmanTree(huffTree);
	if (Root == -1) return;
	CreateBitCode(Root, huffTree);
	FILE* fi = fopen(FileIn, "rb");
	while (true)
	{
		fread(&c, 1, sizeof(char), fi);
		if (feof(fi)) break;
		for (int i = 0; i < BITCODETABLE[c].soBit; i++)
		{
			if (BITCODETABLE[c].bits[i] == 1)
			{
				out = out | (1 << bitpos);
			}
			if (bitpos == 0)
			{
				bitpos = 7;
				fwrite(&out, 1, sizeof(char), fo);
				out = 0;
			}
			else bitpos--;
		}
	}
	BitFinalByte = 7 - bitpos;
	if (BitFinalByte == 0) BitFinalByte = 8;
	else
		fwrite(&out, 1, sizeof(char), fo);
	fclose(fi);
	fclose(fo);
}
//================================= DECODE ====================================
int getbit(char n, int i)
{
	return (n >> i) & 1;
}
void LoadHuffmanTree(FILE *&fi, NODE huffTree[])
{
	Init(huffTree);
	unsigned char ch;
	int f;
	int soNode;
	fread(&soNode, sizeof(int), 1, fi);
	for (int i = 0; i < soNode; i++)
	{
		fread(&ch, sizeof(char), 1, fi);
		fread(&f, sizeof(int), 1, fi);
		huffTree[ch].freq = f;
	}
}
int CountCharacter(NODE huffTree[])
{
	int s = 0;
	for (int i = 0; i < 256; i++)
	{
		if (huffTree[i].freq > 0)  s += huffTree[i].freq;
	}
	return s;
}
void Decode(int nRoot, FILE *& fo, char *FileOut, NODE huffTree[])
{
	FILE *fdecode = fopen(FileOut, "wb");
	int nCurrent = nRoot;
	int soKiTu = CountCharacter(huffTree);
	int isoKiTu = 0;
	unsigned char c;
	while (true)
	{
		fread(&c, sizeof(char), 1, fo);
		for (int i = 7; i >= 0; i--)
		{
			int ibit = getbit(c, i);
			if (ibit == 1)
				nCurrent = huffTree[nCurrent].right;
			else
				nCurrent = huffTree[nCurrent].left;

			if (huffTree[nCurrent].left == -1 && huffTree[nCurrent].right == -1)
			{
				fwrite(&huffTree[nCurrent].c, sizeof(char), 1, fdecode);
				isoKiTu++;
				if (isoKiTu == soKiTu)
				{
					fclose(fdecode);
					return;
				}
				nCurrent = nRoot;
			}
		}
		if (feof(fo)) break;
	}
	fclose(fdecode);
}
void encodef(char inFile[], char onFile[])
{
	NODE huffTree[MAX_NODE];
	Encode(inFile, onFile, huffTree);
	Init(huffTree);
}
void decodef(char file_cod[], char file_out[])
{
	NODE huffTree[MAX_NODE];
	int SoNode = 0;
	FILE *fo = fopen(file_cod, "rb");
	LoadHuffmanTree(fo, huffTree);
	CountNode(SoNode, huffTree);
	int Root = BuildHuffmanTree(huffTree);
	CreateBitCode(Root, huffTree);
	Decode(Root, fo, file_out, huffTree);

}