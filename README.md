# Run
- Nous n'avons pas testé sur Windows, uniquement sur ubuntu/macos.
- Pour macos nous avons créé un CMakeList spécifique.
- Le CMakeList de base fonctionne très bien sur Ubuntu en ajoutant la ligne suivante :

```c++
add_executable(SDL_part1 main.cpp application.cpp ground.cpp animal.cpp sheep.cpp wolf.cpp helper.cpp)
```
