#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTcpSocket* socket;


private slots:
    void on_ConnectButton_clicked();

    void on_UpButton_pressed();

    void on_UpButton_released();

    void on_BreakButton_clicked();

    void on_DownButton_pressed();

    void on_DownButton_released();

    void on_LeftButton_pressed();

    void on_LeftButton_released();

    void on_RightButton_pressed();

    void on_RightButton_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
