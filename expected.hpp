#include <utility>
// T is value type, U is error type.
template<typename T, typename U>
class expected {
private: // shared_ptr slow down for 2000ns
    T* value;
    U* error;
    bool is_error;
public: // ctors and dctors
    expected(T&& obj) : value(new T(obj)), error(nullptr) { is_error = false; }
    expected(U&& obj) : error(new U(obj)), value(nullptr) { is_error = true; }
    expected(const expected<T, U>& rhs) {
        value = new T(*rhs.value);
        error = new U(*rhs.error);
        is_error = rhs.is_error;
    }
    expected operator=(const expected<T, U>& rhs) {
        value = new T(*rhs.value);
        error = new U(*rhs.error);
        is_error = rhs.is_error;
        *this;
    }
    expected(expected<T, U>&& rhs) noexcept {
        std::swap(value, rhs.value);
        std::swap(error, rhs.error);
        std::swap(is_error, rhs.is_error);
    }
    expected& operator=(expected<T, U>&& rhs) noexcept {
        std::swap(value, rhs.value);
        std::swap(error, rhs.error);
        std::swap(is_error, rhs.is_error);
        return *this;
    }
    ~expected() {
        delete error;
        delete value;
    }
public: // getters
    bool has_value() { return !is_error; }
    bool has_error() { return is_error; }
    T& get_value() { return *value; }
    U& get_error() { return *error; }
public: // const getters
    bool has_value() const { return !is_error; }
    bool has_error() const { return is_error; }
    T get_value() const { return *value; }
    U get_error() const { return *error; }
public: // setters?
    bool set_value(T& val) {
        if (has_value())
            return false;
        val = *value;
        return true;
    }
    bool set_error(U& err) {
        if (has_error())
            return false;
        err = *error;
        return true;
    }
    int set(T& val, U& err) {
        and_then_v([&](T& v, T& rv) -> void {v = rv; }, val);
        if_error_v([&](U& e, U& re) -> void {e = re; }, err);
        return has_error();
    }
public: // stuff with lambda
    template<class F, class ... Args>
    expected& and_then_v(F&& lambda, Args&& ... args) {
        if (has_value())
            (std::forward<F>(lambda)(std::forward<Args>(args)..., *value));
        return *this;
    }
    template<class F, class ... Args>
    expected& if_error_v(F&& lambda, Args&& ... args) {
        if (has_error())
            (std::forward<F>(lambda)(std::forward<Args>(args)..., *error));
        return *this;
    }
    template<class F, class ... Args>
    expected& and_then(F&& lambda, Args&& ... args) {
        if (has_value())
            (std::forward<F>(lambda)(std::forward<Args>(args)...));
        return *this;
    }
    template<class F, class ... Args>
    expected& if_error(F&& lambda, Args&& ... args) {
        if (has_error())
            (std::forward<F>(lambda)(std::forward<Args>(args)...));
        return *this;
    }
};
