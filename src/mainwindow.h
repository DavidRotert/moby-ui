#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void init();

private slots:
    void clickedNavContainers();
    void clickedNavImages();
    void clickedNavVolumes();
    void clickedNavCompose();
    void clickedNavRegistries();

private:
    Ui::MainWindow* ui;

    QWidget* current_page_content;

    void clickedNavItem(QAbstractButton* btn, QWidget* page);

    void uncheckNavItems(QAbstractButton* ignore);
};

#endif // MAINWINDOW_H
