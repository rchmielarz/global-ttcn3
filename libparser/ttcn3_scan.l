%{
/*
 * This file is part of GNU GLOBAL.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif

#define YYLTYPE		int

#include "internal.h"
#include "ttcn3_parse.h"
#include "ttcn3_res.h"
#include "die.h"
#include "linetable.h"
#include "strbuf.h"

#ifndef TTCN3_STYPE
#define TTCN3_STYPE char*
#endif

static int last_directive;
int linenum;
int column;

int get_token(int reserved_word_id);

#define lex_symbol_generation_rule(x) ttcn3_ ## x
#define LEXLEX lex_symbol_generation_rule(lex)
#define LEXTEXT lex_symbol_generation_rule(text)
#define LEXLENG lex_symbol_generation_rule(leng)
#define LEXLINENO lex_symbol_generation_rule(lineno)
#define LEXRESTART lex_symbol_generation_rule(restart)
#define LEXLVAL lex_symbol_generation_rule(lval)
#define LEXLLOC lex_symbol_generation_rule(lloc)

#define YY_DECL	int LEXLEX(const struct parser_param *param)

#define YY_INPUT(buf, result, max_size) do {				\
	if ((result = linetable_read(buf, max_size)) == -1)		\
		result = YY_NULL;					\
} while (0)

#undef PUT
#define PUT(type, tag, lno) do {					\
	const char *line_image = linetable_get(lno, NULL);		\
	char *nl = strchr(line_image, '\n');				\
	if (nl != NULL)							\
		*nl = '\0';						\
	param->put(type, tag, lno, param->file, line_image, param->arg);\
	if (nl != NULL)							\
		*nl = '\n';						\
} while (0)

#define YY_USER_ACTION                                                   \
  start_line = prev_linenum; start_column = column;                   \
  if (linenum == prev_linenum) column += yyleng;                     \
  else {                                                                 \
    for (column = 1; yytext[yyleng - column] != '\n'; ++column) {} \
    prev_linenum = linenum;                                            \
  }

%}

N		[0-9]+
L		{N}L?
D1		{N}\.{N}([Ee][+-]?{N})?
D2		\.{N}([Ee][+-]?{N})?
NUMBER		-?({L}|{D1}|{D2})
ALPHA		[a-zA-Z\x80-\xff]
ALPHANUM	[a-zA-Z_\x80-\xff0-9]
IDENTIFIER	{ALPHA}{ALPHANUM}*
COMMENT		("/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*"*"+"/")|("//".*)

%option 8bit noyywrap never-interactive prefix="ttcn3_"
%x BLOCK_COMMENT LINE_COMMENT STRING
%%
   int start_line, start_column;
   int prev_linenum = linenum;

 /* Count line numbers */
\n            { linenum++; }

 /* Ignore spaces */
[ \f\t\v]+

 /* Ignore block comments */
\/\*                { BEGIN(BLOCK_COMMENT); }
<BLOCK_COMMENT>\*\/ { BEGIN(INITIAL); }
<BLOCK_COMMENT>\n   { linenum++; }
<BLOCK_COMMENT>.

 /* Ignore line comment */
\/\/                { BEGIN(LINE_COMMENT); }
<LINE_COMMENT>\n    {
                      linenum++;
		      BEGIN(INITIAL);
                    }
<LINE_COMMENT>.

{IDENTIFIER}  {
		return get_token(ttcn3_reserved_word(LEXTEXT, LEXLENG));
              }
{NUMBER}      {
                return TOKEN_NUMBER;
	      }
\"	      { BEGIN(STRING); }
<STRING>(\\.|[^\"\\\n])+
<STRING>\\\n
<STRING>\n    { ++linenum; }
<STRING>\"    {
                BEGIN(INITIAL);
                return TOKEN_STRING;
              }
.	      {
		return yytext[0];
	      }

%%

void
ttcn3_initscan(void)
{
  linenum = 1;
  column = 1;
  LEXRESTART(NULL);
}

int
get_token(int reserved_word_id)
{
  int token;
  switch(reserved_word_id)
    {
    case TTCN3_ACTION: token = TTCN3_ACTION_KEYWORD; break;
    case TTCN3_ACTIVATE: token = TTCN3_ACTIVATE_KEYWORD; break;
    case TTCN3_ADDRESS: token = TTCN3_ADDRESS_KEYWORD; break;
    case TTCN3_ALIVE: token = TTCN3_ALIVE_KEYWORD; break;
    case TTCN3_ALL: token = TTCN3_ALL_KEYWORD; break;
    case TTCN3_ALT: token = TTCN3_ALT_KEYWORD; break;
    case TTCN3_ALTSTEP: token = TTCN3_ALTSTEP_KEYWORD; break;
    case TTCN3_AND: token = TTCN3_AND_KEYWORD; break;
    case TTCN3_AND4B: token = TTCN3_AND4B_KEYWORD; break;
    case TTCN3_ANY: token = TTCN3_ANY_KEYWORD; break;
    case TTCN3_ANYTYPE: token = TTCN3_ANYTYPE_KEYWORD; break;
    case TTCN3_BITSTRING: token = TTCN3_BITSTRING_KEYWORD; break;
    case TTCN3_BOOLEAN: token = TTCN3_BOOLEAN_KEYWORD; break;
    case TTCN3_BREAK: token = TTCN3_BREAK_KEYWORD; break;
    case TTCN3_CASE: token = TTCN3_CASE_KEYWORD; break;
    case TTCN3_CALL: token = TTCN3_CALL_KEYWORD; break;
    case TTCN3_CATCH: token = TTCN3_CATCH_KEYWORD; break;
    case TTCN3_CHAR: token = TTCN3_CHAR_KEYWORD; break;
    case TTCN3_CHARSTRING: token = TTCN3_CHARSTRING_KEYWORD; break;
    case TTCN3_CHECK: token = TTCN3_CHECK_KEYWORD; break;
    case TTCN3_CLEAR: token = TTCN3_CLEAR_KEYWORD; break;
    case TTCN3_COMPLEMENT: token = TTCN3_COMPLEMENT_KEYWORD; break;
    case TTCN3_COMPONENT: token = TTCN3_COMPONENT_KEYWORD; break;
    case TTCN3_CONNECT: token = TTCN3_CONNECT_KEYWORD; break;
    case TTCN3_CONST: token = TTCN3_CONST_KEYWORD; break;
    case TTCN3_CONTINUE: token = TTCN3_CONTINUE_KEYWORD; break;
    case TTCN3_CONTROL: token = TTCN3_CONTROL_KEYWORD; break;
    case TTCN3_CREATE: token = TTCN3_CREATE_KEYWORD; break;
    case TTCN3_DEACTIVATE: token = TTCN3_DEACTIVATE_KEYWORD; break;
    case TTCN3_DEFAULT: token = TTCN3_DEFAULT_KEYWORD; break;
    case TTCN3_DISCONNECT: token = TTCN3_DISCONNECT_KEYWORD; break;
    case TTCN3_DISPLAY: token = TTCN3_DISPLAY_KEYWORD; break;
    case TTCN3_DO: token = TTCN3_DO_KEYWORD; break;
    case TTCN3_DONE: token = TTCN3_DONE_KEYWORD; break;
    case TTCN3_ELSE: token = TTCN3_ELSE_KEYWORD; break;
    case TTCN3_ENCODE: token = TTCN3_ENCODE_KEYWORD; break;
    case TTCN3_ENUMERATED: token = TTCN3_ENUMERATED_KEYWORD; break;
    case TTCN3_ERROR: token = TTCN3_ERROR_KEYWORD; break;
    case TTCN3_EXCEPT: token = TTCN3_EXCEPT_KEYWORD; break;
    case TTCN3_EXCEPTION: token = TTCN3_EXCEPTION_KEYWORD; break;
    case TTCN3_EXECUTE: token = TTCN3_EXECUTE_KEYWORD; break;
    case TTCN3_EXTENDS: token = TTCN3_EXTENDS_KEYWORD; break;
    case TTCN3_EXTENSION: token = TTCN3_EXTENSION_KEYWORD; break;
    case TTCN3_EXTERNAL: token = TTCN3_EXTERNAL_KEYWORD; break;
    case TTCN3_FAIL: token = TTCN3_FAIL_KEYWORD; break;
    case TTCN3_FALSE: token = TTCN3_FALSE_KEYWORD; break;
    case TTCN3_FLOAT: token = TTCN3_FLOAT_KEYWORD; break;
    case TTCN3_FOR: token = TTCN3_FOR_KEYWORD; break;
    case TTCN3_FRIEND: token = TTCN3_FRIEND_KEYWORD; break;
    case TTCN3_FROM: token = TTCN3_FROM_KEYWORD; break;
    case TTCN3_FUNCTION: token = TTCN3_FUNCTION_KEYWORD; break;
    case TTCN3_GETVERDICT: token = TTCN3_GETVERDICT_KEYWORD; break;
    case TTCN3_GETCALL: token = TTCN3_GETCALL_KEYWORD; break;
    case TTCN3_GETREPLY: token = TTCN3_GETREPLY_KEYWORD; break;
    case TTCN3_GOTO: token = TTCN3_GOTO_KEYWORD; break;
    case TTCN3_GROUP: token = TTCN3_GROUP_KEYWORD; break;
    case TTCN3_HALT: token = TTCN3_HALT_KEYWORD; break;
    case TTCN3_HEXSTRING: token = TTCN3_HEXSTRING_KEYWORD; break;
    case TTCN3_IF: token = TTCN3_IF_KEYWORD; break;
    case TTCN3_IFPRESENT: token = TTCN3_IFPRESENT_KEYWORD; break;
    case TTCN3_IMPORT: token = TTCN3_IMPORT_KEYWORD; break;
    case TTCN3_IN: token = TTCN3_IN_KEYWORD; break;
    case TTCN3_INCONC: token = TTCN3_INCONC_KEYWORD; break;
    case TTCN3_INFINITY: token = TTCN3_INFINITY_KEYWORD; break;
    case TTCN3_INOUT: token = TTCN3_INOUT_KEYWORD; break;
    case TTCN3_INTEGER: token = TTCN3_INTEGER_KEYWORD; break;
    case TTCN3_INTERLEAVE: token = TTCN3_INTERLEAVE_KEYWORD; break;
    case TTCN3_KILL: token = TTCN3_KILL_KEYWORD; break;
    case TTCN3_KILLED: token = TTCN3_KILLED_KEYWORD; break;
    case TTCN3_LABEL: token = TTCN3_LABEL_KEYWORD; break;
    case TTCN3_LANGUAGE: token = TTCN3_LANGUAGE_KEYWORD; break;
    case TTCN3_LENGTH: token = TTCN3_LENGTH_KEYWORD; break;
    case TTCN3_LOG: token = TTCN3_LOG_KEYWORD; break;
    case TTCN3_MAP: token = TTCN3_MAP_KEYWORD; break;
    case TTCN3_MATCH: token = TTCN3_MATCH_KEYWORD; break;
    case TTCN3_MESSAGE: token = TTCN3_MESSAGE_KEYWORD; break;
    case TTCN3_MIXED: token = TTCN3_MIXED_KEYWORD; break;
    case TTCN3_MOD: token = TTCN3_MOD_KEYWORD; break;
    case TTCN3_MODIFIES: token = TTCN3_MODIFIES_KEYWORD; break;
    case TTCN3_MODULE: token = TTCN3_MODULE_KEYWORD; break;
    case TTCN3_MODULEPAR: token = TTCN3_MODULEPAR_KEYWORD; break;
    case TTCN3_MTC: token = TTCN3_MTC_KEYWORD; break;
    case TTCN3_NOBLOCK: token = TTCN3_NOBLOCK_KEYWORD; break;
    case TTCN3_NONE: token = TTCN3_NONE_KEYWORD; break;
    case TTCN3_NOT: token = TTCN3_NOT_KEYWORD; break;
    case TTCN3_NOT4B: token = TTCN3_NOT4B_KEYWORD; break;
    case TTCN3_NOWAIT: token = TTCN3_NOWAIT_KEYWORD; break;
    case TTCN3_NULL: token = TTCN3_NULL_KEYWORD; break;
    case TTCN3_OCTETSTRING: token = TTCN3_OCTETSTRING_KEYWORD; break;
    case TTCN3_OF: token = TTCN3_OF_KEYWORD; break;
    case TTCN3_OMIT: token = TTCN3_OMIT_KEYWORD; break;
    case TTCN3_ON: token = TTCN3_ON_KEYWORD; break;
    case TTCN3_OPTIONAL: token = TTCN3_OPTIONAL_KEYWORD; break;
    case TTCN3_OR: token = TTCN3_OR_KEYWORD; break;
    case TTCN3_OR4B: token = TTCN3_OR4B_KEYWORD; break;
    case TTCN3_OUT: token = TTCN3_OUT_KEYWORD; break;
    case TTCN3_OVERRIDE: token = TTCN3_OVERRIDE_KEYWORD; break;
    case TTCN3_PARAM: token = TTCN3_PARAM_KEYWORD; break;
    case TTCN3_PASS: token = TTCN3_PASS_KEYWORD; break;
    case TTCN3_PATTERN: token = TTCN3_PATTERN_KEYWORD; break;
    case TTCN3_PERMUTATION: token = TTCN3_PERMUTATION_KEYWORD; break;
    case TTCN3_PORT: token = TTCN3_PORT_KEYWORD; break;
    case TTCN3_PRESENT: token = TTCN3_PRESENT_KEYWORD; break;
    case TTCN3_PRIVATE: token = TTCN3_PRIVATE_KEYWORD; break;
    case TTCN3_PROCEDURE: token = TTCN3_PROCEDURE_KEYWORD; break;
    case TTCN3_PUBLIC: token = TTCN3_PUBLIC_KEYWORD; break;
    case TTCN3_RAISE: token = TTCN3_RAISE_KEYWORD; break;
    case TTCN3_READ: token = TTCN3_READ_KEYWORD; break;
    case TTCN3_RECEIVE: token = TTCN3_RECEIVE_KEYWORD; break;
    case TTCN3_RECORD: token = TTCN3_RECORD_KEYWORD; break;
    case TTCN3_RECURSIVE: token = TTCN3_RECURSIVE_KEYWORD; break;
    case TTCN3_REM: token = TTCN3_REM_KEYWORD; break;
    case TTCN3_REPEAT: token = TTCN3_REPEAT_KEYWORD; break;
    case TTCN3_REPLY: token = TTCN3_REPLY_KEYWORD; break;
    case TTCN3_RETURN: token = TTCN3_RETURN_KEYWORD; break;
    case TTCN3_RUNNING: token = TTCN3_RUNNING_KEYWORD; break;
    case TTCN3_RUNS: token = TTCN3_RUNS_KEYWORD; break;
    case TTCN3_SELECT: token = TTCN3_SELECT_KEYWORD; break;
    case TTCN3_SELF: token = TTCN3_SELF_KEYWORD; break;
    case TTCN3_SEND: token = TTCN3_SEND_KEYWORD; break;
    case TTCN3_SENDER: token = TTCN3_SENDER_KEYWORD; break;
    case TTCN3_SET: token = TTCN3_SET_KEYWORD; break;
    case TTCN3_SETVERDICT: token = TTCN3_SETVERDICT_KEYWORD; break;
    case TTCN3_SIGNATURE: token = TTCN3_SIGNATURE_KEYWORD; break;
    case TTCN3_START: token = TTCN3_START_KEYWORD; break;
    case TTCN3_STOP: token = TTCN3_STOP_KEYWORD; break;
    case TTCN3_SUBSET: token = TTCN3_SUBSET_KEYWORD; break;
    case TTCN3_SUPERSET: token = TTCN3_SUPERSET_KEYWORD; break;
    case TTCN3_SYSTEM: token = TTCN3_SYSTEM_KEYWORD; break;
    case TTCN3_TEMPLATE: token = TTCN3_TEMPLATE_KEYWORD; break;
    case TTCN3_TESTCASE: token = TTCN3_TESTCASE_KEYWORD; break;
    case TTCN3_TIMEOUT: token = TTCN3_TIMEOUT_KEYWORD; break;
    case TTCN3_TIMER: token = TTCN3_TIMER_KEYWORD; break;
    case TTCN3_TO: token = TTCN3_TO_KEYWORD; break;
    case TTCN3_TRIGGER: token = TTCN3_TRIGGER_KEYWORD; break;
    case TTCN3_TRUE: token = TTCN3_TRUE_KEYWORD; break;
    case TTCN3_TYPE: token = TTCN3_TYPE_KEYWORD; break;
    case TTCN3_UNION: token = TTCN3_UNION_KEYWORD; break;
    case TTCN3_UNIVERSAL: token = TTCN3_UNIVERSAL_KEYWORD; break;
    case TTCN3_UNMAP: token = TTCN3_UNMAP_KEYWORD; break;
    case TTCN3_VALUE: token = TTCN3_VALUE_KEYWORD; break;
    case TTCN3_VALUEOF: token = TTCN3_VALUEOF_KEYWORD; break;
    case TTCN3_VAR: token = TTCN3_VAR_KEYWORD; break;
    case TTCN3_VARIANT: token = TTCN3_VARIANT_KEYWORD; break;
    case TTCN3_VERDICTTYPE: token = TTCN3_VERDICTTYPE_KEYWORD; break;
    case TTCN3_WHILE: token = TTCN3_WHILE_KEYWORD; break;
    case TTCN3_WITH: token = TTCN3_WITH_KEYWORD; break;
    case TTCN3_XOR: token = TTCN3_XOR_KEYWORD; break;
    case TTCN3_XOR4B: token = TTCN3_XOR4B_KEYWORD; break;
    default:
      token = TOKEN_IDENTIFIER;
      ttcn3_lval = strdup(yytext);
      break;
    }

  return token;
}
