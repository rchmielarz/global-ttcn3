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
#include <assert.h>
#include <ctype.h>
#ifdef HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif

#include "internal.h"
#include "die.h"
#include "linetable.h"
#include "strbuf.h"

#define YYLTYPE		int
#ifndef YYSTYPE
#define YYSTYPE char*
#endif
#define YYLLOC_DEFAULT(Current, Rhs, N)	((Current) = (Rhs)[1])

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

static void yyerror(const struct parser_param *, const char *);
extern int linenum;
extern int column;
%}

%token TOKEN_IDENTIFIER
%token TOKEN_NUMBER
%token TOKEN_STRING

%token TTCN3_ACTION_KEYWORD "action"
%token TTCN3_ACTIVATE_KEYWORD "activate"
%token TTCN3_ADDRESS_KEYWORD "address"
%token TTCN3_ALIVE_KEYWORD "alive"
%token TTCN3_ALL_KEYWORD "all"
%token TTCN3_ALT_KEYWORD "alt"
%token TTCN3_ALTSTEP_KEYWORD "altstep"
%token TTCN3_AND_KEYWORD "and"
%token TTCN3_AND4B_KEYWORD "and4b"
%token TTCN3_ANY_KEYWORD "any"
%token TTCN3_ANYTYPE_KEYWORD "anytype"
%token TTCN3_BITSTRING_KEYWORD "bitstring"
%token TTCN3_BOOLEAN_KEYWORD "boolean"
%token TTCN3_BREAK_KEYWORD "break"
%token TTCN3_CASE_KEYWORD "case"
%token TTCN3_CALL_KEYWORD "call"
%token TTCN3_CATCH_KEYWORD "catch"
%token TTCN3_CHAR_KEYWORD "char"
%token TTCN3_CHARSTRING_KEYWORD "charstring"
%token TTCN3_CHECK_KEYWORD "check"
%token TTCN3_CLEAR_KEYWORD "clear"
%token TTCN3_COMPLEMENT_KEYWORD "complement"
%token TTCN3_COMPONENT_KEYWORD "component"
%token TTCN3_CONNECT_KEYWORD "connect"
%token TTCN3_CONST_KEYWORD "const"
%token TTCN3_CONTINUE_KEYWORD "continue"
%token TTCN3_CONTROL_KEYWORD "control"
%token TTCN3_CREATE_KEYWORD "create"
%token TTCN3_DEACTIVATE_KEYWORD "deactivate"
%token TTCN3_DEFAULT_KEYWORD "default"
%token TTCN3_DISCONNECT_KEYWORD "disconnect"
%token TTCN3_DISPLAY_KEYWORD "display"
%token TTCN3_DO_KEYWORD "do"
%token TTCN3_DONE_KEYWORD "done"
%token TTCN3_ELSE_KEYWORD "else"
%token TTCN3_ENCODE_KEYWORD "encode"
%token TTCN3_ENUMERATED_KEYWORD "enumerated"
%token TTCN3_ERROR_KEYWORD "error"
%token TTCN3_EXCEPT_KEYWORD "except"
%token TTCN3_EXCEPTION_KEYWORD "exception"
%token TTCN3_EXECUTE_KEYWORD "execute"
%token TTCN3_EXTENDS_KEYWORD "extends"
%token TTCN3_EXTENSION_KEYWORD "extension"
%token TTCN3_EXTERNAL_KEYWORD "external"
%token TTCN3_FAIL_KEYWORD "fail"
%token TTCN3_FALSE_KEYWORD "false"
%token TTCN3_FLOAT_KEYWORD "float"
%token TTCN3_FOR_KEYWORD "for"
%token TTCN3_FRIEND_KEYWORD "friend"
%token TTCN3_FROM_KEYWORD "from"
%token TTCN3_FUNCTION_KEYWORD "function"
%token TTCN3_GETVERDICT_KEYWORD "getverdict"
%token TTCN3_GETCALL_KEYWORD "getcall"
%token TTCN3_GETREPLY_KEYWORD "getreply"
%token TTCN3_GOTO_KEYWORD "goto"
%token TTCN3_GROUP_KEYWORD "group"
%token TTCN3_HALT_KEYWORD "halt"
%token TTCN3_HEXSTRING_KEYWORD "hexstring"
%token TTCN3_IF_KEYWORD "if"
%token TTCN3_IFPRESENT_KEYWORD "ifpresent"
%token TTCN3_IMPORT_KEYWORD "import"
%token TTCN3_IN_KEYWORD "in"
%token TTCN3_INCONC_KEYWORD "inconc"
%token TTCN3_INFINITY_KEYWORD "infinity"
%token TTCN3_INOUT_KEYWORD "inout"
%token TTCN3_INTEGER_KEYWORD "integer"
%token TTCN3_INTERLEAVE_KEYWORD "interleave"
%token TTCN3_KILL_KEYWORD "kill"
%token TTCN3_KILLED_KEYWORD "killed"
%token TTCN3_LABEL_KEYWORD "label"
%token TTCN3_LANGUAGE_KEYWORD "language"
%token TTCN3_LENGTH_KEYWORD "length"
%token TTCN3_LOG_KEYWORD "log"
%token TTCN3_MAP_KEYWORD "map"
%token TTCN3_MATCH_KEYWORD "match"
%token TTCN3_MESSAGE_KEYWORD "message"
%token TTCN3_MIXED_KEYWORD "mixed"
%token TTCN3_MOD_KEYWORD "mod"
%token TTCN3_MODIFIES_KEYWORD "modifies"
%token TTCN3_MODULE_KEYWORD "module"
%token TTCN3_MODULEPAR_KEYWORD "modulepar"
%token TTCN3_MTC_KEYWORD "mtc"
%token TTCN3_NOBLOCK_KEYWORD "noblock"
%token TTCN3_NONE_KEYWORD "none"
%token TTCN3_NOT_KEYWORD "not"
%token TTCN3_NOT4B_KEYWORD "not4b"
%token TTCN3_NOWAIT_KEYWORD "nowait"
%token TTCN3_NULL_KEYWORD "null"
%token TTCN3_OCTETSTRING_KEYWORD "octetstring"
%token TTCN3_OF_KEYWORD "of"
%token TTCN3_OMIT_KEYWORD "omit"
%token TTCN3_ON_KEYWORD "on"
%token TTCN3_OPTIONAL_KEYWORD "optional"
%token TTCN3_OR_KEYWORD "or"
%token TTCN3_OR4B_KEYWORD "or4b"
%token TTCN3_OUT_KEYWORD "out"
%token TTCN3_OVERRIDE_KEYWORD "override"
%token TTCN3_PARAM_KEYWORD "param"
%token TTCN3_PASS_KEYWORD "pass"
%token TTCN3_PATTERN_KEYWORD "pattern"
%token TTCN3_PERMUTATION_KEYWORD "permutation"
%token TTCN3_PORT_KEYWORD "port"
%token TTCN3_PRESENT_KEYWORD "present"
%token TTCN3_PRIVATE_KEYWORD "private"
%token TTCN3_PROCEDURE_KEYWORD "procedure"
%token TTCN3_PUBLIC_KEYWORD "public"
%token TTCN3_RAISE_KEYWORD "raise"
%token TTCN3_READ_KEYWORD "read"
%token TTCN3_RECEIVE_KEYWORD "receive"
%token TTCN3_RECORD_KEYWORD "record"
%token TTCN3_RECURSIVE_KEYWORD "recursive"
%token TTCN3_REM_KEYWORD "rem"
%token TTCN3_REPEAT_KEYWORD "repeat"
%token TTCN3_REPLY_KEYWORD "reply"
%token TTCN3_RETURN_KEYWORD "return"
%token TTCN3_RUNNING_KEYWORD "running"
%token TTCN3_RUNS_KEYWORD "runs"
%token TTCN3_SELECT_KEYWORD "select"
%token TTCN3_SELF_KEYWORD "self"
%token TTCN3_SEND_KEYWORD "send"
%token TTCN3_SENDER_KEYWORD "sender"
%token TTCN3_SET_KEYWORD "set"
%token TTCN3_SETVERDICT_KEYWORD "setverdict"
%token TTCN3_SIGNATURE_KEYWORD "signature"
%token TTCN3_START_KEYWORD "start"
%token TTCN3_STOP_KEYWORD "stop"
%token TTCN3_SUBSET_KEYWORD "subset"
%token TTCN3_SUPERSET_KEYWORD "superset"
%token TTCN3_SYSTEM_KEYWORD "system"
%token TTCN3_TEMPLATE_KEYWORD "template"
%token TTCN3_TESTCASE_KEYWORD "testcase"
%token TTCN3_TIMEOUT_KEYWORD "timeout"
%token TTCN3_TIMER_KEYWORD "timer"
%token TTCN3_TO_KEYWORD "to"
%token TTCN3_TRIGGER_KEYWORD "trigger"
%token TTCN3_TRUE_KEYWORD "true"
%token TTCN3_TYPE_KEYWORD "type"
%token TTCN3_UNION_KEYWORD "union"
%token TTCN3_UNIVERSAL_KEYWORD "universal"
%token TTCN3_UNMAP_KEYWORD "unmap"
%token TTCN3_VALUE_KEYWORD "value"
%token TTCN3_VALUEOF_KEYWORD "valueof"
%token TTCN3_VAR_KEYWORD "var"
%token TTCN3_VARIANT_KEYWORD "variant"
%token TTCN3_VERDICTTYPE_KEYWORD "verdicttype"
%token TTCN3_WHILE_KEYWORD "while"
%token TTCN3_WITH_KEYWORD "with"
%token TTCN3_XOR_KEYWORD "xor"
%token TTCN3_XOR4B_KEYWORD "xor4b"

%start input
%define api.prefix {ttcn3_}

%parse-param { const struct parser_param *param }
%lex-param { const struct parser_param *param }

%%

input:
  %empty
  | input module;

module:
  TTCN3_MODULE_KEYWORD TOKEN_IDENTIFIER
  {
    PUT(PARSER_DEF, $2, linenum);
  }
  error /* language spec does not contain any identifiers */
  '{' module_definitions_list.optional '}' semicolon.optional;
  ;

module_definitions_list.optional:
  %empty
  | module_definitions_list.optional module_definition.optional semicolon.optional;

module_definition.optional:
  %empty
  | error /* visibility does not contain any identifiers */ type_def
  | error function_def;

type_def:
  TTCN3_TYPE_KEYWORD typedef_body;

typedef_body:
  structured_typedef;

structured_typedef:
  record_def;

record_def:
  TTCN3_RECORD_KEYWORD struct_def_body;

struct_def_body:
  TOKEN_IDENTIFIER
  {
    PUT(PARSER_DEF, $1, linenum);
  } '{' struct_field_defs.optional '}'
  | TTCN3_ADDRESS_KEYWORD '{' struct_field_defs.optional '}';

struct_field_defs.optional:
  %empty
  | struct_field_def struct_field_def.many.optional;

struct_field_def.many.optional:
 %empty
 | struct_field_def.many.optional ',' struct_field_def;

struct_field_def:
 type TOKEN_IDENTIFIER
 {
    PUT(PARSER_DEF, $2, linenum);
 };

semicolon.optional:
  %empty
  | ';';

type:
  TTCN3_BITSTRING_KEYWORD
  | TTCN3_BOOLEAN_KEYWORD
  | TTCN3_CHARSTRING_KEYWORD
  | TTCN3_UNIVERSAL_KEYWORD TTCN3_CHARSTRING_KEYWORD
  | TTCN3_INTEGER_KEYWORD
  | TTCN3_OCTETSTRING_KEYWORD
  | TTCN3_HEXSTRING_KEYWORD
  | TTCN3_VERDICTTYPE_KEYWORD
  | TTCN3_FLOAT_KEYWORD
  | TTCN3_ADDRESS_KEYWORD
  | TTCN3_DEFAULT_KEYWORD
  | TTCN3_ANYTYPE_KEYWORD;

function_def:
  TTCN3_FUNCTION_KEYWORD TOKEN_IDENTIFIER
  {
    PUT(PARSER_DEF, $2, linenum);
  } error;

%%

void
ttcn3(const struct parser_param *param)
{
	if (linetable_open(param->file) == -1)
		die("'%s' cannot open.", param->file);
	ttcn3_initscan();
	ttcn3_parse(param);
	linetable_close();
}

static void
yyerror(const struct parser_param *param, const char *s)
{

}
