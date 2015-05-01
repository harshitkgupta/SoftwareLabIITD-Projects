#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    QString TwoDigits(int n);
    int countDigits(long long p);
    QString PrintDigits(long n);
    void TextToNumber(long int *val,QString str);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_lineEdit_2_textChanged(QString );
    void on_lineEdit_2_textEdited(QString );
    void on_lineEdit_2_returnPressed();
    void on_lineEdit_textEdited(QString );
    void on_lineEdit_textChanged(QString );
    void on_lineEdit_returnPressed();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
