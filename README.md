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
- ### front()
```ruby
reference front();
const_reference front() const;
```
- ### back()
```ruby
reference back();
const_reference back() const;
```
- ### rbegin(),
```ruby 
reverse_iterator rbegin() noexcept;
const_reverse_iterator rbegin() const noexcept;
```
- ### rend()
```ruby
reverse_iterator rend() noexcept;
const_reverse_iterator rend() const noexcept;
```
- ### reserve()
 ```ruby
template<class T>
void vector<T>::reserve(size_t mem) {
	if (mem <= cap) return;
	if (cap > max_size()) {
		throw new std::length_error("max length exceeded");
	}
	cap = mem;
	//_reallocate();
}
```
