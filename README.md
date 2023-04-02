# myexpected
| Function  | Description |
| ------------- | ------------- |
| ```java expected(T&& obj){}```  | Constructor for first(value) type  |
| ```java expected(U&& obj){}```  | Constructor for second(error) type  |
| ```java expected(const expected<T, U>& rhs){}``` | Copy constructor |
| ```java expected operator=(const expected<T, U>& rhs){}``` | Copy operator |
| ```java expected(expected<T, U>&& rhs){}``` | Move consturctor |
| ```java expected& operator=(expected<T, U>&& rhs){}``` | Move operator |
| ```java ~expected(){}``` | Destructor |
| ```java bool has_value(),  bool has_value() const {}``` | true if value is initializated(you returned value type) |
| ```java bool has_error(),  bool has_error() const {}```| true if error is initializated(you returned error type) |
| ```java T& get_value(), T get_value() const {}```| Lvalue Ref to value, UB if has_value() is false |
| ```java U& get_error(), U get_error() const {}```| Lvalue Ref to error, UB if has_error() is false |
| ```java bool set_value(T& val) {}```| If set_value(T&) returns true, then val == value, else nothing |
| ```java bool set_error(U& err) {}``` | If set_error(U&) returns true, then err = error, else nothing |
| ```java int set(T& val, U& err) {}```| If set(T&,U&) returned 0, then val == value, else err == error |
| ```java template<class F, class ... Args> expected& and_then_v(F&& lambda, Args&& ... args){}``` | Lambda invokes with args and last argument is Ref to value-value |
| ```java template<class F, class ... Args>    expected& if_error_v(F&& lambda, Args&& ... args){}``` | Lambda invoke with args and last argument is Ref to error-value |
| ```java template<class F, class ... Args>    expected& and_then(F&& lambda, Args&& ... args){}``` | Lambda invokes with args |
| ```java template<class F, class ... Args>    expected& if_error(F&& lambda, Args&& ... args){}``` | Lambda invokes with args |
