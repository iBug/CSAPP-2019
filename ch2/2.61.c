// File: 2.61.c
// Author: iBug

// Use (1 && value) as a replacement of (value != 0)
int A(int x) {
    return 1 && x;
}

int B(int x) {
    return 1 && ~x;
}

int C(int x) {
    return 1 && (x & 0xFF);
}

int D(int x) {
    return 1 && (x & 0xFF000000);
}

