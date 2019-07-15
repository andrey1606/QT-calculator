#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <Qt>
#include <QtMath>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double left_operand, temp_result;
    bool plus_status, minus_status, div_status, mult_status, sqr_status, sqrt_status, dot_status, operation_status = 0;

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void numbers();
    void do_oper();
    void on_button_dot_clicked();
    void on_button_backspace_clicked();
    void on_button_clear_clicked();
    void on_button_plus_minus_clicked();
    void on_button_percent_clicked();
    void on_button_plus_clicked();
    void on_button_minus_clicked();
    void on_button_mult_clicked();
    void on_button_div_clicked();
    void on_button_sqr_clicked();
    void on_button_sqrt_clicked();
    void on_button_equal_clicked();
};

#endif // MAINWINDOW_H
