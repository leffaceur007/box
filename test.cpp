#include <iostream>

size_t str_pas_len(char*);
char* str_pas_cat(char*, char*);
size_t str_pas_replace(char*, char, char);

size_t str_cpp_len(char*);
char* str_cpp_cat(char*, char*);
size_t str_cpp_replace(char*, char, char);

int main()
{
    char p1[] = {3,'a','b','c'};
    char p2[] = {6,'d','e','f','g','h','i'};

    char* sp1 = p1;
    size_t len1 = str_pas_len(sp1);
    printf("The lenght of your pascal string p1 is %d \n", len1);

    char* sp2 = p2;
    size_t len2 = str_pas_len(sp2);
    printf("The lenght of your pascal string p2 is %d \n", len2);


    char* cat_str = str_pas_cat(sp1, sp2);
    size_t len3 = str_pas_len(cat_str);
    printf("The lenght of your pascal strings p1 and p2 is %d \n", len3);

    
    size_t count =  str_pas_replace(cat_str, 'a', 'A');
    printf("%9.9s\n", &cat_str[1]);
    printf("%d\n", count);
	    
    free(cat_str);
    


    return 0;
}

size_t str_pas_len(char* sp)
{
    return sp[0];
}

char* str_pas_cat(char* sp1, char* sp2)
{
    size_t len1 = str_pas_len(sp1);
    size_t len2 = str_pas_len(sp2);
    char* cat_str = (char*)malloc((len1 + len2 + 1));
    char* ptr = cat_str;
    *ptr = len1 + len2;
    ptr++;

    for (int i = 1; i <= len1; i++)
    {
   	 *ptr = sp1[i];
	 ptr++;
    }
    for (int i = 1; i <= len2; i++)
    {
 	*ptr = sp2[i];
	ptr++;
    }

    return cat_str;
}


size_t str_pas_replace(char* str, char find, char replace) {
	size_t count = 0;
	char* ptr = str; 

	for (int i = 1; i <= str[0]; i++) {
		if (ptr[i] == find) {
			ptr[i] = replace;
			count ++;
		}
	}

	return count;

}
