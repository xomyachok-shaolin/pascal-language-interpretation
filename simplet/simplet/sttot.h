// 2019 ReVoL Primer Template
// sttot.h
// ������� �������������

// ������-�������
#define INVAL 0   // ������������
#define DIGIT 1   // �����
#define ALPHA 2   // �����
#define OPERA 3   // ��������
#define CHDOT 4   // �����
#define QUOTE 5   // ������� �������
#define SINQU 6   // ��������� �������
#define UNDER 7   // ���� �������������
#define SLASH 8   // ����
#define WHITE 9   // ���������� ������

/* character conversion table */
unsigned char TOT[256] = { /* (c) 2003 ReVoL */
    /* ����������� ������� */
    /* 00     01     02     03     04     05     06     07     08     TAB    LF     0B     0C     CR     0E     0F */
    INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, WHITE, INVAL, INVAL, INVAL, WHITE, INVAL, INVAL,
    /* 10     11     12     13     14     15     16     17     18     19     1A     1B     1C     1D     1E     1F */
    INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL,

    /* ������, �����, ����� */
    /* 20     !      "      #      $      %      &      '      (      )      *      +      ,      -      .      /  */
    WHITE, INVAL, QUOTE, INVAL, INVAL, INVAL, INVAL, INVAL, OPERA, OPERA, OPERA, OPERA, OPERA, OPERA, CHDOT, SLASH,
    /*  0       1      2      3      4      5      6      7      8      9     :      ;      <      =      >      ? */
    DIGIT, DIGIT, DIGIT, DIGIT, DIGIT, DIGIT, DIGIT, DIGIT, DIGIT, DIGIT, INVAL, INVAL, OPERA, OPERA, OPERA, INVAL,

    /* ��������� �����, ����� */
    /*  @      A      B      C      D      E      F      G      H      I      J      K      L      M      N      O */
    INVAL, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,
    /*  P      Q      R      S      T      U      V      W      X      Y      Z      [      \      ]      ^      _ */
    ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, INVAL, INVAL, INVAL, INVAL, UNDER,

    /* �������� �����, ����� */
    /*  `      a      b      c      d      e      f      g      h      i      j      k      l      m      n      o */
    INVAL, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,
    /*  p      q      r      s      t      u      v      w      x      y      z      {      |      }      ~        */
    ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, INVAL, INVAL, INVAL, INVAL, INVAL,

    /* ������ �������� ASCII - ������� ��� ������ ����������������� ������� */
    INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL,
    INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL,
    INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL,
    INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL,
    INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL,
    INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL,
    INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL,
    INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL, INVAL
};
