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

void printTextToMorse(std::string userInput){
    for (int i = 0; i < userInput.length(); i++){ // Looping through the full line of input
        if (isalpha(userInput[i])){ // If its a letter
            std::cout << (morseCodeChars[(int)toupper(userInput[i]) - 65]) << ' ';
        } else if (isdigit(userInput[i])){ // If its a number
            std::cout << (morseCodeChars[(int)userInput[i] - 22]) << ' ';
        } else if (userInput[i] == ' '){ // If its a space
            std::cout << "    ";
        } else { // If its punctuation
            std::cout << "STOP";
        }
    }
}

void printMorseToText(){
    std::string userInput = "";
    std::string textString = "";

    std::cout << "Enter Morse Code to be converted:" << std::endl;
    std::cout << "Enter one letter per line, hitting enter when the letter is complete\n" \
                "Enter an s for the space, and STOP for the period\n" \
                "Normal puctuation can be inputted as well, enter q to convert\n" << std::endl;

    while (1){
        std::cin >> userInput;
        if (toupper(userInput[0]) == 'Q'){ // Quit
            break;
        } else if (toupper(userInput[0]) == 'S'){ // Space
            textString += ' ';
        } else if (userInput[0] != '-' && userInput[0] != '.'){ // Non morse code character
            textString += userInput[0];
        } else {
            for (int i = 0; i < 36; i++){
                if (userInput == morseCodeChars[i]){
                    if (i <= 25){ // Letter
                        textString += (char)(i + 65);
                        break;
                    } else if (i >= 26){ // Number
                        textString += (char)(i + 22);
                        break;
                    }
                }
            }
            //std::cout << "Invalid morse code character" << std::endl;
        }
    }
    std::cout << "The converted string is: " << std::endl;
    std::cout << textString << std::endl;
}

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

        printTextToMorse(userInput);

    } else if (userChoice == '2'){ // Morse to text
        printMorseToText();
    } else {
        std::cout << "Invalid option. Please Try again." << std::endl;
    }
}
