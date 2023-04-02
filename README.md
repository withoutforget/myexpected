# myexpected
| Function  | Description |
| ------------- | ------------- |
| expected(T&& obj)  | Constructor for first(value) type  |
| expected(U&& obj)  | Constructor for second(error) type  |
| expected(const expected<T, U>& rhs) | Copy constructor |
| expected operator=(const expected<T, U>& rhs) | Copy operator |
| expected(expected<T, U>&& rhs) | Move consturctor |
| expected& operator=(expected<T, U>&& rhs) | Move operator |
| ~expected() | Destructor |
| bool has_value(),  bool has_value() const | true if value is initializated(you returned value type) |
| bool has_error(),  bool has_error() const | true if error is initializated(you returned error type) |
| T& get_value(), T get_value() const | Lvalue Ref to value, UB if has_value() is false |
| U& get_error(), U get_error() const | Lvalue Ref to error, UB if has_error() is false |
| bool set_value(T& val) | If set_value(T&) returns true, then val == value, else nothing |
| bool set_error(U& err) | If set_error(U&) returns true, then err = error, else nothing |
| int set(T& val, U& err) | If set(T&,U&) returned 0, then val == value, else err == error |
|  template<class F, class ... Args>
 expected& and_then_v(F&& lambda, Args&& ... args) | Lambda invokes with args and last argument is reference to value-value |
 | template<class F, class ... Args>    expected& if_error_v(F&& lambda, Args&& ... args) | Lambda invokes with args and last arguments is reference to error-value |
| template<class F, class ... Args>    expected& and_then(F&& lambda, Args&& ... args) | Lambda invokes with args |
|template<class F, class ... Args>    expected& if_error(F&& lambda, Args&& ... args) | Lambda invokes with args |
    
