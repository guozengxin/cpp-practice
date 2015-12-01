#include <cstdio>
#include <cstring>

int main(int argc, void **argv)
{
	char *key = "Hello";
	int key_len = strlen(key);
	char *val = "World";
	int val_len = strlen(val);

	FILE *fp = fopen("tmp", "wb");
	printf("int size %d\n", sizeof(int));
	fwrite(&key_len, 1, sizeof(int), fp);
	fwrite((void*)key, 1, key_len, fp);
	fwrite(&val_len, 1, sizeof(int), fp);
	fwrite((void*)val, 1, val_len, fp);
	fclose(fp);
}
