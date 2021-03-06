#include "SFML/Graphics.hpp"
#include "const.h"
using namespace sf;
int main(){
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGTH), "SFML Works!");
	window.setFramerateLimit(60);
	//создание игровых объектов
	float r = 30.f;
	CircleShape circle(r, 100);
	circle.setPosition(400.f - r, 300.f - r);
	float speedx = 10.5f;
	float speedy = 15.5f;
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// 1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		// 2 update (изменение игровых объектов)
		//Движение по экрану со скорости speedx
		circle.move(speedx,speedy);
		if (circle.getPosition().x + 2 * r >= WINDOW_WIDTH) {
			speedx = -speedx;
		}
		if (circle.getPosition().x <= 0) {
			speedx = -speedx;
		}
		if (circle.getPosition().y + 2 * r >= WINDOW_HEIGTH) {
			speedy = -speedy;
		}
		if (circle.getPosition().y <= 0) {
			speedy = -speedy;
		}
		// 3 Отрисовка
		// 3-1 Очистка окна
		window.clear(Color(198, 25, 49,0));
		// 3-3 Рисуем игровые объекты ( в памяти!)
		window.draw(circle);
		//3-3 отображение на экран
		window.display();
	}
	return 0;
}