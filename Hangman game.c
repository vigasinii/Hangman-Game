#include <stdio.h>
#include <string.h>

#define MAX_GUESSES 6

int main() {
    char word[20];
    char guess[20];
    int wrong_guesses = 0;

    printf("Enter the word to guess: ");
    scanf("%s", word);

    int word_length = strlen(word);
    char hidden[word_length + 1];
    for (int i = 0; i < word_length; i++) {
        hidden[i] = '_';
    }
    hidden[word_length] = '\0';

    while (wrong_guesses < MAX_GUESSES) {
        printf("Guess a letter: ");
        scanf("%s", guess);

        int match = 0;
        for (int i = 0; i < word_length; i++) {
            if (guess[0] == word[i]) {
                hidden[i] = guess[0];
                match = 1;
            }
        }

        if (!match) {
            wrong_guesses++;
        }

        printf("%s\n", hidden);

        if (!strcmp(hidden, word)) {
            printf("Congratulations! You've guessed the word!\n");
            break;
        }
    }

    if (wrong_guesses == MAX_GUESSES) {
        printf("Sorry, you've reached the maximum number of wrong guesses. The word was %s\n", word);
    }

    return 0;
}
