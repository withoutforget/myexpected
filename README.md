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

