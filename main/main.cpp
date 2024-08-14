#include <iostream>
#include <stdio.h>
#include <time.h>

const int maxNumber = 100;

char Menu() {
    char input = ' ';
    std::cout << "\nSpielmenü: \n\n(S) Spiel starten\n(B) Beenden\n\n";
    std::cout << "Eingabe: ";
    std::cin >> input;
    system("cls");
    return input;
}

int GetUserGuess() {
    int guess = 0;
    std::cout << "Deine Vermutung: ";
    std::cin >> guess;
    return guess;
}

bool ValidateUserGuess(int guess, int rightResult) {
    if(guess == rightResult) {
        std::cout << "Dein Versuch: Die Zahl " << guess << " ist richtig! Gut gemacht!" << "\n\n";
        return true;
    }
    else if(guess < rightResult) {
        std::cout << "Die gesuchte Zahl ist größer als dein Versuch: " << guess << ".\n\n";
        return false;
    }
    else if(guess > rightResult) {
        std::cout << "Die gesuchte Zahl ist kleiner als dein Versuch: " << guess << ".\n\n";
        return false;
    }
    else {
        std::cout << "Ein Fehler ist unterlaufen, die Eingabe: '" << input << "' wird nicht erkannt.\nBitte versuche es erneut.\n\n";
        return false;
    }
}

void RunGame() {
    int randomNumber = rand() % maxNumber + 1;
    int guess = 0;
    int tries = 0;
    std::cout << "Die gesuchte Zahl ist zwischen " << 1 << " und " << maxNumber << " (Anmerkung: Auch die beiden Zahlen sind mitinkludiert.)\n\n";
    do {
        guess = GetUserGuess();
        tries ++;
    }
    while (!ValidateUserGuess(guess, randomNumber));
    std::cout << "Du hast '" << tries <<"' Versuche gebraucht.\n\n";
}

void RunMenu() {

    while (true) {
        char input = Menu();
        if (input == 'S' || input == 's')
            RunGame();
        else if (input == 'B' || input == 'b')
            break;
        else
            std::cout << "Die Eingabe: '" << input << "' wurde leider nicht erkannt.\nBitte erneut eine Taste eingeben.\n\n";
    }
}

int main()
{
    std::cout << "Willkommen bei Guess ’n’ Vad.\n\nDas einfache Zahlenratespiel ist von Vadenimo in der Programmiersprache C++ entwickelt worden.\nBesonderer Dank geht an Pilzschaf für seine C++-Tutorials raus!\nBitte beim Raten keine Buchstaben verwenden, sonst spinnt das Programm!\n";

    srand(time(NULL));
    RunMenu();

    return 0;
}