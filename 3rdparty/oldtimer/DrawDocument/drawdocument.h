#ifndef DRAWDOUMENT_H
#define DRAWDOUMENT_H

#include "tooldoc.h"

class DrawDocument: public QAbstractScrollArea {
   Q_OBJECT
   public:
      DrawDocument(QWidget * parent = 0);
   inline int xOffset() const {
      return horizontalScrollBar()->value();
   }
   inline int yOffset() const {
      return verticalScrollBar()->value();
   }
   QString pageTextpdf(int index);
   protected:
    bool event(QEvent * e);
   bool gestureNative(QNativeGestureEvent * e);
   void paintEvent(QPaintEvent * ev) Q_DECL_OVERRIDE;
   void paintEditPage(const int index, QPainter * painter);
   void mousePressEvent(QMouseEvent * e);
   void mouseDoubleClickEvent ( QMouseEvent *e );
   void adjustScrollbars();
   void wheelEvent(QWheelEvent * event);
   void resizeEvent(QResizeEvent * e);
   void contextMenuEvent(QContextMenuEvent * event);
   void keyReleaseEvent(QKeyEvent * event);
   void keyPressEvent(QKeyEvent * e);
   void paintgopen(QPainter * painter, int wi = 0, QColor co = _EDITORBGCOLOR_);
   QImage req_ImagePdf(const int  id, QSize *size, const QSize &requestedSize);
   private:
   bool lastkeyMETA;
#ifdef LOADPDFIUMYES
    QPdfium *m_pdf;
#endif
   QRectF page;
   QImage xpage; /// bage bg ground
   qreal mesure; /* fix faktor cm*/
   QTransform mcurrent;
   QSize workArea; /* mobile size from zoom */
   qreal scaleFaktor;
   bool portrait_mode;
   qint64 lineTimer;
   QTextDocument * doc;
   QRectF slider_Horrizzontal_Top;
   QRectF slider_Vertical_Left;
   QTextFrameFormat htmlformat;
   /// QPlainTextDocumentLayout *editLayout;
   QAbstractTextDocumentLayout * docLayout;
   int CursorPosition;
   bool Beeboncontroll;
   qreal strak;
   QTextStream xtrackN;
   qreal distanceswip;
   int PageSumm;
   bool RUNPDF;
    /// public slots:
   signals:
       void newdata();
       void logAction(QString);
   public slots:
       void updateDocument();
       void triggerFormat();
       void fitToLarge();
       void fitToNormal();
       void updateslow();
       void fastupdate();
       void updatedoc(QRectF area);
       void setZoom(const qreal value);
       void LoadFile(); /// internal load file system
       void OpenFile(); /// dialog file
       void ShowFile(const QString file); /// place file

};

#endif // DRAWDOUMENT_H
