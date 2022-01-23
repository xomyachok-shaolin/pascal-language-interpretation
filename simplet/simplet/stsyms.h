// 2019 ReVoL Primer Template
// stsyms.h
// ������� ��������

// ������� �����������
#define ST_EXISTS -2
// ������� ����������
#define ST_NOTFOUND -3

// ������ ������� ��������
typedef sttoken stsym;

// ������� ��������
template <int N>
class stsyms {
private:
    // ������� ��������
    stsym st[N];
    // �������
    int count;
    // �������
    int depth;
public:
    // �����������
    stsyms() {
        count = 1;
        depth = 0;
        st[0].stt = TOK_EOT;
        st[0].str_val[0] = '$';
    }
    // ����������
    ~stsyms() {
        printf("stsyms: size=%d, depth=%d.\n", N, depth - 1);
    }
    // ���������� ���������� ���������
    int size(void) {
        return count - 1;
    }
    // ���������� ����� ������� � �������
    int find(stsym& tok) {
        for (int i = 1; i < count; i++) {
            if (strcmp(tok.str_val, st[i].str_val) == 0) {
                return i;
            }
        }
        return ST_NOTFOUND;
    }
    // ��������� ������ � �������
    int insert(stsym tok) {
        if (count >= N) throw "stsyms::insert table overflow";
        if (find(tok) == ST_NOTFOUND) {
            st[count++] = tok;
            if (depth < count) depth = count;
            return count;
        } else {
            return ST_EXISTS;
        }
    }
    // ���������� ������
    stsym & operator [] (int index) {
        if (index < 0 || index >= count) throw "stsyms::operator[] invalid index";
        return st[index];
    }
};
