#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int get_sentence_count(string sentence);
int get_word_count(string sentence);
int get_letter_count(string sentence);
int main(void)
{

string sentence = get_string("Text: ");

int sentenceCount = get_sentence_count (sentence);
int wordCount = get_word_count(sentence);
int letterCount = get_letter_count(sentence);
printf("Sentence count: %i\n", sentenceCount);
printf("Word Count: %i\n", wordCount);
printf("Letter count: %i\n", letterCount);

float lettersPerHundredWords = ((float)letterCount / (float)wordCount) * 100;
// printf("%f\n", lettersPerHundredWords);
float sentencesPerHundredWords = ((float)sentenceCount / (float)wordCount) * 100;
// printf("%f\n", sentencesPerHundredWords);

float index = (0.0588 * (lettersPerHundredWords) - (0.296 * sentencesPerHundredWords) - 15.8);
index = round(index);
// printf("%f\n", index);


if (index < 1) {
    printf("Before Grade 1\n");
    }

    else if (index >= 16) {
        printf("Grade 16+\n");
    }

    else {
        printf("Grade %i\n", (int)index);
    }
}

// Calculates and returns sentence count.
int get_sentence_count(string sentence)
{

int sentenceCounter = 0;
for (int i = 0, n = strlen(sentence); i < n; i++)
    {
        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?') {
            sentenceCounter++;
        }
    }
    return sentenceCounter;
}

// Calculates and returns number of words in sentence.
int get_word_count(string sentence)
{

int wordCounter = 1;
for (int i = 0, n = strlen(sentence); i < n; i++)
    {
        if (sentence[i] == ' ') {
            wordCounter++;
        }
    }

    return wordCounter;
}

// Calculates and returns letter count.
int get_letter_count(string sentence)
{

int letterCounter = 0;
for (int i = 0, n = strlen(sentence); i < n; i++)
    {
        if ((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z')) {
            letterCounter++;
        }
    }

    return letterCounter;
}
