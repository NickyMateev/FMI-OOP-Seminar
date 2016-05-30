#pragma once
#include <iostream>

const double RESIZE_COEF = 1.5;
const int DEFAULT_CAP = 8;

template <typename K, typename V>
class Dictionary
{
private:
  K* keys;
  V* values;

  int count;
  int capacity;

  void resize();
  void copy(const Dictionary& other);
  void destroy();
  void sort();
  void shift(int index);
public:
  Dictionary();
  Dictionary(const Dictionary& other);
  Dictionary& operator=(const Dictionary& other);
  ~Dictionary();

  void add(const K key, const V value);
  void remove(const K& key);

  V getValue(const K key) const;
  template <typename C, typename P>
  friend std::ostream& operator<<(std::ostream& os, const Dictionary<C,P>& obj);
};

template <typename K, typename V>
void Dictionary<K, V>::resize()
{
  int newCap = this->capacity * RESIZE_COEF;

  K* newKeys = new K[newCap];
  V* newValues = new V[newCap];

  for(int i  = 0; i < this->capacity; i++)
  {
    newKeys[i] = this->keys[i];
    newValues[i] = this->values[i];
  }

  destroy();

  this->capacity = newCap;
  this->keys = newKeys;
  this->values = newValues;
}

template <typename K, typename V>
void Dictionary<K, V>::copy(const Dictionary& other)
{
  this->capacity = other.capacity;
  this->count = other.count;

  this->keys = new K[other.capacity];
  this->values = new V[other.capacity];

  for(int i = 0; i < other.capacity; i++)
  {
    this->keys[i] = other.keys[i];
    this->values[i] = other.values[i];
  }
}

template <typename K, typename V>
void Dictionary<K, V>::destroy()
{
  delete[] keys;
  delete[] values;
}

template <typename K, typename V>
void Dictionary<K, V>::sort()
{
  for(int i = 0; i < this->count - 1; i++)
  {
    for(int j = 0; j < this->count - 1 - i; j++)
    {
      if(this->keys[j] > this->keys[j + 1])
      {
        K tempKey = this->keys[j];
        this->keys[j] = this->keys[j + 1];
        this->keys[j + 1] = tempKey;

        V tempValue = this->values[j];
        this->values[j] = this->values[j + 1];
        this->values[j + 1] = tempValue;
      }
    }
  }
}

template <typename K, typename V>
void Dictionary<K, V>::shift(int index)
{
  for(; index < this->count - 1; index++)
  {
    keys[index] = keys[index + 1];
    values[index] = values[index + 1];
  }
}

template <typename K, typename V>
Dictionary<K, V>::Dictionary()
{
  this->capacity = DEFAULT_CAP;
  this->count = 0;

  this->keys = new K[DEFAULT_CAP];
  this->values = new V[DEFAULT_CAP];
}

template <typename K, typename V>
Dictionary<K, V>::Dictionary(const Dictionary& other)
{
  copy(other);
}

template <typename K, typename V>
Dictionary<K, V>& Dictionary<K, V>::operator=(const Dictionary& other)
{
  if(this != &other)
  {
    destroy();
    copy(other);
  }
  return *this;
}

template <typename K, typename V>
Dictionary<K, V>::~Dictionary()
{
  destroy();
}

template <typename K, typename V>
void Dictionary<K, V>::add(const K key, const V value)
{
  if(this->count == this->capacity)
    resize();

  this->keys[this->count] = key;
  this->values[this->count] = value;

  this->count++;
}

template <typename K, typename V>
void Dictionary<K, V>::remove(const K& key)
{
  for(int i = 0; i < this->count; i++)
  {
    if(this->keys[i] == key)
    {
      shift(i);
      this->count--;

      break;
    }
  }
}

template <typename K, typename V>
V Dictionary<K, V>::getValue(const K key) const
{
  for(int i = 0; i < this->count; i++)
    if(this->keys[i] == key)
      return this->values[i];

  return V();
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const Dictionary<K, V>& obj)
{
  Dictionary<K, V> dict(obj);
  dict.sort();

  for(int i = 0; i < dict.count; i++)
    os << "(" << dict.keys[i] << ", " << dict.values[i] << ")" << std::endl;

  return os;
}
