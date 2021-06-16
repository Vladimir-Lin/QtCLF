/****************************************************************************
 *                                                                          *
 * Copyright (C) 2015 Neutrino International Inc.                           *
 *                                                                          *
 * Author : Brian Lin <lin.foxman@gmail.com>, Skype: wolfram_lin            *
 *                                                                          *
 ****************************************************************************/

#ifndef QT_CLF_H
#define QT_CLF_H

#include <QtComponents>

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#    if defined(QT_BUILD_QTCLF_LIB)
#      define Q_CLF_EXPORT Q_DECL_EXPORT
#    else
#      define Q_CLF_EXPORT Q_DECL_IMPORT
#    endif
#else
#    define Q_CLF_EXPORT
#endif

namespace N
{

class Q_CLF_EXPORT ClfShapes     ;
class Q_CLF_EXPORT ClfStructures ;

/*****************************************************************************
 *                                                                           *
 *                      Chinese Language Formula Widgets                     *
 *                                                                           *
 *****************************************************************************/

class Q_CLF_EXPORT ClfShapes
{
  public:

    explicit ClfShapes      (void) ;
    virtual ~ClfShapes      (void) ;

    void     Conformation   (QImage           & Image  ,
                             QList<QPen>      & Pens   ,
                             enum N::CLF::Types Type ) ;
    void     setClfElements (IMAPs & clfElements) ;

  protected:

    void     Type01         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type02         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type03         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type04         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type05         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type06         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type07         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type08         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type09         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type10         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type11         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type12         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type13         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type14         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type15         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type16         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type17         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type18         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type19         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type20         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type21         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type22         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type23         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type24         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type25         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type26         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type27         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type28         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type29         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type30         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type31         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type32         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type33         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type34         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type35         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type36         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type37         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type38         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type39         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type40         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type41         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type42         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type43         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type44         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type45         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type46         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type47         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type48         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type49         (QPainter & painter,QList<QPen> & pens,QSize size) ;
    void     Type50         (QPainter & painter,QList<QPen> & pens,QSize size) ;

  private:

    void     RealLine       (QSize           size      ,
                             QLine         & PixelLine ,
                             QLineF        & Line    ) ;
    void     Lines          (QPainter      & painter ,
                             QSize           size    ,
                             QList<QLineF> & Lines ) ;

};

class Q_CLF_EXPORT ClfStructures : public ListDock
                                 , public ClfShapes
{
  Q_OBJECT
  public:

    explicit ClfStructures    (StandardConstructor) ;
    virtual ~ClfStructures    (void) ;

    virtual QSize sizeHint    (void) const ;

  protected:

    bool dropAction ;

    virtual bool FocusIn      (void) ;
    virtual void Configure    (void) ;

    virtual bool acceptDrop   (QWidget * source,const QMimeData * mime);
    virtual bool dropNew      (QWidget * source,const QMimeData * mime,QPoint pos) ;
    virtual bool dropMoving   (QWidget * source,const QMimeData * mime,QPoint pos) ;
    virtual bool dropAppend   (QWidget * source,const QMimeData * mime,QPoint pos) ;
    virtual bool removeDrop   (void);

    virtual bool dropKeywords (QWidget * source,QPoint pos,const UUIDs & Uuids) ;

    bool         assureCLF    (SqlConnection & Connection ,
                               int             type       ,
                               QString         script   ) ;

  private:

  public slots:

    virtual void Lists        (void) ;
    virtual void Paste        (void) ;

  protected slots:

    virtual bool Menu         (QPoint pos);

  private slots:

  signals:

    void Maps                 (int Type) ;

};

}

QT_END_NAMESPACE

#endif
