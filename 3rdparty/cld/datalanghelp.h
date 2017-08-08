/*
 * datalanghelp.h
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

#ifndef DATALANGUAGETOOL_H
#define DATALANGUAGETOOL_H

#include <QBuffer>
#include <QChar>

#include <qlist.h>
#include <qhash.h>
#include <qfile.h>
#include <qbytearray.h>
#include <qstring.h>
#include <qchar.h>
#include <qvector.h>
#include <qdebug.h>
#include <QStringList>




class RamStream
{
  public:
  RamStream()
  :d(new QBuffer())
  {
  d->open(QIODevice::ReadWrite);
  start();
  }
  ~RamStream()
  {
   d->close();
  }
  bool clear()
  {
    d->write(QByteArray());
    return d->bytesAvailable() == 0 ? true : false;
  }
  qint64 ramwrite( QByteArray x ) {
    d->write(x);
    start();
    return d->bytesAvailable();
  }

  void start() {
    d->seek(0);
  }

  bool LoadFile( const QString file ) {
    if (clear()) {
     QFile f(file);
        if (f.exists()) {
          if (f.open(QFile::ReadOnly)) {
           d->write(f.readAll());
           f.close();
           start();
           return true;
          }
        }
    }
    return false;
  }
  bool PutOnFile( const QString file ) {
      QFile f(file);
      start();
      if (f.open(QFile::WriteOnly)) {
        uint bi = f.write(d->readAll());
        f.close();
        start();
        return bi > 0 ? true : false;
      }
   return false;
  }
  /// QDomDocument Dom() { return doc; }
  QBuffer *device() { return d; }
  //// bool isValid() { return doc.setContent(stream(),false,0,0,0);  }
  QByteArray stream() { return d->data(); }
  //// QDomDocument doc;
  QBuffer *d;
};



#endif
