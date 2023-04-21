#include <iostream>
#include <string>

struct {
  const char morseTranslation[39] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890  ";
  const char * morseCodeList[37] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----"," "};
} MorseDictionary;

int sizeOfList;

std::string* lineArray(std::string line)
    {
        std::string * list = new std::string[100];
        int nrIndex = 0;
        char c, lastc;
        for (int i = 0; i <= line.length(); i++)
        {
            c = line[i];
            if (c == ' ') {
                nrIndex++;
                if(lastc == c == ' ') {
                     list[nrIndex] += c;   
                }
            }
            else
                list[nrIndex] += c;
            lastc = c;
        }
        sizeOfList = nrIndex;
        return list;
    }

std::string morseTranslator(std::string line) {
    std::string translation = "";
    std::string * list;
    list = lineArray(line);

  
    int index = 0;
    int sizeOfMorseCodeList = 37;
    for(int i = 0; i < sizeOfList; i++)
    {
        std::cout<<i<<std::endl;
        for(index = 0; index < sizeOfMorseCodeList; index++)
        {
            if (MorseDictionary.morseCodeList[index] == list[i]) 
                break;
            //std::cout<<index<<std::endl;
        }
        translation += MorseDictionary.morseTranslation[index];
    }
    return translation;
}

int main() {
  std::string line;
  while (getline(std::cin, line)) {
    std::cout << morseTranslator(line);  
  }
}
