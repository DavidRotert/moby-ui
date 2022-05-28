#include "containerlistitem.h"
#include "ui_containerlistitem.h"

#include <vector>

ContainerListItem::ContainerListItem(QWidget *parent) : QWidget(parent), ui(new Ui::ContainerListItem) {
    this->ui->setupUi(this);
}

ContainerListItem::~ContainerListItem() {
    delete ui;
}

void ContainerListItem::onDelete() {
    delete this;
}
