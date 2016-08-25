#include <stdio.h>
#include <assert.h>

static void concat_str(char* str1_end, char* str2_start) {
    while (*str2_start != 0) {
	*str1_end++ = *str2_start++;
    }
    *str1_end = 0;
}

int del_substr(char* str1, char const *substr) {
    if (*substr == '\0')
	return 1;
    while (*str1 != 0) {
	const char* head = substr;
	char* cur = str1;
	if (*str1 == *head) {
	    while (*str1++ == *head++) {
		if (*head == 0) {
		    concat_str(cur, str1);
		    return 1;
		}
		if (*str1 == 0)
		    break;
	    }
	    str1 = cur + 1;
	} else {
	    str1 = cur + 1;
	}
    }
    return 0;
}

int main() {
    /* 必须这么声明字符串，因为在OSX中，字符串字面量是一个编译时就初始化好的字符数组，对其操作会触发 `bus error` */
    char source[] = "ABCDEFG";
    char* s = source;

    int ret = del_substr(s, "FGH");
    assert(ret == 0);

    s = source;
    ret = del_substr(s, "CDF");
    assert(ret == 0);

    s = source;
    ret = del_substr(s, "XABC");
    assert(ret == 0);

    s = source;
    ret = del_substr(s, "CDE");
    assert(ret == 1);
    printf("%s\n", s);

    s = source;
    ret = del_substr(s, "");
    assert(ret == 1);
    printf("%s\n", s);
    return 0;
    
}
