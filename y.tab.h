#define WORD 257
#define NOTOKEN 258
#define GREAT 259
#define NEWLINE 260
#define GREATER 261
#define PIPE 262
#define AND 263
#define SMALL 264
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union	{
		char   *string_val;
	} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
