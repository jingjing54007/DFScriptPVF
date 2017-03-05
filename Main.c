#include <stdlib.h>
#include <stdio.h>

#include "Tokenizer.h"
#include "FileIO.h"

int main(int argc, char* argv[])
{
	FILE* Script;
	unsigned char* dirTree;
	unsigned char* internalFiles;
	struct fileHeader scriptHeader;
	FILE* OutputFile;

	//Decrypt and output
	Script = safe_fopen("Script.pvf", "rb");
	scriptHeader = GetHeader(Script);
	dirTree = DecryptDirTree(Script, scriptHeader);
	OutputFile = safe_fopen("Script.pvf.bin", "wb");
	fwrite(dirTree, scriptHeader.lengthDirTree, 1, OutputFile);
	fclose(OutputFile);

	internalFiles = DecryptFileTree(Script, dirTree, scriptHeader);

	Output(dirTree, internalFiles, scriptHeader);
	fclose(Script);

	free(dirTree);
	free(internalFiles);
	remove("Script.pvf.bin");

	printf("============Script.pvf is unpacked successfully=============");
	char s[1];
	scanf("%s", s);

	return 0;
}
