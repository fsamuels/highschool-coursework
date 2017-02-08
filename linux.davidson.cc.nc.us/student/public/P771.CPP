#include <iostream.h>

void convert(int decimalNumber, int base)
{
  if(decimalNumber > 0)
  {
    convert(decimalNumber / base, base);
    cout << decimalNumber % base;
  }
}

int main()
{
  for(int base = 2; base <= 10; base++)
  {
    cout << "99 base " << base << " = ";
    convert(99, base);
    cout << endl;
  }

  return 0;
}
