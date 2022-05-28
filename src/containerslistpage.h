#ifndef CONTAINERSLISTPAGE_H
#define CONTAINERSLISTPAGE_H

#include <QWidget>

namespace Ui {
    class ContainersListPage;
}

class ContainersListPage : public QWidget {
    Q_OBJECT

public:
    explicit ContainersListPage(QWidget* parent = nullptr);
    ~ContainersListPage();

private slots:
    void clickedNewContainer();

private:
    Ui::ContainersListPage* ui;

    void addNewContainerItem();
};

#endif // CONTAINERSLISTPAGE_H
