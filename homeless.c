#include <stdio.h>

int main()
{
    char text[1000];

    FILE *input = fopen("input.txt", "r");

    if (input == NULL)
    {
        printf("Cannot open input.txt\n");
        return 1;
    }

    int characters = 0;
    int characters_without_spaces = 0;
    int words = 0;
    int sentences = 0;
    int vowels = 0;

    int letters[26] = {0};

    fgets(text, 1000, input);
    fclose(input);

    FILE *output = fopen("analysis.txt", "w");

    if (output == NULL)
    {
        printf("Cannot create analysis.txt\n");
        return 1;
    }

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        // Characters
        characters++;

        // Characters without spaces
        if (c != ' ')
        {
            characters_without_spaces++;
        }

        // Words
        if (c == ' ')
        {
            words++;
        }

        // Sentences
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }

        // Vowels
        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' ||
            c == 'O' || c == 'U')
        {
            vowels++;
        }

        // Lowercase letters
        if (c >= 'a' && c <= 'z')
        {
            letters[c - 'a']++;
        }

        // Uppercase letters
        if (c >= 'A' && c <= 'Z')
        {
            letters[c - 'A']++;
        }
    }

    // Last word
    if (characters > 0)
    {
        words++;
    }

    // Find most frequent letter
    int max = 0;
    char most_frequent = 'a';

    for (int i = 0; i < 26; i++)
    {
        if (letters[i] > max)
        {
            max = letters[i];
            most_frequent = 'a' + i;
        }
    }

    // Results
    fprintf(output, "\n--- Text Analysis ---\n");

    fprintf(output, "Characters: %d\n", characters);

    fprintf(output, "Characters without spaces: %d\n",
            characters_without_spaces);

    fprintf(output, "Words: %d\n", words);

    fprintf(output, "Sentences: %d\n", sentences);

    fprintf(output, "Vowels: %d\n", vowels);

    fprintf(output, "\nLetter frequency:\n");

    for (int i = 0; i < 26; i++)
    {
        fprintf(output, "%c = %d\n", 'a' + i, letters[i]);
    }

    fprintf(output, "\nMost frequent letter: %c\n", most_frequent);

    fprintf(output, "It appears %d times.\n", max);

    fclose(output);

    return 0;
}
