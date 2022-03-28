#include "RabbitDataBase.h"
#include "ReadUtils.h"
#include <iostream>
#include <fstream>
using namespace std;

RabbitDataBase::RabbitDataBase() {
  numRabbits = 0;
  read();
}

void RabbitDataBase::read() {
    ifstream rabbitFile("rabbits.txt");
    numRabbits = 0;
    while(rabbitFile.peek() != EOF && numRabbits < MAX_RABBITS) {
        rabbitArray[numRabbits].readFromFile(rabbitFile);
        numRabbits++;
    }
}

void RabbitDataBase::printR(ostream &out, bool printIndex) {
  for (int index = 0; index < MAX_RABBITS; index++) {
        if (rabbitArray[index].getValid()) {
            if (printIndex) {
                out << "Index " << index << ": ";
            }
            rabbitArray[index].print(out);
        } 
    }
}

void RabbitDataBase::save() {
  ofstream out("rabbits.txt");
  RabbitDataBase::printR(out,false);
}


void RabbitDataBase::remove() {
  int index = 0;
    do {
        index = readInt("Enter an index to remove between 0 and 500: ");
    }while (index < 0 || index >= MAX_RABBITS);
  //makeInvalid
  rabbitArray[index].getValid() == false;
}

void RabbitDataBase::add() {
  for (int index = 0; index < MAX_RABBITS; index++) {
        if (rabbitArray[index].getValid() == false) {
            rabbitArray[index].readFromUser();
            return;
        }
    }
    cout << "Too many rabbits! No room for more!" << endl;
}