/**@mainpage Отчёт к Лабораторной работе №2 
 * @brief Методы программирования. Лабораторная работа №2. Недомолкин И. Э. СКБ201
 * @section intro Введение
 * Отчёт к лабораторной работе №2 по методам программирования. Включающий в себя документацию по коду сгенерированную doxygen, ссылку на репозиторий с кодом программы и результатами её работы, а так же графики. 
 * @section description Описание 
 * Для работы я брал данные сгенерированные в прошлый раз. Это txt файлы со строчками, каждая из которых представляет один объект, всего их в файлах 200/500/1 000/2 000/5 000/10 000/20 000/50 000/100 000/120 000/1 000 000/5 000 000
 * @section Link Исходный код программы
 * Ссылка на репозиторий Github с кодов, данными и результатами https://github.com/Nedomolkin-Ilya/Programming-Techniques-lab-2.
 * @section Image График
 * \image latex myplot1.png "Graph1"
 * \image latex myplot2.png "Graph2"
 */
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <map>
#include <iomanip>
#include <utility>

using namespace std;

long N;

struct date{
	int day;
	int mounth;
	int year;	
};

struct tim{
	int min;
	int hour;
	int day;
};

class train{
	public:
		
		void set_number(int a){
			/**
			 * @param a Какой номер задать поезду
			 */
			numb = a;
		}
		
		void set_date(int a, int b, int c){
			/**
			 * @param a Задать день даты отправления
			 * @param b Задать месяц даты отправления
			 * @param c Задать год даты отправления
			 */
			data.day = a;
			data.mounth = b;
			data.year = c;
		}

		void set_type(std::string a){
			/**
			 * @param a Задать название поезду
			 */
			type = a;
		}

		void set_time(int a, int b){
			/**
			 * @param a Здать час отправки поезда
			 * @param b Здать минуту отправки поезда
			 */ 
			vremy.hour = a;
			vremy.min = b;
		}

		void set_way(int a, int b){
			/**
			 * @param a Здать количество дней в пути
			 * @param b Здать количество часов в пути
			 */ 
			way.day = a;
			way.hour = b;
		}

		int get_number(){
			/**
			 * return Номер поезда
			 */
			return numb;
		}

		int get_date_d(){
			/**
			 * return День отправки поезда 
			 */
			return data.day;
		}

		int get_date_m(){
			/**
			 * return Месяц отправки поезда
			 */
			return data.mounth;
		}

		int get_date_y(){
			/**
			 * return Год отправки поезда
			 */
			return data.year;
		}

		std::string get_type(){
			/**
			 * return Тип поезда
			 */
			return type;
		}

		int get_time_h(){
			/**
			 * return Час отправки поезда
			 */
			return vremy.hour;
		}

		int get_time_mi(){
			/**
			 * return Минута отправки поезда
			 */
			return vremy.min;
		}

		int get_way_d(){
			/**
			 * return Дней в пути поезду
			 */
			return way.day;
		}

		int get_way_h(){
			/**
			 * return Часов в пути поезду
			 */
			return way.hour;
		}

		friend bool operator> (const train &first, const train &second);
    	friend bool operator<= (const train &first, const train &second);
 
	    friend bool operator< (const train &first, const train &second);
    	friend bool operator>= (const train &first, const train &second);

    	friend bool operator== (const train &first, const train &second);
    	friend bool operator!= (const train &first, const train &second);

	private:
		int numb;
		date data;
		std::string type;
		tim vremy;
		tim way;
};

bool operator >(const train &first, const train &second){
	if (first.type > second.type){
		return true;
	}
	if (first.data.year > second.data.year && first.type == second.type){
		return true;
	}if (first.data.mounth > second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.day > second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.hour > second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && 
		first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.min > second.vremy.min && first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && 
		first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.numb > second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.day > second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.hour > second.way.hour && first.way.day == second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && 
		first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}else{
		return false;
	}
}

bool operator >=(const train &first, const train &second){
	if (first.type > second.type){
		return true;
	}if (first.data.year > second.data.year && first.type == second.type){
		return true;
	}if (first.data.mounth > second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.day > second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.hour > second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && 
		first.data.year == second.data.year && first.type > second.type){
		return true;
	}if (first.vremy.min > second.vremy.min && first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && 
		first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.numb > second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.day > second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.hour > second.way.hour && first.way.day == second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && 
		first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth 
		&& first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.year == second.data.year && first.data.mounth == second.data.mounth && first.data.day == second.data.day && 
		first.vremy.hour == second.vremy.hour && first.vremy.min == second.vremy.min && first.numb == second.numb && 
		first.way.day == second.way.day && first.way.hour == second.way.hour && first.type == second.type){
		return true;
	}else{
		return false;
	}
}

bool operator <(const train &first, const train &second){
	if (first.type < second.type){
		return true;
	}
	if (first.data.year < second.data.year && first.type == second.type){
		return true;
	}if (first.data.mounth < second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.day < second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.hour < second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && 
		first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.min < second.vremy.min && first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && 
		first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.numb < second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.day < second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.hour < second.way.hour && first.way.day == second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && 
		first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}else{
		return false;
	}
}

bool operator <=(const train &first, const train &second){
	if (first.type < second.type){
		return true;
	}if (first.data.year < second.data.year && first.type == second.type){
		return true;
	}if (first.data.mounth < second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.day < second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.hour < second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && 
		first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.min < second.vremy.min && first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && 
		first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.numb < second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.day < second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.hour < second.way.hour && first.way.day == second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && 
		first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth 
		&& first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.year == second.data.year && first.data.mounth == second.data.mounth && first.data.day == second.data.day && 
		first.vremy.hour == second.vremy.hour && first.vremy.min == second.vremy.min && first.numb == second.numb && 
		first.way.day == second.way.day && first.way.hour == second.way.hour && first.type == second.type){
		return true;
	}else{
		return false;
	}
}

bool operator ==(const train &first, const train &second){
	if (first.data.year == second.data.year && first.data.mounth == second.data.mounth && first.data.day == second.data.day && 
		first.vremy.hour == second.vremy.hour && first.vremy.min == second.vremy.min && first.numb == second.numb && 
		first.way.day == second.way.day && first.way.hour == second.way.hour && first.type == second.type) return true;
}

bool operator !=(const train &first, const train &second){
	if (first.data.year != second.data.year or first.data.mounth != second.data.mounth or first.data.day != second.data.day or 
		first.vremy.hour != second.vremy.hour or first.vremy.min != second.vremy.min or first.numb != second.numb or 
		first.way.day != second.way.day or first.way.hour != second.way.hour or first.type != second.type) return true;
}

int RanNum(int min, int max){
	/**
	* @param min Минимально возможное рандомное значение
	* @param max Максимально возможное рандоюное значение
	* @return Рандомное значение из заданного диапозона
	*/ 
	int num = min + rand() % (max - min + 1);
	return num;
}

void generator(std::string name, int count, int nser){
	/**
	* @param name Имя создаваемого файла
	* @param count Число элементов которые будут созданы
	*/ 

	std::ofstream out;

	out.open(name);
	if (out.is_open()){
        for(int i = 0;i<count;i++){
        	int r = RanNum(1,3);
        	std::string Type_of_train;

        	if (r == 1){
        		Type_of_train = "Скорый";
        		int rand_num = RanNum(1,nser);
        		Type_of_train = Type_of_train + std::to_string(rand_num);
        	}if (r == 2){
        		Type_of_train = "Пассажирский";
        		int rand_num = RanNum(1,nser);
        		Type_of_train = Type_of_train + std::to_string(rand_num);
        	}if (r == 3){
        		Type_of_train = "Товарный";
        		int rand_num = RanNum(1,nser);
        		Type_of_train = Type_of_train + std::to_string(rand_num);
        	}

	        out << Type_of_train << ' ' << RanNum(1982,1984) << ' ' << RanNum(6,8) << ' ' << ' ' << RanNum(10,21) 
	        << ' ' <<RanNum(4,9) << ' ' << RanNum(0,59) << ' ' << RanNum(99,123) << ' ' << RanNum(0,2) 
	        << ' ' <<  RanNum(0,23) << std::endl;
    	}
    }
    out.close();
}


void insert(train* trains, long size){
	/**
	* @param trains Массив который должен быть отсортирован
	* @param size Размер массива
	*/ 
	for (long i=1;i<size;i++){
		for (long j=i;j>0 && trains[j-1]>trains[j];j--){
			train t = trains[j-1];
			trains[j-1]=trains[j];
			trains[j]=t;
		}
	}
}

void quick_sort(train* array, long low, long high){
	/**
	* @param array Массив над которым производиться сортировка
	* @param low Нижний элемент
	* @param high Верхний элемент
	*/ 
    long i = low;
    long j = high;
    train pivot;
    pivot = array[(i + j) / 2];
    train temp;

    while (i <= j){
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i <= j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low) quick_sort(array, low, j);
    if (i < high) quick_sort(array, i, high);
}

void read_file(std::string file_name, train* trains, int size){
	/**
	* @param file_name Имя файла из которого производить чтение
	* @param trains Массив куда производить чтение
	* @param size Количество считываемых данных
	*/ 
	std::ifstream is(file_name);
	if (is.is_open()){
		int d_date, m_date, y_date, h_time, m_time, number, d_way, h_way, i = 0;
		std::string Type_of_train;
		while((is >> Type_of_train >> y_date >>m_date >> d_date >> h_time >> m_time >> number >> d_way >> h_way) and (i < size)){
			trains[i].set_type(Type_of_train);
			trains[i].set_date(d_date, m_date, y_date);
			trains[i].set_time(h_time, m_time);
			trains[i].set_number(number);
			trains[i].set_way(d_way,h_way);
			i++;
		}
	}
}

void write_in_file(std::string file_name, train* trains, int size){
	/**
	* @param file_name Куда записать данные
	* @param trains Массив откуда данные брать
	* @param size Количество данных
	*/ 
	std::ofstream out;
	out.open(file_name);
	if (out.is_open()){
        for(int i = 0;i<size;i++){
	        out << trains[i].get_type() << ' ' << trains[i].get_date_y() << ' ' << trains[i].get_date_m() << ' ' <<  trains[i].get_date_d() << 
	        ' ' << trains[i].get_time_h() << ' ' << trains[i].get_time_mi() << ' ' 
	        << trains[i].get_number() << ' ' << trains[i].get_way_d() << ' ' <<  trains[i].get_way_h() << std::endl;
    	}
    }
    out.close();
} 

void write_obj_in_file(std::string file_name, train trains){
	std::ofstream out(file_name, ios::app);
	if (out.is_open()){
	    out << trains.get_type() << ' ' << trains.get_date_y() << ' ' << trains.get_date_m() << ' ' <<  trains.get_date_d() << 
	    ' ' << trains.get_time_h() << ' ' << trains.get_time_mi() << ' ' 
	    << trains.get_number() << ' ' << trains.get_way_d() << ' ' <<  trains.get_way_h() << std::endl;
    }
    out.close();
}

void merge(train* a, long low, long mid, long high){
	train *b = new train[high+1-low];
	long h,i,j,k;
	h=low;
	i=0;
	j=mid+1;
	
	while((h<=mid)&&(j<=high)){
		if(a[h]<=a[j]){
			b[i]=a[h];
			h++;
		}
		else{
			b[i]=a[j];
			j++;
		}
		i++;
	}

	if(h>mid){
		for(k=j;k<=high;k++){
			b[i]=a[k];
			i++;
		}
	}
	else{
		for(k=h;k<=mid;k++){
			b[i]=a[k];
			i++;
		}
	}

	for(k=0;k<=high-low;k++){
		a[k+low]=b[k];
	}
	delete[] b;
}

void merge_sort(train* a, long low, long high){
	/**
	* @param a Массив на сортровку
	* @param low Нижний элемент
	* @param high Верхний элемент
	*/ 
	long mid;
	if(low<high){
		mid=(low+high)/2;
		merge_sort(a, low,mid);
		merge_sort(a, mid+1,high);
		merge(a, low, mid,high);
	}
}

int liner_search(train* a, long start, long size, std::string key){
    for (int i = start; i <= size; i++) if (a[i].get_type() == key) return i;
    return -1;
}

int binary_search(train* a, int start, int end, std::string key){
	if (start > end) return -1;

	int middle = start + ((end - start)/2);
	if (a[middle].get_type() == key) return middle;
	else if (a[middle].get_type() > key) return binary_search(a, start, middle - 1, key);

	return binary_search(a, middle + 1, end, key);
}

int main(){
	bool start = true;
	//generator("data5000000.txt",5000000,40);
	while(start){
		std::string key = "Скорый12";
		std::cin >> N;
		train* trains = new train[N];
		std::string s = std::to_string(N);
		std::string name_data = "data";
		name_data = name_data + s;
		name_data = name_data + ".txt";

		read_file(name_data,trains,N);

		//insert(trains, N);
		//merge_sort(trains,0,N-1);
		//quick_sort(trains, 0, N-1);
		

		std::multimap<std::string, train> Multy;
		for (int i = 0; i < N; i++){
			Multy.emplace(trains[i].get_type(), trains[i]);
		}

		unsigned int start_time =  clock();
		
		// int res = liner_search(trains, 0, N-1, key);
		// while(res != -1){
		// 	//write_obj_in_file("result_of_search.txt", trains[res]);
		// 	res = liner_search(trains, res+1, N-1, key);
		// }

		// quick_sort(trains, 0, N-1);
		// int res = binary_search(trains, 0, N-1, key), beg, en, k = 0;
		// while ((trains[res-k].get_type() == key) and ((res-k) >= 0)) k++;
		// beg = res - k + 1;
		// while ((trains[res+k].get_type() == key) and ((res+k) >= (N-1))) k++;
		// en = res + k -1;

		auto iii = Multy.equal_range("Скорый12");
	    
	    unsigned int end_time = clock();
	    unsigned int search_time = end_time - start_time;
		

		// Подсчёт времени работы программы
	    std::cout << "Total time:"<< search_time << std::endl;

	    do{
	    	write_obj_in_file("result_of_search.txt", iii.first->second);
	    	iii.first++;
	    } while (iii.first != iii.second);


		/// Автоматизация создания имени создаваемого файла
		
		// for(int i = beg; i <= en; i++){
		// 	write_obj_in_file("result_of_search.txt", trains[i]);
		// }
		
		// std::string name_result = "merge_sort_result";
		// name_result = name_result + s;
		// name_result = name_result + ".txt";
		// write_in_file(name_result, trains, N);

		delete [] trains;
		std::cin >> start;
	}
	return 1;
}