#include <stdio.h>
#include <string.h>
#define INT_BITS 16


/*Function to left rotate n by d bits*/
signed short leftRotate(signed short n, signed short d)
{
	return (n << d)|(n >> (INT_BITS - d));
}

signed short compute_hash(char pw[15])
{

	int hash=0;

	int char_count = strlen(pw);
	int char_index = char_count;

	while (char_index > 0)
	{
		char_index--;
		char current_char=pw[char_index];
		hash = hash ^ current_char;
		hash = leftRotate(hash, 1);
	}

	hash = hash ^ char_count ^ 0xCE4B;
	return hash;
}

int main()
{
	char inputhash[15];
	scanf("%15s", inputhash);
	
	printf("%x", (unsigned short) compute_hash(inputhash));
	return 0;
}


