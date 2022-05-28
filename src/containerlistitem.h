#ifndef CONTAINERLISTITEM_H
#define CONTAINERLISTITEM_H

#include <QWidget>

namespace Ui {
    class ContainerListItem;
}

class ContainerListItem : public QWidget {
    Q_OBJECT

public:
    explicit ContainerListItem(QWidget *parent = nullptr);
    ~ContainerListItem();

private slots:
    void onDelete();

private:
    Ui::ContainerListItem *ui;
};

#endif // CONTAINERLISTITEM_H
