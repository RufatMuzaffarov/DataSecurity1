# Защита программ и данных (Задание 1)
## Описание задания
Реализовать программу на языке C\C++, которая должна включать
следующую последовательность действий:
1. Запрос какой-либо информации от пользователя (логин, номер телефона, номер какого-либо документа, ключ любого вида и т.д.)
2. Произведение манипуляций по разработанному алгоритму с введённой пользователем информацией для генерации ответа на ключевой вопрос.
3. Запрос ключа от пользователя и сравнение его со сгенерированным ключом на этапе 2.
4. Выдача результата по принципу: сгенерированный и алгоритмом и введённый пользователем ключи совпадают – TRUE-> Поздравление или доступ к какой либо информации; Не совпадают – ошибка.

При реализации программы должны быть соблюдены условия:
1. Внутри программы должен быть какой-либо алгоритм преобразования данных для генерации ключевой информации. Например, сложение по модулю кодов букв из таблицы ASCII, Подсчёт количества букв в логине пользователя и умножение его на текущий год, запросы системного времени или к каким-либо заранее определённым файлам.
2. Должны быть реализованы меры защиты от отладки: специальные функции языка, искусственное усложнение кода, директивы препроцессора, условия сборки компилятора, упаковщики и т. д.

Результатом выполнения задания должна быть разработанная программа в виде исходных кодов, make/cmake файла сборки или инструкции по сборке в случае применения дополнительных средств или специальных скриптов. Документация к программе с описанием алгоритма работы, описанием входных и выходных данных и применяемых в программе мер защиты.

## Описание работы программы
Программа запрашивает логин, являющийся любой комбинацией символов без пробелов. Затем запрашивается пароль, который впоследствии сравнивается с созданным на основе логина ключом, с помощью функции phash. В зависимости от результата сравнения выдается соотвествующий текст с разрешением или запретом на вход.

### Описание алгоритма генерации ключа
Введенный логин превращается в свое численное представление на основе таблицы ASCII. Затем происходит разделение на пары символов (в случае нечетного количества символов в числовом значении происходит добавление 0 в конец). Далее полученные пары берутся по модулю в диапазоне от 48 до 122 и затем приобретают свое символьное значение таблицы ASCII. 

## Примеры работы программы
```
 --Your login:
     Rufat
   Your password:
     dontknow
   Access denied! Invalid password!
   
--Your login:
    Mark@2
  Your password:
    2F;Y7pb
  Access allowed!
```
## Примененные меры защиты
В качестве мер защиты были использованы:
* Весь текст вывода на экран в самом коде приобрел нечитаемый вид с помощью сдвига значений таблицы ASCII.
* Были созданы некоторые макросы C++ для констант: порядок и длина длина шага для сдвига выводимого текста;
* Были добавлены "бессмысленные" операции с числами и строками, многоуровневые условные операторы, бесполезные буферы для хранения переменных;
* При сборке файла можно также использовать флаги: -s для удаления таблицы .symtab, -O3 для оптимизация и ухудшение читабельности;
