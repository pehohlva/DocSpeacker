#ifndef DRAWDOUMENT_H
#define DRAWDOUMENT_H

#include "tooldoc.h"



class DrawDoument : public QAbstractScrollArea
{
    Q_OBJECT
//
public:

     DrawDoument( QWidget *parent = 0 );
     inline int xOffset() const { return horizontalScrollBar()->value(); }
     inline int yOffset() const { return verticalScrollBar()->value(); }

protected:
      bool event( QEvent * e);
      bool gestureEvent( QGestureEvent * e );
      bool gestureNative( QNativeGestureEvent * e );
      void paintEvent(QPaintEvent *ev ) Q_DECL_OVERRIDE;
      void paintEditPage( const int index  , QPainter * painter );
      void mousePressEvent ( QMouseEvent *e );
      ///void mouseDoubleClickEvent ( QMouseEvent *e );
      void adjustScrollbars();
      void wheelEvent (QWheelEvent * event);
      void resizeEvent(QResizeEvent *e);
      void contextMenuEvent(QContextMenuEvent *event);
      void keyReleaseEvent(QKeyEvent *event);
      void keyPressEvent ( QKeyEvent * e );
     void paintgopen(QPainter * painter, int wi = 0 , QColor co = _EDITORBGCOLOR_ );

private:
    bool lastkeyMETA;
    QRectF page;
    QImage xpage;  /// bage bg ground
    qreal mesure; /* fix faktor cm*/
    QTransform mcurrent;
    QSize workArea;  /* mobile size from zoom */
    qreal scaleFaktor;
    bool portrait_mode;
    qint64 lineTimer;
    QTextDocument *doc;
    QRectF slider_Horrizzontal_Top;
    QRectF slider_Vertical_Left;
    QTextFrameFormat htmlformat;
    /// QPlainTextDocumentLayout *editLayout;
    QAbstractTextDocumentLayout *docLayout;
    int CursorPosition;
    bool Beeboncontroll;
    qreal strak;
    QTextStream xtrackN;
    qreal distanceswip;


signals:
    void newdata();
    void logAction(QString);
public slots:
    void updateDocument();
    void triggerFormat();
    void fitToLarge();
    void fitToNormal();
    void updateslow();
    void updatedoc(QRectF area);
    void LoadFile();
    void setZoom( const qreal value );
    /// void zoomIn();
    /// void zoomOut();
     void OpenFile();

};



#endif // DRAWDOUMENT_H
