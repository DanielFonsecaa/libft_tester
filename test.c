#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <stddef.h>
#include <bsd/string.h>
#include <unistd.h>

int file_exists(const char *filename)
{
    return access(filename, F_OK) == 0;
}
void	test_atoi(char *src, int (*f)(const char*), int (*fo)(const char*))
{
	int	expected;
	int	result;

	expected = fo(src);
	result = f(src);
	if (expected == result)
	{	
		if (!ft_isprint(src[0]))
			printf("with ascii code %i --- \x1B[32m \033[1mSUCCESS \033[0m\n\t\x1B[0m", src[0]);
		else
			printf("with %s --- \x1B[32m\033[1m SUCCESS\033[0m \n\t\x1B[0m", src);
	}
	else 
		printf("\x1B[31m\033[1m FAILED\033[0m \x1B[0m, you sent %s , was expected %d . And you got %d \n\t",src, expected, result);
}
void	test_(int c, int (*f)(int), int (*fo)(int))
{
	int expected = fo(c);
	int result = f(c);
    
    if ((expected > 0 && result > 0) || (expected == 0 && result == 0) || (result < 0 && expected < 0))
	{
        if (!ft_isprint(c))
            printf("with ascii code %i --- \x1B[32m \033[1mSUCCESS\033[0m \n\t\x1B[0m", c);
		else
            printf("with '%c' --- \x1B[32m\033[1m SUCCESS \033[0m\n\t\x1B[0m", c);
    }
	else
        printf("\x1B[31m \033[1mFAILED\033[0m \x1B[0m, you sent '%c' (ascii code %i), expected %d but got %d.\n\t", c, c, expected, result);
}
void	test_bzero(const char *src, size_t n)
{
    // Allocate memory for the buffers
    char *original = malloc(strlen(src) + 1); // +1 for the null terminator
    char *custom = malloc(strlen(src) + 1);   // +1 for the null terminator

    if (!original || !custom) {
        printf("\x1B[31m\033[1m FAILED \033[0m\x1B[0m, memory allocation failed.\n");
        return;
    }

    strcpy(original, src);
    strcpy(custom, src);

    bzero(original, n);
    ft_bzero(custom, n);
    
    if (memcmp(original, custom, strlen(src)) == 0) {
        printf("with %s and n = %zu --- \x1B[32m\033[1m SUCCESS \033[0m\n\t\x1B[0m", src, n);
    } else {
        printf("\x1B[31m\033[1mFAILED \x1B[0m\033[0m, expected \"%s\" but got \"%s\".\n\t", original, custom);
    }

    // Free allocated memory
    free(original);
    free(custom);
}
void	test_memchr(const char *s, int c, size_t n) 
{
    void *expected = memchr(s, c, n);
    void *result = ft_memchr(s, c, n);

    if (expected == result) {
        if (result != NULL) {
            printf("Test with \"%s\", searching for '%c' --- \x1B[32m \033[1mSUCCESS \033[0m\n\t\x1B[0m", s, c);
        } else {
            printf("Test with \"%s\", searching for '%c' --- \x1B[32m \033[1mSUCCESS (not found) \033[0m\n\t\x1B[0m", s, c);
        }
    } else {
        printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m, you sent \"%s\", searching for '%c', expected %p but got %p.\n\t", s, c, expected, result);
	}
}
void	test_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1 = (char *)s1;
	char	*str2 = (char *)s2;
	int expected = memcmp(s1, s2, n);
	int result = ft_memcmp(s1, s2, n);

    if (expected == result)
            printf("Test with \"%s\" and \"%s\" --- \x1B[32m \033[1mSUCCESS\033[0m \n\t\x1B[0m",str1, str2);
    else
        printf("\x1B[31m \033[1mFAILED\033[0m \x1B[0m, you sent \"%s\", and \"%s\", expected %d but got %d.\n\t", str1, str2, expected, result);
}
void	test_memcpy(void *dest, const void *src, size_t n)
{
	char *expected = (char *)malloc(n + 1);
	if (!expected)
		printf("\x1B[31m\033[1m FAILED \033[0m\x1B[0m, memory allocation failed.\n");
	ft_memcpy(dest, src, n);
	memcpy(expected, src, n);
    if (memcmp(expected, dest, n) == 0)
		printf("Test with \"%s\" and size %zu --- \x1B[32m \033[1mSUCCESS\033[0m \n\t\x1B[0m",(char *)src, n);
    else
		printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m, you sent \"%s\", expected %s but got %s.\n\t", (char *)src, expected, (char *)dest);

	free(expected);
}
void	test_memmove(void *dest, const void *src, size_t n)
{
	char *expected = (char *)malloc(n + 1);
	if (!expected)
		printf("\x1B[31m\033[1m FAILED \033[0m\x1B[0m, memory allocation failed.\n");
	ft_memmove(dest, src, n);
	memmove(expected, src, n);
    if (memcmp(expected, dest, n) == 0)
		printf("Test with \"%s\" and size %zu --- \x1B[32m \033[1mSUCCESS\033[0m \n\t\x1B[0m",(char *)src, n);
    else
		printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m, you sent \"%s\", expected %s but got %s.\n\t", (char *)src, expected, (char *)dest);

	free(expected);
}
void	test_memset(void *s, int c, size_t n)
{
	char *expected = (char *)s;
	ft_memset(s, c, n);
	memset(expected, c, n);
    if (memcmp(expected, s, n) == 0)
		printf("Test with \"%s\" and size %zu --- \x1B[32m \033[1mSUCCESS\033[0m \n\t\x1B[0m",(char *)s, n);
    else
		printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m, you sent \"%s\", expected %s but got %s.\n\t", (char *)s, expected, (char *)s);
}
void	test_strchr(const char *s, int c)
{
	char *expected = ft_strchr(s, c);
	char *result = strchr(s, c);
    if (expected == result)
	{	if (result != NULL)
            printf("Test with string \"%s\", searching for '%c' --- \x1B[32m SUCCESS \n\t\x1B[0m", s, c);
		else
			printf("Test with string \"%s\", searching for '%c' --- \x1B[32m SUCCESS (not found) \n\t\x1B[0m", s, c);
	}
	else
		printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m, you sent \"%s\", expected %s but got %s.\n\t", s, expected, s);
}
void	test_strdup(const char *s)
{
	char *expected = strdup(s);
	char *result = ft_strdup(s);
	if (strcmp(expected, result) == 0)
		printf("Test with string \"%s\" --- \x1B[32m SUCCESS \n\t\x1B[0m", s);
	else
		printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m --- you sent \"%s\", expected %s but got %s\n\t", s, expected, result);
	free(result);
	free(expected);
}
void	test_strlcat(char *dst, const char *src, size_t size)
{
	char temp[100];
	strcpy(temp, dst);
	size_t len_result = ft_strlcat(temp, src, size);
	size_t len_expected = strlcat(dst, src, size);

	if (len_expected == len_result)
			printf("Test with string \"%s\" --- \x1B[32m SUCCESS \n\t\x1B[0m", src);
	else
		printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m --- you sent \"%s\", expected %zu but got %zu\n\t", src, len_expected, len_result);
		
}
void	test_strlcpy(char *dst, const char *src, size_t size)
{
	char temp[100];
	strcpy(temp, dst);
	size_t len_result = ft_strlcpy(temp, src, size);
	size_t len_expected = strlcpy(dst, src, size);

	if (len_expected == len_result)
			printf("Test with string \"%s\" --- \x1B[32m SUCCESS \n\t\x1B[0m", src);
	else
		printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m --- you sent \"%s\", expected %zu but got %zu\n\t", src, len_expected, len_result);
		
}
void	test_strlen(const char *s)
{
	size_t result = ft_strlen(s);
	size_t expected = strlen(s);

	if (expected == result)
			printf("Test with string \"%s\" --- \x1B[32m SUCCESS \n\t\x1B[0m", s);
	else
		printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m --- you sent \"%s\", expected %zu but got %zu\n\t", s, expected, result);
		

}
void	test_strncmp(const char *s1, const char *s2, size_t n)
{
	int result = ft_strncmp(s1, s2, n);
	int expected = strncmp(s1, s2, n);

	if (expected == result)
			printf("Test with string \"%s\" and \"%s\" --- \x1B[32m SUCCESS \n\t\x1B[0m", s1, s2);
	else
		printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m --- you sent \"%s\" and \"%s\", expected %d but got %d\n\t", s1, s2, expected, result);
}
void	test_strnstr(const char *big, const char *little, size_t len)
{
	char *result = ft_strnstr(big, little, len);
	char *expected = strnstr(big, little, len);

	if (result == expected)
		printf("Test with string \"%s\" and \"%s\" --- \x1B[32m SUCCESS \n\t\x1B[0m", big, little);
	else
		printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m --- you sent \"%s\" and \"%s\", expected %s but got %s\n\t", big, little, expected, result);
}
void	test_tolower(int c)
{
	int expected = tolower(c);
	int result = ft_tolower(c);

	if (result == expected)
		printf("Test with number \"%d\" --- \x1B[32m SUCCESS \n\t\x1B[0m", c);
	else
		printf("\x1B[31m \033[1mFAILED \033[0m\x1B[0m --- you sent \"%d\", expected %d but got %d\n\t", c, expected, result);
}

int	main()
{
	printf("\n\x1B[35m\033[1m\tTestes para ft_atoi:\x1B[0m \n\n\t");

	test_atoi("1235", ft_atoi, atoi);
	test_atoi("2147483647", ft_atoi, atoi);
	test_atoi("-2147483648", ft_atoi, atoi);
	test_atoi("", ft_atoi, atoi);
	test_atoi("999999999999", ft_atoi, atoi);
	test_atoi("-999999999999", ft_atoi, atoi);
	test_atoi("(NULL)", ft_atoi, atoi);
	test_atoi("\n", ft_atoi, atoi);
	test_atoi("\t", ft_atoi, atoi);
	test_atoi("NULL", ft_atoi, atoi);
	
	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_bzero:\x1B[0m \n\n\t");

	test_bzero("hello", 4);
	test_bzero("hello", 5);
	test_bzero("hello", 10);
	test_bzero("hello", 0);
	test_bzero("", 0);
	test_bzero("abc", 2);
	test_bzero("abc", 3);
	test_bzero("1234567890", 6);

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_isalnum:\x1B[0m \n\n\t");
	
	test_(212, ft_isalnum, isalnum);
	test_('0', ft_isalnum, isalnum); 
    test_('A', ft_isalnum, isalnum); 
    test_('z', ft_isalnum, isalnum);
    test_(' ', ft_isalnum, isalnum);
    test_('!', ft_isalnum, isalnum);
    test_('9', ft_isalnum, isalnum);
    test_('\n', ft_isalnum, isalnum);
    test_('\t', ft_isalnum, isalnum);
    test_('\0', ft_isalnum, isalnum);

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_isalpha:\x1B[0m \n\n\t");
	
	test_(212, ft_isalpha, isalpha);
	test_('0', ft_isalpha, isalpha); 
    test_('A', ft_isalpha, isalpha); 
    test_('z', ft_isalpha, isalpha);
    test_(' ', ft_isalpha, isalpha);
    test_('!', ft_isalpha, isalpha);
    test_('9', ft_isalpha, isalpha);
    test_('\n', ft_isalpha, isalpha);
    test_('\t', ft_isalpha, isalpha);
    test_('\0', ft_isalpha, isalpha);

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_isascii:\x1B[0m \n\n\t");
	
	test_(212, ft_isascii, isascii);
	test_('0', ft_isascii, isascii); 
    test_('A', ft_isascii, isascii); 
    test_('z', ft_isascii, isascii);
    test_(' ', ft_isascii, isascii);
    test_('!', ft_isascii, isascii);
    test_('9', ft_isascii, isascii);
    test_('\n', ft_isascii, isascii);
    test_('\t', ft_isascii, isascii);
    test_('\0', ft_isascii, isascii);

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_isdigit:\x1B[0m \n\n\t");
	
	test_(212, ft_isdigit, isdigit);
	test_('0', ft_isdigit, isdigit); 
    test_('A', ft_isdigit, isdigit); 
    test_('z', ft_isdigit, isdigit);
    test_(' ', ft_isdigit, isdigit);
    test_('!', ft_isdigit, isdigit);
    test_('9', ft_isdigit, isdigit);
    test_('\n', ft_isdigit, isdigit);
    test_('\t', ft_isdigit, isdigit);
    test_('\0', ft_isdigit, isdigit);

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_isprint:\x1B[0m \n\n\t");
	
	test_(212,  ft_isprint, isprint);
	test_('0',  ft_isprint, isprint); 
    test_('A',  ft_isprint, isprint); 
    test_('z',  ft_isprint, isprint);
    test_(' ',  ft_isprint, isprint);
    test_('!',  ft_isprint, isprint);
    test_('9',  ft_isprint, isprint);
    test_('\n', ft_isprint, isprint);
    test_('\t', ft_isprint, isprint);
    test_('\0', ft_isprint, isprint);

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_memchr:\x1B[0m \n\n\t");
	
	test_memchr("hello", 'e', 5); 
    test_memchr("hello", 'x', 5); 
    test_memchr("hello", 'o', 10);
    test_memchr("", 'a', 0);
    test_memchr("hello", 'h', 5); 
    test_memchr("hello", 'o', 5); 

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_memcmp:\x1B[0m \n\n\t");

    test_memcmp("abc", "abc", 3); 
    test_memcmp("abc", "abd", 3); 
    test_memcmp("abc", "abc", 2); 
    test_memcmp("abc", "ab", 3);  
    test_memcmp("abc", "abcd", 3);
    test_memcmp("abc", "a", 1);   
    test_memcmp("abc", "xyz", 3); 
    test_memcmp("", "", 0);       

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_memcpy:\x1B[0m \n\n\t");
	
	char dest1[10];
	test_memcpy(dest1, "hello", 5); // Basic copy
    test_memcpy(dest1, "hello", 3); // Partial copy
    test_memcpy(dest1, "hello", 0); // Zero length copy
    test_memcpy(dest1, "world", 5); // Copying to an empty destination

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_memmove:\x1B[0m \n\n\t");
	
	char dest2[10];
    test_memmove(dest2, "hello", 5); // Basic copy
    test_memmove(dest2, "hello", 3); // Partial copy
    test_memmove(dest2, "hello", 0); // Zero length copy
    test_memmove(dest2, "world", 5); // Copying to an empty destination

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_memset:\x1B[0m \n\n\t");
	
	char dest3[10];
    test_memset(dest3, 'A', 5); // Basic fill
    test_memset(dest3, 0, 5);    // Fill with zero
    test_memset(dest3, 'B', 3);   // Partial fill
    test_memset(dest3, 'C', 0);   // Fill with length zero
    test_memset(dest3, 'D', 5);   // Fill entire buffer
	
	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_strchr:\x1B[0m \n\n\t");
	
	test_strchr("hello", 'e'); // Found
    test_strchr("hello", 'x'); // Not found
    test_strchr("hello", '\0'); // Null terminator
    test_strchr("hello", 'h'); // First character
    test_strchr("hello", 'o'); // Last character
    test_strchr("", 'a'); // Empty string
	
	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_strdup:\x1B[0m \n\n\t");

	test_strdup("hello");          // Basic duplication
    test_strdup("");               // Empty string
    test_strdup("hello world");    // String with spaces
    test_strdup("hello@123!");     // String with special characters
    //test_strdup(NULL);             // Null input ask about segfault
	
	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_strlcat:\x1B[0m \n\n\t");

	char dest4[20] = "Hello, ";
    test_strlcat(dest4, "World!", 20); // Basic concatenation

    char dest5[20] = "Hello, ";
    test_strlcat(dest5, "World!", 10); // Buffer too small

    char dest6[20] = "Hello, ";
    test_strlcat(dest6, "", 20); // Empty source

    char dest7[20] = "";
    test_strlcat(dest7, "World!", 20); // Empty destination

    char dest8[20] = "Hello";
    test_strlcat(dest8, ", World!", 13); // Exact fit

	//char dest9[20] = "Hello, ";
	//test_strlcat(dest9, NULL, 20); // Null input segment fault

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_strlcpy:\x1B[0m \n\n\t");

	char dest9[20] = "Initial"; // Buffer for test
    test_strlcpy(dest9, "Hello, World!", 20); // Basic copy

    char dest10[20] = "Initial"; // Buffer for test
    test_strlcpy(dest10, "Hello, World!", 5); // Buffer too small

    char dest11[20] = "Initial"; // Buffer for test
    test_strlcpy(dest11, "", 20); // Empty source

    char dest12[20] = "Initial"; // Buffer for test
    test_strlcpy(dest12, "Hello", 20); // Copy to empty destination

    char dest13[20] = "Initial"; // Buffer for test
    test_strlcpy(dest13, "Hello", 6); // Exact fit

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_strlen:\x1B[0m \n\n\t");

	test_strlen("Hello");          // Basic length
    test_strlen("");               // Empty string
    test_strlen("Hello World");    // String with spaces
    test_strlen("Hello@123!");     // String with special characters
    test_strlen("Hello\t");        // String with newline
	
	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_strncmp:\x1B[0m \n\n\t");

	test_strncmp("Hello", "Hello", 5);          // Basic comparison
    test_strncmp("Hello", "World", 5);          // Different strings
    test_strncmp("Hello", "Helium", 3);         // Partial comparison
    test_strncmp("Hello", "Hello, World!", 5);  // Different lengths
    test_strncmp("Hello", "hello", 5);          // Case sensitivity

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_strnstr:\x1B[0m \n\n\t");

	test_strnstr("Hello, World!", "World", 13);          // Basic substring
    test_strnstr("Hello, World!", "Earth", 13);          // Substring not found
    test_strnstr("Hello, World!", "", 13);               // Needle is empty
    test_strnstr("Hello", "Hello, World!", 5);           // Needle
	
	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_tolower:\x1B[0m \n\n\t");

	test_tolower('a'); // Lowercase character
    test_tolower('A'); // Uppercase character
    test_tolower('1'); // Non-alphabetic character
    test_tolower('@'); // Special character
    test_tolower(' '); // Whitespace character
    test_tolower(200); // Extended ASCII character
    test_tolower(-1); // Negative input
		
	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_toupper:\x1B[0m \n\n\t");

	test_tolower('a'); // lowercase character
	test_tolower('A'); // uppercase character
	test_tolower('1'); // non-alphabetic character
	test_tolower('@'); // special character
	test_tolower(' '); // whitespace character
	test_tolower(200); // extended ascii character
	test_tolower(-1); // Negative input

	printf("\n\n\t-----------------------------\n");
	printf("\x1B[35m\033[1m\tTestes para ft_calloc:\x1B[0m \n\n\t");

	printf("\x1B[34m\033[1m\tNOT DONE YET. WAIT FOR MORE\x1B[0m \n\n\t");
   // test_calloc(5, sizeof(int));          // Basic allocation
   // test_calloc(0, sizeof(int));          // Zero allocation
   // test_calloc(1000, sizeof(int));       // Large allocation
   // test_calloc(10, sizeof(char));        // Allocation for characters

}
