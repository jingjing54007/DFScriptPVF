# DFScriptPVF
A Dungeon & Fighter Script.pvf unpacker. Only used in 60/55 version.

# 55 PVF Structure

## Script Header
"DNF_SCRIPT_PACK" -15bytes
File Tree Length -4bytes
File Tree Checksum -4bytes
Files Numbers -4bytes

## Script FileTree Format
fileNumber -4bytes
relOffset -4bytes
fileLength -4bytes
checksum -4bytes
fileNameLength -4bytes
fileName -fileNameLength bytes

# 60 PVF Structure

## Script Header
lengthChecksum -4bytes
checksum -lengthChecksum bytes
version -4bytes
lengthDirTree -4bytes
dirTreeChecksum -4bytes
numFiles -4bytes

## Script FileTree Format
fileNumber -4bytes
fileNameLength -4bytes
fileName -fileNameLength bytes
fileLength -4bytes
checksum -4bytes
relOffset -4bytes
