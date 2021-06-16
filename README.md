# VU_3uzd
# Spartos analizė
|  | 10000 | 100000 | 1000000 | 10000000 | 100000000 |
| --- | --- | --- | --- | --- | ---|
| std::vector | 0,000906s | 0,007754s | 0,69352s | 0,318624s | 3,54173s |
| Vector | 0,000891s | 0,00358s | 0,49165s | 0,27418s | 3,02941s |

# Atminties perskirstymai
|  | 100000000 |
| --- | --- |
| std::vector | 27 | 
| Vector | 44 |

# Funkcijų pavyzdžiai
- ### front(), back()
```ruby
	vector<int> vec;
vec.push_back(78);
vec.push_back(16);

vec.front()-=vec.back();
std::cout << "vec.front() lygus: " << vec.front()<< "\n";
```
- ### rbegin(), rend()
```ruby
vector <int> v(10);
	int i=0;
	for (vector<int>::reverse_iterator rit=v.rbegin(); rit!=v.rend(); ++rit)
        *rit=++i;
    std::cout << "Vector susideda is siu elementu: ";
    for (vector<int>::reverse_iterator it=v.rbegin(); it!=v.rend(); ++it)
std::cout<< *it<< " ";
std::cout << "\n";
```
- ### reserve()
  ```ruby
  int sz1;
     	vector<int> vector1;
  sz1 = vector1.capacity();
  std::cout << "making vector1 grow:\n";
  for (int i=0; i<100; ++i) {
    vector1.push_back(i);
    if (sz1!=vector1.capacity()) {
      sz1 = vector1.capacity();
      std::cout << "capacity changed: " << sz1 << '\n';
    }
  }
  std::cout << '\n';

  vector<int> vector2;
  sz1 = vector2.capacity();
  vector2.reserve(100);   // this is the only difference with vector1 above
  std::cout << "making vector2 grow:\n";
  for (int i=0; i<100; ++i) {
    vector2.push_back(i);
    if (sz1!=vector2.capacity()) {
      sz1= vector2.capacity();
      std::cout << "capacity changed: " << sz1 << '\n';
    }
  }
```
