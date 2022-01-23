/* Generated by 2016 ReVoL SYNAX */
/* 24-11-2021 16:36:47 */

#define ST_MAX_RULE_LEN 64 /* Max rule length */

/* Rules */
sttype RULE[52][ST_MAX_RULE_LEN] = {
	/* 0*/{ TOK_EOT },
	/* 1 SYM_M   */{ SYM_DS, SYM_B, TOK_DOT, TOK_EOT },
	/* 2 SYM_DS  */{ TOK_VAR, SYM_DL, SYM_DL_,  TOK_EOT },
	/* 3 SYM_DS  */{ TOK_EOT },
	/* 4 SYM_B   */{ TOK_BEGIN, SYM_SS, TOK_END, TOK_EOT },
	/* 5 SYM_DL  */{ TOK_ID, OUT_ID, SYM_IL, TOK_COLON, SYM_TY, TOK_SEMI, TOK_EOT },
	/* 6 SYM_DL_ */{ SYM_DL, SYM_DL_, TOK_EOT },
	/* 7 SYM_DL_ */{ TOK_EOT },
	/* 8 SYM_IL  */{ TOK_COMMA, TOK_ID, OUT_ID, SYM_IL, TOK_EOT },
	/* 9 SYM_IL  */{ TOK_EOT },
	/*10 SYM_TY  */{ TOK_REAL, OUT_REAL,OUT_VAR,TOK_EOT },
	/*11 SYM_TY  */{ TOK_INTEGER, OUT_INTEGER, OUT_VAR, TOK_EOT },
	/*12 SYM_TY  */{ TOK_STRING, OUT_STRING, OUT_VAR, TOK_EOT },
	/*13 SYM_SS  */{ SYM_S, SYM_SS, TOK_EOT },
	/*14 SYM_SS  */{ TOK_EOT },
	/*15 SYM_S   */{ TOK_SEMI, TOK_EOT },
	/*16 SYM_S   */{ SYM_B, TOK_EOT },
	/*17 SYM_S   */{ TOK_ID, OUT_ID, TOK_ASS, SYM_E, OUT_ASS, TOK_SEMI, TOK_EOT },
	/*18 SYM_S   */{ TOK_WRITE, TOK_LP, SYM_E, OUT_WRITE, TOK_RP, TOK_SEMI, TOK_EOT },
	/*19 SYM_S   */{ TOK_FOR, TOK_ID, OUT_ID, TOK_ASS, SYM_E, OUT_ASS2, OUT_ID_START, TOK_TO, TOK_I4, OUT_I4, OUT_MAX, TOK_DO, OUT_BODY, SYM_B, OUT_IS_STOP, TOK_SEMI, TOK_EOT },
	/*20 SYM_S   */{ TOK_WHILE, OUT_PUSH, OUT_DEFL, SYM_E, TOK_DO, OUT_PUSH, OUT_BZ, SYM_B, OUT_SWAP, OUT_BR, OUT_POPL, OUT_DEFL, TOK_SEMI, TOK_EOT },
	/*21 SYM_S   */{ TOK_IF, SYM_E, TOK_THEN, OUT_PUSH, OUT_BZ, SYM_B, SYM_SI, TOK_SEMI, TOK_EOT },
	/*22 SYM_E   */{ SYM_R, SYM_R_, TOK_EOT },
	/*23 SYM_SI  */{ TOK_ELSE,OUT_PUSH, OUT_BR, OUT_SWAP, OUT_DEFL, SYM_B, OUT_POPL, OUT_DEFL, TOK_EOT },
	/*24 SYM_SI  */{ OUT_POPL, OUT_DEFL, TOK_EOT },
	/*25 SYM_R   */{ SYM_T, SYM_T_, TOK_EOT },
	/*26 SYM_R_  */{ TOK_EQ, SYM_R, SYM_R_,OUT_EQ, TOK_EOT },
	/*27 SYM_R_  */{ TOK_NE, SYM_R, SYM_R_, OUT_NE, TOK_EOT },
	/*28 SYM_R_  */{ TOK_LT, SYM_R, SYM_R_, OUT_LT, TOK_EOT },
	/*29 SYM_R_  */{ TOK_GT, SYM_R, SYM_R_, OUT_GT, TOK_EOT },
	/*30 SYM_R_  */{ TOK_LE, SYM_R, SYM_R_, OUT_LE, TOK_EOT },
	/*31 SYM_R_  */{ TOK_GE, SYM_R, SYM_R_, OUT_GE, TOK_EOT },
	/*32 SYM_R_  */{ TOK_EOT },
	/*33 SYM_T   */{ SYM_A, SYM_A_, TOK_EOT },
	/*34 SYM_T_  */{ TOK_ADD, SYM_T, SYM_T_, OUT_ADD, TOK_EOT },
	/*35 SYM_T_  */{ TOK_SUB, SYM_T, SYM_T_, OUT_SUB, TOK_EOT },
	/*36 SYM_T_  */{ TOK_OR, SYM_T, SYM_T_, OUT_OR, TOK_EOT },
	/*37 SYM_T_  */{ TOK_EOT },
	/*38 SYM_A   */{ SYM_U, SYM_U_, TOK_EOT },
	/*39 SYM_A_  */{ TOK_AND, SYM_A, SYM_A_, OUT_AND, TOK_EOT },
	/*40 SYM_A_  */{ TOK_EOT },
	/*41 SYM_U   */{ SYM_P, TOK_EOT },
	/*42 SYM_U   */{ TOK_NOT, SYM_P, OUT_NOT, TOK_EOT },
	/*43 SYM_U   */{ TOK_SUB, SYM_P, OUT_SUB, TOK_EOT },
	/*44 SYM_U_  */{ TOK_MUL, SYM_U, SYM_U_, OUT_MUL, TOK_EOT },
	/*45 SYM_U_  */{ TOK_DIV, SYM_U, SYM_U_, OUT_DIV, TOK_EOT },
	/*46 SYM_U_  */{ TOK_EOT },
	/*47 SYM_P   */{ TOK_I4, OUT_I4, TOK_EOT },
	/*48 SYM_P   */{ TOK_R8, OUT_R8, TOK_EOT },
	/*49 SYM_P   */{ TOK_QUOTE, OUT_QUOTE, TOK_EOT },
	/*50 SYM_P   */{ TOK_ID, OUT_ID, TOK_EOT },
	/*51 SYM_P   */{ TOK_LP, SYM_E, TOK_RP, TOK_EOT }
};

#define MAX_RULE 51 /* Max rule index */

/* Rule Length */
int RLEN[] = { 0,3,3,0,3,5,2,0,3,0,1,1,1,2,0,1,1,4,4,8,5,6,2,2,0,2,3,3,3,3,3,3,0,2,3,3,3,0,2,3,0,1,2,2,3,3,0,1,1,1,1,3 };

/* Evaluates actual rule's length */
void get_rule_len() {
	int rule, count;
	for (rule = 1; rule <= MAX_RULE; rule++) {
		for (count = 0; count < ST_MAX_RULE_LEN; count++) {
			if ((int)RULE[rule][count] == 0) break;
		}
		RLEN[rule] = count;
	}
}

#define ACC 255 /* ACCEPT CODE */
#define POP 254 /* POP CODE */
#define START SYM_M /* START SYMBOL */

/* Syntax Table SYNTA (LL-analysis) */
stack_t SYNTA[59][39] = {
	/*              EOT   [.] [var] [begi [end]  [id]   [:]   [;]   [,] [real [inte [stri  [:=] [writ   [(]   [)] [for]  [to]  [I4] [whil  [do]  [if] [then [else   [=]  [<>]   [<]   [>]  [<=]  [>=]   [+]   [-]  [or] [and] [not]   [*]   [/]  [R8] [QUOT */
	/*         */{  ACC,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      [.]*/{    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*    [var]*/{    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*  [begin]*/{    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*    [end]*/{    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     [id]*/{    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      [:]*/{    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      [;]*/{    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      [,]*/{    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*   [real]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*[integer]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/* [string]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     [:=]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*  [write]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      [(]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      [)]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*    [for]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     [to]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     [I4]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*  [while]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     [do]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     [if]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*   [then]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*   [else]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      [=]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     [<>]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      [<]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      [>]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     [<=]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     [>=]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      [+]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      [-]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0 },
	/*     [or]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0 },
	/*    [and]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0 },
	/*    [not]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0 },
	/*      [*]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0 },
	/*      [/]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0 },
	/*     [R8]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0 },
	/*  [QUOTE]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP },
	/*              EOT   [.] [var] [begi [end]  [id]   [:]   [;]   [,] [real [inte [stri  [:=] [writ   [(]   [)] [for]  [to]  [I4] [whil  [do]  [if] [then [else   [=]  [<>]   [<]   [>]  [<=]  [>=]   [+]   [-]  [or] [and] [not]   [*]   [/]  [R8] [QUOT */
	/*      <M>*/{    0,    0,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     <DS>*/{    0,    0,    2,    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      <B>*/{    0,    0,    0,    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     <DL>*/{    0,    0,    0,    0,    0,    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*    <DL.>*/{    0,    0,    0,    7,    0,    6,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     <SS>*/{    0,    0,    0,   13,   14,   13,    0,   13,    0,    0,    0,    0,    0,   13,    0,    0,   13,    0,    0,   13,    0,   13,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     <IL>*/{    0,    0,    0,    0,    0,    0,    9,    0,    8,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*     <TY>*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,   10,   11,   12,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      <S>*/{    0,    0,    0,   16,    0,   17,    0,   15,    0,    0,    0,    0,    0,   18,    0,    0,   19,    0,    0,   20,    0,   21,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      <E>*/{    0,    0,    0,    0,    0,   22,    0,    0,    0,    0,    0,    0,    0,    0,   22,    0,    0,    0,   22,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   22,    0,    0,   22,    0,    0,   22,   22 },
	/*     <SI>*/{    0,    0,    0,    0,    0,    0,    0,   24,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   23,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      <R>*/{    0,    0,    0,    0,    0,   25,    0,    0,    0,    0,    0,    0,    0,    0,   25,    0,    0,    0,   25,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   25,    0,    0,   25,    0,    0,   25,   25 },
	/*     <R.>*/{    0,    0,    0,    0,    0,    0,    0,   32,    0,    0,    0,    0,    0,    0,    0,   32,    0,   32,    0,    0,   32,    0,   32,    0,   26,   27,   28,   29,   30,   31,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
	/*      <T>*/{    0,    0,    0,    0,    0,   33,    0,    0,    0,    0,    0,    0,    0,    0,   33,    0,    0,    0,   33,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   33,    0,    0,   33,    0,    0,   33,   33 },
	/*     <T.>*/{    0,    0,    0,    0,    0,    0,    0,   37,    0,    0,    0,    0,    0,    0,    0,   37,    0,   37,    0,    0,   37,    0,   37,    0,   37,   37,   37,   37,   37,   37,   34,   35,   36,    0,    0,    0,    0,    0,    0 },
	/*      <A>*/{    0,    0,    0,    0,    0,   38,    0,    0,    0,    0,    0,    0,    0,    0,   38,    0,    0,    0,   38,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   38,    0,    0,   38,    0,    0,   38,   38 },
	/*     <A.>*/{    0,    0,    0,    0,    0,    0,    0,   40,    0,    0,    0,    0,    0,    0,    0,   40,    0,   40,    0,    0,   40,    0,   40,    0,   40,   40,   40,   40,   40,   40,   40,   40,   40,   39,    0,    0,    0,    0,    0 },
	/*      <U>*/{    0,    0,    0,    0,    0,   41,    0,    0,    0,    0,    0,    0,    0,    0,   41,    0,    0,    0,   41,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   43,    0,    0,   42,    0,    0,   41,   41 },
	/*     <U.>*/{    0,    0,    0,    0,    0,    0,    0,   46,    0,    0,    0,    0,    0,    0,    0,   46,    0,   46,    0,    0,   46,    0,   46,    0,   46,   46,   46,   46,   46,   46,   46,   46,   46,   46,    0,   44,   45,    0,    0 },
	/*      <P>*/{    0,    0,    0,    0,    0,   50,    0,    0,    0,    0,    0,    0,    0,    0,   51,    0,    0,    0,   47,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   48,   49 }
};
