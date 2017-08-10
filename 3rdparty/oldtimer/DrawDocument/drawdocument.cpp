#include "drawdocument.h"

void DrawDoument::updateDocument() {
  htmlformat.setLeftMargin(MM_TO_POINT(30));
  htmlformat.setRightMargin(MM_TO_POINT(25));
  htmlformat.setBottomMargin(MM_TO_POINT(35)); /// paint cut 30
  htmlformat.setTopMargin(MM_TO_POINT(18));
  doc->rootFrame()->setFrameFormat(htmlformat);

  /// QTextDocumentPrivate   cursorPositionChanged
}

DrawDoument::DrawDoument(QWidget * parent):
        QAbstractScrollArea(0),
        lineTimer(0),
        scaleFaktor(1.367),
        Beeboncontroll(false),
        doc(new QTextDocument()),
        portrait_mode(true) {

        lastkeyMETA = false;
        CursorPosition = -1;
        doc->setPageSize(QSizeF(MM_TO_POINT(210), MM_TO_POINT(297)));
        htmlformat = doc->rootFrame()->frameFormat();
        this->setMinimumHeight(480);
        this->setMinimumWidth(460);
        this->resize(900, 499);
        if (htmlformat.leftMargin() < 10) {
           this->updateDocument();
        }
        this->setContentsMargins(0,0,0,0);
        setAcceptDrops(true);
        QTimer::singleShot(700, this, SLOT(LoadFile())); /// not overload painter...
        connect(doc->documentLayout(), SIGNAL(update(QRectF)),this, SLOT(updatedoc(QRectF)));
        connect(this, SIGNAL(newdata()),this, SLOT(updateslow()));
        updateslow();


}

bool DrawDoument::event( QEvent * e) {
   const int xmac = e->type();
     if (doc->documentLayout()->event(e)) {
          qDebug() << "HEI is a doument event!!!!" <<  __FUNCTION__;
      }
    if (xmac == 197) {

     }

 #ifdef QT_KEYPAD_NAVIGATION
    if (QApplication::keypadNavigationEnabled()) {
        qDebug() << "HEI is a keypadNav  event!!!!" <<  __FUNCTION__;
      }
 #endif


    return QAbstractScrollArea::event(e);
}

void DrawDoument::updatedoc(QRectF area) {

     qDebug() <<  __FUNCTION__ << " Area new date ->" << area.center().x() << "x" << area.center().y();
     /*  QPainter * p = new QPainter(viewport());
     p->setRenderHint(QPainter::Antialiasing, true);
     //// paintArea(p,area, _EDITORBGCOLOR_);
     p->setBrush(Qt::blue);
     p->drawRect(area);
     p->save();
     p->end(); */
     //// emit newdata();
}

void DrawDoument::paintEvent( QPaintEvent * ev ) {

  const QRectF viewAreaRect(0, 0, viewport()->width(), viewport()->height());
  //// lineTimer++;
  //// qDebug() <<  __FUNCTION__  << " lineTimer->" <<  lineTimer << " - " << viewAreaRect.height();
  htmlformat = doc->rootFrame()->frameFormat();
  QTransform matrix; ///* zero matrix
  QPainter * p = new QPainter(viewport());
  p->setRenderHint(QPainter::Antialiasing, true);
  paintArea(p,ev->rect(), _EDITORBGCOLOR_);

  const int y = yOffset();
  const int x = xOffset();
  p->translate(-x, -y);
  p->setWorldTransform(mcurrent, true); ///   zoom && center on adjustScrollbars()
  const int PageSumm = qBound(1, doc->pageCount(), MaximumPages);
  p->save();
  for (int o = 0; o < PageSumm; ++o) {
    paintEditPage(o, p);
  }
  p->end();
  p = 0;
}



/*


void DrawDoument::mousePressEvent(QMouseEvent * e) {

}

void DrawDoument::mouseDoubleClickEvent(QMouseEvent * e) {

}







*/


void DrawDoument::adjustScrollbars() {
  ////  portrait - landscape
  qreal lmax = 10 + qMax(doc->pageSize().width(), doc->pageSize().height());
  qreal lmin = 10 +  qMin(doc->pageSize().width(), doc->pageSize().height());
  if (portrait_mode) {
    page = QRectF(0, 0, lmin, lmax);
  } else {
    page = QRectF(0, 0, lmax, lmin);
  }
  const qreal left_slide = SLIDERMARGIN_TICK_TOTAL;

  const int PageSumm = qBound(1, doc->pageCount(), MaximumPages);

  workArea = QSize(page.width() * scaleFaktor, (page.height() * scaleFaktor) * PageSumm);
  bool stayinwi = workArea.width() < viewport()->width() ? true : false;
  bool stayinhi = workArea.height() < viewport()->height() ? true : false;
  qreal border_wi = left_slide;
  qreal border_hi = 0.1;
  if (stayinwi) {
    border_wi = qMax(left_slide, qAbs((qreal)(workArea.width() / 2) - (viewport()->width() / 2)));
  } else {
    border_hi = left_slide;
  }

  mcurrent = QTransform(scaleFaktor, 0., 0., scaleFaktor, border_wi + PAPERSPACE, SLIDERMARGIN_TICK_TOTAL + PAPERSPACE); ////// ultimo da sopra penultimo da sinistra
  QSize viewPanelSize = viewport()->size();
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  verticalScrollBar()->setPageStep(workArea.height()); ////* zoom state
  horizontalScrollBar()->setPageStep(workArea.width()); ////* zoom state
  verticalScrollBar()->setRange(0, workArea.height() - viewPanelSize.height() + SLIDERMARGIN_TICK_TOTAL * 3);
  horizontalScrollBar()->setRange(0, (page.width() * scaleFaktor) - viewPanelSize.width() + SLIDERMARGIN_TICK_TOTAL * 3);
}


void DrawDoument::paintgopen(QPainter * painter , int wi , QColor co) {
  //// QPen  pen=painter->pen();
  QPen  fora(co);
        fora.setWidth(wi); /// Qt::SolidLine,

  if (wi < 2 ) {
       painter->setPen(Qt::NoPen);
    } else {
      /// pen as margin transparent
      painter->setPen(fora);

    }
}


void DrawDoument::wheelEvent(QWheelEvent * e) {
     if (e->phase() !=Qt::ScrollEnd) {
      if (static_cast<QWheelEvent*>(e)->orientation() == Qt::Horizontal) {
            QApplication::sendEvent(horizontalScrollBar(), e);
       } else {
            QApplication::sendEvent(verticalScrollBar(),e);
       }
      }

        if( e->modifiers() & Qt::ShiftModifier )
         {
            qDebug() <<  __FUNCTION__ << " ShiftModifier->" << e->KeyRelease << "-";
         }
         else if( e->modifiers() & Qt::ControlModifier )
         {
            qDebug() <<  __FUNCTION__ << " ControlModifier->" << e->KeyRelease << "-";
         }
}

void DrawDoument::paintEditPage(const int index, QPainter * painter) {
  //// painter->save();
  const qreal hip = doc->pageSize().height();
  const qreal fromtop = index * hip;
  const qreal diff = 5 * 4; /// shadow page white hight
  QRectF viewarea(QPointF(0,fromtop),doc->pageSize());
  const QRectF body = QRectF(viewarea.topLeft(),viewarea.size());
  if (index == 0) {
      /// paint image page ground only 1 time e class save.
      xpage = onepageimage(QRectF(0,0,body.size().width(),body.size().height()),diff);
    }

  //// qDebug() <<  __FUNCTION__ << " ->" << index << "-" << fromtop;
  QAbstractTextDocumentLayout::PaintContext CTX;
  CTX.palette.setColor(QPalette::Text, Qt::black);
  //// const QRectF body = QRectF(viewarea.topLeft(),viewarea.size()); /* on view */
  QRectF view(viewarea.topLeft(),viewarea.size());   /* on doc */
  painter->save();
  painter->setClipRect(view);
  painter->drawImage(view,xpage);
  CTX.clip = view;
  CTX.cursorPosition = CursorPosition;
  paintgopen(painter,0);
  doc->documentLayout()->setProperty("basic_point",QVariant(index)); /// register if is paint or not! page nr.x
  doc->documentLayout()->draw(painter,CTX);
  painter->restore();
}


void DrawDoument::triggerFormat() {
  portrait_mode = portrait_mode == true ? false : true;
  if (portrait_mode) {
    doc->setPageSize(QSizeF(MM_TO_POINT(210), MM_TO_POINT(297)));
  } else {
    doc->setPageSize(QSizeF(MM_TO_POINT(297), MM_TO_POINT(210)));
  }
    emit newdata();
}




void DrawDoument::fitToNormal() {
  /// setZoom(1.0);
}




void DrawDoument::resizeEvent(QResizeEvent * e) {

    this->updateslow();
}


void DrawDoument::updateslow() {
   updateDocument();
   viewport()->update();
   adjustScrollbars();
   docLayout = doc->documentLayout();
}


void DrawDoument::keyReleaseEvent(QKeyEvent *event) {

  if (lastkeyMETA) {
       if (Beeboncontroll) {
         QApplication::beep();
        }
      lastkeyMETA = false; /// close cyle from keyPressEvent

    }

}

/*   Qt::Key_Down	0x01000015
Qt::Key_PageUp	0x01000016  Qt::Key_Control
Qt::Key_PageDown */
void DrawDoument::keyPressEvent(QKeyEvent * e) {
  bool CONTROLLACTIVE, savekey = false;

   if (Qt::Key_Meta == e->key() ||
                 Qt::Key_Control == e->key() ||
                 Qt::Key_Escape == e->key() ) { /// window & mac || Qt::Key_Up == e->key()  || Qt::Key_Down == e->key()
      lastkeyMETA = true;
       if (Beeboncontroll) {
        QApplication::beep();
       }
    }
    //// qDebug() <<  __FUNCTION__ << " - e->key()" << e->key() << " lastkeyMETA:" << lastkeyMETA;
    if (lastkeyMETA || e->isAutoRepeat() ) {
         if (Qt::Key_PageUp == e->key() ) {
                //// qDebug() <<  "salire su page scroll";
                e->accept();
                emit newdata();
                return;
          } else
           if (Qt::Key_PageDown == e->key() ) {
                //// qDebug() <<  "giuuu page scroll ";
                e->accept();
                emit newdata();
                return;
          } else
            if (Qt::Key_Up == e->key() ) {
                scaleFaktor = scaleFaktor + 0.05;
                if (scaleFaktor < 0.22 || scaleFaktor > 10) {
                 scaleFaktor = 9.9;
                 //// this->setZoom(scaleFaktor);
                }
                emit newdata();
                e->accept();
                return;
          } else
            if (Qt::Key_Down == e->key()) {
                scaleFaktor = scaleFaktor - 0.05;
                if (scaleFaktor < 0.22 || scaleFaktor > 10) {
                 scaleFaktor =0.23;
                 //// this->setZoom(scaleFaktor);
                }
                emit newdata();
                e->accept();
                return;
            }
         }

        e->accept();
        //// qDebug() <<  __FUNCTION__ << " ende - e->isAutoRepeat()" << e->isAutoRepeat();
}

void DrawDoument::contextMenuEvent(QContextMenuEvent * event) {
  QMenu * menu = new QMenu(this);
  menu->addAction(tr("Open File html"), this, SLOT(OpenFile()));
  menu->addAction(tr("Swap page format"), this, SLOT(triggerFormat()));
  menu->addAction(tr("Fit size to Page"), this, SLOT(fitToLarge()));
  menu->exec(event->globalPos());
  delete menu;
}


/*
 *
 *



void DrawDoument::zoomIn() {
  setZoom(mcurrent.m11() + SCALING_STEEP);
}

void DrawDoument::zoomOut() {
  setZoom(mcurrent.m11() - SCALING_STEEP);
}




*/

void DrawDoument::OpenFile() {
  ////  only to test html
  QString file = QFileDialog::getOpenFileName(this,
    tr("Open File to read"), qApp->applicationDirPath(), tr("Files (*)"));
  if (!file.isEmpty()) {
    StreamBuf * buf = new StreamBuf();
    buf->LoadFile(file);
    doc->setHtml(buf->data());
    buf->~StreamBuf();
    emit newdata();
  }
}

void DrawDoument::LoadFile() {
  StreamBuf *buff = new StreamBuf();
  buff->LoadFile("./index.html");
  doc->setHtml(buff->stream());
  buff->~StreamBuf();
  QString textplain = doc->toPlainText();
    if (textplain.size() < 10) {
      this->OpenFile();
        return;
    }
    emit newdata();
}


void DrawDoument::setZoom(const qreal value) {
  if (value < 0.22 || value > 10) {
      scaleFaktor = 1.3;
  } else {
    qDebug() << "### setZoom " << value;
    scaleFaktor = value;
    adjustScrollbars();
    viewport()->update();
  }
  QTimer::singleShot(150, this, SLOT(updateslow()));
}

void DrawDoument::fitToLarge() {
  qDebug() <<  __FUNCTION__;
  qreal scaleFaktor = 4;
#ifndef QT_NO_GRAPHICSEFFECT
   qDebug() <<  __FUNCTION__ << " QT_NO_GRAPHICSEFFECT";
#endif
       QSizeF vdocument = doc->pageSize();
      qreal posibel = viewport()->width();
      QRect screens = QApplication::desktop()->availableGeometry();
      int largox = screens.width() / 2;
      int altox = screens.height() / 2;
      qDebug() <<  largox << "x" << altox << " innrt:" << (posibel / vdocument.width() * 1.3) << "x";
      setZoom((posibel / vdocument.width() * 2));
}
