#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

const int c_size = 26;

int prepare_key(char *key) {
    if (*key == '\0')
	return 0;
    
    int map[c_size];
    memset(map, 0, sizeof(map));

    char* head = key;
    while (*key) {
	char ch = toupper(*key);
	if (!(ch >= 'A' && ch <= 'Z'))
	    return 0;
	if (map[ch - 'A'] == 0) {
	    *head++ = ch;
	    map[ch - 'A'] = 1;
	}
	key++;
    }
    for (int i=0; i<c_size; i++) {
	if (map[i] == 0)
	    *head++ = i + 'A';
    }
    *head = 0;
    return 1;
}

void encrypt(char *data, char const *key) {
    while (*data) {
	char ch = toupper(*data);
	
	if (ch >= 'A' && ch <= 'Z') {
	    *data = *(key + ch - 'A');
	}
	data++;
    }
}

void decrypt(char *data, char const *key) {
    int map[c_size];
    memset(map, 0, sizeof(map));
    int cur = 0;
    while (*key) {
	map[*key - 'A'] = cur++;
	key++;
    }
    
    while (*data) {
	char ch = toupper(*data);

	if (ch >= 'A' && ch <= 'Z')
	    *data = 'A' + map[ch - 'A'];

	data++;
    }
}

int main() {
    char key[27] = "TRAILBLAZERS";
    int ret = prepare_key(key);
    assert(ret == 1);

    printf("%s\n", key);

    char data[] = "Attack at dawn 12:00";
    encrypt(data, key);
    printf("Data: %s\n", data);

    decrypt(data, key);
    printf("Data: %s\n", data);
    return 0;
}
