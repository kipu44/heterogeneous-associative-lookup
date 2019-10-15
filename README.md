### Storing git credentials

```
$ git config credential.helper store
```

Then the next time you are asked for credentials they will be stored in plain text in a file.

### Xcode

```
$ mkdir -p ../build;
$ cd ../build;
$ cmake -G Xcode ../source;
```

### Bibliography

- https://en.cppreference.com/w/cpp/container/map/find
- https://en.cppreference.com/w/cpp/utility/functional/less
