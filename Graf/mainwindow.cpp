#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
	#include <algorithm>
		#include <cmath>
			#include <QMessageBox>
				#include <ctime>
					void MainWindow::find_way()
					{
					int min = 9999, min_ = 9999;
					QVector<int>
						mini, mini_;
						QVector<index>
							answer;
							// Минимальное значение
							for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (min >= matrix_graph[i][j] && i != j && matrix_graph[i][j] != -1) min = matrix_graph[i][j];
							}
							mini.push_back(min);
							min = 9999;
							}
							// Редукция строк
							for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j && matrix_graph[i][j] != -1)
							{
							matrix_graph[i][j] -= mini[i];
							}
							}
							}
							mini.clear();
							// Поиск минимального в столбце
							for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (min > matrix_graph[j][i] && i != j && matrix_graph[j][i] != -1) min = matrix_graph[j][i];
							}
							mini.push_back(min);
							min = 9999;
							}
							// Удаление по столбцам
							for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j  && matrix_graph[i][j] != -1)
							{
							matrix_graph[i][j] -= mini[j];
							}
							}
							}
							mini.clear();
							// Оценка
							// Помечаем 0
							// Минимальные
							int count_0 = 0;
							for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix_graph[i][j] == 0 && i != j) count_0++;
							if (min > matrix_graph[i][j] && i != j && matrix_graph[i][j] != 0 && matrix_graph[i][j] != -1) min = matrix_graph[i][j];
							if (count_0 > 1) min = 0;
							}
							mini.push_back(min);
							min = 9999;
							count_0 = 0;
							}
							for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix_graph[j][i] == 0 && i != j) count_0++;
							if (min_ > matrix_graph[j][i] && i != j && matrix_graph[j][i] != 0 && matrix_graph[j][i] != -1) min_ = matrix_graph[j][i];
							if (count_0 > 1) min_ = 0;
							}
							mini_.push_back(min_);
							min_ = 9999;
							count_0 = 0;
							}
							//Добавление к 0
							int max = -1;
							index ind;
							for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j && matrix_graph[i][j] == 0)
							{
							if (max < mini[i] + mini_[j])
                {
                    ind.ii = i;
                    ind.jj = j;
                    max = mini[i] + mini_[j];
                }
            }
        }
    }
    max = 0;
    this->answer.push_back(ind);
    // Удаление строк и столбцов
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j && (i == ind.ii || j == ind.jj))
							{
							matrix_graph[i][j] = -1;
							}
							}
							}
							}

							MainWindow::MainWindow(QWidget *parent)
							: QMainWindow(parent)
							, ui(new Ui::MainWindow)
							{
							ui->setupUi(this);

							graph = new cityitem();
							connect(graph, &cityitem::firstwindow, this, &MainWindow::show);
							connect(this, SIGNAL(send_data_vert(int)), graph, SLOT(recievData(int)));
							}

							MainWindow::~MainWindow()
							{
							delete ui;
							}


							void MainWindow::on_Create_clicked()
							{
							int size = ui->City->text().toInt();
							if (size > 10) QMessageBox::warning(this, "Ошибка", "Максимальный размер графа равен 10!");
							else
							{
							ui->LinksTable->setRowCount(size);
							ui->LinksTable->setColumnCount(size);
							int temp = 0;
							for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ui->LinksTable->setItem(i,j,new QTableWidgetItem(temp));
            }
        }
        n = size;
        for(int i = 0; i < size;i++)
        {
            ui->LinksTable->setColumnWidth(i,1);
            ui->LinksTable->setItem(i,i,new QTableWidgetItem(temp));
            ui->LinksTable->item(i, i)->setText("0");
            this->vertexList.push_back(i);
        }
    }
}
bool MainWindow::empty()
{
    for(int i = 0; i < n; i++)
    {
        for(int j  = 0; j < n; j++)
        {
            if(!(ui->LinksTable->item(i,j)))
            {
                QMessageBox::warning(this, "Ошибка", "Запишите информацию во все ячейки.");
                return 0;
            }
        }
    }
    return 1;
}
bool MainWindow::chain()
{
    for(int i = 0; i < n; i++)
    {
        if(ui->LinksTable->item(i,i)->text() != "0")
        {
            QMessageBox::warning(this, "Ошибка", "Не создавайте путь между одним и тем же городом.");
            return 0;
        }
    }
    return 1;
}
bool MainWindow::table()
{
    if (n > 1) return 1;
    QMessageBox::warning(this, "Ошибка", "Для использования данной функции создайте таблицу.");
    return 0;
}
void MainWindow::on_Answer_clicked()
{
    if(empty() && chain() && table())
							{
							QVector<int>
								temp;
								for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
               temp.push_back(ui->LinksTable->item(i,j)->text().toInt());
            }
            matrix_graph.push_back(temp);
            temp.clear();
        }
        int counter = 0;
        while (counter < n)
        {
            find_way();
            counter++;
        }
        matrix_graph.clear();
        QString ans;
        for (int i = 0; i < n; ++i)
        {
            if(answer[i].ii != 0)
            {
                for (int j = i+1; j < n; ++j)
                {
                    if(j != n-1 && answer[j].ii == 0)
								{
								index swap = answer[i];
								answer[i] = answer[j];
								answer[j] = swap;
								}
								}
								}
								if(answer[i].jj == 0 && i != n -1)
								{
								for (int j = i+1; j < n; ++j)
                {
                    index swap = answer[i];
                    answer[i] = answer[n-1];
                    answer[n-1] = swap;
                }
            }
            if(i != n-1 && answer[i].jj != answer[i+1].ii)
								{
								for (int j = i+2; j < n; ++j)
                {
                    if(i != n-1 && answer[i].jj == answer[j].ii)
								{
								index swap = answer[i+1];
								answer[i+1] = answer[j];
								answer[j] = swap;
								}
								}
								}

								}
								for (int i = 0; i < n; i++)
        {
            ans = ans + QString::number(answer[i].ii + 1) + " -> ";
        }
        ans += '1';
        int lengh = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if(i != n - 1)
                lengh += ui->LinksTable->item(answer[i].ii, answer[i+1].ii)->text().toInt();
        }
        lengh += ui->LinksTable->item(answer[n-1].ii, 0)->text().toInt();
        ans = ans + " Длина = " + QString::number(lengh);
        QMessageBox::information(this, "Ответ", ans);
        answer.clear();
        //
    }
}
void MainWindow::on_Visual_clicked()
{
   if (n > 10 || n <= 1)
								{
								if (n > 10) QMessageBox::warning(this, "Ошибка", "Максимальный размер графа равен 10!");
								else QMessageBox::warning(this, "Ошибка", "Размер графа не может быть равен 0!");
								}
								else
								{
								if (empty() && chain())
								{
								graph->set_size(n);
								for (int i = 0; i < n; ++i)
           {
               for (int j = 0; j < n; ++j)
               {
                   graph->temp.push_back(ui->LinksTable->item(i,j)->text());
               }
               graph->matrix_graph.push_back(graph->temp);
               graph->temp.clear();
           }
           graph->show();
           graph->receiveData(n);
       }
   }
}


void MainWindow::on_Accept_clicked()
{
    if (n == 10) QMessageBox::warning(this, "Ошибка", "Максимальный размер графа был достигнут!");
    else
    {
        this->vertexList.push_back(n);
        n += 1;
        ui->LinksTable->setRowCount(n);
        ui->LinksTable->setColumnCount(n);
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            ui->LinksTable->setRowHeight(i,1);
            ui->LinksTable->setColumnWidth(i,1);
            ui->LinksTable->setItem(i,i,new QTableWidgetItem(temp));
            ui->LinksTable->item(i, i)->setText("0");
        }
        ui->City->setText(QString::number(n));
    }
}

void MainWindow::on_Accept_2_clicked()
{
    this->vertexList.pop_back();
    n -= 1;
    ui->LinksTable->setRowCount(n);
    ui->LinksTable->setColumnCount(n);
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        ui->LinksTable->setRowHeight(i,1);
        ui->LinksTable->setColumnWidth(i,1);
        ui->LinksTable->setItem(i,i,new QTableWidgetItem(temp));
        ui->LinksTable->item(i, i)->setText("0");
    }
    ui->City->setText(QString::number(n));
}
void MainWindow::fill_table()
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j) ui->LinksTable->item(i, j)->setText(QString::number(rand()%10 + 5));
}
void MainWindow::fill_matrix()
{
    if(empty() && chain() && table())
								{
								QVector<int>
									temp;
									for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
               temp.push_back(ui->LinksTable->item(i,j)->text().toInt());
            }
            this->matrix_graph.push_back(temp);
            temp.clear();
        }

    }
}
// Обход в глубину
QString MainWindow::depth(int& startVertex, QVector<bool>
										visitedVerts, QString &res)
										{
										if (visitedVerts[this->get_vert_pos(startVertex)] == false)
										{
										this->VertsQueue.push_back(startVertex);
										res += "Вершина " + QString::number(startVertex + 1) + " обработана\n" ;
										visitedVerts[this->get_vert_pos(startVertex)] = true;
										}
										QVector<int>
											neighbors = this->GetNbrs(startVertex);
											this->VertsQueue.pop_front();
											for (int i = 0; i < neighbors.size(); ++i)
    {
        if (!visitedVerts[this->get_vert_pos(neighbors[i])])
        {
            this->VertsQueue.push_back(neighbors[i]);
            visitedVerts[this->get_vert_pos(neighbors[i])] = true;
            res += "Вершина " + QString::number(neighbors[i] + 1) + " обработана\n";
        }
    }
    if (!this->VertsQueue.empty()) depth(VertsQueue.front(), visitedVerts, res);
    return res;
}
// Обход в ширину
QString MainWindow::width(int &start, QVector<bool>
												& visitedVerts, QString &res)
												{
												res+= "Вершина " + QString::number(start+1) + " обработана\n";
												visitedVerts[this->get_vert_pos(start)] = true;
												QVector<int>
													neighbors = this->GetNbrs(start);
													for (int i = 0; i < neighbors.size(); ++i){
        if (!visitedVerts[this->get_vert_pos(neighbors[i])])
            this->width(neighbors[i], visitedVerts, res); }
    return res;
}
bool MainWindow::AllVisited(QVector<bool>
														&visitedVerts)
														{
														bool flag = true;
														for (int i = 0; i < this->vertexList.size(); i++)
        if (visitedVerts[i] != true)
            flag = false;
    return flag;
}

void MainWindow::FillLabels(int &start)
														{
														for (int i = 0, size = vertexList.size(); i < size; ++i)
            labelList[i] = 1000000;
        int pos = get_vert_pos(start);
        labelList[pos] = 0;
};
int MainWindow::GetWeight(int x, int y)
{
    this -> fill_matrix();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i == x && j == y)
														return matrix_graph[i][j];
														return 0;
														}
														QString MainWindow::Deixtra(int &start, QString &res)
														{
														for (int i = 0; i < vertexList.size(); i++)
        for (int j = 0; j < vertexList.size(); j++)
            if (matrix_graph[i][j] < 0)
                return res;
    if (get_vert_pos(start) == -1)
        return res;
    QVector<bool>
															visitedVerts(vertexList.size());
															for (auto it = visitedVerts.begin(); it!=visitedVerts.end(); ++it) *it = false;

															this->FillLabels(start);
															int curSrc = start;
															QVector<int>
																neighbors;

																while (!this->AllVisited(visitedVerts))
																{
																neighbors = this->GetNbrs(curSrc);
																int startLabel = labelList[get_vert_pos(curSrc)];

																int* minNeighbor_ptr = nullptr;
																int minW = 1000000;

																for (int i = 0; i < neighbors.size(); ++i)
        {
            int weight = this->GetWeight(curSrc, neighbors[i]);
            int nIndex = this->get_vert_pos(neighbors[i]);
            int nextLabel = labelList[nIndex];

            if (startLabel + weight < nextLabel) labelList[nIndex] = startLabel + weight;

            if (!visitedVerts[nIndex] && minW > labelList[nIndex])
																{
																minW = labelList[nIndex];
																minNeighbor_ptr = &neighbors[i];
																}
																}
																visitedVerts[get_vert_pos(curSrc)] = true;
																if (minNeighbor_ptr != nullptr) curSrc = *minNeighbor_ptr;
																}

																for (int i = 0; i < vertexList.size(); ++i)
    {
        if (i != get_vert_pos(start)){
            res+= "Кратчайшее расстояние от вершины " + QString::number(start + 1)
                + " до вершины "  + QString::number(vertexList[i] + 1) + " равно "
                + QString::number(labelList[get_vert_pos(vertexList[i])]) + "\n";
        }
    }
    return res;

}
void MainWindow::on_Deikstra_clicked()
{
    QVector<bool>
																	visitedVerts = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
																	QString detour;
																	this->fill_matrix();
																	int start = 0;
																	detour = Deixtra(start, detour);
																	QMessageBox::information(this, "Обход в глубину", detour);
																	}
																	void MainWindow::on_depth_clicked()
																	{
																	QVector<bool>
																		visitedVerts = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
																		QString detour;
																		this->fill_matrix();
																		int start = 0;
																		detour = depth(start, visitedVerts, detour);
																		QMessageBox::information(this, "Обход в ширину", detour);
																		}
																		void MainWindow::on_width_clicked()
																		{
																		QVector<bool>
																			visitedVerts = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
																			QString detour;
																			this->fill_matrix();
																			int start = 0;
																			detour = width(start, visitedVerts, detour);
																			QMessageBox::information(this, "Обход в глубину", detour);
																			}
																			int MainWindow::get_vert_pos(int a)
																			{
																			fill_matrix();
																			for (int i = 0; i < n; i++)
    {
        if (a == i)
            return i;
    }
    return -1;
}
QVector<int>
																				MainWindow::GetNbrs(int start)
																				{
																				QVector<int>
																					nbrs;
																					fill_matrix();
																					int pos = this->get_vert_pos(start);
																					if (pos != -1)
																					{
																					for (int i = 0; i < n; i++)
        {
            if (this->matrix_graph[pos][i] != 0)
            {
                nbrs.push_back(this->vertexList[i]);
            }
        }
    }
    return nbrs;
}


void MainWindow::on_depth_2_clicked()
{
    fill_table();
}
