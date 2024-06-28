#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox> //подключаем библиотеку с окошками сообщений

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Clear_clicked();

    void on_pushButton_Create_clicked();

    void on_lineEdit_Name_textChanged(const QString &arg1);

    void on_lineEdit_Str_textChanged(const QString &arg1);

    void on_lineEdit_Dex_textChanged(const QString &arg1);

    void on_lineEdit_Int_textChanged(const QString &arg1);

    void on_lineEdit_Luck_textChanged(const QString &arg1);
    void calc_score(void); //функция расчета очков






    void on_comboBox_Race_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    int mas_str[4][2];    //массивараметров силы: 4 - 0,1,2,3 - расы (0-люди, 1-эльфы,...);2 - мин(0) и макс (1)
    int mas_dex[4][2];  //массив параметров ловкости
    int mas_intel[4][2]; //массив параметров интеллекта
    int mas_luck[4][2]; // массив параметров удачи

};

#endif // MAINWINDOW_H
