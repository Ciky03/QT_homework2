#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::initUI()
{
    //用于显示当前文件名的标签
    fLabCurFile = new QLabel;
    fLabCurFile->setMinimumWidth(150);  //最小大小
    fLabCurFile->setText("当前文件");    //文字
    ui->statusBar->addWidget(fLabCurFile); //添加到statusbar

    //状态栏上的进度条
    progressBar = new QProgressBar;
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setMaximumWidth(200);  //组件最大宽度
    progressBar->setValue(ui->textEdit->font().pointSize());
    ui->statusBar->addWidget(progressBar);

    ui->toolBar->addSeparator();
    //关于按钮
    aboutButton = new QToolButton;
    aboutButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    aboutButton->setIcon(QIcon(":/images/images/20.ico"));
    aboutButton->setText("关于");
    ui->toolBar->addWidget(aboutButton);

    //工具栏的字体大小
    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setMinimumWidth(75);
    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinFontSize);

    //工具栏的字体
    ui->toolBar->addSeparator();    //工具栏上增加分隔条
    comboFont = new QFontComboBox;
    ui->toolBar->addWidget(new QLabel("字体"));
    comboFont->setMinimumWidth(150);    //设置组件最小宽度
    ui->toolBar->addWidget(comboFont);  //添加到工具栏

    setCentralWidget(ui->textEdit); //将txtEdit设置为中心组件，自动填充整个工作区
}

void MainWindow::initSingalSlots()
{
    connect(spinFontSize,SIGNAL(valueChanged(int)),
            this,SLOT(on_spinBoxFontSize_valueChanged(int)));

    connect(comboFont,SIGNAL(currentFontChanged(QFont)),
            this,SLOT(on_spinBoxFontSize_valueChanged(int)));

    connect(aboutButton,SIGNAL(clicked(bool)),
            this,SLOT(on_aboutButton_clicker()));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    initSingalSlots();
    setCentralWidget(ui->textEdit); //textEdit布局
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}




void MainWindow::on_actFontItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actFontUnder_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->textEdit->canPaste());

}


void MainWindow::on_textEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat();
    ui->actFontItalic->setChecked(fmt.fontItalic());
    ui->actFontBold->setChecked(fmt.font().bold());
    ui->actFontUnder->setChecked(fmt.fontUnderline());
}

void MainWindow::on_spinBoxFontSize_valueChanged(int aFontSize)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);
    ui->textEdit->mergeCurrentCharFormat(fmt);
    progressBar->setValue(aFontSize);
}

void MainWindow::on_comboFont_currentIndexChanged(const QString &arg1)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_aboutButton_clicker()
{
    aboutWindow *configWindow = new aboutWindow;
    configWindow->show();
}

