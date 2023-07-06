#include <stdio.h>
#include <string.h>
#include <ctype.h>

int delimit(char *kalimat, char *delimiter)
{
  int count = 0;
  int length = strlen(kalimat);

  // Iterate through the characters of the sentence
  for (int i = 0; i < length; i++)
  {
    if (!isalpha(kalimat[i])) // Check if the character is not alphabetic
    {
      delimiter[count] = kalimat[i]; // Store the non-alphabetic character in the delimiter array
      count++;
    }
  }
  return count; // Return the count of delimiters
}

int main()
{
  char kalimat[100];
  char delimiter[100];
  char arrKata[100][100];
  int jumlahKata = 0;

  printf("Masukkan kalimat: ");
  gets(kalimat); // Input the sentence

  delimit(kalimat, delimiter); // Call the delimit function to identify the delimiters

  char *kata = strtok(kalimat, delimiter); // Tokenize the sentence using the delimiters

  // Store each tokenized word in the arrKata array
  while (kata != NULL)
  {
    strcpy(arrKata[jumlahKata], kata);
    jumlahKata++;
    kata = strtok(NULL, delimiter);
  }

  printf("Kata-kata dalam array:\n");

  // Print the words stored in the arrKata array
  for (int i = 0; i < jumlahKata; i++)
  {
    printf("%s\n", arrKata[i]);
  }
  return 0;
}
