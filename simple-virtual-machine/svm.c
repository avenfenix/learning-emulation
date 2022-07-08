#include <stdbool.h>
#include <stdio.h>

typedef enum {
    A, B, C, D, E, F, PC, SP,
    NUM_OF_REGISTERS
} Registers;

typedef enum {
    PSH,        // Agrega un elemento al STACK
    ADD,        // Saca y suma 2 elementos del STACK y devuelve el resultado al STACK
    MUL,        // Saca y multiplica 2 elems del STACK y retorna al STACK la *.
    POP,        // Saca un elemento del STACK y lo *printea*
    SET,        // Setea registros
    HLT         // Termina programa
} InstructionSet;

const int program[] = {
    PSH, 5,     // Agrega un 5 al STACK
    PSH, 6,     // Agrega un 6 al STACK
    ADD,        // Suma los valores ( 5 + 6 )
    POP,        // Saca el valor de la suma del STACK.
    PSH, 20,
    PSH, 10,
    MUL,
    POP,
    HLT         // Exit()
};

int registers[NUM_OF_REGISTERS];

//#define sp (registers[SP])
//#define pc (registers[PC])

int pc = 0; // Program counter
int sp = -1; // Stack pointer; -1 means it's empty
int stack[256];
bool running = true;

int fetch(){
    return program[pc];
}

void eval(int instr){
    switch (instr){
        case HLT: {
            running = false;
            break;
        } 
        case PSH: {
            sp++;
            stack[sp] = program[++pc];
            break;
        }
        case POP: {
            int val_popped = stack[sp--];
            printf("popped %d\n", val_popped);
            break;
        }
        case ADD: {
            int a = stack[sp--];
            int b = stack[sp --];
            int result = b + a;
            sp++;
            stack[sp] = result;
            break;
        }
        
        case MUL: {
            int a = stack[sp--];
            int b = stack[sp --];
            int result = b*a;
            sp++;
            stack[sp] = result;
        }
    }
}



int main() {
    while (running){
        eval(fetch());
        pc++;
    }
    
    return 0;
}