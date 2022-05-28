#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "containerslistpage.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) , ui(new Ui::MainWindow) {
    this->ui->setupUi(this);

    this->current_page_content = this->ui->content_frame;

    this->ui->nav_button_containers->toggle();
    this->clickedNavContainers();
}

MainWindow::~MainWindow() {
    delete this->ui;
}

void MainWindow::clickedNavContainers() {
    QToolButton* btn = this->ui->nav_button_containers;

    QWidget* page = new ContainersListPage(this->ui->content_widget);
    this->clickedNavItem(btn, page);

    //TODO: remove this in production and replace with real daemon check
    this->ui->docker_daemon_status_logo->setStyleSheet("color: rgb(224, 27, 36);");
    this->ui->docker_daemon_status_text->setText("Docker daemon not running");
}

void MainWindow::clickedNavImages() {
    QToolButton* btn = this->ui->nav_button_images;

    QWidget* page = new QWidget(this->ui->content_widget);
    this->clickedNavItem(btn, page);

    //TODO: remove this
    this->ui->docker_daemon_status_logo->setStyleSheet("color: green;");
    this->ui->docker_daemon_status_text->setText("Running");
}

void MainWindow::clickedNavVolumes() {
    QToolButton* btn = this->ui->nav_button_volumes;

    QWidget* page = new ContainersListPage(this->ui->content_widget);
    this->clickedNavItem(btn, page);
}

void MainWindow::clickedNavCompose() {
    QToolButton* btn = this->ui->nav_button_compose;

    QWidget* page = new ContainersListPage(this->ui->content_widget);
    this->clickedNavItem(btn, page);
}

void MainWindow::clickedNavRegistries() {
    QToolButton* btn = this->ui->nav_button_registries;

    QWidget* page = new ContainersListPage(this->ui->content_widget);
    this->clickedNavItem(btn, page);
}

void MainWindow::clickedNavItem(QAbstractButton* btn, QWidget* page) {
    this->ui->content_widget->layout()->replaceWidget(this->current_page_content, page);
    delete current_page_content;
    this->current_page_content = page;

    // Don't allow to uncheck current nav item
    if (btn->isCheckable() && !btn->isChecked()) {
        btn->toggle();
        return;
    }

    this->uncheckNavItems(btn);
}

/**
 *
 * @brief MainWindow::uncheckNavItems
 * @param ignore Don't uncheck this button
 */
void MainWindow::uncheckNavItems(QAbstractButton* ignore) {
    QList<QObject*> navItems = this->ui->nav_buttons->children();

    QObject* navItem;
    foreach(navItem, navItems) {
        QAbstractButton* navItemButton = dynamic_cast<QAbstractButton*>(navItem);
        if (navItemButton == ignore) {
            if (navItemButton->winId() == ignore->winId()) {
                ignore->setDisabled(true);

                continue;
            }
        } else if (navItemButton != nullptr) {
            navItemButton->setDisabled(false);
            if (navItemButton->isCheckable() && navItemButton->isChecked()) {
                navItemButton->setChecked(false);
            }
        }
    }
}
