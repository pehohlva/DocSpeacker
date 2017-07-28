#ifndef RE_DOCUMENT_OPEN_H
#define RE_DOCUMENT_OPEN_H
/*
 * re_document_open.h
 * 
 * Copyright 2017 dev <phohlva@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <QObject>
#include "Document_Handler.h"
#include <QCoreApplication>
#include <QObject>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QTimer>
#include <QUrl>
#include <QDir>
#include <QDate>
#include <QDateTime>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QtCore>
#include <QDirIterator>
#include <QStorageInfo>
#include <QCryptographicHash>
#include <QFileInfo>
#include <QBuffer>





class Document_Handler
{

public:
    Document_Handler();
    QString simple_open( const QString file );
    void handler_odt( const QString file );
    void handler_html( const QString file );
    void handler_pdf( const QString file );
    void handler_txtutils( const QString file );
    void handler_docx( const QString file );
    void handler_text_plain( const QString file );
    void show_zip( const QString file );
    void clear(); /// reset !!
    QString get_text() { return text_s;  }
    ~Document_Handler();

private:
    QString strip_tag(QByteArray istring); /// remove html tag or xml tag
    QString strip_tag(QString istring);
    QString html_s;
    QString text_s;
    QString converter;
    RamStream *ram;
};




#endif


