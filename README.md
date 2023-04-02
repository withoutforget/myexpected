# myexpected
| Function  | Description |
| ------------- | ------------- |
| ```cpp expected(T&& obj)```  | Constructor for first(value) type  |
| ```cpp expected(U&& obj)```  | Constructor for second(error) type  |
| ```cpp expected(const expected<T, U>& rhs)``` | Copy constructor |
| ```cpp expected operator=(const expected<T, U>& rhs)``` | Copy operator |
| ```cpp expected(expected<T, U>&& rhs)``` | Move consturctor |
| ```cpp expected& operator=(expected<T, U>&& rhs)``` | Move operator |
| ```cpp ~expected()``` | Destructor |
| ```cpp bool has_value(),  bool has_value() const``` | true if value is initializated(you returned value type) |
| ```cpp bool has_error(),  bool has_error() const ```| true if error is initializated(you returned error type) |
| ```cpp T& get_value(), T get_value() const ```| Lvalue Ref to value, UB if has_value() is false |
| ```cpp U& get_error(), U get_error() const ```| Lvalue Ref to error, UB if has_error() is false |
| ```cpp bool set_value(T& val) ```| If set_value(T&) returns true, then val == value, else nothing |
| ```cpp bool set_error(U& err)``` | If set_error(U&) returns true, then err = error, else nothing |
| ```cpp int set(T& val, U& err) ```| If set(T&,U&) returned 0, then val == value, else err == error |
| ```cpp template<class F, class ... Args> expected& and_then_v(F&& lambda, Args&& ... args)``` | Lambda invokes with args and last argument is Ref to value-value |
| ```cpp template<class F, class ... Args>    expected& if_error_v(F&& lambda, Args&& ... args)``` | Lambda invokes with args and last arguments is Ref to error-value |
| ```cpp template<class F, class ... Args>    expected& and_then(F&& lambda, Args&& ... args)``` | Lambda invokes with args |
| ```cpp template<class F, class ... Args>    expected& if_error(F&& lambda, Args&& ... args)``` | Lambda invokes with args |
    
