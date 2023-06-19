#include "cityitem.h"
#include "ui_cityitem.h"
#include <QtMath>
	#include "mainwindow.h"

	cityitem::cityitem(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::cityitem)
	{
	ui->setupUi(this);
	}

	void cityitem::set_size(int new_size)
	{
	this -> n = new_size;
	}

	cityitem::~cityitem()
	{
	delete ui;
	}
	// Отрисовка графа
	void cityitem::paintEvent(QPaintEvent *event)
	{
	Q_UNUSED(event);
	QPainter painter(this);
	painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

	int y, x = -150;
	int r = 150;
	int len = 300/(n/2);
	int **citycoords = new int*[n];
	for(int i = 0; i < n; i++)
        {
            citycoords[i] = new int[2];
        }
        int k = 0;
        for(int i = 0; i < n/2; i++)
        {
            y = qSqrt(r*r - x*x);
            citycoords[k][0] = 200 - x;
            citycoords[k][1] = 200 - y;
            k++;
            x += len;
        }
        x = 150;
        if(n%2 == 0)
        {
            for(int i = 0; i < n/2; i++)
            {
                y = qSqrt(r*r - x*x)*(-1);
                citycoords[k][0] = 200 - x;
                citycoords[k][1] = 200 - y;
                k++;
                x -= len;
            }
        }
        else
        {
            len = 300/(n/2 + 1);
            for(int i  =0; i < n/2 + 1; i++)
            {
                y = qSqrt(r*r - x*x)*(-1);
                citycoords[k][0] = 200 - x;
                citycoords[k][1] = 200 - y;
                k++;
                x -= len;
            }
        }
        // Отрисовка рёбер
        for(int i = 0; i < n; i++)
        {
           for(int j = 0; j < n ;j++)
           {
               if(matrix_graph[i][j] != "0" && matrix_graph[j][i] != "0")
	{
	QPen pen(Qt::black, 2, Qt::SolidLine);
	painter.setPen(pen);
	painter.drawLine(citycoords[i][0]+25, citycoords[i][1]+25, citycoords[j][0]+25, citycoords[j][1]+25);
	}
	}
	}

	for(int i = 0; i < n ; i++)
        {
            // Контур вершин
            QPen pen1(Qt::black, 2, Qt::SolidLine);
            painter.setPen(pen1);
            // Вершины
            painter.setBrush(QBrush(QColor(159,186,199,255), Qt::SolidPattern));
            painter.drawEllipse(citycoords[i][0], citycoords[i][1], 50, 50);
            painter.setFont(QFont(QString::number(i+1),14));
            // Текст внутри вершин графа
            QPen pen2(QColor(138,69,153,255), 2, Qt::SolidLine);
            painter.setPen(pen2);
            painter.drawText(citycoords[i][0]+15, citycoords[i][1]+30, name_list[i]);
        }
}


void cityitem::receiveData(int x)
{
    n = x;
}
void cityitem::on_back_clicked()
{
    this->close();
    this->matrix_graph.clear();
    emit firstwindow();
}
