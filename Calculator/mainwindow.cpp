#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Calculator");
    connect(ui->button_0,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_1,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_2,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_3,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_4,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_5,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_6,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_7,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_8,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_9,SIGNAL(clicked()),this,SLOT(numbers()));

    double left_operand, temp_result;
    bool plus_status, minus_status, div_status, mult_status, sqr_status, sqrt_status, dot_status, operation_status = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    QString str = QString(QChar(key));
    if(key == Qt::Key_0)
        ui->button_0->clicked();
    else if(key == Qt::Key_1)
        ui->button_1->clicked();
    else if(key == Qt::Key_2)
        ui->button_2->clicked();
    else if(key == Qt::Key_3)
        ui->button_3->clicked();
    else if(key == Qt::Key_4)
        ui->button_4->clicked();
    else if(key == Qt::Key_5)
        ui->button_5->clicked();
    else if(key == Qt::Key_6)
        ui->button_6->clicked();
    else if(key == Qt::Key_7)
        ui->button_7->clicked();
    else if(key == Qt::Key_8)
        ui->button_8->clicked();
    else if(key == Qt::Key_9)
        ui->button_9->clicked();
    else if(key == Qt::Key_Delete)
        ui->button_clear->clicked();
    else if(key == Qt::Key_Plus)
        ui->button_plus->clicked();
    else if(key == Qt::Key_Minus)
        ui->button_minus->clicked();
    else if(key == 42)
        ui->button_mult->clicked();
    else if(key == 47)
        ui->button_div->clicked();
    else if(key == 46)
        ui->button_dot->clicked();
    else if(key == Qt::Key_Backspace)
        ui->button_backspace->clicked();
    else if(key == Qt::Key_Enter)
        ui->button_equal->clicked();
}

void MainWindow::numbers()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    double all_numbers;
    QString new_screen;
    if(operation_status)
          {
            ui->screen_calc->clear();
            operation_status = 0;
          }
    if(ui->screen_calc->text().contains(".") && (button->text() == "0"))
    {
        if(ui->screen_calc->text().length()<15)
          {
            new_screen = ui->screen_calc->text() + button->text();
          }
        else
          {
            new_screen = ui->screen_calc->text();
          }
    }
    else
    {
    all_numbers = (ui->screen_calc->text() + button->text()).toDouble();
    new_screen=QString::number(all_numbers,'g',15);
    }
    ui->screen_calc->setText(new_screen);
}



void MainWindow::on_button_dot_clicked()
{
    if(!(ui->screen_calc->text().contains('.')))
        {
            ui->screen_calc->setText(ui->screen_calc->text() + ".");
        }

}





void MainWindow::on_button_backspace_clicked()
{
    QString reduce = ui->screen_calc->text();
      reduce.resize(reduce.size() - 1);
      if(reduce.length() == 0)
        {
          reduce = "0";

        }
      ui->screen_calc->setText(reduce);
}

void MainWindow::on_button_clear_clicked()
{
    ui->screen_calc->setText("0");
    ui->screen2->setText("");
    plus_status = 0;
    minus_status = 0;
    div_status = 0;
    mult_status = 0;
    sqr_status = 0;
    sqrt_status = 0;
    dot_status = 0;
    operation_status = 0;
    left_operand = 0;
}

void MainWindow::on_button_plus_minus_clicked()
{
    double number;
    QString new_screen;
    number = (ui->screen_calc->text()).toDouble();
    number = number * (-1);
    new_screen=QString::number(number,'g',15);
    ui->screen_calc->setText(new_screen);
}

void MainWindow::on_button_percent_clicked()
{
    double number;
    QString new_screen;
    number = (ui->screen_calc->text()).toDouble();
    number = number * 0.01;
    new_screen=QString::number(number,'g',15);
    ui->screen_calc->setText(new_screen);
}



void MainWindow::on_button_plus_clicked()
{
    if (!operation_status && !plus_status && !minus_status && !div_status && !mult_status && !dot_status && !sqr_status && !sqrt_status)
    {
        double number;
        number = (ui->screen_calc->text()).toDouble();
        left_operand = number;
        ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text() + "+");
        operation_status = 1;
        plus_status = 1;
    }
    if (plus_status && !operation_status)
        {
            double number, temp;
            QString str;
            number = (ui->screen_calc->text()).toDouble();
            temp = left_operand + number;
            ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text() + "+");
            str = QString::number(temp,'g',15);
            ui->screen_calc->setText(str);
            left_operand = temp;
            operation_status = 1;
            plus_status = 1;
            minus_status = 0;
            div_status = 0;
            mult_status = 0;
            sqr_status = 0;
            sqrt_status=0;
        }
    if ((minus_status|div_status|mult_status|sqr_status|sqrt_status) && !operation_status && !plus_status)
        {
            do_oper();
            ui->screen2->setText(ui->screen2->text() + "+");
            plus_status = 1;
            operation_status = 1;
        }
    if (operation_status && (minus_status|div_status|mult_status|sqr_status|sqrt_status) &&  !plus_status)
    {
        QString str;
        str = (ui->screen2->text());
        int size = str.size();
        str[size-1] = '+';
    }
}

void MainWindow::on_button_minus_clicked()
{
    if (!operation_status && !plus_status && !minus_status && !div_status && !mult_status && !dot_status && !sqr_status && !sqrt_status)
    {
        double number;
        number = (ui->screen_calc->text()).toDouble();
        left_operand = number;
        ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text() + "-");
        operation_status = 1;
        minus_status = 1;
    }
    if (minus_status && !operation_status)
        {
            double number, temp;
            QString str;
            number = (ui->screen_calc->text()).toDouble();
            temp = left_operand - number;
            ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text() + "-");
            str = QString::number(temp,'g',15);
            ui->screen_calc->setText(str);
            left_operand = temp;
            operation_status = 1;
            plus_status = 0;
            minus_status = 1;
            div_status = 0;
            mult_status = 0;
            sqr_status = 0;
            sqrt_status = 0;
        }
    if ((plus_status|div_status|mult_status|sqr_status|sqrt_status) && !operation_status && !minus_status)
        {
            do_oper();
            ui->screen2->setText(ui->screen2->text() + "-");
            minus_status = 1;
            operation_status = 1;
        }
    if (operation_status && (plus_status|div_status|mult_status|sqr_status|sqrt_status) && !minus_status)
    {
        QString str;
        str = (ui->screen2->text());
        int size = str.size();
        str[size-1] = '-';
    }
}

void MainWindow::on_button_mult_clicked()
{
    if (!operation_status && !plus_status && !minus_status && !div_status && !mult_status && !dot_status && !sqr_status && !sqrt_status)
    {
        double number;
        number = (ui->screen_calc->text()).toDouble();
        left_operand = number;
        ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text() + "*");
        operation_status = 1;
        mult_status = 1;
    }
    if (mult_status && !operation_status)
        {
            double number, temp;
            QString str;
            number = (ui->screen_calc->text()).toDouble();
            temp = left_operand * number;
            ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text() + "*");
            str = QString::number(temp,'g',15);
            ui->screen_calc->setText(str);
            left_operand = temp;
            operation_status = 1;
            plus_status = 0;
            minus_status = 0;
            div_status = 0;
            mult_status = 1;
            sqr_status = 0;
            sqrt_status = 0;
        }
    if ((plus_status|div_status|minus_status|sqr_status|sqrt_status) && !operation_status && !mult_status)
        {
            do_oper();
            ui->screen2->setText(ui->screen2->text() + "*");
            mult_status = 1;
            operation_status = 1;
        }
    if (operation_status && (plus_status|div_status|minus_status|sqr_status|sqrt_status) && !mult_status)
    {
        QString str;
        str = (ui->screen2->text());
        int size = str.size();
        str[size-1] = '*';
    }
}

void MainWindow::on_button_div_clicked()
{
    if (!operation_status && !plus_status && !minus_status && !div_status && !mult_status && !dot_status && !sqr_status && !sqrt_status)
    {
        double number;
        number = (ui->screen_calc->text()).toDouble();
        left_operand = number;
        ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text() + "/");
        operation_status = 1;
        div_status = 1;
    }
    if (div_status && !operation_status)
        {
            double number, temp;
            QString str;
            number = (ui->screen_calc->text()).toDouble();
            temp = left_operand / number;
            ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text() + "/");
            str = QString::number(temp,'g',15);
            ui->screen_calc->setText(str);
            left_operand = temp;
            operation_status = 1;
            plus_status = 0;
            minus_status = 0;
            div_status = 1;
            mult_status = 0;
            sqr_status = 0;
            sqrt_status = 0;
        }
    if ((plus_status|minus_status|mult_status|sqr_status|sqrt_status) && !operation_status && !div_status)
        {
            do_oper();
            ui->screen2->setText(ui->screen2->text() + "/");
            div_status = 1;
            operation_status = 1;
        }
    if (operation_status && (plus_status|minus_status|mult_status|sqr_status|sqrt_status) && !div_status)
    {
        QString str;
        str = (ui->screen2->text());
        int size = str.size();
        str[size-1] = '/';
    }
}

void MainWindow::on_button_sqr_clicked()
{
    if (!operation_status && !plus_status && !minus_status && !div_status && !mult_status && !dot_status && !sqr_status && !sqrt_status)
    {
        double number;
        number = (ui->screen_calc->text()).toDouble();
        left_operand = number;
        ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text() + "^");
        operation_status = 1;
        sqr_status = 1;
    }
    if (sqr_status && !operation_status)
        {
            double number, temp;
            QString str;
            number = (ui->screen_calc->text()).toDouble();
            temp = pow(left_operand, number);
            ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text() + "^");
            str = QString::number(temp,'g',15);
            ui->screen_calc->setText(str);
            left_operand = temp;
            operation_status = 1;
            plus_status = 0;
            minus_status = 0;
            div_status = 0;
            mult_status = 0;
            sqr_status = 1;
            sqrt_status = 0;
        }
    if ((plus_status|minus_status|mult_status|div_status|sqrt_status) && !operation_status && !sqr_status)
        {
            do_oper();
            ui->screen2->setText(ui->screen2->text() + "^");
            sqr_status = 1;
            operation_status = 1;
        }
    if (operation_status && (plus_status|minus_status|mult_status|div_status|sqrt_status) && !sqr_status)
    {
        QString str;
        str = (ui->screen2->text());
        int size = str.size();
        str[size-1] = '^';
    }
}

void MainWindow::on_button_sqrt_clicked()
{
    if (!operation_status && !minus_status && !div_status && !mult_status && !dot_status && !sqr_status && !sqrt_status)
    {
        double number;
        QString new_screen;
        ui->screen2->setText(ui->screen2->text() + "√" + ui->screen_calc->text());
        number = (ui->screen_calc->text()).toDouble();
        number = sqrt(number);
        new_screen=QString::number(number,'g',15);
        ui->screen_calc->setText(new_screen);
        sqrt_status = 1;

    }
}

void MainWindow::do_oper()
{
    QString strk;
    strk = (ui->screen2->text());
    int size = strk.size();
    if (strk[size-1] == '+')
    {
        double number, temp;
        QString str;
        number = (ui->screen_calc->text()).toDouble();
        temp = number + left_operand;
        ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text());
        str = QString::number(temp,'g',15);
        ui->screen_calc->setText(str);
        left_operand = temp;
        operation_status = 0;
        plus_status = 0;
        minus_status = 0;
        div_status = 0;
        mult_status = 0;

    } else if (strk[size-1] == '-')
    {
        double number, temp;
        QString str;
        number = (ui->screen_calc->text()).toDouble();
        temp = left_operand - number;
        ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text());
        str = QString::number(temp,'g',15);
        ui->screen_calc->setText(str);
        left_operand = temp;
        operation_status = 0;
        plus_status = 0;
        minus_status = 0;
        div_status = 0;
        mult_status = 0;

    } else if (strk[size-1] == '*')
    {
        double number, temp;
        QString str;
        number = (ui->screen_calc->text()).toDouble();
        temp = left_operand * number;
        ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text());
        str = QString::number(temp,'g',15);
        ui->screen_calc->setText(str);
        left_operand = temp;
        operation_status = 0;
        plus_status = 0;
        minus_status = 0;
        div_status = 0;
        mult_status = 0;

    } else if (strk[size-1] == '/')
    {
        double number, temp;
        QString str;
        number = (ui->screen_calc->text()).toDouble();
        temp = left_operand / number;
        ui->screen2->setText(ui->screen2->text() + ui->screen_calc->text());
        str = QString::number(temp,'g',15);
        ui->screen_calc->setText(str);
        left_operand = temp;
        operation_status = 0;
        plus_status = 0;
        minus_status = 0;
        div_status = 0;
        mult_status = 0;

    }

}

void MainWindow::on_button_equal_clicked()
{
    do_oper();
    ui->screen2->setText("");
    plus_status = 0;
    minus_status = 0;
    div_status = 0;
    mult_status = 0;
    sqr_status = 0;
    sqrt_status = 0;
    dot_status = 0;
    operation_status = 0;
    left_operand = 0;
}
