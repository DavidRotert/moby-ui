#include "containerslistpage.h"
#include "ui_containerslistpage.h"

#include "containerlistitem.h"

#include <QGraphicsDropShadowEffect>

ContainersListPage::ContainersListPage(QWidget* parent) : QWidget(parent), ui(new Ui::ContainersListPage) {
    this->ui->setupUi(this);

    for (int i = 0; i < 2; ++i) {
        this->addNewContainerItem();
    }
}

ContainersListPage::~ContainersListPage() {
    delete ui;
}

void ContainersListPage::clickedNewContainer() {
    this->addNewContainerItem();
}

void ContainersListPage::addNewContainerItem() {
    ContainerListItem* widget = new ContainerListItem(this->ui->scrollarea);

    // Set shadow effect
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(10);
    effect->setXOffset(-3);
    effect->setYOffset(5);
    effect->setColor(Qt::gray);

    widget->setGraphicsEffect(effect);

    this->ui->scrollable_container_list->insertWidget(this->ui->scrollable_container_list->count() - 1, widget);
}
