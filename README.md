# Задача 1 (Луны)

 * Десериализация простых значений
 
 Имеется структура *Moon* необходимо десериализовать значения, которые находятся в файле SolSystemMoons.json
 
 *Структура Moon*
 ```yaml
struct Moon {
    string name;
    string parentPlanet
    long square;
    int openingYear;
};
 ```
 
 После десериализации необходимо вывести полученные значения в виде таблицы
 
```
| Name     | The planet | The square | Year of the opening |
|----------|------------|------------|---------------------|
| Moon     | Earth      | 38000000   | 0                   |
|----------|------------|------------|---------------------|
| Phobos   | Mars       | 1600       | 1877                |
|----------|------------|------------|---------------------|
| Ganimed  | Jupiter    | 5262       | 1610                |
|----------|------------|------------|---------------------|
| Kallisto | Jupiter    | 4821       | 1610                |
|----------|------------|------------|---------------------|
| IO       | Jupiter    | 41910000   | 1610                |
|----------|------------|------------|---------------------|
| Miranda  | Uranus     | 698710     | 1948                |
```