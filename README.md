# Class description
```cpp
template<class T, class U>
class expected
```
```T``` is value type, ```U``` is error type.
| Function  | Description |
| ------------- | ------------- |
| ```expected(T&& obj)```  | Constructor for first(value) type  |
| ```expected(U&& obj)```  | Constructor for second(error) type  |
| ```expected(const expected<T, U>& rhs)``` | Copy constructor |
| ```expected operator=(const expected<T, U>& rhs)``` | Copy operator |
| ```expected(expected<T, U>&& rhs)``` | Move consturctor |
| ```expected& operator=(expected<T, U>&& rhs)``` | Move operator |
| ```~expected()``` | Destructor |
| ```bool has_value(),  bool has_value() const``` | true if value is initializated(you returned value type) |
| ```bool has_error(),  bool has_error() const ```| true if error is initializated(you returned error type) |
| ```T& get_value(), T get_value() const ```| Lvalue Ref to value, UB if has_value() is false |
| ```U& get_error(), U get_error() const ```| Lvalue Ref to error, UB if has_error() is false |
| ```bool set_value(T& val) ```| If set_value(T&) returns true, then val == value, else nothing |
| ```bool set_error(U& err)``` | If set_error(U&) returns true, then err = error, else nothing |
| ```int set(T& val, U& err) ```| If set(T&,U&) returned 0, then val == value, else err == error |
| ```template<class F, class ... Args> expected& and_then_v(F&& lambda, Args&& ... args)``` | Lambda invokes with args and last argument is Ref to value-value |
| ```template<class F, class ... Args> expected& if_error_v(F&& lambda, Args&& ... args)``` | Lambda invokes with args and last arguments is Ref to error-value |
| ```template<class F, class ... Args> expected& and_then(F&& lambda, Args&& ... args)``` | Lambda invokes with args |
| ```template<class F, class ... Args> expected& if_error(F&& lambda, Args&& ... args)``` | Lambda invokes with args |


# Examples
## First example:
```cpp 
expected<int, double> foo(int x) { // create function that returns expected 
    if (x % 2)
        return 1; // return int 
    else
        return 3.14; // return double
}
void TEST1() {
    int i1 = 0, i2 = 0;
    double d1 = 0, d2 = 0;
    foo(7)
        .and_then_v([&](int& i, int v) -> void {i = v; }, i1) // if foo returns int, then  i1 = returned value
        .if_error_v([&](double& d, double e) -> void {d = e; }, d1); // if foo returns double, then d1 = returned value
    foo(8)
        .and_then_v([&](int& i, int v) -> void {i = v; }, i2) // if foo returns int, then  i1 = returned value
        .if_error_v([&](double& d, double e) -> void {d = e; }, d2); // if foo returns double, then d2 = returned value

    print("i1 = ", i1, "\ni2 = ", i2, '\n');
    print("d1 = ", d1, "\nd2 = ", d2, '\n');
}
```
## Second example:
```cpp
void TEST2() { 
    int i1 = 0, i2 = 0;
    double d1 = 0, d2 = 0;

    auto t1 = foo(7); // get returned expected class
    if (t1.has_value()) // if returned int
        i1 = t1.get_value();        // then i1 = returned value
    else 
        d1 = t1.get_error();       // if returned double(error-type) and d1 = returned value

    auto t2 = foo(8); // the same comments

    if (t2.has_value())
        i2 = t2.get_value();
    else 
        d2 = t2.get_error();       

    print("i1 = ", i1, "\ni2 = ", i2, '\n');
    print("d1 = ", d1, "\nd2 = ", d2, '\n');
}
```
### Third example:
```cpp
  void TEST3() {
      int i1 = 0, i2 = 0;
      double d1 = 0, d2 = 0;
      int pos1 = foo(7).set(i1, d1); // if returned int, then i1 = returned value, else d1 = returned value
      int pos2 = foo(8).set(i2, d2); // same actions
      print("pos1 = ", pos1, "\npos2 = ", pos2, '\n');
      print("i1 = ", i1, "\ni2 = ", i2, '\n');
      print("d1 = ", d1, "\nd2 = ", d2, '\n');
  }    

```
