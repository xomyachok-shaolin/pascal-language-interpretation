// 2019 ReVoL Primer Template
// simplet.cpp
// �������� �������

#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
// �������� ���� � �������
#include "types.h"
// ����������� ����������
#include "lexan.h"
// �������������� ����������
// #include "sa1null.h"
// #include "sa2RD.h"
#include  "sa3LL.h"
#include "simplet.h"


int simplet(FILE * input) {
    // ����������� ����������
    try {
        // �������������� ������
        return (new syntaxan(new lexan(input, stdout), stdout, stdout))->parse();
    } catch(const char * e) {
        OUT_STR_FILE.append("\nException raised %s.\n\n", e);
    } catch(...) {
        OUT_STR_FILE.append("\nUnexpected exception raised.\n\n");
    }
    return 0; // �������
}


int main(int argc, char * argv[]) {
    int x = 4294967297;
    double y = 4294967297;

    // ��������� ������� �����
    FILE * input = fopen("..\\Debug\\1.st", "rt");
    if (!input) {
        // �������� � ������� ������
        OUT_STR_FILE.append("simplet: error while open input file\n\n");

        updateAPI();
        return 1; // �������
    }
    updateAPI();

    // ���������� ����������
    __try {
        bool flag = (simplet(input)) == 0 ? 1 : 0;

        updateAPI();
        return flag;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        unsigned int code = GetExceptionCode();
        if (code == EXCEPTION_ACCESS_VIOLATION) {
            OUT_STR_FILE.append("\nAccess violation raised.\n\n");
        } else if (code == EXCEPTION_STACK_OVERFLOW) {
            OUT_STR_FILE.append("\nStack overflow raised.\n\n");
        } else {
            OUT_STR_FILE.append("\nHardware exception raised.\n\n");
        }
    }
    updateAPI();

    return 1; // �������
 }
