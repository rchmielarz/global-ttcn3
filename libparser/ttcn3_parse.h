/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_TTCN3_TTCN3_PARSE_H_INCLUDED
# define YY_TTCN3_TTCN3_PARSE_H_INCLUDED
/* Debug traces.  */
#ifndef TTCN3_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define TTCN3_DEBUG 1
#  else
#   define TTCN3_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define TTCN3_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined TTCN3_DEBUG */
#if TTCN3_DEBUG
extern int ttcn3_debug;
#endif

/* Token type.  */
#ifndef TTCN3_TOKENTYPE
# define TTCN3_TOKENTYPE
  enum ttcn3_tokentype
  {
    TOKEN_IDENTIFIER = 258,
    TOKEN_NUMBER = 259,
    TOKEN_STRING = 260,
    TTCN3_ACTION_KEYWORD = 261,
    TTCN3_ACTIVATE_KEYWORD = 262,
    TTCN3_ADDRESS_KEYWORD = 263,
    TTCN3_ALIVE_KEYWORD = 264,
    TTCN3_ALL_KEYWORD = 265,
    TTCN3_ALT_KEYWORD = 266,
    TTCN3_ALTSTEP_KEYWORD = 267,
    TTCN3_AND_KEYWORD = 268,
    TTCN3_AND4B_KEYWORD = 269,
    TTCN3_ANY_KEYWORD = 270,
    TTCN3_ANYTYPE_KEYWORD = 271,
    TTCN3_BITSTRING_KEYWORD = 272,
    TTCN3_BOOLEAN_KEYWORD = 273,
    TTCN3_BREAK_KEYWORD = 274,
    TTCN3_CASE_KEYWORD = 275,
    TTCN3_CALL_KEYWORD = 276,
    TTCN3_CATCH_KEYWORD = 277,
    TTCN3_CHAR_KEYWORD = 278,
    TTCN3_CHARSTRING_KEYWORD = 279,
    TTCN3_CHECK_KEYWORD = 280,
    TTCN3_CLEAR_KEYWORD = 281,
    TTCN3_COMPLEMENT_KEYWORD = 282,
    TTCN3_COMPONENT_KEYWORD = 283,
    TTCN3_CONNECT_KEYWORD = 284,
    TTCN3_CONST_KEYWORD = 285,
    TTCN3_CONTINUE_KEYWORD = 286,
    TTCN3_CONTROL_KEYWORD = 287,
    TTCN3_CREATE_KEYWORD = 288,
    TTCN3_DEACTIVATE_KEYWORD = 289,
    TTCN3_DEFAULT_KEYWORD = 290,
    TTCN3_DISCONNECT_KEYWORD = 291,
    TTCN3_DISPLAY_KEYWORD = 292,
    TTCN3_DO_KEYWORD = 293,
    TTCN3_DONE_KEYWORD = 294,
    TTCN3_ELSE_KEYWORD = 295,
    TTCN3_ENCODE_KEYWORD = 296,
    TTCN3_ENUMERATED_KEYWORD = 297,
    TTCN3_ERROR_KEYWORD = 298,
    TTCN3_EXCEPT_KEYWORD = 299,
    TTCN3_EXCEPTION_KEYWORD = 300,
    TTCN3_EXECUTE_KEYWORD = 301,
    TTCN3_EXTENDS_KEYWORD = 302,
    TTCN3_EXTENSION_KEYWORD = 303,
    TTCN3_EXTERNAL_KEYWORD = 304,
    TTCN3_FAIL_KEYWORD = 305,
    TTCN3_FALSE_KEYWORD = 306,
    TTCN3_FLOAT_KEYWORD = 307,
    TTCN3_FOR_KEYWORD = 308,
    TTCN3_FRIEND_KEYWORD = 309,
    TTCN3_FROM_KEYWORD = 310,
    TTCN3_FUNCTION_KEYWORD = 311,
    TTCN3_GETVERDICT_KEYWORD = 312,
    TTCN3_GETCALL_KEYWORD = 313,
    TTCN3_GETREPLY_KEYWORD = 314,
    TTCN3_GOTO_KEYWORD = 315,
    TTCN3_GROUP_KEYWORD = 316,
    TTCN3_HALT_KEYWORD = 317,
    TTCN3_HEXSTRING_KEYWORD = 318,
    TTCN3_IF_KEYWORD = 319,
    TTCN3_IFPRESENT_KEYWORD = 320,
    TTCN3_IMPORT_KEYWORD = 321,
    TTCN3_IN_KEYWORD = 322,
    TTCN3_INCONC_KEYWORD = 323,
    TTCN3_INFINITY_KEYWORD = 324,
    TTCN3_INOUT_KEYWORD = 325,
    TTCN3_INTEGER_KEYWORD = 326,
    TTCN3_INTERLEAVE_KEYWORD = 327,
    TTCN3_KILL_KEYWORD = 328,
    TTCN3_KILLED_KEYWORD = 329,
    TTCN3_LABEL_KEYWORD = 330,
    TTCN3_LANGUAGE_KEYWORD = 331,
    TTCN3_LENGTH_KEYWORD = 332,
    TTCN3_LOG_KEYWORD = 333,
    TTCN3_MAP_KEYWORD = 334,
    TTCN3_MATCH_KEYWORD = 335,
    TTCN3_MESSAGE_KEYWORD = 336,
    TTCN3_MIXED_KEYWORD = 337,
    TTCN3_MOD_KEYWORD = 338,
    TTCN3_MODIFIES_KEYWORD = 339,
    TTCN3_MODULE_KEYWORD = 340,
    TTCN3_MODULEPAR_KEYWORD = 341,
    TTCN3_MTC_KEYWORD = 342,
    TTCN3_NOBLOCK_KEYWORD = 343,
    TTCN3_NONE_KEYWORD = 344,
    TTCN3_NOT_KEYWORD = 345,
    TTCN3_NOT4B_KEYWORD = 346,
    TTCN3_NOWAIT_KEYWORD = 347,
    TTCN3_NULL_KEYWORD = 348,
    TTCN3_OCTETSTRING_KEYWORD = 349,
    TTCN3_OF_KEYWORD = 350,
    TTCN3_OMIT_KEYWORD = 351,
    TTCN3_ON_KEYWORD = 352,
    TTCN3_OPTIONAL_KEYWORD = 353,
    TTCN3_OR_KEYWORD = 354,
    TTCN3_OR4B_KEYWORD = 355,
    TTCN3_OUT_KEYWORD = 356,
    TTCN3_OVERRIDE_KEYWORD = 357,
    TTCN3_PARAM_KEYWORD = 358,
    TTCN3_PASS_KEYWORD = 359,
    TTCN3_PATTERN_KEYWORD = 360,
    TTCN3_PERMUTATION_KEYWORD = 361,
    TTCN3_PORT_KEYWORD = 362,
    TTCN3_PRESENT_KEYWORD = 363,
    TTCN3_PRIVATE_KEYWORD = 364,
    TTCN3_PROCEDURE_KEYWORD = 365,
    TTCN3_PUBLIC_KEYWORD = 366,
    TTCN3_RAISE_KEYWORD = 367,
    TTCN3_READ_KEYWORD = 368,
    TTCN3_RECEIVE_KEYWORD = 369,
    TTCN3_RECORD_KEYWORD = 370,
    TTCN3_RECURSIVE_KEYWORD = 371,
    TTCN3_REM_KEYWORD = 372,
    TTCN3_REPEAT_KEYWORD = 373,
    TTCN3_REPLY_KEYWORD = 374,
    TTCN3_RETURN_KEYWORD = 375,
    TTCN3_RUNNING_KEYWORD = 376,
    TTCN3_RUNS_KEYWORD = 377,
    TTCN3_SELECT_KEYWORD = 378,
    TTCN3_SELF_KEYWORD = 379,
    TTCN3_SEND_KEYWORD = 380,
    TTCN3_SENDER_KEYWORD = 381,
    TTCN3_SET_KEYWORD = 382,
    TTCN3_SETVERDICT_KEYWORD = 383,
    TTCN3_SIGNATURE_KEYWORD = 384,
    TTCN3_START_KEYWORD = 385,
    TTCN3_STOP_KEYWORD = 386,
    TTCN3_SUBSET_KEYWORD = 387,
    TTCN3_SUPERSET_KEYWORD = 388,
    TTCN3_SYSTEM_KEYWORD = 389,
    TTCN3_TEMPLATE_KEYWORD = 390,
    TTCN3_TESTCASE_KEYWORD = 391,
    TTCN3_TIMEOUT_KEYWORD = 392,
    TTCN3_TIMER_KEYWORD = 393,
    TTCN3_TO_KEYWORD = 394,
    TTCN3_TRIGGER_KEYWORD = 395,
    TTCN3_TRUE_KEYWORD = 396,
    TTCN3_TYPE_KEYWORD = 397,
    TTCN3_UNION_KEYWORD = 398,
    TTCN3_UNIVERSAL_KEYWORD = 399,
    TTCN3_UNMAP_KEYWORD = 400,
    TTCN3_VALUE_KEYWORD = 401,
    TTCN3_VALUEOF_KEYWORD = 402,
    TTCN3_VAR_KEYWORD = 403,
    TTCN3_VARIANT_KEYWORD = 404,
    TTCN3_VERDICTTYPE_KEYWORD = 405,
    TTCN3_WHILE_KEYWORD = 406,
    TTCN3_WITH_KEYWORD = 407,
    TTCN3_XOR_KEYWORD = 408,
    TTCN3_XOR4B_KEYWORD = 409
  };
#endif

/* Value type.  */
#if ! defined TTCN3_STYPE && ! defined TTCN3_STYPE_IS_DECLARED
typedef int TTCN3_STYPE;
# define TTCN3_STYPE_IS_TRIVIAL 1
# define TTCN3_STYPE_IS_DECLARED 1
#endif


extern TTCN3_STYPE ttcn3_lval;

int ttcn3_parse (const struct parser_param *param);

#endif /* !YY_TTCN3_TTCN3_PARSE_H_INCLUDED  */
