/* ANSI-C code produced by gperf version 3.0.4 */
/* Command-line: gperf --language=ANSI-C --struct-type --slot-name=name --hash-fn-name=ttcn3_hash --lookup-fn-name=ttcn3_lookup  */
/* Computed positions: -k'1,3,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif


#include "strmake.h"
#define START_VARIABLE	1001
#define START_WORD	2001
#define START_SHARP	3001
#define START_YACC	4001
#define IS_RESERVED_WORD(a)	((a) >= START_WORD)
#define IS_RESERVED_VARIABLE(a)	((a) >= START_VARIABLE && (a) < START_WORD)
#define IS_RESERVED_SHARP(a)	((a) >= START_SHARP && (a) < START_YACC)
#define IS_RESERVED_YACC(a)	((a) >= START_YACC)

#define TTCN3_ACTION	2001
#define TTCN3_ACTIVATE	2002
#define TTCN3_ADDRESS	2003
#define TTCN3_ALIVE	2004
#define TTCN3_ALL	2005
#define TTCN3_ALT	2006
#define TTCN3_ALTSTEP	2007
#define TTCN3_AND	2008
#define TTCN3_AND4B	2009
#define TTCN3_ANY	2010
#define TTCN3_ANYTYPE	2011
#define TTCN3_BITSTRING	2012
#define TTCN3_BOOLEAN	2013
#define TTCN3_BREAK	2014
#define TTCN3_CASE	2015
#define TTCN3_CALL	2016
#define TTCN3_CATCH	2017
#define TTCN3_CHAR	2018
#define TTCN3_CHARSTRING	2019
#define TTCN3_CHECK	2020
#define TTCN3_CLEAR	2021
#define TTCN3_COMPLEMENT	2022
#define TTCN3_COMPONENT	2023
#define TTCN3_CONNECT	2024
#define TTCN3_CONST	2025
#define TTCN3_CONTINUE	2026
#define TTCN3_CONTROL	2027
#define TTCN3_CREATE	2028
#define TTCN3_DEACTIVATE	2029
#define TTCN3_DEFAULT	2030
#define TTCN3_DISCONNECT	2031
#define TTCN3_DISPLAY	2032
#define TTCN3_DO	2033
#define TTCN3_DONE	2034
#define TTCN3_ELSE	2035
#define TTCN3_ENCODE	2036
#define TTCN3_ENUMERATED	2037
#define TTCN3_ERROR	2038
#define TTCN3_EXCEPT	2039
#define TTCN3_EXCEPTION	2040
#define TTCN3_EXECUTE	2041
#define TTCN3_EXTENDS	2042
#define TTCN3_EXTENSION	2043
#define TTCN3_EXTERNAL	2044
#define TTCN3_FAIL	2045
#define TTCN3_FALSE	2046
#define TTCN3_FLOAT	2047
#define TTCN3_FOR	2048
#define TTCN3_FRIEND	2049
#define TTCN3_FROM	2050
#define TTCN3_FUNCTION	2051
#define TTCN3_GETVERDICT	2052
#define TTCN3_GETCALL	2053
#define TTCN3_GETREPLY	2054
#define TTCN3_GOTO	2055
#define TTCN3_GROUP	2056
#define TTCN3_HALT	2057
#define TTCN3_HEXSTRING	2058
#define TTCN3_IF	2059
#define TTCN3_IFPRESENT	2060
#define TTCN3_IMPORT	2061
#define TTCN3_IN	2062
#define TTCN3_INCONC	2063
#define TTCN3_INFINITY	2064
#define TTCN3_INOUT	2065
#define TTCN3_INTEGER	2066
#define TTCN3_INTERLEAVE	2067
#define TTCN3_KILL	2068
#define TTCN3_KILLED	2069
#define TTCN3_LABEL	2070
#define TTCN3_LANGUAGE	2071
#define TTCN3_LENGTH	2072
#define TTCN3_LOG	2073
#define TTCN3_MAP	2074
#define TTCN3_MATCH	2075
#define TTCN3_MESSAGE	2076
#define TTCN3_MIXED	2077
#define TTCN3_MOD	2078
#define TTCN3_MODIFIES	2079
#define TTCN3_MODULE	2080
#define TTCN3_MODULEPAR	2081
#define TTCN3_MTC	2082
#define TTCN3_NOBLOCK	2083
#define TTCN3_NONE	2084
#define TTCN3_NOT	2085
#define TTCN3_NOT4B	2086
#define TTCN3_NOWAIT	2087
#define TTCN3_NULL	2088
#define TTCN3_OCTETSTRING	2089
#define TTCN3_OF	2090
#define TTCN3_OMIT	2091
#define TTCN3_ON	2092
#define TTCN3_OPTIONAL	2093
#define TTCN3_OR	2094
#define TTCN3_OR4B	2095
#define TTCN3_OUT	2096
#define TTCN3_OVERRIDE	2097
#define TTCN3_PARAM	2098
#define TTCN3_PASS	2099
#define TTCN3_PATTERN	2100
#define TTCN3_PERMUTATION	2101
#define TTCN3_PORT	2102
#define TTCN3_PRESENT	2103
#define TTCN3_PRIVATE	2104
#define TTCN3_PROCEDURE	2105
#define TTCN3_PUBLIC	2106
#define TTCN3_RAISE	2107
#define TTCN3_READ	2108
#define TTCN3_RECEIVE	2109
#define TTCN3_RECORD	2110
#define TTCN3_RECURSIVE	2111
#define TTCN3_REM	2112
#define TTCN3_REPEAT	2113
#define TTCN3_REPLY	2114
#define TTCN3_RETURN	2115
#define TTCN3_RUNNING	2116
#define TTCN3_RUNS	2117
#define TTCN3_SELECT	2118
#define TTCN3_SELF	2119
#define TTCN3_SEND	2120
#define TTCN3_SENDER	2121
#define TTCN3_SET	2122
#define TTCN3_SETVERDICT	2123
#define TTCN3_SIGNATURE	2124
#define TTCN3_START	2125
#define TTCN3_STOP	2126
#define TTCN3_SUBSET	2127
#define TTCN3_SUPERSET	2128
#define TTCN3_SYSTEM	2129
#define TTCN3_TEMPLATE	2130
#define TTCN3_TESTCASE	2131
#define TTCN3_TIMEOUT	2132
#define TTCN3_TIMER	2133
#define TTCN3_TO	2134
#define TTCN3_TRIGGER	2135
#define TTCN3_TRUE	2136
#define TTCN3_TYPE	2137
#define TTCN3_UNION	2138
#define TTCN3_UNIVERSAL	2139
#define TTCN3_UNMAP	2140
#define TTCN3_VALUE	2141
#define TTCN3_VALUEOF	2142
#define TTCN3_VAR	2143
#define TTCN3_VARIANT	2144
#define TTCN3_VERDICTTYPE	2145
#define TTCN3_WHILE	2146
#define TTCN3_WITH	2147
#define TTCN3_XOR	2148
#define TTCN3_XOR4B	2149
struct keyword { char *name; int token; };

#define TOTAL_KEYWORDS 149
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 11
#define MIN_HASH_VALUE 3
#define MAX_HASH_VALUE 368
/* maximum key range = 366, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
ttcn3_hash (register const char *str, register unsigned int len)
{
  static unsigned short asso_values[] =
    {
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369,   0, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 190,   5,  55,
       15,   5,  75,  80, 180, 150, 120,   0,  20,  95,
       30,  95,  65,   0, 125,   0,   0,  75,  70, 100,
       45, 115, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369, 369, 369, 369,
      369, 369, 369, 369, 369, 369, 369
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
      case 1:
        hval += asso_values[(unsigned char)str[0]+1];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

#ifdef __GNUC__
__inline
#if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
struct keyword *
ttcn3_lookup (register const char *str, register unsigned int len)
{
  static struct keyword wordlist[] =
    {
      {""}, {""}, {""},
      {"set", TTCN3_SET},
      {"pass", TTCN3_PASS},
      {""}, {""}, {""},
      {"alt", TTCN3_ALT},
      {""},
      {"setverdict", TTCN3_SETVERDICT},
      {"subset", TTCN3_SUBSET},
      {"present", TTCN3_PRESENT},
      {""}, {""},
      {"disconnect", TTCN3_DISCONNECT},
      {""}, {""},
      {"activate", TTCN3_ACTIVATE},
      {""}, {""}, {""}, {""}, {""},
      {"case", TTCN3_CASE},
      {"check", TTCN3_CHECK},
      {"select", TTCN3_SELECT},
      {"address", TTCN3_ADDRESS},
      {""}, {""},
      {"and4b", TTCN3_AND4B},
      {"create", TTCN3_CREATE},
      {""}, {""},
      {"runs", TTCN3_RUNS},
      {""},
      {"return", TTCN3_RETURN},
      {"pattern", TTCN3_PATTERN},
      {"and", TTCN3_AND},
      {""}, {""},
      {"action", TTCN3_ACTION},
      {"message", TTCN3_MESSAGE},
      {""},
      {"done", TTCN3_DONE},
      {""}, {""}, {""},
      {"all", TTCN3_ALL},
      {"send", TTCN3_SEND},
      {"const", TTCN3_CONST},
      {""},
      {"connect", TTCN3_CONNECT},
      {"modifies", TTCN3_MODIFIES},
      {""}, {""},
      {"module", TTCN3_MODULE},
      {""},
      {"continue", TTCN3_CONTINUE},
      {"call", TTCN3_CALL},
      {""},
      {"killed", TTCN3_KILLED},
      {""},
      {"mod", TTCN3_MOD},
      {"kill", TTCN3_KILL},
      {"break", TTCN3_BREAK},
      {"public", TTCN3_PUBLIC},
      {"receive", TTCN3_RECEIVE},
      {"out", TTCN3_OUT},
      {"recursive", TTCN3_RECURSIVE},
      {""},
      {"repeat", TTCN3_REPEAT},
      {"control", TTCN3_CONTROL},
      {"superset", TTCN3_SUPERSET},
      {"or4b", TTCN3_OR4B},
      {""},
      {"record", TTCN3_RECORD},
      {"altstep", TTCN3_ALTSTEP},
      {""}, {""}, {""}, {""},
      {"extends", TTCN3_EXTENDS},
      {"override", TTCN3_OVERRIDE},
      {"else", TTCN3_ELSE},
      {""}, {""},
      {"default", TTCN3_DEFAULT},
      {"testcase", TTCN3_TESTCASE},
      {""}, {""}, {""},
      {"execute", TTCN3_EXECUTE},
      {"optional", TTCN3_OPTIONAL},
      {"signature", TTCN3_SIGNATURE},
      {"mixed", TTCN3_MIXED},
      {""},
      {"on", TTCN3_ON},
      {"not", TTCN3_NOT},
      {"self", TTCN3_SELF},
      {""},
      {"system", TTCN3_SYSTEM},
      {"do", TTCN3_DO},
      {"external", TTCN3_EXTERNAL},
      {""},
      {"not4b", TTCN3_NOT4B},
      {""},
      {"noblock", TTCN3_NOBLOCK},
      {""},
      {"procedure", TTCN3_PROCEDURE},
      {"false", TTCN3_FALSE},
      {""}, {""}, {""},
      {"extension", TTCN3_EXTENSION},
      {""}, {""},
      {"running", TTCN3_RUNNING},
      {""},
      {"component", TTCN3_COMPONENT},
      {"complement", TTCN3_COMPLEMENT},
      {""}, {""}, {""}, {""},
      {"label", TTCN3_LABEL},
      {""},
      {"display", TTCN3_DISPLAY},
      {""},
      {"port", TTCN3_PORT},
      {"value", TTCN3_VALUE},
      {""},
      {"anytype", TTCN3_ANYTYPE},
      {""},
      {"none", TTCN3_NONE},
      {"interleave", TTCN3_INTERLEAVE},
      {"except", TTCN3_EXCEPT},
      {""},
      {"language", TTCN3_LANGUAGE},
      {"null", TTCN3_NULL},
      {""},
      {"encode", TTCN3_ENCODE},
      {"of", TTCN3_OF},
      {"mtc", TTCN3_MTC},
      {"bitstring", TTCN3_BITSTRING},
      {""}, {""}, {""},
      {"function", TTCN3_FUNCTION},
      {"type", TTCN3_TYPE},
      {"clear", TTCN3_CLEAR},
      {""},
      {"in", TTCN3_IN},
      {""}, {""}, {""},
      {"octetstring", TTCN3_OCTETSTRING},
      {""}, {""},
      {"true", TTCN3_TRUE},
      {"raise", TTCN3_RAISE},
      {"sender", TTCN3_SENDER},
      {"private", TTCN3_PRIVATE},
      {"map", TTCN3_MAP},
      {"stop", TTCN3_STOP},
      {"alive", TTCN3_ALIVE},
      {"permutation", TTCN3_PERMUTATION},
      {""}, {""},
      {"exception", TTCN3_EXCEPTION},
      {""}, {""},
      {"to", TTCN3_TO},
      {""},
      {"halt", TTCN3_HALT},
      {"enumerated", TTCN3_ENUMERATED},
      {""},
      {"timeout", TTCN3_TIMEOUT},
      {""},
      {"modulepar", TTCN3_MODULEPAR},
      {"float", TTCN3_FLOAT},
      {""}, {""},
      {"template", TTCN3_TEMPLATE},
      {""},
      {"reply", TTCN3_REPLY},
      {""},
      {"boolean", TTCN3_BOOLEAN},
      {""}, {""},
      {"getverdict", TTCN3_GETVERDICT},
      {"import", TTCN3_IMPORT},
      {"or", TTCN3_OR},
      {"rem", TTCN3_REM},
      {"ifpresent", TTCN3_IFPRESENT},
      {"start", TTCN3_START},
      {""},
      {"if", TTCN3_IF},
      {""}, {""},
      {"catch", TTCN3_CATCH},
      {"nowait", TTCN3_NOWAIT},
      {"valueof", TTCN3_VALUEOF},
      {""}, {""},
      {"while", TTCN3_WHILE},
      {""},
      {"getcall", TTCN3_GETCALL},
      {""},
      {"read", TTCN3_READ},
      {"deactivate", TTCN3_DEACTIVATE},
      {""}, {""}, {""}, {""},
      {"match", TTCN3_MATCH},
      {""}, {""}, {""},
      {"omit", TTCN3_OMIT},
      {"inout", TTCN3_INOUT},
      {""}, {""}, {""}, {""},
      {"param", TTCN3_PARAM},
      {""}, {""}, {""},
      {"with", TTCN3_WITH},
      {""}, {""},
      {"variant", TTCN3_VARIANT},
      {""}, {""},
      {"unmap", TTCN3_UNMAP},
      {"inconc", TTCN3_INCONC},
      {""},
      {"any", TTCN3_ANY},
      {""}, {""},
      {"verdicttype", TTCN3_VERDICTTYPE},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {"universal", TTCN3_UNIVERSAL},
      {"xor4b", TTCN3_XOR4B},
      {"friend", TTCN3_FRIEND},
      {"integer", TTCN3_INTEGER},
      {""},
      {"fail", TTCN3_FAIL},
      {"union", TTCN3_UNION},
      {""}, {""},
      {"log", TTCN3_LOG},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
      {"from", TTCN3_FROM},
      {""}, {""}, {""}, {""},
      {"goto", TTCN3_GOTO},
      {""}, {""}, {""}, {""},
      {"hexstring", TTCN3_HEXSTRING},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
      {"charstring", TTCN3_CHARSTRING},
      {""}, {""}, {""}, {""},
      {"timer", TTCN3_TIMER},
      {""}, {""},
      {"getreply", TTCN3_GETREPLY},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {"length", TTCN3_LENGTH},
      {""}, {""}, {""}, {""}, {""}, {""},
      {"infinity", TTCN3_INFINITY},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
      {"error", TTCN3_ERROR},
      {""}, {""},
      {"for", TTCN3_FOR},
      {"char", TTCN3_CHAR},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
      {"group", TTCN3_GROUP},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {"var", TTCN3_VAR},
      {""}, {""}, {""},
      {"trigger", TTCN3_TRIGGER},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
      {"xor", TTCN3_XOR}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = ttcn3_hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}

int
ttcn3_reserved_word(const char *str, int len)
{
	struct keyword *keyword;

	keyword = ttcn3_lookup(str, len);
	return (keyword && IS_RESERVED_WORD(keyword->token)) ? keyword->token : 0;
}
