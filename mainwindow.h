#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "aboutwindow.h"

#include <QMainWindow>
#include<QProgressBar>
#include<QLabel>
#include<QSpinBox>
#include<QFontComboBox>
#include<QToolButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    //新增控件
    QLabel *fLabCurFile;    //状态栏里显示当前文件的Label
    QProgressBar *progressBar;  //状态栏上的进度条
    QSpinBox *spinFontSize;     //字体大小
    QFontComboBox *comboFont;   //字体名称
    QToolButton *aboutButton;   //关于按钮


    void initUI();
    void initSingalSlots(); //连接信号和自定义槽函数


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // void on_actCut_triggered();

    void on_actFontBold_triggered(bool checked);

    void on_actFontItalic_triggered(bool checked);

    void on_actFontUnder_triggered(bool checked);

    void on_textEdit_copyAvailable(bool b);

    void on_textEdit_selectionChanged();

    //自定义槽函数
    void on_spinBoxFontSize_valueChanged(int aFontSize);    //改变字体大小的spinBox响应

    void on_comboFont_currentIndexChanged(const QString &arg1); //FontComboBox的

    void on_aboutButton_clicker();  //点击关于按钮
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
