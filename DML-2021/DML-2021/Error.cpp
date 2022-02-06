#include "Error.h"
namespace Error
{
	// серии ошибок:	0 -- 99 - системные ошибки 
	//					100 -- 119 - ошибки файлового характера 
	//					200 -- 219 - ошибки лексического характера 
	//					300 -- 319 - ошибка синтаксического характера 
	//					600 -- 619 - ошибки семантического характера
	ERROR errors[ERROR_MAX_ENTRY] =
		{
			ERROR_ENTRY(0, "[Системная ошибка] Недопустимый код ошибки"),
			ERROR_ENTRY(1, "[Системная ошибка] Системный сбой"),
			ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
			ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
			ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
			ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
			ERROR_ENTRY(100, "[Файловая ошибка] Параметр -in должен быть задан"),
			ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
			ERROR_ENTRY(104, "[Файловая ошибка] Превышена длина входного параметра"),
			ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
			ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
			ERROR_ENTRY(110, "[Файловая ошибка] Ошибка при открытии файла с исходным кодом (-in)"),
			ERROR_ENTRY(111, "[Файловая ошибка] Недопустимый символ в исходном файле (-in)"),
			ERROR_ENTRY(112, "[Файловая ошибка] Ошибка при создании файла протокола (-log)"),
			ERROR_ENTRY_NODEF(113), ERROR_ENTRY_NODEF(114), ERROR_ENTRY_NODEF(115),
			ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
			ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
			ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
			ERROR_ENTRY(200, "[Лексическая ошибка] Запрещенный символ в исходном файле (-in)"),
			ERROR_ENTRY(201, "[Лексическая ошибка] Размер таблицы лексем превышен"),
			ERROR_ENTRY(202, "[Лексическая ошибка] Переполнение таблицы лексем"),
			ERROR_ENTRY(203, "[Лексическая ошибка] Размер таблицы идентификаторов превышен"),
			ERROR_ENTRY(204, "[Лексическая ошибка] Переполнение таблицы идентификаторов"),
			ERROR_ENTRY(205, "[Лексическая ошибка] Неизвестная последовательность символов"),
			ERROR_ENTRY_NODEF(206), ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
			ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250),
			ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
			ERROR_ENTRY(300, "[Семантическая ошибка] Имеется не закрытый строковый литерал"),
			ERROR_ENTRY(301, "[Семантическая ошибка] Имеется более одной точки входа в main"),
			ERROR_ENTRY(302, "[Семантическая ошибка] Не имеется точки входа в main"),
			ERROR_ENTRY(303, "[Семантическая ошибка] Превышен размер строкового литерала"),
			ERROR_ENTRY(304, "[Семантическая ошибка] Объявление переменной без ключевого слова var"),
			ERROR_ENTRY(305, "[Семантическая ошибка] Необъявленный идентификатор"),
			ERROR_ENTRY(306, "[Семантическая ошибка] Объвление переменной без указания типа"),
			ERROR_ENTRY(307, "[Семантическая ошибка] Попытка реализовать существующую функцию"),
			ERROR_ENTRY(308, "[Семантическая ошибка] Объявление функции без указания типа"),
			ERROR_ENTRY(309, "[Семантическая ошибка] Несовпадение типов передаваемых параметров функции"),
			ERROR_ENTRY(310, "[Семантическая ошибка] Несоответствие арифметических операторов"),
			ERROR_ENTRY(311, "[Семантическая ошибка] Невозможно деление на ноль"),
			ERROR_ENTRY(312, "[Семантическая ошибка] Несоответсвие типов данных"),
			ERROR_ENTRY(313, "[Семантическая ошибка] Несоответсвие открытых и закрытых скобок в выражении"),
			ERROR_ENTRY(314, "[Семантическая ошибка] Функция возвращает неверный тип данных"),
			ERROR_ENTRY(315, "[Семантическая ошибка] Несоответствие количества передаваемых параметров функции"),
			ERROR_ENTRY_NODEF(316), ERROR_ENTRY_NODEF(317),
			ERROR_ENTRY_NODEF(318), ERROR_ENTRY_NODEF(319),
			ERROR_ENTRY_NODEF10(320), ERROR_ENTRY_NODEF10(330), ERROR_ENTRY_NODEF10(340), ERROR_ENTRY_NODEF10(350), ERROR_ENTRY_NODEF10(360),
			ERROR_ENTRY_NODEF10(370), ERROR_ENTRY_NODEF10(380), ERROR_ENTRY_NODEF10(390),
			ERROR_ENTRY_NODEF100(400),
			ERROR_ENTRY_NODEF10(500), ERROR_ENTRY_NODEF10(510), ERROR_ENTRY_NODEF10(520), ERROR_ENTRY_NODEF10(530), ERROR_ENTRY_NODEF10(540),
			ERROR_ENTRY_NODEF10(550), ERROR_ENTRY_NODEF10(560), ERROR_ENTRY_NODEF10(570), ERROR_ENTRY_NODEF10(580), ERROR_ENTRY_NODEF10(590),
			ERROR_ENTRY(600, "[Синтаксическая ошибка] Неверная структура программы"),
			ERROR_ENTRY(601, "[Синтаксическая ошибка] Отсутствует список параметров функции"),
			ERROR_ENTRY(602, "[Синтаксическая ошибка] Ошибка в параметрах функции"),
			ERROR_ENTRY(603, "[Синтаксическая ошибка] Отсутствует тело функции"),
			ERROR_ENTRY(604, "[Синтаксическая ошибка] Недопустимое выражение"),
			ERROR_ENTRY(605, "[Синтаксическая ошибка] Отсутствует тело условия"),
			ERROR_ENTRY(606, "[Синтаксическая ошибка] Неверная конструкция в теле функции"),
			ERROR_ENTRY(607, "[Синтаксическая ошибка] Ошибка в условном выражении"),
			ERROR_ENTRY(608, "[Синтаксическая ошибка] Ошибка в вызове функции"),
			ERROR_ENTRY(609, "[Синтаксическая ошибка] Ошибка в арифметическом выражении"),
			ERROR_ENTRY(610, "[Синтаксическая ошибка] Ошибка в списке параметров при вызове функции"),
			ERROR_ENTRY(611, "[Синтаксическая ошибка] Ошибка в арифметическом выражении"),
			ERROR_ENTRY(612, "[Синтаксическая ошибка] Неверная конструкция в теле условия"),
			ERROR_ENTRY_NODEF(614), ERROR_ENTRY_NODEF(615), ERROR_ENTRY_NODEF(616), ERROR_ENTRY_NODEF(617), ERROR_ENTRY_NODEF(618), ERROR_ENTRY_NODEF(619),
			ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630), ERROR_ENTRY_NODEF10(640), ERROR_ENTRY_NODEF10(650),
			ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670), ERROR_ENTRY_NODEF10(680), ERROR_ENTRY_NODEF10(690),
			ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)};
	ERROR geterror(int id)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
		{
			return errors[id];
		}
		else
		{
			return errors[0];
		}
	}
	ERROR geterrorin(int id, int line = -1, int col = -1)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
		{
			errors[id].inext.col = col;
			errors[id].inext.line = line;
			return errors[id];
		}
		else
		{
			return errors[0];
		}
	}
}