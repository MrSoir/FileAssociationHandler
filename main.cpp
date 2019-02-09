#include "mainwindow.h"
#include <QApplication>
#include <QFileInfo>
#include <QString>
#include <QDebug>

#include <Windows.h>
#include <stdio.h>
#include <strsafe.h>
#include <iostream>
#include <string>
#include <Windows.h>

#include "registry.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString file_path("D:\\Rotkaeppchen\\DOWNLOADS_SD\\BEFUND.PDF");
    QFileInfo fi(file_path);
    qDebug() << "file exists: " << fi.exists();

    getFileAssociatedApps(L".pdf");

    return a.exec();
}
