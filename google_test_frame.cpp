
/*
https://github.com/google/googletest/tree/main
*/
#include <stddef.h>
#include <setjmp.h>
#include <stdlib.h>

typedef struct{
    int output;
    int a;
    int b;
    int (*TestMFunc)(int,int);
}T_EMTest;

T_EMTest * addFunc(int(*TestMFunc)(int,int),int a,int b,int output){
    T_EMTest *m_EMTest = (T_EMTest*)malloc(sizeof(T_EMTest));
    m_EMTest->a =a;
    m_EMTest->b =b;
    m_EMTest->output =output;
    m_EMTest->TestMFunc =TestMFunc;
    return m_EMTest;
}

void runEMTest(T_EMTest *p_EMTest){
    if(p_EMTest != NULL){
        int count = p_EMTest->TestMFunc(p_EMTest->a,p_EMTest->b);
        if (count == p_EMTest->output){
            printf("success\n");
        }
        else{
            printf("fail %d != %d\n",count,p_EMTest->output);
        }
        free(p_EMTest);
    }
}



int sum(int a,int b){
    return a+b;
}

int main(){
    T_EMTest * m_EMTest = addFunc(sum,1,2,3);
    runEMTest(m_EMTest);
}