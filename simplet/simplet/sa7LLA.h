// 2019 ReVoL Primer Template
// sa7LLA.h
// �������������� ����������

#include "syntall.h"
#include "stsyms.h"
// ������ ����� ��-��������
#define MAX_STACK 64

class syntaxan {
public:
    // �����������
    syntaxan(lexan * lex, FILE * parse_stream, FILE * error_stream) {
        this->lex = lex;
        this->parse_stream = parse_stream;
        this->error_stream = error_stream;
    }
    // ���������� LL(1)
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
    // ���� ��-��������
    ststack<stack_t, MAX_STACK> sta;
    // ���������� ��������� �����
    int next_token() {
        return lex->next_token(tok);
    }
};
