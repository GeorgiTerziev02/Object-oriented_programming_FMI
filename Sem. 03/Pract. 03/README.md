# Двоични файлове/Binary Files

**Задача 1**:
Да се напише структура, която съхранява информация за доставка на пица. <br />
Структурата да съдържа: <br />
 * цена на доставката (число с плаваща запетая); <br />
 * адрес на доставката с максимална дължина 25 символа 


Да се създаде масив от доставки - списък с поръчки. <br />
Да се имплементират функции, които позволяват съхраняването и изчитането на информацията за поръчките от двоичен файл. <br />
Да се сортират поръчките в масива по адрес на доставка и да се запише в нов двоичен файл. <br />

Разгледайте съдържанието на този файл като използвате за целта подходящ Hex Editor: https://en.wikipedia.org/wiki/Hex_editor

* Бонус: Разширете логиката, като имплементирате функционалност за манипулация на доставки - добавяне, отпчеатване на конзолата, съхраняване в human-readable файлове (.txt или .csv), etc...


**Задача 2:**                     
След като Стойчо успешно завърши първи курс на ФМИ, той беше готов да започне работа. <br />
Но понеже работодателите, търсещи неговите невероятни умения, бяха повече от очакваното, <br />
той реши да изтрие имейла си и да направи собствена система, чрез която да получава покани за работа. <br />
     
Създайте структура, описваща обява за работа. Структурата трябва да съдържа: <br />
1. Име на фирмата. То трябва да е с максимална дължина от 25 символа. <br />
2. Брой на програмистите, с които той ще работи в екип. <br />
3. Брой на дните платен отпуск през годината. <br />
4. Сума, която ще му бъде изплатена след успешно завършване на проекта (от тип long long) <br />
    
- Създайте функция, която прочита n на брой заявки от стандартния вход. <br />
Заявките се запазват в двоичен файл, като ако във файла вече има информация,тя не се изтрива. <br />
- Създайте функция void filterOffers(const char* filePath, long long minSalary), <br />
която приема адрес на файл, от който четем заявките и минимална заплата. <br />
Извежда на стандартния изход всички обяви за работа, които предлагат поне толкова пари, колкото са подадени като аргумент. <br />
-Създайте функция, bool existOffer(const char* filePath, const char* name), <br />
която проверява дали дадена фирма е пратила покана за работа.
     
Бонус №1:
Създайте void perfectOffer(const char* filePath, int maxCoworkers, int minVacancyDays, int minSalary),
която извежда във файл всички обяви, които отговарят точно на изискванията на Стойчо.

Бонус №2:
Създайте система, която работи чрез следните заявки:
1. a <оферта> - добавя оферта за работа
2. i - показва всички оферти
3. s <име на фирма> - връща дали фирмата съществува
4. f <число> - извежда всички обяви, за които заплатата е по - висока от
числото
5. q - изход от системата
