// 2019 ReVoL Primer Template
// ststrip.h
// классы ленты внутреннего представления

// элемент ленты
typedef sttoken exstel;

#include <iostream>
#include <fstream>
using namespace std;
string OUT_STR_POLIZ;

// лента
template <int N>
class ststrip {
    // массив элементов
    exstel st[N];
    // счетчик элементов
    int count;
    // счетчик меток
    int label;
    // глубина
    int depth;
public:
    // конструктор
    ststrip() {
        reset();
        st[0].stt = OUT_START;
    }
    // деструктор
    ~ststrip() {
        printf("ststrip: size=%d, depth=%d.\n", N, depth - 1);
    }
    // очищает объект
    void reset(void) {
        count = 1;
        depth = label = 0;
        for (int i = 0; i < N; i++) st[i].reset();
    }
    // возвращает количество элементов
    int size(void) {
        return count - 1;
    }
    // возвращает новый идентификатор метки
    int new_label() {
        return ++label;
    }
    // возвращает указанный элемент
    exstel & operator [] (int index) {
        if (index < 1 || index >= count) throw "ststrip::operator[] invalid index";
        return st[index];
    }
    // добавляет элемент
    void add(exstel e) {
        if (count >= N) throw "ststrip::add strip overflow";
        st[count++] = e;
        if (depth < count) depth = count;
    }
    // ищет на ленте определение метки с идентификатором id
    int find_DEF(int id) {
        for (int i = 1; i < count; i++) {
            if (st[i].stt == OUT_END) return -1; // конец ленты
            if (st[i].stt == OUT_LABEL && st[i].int_val == id) {
                if (st[i + 1].stt == OUT_DEFL) {
                    return (i + 2);
                }
            }
        }
        return -1;
    }
    // вывод в текстовый файл
    void print(FILE * f) {


        
        // OUT_STR_POLIZ.append(string("strip\n\n"));
        for (int i = 1; i < count; i++) {
            OUT_STR_POLIZ.append(string("\n").append(to_string(i)).append(" "));
            switch (st[i].stt) {
            case OUT_ID:    OUT_STR_POLIZ.append(string("ID ").append(st[i].str_val)); break;
            case OUT_I4:    OUT_STR_POLIZ.append(string("I4 ").append(to_string(st[i].int_val))); break;
            case OUT_R8:    OUT_STR_POLIZ.append(string("R8 ").append(to_string(st[i].dbl_val))); break;
			case OUT_QUOTE:   OUT_STR_POLIZ.append(string("QUOTE ").append( st[i].str_val)); break;
            case OUT_LABEL: OUT_STR_POLIZ.append(string("LABEL ").append(to_string(st[i].int_val))); break;
            case OUT_DEFL:  OUT_STR_POLIZ.append(string("DEFL\n")); break;
            case OUT_PUSH:  OUT_STR_POLIZ.append(string("PUSH\n")); break;
            case OUT_POPL:  OUT_STR_POLIZ.append(string("POPL\n")); break;
            case OUT_SWAP:  OUT_STR_POLIZ.append(string("SWAP\n")); break;
            case OUT_BZ:    OUT_STR_POLIZ.append(string("BZ\n")); break;
            case OUT_BR:    OUT_STR_POLIZ.append(string("BR\n")); break;
            case OUT_EQ:    OUT_STR_POLIZ.append(string("EQ\n")); break;
            case OUT_NOT:    OUT_STR_POLIZ.append(string("NOT\n")); break;
			case OUT_OR:    OUT_STR_POLIZ.append(string("OR\n")); break;
			case OUT_AND:    OUT_STR_POLIZ.append(string("AND\n")); break;
            case OUT_NE:    OUT_STR_POLIZ.append(string("NE\n")); break;
            case OUT_LT:    OUT_STR_POLIZ.append(string("LT\n")); break;
            case OUT_GT:    OUT_STR_POLIZ.append(string("GT\n")); break;
            case OUT_LE:    OUT_STR_POLIZ.append(string("LE\n")); break;
            case OUT_GE:    OUT_STR_POLIZ.append(string("GE\n")); break;
            case OUT_VAR:   OUT_STR_POLIZ.append(string("VAR\n")); break;
            case OUT_ASS:   OUT_STR_POLIZ.append(string("ASS\n")); break;
            case OUT_MAX:   OUT_STR_POLIZ.append(string("MAX\n")); break;
            case OUT_BODY:   OUT_STR_POLIZ.append(string("BODY\n")); break;
            case OUT_ID_START:   OUT_STR_POLIZ.append(string("ID_START\n")); break;
            case OUT_IS_STOP:   OUT_STR_POLIZ.append(string("IS_STOP\n")); break;
            case OUT_ASS2:   OUT_STR_POLIZ.append(string("ASS2\n")); break;
            case OUT_ADD:   OUT_STR_POLIZ.append(string("ADD\n")); break;
            case OUT_SUB:   OUT_STR_POLIZ.append(string("SUB\n")); break;
            case OUT_MUL:   OUT_STR_POLIZ.append(string("MUL\n")); break;
            case OUT_DIV:   OUT_STR_POLIZ.append(string("DIV\n")); break;
			case OUT_STRING:   OUT_STR_POLIZ.append(string("STRING\n")); break;
            case OUT_WRITE: OUT_STR_POLIZ.append(string("WRITE\n")); break;
            case OUT_REAL:  OUT_STR_POLIZ.append(string("REAL\n")); break;
            case OUT_INTEGER:   OUT_STR_POLIZ.append(string("INT\n")); break;
            case OUT_END:   OUT_STR_POLIZ.append(string("END\n")); break;
            default: OUT_STR_POLIZ.append(string("UNKNOWN\n"));
            }
        }
        OUT_STR_POLIZ.append(string("\n"));


    }
};

// вычислительный стек ПОЛИЗ
template <int N>
class exstack {
private:
    // массив элементов
    exstel st[N];
    // счетчик
    int count;
    // глубина
    int depth;
public:
    // конструктор
    exstack() {
        count = 0;
        depth = 0;
    }
    // деструктор
    ~exstack() {
        printf("exstack: size=%d, depth=%d.\n", N, depth);

        
    }
    // возвращает количество элементов
    int size(void) {
        return count;
    }
    // проталкивает элемент
    void push(exstel & e) {
        if (count >= N) throw "exstack::push exe-stack overflow";
        st[count++] = e;
        if (depth < count) {
            depth = count;
        }
    }
    // выталкивает элемент
    void pop(exstel & e) {
        if (count < 1) throw "exstack::push exe-stack is empty";
        e = st[--count];
        st[count].reset();
    }
};
