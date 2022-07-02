#include <iostream>

#include <thread> // библиотека для многопоточности

#include <chrono>

#include <math.h> 

using namespace std;

void DoWork(int& a)
{

	this_thread::sleep_for(chrono::milliseconds(3000)); // имитация длительного процесса обработки данных (3000 milliseconds)

	cout << "ID потока = \t" << this_thread::get_id() << "\t ==========\t" << "DoWork STARTED\t==========\t " << endl;

	this_thread::sleep_for(chrono::milliseconds(5000)); // имитация длительного процесса обработки данных (5000 milliseconds) 

	a = a * 2;

	// this_thread::sleep_for(chrono::milliseconds(1000));

	cout << "ID потока = \t" << this_thread::get_id() << "\t ==========\t" << "DoWork STOPPED\t==========\t " << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int q = 5;

	thread t(DoWork, std::ref/*ссылкаб результат работы через ссылку */(q)); // передача 2 парметром

	// DoWork(q);


	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока =" << this_thread::get_id() << "\tmain" << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	t.join(); // либо detach(); 
	cout << q << endl;

	return 0;
}


