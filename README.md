# MIF (MetaInfo Framework)
Каркас для разработки веб-сервисов.

# Текущее состояние
Version 1.0.0 - in progress ...

# Возможности
- Разработка http веб-сервисов
- Взаимодействие микросервисов (RPC c воможностью маршалинга объектов межде микросервисами)
- Сериализация структур данных на базе рефлексии
- Работа с БД (пока не реализовано)
- Поддержка нескольких языков программирования (пока не реализовано)

# Поддержка языков программирования
- C++ - основной язык для разработки микросервисов на базе MIF. (Стандарт: C++11)
- Python - планитруется поддеркжка для обращения к модулям, разработанным на C++

# Платформа
- Linux
- Windows (планируется поддержка в будущем)

# Компилятор
- gcc версии не ниже 5.4
- clang (планируется поддержка)

# Сборка
Сборка осуществляется с помощью утилит cmake + make

Так как MIF зависит от других библиотек, то в связи с этим возможно несколько вариантов сборки.
- Сборки MIF с предварительной загрузкой всех необходимые библиотеки.
- Сборка с подгрузкой всех библиотек с GitHub в момент выполнения cmake + make
- Сборка с подгрузкой всех библиотек с собственного сервера в момент выполнения cmake + make (пока не реализовано)
- Сборка с установленными в систему библиотеками

Пример сборки с предварительной загрузкой всех необходимых библиотек

git clone https://github.com/tdv/mif.git  
cd mif  
./download_third_party.sh  
mkdir build  
cd build  
cmake ..  
make  

Сборка примеров осуществляется после сборки MIF библиотек
Пример:

cd mif/examples/hello_world  
mkdir build  
cd build  
cmake ..  
make  

Собранный пример может быть запущен в разных консолях

Сервер:

./helloworld_server

Клиент:

./helloworld_client

Для получения описания всех параметров запуска примеров нужно запустить приложение с параметром --help

# Установка
make install

# Примеры
- hello_world - пример простого взаимодействия клиента с сервером
- complex_type - пример, демонстрирующий возможность передачи пользовательских структур данных межеду компонентами
- inheritance - пример, демонстрирующий наследование интерфейсов (построение иерархий) и запрос интерфейсов из имеющихся экземпляров.
- http - пример веб-сервиса, с возможностью формировать ответы в виде текста, в формате json и выдавать html-страницы, а так же есть RPC (работа с объектами, как в других примерах MIF).
- visitor - пример, демонстрирующий маршалинг интерфейсов между компонентами. Передача указателя в другой процесс / компонент и вызов методов объекта по переданному указателю из другого процесса. На базе этого примера можно разрабатывать сервисы с поддержкой publish/subscribe.
