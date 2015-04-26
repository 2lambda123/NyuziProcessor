// 
// Copyright 2011-2015 Jeff Bush
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// 

#include <stdio.h>
#include <sdmmc.h>

#define TRANSFER_LENGTH 0x800

int main()
{
	char *buf = (char*) 0x100000;
		
	if (initSdmmcDevice() < 0)
	{
		printf("error initializing card\n");
		return -1;
	}

	for (int i = 0; i < TRANSFER_LENGTH; i += BLOCK_SIZE)
		readBlockDevice(i, buf + i);
	
	return 0;
}