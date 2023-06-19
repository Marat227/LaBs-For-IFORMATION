#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
	#include <cityitem.h>
		#include <QQueue>

			QT_BEGIN_NAMESPACE
			namespace Ui { class MainWindow; }
			QT_END_NAMESPACE
			struct index{
			int ii;
			int jj;
			};
			class MainWindow : public QMainWindow
			{
			Q_OBJECT
			public:
			int n = -1;

			public:
			MainWindow(QWidget *parent = nullptr);
			~MainWindow();
			bool empty();
			bool chain();
			bool table();
			void find_way();
			QString depth(int&, QVector<bool>
				, QString &);
				QString width(int &, QVector<bool>
					&, QString &);
					QString Deixtra(int &, QString &);
					void fill_matrix();
					int get_vert_pos(int);
					QVector<int>
						GetNbrs(int);
						void fill_table();
						bool AllVisited(QVector<bool>
							&);
							void FillLabels(int &);
							int GetWeight(int, int);

							signals:
							void send_data_vert (int n);

							private slots:
							void on_Create_clicked();

							void on_Answer_clicked();
							void on_Visual_clicked();
							void on_Accept_clicked();

							void on_Accept_2_clicked();

							void on_depth_clicked();

							void on_width_clicked();

							void on_Deikstra_clicked();

							void on_depth_2_clicked();

							private:
							Ui::MainWindow *ui;
							cityitem *graph;
							QVector<index>
								answer;
								QVector<QVector<int>
									> matrix_graph;
									QQueue<int>
										VertsQueue;
										QVector<int>
											vertexList;
											QVector<int> labelList {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};
#endif // MAINWINDOW_H