#include <iostream>

#include <string>

#include <cstring>

#include <clocale>


class Telephone {
        public: Telephone(std::string model, int age, int value): model(model),
        age(age),
        value(value) {}

        int checkage() {
                return age;
        }

        virtual int calculatevalue() const {
                return value;
        }

        void changeEngine(int new_HP) {
                age = new_HP;
        }

        virtual void showData() const {
                std::cout << "Модель: " << model << std::endl;
                std::cout << "Год выпуска: " << age << std::endl;
                std::cout << "Цена: " << value << std::endl;
        }

        protected: int age;
        int value;
        std::string model;

};

class Stacionar: public Telephone {
        public: Stacionar(std::string model, int age, bool isSpeedster, int value): Telephone(model, age, value),
        isSpeedster(isSpeedster) {}

        void showData() const override {
                std::cout << "Стационарный телефон: " << std::endl;
                Telephone::showData();
                if (isSpeedster == true) {
                        std::cout << "Скоростной" << std::endl;
                } else {
                        std::cout << "Обычный" << std::endl;
                }
        }

        int calculatevalue() const override {
                return Telephone::calculatevalue() + 5;
        }

        void changeLicense(bool new_status) {
                if (new_status == true) {
                        std::cout << "Теперь скоростной" << std::endl;
                        isSpeedster = true;
                } else {
                        std::cout << "Тепереь обычный" << std::endl;
                        isSpeedster = false;
                }
        }

        private: bool isSpeedster;
};

class Mobile: public Telephone {
        public: Mobile(std::string model, int age, bool isRacing, int value): Telephone(model, age, value),
        isRacing(isRacing) {}

        void showData() const override {
                std::cout << "Мобильный телефон: " << std::endl;
                Telephone::showData();
                if (isRacing == true) {
                        std::cout << "Крутой" << std::endl;
                } else {
                        std::cout << "Обычный" << std::endl;
                }
        }

        void changeLicense(bool new_status) {
                if (new_status == true) {
                        std::cout << "теперь крутойя" << std::endl;
                        isRacing = true;
                } else {
                        std::cout << "теперь обычный" << std::endl;
                        isRacing = false;
                }
        }
        private: bool isRacing;
};

int main() {
        const int arraySize = 3;
        Telephone * ts[arraySize];

        ts[0] = new Mobile("Iphone", 110, true, 4);
        ts[1] = new Stacionar("стационарный 1", 110000, true, 5);

        int choice = -1;
        int option = 0;
        int min_ts = 0;
        int new_hp = 0;
        bool new_license = false;
        int min_value = 1000;

        std::cout << "Список транспорта" << std::endl;
        std::cout << "Выберите одно действие: " << std::endl;
        std::cout << "1 для Информация" << std::endl;
        std::cout << "2 для Поменять мощность мотора" << std::endl;
        std::cout << "3 для Пересчитать транспорт" << std::endl;

        while (choice != 0) {
                std::cout << "Напишите опцию или 0 для заверешения" << std::endl;
                std::cin >> choice;
                switch (choice) {
                case 0: {
                        choice = 0;
                        std::cout << "Выход из программы" << std::endl;
                        break;
                }
                case 1: {
                        for (int i = 0; i < arraySize; i++) {
                                std::cout << "Транспорт " << (i + 1) << std::endl;
                                ts[i] -> showData();
                        }
                        break;
                }
                case 2: {
                        std::cout << "Выберите лнию которую хотите поменять" << std::endl;
                        std::cin >> option;
                        std::cout << "Напишите новое значенеи лошадинных сил" << std::endl;
                        std::cin >> new_hp;
                        ts[option - 1] -> changeEngine(new_hp);
                        std::cout << "Л/С изменены" << std::endl;
                        break;
                }
                case 3: {
                        for (int i = 0; i < arraySize; i++) {
                                if (ts[i] -> calculatevalue() < min_value) {
                                        min_value = ts[i] -> calculatevalue();
                                        min_ts = i;
                                }
                        }
                        std::cout << "Самый дешевый: " << min_ts + 1 << " рублей";
                        break;
                }

                default: {
                        std::cout << "Введена неверная цифра,пробуйте еще раз" << std::endl;
                        break;
                }

                }

        }

        for (int i = 0; i < arraySize; ++i) {
                delete ts[i];
        }

        return 0;
}