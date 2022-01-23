// 2019 ReVoL Primer Template
// sa2RD.h
// синтаксический анализатор

class syntaxan {
public:
    // конструктор
    syntaxan(lexan * lex, FILE * parse_stream, FILE * error_stream) {
        this->lex = lex;
        this->parse_stream = parse_stream;
        this->error_stream = error_stream;
    }

    // рекурсивный спуск
    int parse(void) {
        double result = 0;
        if (!next_token()) return 0;
        if (E(result))
            fprintf(parse_stream, "%g\nsyntaxan: success.\n\n", result);
        else
            fprintf(error_stream, "syntaxan: failure.\n\n");

        return 1;
    }
private:
    // ссылка на лексический анализатор
    lexan * lex;
    // поток результата
    FILE * parse_stream;
    // поток сообщений
    FILE * error_stream;
    // текущий токен
    sttoken tok;
    // возвращает очередной токен
    int next_token() {
        return lex->next_token(tok);
    }
    int is_plus() { if (tok.stt == TOK_ADD) return 1; return 0; }
    int is_sub() { if (tok.stt == TOK_SUB) return 1; return 0; }
    int is_mult() { if (tok.stt == TOK_MUL) return 1; return 0; }
    int is_div() { if (tok.stt == TOK_DIV) return 1; return 0; }

    int P(double &value) {

        sttoken temp = tok;
        next_token();

        if (temp.stt == TOK_ADD || temp.stt == TOK_MUL) return 0;

        if (temp.stt == TOK_LP) {
            if (!E(value)) return 0;
            if (tok.stt != TOK_RP) return 0;
            next_token();
        } else if (temp.stt == TOK_I4) {
            value = temp.int_val;
            return 1;
        } else if (temp.stt == TOK_R8) {
            value = temp.dbl_val;
            return 1;
        }
        else 
            return 0;
    }
    int T(double &value) {
        double mul = 0;
        if (!P(value)) return 0;
        while (is_mult()) {
            next_token();
            if (!P(mul)) return 0;
            value *= mul;
        }
        while (is_div()) {
            next_token();
            if (!P(mul)) return 0;
            value /= mul;
        }
        return 1;
    }
    int E(double &value) {
        double add = 0;
        if (!T(value)) return 0;
        while (is_plus()) {
            next_token();
            if (!T(add)) return 0;
            value += add;
        }
        while (is_sub()) {
            next_token();
            if (!T(add)) return 0;
            value -= add;
        }
        return 1;
    }
};
