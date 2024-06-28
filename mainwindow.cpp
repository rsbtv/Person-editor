#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_Clear->click();

    ui->lineEdit_Score_Left->setReadOnly(true); //отключаем возможность изменения со стороны пользователя

    ui->lineEdit_Name->setMaxLength(20); //макс длина строки
    ui->lineEdit_Str->setMaxLength(2); //ограничение в 2 символа
    ui->lineEdit_Dex->setMaxLength(2); //ограничение в 2 символа
    ui->lineEdit_Int->setMaxLength(2);//ограничение в 2 символа
    ui->lineEdit_Luck->setMaxLength(2);//ограничение в 2 символа

    //инициализация массивов
    //сила
    mas_str[0][0]=2;         //люди мин
    mas_str[0][1]=10;       //люди макс
    mas_str[1][0]=1;        //эльфы мин
    mas_str[1][1]=8;        //эльфы макс
    mas_str[2][0]=1;        //дварфы мин
    mas_str[2][1]=6;        //дварфы макс
    mas_str[3][0]=4;        //орки мин
    mas_str[3][1]=10;      //орки макс
    //Ловкость
    mas_dex[0][0]=1;      //люди мин
    mas_dex[0][1]=8;      //люди макс
    mas_dex[1][0]=4;      //эльфы мин
    mas_dex[1][1]=10;    //эльфы макс
    mas_dex[2][0]=1;      //дварфы мин
    mas_dex[2][1]=7;      //дварфы макс
    mas_dex[3][0]=1;      //орки мин
    mas_dex[3][1]=5;      //орки макс
    //Интеллект
    mas_intel[0][0]=2;     //люди мин
    mas_intel[0][1]=10;   //люди макс
    mas_intel[1][0]=4;    //эльфы мин
    mas_intel[1][1]=10;  //эльфы макс
    mas_intel[2][0]=4;    //дварфы мин
    mas_intel[2][1]=10;  //дварфы макс
    mas_intel[3][0]=1;    //орки мин
    mas_intel[3][1]=6;    //орки макс
    //Удача
    mas_luck[0][0]=1;     //люди мин
    mas_luck[0][1]=10;   //люди макс
    mas_luck[1][0]=4;     //эльфы мин
    mas_luck[1][1]=10;   //эльфы макс
    mas_luck[2][0]=5;    //дварфы мин
    mas_luck[2][1]=10;  //дварфы макс
    mas_luck[3][0]=1;   //орки мин
    mas_luck[3][1]=10; //орки макс
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Clear_clicked() //Очистка
{
    ui->lineEdit_Name->clear(); //очистка имени
    ui->lineEdit_Str->clear();  //очистка силы
    ui->lineEdit_Dex->clear();  //очистка ловкости
    ui->lineEdit_Int->clear();  //очистка интеллекта
    ui->lineEdit_Luck->clear(); //очистка удачи

    ui->label_HP_Value->clear();//очистка хп
    ui->label_MP_Value->clear();//очистка маны
    ui->label_Atk_Value->clear();//очистка атаки
    ui->label_Def_Value->clear();//очистка ловкости
    ui->label_Class_Value->clear();//очистка класса

    ui->radioButton_Sex_M->setChecked(true); //при старте нажата кнопка мужского пола

    ui->lineEdit_Score_Left->setText("20"); //стартовое кол-во очков
}
void MainWindow::on_lineEdit_Name_textChanged(const QString &) //Изменили имя
{
    int dlina=ui->lineEdit_Name->text().length();; //ввод длины
    QPalette pal=ui->lineEdit_Name->palette(); //ввод палитры
    pal.setColor(ui->label_Name->foregroundRole(),Qt::black); //красим лейбл в черный изначально

    if ((dlina<3)||(dlina >20)) //длина имени от 3 до 20
    {
        pal.setColor(ui->label_Name->foregroundRole(),Qt::red); //окраска в красный при неправильном значении
        pal.setColor(ui->lineEdit_Name->foregroundRole(),Qt::red);//окраска в красный при неправильном значении
    }
    else
    {
        pal.setColor(ui->label_Name->foregroundRole(),Qt::green); //окраска лейбла в зеленый при правильном
        pal.setColor(ui->lineEdit_Name->foregroundRole(),Qt::green); //окраска эдита в зеленый при правильном
    }
    ui->lineEdit_Name->setPalette(pal); //установка палитры
    ui->label_Name->setPalette(pal); //установка палитры

}
void MainWindow::on_lineEdit_Str_textChanged(const QString &) //изменение силы
{
    int val; //кол-во очков внутри эдита
    int index_race=ui->comboBox_Race->currentIndex(); //считывание расы с комбобокса


    val=ui->lineEdit_Str->text().toInt(); //узнали значение силы
    QPalette pal=ui->lineEdit_Str->palette(); //введение палитры
    pal.setColor(ui->label_Str->foregroundRole(),Qt::black); //красим лейбл в черный изначально
    if ((val<mas_str[index_race][0])||(val>mas_str[index_race][1])) //условие для слишком маленького или слишком большого значения
    {
        pal.setColor(ui->label_Str->foregroundRole(),Qt::black); //окраска в черный при ошибке
        pal.setColor(ui->lineEdit_Str->foregroundRole(),Qt::black); //окраска в черный при ошибке
    } //окраска в красный при неправильном значении
    if ((val>=1)&&(val>=mas_str[index_race][0])&&(val<=3)) //условие для оранжевого цвета
    {
        pal.setColor(ui->label_Str->foregroundRole(), Qt::red); //красный
        pal.setColor(ui->lineEdit_Str->foregroundRole(), Qt::red); //красный
    }
    if ((val>3)&&(val<=7)) //условие для желтого цвета
    {
        pal.setColor(ui->label_Str->foregroundRole(),QColor(255,240,00)); //желтый
        pal.setColor(ui->lineEdit_Str->foregroundRole(),QColor(255,240,00)); //желтый
    }
    if((val>7)&&(val<=10)&&(val<mas_str[index_race][1])) //условие для зеленого цвета
    {
        pal.setColor(ui->label_Str->foregroundRole(),Qt::green); //зеленый при подходящем значении
        pal.setColor(ui->lineEdit_Str->foregroundRole(),Qt::green);//зеленый при подходящем значении
    }
    ui->lineEdit_Str->setPalette(pal); //установка палитры в объект
    ui->label_Str->setPalette(pal);//установка палитры в объект

    calc_score(); //вызов функции
}

void MainWindow::on_lineEdit_Dex_textChanged(const QString &) //изменили ловкость
{
    int val; //кол-во очков внутри эдита
    int index_race;        //индекс расы
    index_race=ui->comboBox_Race->currentIndex();
    val=ui->lineEdit_Dex->text().toInt(); //узнали значение ловкости
    QPalette pal=ui->lineEdit_Dex->palette(); //ввод палитры
    pal.setColor(ui->label_Dex->foregroundRole(),Qt::black);
    if ((val<mas_dex[index_race][0])||(val >mas_dex[index_race][1])) //условие для ошибочного значения
    {
        pal.setColor(ui->label_Dex->foregroundRole(),Qt::black);//окраска черный при ошибке
        pal.setColor(ui->lineEdit_Dex->foregroundRole(),Qt::black);//окраска черный при ошибке
    }
    if ((val>=1)&&(val>=mas_str[index_race][0])&&(val<=3)) //условие для красного цвета
    {
        pal.setColor(ui->label_Dex->foregroundRole(),Qt::red);//красный
        pal.setColor(ui->lineEdit_Dex->foregroundRole(),Qt::red); //красный
    }
    if ((val>3)&&(val<=7)) //условие для желтого цвета
    {
        pal.setColor(ui->label_Dex->foregroundRole(),QColor(255,240,00));//желтый
        pal.setColor(ui->lineEdit_Dex->foregroundRole(),QColor(255,240,00)); //желтый
    }
    if((val>7)&&(val<=10)&&(val<mas_str[index_race][1])) //условие для зеленого цвета
    {
        pal.setColor(ui->label_Dex->foregroundRole(),Qt::green); //окраска в зеленый
        pal.setColor(ui->lineEdit_Dex->foregroundRole(),Qt::green);//окраска в зеленый
    }
    ui->lineEdit_Dex->setPalette(pal); //установка палитры
    ui->label_Dex->setPalette(pal);//установка палитры

    calc_score(); //вызов функции
}

void MainWindow::on_lineEdit_Int_textChanged(const QString &) //изменили интеллект
{
    int val; //введение переменных
    int index_race=ui->comboBox_Race->currentIndex();       //индекс расы


    val=ui->lineEdit_Int->text().toInt(); //узнали значение силы
    QPalette pal; //ввод палитры
    pal=ui->lineEdit_Int->palette();
    pal.setColor(ui->label_Int->foregroundRole(),Qt::black); //окраска в черный изначально
    if ((val<mas_intel[index_race][0])||(val >mas_intel[index_race][1]))
    {
        pal.setColor(ui->label_Int->foregroundRole(),Qt::black);//окраска в черный при ошибке
        pal.setColor(ui->lineEdit_Int->foregroundRole(),Qt::black); //окраска в черный при ошибке
    }
    if ((val>=1)&&(val>=mas_str[index_race][0])&&(val<=3)) //условие для красного
    {
        pal.setColor(ui->label_Int->foregroundRole(),Qt::red); //красный
        pal.setColor(ui->lineEdit_Int->foregroundRole(),Qt::red); //красный
    }
    if ((val>3)&&(val<=7)) //условие для желтого
    {
        pal.setColor(ui->label_Int->foregroundRole(),QColor(255,240,00));//желтый
        pal.setColor(ui->lineEdit_Int->foregroundRole(),QColor(255,240,00)); //желтый
    }
    if((val>7)&&(val<=10)&&(val<mas_str[index_race][1])) //условие для зеленого
    {
        pal.setColor(ui->label_Int->foregroundRole(),Qt::green); //окраска в зеленый
        pal.setColor(ui->lineEdit_Int->foregroundRole(),Qt::green); //окраска в зеленый
    }
    ui->lineEdit_Int->setPalette(pal); //установка палитры
    ui->label_Int->setPalette(pal);//установка палитры

    calc_score(); //вызов функции
}


void MainWindow::on_lineEdit_Luck_textChanged(const QString &) //изменили значение удачи
{
    int val; //введение переменных
    int index_race;        //индекс расы
    index_race=ui->comboBox_Race->currentIndex(); //ссчитывание индекса расы

    val=ui->lineEdit_Luck->text().toInt(); //узнали значение силы
    QPalette pal; //введение палиитры
    pal=ui->lineEdit_Luck->palette();
    pal.setColor(ui->label_Luck->foregroundRole(),Qt::black); //окраска в черный изначально
    if ((val<mas_luck[index_race][0])||(val >mas_luck[index_race][1])) //условие для ошибочного значения
    {
        pal.setColor(ui->label_Luck->foregroundRole(),Qt::black); //окраска в черынй при ошибке
        pal.setColor(ui->lineEdit_Luck->foregroundRole(),Qt::black); //окраска в черынй при ошибке
    }
    if ((val>=1)&&(val>=mas_str[index_race][0])&&(val<=3)) //условие для красного
    {
        pal.setColor(ui->label_Luck->foregroundRole(),Qt::red); // окраска в красный
        pal.setColor(ui->lineEdit_Luck->foregroundRole(),Qt::red); // окраска в красный
    }
    if ((val>3)&&(val<=7)) //условие для желтого
    {
        pal.setColor(ui->label_Luck->foregroundRole(),QColor(255,240,00));//окраска в желтый
        pal.setColor(ui->lineEdit_Luck->foregroundRole(),QColor(255,240,00));//окраска в желтый
    }
    if((val>7)&&(val<=10)&&(val<mas_str[index_race][1])) //условие для зеленого
    {
        pal.setColor(ui->label_Luck->foregroundRole(),Qt::green); //окраска в зеленый
        pal.setColor(ui->lineEdit_Luck->foregroundRole(),Qt::green);//окраска в зеленый
    }
    ui->lineEdit_Luck->setPalette(pal); //установка палитры
    ui->label_Luck->setPalette(pal);//установка палитры

    calc_score(); //вызов функции
}

void MainWindow::on_comboBox_Race_currentIndexChanged(int) //функция изменения цвета при изменении расы
{
    on_lineEdit_Str_textChanged(ui->lineEdit_Str->text()); //изменеие цвета силы
    on_lineEdit_Dex_textChanged(ui->lineEdit_Dex->text());//изменеие цвета ловкости
    on_lineEdit_Int_textChanged(ui->lineEdit_Int->text());//изменеие цвета интеллекта
    on_lineEdit_Luck_textChanged(ui->lineEdit_Luck->text());//изменеие цвета удачи


}

void MainWindow::calc_score() //расчет остатка очков
{
    int str,dex,intel,luck,score_left; //ввод переменных для характеристик
    //ссчитывание характеристик
    str=ui->lineEdit_Str->text().toInt(); //ссчитывание кол-ва очков с лайн эдита
    dex=ui->lineEdit_Dex->text().toInt();//ссчитывание кол-ва очков с лайн эдита
    intel=ui->lineEdit_Int->text().toInt();//ссчитывание кол-ва очков с лайн эдита
    luck=ui->lineEdit_Luck->text().toInt();//ссчитывание кол-ва очков с лайн эдита

    score_left=20-str-dex-intel-luck; //рассчет оставшихся очков

    QPalette pal=ui->lineEdit_Score_Left->palette(); //введение палитры

    if (score_left<0) //если потрачено слишком много очков
        pal.setColor(QPalette::Text,Qt::red);
    else
        if (score_left>0) //если остались очки
            pal.setColor(QPalette::Text,Qt::magenta);
        else //очков не осталось
            pal.setColor(QPalette::Text,Qt::green);

    ui->lineEdit_Score_Left->setPalette(pal); //установка палитры
    ui->lineEdit_Score_Left->setText(QString::number(score_left)); //отображение оставшегося кол-ва очков


}




void MainWindow::on_pushButton_Create_clicked() //расчет параметров персонажа
{
    QString name;         //имя
    int dlina;                //длина имени
    bool flag;  //признак успешности генерации

    int str,dex,intel,luck; //параметры
    int index_race;        //индекс расы

    index_race=ui->comboBox_Race->currentIndex(); //ссчитывание индекса расы


    name=ui->lineEdit_Name->text(); //считывание имени
    dlina=name.length();                  //определили длину имени

    if ((dlina<3)||(dlina>20)) //диапазон имени
    {
        flag=false;
        QMessageBox::information(this,"Ошибка", "Имя должно быть от 3 до 20 символов.",QMessageBox::Ok); //вывод ошибки
    }
    else
        flag=true; //длина подходит, ошибки нет

    //Сила
    str=0; //ввод переменной
    if (flag) //вместо вложенных условий
    {
        str=ui->lineEdit_Str->text().toInt(&flag); //ссчитывание силы
        if (flag) //проверка значения
        {
            if ((str<mas_str[index_race][0])||(str>mas_str[index_race][1])) //неправильное значение силы
            {
                flag=false;
                QMessageBox::information(this,"Ошибка", "Параметр \"Сила\" должен быть от "+
                                         QString::number(mas_str[index_race][0])+" до "+
                        QString::number(mas_str[index_race][1]) +".",QMessageBox::Ok); //вывод ошибки
            }
        }

        else //введен мусор
            QMessageBox::information(this,"Ошибка", "Неправильное значение параметра \"Сила\".",QMessageBox::Ok); //вывод ошибки
    }
    //Интеллект
    intel=0; //введение переменной
    if (flag) //вместо вложенных условий
    {
        intel=ui->lineEdit_Int->text().toInt(&flag); //ссчитывание интеллекта
        if (flag) //проверка значения
        {
            if ((intel<mas_intel[index_race][0])||(intel>mas_intel[index_race][1])) //значение не в диапазоне
            {
                flag=false;
                QMessageBox::information(this,"Ошибка", "Параметр \"Интеллект\" должен быть от "+
                                         QString::number(mas_intel[index_race][0])+" до "+
                        QString::number(mas_intel[index_race][1]) +".",QMessageBox::Ok); //вывод ошибки

            }
        }
        else //введен мусор
            QMessageBox::information(this,"Ошибка", "Неправильное значение параметра \"Интеллект\".",QMessageBox::Ok); //вывод ошибки
    }

    //Ловкость
    dex=0; //введение переменнной
    if (flag) //вместо вложенных условий
    {
        dex=ui->lineEdit_Dex->text().toInt(&flag); //ссчитывание ловкости
        if (flag) //проверка значения
        {
            if ((dex<mas_dex[index_race][0])||(dex>mas_dex[index_race][1])) //значение не в диапазоне
            {
                flag=false;
                QMessageBox::information(this,"Ошибка", "Параметр \"Ловкость\" должен быть от "+
                                         QString::number(mas_dex[index_race][0])+" до "+
                        QString::number(mas_dex[index_race][1]) +".",QMessageBox::Ok); //вывод ошибки

            }
        }
        else //ввелен мусор
            QMessageBox::information(this,"Ошибка", "Неправильное значение параметра \"Ловкость\".",QMessageBox::Ok); //вывод ошибки
    }

    //Удача
    luck=0; //ввод переменной
    if (flag) //вместо вложенных условий
    {
        luck=ui->lineEdit_Luck->text().toInt(&flag); //ссчитывание удачи
        if (flag)
        {
            if ((luck<mas_luck[index_race][0])||(luck>mas_luck[index_race][1])) //значение не в диапазоне
            {
                flag=false;
                QMessageBox::information(this,"Ошибка", "Параметр \"Удача\" должен быть от "+
                                         QString::number(mas_luck[index_race][0])+" до "+
                        QString::number(mas_luck[index_race][1]) +".",QMessageBox::Ok); //вывод ошибки

            }
        }
        else //введен мусор
            QMessageBox::information(this,"Ошибка", "Неправильное значение параметра \"Удача\".",QMessageBox::Ok); //вывод ошибки
    }



    //проверка количества очков
    if (flag)
    {

        int score_left=20-str-dex-intel-luck;  //рассчет оставшихся очков
        ui->lineEdit_Score_Left->setText(QString::number(score_left)); //преобразуем число в окошко без создания строки
        if (score_left!=0) //проверка значения
        {
            flag=false;
            if (score_left<0) //потрачено слишком много очков
                QMessageBox::information(this,"Ошибка", "Нельзя потратить больше 20 очков.", QMessageBox::Ok);
            else //остались очки
                QMessageBox::information(this, "Ошибка", "Нужно потратить все очки.", QMessageBox::Ok);


        }
    }
    if (flag) //расчет из 3-их героев
    {
        int hp,mp,atk,def; //ввод переменных
        hp=8*str+2*dex; //здоровье
        mp=8*intel+dex+luck; //мана
        atk=6*str+2*dex+2*luck; //атака
        def=7*str+3*dex; //защита

        ui->label_HP_Value->setNum(hp);     //вывод рассчитанных характеристик
        ui->label_MP_Value->setNum(mp);    //вывод рассчитанных характеристик
        ui->label_Atk_Value->setNum(atk);   //вывод рассчитанных характеристик
        ui->label_Def_Value->setNum(def);   //вывод рассчитанных характеристик
        //класс воина
        if ((str>=5) && (str<=8) && (dex>=5)) //условие для класса
        {
            if (ui->radioButton_Sex_M->isChecked()) //мужской пол
            {
                ui->label_Class_Value->setText("Воин"); //вывод класса для мужского пола
            }
            if (ui->radioButton__Sex_W->isChecked()) //женский пол
            {
                ui->label_Class_Value->setText("Воительница");//вывод класса для женского пола
            }
        }
        //класс плута
        if ((dex>=6) && (str<5)) //условие для класса
        {
            if (ui->radioButton_Sex_M->isChecked())//мужской пол
            {
                ui->label_Class_Value->setText("Плут");//вывод класса для мужского пола
            }
            if (ui->radioButton__Sex_W->isChecked())//женский пол
            {
                ui->label_Class_Value->setText("Плутовка");//вывод класса для женского пола
            }
        }
        //класс чародея
        if ((mp>50) && (intel>=6) && (str<=6)) //условие для класса
        {
            if (ui->radioButton_Sex_M->isChecked())//мужской пол
            {
                ui->label_Class_Value->setText("Чародей");//вывод класса для мужского пола
            }
            if (ui->radioButton__Sex_W->isChecked())//женский пол
            {
                ui->label_Class_Value->setText("Чародейка");//вывод класса для женского пола
            }
        }
        //класс вора
        if ((dex>5)&&(luck>5)&&(intel>4)) //условие для класса
        {
            if (ui->radioButton_Sex_M->isChecked())//мужской пол
            {
                ui->label_Class_Value->setText("Вор");//вывод класса для мужского пола
            }
            if (ui->radioButton__Sex_W->isChecked())//женский пол
            {
                ui->label_Class_Value->setText("Воровка");//вывод класса для женского пола
            }
        }
        if ((intel>=7)&&(str>=6)) //условие для класса
        {
            if (ui->radioButton_Sex_M->isChecked())//мужской пол
            {
                ui->label_Class_Value->setText("Ремесленник");//вывод класса для мужского пола
            }
            if (ui->radioButton__Sex_W->isChecked())//женский пол
            {
                ui->label_Class_Value->setText("Ремесленница");//вывод класса для женского пола
            }
        }
        //жрец
        if ((luck>=7) &&(intel>=7) && (str<=5)) //условие для класса
        {
            if (ui->radioButton_Sex_M->isChecked())//мужской пол
            {
                ui->label_Class_Value->setText("Жрец");//вывод класса для мужского пола
            }
            if (ui->radioButton__Sex_W->isChecked())//женский пол
            {
                ui->label_Class_Value->setText("Жрица");//вывод класса для женского пола
            }
        }
        if ((luck>=6)&&(str>=6)&&(intel>=6)) //условие для класса
        {
            if (ui->radioButton_Sex_M->isChecked())//мужской пол
            {
                ui->label_Class_Value->setText("Лучник");//вывод класса для мужского пола
            }
            if (ui->radioButton__Sex_W->isChecked())//женский пол
            {
                ui->label_Class_Value->setText("Лучница");//вывод класса для женского пола
            }
        }
        if ((luck>=6)&&(intel>=6) &&(str<=5))
        {
            if (ui->radioButton_Sex_M->isChecked())//мужской пол
            {
                ui->label_Class_Value->setText("Зельевар");//вывод класса для мужского пола
            }
            if (ui->radioButton__Sex_W->isChecked())//женский пол
            {
                ui->label_Class_Value->setText("Зельеварка");//вывод класса для женского пола
            }
        }

        if (str>=8) //класс силач
        {
            if (ui->radioButton_Sex_M->isChecked()) //мужской пол
            {
                ui->label_Class_Value->setText("Силач"); //вывод класса для мужского пола
            }
            if (ui->radioButton__Sex_W->isChecked()) //женский пол
            {
                ui->label_Class_Value->setText("Силачка"); //вывод класса для женского пола
            }
        }
        if (str<=3 && luck >=8) //класс бард
        {
            if (ui->radioButton_Sex_M->isChecked()) //мужской пол
            {
                ui->label_Class_Value->setText("Бард"); //вывод класса для мужского пола
            }
            if (ui->radioButton__Sex_W->isChecked()) //женский пол
            {
                ui->label_Class_Value->setText("Певица"); // вывод класса для женского пола
            }
        }
        if (luck>=8)
        {
            if (ui->radioButton_Sex_M->isChecked())
            {
                ui->label_Class_Value->setText("Игроман");
            }
            if (ui->radioButton__Sex_W->isChecked())
            {
                ui->label_Class_Value->setText("Игроманка");
            }
        }



    }
    else // при неверных значениях очищаем результаты
    {

        ui->label_HP_Value->clear();
        ui->label_MP_Value->clear();
        ui->label_Atk_Value->clear();
        ui->label_Def_Value->clear();
        ui->label_Class_Value->clear();

    }
}












