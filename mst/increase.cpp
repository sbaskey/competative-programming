#include <bits/stdc++.h>
using namespace std;
int main ()
{
  int a, b, c[30], d, r = 0, d1; //Max bits here i kept is 30
  cout << " Enter the No of Data Bits you want to Enter : ";
  cin >> a;
while (a + r + 1 > pow (2, r))
    {
      r++;
    }
  cout << "No of data bits to be added " << r << " : Total Bits :" << a +
    r << endl;
cout << " Enter the Data Bits One by One :" << endl;
for (int i = 1; i <= a; ++i)
    cin >> c[i];
cout << endl << " Data bits entered : ";
for (int i = 1; i <= a; ++i)
    cout << c[i] << " ";
cout << endl;
int data[a + r];
  d = 0;
  d1 = 1;
for (int i = 1; i <= a + r; ++i)
    {
      if ((i) == pow (2, d))
 {
   data[i] = 0;
   ++d;
 }
      else
 {
   data[i] = c[d1];
   ++d1;
 }
    }
cout << " Data Bits are Encoded with Parity bits(0): ";

for (int i = 1; i <= a + r; ++i)
    cout << data[i] << " ";

}