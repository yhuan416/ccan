#ifndef CCAN_STR_H
#define CCAN_STR_H
#include "config.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * streq - Are two strings equal?
 * @a: first string
 * @b: first string
 *
 * This macro is arguably more readable than "!strcmp(a, b)".
 *
 * Example:
 *	if (streq(somestring, ""))
 *		printf("String is empty!\n");
 */
#define streq(a,b) (strcmp((a),(b)) == 0)

/**
 * strstarts - Does this string start with this prefix?
 * @str: string to test
 * @prefix: prefix to look for at start of str
 *
 * Example:
 *	if (strstarts(somestring, "foo"))
 *		printf("String %s begins with 'foo'!\n", somestring);
 */
#define strstarts(str,prefix) (strncmp((str),(prefix),strlen(prefix)) == 0)

/**
 * strends - Does this string end with this postfix?
 * @str: string to test
 * @postfix: postfix to look for at end of str
 *
 * Example:
 *	if (strends(somestring, "foo"))
 *		printf("String %s end with 'foo'!\n", somestring);
 */
static inline bool strends(const char *str, const char *postfix)
{
	if (strlen(str) < strlen(postfix))
		return false;

	return streq(str + strlen(str) - strlen(postfix), postfix);
}

/**
 * stringify - Turn expression into a string literal
 * @expr: any C expression
 *
 * Example:
 *	#define PRINT_COND_IF_FALSE(cond) \
 *		((cond) || printf("%s is false!", stringify(cond)))
 */
#define stringify(expr)		stringify_1(expr)
/* Double-indirection required to stringify expansions */
#define stringify_1(expr)	#expr

/**
 * strcount - Count number of (non-overlapping) occurrences of a substring.
 * @haystack: a C string
 * @needle: a substring
 *
 * Example:
 *	int i;
 *      i = strcount("aaa aaa", "a");  // i = 6;
 *      i = strcount("aaa aaa", "ab"); // i = 0;
 *      i = strcount("aaa aaa", "aa"); // i = 2;
 */
size_t strcount(const char *haystack, const char *needle);

#include <ccan/str/str_debug.h>

/* These checks force things out of line, hence they are under DEBUG. */
#ifdef CCAN_STR_DEBUG
#include <ccan/build_assert/build_assert.h>

/* These are commonly misused: they take -1 or an *unsigned* char value. */
#undef isalnum
#undef isalpha
#undef isascii
#undef isblank
#undef iscntrl
#undef isdigit
#undef isgraph
#undef islower
#undef isprint
#undef ispunct
#undef isspace
#undef isupper
#undef isxdigit

/* You can use a char if char is unsigned. */
#if HAVE_BUILTIN_TYPES_COMPATIBLE_P && HAVE_TYPEOF
#define str_check_arg_(i)						\
	((i) + BUILD_ASSERT_OR_ZERO(!__builtin_types_compatible_p(typeof(i), \
								  char)	\
				    || (char)255 > 0))
#else
#define str_check_arg_(i) (i)
#endif

#define isalnum(i) str_isalnum(str_check_arg_(i))
#define isalpha(i) str_isalpha(str_check_arg_(i))
#define isascii(i) str_isascii(str_check_arg_(i))
#define isblank(i) str_isblank(str_check_arg_(i))
#define iscntrl(i) str_iscntrl(str_check_arg_(i))
#define isdigit(i) str_isdigit(str_check_arg_(i))
#define isgraph(i) str_isgraph(str_check_arg_(i))
#define islower(i) str_islower(str_check_arg_(i))
#define isprint(i) str_isprint(str_check_arg_(i))
#define ispunct(i) str_ispunct(str_check_arg_(i))
#define isspace(i) str_isspace(str_check_arg_(i))
#define isupper(i) str_isupper(str_check_arg_(i))
#define isxdigit(i) str_isxdigit(str_check_arg_(i))

#if HAVE_TYPEOF
/* With GNU magic, we can make const-respecting standard string functions. */
#undef strstr
#undef strchr
#undef strrchr

/* + 0 is needed to decay array into pointer. */
#define strstr(haystack, needle)					\
	((typeof((haystack) + 0))str_strstr((haystack), (needle)))
#define strchr(haystack, c)					\
	((typeof((haystack) + 0))str_strchr((haystack), (c)))
#define strrchr(haystack, c)					\
	((typeof((haystack) + 0))str_strrchr((haystack), (c)))
#endif
#endif /* CCAN_STR_DEBUG */

#endif /* CCAN_STR_H */
