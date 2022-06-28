#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include <iomanip>
#include <string>
#include <cstring>
#include "ThirtyTwoBit.h"
using namespace std;


string ecall_func(){
    string x = "ecall";
    return x;
}

string r_type(unsigned int instWord){
    string x,b,c,d;
    unsigned int rd = (instWord >> 7) & 0x0000001F;
	unsigned int funct3 = (instWord >> 12) & 0x00000007;
	unsigned int rs1 = (instWord >> 15) & 0x0000001F;
	unsigned int rs2 = (instWord >> 20) & 0x0000001F;
	unsigned int funct7 = (instWord >> 25) & 0x0000007F;
	if (funct3 == 0){
		if (funct7 == 0){
    
                x = "add";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(rs2);
                x += "  x" + b + ",x" + c + ",x" + d;
		}
		else {    
                x = "sub";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(rs2);
                x += "  x" + b + ",x" + c + ",x" + d;
		}
	}
	else if (funct3 == 1){
    
                x = "sll";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(rs2);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else if (funct3 == 2){
    
                x = "add";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(rs2);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else if (funct3 == 3){
    
                x = "sltu";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(rs2);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else if (funct3 == 4){
                x = "xor";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(rs2);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else if (funct3 == 5){
		if (funct7 == 0){
    
                x = "srl";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(rs2);
                x += "  x" + b + ",x" + c + ",x" + d;
		}
		else {
                x = "sra";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(rs2);
                x += "  x" + b + ",x" + c + ",x" + d;

		}
	}
	else if (funct3 == 6){
                x = "or";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(rs2);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else if (funct3 == 7){
    
                x = "and";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(rs2);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else {
            x = "Instruction not found";        
	}
    return x;
}

string i_type(unsigned int instWord, unsigned int opcode){
    string x,b,c,d;
	unsigned int rd = (instWord >> 7) & 0x0000001F;
	unsigned int funct3 = (instWord >> 12) & 0x00000007;
	unsigned int rs1 = (instWord >> 15) & 0x0000001F;
	signed int imm = (instWord >> 20) & 0x00000FFF;
    if (opcode == 1100111){
        jalr_type(instWord);
    }
    else{
	if (funct3 == 0){
		
   
                x = "andi";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(imm);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else if (funct3 == 2){ 
                x = "slti";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(imm);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else if (funct3 == 3){
				x = "sltiu";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(imm);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else if (funct3 == 4){
				x = "xori";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(imm);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else if (funct3 == 6){
				x = "ori";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(imm);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else if (funct3 == 7){
				x = "andi";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(imm);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else {
		x = "Instruction not found";
	}
    }
    return x;
}



string i_type_load(unsigned int instWord){
    string x,b,c,d;
	unsigned int rd = (instWord >> 7) & 0x0000001F;
	unsigned int funct3 = (instWord >> 12) & 0x00000007;
	unsigned int rs1 = (instWord >> 15) & 0x0000001F;
	unsigned int imm = (instWord >> 20) & 0x0000001F;
    unsigned int funct7 = (instWord >> 25) & 0x0000007F;

	if (funct3 == 1){   
                x = "slli";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(imm);
                x += "  x" + b + ",x" + c + ",x" + d;
	}
	else if (funct3 == 5){
		if (funct7 == 0){
				x = "srli";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(imm);
                x += "  x" + b + ",x" + c + ",x" + d;
		}
		else {
				x = "srai";
                b = to_string(rd);
                c = to_string(rs1);
                d = to_string(imm);
                x += "  x" + b + ",x" + c + ",x" + d;
		}
	}
	else{
		x = "Instruction not found";
	}
    return x;
}

string jalr_type(unsigned int instWord){
    string x,b,c,d;
    unsigned int rd = (instWord >> 7) & 0x0000001F;
	unsigned int funct3 = (instWord >> 12) & 0x00000007;
	unsigned int rs1 = (instWord >> 15) & 0x0000001F;
	signed int imm = (instWord >> 20) & 0x00000FFF;
    x = "jalr";
    b = to_string(rd);
    c = to_string(rs1);
    d = to_string(imm);
    x += "  x" + b + ",x" + c + ",x" + d;
    return x;
}

void printing(unsigned int pc, string x){
    fstream final;
    final.open("output",ios::app);
    final << pc << x << "\n";
    final.close();
}