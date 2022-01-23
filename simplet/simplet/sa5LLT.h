// 2019 ReVoL Primer Template
// sa5LLT.h
// �������������� ����������

#include "syntallo.h"
#include "stsyms.h"
#include "ststrip.h"
// ������ ����� ��-��������
#define MAX_STACK 64
// ������ ��������������� �����
#define MAX_EXEST 64
// ������ ������� ��������
#define MAX_SYMS 16
// ������ ����� �����
#define MAX_LABEL 16
// ������ �����
#define MAX_STRIP 64
// ������ ����� ��������
#define MAX_IT 999

class syntaxan {
public:
    // �����������
    syntaxan(lexan * lex, FILE * parse_stream, FILE * error_stream) {
        this->lex = lex;
        this->parse_stream = parse_stream;
        this->error_stream = error_stream;
    }
    // LL(1) ���������� � �����
    int parse(void) {
        if (!next_token()) return 0;


        fprintf(parse_stream, "\nsyntaxan: success.\n\n");
        return 1;
    }
private:
    // ������ �� ����������� ����������
    lexan * lex;
    // ����� ����������
    FILE * parse_stream;
    // ����� ���������
    FILE * error_stream;
    // ������� �����
    sttoken tok;
    // ���������� ��������� �����
    int next_token() {
        return lex->next_token(tok);
    }
};
