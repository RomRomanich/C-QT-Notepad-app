#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QDebug>
#include <QStatusBar>
#include <QMessageBox>
#include <QTextEdit>
#include <QTextCursor>
#include <QVector>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QPalette>
#include <QThread>
#include <QCloseEvent>
#include "finddialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
//    1 menu
    void action_new();
    void action_new_window();
    void action_open();
    void action_save();
    void action_save_as();
    void action_print();
    void action_exit();
//    2 menu
    void action_undo();
    void action_cut();
    void action_copy();
    void action_paste();
    void action_delete();
    void action_find();
    void action_select_all();
    void action_date_time();
//    3 menu
    void action_font();
    void action_color();
    void action_background_color();
    void action_backgroud_color_edit_text();
//    4 menu
    void action_zoom_in();
    void action_zoom_out();
    void action_default_zoom();
    void action_status_bar();
//    5 menu
    void action_view_help();
    void action_send_feedback();
    void action_about_notepad();

public:
    int save_file();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void create_actions();
    void create_menus();
    virtual void closeEvent(QCloseEvent* event);

private:
    QVector<QMenu*> *menus;
    QVector<QAction*> *actions;
    QString file_path;
    QString file_dir;
    QString file_status;
    QTextEdit* text_edit;
    QTextEdit* feedbackEdit;
    FindDialog *findDialog;

    // Some actions
    QAction* undo;
    QAction* cut;
    QAction* copy;
    QAction* paste;
    QAction* dlte;
    QAction* fnd;
    QAction* find_next;
    QAction* find_pevious;
    QAction* status_bar;

private slots:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);


};

#endif // MAINWINDOW_H
