#include <iostream>
#include <cstring>
using namespace std;

const int INIT_CAP = 64;

class Dictionary
{
  char** bgWords;
  char** engWords;
  size_t capacity;
  size_t wordsCount;
public:
  Dictionary();
  Dictionary(const char** _bgWords, const char** _engWords, size_t numOfWords);
  ~Dictionary();

  void AddWord(const char* bgWord, const char* engWord);
  void DeleteWord(const char* word);
  bool Search(const char* word) const;
  const char* Translate(const char* word) const;
};

void mystrcpy(char*& destination, const char* source)
{
  destination = new char[strlen(source) + 1];
  for(int i = 0; i <= strlen(source); i++)
    destination[i] = source[i];
}

Dictionary::Dictionary()
{
  capacity = INIT_CAP;
  bgWords = new char*[INIT_CAP];
  engWords = new char*[INIT_CAP];
  wordsCount = 0;
}

Dictionary::Dictionary(const char** _bgWords, const char** _engWords, size_t numOfWords)
{
  capacity = 2 * numOfWords;
  bgWords = new char*[capacity];
  engWords = new char*[capacity];
  wordsCount = numOfWords;

  for(int i = 0; i < wordsCount; i++)
  {
    mystrcpy(bgWords[i], _bgWords[i]);
    mystrcpy(engWords[i], _engWords[i]);
  }
}

Dictionary::~Dictionary()
{
  for(int i = 0; i < wordsCount; i++)
  {
    if(bgWords[i] != NULL)
      delete[] bgWords[i];

    if(engWords[i] != NULL)
      delete[] engWords[i];
  }

  delete[] bgWords;
  delete[] engWords;
}

void Dictionary::AddWord(const char* bgWord, const char* engWord)
{
  if(wordsCount == capacity)
  {
    cout << "The dictionary is full! Cannot add any more words." << endl;
    return;
  }

  mystrcpy(bgWords[wordsCount], bgWord);
  mystrcpy(engWords[wordsCount], engWord);
  wordsCount++;
}

void Dictionary::DeleteWord(const char* word)
{
  for(int i = 0; i < wordsCount; i++)
  {
    if((strcmp(word, bgWords[i]) == 0) || (strcmp(word, engWords[i]) == 0))
    {
      delete[] bgWords[i];
      delete[] engWords[i];

      // Method 1(swap deleted with last):
      bgWords[i] = bgWords[wordsCount - 1];
      engWords[i] = engWords[wordsCount - 1];

      delete[] bgWords[wordsCount - 1];
      delete[] engWords[wordsCount - 1];

      // Method 2(shift all elements):
      // for(int j = i; j < wordsCount - 1; j++)
      // {
      //    bgWords[j] = bgWords[j + 1];
      //    engWords[j] = engWords[j + 1];
      // }

      wordsCount--;
      return;
    }
  }
}

bool Dictionary::Search(const char* word) const
{
  for(int i = 0; i < wordsCount; i++)
  {
    if((strcmp(word, bgWords[i]) == 0) || (strcmp(word, engWords[i]) == 0))
      return true;
  }
  return false;
}

const char* Dictionary::Translate(const char* word) const
{
  for(int i = 0; i < wordsCount; i++)
  {
    if(strcmp(word, bgWords[i]) == 0)
      return engWords[i];

    if(strcmp(word, engWords[i]) == 0)
      return bgWords[i];
  }
}

int main()
{
  Dictionary dictionary;
  dictionary.AddWord("kola", "car");
  dictionary.AddWord("kotka", "cat");
  dictionary.AddWord("priroda", "nature");

  cout << "Is the word \"cat\" in the dictionary: ";
  if(dictionary.Search("cat"))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  dictionary.DeleteWord("cat");

   cout << "Is the word \"cat\" in the dictionary: ";
   if(dictionary.Search("cat"))
    cout << "Yes" << endl;
   else
    cout << "No" << endl;

  return 0;
}
