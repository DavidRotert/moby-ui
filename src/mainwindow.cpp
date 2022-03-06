#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete this->ui;
}

void MainWindow::clickedNavContainers() {
    QToolButton* btn = this->ui->nav_button_containers;

    this->clickedNavItem(btn);

    //TODO: remove this
    this->ui->docker_daemon_status_logo->setStyleSheet("color: rgb(224, 27, 36);");
    this->ui->docker_daemon_status_text->setText("Docker daemon not running");
}

void MainWindow::clickedNavImages() {
    QToolButton* btn = this->ui->nav_button_images;

    this->clickedNavItem(btn);

    //TODO: remove this
    this->ui->docker_daemon_status_logo->setStyleSheet("color: green;");
    this->ui->docker_daemon_status_text->setText("Running");
}

void MainWindow::clickedNavVolumes() {
    QToolButton* btn = this->ui->nav_button_volumes;

    this->clickedNavItem(btn);
}

void MainWindow::clickedNavCompose() {
    QToolButton* btn = this->ui->nav_button_compose;

    this->clickedNavItem(btn);
}

void MainWindow::clickedNavRegistries() {
    QToolButton* btn = this->ui->nav_button_registries;

    this->clickedNavItem(btn);
}

void MainWindow::clickedNavItem(QAbstractButton *btn) {
    if (btn->isCheckable() && !btn->isChecked()) {
        btn->toggle();
        return;
    }

    this->uncheckNavItems(btn);
}

void MainWindow::uncheckNavItems(QAbstractButton* ignore) {
    QList<QObject*> navItems = this->ui->nav_buttons->children();

    QObject* navItem;
    foreach(navItem, navItems) {
        QAbstractButton* navItemButton = dynamic_cast<QAbstractButton*>(navItem);
        if (navItemButton == ignore) {
            if (navItemButton->winId() == ignore->winId()) {
                continue;
            }
        } else if (navItemButton != nullptr) {
            if (navItemButton->isCheckable() && navItemButton->isChecked()) {
                navItemButton->toggle();
            }
        }
    }
}
