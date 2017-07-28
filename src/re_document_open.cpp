/*
 * re_document_open.cpp
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




Document_Handler::Document_Handler() {
  ram = new RamStream();
  ram->start();
}



QString Document_Handler::simple_open( const QString file ) {
  text_s = QString("Not possibel to load Document:%1").arg(file);
  QMimeDatabase mimeDatabase;
  QMimeType mimeType;
  /*  https://developer.apple.com/legacy/library/documentation/Darwin/Reference/ManPages/man1/textutil.1.html   */
  QString helper = run_which("textutil"); /// mac only convert txt, /// html, rtf, rtfd, doc, docx, wordml, odt, or webarchive
    if (helper.size() > 5) {
      converter=helper;
      //// 
    }
  QFileInfo ifile(file);
    if ( ifile.exists()  ) {
        const QString extension = ifile.suffix().toLower();
        mimeType = mimeDatabase.mimeTypeForFile(ifile);
        QStringList alii = mimeType.aliases();
        qDebug() << "### comment " <<  mimeType.comment();
        qDebug() << "### alias " <<  alii;
        ////  RTF format go inside text/plain!!  text/rtf
        if (extension == "rtf" || alii.contains("text/rtf") ||
            extension == "wordml" || extension == "doc" ||
            extension == "rtfd" || extension == "webarchive") {
             this->handler_txtutils(file);
             //// xml html all here and strip tag
        } else if (mimeType.inherits("text/plain")) {
             this->handler_text_plain(file);
        } else if (extension == "odt") {
             this->handler_txtutils(file);
         } else if (extension == "sxw") {
            this->handler_odt(file);
         }  else if (extension == "html" || extension == "htm") {
            this->handler_html(file);
         } else if (extension == "pdf") {
             this->handler_pdf(file);
          } else if (extension == "docx") {
             this->handler_txtutils(file);
          }
    }

    return text_s;
}

void Document_Handler::handler_text_plain( const QString file ) {
	 qDebug() << "### handler use-> " <<  __FUNCTION__;
     ram->LoadFile(file);
     const QByteArray base = ram->stream();
     if (base.size() > 0 ) {
        text_s =  this->strip_tag(base);
     }
}

void Document_Handler::handler_html( const QString file ) {
	  qDebug() << "### handler use-> " <<  __FUNCTION__;
      ram->LoadFile(file);
      const QByteArray base = ram->stream();
       if (base.size() > 0 ) {
          text_s =  this->strip_tag(base);
       }

}

void Document_Handler::handler_pdf( const QString file ) {
	   qDebug() << "### handler use-> " <<  __FUNCTION__;
       QPdfium pdf(file);
       QString grep;
       const int sumpage =  pdf.pageCount();
       const int last = sumpage - 1;
       ///  std::cout << "sumpage:"  << sumpage << std::endl;
       for (int i = 0; i <=sumpage; i ++) {
             if (i <= last ) {
                 QPdfiumPage page =  pdf.page(i);
                 grep.append(page.text());
             }
             //// std::cout << "for:"  << i << std::endl;
       }
       text_s =  grep;
}


void Document_Handler::handler_odt( const QString file ) {
	qDebug() << "### handler use-> " <<  __FUNCTION__;
  QMap<QString,QByteArray>  filist = unzipstream(file);
  const QByteArray base = filist["content.xml"];
    if (base.size() > 0 ) {
       if (ram->ramwrite(base) > 1 && ram->isValid()) {
          QDomDocument body = ram->Dom(); //// parse down... body.toString(5);
          text_s =  this->strip_tag(base);
          //// qDebug() << "### valid all ";
       }
    }
}

void Document_Handler::handler_txtutils( const QString file ) {
	qDebug() << "### handler use-> " <<  __FUNCTION__;
     //// converter = /usr/bin/textutil
     if (converter.size() < 4) {
       text_s = QString("textutil -convert .. unable to read! or not mac osx.");
     }
    //// ram->LoadFile(file);
    //// const QByteArray base = ram->stream();
    QProcess *process = new QProcess(NULL);
    process->setReadChannelMode(QProcess::MergedChannels);
    process->start(converter,  QStringList() << "-convert" << "txt" << file << "-stdout", QIODevice::ReadOnly );
      if (!process->waitForFinished()) {
           text_s = QString("Unable to read!.");
      } else {
           text_s = strip_tag(process->readAll());
      }

        ///// qDebug() << "### text_s " << text_s;
}

void Document_Handler::handler_docx( const QString file ) {
	qDebug() << "### handler use-> " <<  __FUNCTION__;
  QMap<QString,QByteArray>  filist = unzipstream(file);
  const QByteArray base = filist["word/document.xml"];
    if (base.size() > 0 ) {
       if (ram->ramwrite(base) > 1 && ram->isValid()) {
          QDomDocument body = ram->Dom(); //// parse down... body.toString(5);
          text_s =  this->strip_tag(base);
          //// qDebug() << "### valid all ";
       }
    }
}

QString Document_Handler::strip_tag(QString istring) {
	
	QByteArray longx;
    longx.append(istring.toLatin1());
	return this->strip_tag(longx);
}

QString Document_Handler::strip_tag(QByteArray istring) {
	qDebug() << "### handler use-> " <<  __FUNCTION__;

    bool intag = false;
    QChar newbr(10);
    QByteArray br;
    br.append(newbr.toLatin1());
    QByteArray new_string;
    for (int i = 0; i < istring.length(); i++) {
        QChar vox(istring.at(i));
        int letter = vox.unicode(); /// <60 62>
        if (letter != 60 && !intag) {
            new_string += istring.at(i);
        }
        if (letter == 60 && !intag) {
            intag = true;
        }
        if (letter == 62 && intag) {
            intag = false;
            new_string += br; //// append new line..

        }
    }


    QString clean = QString(new_string).trimmed();
    QStringList alline = clean.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    return alline.join(" ");;
}


void Document_Handler::show_zip( const QString file ) {
  QMap<QString,QByteArray>  filist = unzipstream(file);
  QMapIterator<QString,QByteArray> i(filist);
      while (i.hasNext()) {
          i.next();
          qDebug() << "### name->" << i.key();
      }
}


void Document_Handler::clear() {
	text_s = QString("NULL_ERROR!");
}

Document_Handler::~Document_Handler()
{
   ram->~RamStream();
}



