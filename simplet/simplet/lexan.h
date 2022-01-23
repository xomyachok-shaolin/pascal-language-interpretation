// 2019 ReVoL Primer Template
// lexan.h
// ����������� ����������

#include "sttot.h"

#include <iostream>
#include <fstream>
using namespace std;
string OUT_STR_LEX;

void updateLexAPI()
{
    ofstream myfile;
    myfile.open("lexan");
    myfile << OUT_STR_LEX;
    myfile.close();
}


class lexan {
    // ������� �����
    FILE * input_stream;
    // ����� ���������
    FILE * error_stream;
    // ������� ������ �����
    char cc;
    // ���������� ��������� ������ �����
    void next_char(void) {
        cc = getc(input_stream);
        if (cc != -1)
            _putch(cc);
    }
    // ��������� ����������� ��
    sttype is_comment() {
        enum {A, B, C} state = A;
        while (1) {
            next_char();
            switch (state) {
            case A:
                if (cc == EOF) {
                    OUT_STR_LEX.append(string("\n\n")); 
                    updateLexAPI();
                    return TOK_UNKNOWN;
                }
                if (cc == '*') {
                    state = B;
                    break;
                }
                return TOK_DIV;
            case B:
                if (cc == EOF) {
                    OUT_STR_LEX.append(string("\n\n"));
                    updateLexAPI();
                    return TOK_UNKNOWN;
                }
                if (cc == '*') {
                    state = C;
                    break;
                }
                break;
            case C:
                if (cc == EOF) {
                    OUT_STR_LEX.append(string("\n\n"));
                    updateLexAPI();
                    return TOK_UNKNOWN;
                }
                if (cc == '*') break;
                if (cc == '/') return TOK_COMMENT;
                state = B;
                break;
            }
        }
        return TOK_UNKNOWN;
    }
    // ��������� �������������
    int get_id(sttoken & tok) {
        tok.stt = TOK_ID;
        // ������� ����� ��������������
        int length_id = 1;
        while (1) {
            switch (TOT[cc]) {
            case ALPHA:
                if (strlen(tok.str_val) < MAX_ID) 
                    tok.append(cc);
                break;
            case DIGIT:
                if (strlen(tok.str_val) < MAX_ID) 
                    tok.append(cc);
                break;
            default:
                return is_keyword(tok);
            }
            next_char();
        }
        return 1;
    }
    // ���������� �������� �����
    int is_keyword(sttoken & tok) {
        if (!strcmp(tok.str_val, "var")) {
            tok.stt = TOK_VAR;
            return 1;
        }
        if (!strcmp(tok.str_val, "write")) {
            tok.stt = TOK_WRITE;
            return 1;
        }
        if (!strcmp(tok.str_val, "if")) {
            tok.stt = TOK_IF;
            return 1;
        }
        if (!strcmp(tok.str_val, "then")) {
            tok.stt = TOK_THEN;
            return 1;
        }
        if (!strcmp(tok.str_val, "else")) {
            tok.stt = TOK_ELSE;
            return 1;
        }
        if (!strcmp(tok.str_val, "begin")) {
            tok.stt = TOK_BEGIN;
            return 1;
        }
        if (!strcmp(tok.str_val, "end")) {
            tok.stt = TOK_END;
            return 1;
        }
        if (!strcmp(tok.str_val, "integer")) {
            tok.stt = TOK_INTEGER;
            return 1;
        }
        if (!strcmp(tok.str_val, "real")) {
            tok.stt = TOK_REAL;
            return 1;
        }
        if (!strcmp(tok.str_val, "string")) {
            tok.stt = TOK_STRING;
            return 1;
        }
        if (!strcmp(tok.str_val, "or")) {
            tok.stt = TOK_OR;
            return 1;
        }
        if (!strcmp(tok.str_val, "and")) {
            tok.stt = TOK_AND;
            return 1;
        }
        if (!strcmp(tok.str_val, "not")) {
            tok.stt = TOK_NOT;
            return 1;
        }
		if (!strcmp(tok.str_val, "for")) {
			tok.stt = TOK_FOR;
			return 1;
		}
		if (!strcmp(tok.str_val, "to")) {
			tok.stt = TOK_TO;
			return 1;
		}
        if (!strcmp(tok.str_val, "do")) {
            tok.stt = TOK_DO;
            return 1;
        }
        if (!strcmp(tok.str_val, "while")) {
            tok.stt = TOK_WHILE;
            return 1;
        }
        return 1;
    }
    // ��������� ����� �����
    int is_number(sttoken & tok) {
        // TOK_I4 - ������� ������ �����
        tok.stt = TOK_I4;
        // �������� ��������� �� ������ ������ �����

        while (1) {
            switch (TOT[cc]) {
            case DIGIT:
                tok.int_val *= 10;
                tok.int_val += cc - '0';
                break;
            case CHDOT:
                return is_float(tok, 0);
            default:
                return 1;
            }
            next_char();
        }
        return 1;
    }
    // ��������� ������������ ����� �����
    int is_float(sttoken & tok, int must) {
        tok.stt = TOK_R8;
        // ���������� � ������� ����� ����������� �����������
        double number = 0;
        int div = 0;

        if (must == 1) {
            tok.stt = TOK_DOT;
            next_char();
            return 1;
        }

        while (1) {
            // �� ����� �� ��������� ��������
            next_char();
            switch (TOT[cc]) {
            // ����� ������ ���� ������ ����
            case CHDOT:
                OUT_STR_LEX.append(string("\nlexan: extra dot in float\n\n"));
                updateLexAPI();
                return 0;
            case DIGIT:
                number *= 10;
                number += cc - '0';
                div++;
                must = 1;
                break;
            default:
                // ��������� �������� ������
                if (must != 1) {
                    OUT_STR_LEX.append(string("\nsingle dot in float\n\n"));
                    updateLexAPI();
                    return 0;
                }


                number /= pow(10, div);
                tok.dbl_val = tok.int_val + number;
                return 1;
            }
        }
        return 1;
    }
    // ��������� ��������� �������
    int is_quote(sttoken & tok) {
        tok.stt = TOK_QUOTE;
        while (1) {
            next_char();
            if (TOT[cc] == QUOTE) {
                next_char();
                if (TOT[cc] != QUOTE) 
                    return 1;
                else {
                    tok.append(' ');
                    continue;
                }
            }
            if (cc == EOF) {
                OUT_STR_LEX.append(string("\nlexan: unexpected end of file in quote\n\n"));
                updateLexAPI();
                return 0;
            }
            if (cc < 32) {
                OUT_STR_LEX.append(string("\nlexan: extra character in quote\n\n"));
                updateLexAPI();
                return 0;
            }
            tok.append(cc);
        }
        
        return 1;
    }
    // ��������� ��������
    int is_opera(sttoken & tok) {
        
        switch (cc) {
        // ������������ �������� ��� �����������
        case '(': 
            next_char(); 
            tok.stt = TOK_LP;
            return 1;
        case ')':
            next_char();
            tok.stt = TOK_RP;
            return 1;
        case '{':
            next_char();
            tok.stt = TOK_LS;
            return 1;
        case '}':
            next_char();
            tok.stt = TOK_RS;
            return 1;
        case ',':
            next_char();
            tok.stt = TOK_COMMA;
            return 1;
        case '+':
            next_char();
            tok.stt = TOK_ADD;
            return 1;
        case '-':
            next_char();
            tok.stt = TOK_SUB;
            return 1;
        case '*':
            next_char();
            tok.stt = TOK_MUL;
            return 1;
        case '/':
            next_char();
            tok.stt = TOK_DIV;
            return 1;
        case ';':
            next_char();
            tok.stt = TOK_SEMI;
            return 1;

        // ������������� ��������
        case ':':
            next_char();
            if (cc == '=') {
                next_char();
                tok.stt = TOK_ASS;
                return 1;
            } else {
                tok.stt = TOK_COLON;
                return 1;
            }
        case '=':
            next_char();
            if (cc == '=') {
                next_char();
                tok.stt = TOK_ASS;
                return 1;
            } else {
                tok.stt = TOK_EQ;
                return 1;
            }
        case '<':
            next_char();
            if (cc == '>') {
                next_char();
                tok.stt = TOK_NE;
                return 1;
            }
            if (cc == '=') {
                next_char();
                tok.stt = TOK_LE;
                return 1;
            } else {
                tok.stt = TOK_LT;
                return 1;
            }
        case '>':
            next_char();
            if (cc == '=') {
                next_char();
                tok.stt = TOK_GE;
                return 1;
            } else {
                tok.stt = TOK_GT;
                return 1;
            }
        default:
            OUT_STR_LEX.append(string("\nlexan: extra character in line\n\n"));
            updateLexAPI();
            return 0;
        }

        return 1;
    }
public:
    // ���������� ��������� ����� ������
    int next_token(sttoken & tok) {
        // ���� ������ ������ �������
        while (1) {
            if (cc == EOF) {
                // ����� ������
                tok.stt = TOK_EOT;
                return 1;
            } else if (cc == 10) {
                // ������ ������������
                /*/
                // ���� � ����� ���� ����� LF
                tok.stt = TOK_LF;
                next_char();
                return 1;
                /*/
            } else if (cc == '/') {
                // ���� ������������ � ��
                sttype result = is_comment();
                if (result == TOK_DIV) {
                    // ��� �������� �������, � �� comment
                    tok.stt = TOK_DIV;
                    return 1;
                } else if (result == TOK_UNKNOWN) {
                    // ������ � �����������
                    return 0;
                }
                // comment ����������, 32 - ������
            } else if (cc < 33) {
                // ����������� ������� � ������ ����������
            } else {
                // ������ ������ ��������� ������
                break;
            }
            // ��������� ������
            next_char();
        }
        // �������������� �����
        tok.reset();
        // ��������� ������ ������ �������
        switch (TOT[cc]) {
        case ALPHA:
            return get_id(tok);
        case DIGIT:
            return is_number(tok);
        case CHDOT:
            return is_float(tok, 1);
        case QUOTE:
            return is_quote(tok);
        default:
            return is_opera(tok);
        }
        return 0;
    }
    // �����������
    lexan(FILE * input_stream, FILE * error_stream) {
        this->input_stream = input_stream;
        this->error_stream = error_stream;
        // ������ ������ ������
        next_char();
    }
};
