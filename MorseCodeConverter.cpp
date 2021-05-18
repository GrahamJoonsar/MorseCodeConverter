#include <iostream>
#include <string>

/*********************************************************************************************************\
 * Author: Graham Joonsar                                                                                *
 *                                                                                                       *
 * Description:                                                                                          *
 * The purpose of this program is to convert characters to morse code and morse code to characters.      *
 * The converting from text to morse code is the fastest, as I base the index of the morse code          *
 * equivalents in the morseCodeChars array, so I don't have to use a switch statement                    *
 *                                                                                                       *
 * Here is the source I used:                                                                            *
 * https://en.wikipedia.org/wiki/Morse_code                                                              *
\*********************************************************************************************************/
// There are 36 total morse code combinations
const char* morseCodeChars[36] = {
    // Letters
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--..",  // Z
    // Numbers
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
};

int main(){
    char userChoice;
    std::string userInput = "";
    std::cout << "Text to Morse (1) | Morse to Text (2)" << std::endl;
    userChoice = getchar();
    system("CLS"); // Clear screen
    if (userChoice == '1') { // Text to morse
        std::cout << "Enter text to be converted:" << std::endl;
        // Getting the full line of Input, Probably an easier way to do this
        while (std::getline(std::cin, userInput)){
            if (userInput.length() > 0){
                break;
            }
        }

        for (int i = 0; i < userInput.length(); i++){
            if (isalpha(userInput[i])){
                std::cout << (morseCodeChars[(int)toupper(userInput[i]) - 65]) << ' ';
            } else if (isdigit(userInput[i])){
                std::cout << (morseCodeChars[(int)userInput[i] - 22]) << ' ';
            } else if (userInput[i] == ' '){
                std::cout << "    ";
            } else {
                std::cout << "STOP";
            }
        }
    } else if (userChoice == '2'){ // Morse to text
        std::cout << "Not finished" << std::endl;
    } else {
        std::cout << "Invalid option. Please Try again." << std::endl;
    }
}