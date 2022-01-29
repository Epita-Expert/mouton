# Compatibility

- Nous n'avons pas testé sur Windows, uniquement sur ubuntu/macos.
- Pour macos nous avons créé un CMakeList spécifique.
- Le CMakeList de base fonctionne très bien sur Ubuntu en ajoutant la ligne suivante :

```c++
add_executable(SDL_part1 main.cpp application.cpp ground.cpp animal.cpp sheep.cpp wolf.cpp helper.cpp)
```

# Compile

Pour Compiler ce projet

```
cd Project_SDL_Part1_base
cmake .
make
```

# Run
```
./SDL_part1 5 5 1000
```
