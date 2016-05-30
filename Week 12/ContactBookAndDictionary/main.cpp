#include "ContactBook.h"

int main()
{
  Dictionary<int, int> dict;
  dict.add(12, 2);
  dict.add(3, 4);
  dict.add(55, 6);
  dict.add(4, 7);

  std::cout << dict << std::endl;
  std::cout << dict.getValue(55) << std::endl;

  std::string str = "test", str2 = "test2";
  str = str2;
  std::cout << str << std::endl;

  char* name = "Nick";
  Contact c1(name, "123456789", "1");
  std::cout << c1 << std::endl;

  Contact cTest;
  std::cout << cTest << std::endl;

  ContactBook cb;
  cb.addContact(c1);
  std::cout << cb << std::endl;

  return 0;
}
