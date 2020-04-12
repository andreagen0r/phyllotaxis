#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QtMath>
#include <QTimer>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    angle(137.37),
    size(0),
    maxSize(3000),
    speed(1)
{
    ui->setupUi(this);
    showMaximized();

    ui->doubleSpinBox->setValue(angle);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::sizeUpdate);
    timer->start(15);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    double n = 0.0;
    double c = 10.0;

    QPainter painter(this);

    painter.setBrush(Qt::red);
    painter.setPen(Qt::NoPen);

    for (int i = 0; i < size; i++)
    {
        double a = n * angle;
        double r = c * sqrt(n);

        double x = r * cos(a) + (width() / 2);
        double y = r * sin(a) + (height() / 2);

        painter.drawEllipse(QPointF(x, y), 5, 5);

        n++;
    }
}

void Widget::on_doubleSpinBox_valueChanged(double arg1)
{
    angle = arg1;
    update();
}

void Widget::on_spnBox_size_valueChanged(int arg1)
{
    maxSize = arg1;
    update();
}

void Widget::sizeUpdate()
{
    if (size < maxSize) {
        size += speed;
//        ui->spnBox_size->setValue(size);
    } else {
        size = 0;
//        ui->spnBox_size->setValue(size);
    }
    update();
}

void Widget::on_spnBox_speed_valueChanged(int arg1)
{
    speed = arg1;
}
