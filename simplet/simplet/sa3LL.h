// 2019 ReVoL Primer Template
// sa3LL.h
// синтаксический анализатор

#include "syntall.h"
#include "stsyms.h"
#include "ststrip.h"
// размер стека МП-автомата
#define MAX_STACK 64
// размер вычислительного стека
#define MAX_EXEST 64
// размер таблицы символов
#define MAX_SYMS 16
// размер стека меток
#define MAX_LABEL 16
// размер ленты
#define MAX_STRIP 64
// предел числа итераций
#define MAX_IT 999999


#include <iostream>
#include <stack> 
using namespace std;

string OUT_STR_FILE;

class cycleFor {
public:
	exstel curVal;
	int maxVal;
	int body;
	int pos;

	cycleFor() {
		this->curVal.int_val = 0;
		this->maxVal = 0;
		this->body = 0;
		this->pos = 0;
	}

	int UpIteration() {
		if (curVal.int_val < maxVal) {
			curVal.int_val += 1;
			return curVal.int_val;
		}
		else {
			return MAX_IT;
		}
	}
	int getIteration() {
		return curVal.int_val;
	}
};

void updateAPI()
{
	ofstream myfile;
	myfile.open("response");
	myfile << OUT_STR_FILE;
	myfile.close();

	myfile.open("poliz");
	myfile << OUT_STR_POLIZ;
	myfile.close();
}


cycleFor _For;
stack<cycleFor> stackCycle;


class syntaxan {
public:
    // конструктор
    syntaxan(lexan * lex, FILE * parse_stream, FILE * error_stream) {
        this->lex = lex;
        this->parse_stream = parse_stream;
        this->error_stream = error_stream;
    }
	// LL(1) трансляция в ПОЛИЗ
	int parse(void) {
		if (!next_token()) return 0;
		stack_t at = TOK_EOT, bt = TOK_EOT;
		stack_t s = TOK_EOT;    // значение на вершине стека
		stack_t t = TOK_EOT;    // значение, считанное из управляющей таблицы
		int i = 0, n = 0;
		get_rule_len();
		sta.push(TOK_EOT);
		sta.push(START);
		while (true) {
			s = clear_stack();  // выталкиваем символ с вершины стека И проталкиваем их на ленту. 
			t = SYNTA[s][tok.stt];
			if (t <= 0) {
				OUT_STR_FILE.append(string("\nsyntaxan: syntax error\n"));

				updateAPI();

				return 0;
			}
			else if (t == ACC) {    // допуск
				break;
			}
			else if (t == POP) {    // выброс
				at = sta.pop();
				clear_stack();
				if (!next_token()) return 0;
			}
			else if (t <= MAX_RULE) {   // правило
				at = sta.pop();
				n = RLEN[t];
				for (int i = n - 1; i >= 0; i--) {
					bt = RULE[t][i];
					sta.push(bt);
				}
			}
			else {
				OUT_STR_FILE.append(string("\nsyntaxan: invalid SYNTA\n"));

				updateAPI();
			}
		}
		out(OUT_END);
		strip.print(parse_stream);  // вывод ленты полиз в консоль
		execute();
		OUT_STR_FILE.append(string("\nsyntaxan: success\n"));

		return 1;
	}
private:
	// ссылка на лексический анализатор
	lexan* lex;
	// поток результата
	FILE* parse_stream;
	// поток сообщений
	FILE* error_stream;
	// текущий токен
	sttoken tok;
	// таблица символов
	stsyms<MAX_SYMS> syms;
	// исполняющий стек
	exstack<MAX_EXEST> exe;
	// лента ПОЛИЗ
	ststrip<MAX_STRIP> strip;
	// стек меток
	ststack<int, MAX_LABEL> stl;
	// стек МП-автомата
	ststack<stack_t, MAX_STACK> sta;
	// возвращает очередной токен
	int next_token() {
		return lex->next_token(tok);
	}

	// запись символа на ленту ПОЛИЗ
	void out(sttype tt) {
		int i = 0, j = 0;
		sttoken t = tok;
		t.stt = tt;
		switch (tt) {
		case OUT_PUSH:
			j = strip.new_label();
			stl.push(j);
			t.int_val = j;
			t.stt = OUT_LABEL;
			break;
		case OUT_POPL:
			j = stl.pop();
			t.int_val = j;
			t.stt = OUT_LABEL;
			break;
		case OUT_SWAP:
			i = stl.pop();
			j = stl.pop();
			stl.push(i);
			t.int_val = j;
			t.stt = OUT_LABEL;
			break;
		}
		strip.add(t);
	}
	// извлечения из стека (таблицы символов) значения элемента 
	void exe_pop(exstel& e) {
		exe.pop(e);
		if (e.stt == OUT_I4 || e.stt == OUT_R8 || e.stt == OUT_QUOTE) {
		}
		else if (e.stt == OUT_ID) {
			int j = syms.find(e);   // поиск в таблице символов
			if (j == ST_NOTFOUND) {
				OUT_STR_FILE.append(string("exe_pop identifier not found"));
			}
			// извлекаем значение из таблицы символов
			e.int_val = syms[j].int_val;
			e.dbl_val = syms[j].dbl_val;
			e.stt = syms[j].stt;
			// меняем тип элемента на константный
			if (!syms[j].string_val.empty()) {
				e.stt = OUT_QUOTE;
				e.string_val = syms[j].string_val;
			}
		}	else {
			OUT_STR_FILE.append(string("exe_pop internal error"));
		}
	}
	// исполняющая машина ПОЛИЗ
	void execute() {
		// счетчик операций ПОЛИЗ
		int it_counter = 1;
		// указатель ленты ПОЛИЗ
		int strip_pointer = 1;
		// текущий эл-т ПОЛИЗ
		sttype stt;
		// переменные для вычислений
		exstel X, Y;
		// вспомогательные 
		int j = 0;
		// рабочий цикл выполнения ленты ПОЛИЗ
		while (1) {
			// очистим переменные
			X.reset();
			Y.reset();
			// считываем тип эл-та лент
			stt = strip[strip_pointer].stt;
			switch (stt) {
			case OUT_END:
				OUT_STR_FILE.append(string("\n\nEXE DONE"));
				return;
			case OUT_ID: case OUT_I4: case OUT_INTEGER: case OUT_R8: case OUT_REAL: case OUT_QUOTE: case OUT_STRING:
				// проталкиваем в стек
				exe.push(strip[strip_pointer]);
				strip_pointer++;
				break;
			case OUT_VAR:
				exe.pop(Y); // тип данных
				exe.pop(X); // переменная
				
				if (Y.stt == OUT_INTEGER)
					X.data_type = STDT_I4;
				else if (Y.stt == OUT_REAL)
					X.data_type = STDT_R8;
				else if (Y.stt == OUT_STRING)
					X.data_type = STDT_QUOTE;
				else
					X.data_type = Y.data_type;

				j = syms.insert(X);
				if (j == ST_EXISTS) {
					OUT_STR_FILE.append(string("exe duplicate declaration"));
				}

				

				while (exe.size() != 0) {
					exe.pop(X); // переменная

					if (Y.stt == OUT_INTEGER)
						X.data_type = STDT_I4;
					else if (Y.stt == OUT_REAL)
						X.data_type = STDT_R8;
					else if (Y.stt == OUT_QUOTE)
						X.data_type = STDT_QUOTE;
					else 
						X.data_type = Y.data_type;

					j = syms.insert(X);
					if (j == ST_EXISTS) {
						OUT_STR_FILE.append(string("exe duplicate declaration"));
					}
					
				}
				strip_pointer++;
				break;
			case OUT_ASS:
				exe_pop(Y);
				exe.pop(X);
				j = syms.find(X);
				if (j == ST_NOTFOUND) {
					OUT_STR_FILE.append(string("exe identifier not found"));
				}

				if (syms[j].data_type == STDT_R8 && Y.stt == OUT_I4) {
					syms[j].stt = OUT_R8;
					syms[j].dbl_val = Y.int_val;
				} else if (syms[j].data_type == STDT_R8 && Y.stt == OUT_R8) {
					syms[j].stt = OUT_R8;
					syms[j].dbl_val = Y.dbl_val;
				}else if (syms[j].data_type == STDT_I4 && Y.stt == OUT_R8) {
					syms[j].stt = OUT_I4;
					syms[j].int_val = Y.dbl_val;
				} else if (syms[j].data_type == STDT_I4 && Y.stt == OUT_I4) {
					syms[j].stt = OUT_I4;
					syms[j].int_val = Y.int_val;
				} else if (syms[j].data_type == STDT_QUOTE && Y.stt == OUT_QUOTE) {
					syms[j].stt = OUT_QUOTE;
					if (!Y.string_val.empty())
						syms[j].string_val = Y.string_val;
					else
						syms[j].string_val = Y.str_val;

				}
				else {
					OUT_STR_FILE.append(string("exe initialization not compatible data type"));
				}
				strip_pointer++;
				break;



			case OUT_ID_START:
				exe_pop(X);     // позиция
				exe_pop(Y);     // значение переменнуй 
				_For.pos = X.int_val;
				_For.curVal = Y;
				strip_pointer++;
				break;

			case OUT_ASS2:
				exe_pop(Y);
				exe.pop(X);
				j = syms.find(X);   // смотрим, определён ли он
				if (j == ST_NOTFOUND) {
					OUT_STR_FILE.append(string("exe identifier not found"));
				}

				if (syms[j].data_type != STDT_I4) {
					OUT_STR_FILE.append(string("exe identifier not compatible data type"));
				}

				syms[j].int_val = Y.int_val;
				syms[j].stt = OUT_I4;

				strip_pointer++;
				X = syms[j];
				exe.push(X);        // протолкнули значение x в цикле "for x = 0 .... "

				Y.int_val = j;
				exe.push(Y);         // протолкнули позицию из таблицы символов sym нашего x в цикле "for x = 0 .... "
				break;

			case OUT_MAX:
				exe.pop(Y);
				_For.maxVal = Y.int_val;
				strip_pointer++;
				break;


			case OUT_BODY:
				_For.body = ++strip_pointer;
				stackCycle.push(_For);
				break;


			case OUT_IS_STOP:
				_For = stackCycle.top();
				stackCycle.pop();
				// обновляем текущее значение итератора цикла for (локально)
				_For.curVal.int_val = syms[_For.pos].int_val;
				if (_For.UpIteration() != MAX_IT) {
					strip_pointer = _For.body;  // вернулись обратно
					// обновляем значение переменной итератора цикла for(глобально)
					// pos - позиция в массиве syms
					syms[_For.pos].int_val = _For.curVal.int_val;
					stackCycle.push(_For);
				}
				else {
					strip_pointer++;
				}
				break;

			case OUT_NOT:
				exe_pop(X);
					if (X.stt == OUT_I4)
						if (X.int_val) X.int_val = 0;
						else X.int_val = 1;
					else if (X.stt == OUT_R8)
						if (X.dbl_val) X.int_val = 0;
						else X.int_val = 1;
					else if (X.stt == OUT_QUOTE)
						OUT_STR_FILE.append(string("ERROR. Logical operation of type string"));

				exe.push(X);
				strip_pointer++;
				break;


			case OUT_ADD: case OUT_SUB: case OUT_MUL: case OUT_DIV:
			case OUT_EQ: case OUT_NE: case OUT_LT: case OUT_GT: case OUT_LE: case OUT_GE: 
			case OUT_OR: case OUT_AND:
				exe_pop(Y);
				exe_pop(X);
				switch (stt) {
				case OUT_ADD:
					if (X.stt == OUT_QUOTE || Y.stt == OUT_QUOTE) {
						string tempX, tempY;
						if (Y.stt == OUT_QUOTE) {
							
							if (!X.string_val.empty())
								tempX = X.string_val;
							else
								tempX = string(X.str_val);
							if (!Y.string_val.empty()) 
								tempY = Y.string_val;
							else 
								tempY = string(Y.str_val);
						} 
						if (X.stt == OUT_I4 || X.stt == OUT_R8) {
							if (!Y.string_val.empty())
								tempY = Y.string_val;
							else
								tempY = string(Y.str_val);
							if (X.dbl_val)
								tempX = std::to_string(X.dbl_val);
							else
								tempX = std::to_string(X.int_val);
						}
						if (Y.stt == OUT_I4 || Y.stt == OUT_R8) {
							if (!X.string_val.empty())
								tempX = X.string_val;
							else
								tempX = string(X.str_val);
							if (Y.dbl_val) 
								tempY = std::to_string(Y.dbl_val);
							else
								tempY = std::to_string(Y.int_val);
						}
						X.string_val = tempX + tempY;
						X.stt = OUT_QUOTE;
						break;
					}

					if (X.stt == OUT_R8 || Y.stt == OUT_R8) {
						if (X.stt == OUT_I4)
							X.dbl_val = X.int_val + Y.dbl_val;
						if (Y.stt == OUT_I4)
							X.dbl_val = Y.int_val + X.dbl_val;
						if (X.stt == OUT_R8 && Y.stt == OUT_R8)
							X.dbl_val += Y.dbl_val;
						X.stt = OUT_R8;
					} else
					if (X.stt != Y.stt) OUT_STR_FILE.append(string("ERROR. Adding. Different types"));
					X.int_val += Y.int_val;
					break;
				case OUT_SUB:
					if (X.stt == OUT_R8 || Y.stt == OUT_R8) {
						if (X.stt == OUT_I4)
							X.dbl_val = X.int_val - Y.dbl_val;
						if (Y.stt == OUT_I4)
							X.dbl_val = X.dbl_val - Y.int_val;
						if (X.stt == OUT_R8 && Y.stt == OUT_R8)
							X.dbl_val -= Y.dbl_val;
						X.stt = OUT_R8;
					}
					else
						if (X.stt != Y.stt) OUT_STR_FILE.append(string("ERROR. Subtracting. Different types"));
					X.int_val -= Y.int_val;
					break;


				case OUT_OR:
					if (X.stt == Y.stt) {
						if (X.stt == OUT_I4)
							if (X.int_val || Y.int_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_R8)
							if (X.dbl_val || Y.dbl_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_QUOTE) {
							OUT_STR_FILE.append(string("ERROR. Logical operation of type string"));
						}
					}
					else {
						OUT_STR_FILE.append(string("ERROR. Logical operation of different types"));
					}
					break;

				case OUT_AND:
					if (X.stt == Y.stt) {
						if (X.stt == OUT_I4)
							if (X.int_val && Y.int_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_R8)
							if (X.dbl_val && Y.dbl_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_QUOTE) {
							OUT_STR_FILE.append(string("ERROR. Logical operation of type string"));
						}
					}
					else {
						OUT_STR_FILE.append(string("ERROR. Logical operation of different types"));
					}
					break;


				case OUT_MUL:
					if (X.stt == OUT_R8 || Y.stt == OUT_R8) {
						if (X.stt == OUT_I4)
							X.dbl_val = X.int_val * Y.dbl_val;
						if (Y.stt == OUT_I4)
							X.dbl_val = X.dbl_val * Y.int_val;
						if (X.stt == OUT_R8 && Y.stt == OUT_R8)
							X.dbl_val *= Y.dbl_val;
						X.stt = OUT_R8;
					}
					else
						if (X.stt != Y.stt) OUT_STR_FILE.append(string("ERROR. Multiplication. Different types"));
					X.int_val *= Y.int_val;
					break;
				case OUT_DIV:
					if (Y.int_val == 0 && Y.dbl_val == 0) OUT_STR_FILE.append(string("exe division by zero"));
					if (X.stt == OUT_R8 || Y.stt == OUT_R8) {
						if (X.stt == OUT_I4)
							X.dbl_val = X.int_val / Y.dbl_val;
						if (Y.stt == OUT_I4)
							X.dbl_val = X.dbl_val / Y.int_val;
						if (X.stt == OUT_R8 && Y.stt == OUT_R8)
							X.dbl_val /= Y.dbl_val;
						X.stt = OUT_R8;
					}
					else
						if (X.stt != Y.stt) OUT_STR_FILE.append(string("ERROR. Division. Different types"));
					X.int_val /= Y.int_val;

					break;
				case OUT_EQ:
					if (X.stt == Y.stt) {
						if (X.stt == OUT_I4)
							if (X.int_val == Y.int_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_R8) 
							if (X.dbl_val == Y.dbl_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_QUOTE) {
							string a = X.str_val, b = Y.str_val;
							if (!X.string_val.empty()) a = X.string_val;
							if (!Y.string_val.empty()) b = Y.string_val;
							if (!a.compare(b)) X.int_val = 1;
							else X.int_val = 0;
						}
					} else {
						OUT_STR_FILE.append(string("ERROR. Comparison of different types"));
					}
					break;
				case OUT_NE:
					if (X.stt == Y.stt) {
						if (X.stt == OUT_I4)
							if (X.int_val != Y.int_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_R8)
							if (X.dbl_val != Y.dbl_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_QUOTE) {
							string a = X.str_val, b = Y.str_val;
							if (!X.string_val.empty()) a = X.string_val;
							if (!Y.string_val.empty()) b = Y.string_val;
							if (a.compare(b)) X.int_val = 1;
							else X.int_val = 0;
						}
					}
					else {
						OUT_STR_FILE.append(string("ERROR. Comparison of different types"));
				}
					break;
				case OUT_LT:
					if (X.stt == Y.stt) {
						if (X.stt == OUT_I4)
							if (X.int_val < Y.int_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_R8)
							if (X.dbl_val < Y.dbl_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_QUOTE) {
							string a = X.str_val, b = Y.str_val;
							if (!X.string_val.empty()) a = X.string_val;
							if (!Y.string_val.empty()) b = Y.string_val;
							if (a < b) X.int_val = 1;
							else X.int_val = 0;
						}
					} else {
						OUT_STR_FILE.append(string("ERROR. Comparison of different types"));
					}
					break;
				case OUT_GT:
					if (X.stt == Y.stt) {
						if (X.stt == OUT_I4)
							if (X.int_val > Y.int_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_R8)
							if (X.dbl_val > Y.dbl_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_QUOTE) {
							string a = X.str_val, b = Y.str_val;
							if (!X.string_val.empty()) a = X.string_val;
							if (!Y.string_val.empty()) b = Y.string_val;
							if (a > b) X.int_val = 1;
							else X.int_val = 0;
						}
					} else {
						OUT_STR_FILE.append(string("ERROR. Comparison of different types"));
					}
					break;

				case OUT_LE:
					if (X.stt == Y.stt) {
						if (X.stt == OUT_I4)
							if (X.int_val <= Y.int_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_R8)
							if (X.dbl_val <= Y.dbl_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_QUOTE) {
							string a = X.str_val, b = Y.str_val;
							if (!X.string_val.empty()) a = X.string_val;
							if (!Y.string_val.empty()) b = Y.string_val;
							if (a < b) X.int_val = 1;
							else X.int_val = 0;
						}
					}
					else {
						OUT_STR_FILE.append(string("ERROR. Comparison of different types"));
					}
					break;
				case OUT_GE:
					if (X.stt == Y.stt) {
						if (X.stt == OUT_I4)
							if (X.int_val >= Y.int_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_R8)
							if (X.dbl_val >= Y.dbl_val) X.int_val = 1;
							else X.int_val = 0;
						else if (X.stt == OUT_QUOTE) {
							string a = X.str_val, b = Y.str_val;
							if (!X.string_val.empty()) a = X.string_val;
							if (!Y.string_val.empty()) b = Y.string_val;
							if (a > b) X.int_val = 1;
							else X.int_val = 0;
						}
					}
					else {
						OUT_STR_FILE.append(string("ERROR. Comparison of different types"));
					}
					break;

				}
				exe.push(X);
				strip_pointer++;
				break;
			case OUT_LABEL:
				X.int_val = strip[strip_pointer].int_val;
				X.stt = OUT_I4;
				exe.push(X);
				strip_pointer++;
				break;
			case OUT_DEFL:
				exe.pop(X);
				strip_pointer++;
				break;
			case OUT_BZ:
				exe_pop(Y);
				exe_pop(X);
				if (X.int_val == 0) {
					j = strip.find_DEF(Y.int_val);
					if (j == -1) OUT_STR_FILE.append(string("exe label not found"));
					strip_pointer = j;
				}
				else {
					strip_pointer++;
				}
				break;
			case OUT_BR:
				exe_pop(Y);
				j = strip.find_DEF(Y.int_val);
				if (j == -1) OUT_STR_FILE.append(string("exe label not found"));
				strip_pointer = j;
				break;
			case OUT_WRITE:
				exe_pop(Y);
				if (Y.stt == OUT_R8)
					OUT_STR_FILE.append(to_string(Y.dbl_val).append("\n"));
				if (Y.stt == OUT_I4)
					OUT_STR_FILE.append(to_string(Y.int_val).append("\n"));
				if (Y.stt == OUT_QUOTE) {
					if (!Y.string_val.empty())
						OUT_STR_FILE.append(Y.string_val).append("\n");
					else
						OUT_STR_FILE.append(Y.str_val).append("\n");
				}
				strip_pointer++;
				break;



			}

			if (++it_counter > MAX_IT) {
				OUT_STR_FILE.append(string("exe deadlock"));
			}
		}
	}
	
	// выводит операционные символы со стека
	stack_t clear_stack() {
		stack_t s;
		while ((s = sta.top()) > SYM_LAST) {
			s = sta.pop();
			out((sttype)s);
		}
		return s;
	}
};
