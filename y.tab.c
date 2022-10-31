/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 18 "shell.y"
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
#line 23 "shell.y"
extern "C" 
{
	int yylex();
	void yyerror (char const *s);
}
#define yylex yylex
#include <stdio.h>
#include "command.h"
#line 41 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define WORD 257
#define NOTOKEN 258
#define GREAT 259
#define NEWLINE 260
#define GREATER 261
#define PIPE 262
#define AND 263
#define SMALL 264
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    3,    3,    3,    3,    4,    7,
    7,    8,    6,    5,    5,    5,    5,    5,    5,    5,
    5,    5,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    3,    3,    1,    2,    2,    2,
    0,    1,    1,    2,    2,    2,    1,    4,    4,    4,
    4,    0,
};
static const YYINT yydefred[] = {                         0,
    0,   13,    7,    0,    0,    2,    4,    0,   11,    8,
    3,    0,    0,   17,    0,    0,    0,    0,    0,    0,
    5,    6,   12,   10,    0,    0,    0,    0,   18,   20,
   19,   21,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,   16,    9,   17,   24,
};
static const YYINT yysindex[] = {                      -244,
 -246,    0,    0,    0, -244,    0,    0, -253,    0,    0,
    0, -231, -230,    0, -229, -245, -228, -234, -233, -252,
    0,    0,    0,    0, -225, -224, -223, -222,    0,    0,
    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,   36,    0,    0, -242,    0,    0,
    0,    0,    0,    0,    0,    0, -259, -241, -238, -237,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,   32,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 37
static const YYINT yytable[] = {                          9,
    9,    9,    9,    9,    9,   12,   27,   13,   28,   14,
   15,    1,    2,   10,   21,    3,   22,   22,   14,   22,
   14,   15,   16,   15,   16,   18,   19,   20,   23,   25,
   26,   29,   30,   31,   32,    1,   11,
};
static const YYINT yycheck[] = {                        259,
  260,  261,  262,  263,  264,  259,  259,  261,  261,  263,
  264,  256,  257,  260,  260,  260,  262,  260,  260,  262,
  262,  260,  260,  262,  262,  257,  257,  257,  257,  264,
  264,  257,  257,  257,  257,    0,    5,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 264
#define YYUNDFTOKEN 275
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"WORD","NOTOKEN","GREAT",
"NEWLINE","GREATER","PIPE","AND","SMALL",0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : goal",
"goal : commands",
"commands : command",
"commands : commands command",
"command : simple_command",
"simple_command : command_and_args iomodifier_opt NEWLINE",
"simple_command : command_and_args iomodifier_opt PIPE",
"simple_command : NEWLINE",
"simple_command : error NEWLINE",
"command_and_args : command_word arg_list",
"arg_list : arg_list argument",
"arg_list :",
"argument : WORD",
"command_word : WORD",
"iomodifier_opt : GREAT WORD",
"iomodifier_opt : GREATER WORD",
"iomodifier_opt : SMALL WORD",
"iomodifier_opt : AND",
"iomodifier_opt : GREAT WORD SMALL WORD",
"iomodifier_opt : SMALL WORD GREAT WORD",
"iomodifier_opt : GREATER WORD SMALL WORD",
"iomodifier_opt : SMALL WORD GREATER WORD",
"iomodifier_opt :",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 140 "shell.y"

void
yyerror(const char * s)
{
	fprintf(stderr,"%s", s);
}

#if 0
main()
{
	yyparse();
}
#endif
#line 225 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 5:
#line 48 "shell.y"
	{
		printf("   Yacc: Execute command\n");
		Command::_currentCommand.execute();
	}
break;
case 6:
#line 52 "shell.y"
	{
		printf("   Yacc: Execute piped command\n");
		Command::_currentCommand.execute();
	}
break;
case 8:
#line 57 "shell.y"
	{ yyerrok; }
break;
case 9:
#line 61 "shell.y"
	{
		Command::_currentCommand.
			insertSimpleCommand( Command::_currentSimpleCommand );
	}
break;
case 12:
#line 73 "shell.y"
	{
               printf("   Yacc: insert argument \"%s\"\n", yystack.l_mark[0].string_val);

	       Command::_currentSimpleCommand->insertArgument( yystack.l_mark[0].string_val );\
	}
break;
case 13:
#line 81 "shell.y"
	{
               printf("   Yacc: insert command \"%s\"\n", yystack.l_mark[0].string_val);
	       
	       Command::_currentSimpleCommand = new SimpleCommand();
	       Command::_currentSimpleCommand->insertArgument( yystack.l_mark[0].string_val );
	}
break;
case 14:
#line 90 "shell.y"
	{
		printf("   Yacc: insert output \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._outFile = yystack.l_mark[0].string_val;
		Command::_currentCommand._append = 0;
	}
break;
case 15:
#line 95 "shell.y"
	{
		printf("   Yacc: insert output \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._outFile = yystack.l_mark[0].string_val;
		Command::_currentCommand._append = 1;
	}
break;
case 16:
#line 100 "shell.y"
	{
		printf("   Yacc: insert input \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._inputFile = yystack.l_mark[0].string_val;
	}
break;
case 17:
#line 104 "shell.y"
	{
		printf ("	Yacc: insert background operation\n");
		Command::_currentCommand._background = 1;
	}
break;
case 18:
#line 108 "shell.y"
	{
		printf("   Yacc: insert output \"%s\"\n", yystack.l_mark[-2].string_val);
		Command::_currentCommand._outFile = yystack.l_mark[-2].string_val;
		printf("   Yacc: insert input \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._inputFile = yystack.l_mark[0].string_val;
		Command::_currentCommand._append = 0;
	}
break;
case 19:
#line 115 "shell.y"
	{
		printf("   Yacc: insert output \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._outFile = yystack.l_mark[0].string_val;
		printf("   Yacc: insert input \"%s\"\n", yystack.l_mark[-2].string_val);
		Command::_currentCommand._inputFile = yystack.l_mark[-2].string_val;
		Command::_currentCommand._append = 0;
	}
break;
case 20:
#line 122 "shell.y"
	{
		printf("   Yacc: insert output \"%s\"\n", yystack.l_mark[-2].string_val);
		Command::_currentCommand._outFile = yystack.l_mark[-2].string_val;
		printf("   Yacc: insert input \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._inputFile = yystack.l_mark[0].string_val;
		Command::_currentCommand._append = 1;
	}
break;
case 21:
#line 129 "shell.y"
	{
		printf("   Yacc: insert output \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._outFile = yystack.l_mark[0].string_val;
		printf("   Yacc: insert input \"%s\"\n", yystack.l_mark[-2].string_val);
		Command::_currentCommand._inputFile = yystack.l_mark[-2].string_val;
		Command::_currentCommand._append = 1;
	}
break;
#line 539 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
