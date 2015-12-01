#include <cstdio>
#include <cstring>

int main(int argc, char **argv)
{
	char key[20];
	int key_len;
	char val[20];
	int val_len;

	FILE *fp = fopen("tmp", "rb");
	fread(&key_len,1,sizeof(int),fp);
	fread(key,1,key_len,fp);
	fread(&val_len,1,sizeof(int), fp);
	fread(val, 1, val_len, fp);
	printf("1%.*s %.*s", key_len, key, val_len, val);
	fclose(fp);
}
