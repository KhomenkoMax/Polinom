Реалізація класа поліном на С++. Клас вміщує в себе деякі алгебраїчні дії з поліномами.
Зокрема, в програмі можна власноруч задавати поліноми та їх степені, також програма виконує такі дії з поліномами:
1)перегружає оператори >>,<<,-,+,*.=.
2)виконує необхідні дії відносно вище зазначених операторів, виводить результат на екран.
3) також всередині коду програми можна задати перший поліном та його степінь, потім при запуску прграми в користувача
запитується степінь другого полінома та відповідні коефіцієнти(їх вносити вручну).

Планується зробити:
програма повинна містити функцію-метод знаходження інтегралу від многочлена, яка повертає новий поліном, який є невизначеним інтегралом від заданого.
Напр: 3/2*x^2+5/3*x^3+5/4*x^4
Щоб це зробити потрібно створити новий обєкт класу поліном (можна на основі заданого), до кожного степеня додати 1 (змістити елементи масиву, що містить коефіцієнти поліному, на 1 елемент в бік збільшення степеня), та поділити коефіцієнт на значення отриманого степеня, після чого повернути отриманий обєкт класу (наприклад return res; )
Функція повинна повернути об'єкт класу поліном та містити відповідні коеф (вірно).
Приклад використання:
double mas[]={1,2,3};
polynom a(mas, 3);
polynom b;
b=a.integral();
b.show();
Функцію для знаходження інтегралу від многочлена вже розробили, програма її компілює. 
З'явилась нова ПРОБЛЕМА при виводженні результату на екран. Виводяться ті самі коефіцієнти, що й при множенні одного 
многочлена на інший, а не результат інтегрування.
Якщо степінь інтегрованого многочлена задати меншою,ніж та, що отримана при множенні двох многочленів, то на екран 
програма виведе коефіцієнти, які були задані у вихідному многочлені.


