### Storing git credentials

$ git config credential.helper store

Then the next time you are asked for credentials they will be stored in plain text in a file.

### Xcode

mkdir -p build
cd build
cmake -G Xcode ../source

### Bibliography

- https://en.cppreference.com/w/cpp/language/user_literal
- https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique
- https://en.cppreference.com/w/cpp/named_req/LiteralType
- https://en.cppreference.com/w/cpp/string/basic_string/operator""s
- https://stackoverflow.com/questions/27345284/is-it-possible-to-declare-constexpr-class-in-a-header-and-define-it-in-a-separat
