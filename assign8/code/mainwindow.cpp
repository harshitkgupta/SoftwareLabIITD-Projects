#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::countDigits(long long p)
{int c=0;
    while(p>0)
    {
    c++;
    p=p/10;
    }
return c;
}
QString MainWindow::PrintDigits(long  n)
{
    QString text="";
    QString tmp="";
    int c=countDigits(n);

    if(c==9||c==8)
   {
       tmp=TwoDigits(n/10000000);
        if(tmp.count()!=0)
        text+=tmp+"Crore ";
    n=n%10000000;
    if(c==9)c-=2;
    if(c==8)c--;
    }
    if(c==7||c==6)
   {
       tmp=TwoDigits(n/100000);
if(tmp.count()!=0)
        text+=tmp+"Lakh";
    n=n%100000;
    if(c==7)c-=2;
    if(c==6)c--;
    }
    if(c==5||c==4)
   {
       tmp=TwoDigits(n/1000);
if(tmp.count()!=0)
        text+=tmp+"Thousand ";
    n=n%1000;
    if(c==5)c-=2;
    if(c==4)c--;
    }
    if(c==3)
   {
       tmp=TwoDigits(n/100);
if(tmp.count()!=0)
        text+=tmp+"Hundred ";
    n=n%100;
    c--;
    }
    text+=TwoDigits(n);

    return text;
  }



QString MainWindow::TwoDigits(int n)
{
QString text="";
if(n==0)
{    text+="";
    return text;
}
if(n<10)
{
    switch(n)
    {
    case 1:text+="One ";
        break;
    case 2:text+="Two ";
        break;
    case 3:text+="Three ";
        break;
    case 4:text+="Four ";
        break;
    case 5:text+="Five ";
        break;
    case 6:text+="Six ";
        break;
    case 7:text+="Seven ";
        break;
    case 8:text+="Eight ";
        break;
    case 9:text+="Nine ";
        break;
    }
}
else if(n>9&&n<20)
{

switch(n%10)
{
case 0:text+="Ten ";
             break;
case 1:text+="Eleven ";
    break;
case 2:text+="Twelve ";
    break;
case 3:text+="Thirteen ";
    break;
case 4:text+="Fourteen ";
    break;
case 5:text+="Fifteen ";
    break;
case 6:text+="Sixteen ";
    break;
case 7:text+="Seventeen ";
    break;
case 8:text+="Eighteen ";
    break;
case 9:text+="Ninteen ";
    break;
}
}
else
{
switch(n/10)
{
case 2:text+="Twenty ";
    break;
case 3:text+="Thirty ";
    break;
case 4:text+="Fourty ";
    break;
case 5:text+="Fifty ";
    break;
case 6:text+="Sixty ";
    break;
case 7:text+="Seventy ";
    break;
case 8:text+="Eighty ";
    break;
case 9:text+="Ninty ";
    break;
}
switch(n%10)
{
case 1:text+="One ";
    break;
case 2:text+="Two ";
    break;
case 3:text+="Three ";
    break;
case 4:text+="Four ";
    break;
case 5:text+="Five ";
    break;
case 6:text+="Six ";
    break;
case 7:text+="Seven ";
    break;
case 8:text+="Eight ";
    break;
case 9:text+="Nine ";
    break;
}
}
return text;


}
void MainWindow::TextToNumber(long int *val,QString str)
{
    if(QString::compare(str, "one", Qt::CaseInsensitive)==0)
    {
        *val=*val+1;
        return;
    }
    if(QString::compare(str, "two", Qt::CaseInsensitive)==0)
    {
        *val=*val+2;
        return;
    }
    if(QString::compare(str, "three", Qt::CaseInsensitive)==0)
    {
        *val=*val+3;
        return;
    }
    if(QString::compare(str, "four", Qt::CaseInsensitive)==0)
    {
        *val=*val+4;
        return;
    }
    if(QString::compare(str, "five", Qt::CaseInsensitive)==0)
    {
        *val=*val+5;
        return;
    }
    if(QString::compare(str, "six", Qt::CaseInsensitive)==0)
    {
        *val=*val+6;
        return;
    }
    if(QString::compare(str, "seven", Qt::CaseInsensitive)==0)
    {
        *val=*val+7;
        return;
    }
    if(QString::compare(str, "eight", Qt::CaseInsensitive)==0)
    {
        *val=*val+8;
        return;
    }
    if(QString::compare(str, "nine", Qt::CaseInsensitive)==0)
    {
        *val=*val+9;
        return;
    }
    if(QString::compare(str, "ten", Qt::CaseInsensitive)==0)
    {
        *val=*val+10;
        return;
    }
    if(QString::compare(str, "eleven", Qt::CaseInsensitive)==0)
    {
        *val=*val+11;
        return;
    }
    if(QString::compare(str, "twelve", Qt::CaseInsensitive)==0)
    {
        *val=*val+12;
        return;
    }
    if(QString::compare(str, "thirteen", Qt::CaseInsensitive)==0)
    {
        *val=*val+13;
        return;
    }
    if(QString::compare(str, "fourteen", Qt::CaseInsensitive)==0)
    {
        *val=*val+14;
        return;
    }
    if(QString::compare(str, "fifteen", Qt::CaseInsensitive)==0)
    {
        *val=*val+15;
        return;
    }
    if(QString::compare(str, "sixteen", Qt::CaseInsensitive)==0)
    {
        *val=*val+16;
        return;
    }
    if(QString::compare(str, "seventeen", Qt::CaseInsensitive)==0)
    {
        *val=*val+17;
        return;
    }
    if(QString::compare(str, "eighteen", Qt::CaseInsensitive)==0)
    {
        *val=*val+18;
        return;
    }
    if(QString::compare(str, "nineteen", Qt::CaseInsensitive)==0)
    {
        *val=*val+19;
        return;
    }
    if(QString::compare(str, "twenty", Qt::CaseInsensitive)==0)
    {
        *val=*val+20;
        return;
    }
    if(QString::compare(str, "thirty", Qt::CaseInsensitive)==0)
    {
        *val=*val+30;
        return;
    }
    if(QString::compare(str, "fouty", Qt::CaseInsensitive)==0)
    {
        *val=*val+40;
        return;
    }
    if(QString::compare(str, "fifty", Qt::CaseInsensitive)==0)
    {
        *val=*val+50;
        return;
    }
    if(QString::compare(str, "sixty", Qt::CaseInsensitive)==0)
    {
        *val=*val+60;
        return;
    }
    if(QString::compare(str, "seventy", Qt::CaseInsensitive)==0)
    {
        *val=*val+70;
        return;
    }
    if(QString::compare(str, "eighty", Qt::CaseInsensitive)==0)
    {
        *val=*val+80;
        return;
    }
    if(QString::compare(str, "ninety", Qt::CaseInsensitive)==0)
    {
        *val=*val+90;
        return;
    }
    if(QString::compare(str, "hundred", Qt::CaseInsensitive)==0)
    {
        int k=(*val)%10;
        *val=(*val)+(k*100-k);
        return;
    }
    if(QString::compare(str, "thousand", Qt::CaseInsensitive)==0)
    {
        int k=(*val)%100;
        *val=(*val)+(k*1000-k);
        return;
    }
    if(QString::compare(str, "lakh", Qt::CaseInsensitive)==0)
    {
        int k=(*val)%100;
        *val=(*val)+(k*100000-k);
        return;
    }
    if(QString::compare(str, "crore", Qt::CaseInsensitive)==0)
    {
        *val=(*val)*10000000;
        return;
    }
    return;
}
void MainWindow::on_pushButton_clicked()
{

    QString t= ui->lineEdit->text();
  long long n=t.toLongLong();
  QString text="";
  if(n<0)
  {
   ui->label_2->setText("Error: Negative Number ...Please ReEnter  ");
return;
  }

if(n==0)
        {
    ui->label_2->setText("Zero");
    return;
        }
  int c=countDigits(n);
if(c>9)
  {
text+=PrintDigits( n/1000000000);
text+="Arab ";
n=n%1000000000;
}
 text+=PrintDigits(n);

   ui->label_2->setText(text);

}



void MainWindow::on_pushButton_2_clicked()
{
    QString text=ui->lineEdit_2->text();
        QStringList strlist = text.split(" ", QString::SkipEmptyParts);
        QString str="";
        long int *val=new long int();
        *val=0;
        ui->label->setText("");
        for (QStringList::iterator it = strlist.begin();it != strlist.end(); ++it)
        {
                QString current = *it;
                str=str+"$"+*it;
                TextToNumber(val,current);

        }
        QString numVal=QString::number(*val);
        ui->label->setText(numVal);

}

void MainWindow::on_lineEdit_returnPressed()
{
 on_pushButton_clicked();
}

void MainWindow::on_lineEdit_textChanged(QString )
{
     on_pushButton_clicked();
}

void MainWindow::on_lineEdit_textEdited(QString )
{
    on_pushButton_clicked();
}

void MainWindow::on_lineEdit_2_returnPressed()
{
    on_pushButton_2_clicked();
}

void MainWindow::on_lineEdit_2_textEdited(QString )
{
     on_pushButton_2_clicked();
}

void MainWindow::on_lineEdit_2_textChanged(QString )
{
    QString text=ui->lineEdit_2->text();
        QStringList strlist = text.split(" ", QString::SkipEmptyParts);
        QString str="";
        long int *val=new long int();
        *val=0;
        ui->label->setText("");
        for (QStringList::iterator it = strlist.begin();it != strlist.end(); ++it)
        {
                QString current = *it;
                str=str+"$"+*it;
                TextToNumber(val,current);

        }
        QString numVal=QString::number(*val);
        QString num="";
        for(int i=0;i<numVal.length();i++)
        {

            if(numVal.length()%2==0 && i%2!=0 && i!= numVal.length()-1)
                num+=",";
            else if(numVal.length()%2!=0 && i%2==0 && i!= numVal.length()-1 && i!=0)
                num+=",";
            num+=numVal.at(i);
        }
        ui->label->setText(num);
}
