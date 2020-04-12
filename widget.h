#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;

    double angle;
    int size;
    int maxSize;
    int speed;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_doubleSpinBox_valueChanged(double arg1);
    void on_spnBox_size_valueChanged(int arg1);
    void sizeUpdate();
    void on_spnBox_speed_valueChanged(int arg1);
};

#endif // WIDGET_H
