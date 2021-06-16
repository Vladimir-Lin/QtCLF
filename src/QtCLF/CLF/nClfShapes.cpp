#include <qtclf.h>

N::ClfShapes:: ClfShapes(void)
{
}

N::ClfShapes::~ClfShapes(void)
{
}

void N::ClfShapes::Conformation (
       QImage           & Image ,
       QList<QPen>      & Pens   ,
       enum N::CLF::Types Type  )
{
  QSize    size = Image.size()                                       ;
  QPainter p                                                         ;
  p . begin                              ( &Image          )         ;
  switch (Type)                                                      {
    case CLF::Conformation      : Type01 ( p , Pens , size ) ; break ;
    case CLF::Complex           : Type02 ( p , Pens , size ) ; break ;
    case CLF::H11               : Type03 ( p , Pens , size ) ; break ;
    case CLF::H11E              : Type04 ( p , Pens , size ) ; break ;
    case CLF::H12               : Type05 ( p , Pens , size ) ; break ;
    case CLF::H21               : Type06 ( p , Pens , size ) ; break ;
    case CLF::H3                : Type07 ( p , Pens , size ) ; break ;
    case CLF::H3C               : Type08 ( p , Pens , size ) ; break ;
    case CLF::V11               : Type09 ( p , Pens , size ) ; break ;
    case CLF::V11E              : Type10 ( p , Pens , size ) ; break ;
    case CLF::V12               : Type11 ( p , Pens , size ) ; break ;
    case CLF::V21               : Type12 ( p , Pens , size ) ; break ;
    case CLF::V3                : Type13 ( p , Pens , size ) ; break ;
    case CLF::V3C               : Type14 ( p , Pens , size ) ; break ;
    case CLF::Hat               : Type15 ( p , Pens , size ) ; break ;
    case CLF::Siege             : Type16 ( p , Pens , size ) ; break ;
    case CLF::Triplet           : Type17 ( p , Pens , size ) ; break ;
    case CLF::TriSymmetry       : Type18 ( p , Pens , size ) ; break ;
    case CLF::Quadlet           : Type19 ( p , Pens , size ) ; break ;
    case CLF::QuadSymmetry      : Type20 ( p , Pens , size ) ; break ;
    case CLF::Five              : Type21 ( p , Pens , size ) ; break ;
    case CLF::FiveSymmetry      : Type22 ( p , Pens , size ) ; break ;
    case CLF::Chair             : Type23 ( p , Pens , size ) ; break ;
    case CLF::Sofa              : Type24 ( p , Pens , size ) ; break ;
    case CLF::Body              : Type25 ( p , Pens , size ) ; break ;
    case CLF::Sheet             : Type26 ( p , Pens , size ) ; break ;
    case CLF::Door              : Type27 ( p , Pens , size ) ; break ;
    case CLF::Concave           : Type28 ( p , Pens , size ) ; break ;
    case CLF::Giant             : Type29 ( p , Pens , size ) ; break ;
    case CLF::Teeth             : Type30 ( p , Pens , size ) ; break ;
    case CLF::Mountain          : Type31 ( p , Pens , size ) ; break ;
    case CLF::MountainSymmetry  : Type32 ( p , Pens , size ) ; break ;
    case CLF::Rain              : Type33 ( p , Pens , size ) ; break ;
    case CLF::RainSymmetry      : Type34 ( p , Pens , size ) ; break ;
    case CLF::EUD               : Type35 ( p , Pens , size ) ; break ;
    case CLF::EudSymmetry       : Type36 ( p , Pens , size ) ; break ;
    case CLF::REUD              : Type37 ( p , Pens , size ) ; break ;
    case CLF::ReudSymmetry      : Type38 ( p , Pens , size ) ; break ;
    case CLF::TShape            : Type39 ( p , Pens , size ) ; break ;
    case CLF::TShapeSymmetry    : Type40 ( p , Pens , size ) ; break ;
    case CLF::Thumbtack         : Type41 ( p , Pens , size ) ; break ;
    case CLF::ThumbtackSymmetry : Type42 ( p , Pens , size ) ; break ;
    case CLF::RightT            : Type43 ( p , Pens , size ) ; break ;
    case CLF::RightTSymmetry    : Type44 ( p , Pens , size ) ; break ;
    case CLF::LeftT             : Type45 ( p , Pens , size ) ; break ;
    case CLF::LeftTSymmetry     : Type46 ( p , Pens , size ) ; break ;
    case CLF::Worker            : Type47 ( p , Pens , size ) ; break ;
    case CLF::WorkerSymmetry    : Type48 ( p , Pens , size ) ; break ;
    case CLF::HShape            : Type49 ( p , Pens , size ) ; break ;
    case CLF::HShapeSymmetry    : Type50 ( p , Pens , size ) ; break ;
  }                                                                  ;
  p . end                                (                 )         ;
}

void N::ClfShapes::RealLine (
       QSize    size        ,
       QLine  & PixelLine   ,
       QLineF & Line        )
{
  double  w  = size . width  ( ) - 1 ;
  double  h  = size . height ( ) - 1 ;
  QPointF P1 = Line . p1     ( )     ;
  QPointF P2 = Line . p2     ( )     ;
  double  x1 = P1   . x      ( ) * w ;
  double  x2 = P2   . x      ( ) * w ;
  double  y1 = P1   . y      ( ) * h ;
  double  y2 = P2   . y      ( ) * h ;
  PixelLine  . setLine (x1,y1,x2,y2) ;
}

void N::ClfShapes:: Lines      (
       QPainter      & painter ,
       QSize           size    ,
       QList<QLineF> & Lines   )
{
  QLine L                            ;
  for (int i=0;i<Lines.count();i++)  {
    RealLine ( size , L , Lines[i] ) ;
    painter . drawLine ( L )         ;
  }                                  ;
}

void N::ClfShapes::setClfElements(IMAPs & clfElements)
{
  clfElements [  1 ] = 1 ;
  clfElements [  2 ] = 1 ;
  clfElements [  3 ] = 2 ;
  clfElements [  4 ] = 1 ;
  clfElements [  5 ] = 2 ;
  clfElements [  6 ] = 2 ;
  clfElements [  7 ] = 3 ;
  clfElements [  8 ] = 2 ;
  clfElements [  9 ] = 2 ;
  clfElements [ 10 ] = 1 ;
  clfElements [ 11 ] = 2 ;
  clfElements [ 12 ] = 2 ;
  clfElements [ 13 ] = 3 ;
  clfElements [ 14 ] = 2 ;
  clfElements [ 15 ] = 2 ;
  clfElements [ 16 ] = 2 ;
  clfElements [ 17 ] = 3 ;
  clfElements [ 18 ] = 1 ;
  clfElements [ 19 ] = 4 ;
  clfElements [ 20 ] = 1 ;
  clfElements [ 21 ] = 5 ;
  clfElements [ 22 ] = 2 ;
  clfElements [ 23 ] = 2 ;
  clfElements [ 24 ] = 2 ;
  clfElements [ 25 ] = 2 ;
  clfElements [ 26 ] = 2 ;
  clfElements [ 27 ] = 2 ;
  clfElements [ 28 ] = 2 ;
  clfElements [ 29 ] = 2 ;
  clfElements [ 30 ] = 2 ;
  clfElements [ 31 ] = 3 ;
  clfElements [ 32 ] = 2 ;
  clfElements [ 33 ] = 3 ;
  clfElements [ 34 ] = 2 ;
  clfElements [ 35 ] = 3 ;
  clfElements [ 36 ] = 2 ;
  clfElements [ 37 ] = 3 ;
  clfElements [ 38 ] = 2 ;
  clfElements [ 39 ] = 3 ;
  clfElements [ 40 ] = 2 ;
  clfElements [ 41 ] = 3 ;
  clfElements [ 42 ] = 2 ;
  clfElements [ 43 ] = 3 ;
  clfElements [ 44 ] = 2 ;
  clfElements [ 45 ] = 3 ;
  clfElements [ 46 ] = 2 ;
  clfElements [ 47 ] = 3 ;
  clfElements [ 48 ] = 2 ;
  clfElements [ 49 ] = 3 ;
  clfElements [ 50 ] = 2 ;
}

// Elementary grapheme , only one grapheme
void N::ClfShapes::Type01 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen ( pens[0]              ) ;
  Lines            ( painter , size , L   ) ;
}

// In a simplified version , we do not disassemble complex structure
void N::ClfShapes::Type02 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.05 , 0.95 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Horizontal arrangement 1 : 1
void N::ClfShapes::Type03 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.45 , 0.05 ) ;
  L << QLineF ( 0.45 , 0.05 , 0.45 , 0.95 ) ;
  L << QLineF ( 0.45 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.55 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.55 , 0.95 ) ;
  L << QLineF ( 0.55 , 0.95 , 0.55 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A A       : Horizontal arrangement 1 : 1 , but only A
void N::ClfShapes::Type04 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.45 , 0.05 ) ;
  L << QLineF ( 0.45 , 0.05 , 0.45 , 0.95 ) ;
  L << QLineF ( 0.45 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.55 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.55 , 0.95 ) ;
  L << QLineF ( 0.55 , 0.95 , 0.55 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Horizontal arrangement 1 : 2
void N::ClfShapes::Type05 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.35 , 0.05 ) ;
  L << QLineF ( 0.35 , 0.05 , 0.35 , 0.95 ) ;
  L << QLineF ( 0.35 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.40 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.40 , 0.95 ) ;
  L << QLineF ( 0.40 , 0.95 , 0.40 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Horizontal arrangement 2 : 1
void N::ClfShapes::Type06 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.60 , 0.05 ) ;
  L << QLineF ( 0.60 , 0.05 , 0.60 , 0.95 ) ;
  L << QLineF ( 0.60 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.65 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.65 , 0.95 ) ;
  L << QLineF ( 0.65 , 0.95 , 0.65 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : Horizontal arrangement 1 : 1 : 1
void N::ClfShapes::Type07 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.33 , 0.05 ) ;
  L << QLineF ( 0.33 , 0.05 , 0.33 , 0.95 ) ;
  L << QLineF ( 0.33 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.38 , 0.05 , 0.62 , 0.05 ) ;
  L << QLineF ( 0.62 , 0.05 , 0.62 , 0.95 ) ;
  L << QLineF ( 0.62 , 0.95 , 0.38 , 0.95 ) ;
  L << QLineF ( 0.38 , 0.95 , 0.38 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.67 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.67 , 0.95 ) ;
  L << QLineF ( 0.67 , 0.95 , 0.67 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B A     : Horizontal arrangement 1 : 1 : 1 , but only A,B
void N::ClfShapes::Type08 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.33 , 0.05 ) ;
  L << QLineF ( 0.33 , 0.05 , 0.33 , 0.95 ) ;
  L << QLineF ( 0.33 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.67 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.67 , 0.95 ) ;
  L << QLineF ( 0.67 , 0.95 , 0.67 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.38 , 0.05 , 0.62 , 0.05 ) ;
  L << QLineF ( 0.62 , 0.05 , 0.62 , 0.95 ) ;
  L << QLineF ( 0.62 , 0.95 , 0.38 , 0.95 ) ;
  L << QLineF ( 0.38 , 0.95 , 0.38 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Vertical arrangement 1 : 1
void N::ClfShapes::Type09 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.45 ) ;
  L << QLineF ( 0.95 , 0.45 , 0.05 , 0.45 ) ;
  L << QLineF ( 0.05 , 0.45 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.55 , 0.95 , 0.55 ) ;
  L << QLineF ( 0.95 , 0.55 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.55 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A A       : Vertical arrangement 1 : 1 , but only A
void N::ClfShapes::Type10 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.45 ) ;
  L << QLineF ( 0.95 , 0.45 , 0.05 , 0.45 ) ;
  L << QLineF ( 0.05 , 0.45 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.55 , 0.95 , 0.55 ) ;
  L << QLineF ( 0.95 , 0.55 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.55 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Vertical arrangement 1 : 2
void N::ClfShapes::Type11 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.35 ) ;
  L << QLineF ( 0.95 , 0.35 , 0.05 , 0.35 ) ;
  L << QLineF ( 0.05 , 0.35 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.40 , 0.95 , 0.40 ) ;
  L << QLineF ( 0.95 , 0.40 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.40 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Vertical arrangement 2 : 1
void N::ClfShapes::Type12 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.60 ) ;
  L << QLineF ( 0.95 , 0.60 , 0.05 , 0.60 ) ;
  L << QLineF ( 0.05 , 0.60 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.65 , 0.95 , 0.65 ) ;
  L << QLineF ( 0.95 , 0.65 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.65 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : Vertical arrangement 1 : 1 : 1
void N::ClfShapes::Type13 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.33 ) ;
  L << QLineF ( 0.95 , 0.33 , 0.05 , 0.33 ) ;
  L << QLineF ( 0.05 , 0.33 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.38 , 0.95 , 0.38 ) ;
  L << QLineF ( 0.95 , 0.38 , 0.95 , 0.62 ) ;
  L << QLineF ( 0.95 , 0.62 , 0.05 , 0.62 ) ;
  L << QLineF ( 0.05 , 0.62 , 0.05 , 0.38 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.67 , 0.95 , 0.67 ) ;
  L << QLineF ( 0.95 , 0.67 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.67 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B A     : Vertical arrangement 1 : 1 : 1 , but only A,B
void N::ClfShapes::Type14 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.33 ) ;
  L << QLineF ( 0.95 , 0.33 , 0.05 , 0.33 ) ;
  L << QLineF ( 0.05 , 0.33 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.67 , 0.95 , 0.67 ) ;
  L << QLineF ( 0.95 , 0.67 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.67 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.05 , 0.38 , 0.95 , 0.38 ) ;
  L << QLineF ( 0.95 , 0.38 , 0.95 , 0.62 ) ;
  L << QLineF ( 0.95 , 0.62 , 0.05 , 0.62 ) ;
  L << QLineF ( 0.05 , 0.62 , 0.05 , 0.38 ) ;
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : B Wearing a hat A
void N::ClfShapes::Type15 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.35 ) ;
  L << QLineF ( 0.95 , 0.35 , 0.05 , 0.35 ) ;
  L << QLineF ( 0.05 , 0.35 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.25 , 0.85 , 0.25 ) ;
  L << QLineF ( 0.85 , 0.25 , 0.85 , 0.95 ) ;
  L << QLineF ( 0.85 , 0.95 , 0.15 , 0.95 ) ;
  L << QLineF ( 0.15 , 0.95 , 0.15 , 0.25 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : A siege B
void N::ClfShapes::Type16 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.25 , 0.25 , 0.75 , 0.25 ) ;
  L << QLineF ( 0.75 , 0.25 , 0.75 , 0.75 ) ;
  L << QLineF ( 0.75 , 0.75 , 0.25 , 0.75 ) ;
  L << QLineF ( 0.25 , 0.75 , 0.25 , 0.25 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : Triangle arrangement
void N::ClfShapes::Type17 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.30 , 0.05 , 0.70 , 0.05 ) ;
  L << QLineF ( 0.70 , 0.05 , 0.70 , 0.45 ) ;
  L << QLineF ( 0.70 , 0.45 , 0.30 , 0.45 ) ;
  L << QLineF ( 0.30 , 0.45 , 0.30 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.55 , 0.45 , 0.55 ) ;
  L << QLineF ( 0.45 , 0.55 , 0.45 , 0.95 ) ;
  L << QLineF ( 0.45 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.55 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.55 , 0.55 , 0.95 , 0.55 ) ;
  L << QLineF ( 0.95 , 0.55 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.55 , 0.95 ) ;
  L << QLineF ( 0.55 , 0.95 , 0.55 , 0.55 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A A A     : Triangle arrangement , but only A
void N::ClfShapes::Type18 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.30 , 0.05 , 0.70 , 0.05 ) ;
  L << QLineF ( 0.70 , 0.05 , 0.70 , 0.45 ) ;
  L << QLineF ( 0.70 , 0.45 , 0.30 , 0.45 ) ;
  L << QLineF ( 0.30 , 0.45 , 0.30 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.55 , 0.45 , 0.55 ) ;
  L << QLineF ( 0.45 , 0.55 , 0.45 , 0.95 ) ;
  L << QLineF ( 0.45 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.55 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.55 , 0.55 , 0.95 , 0.55 ) ;
  L << QLineF ( 0.95 , 0.55 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.55 , 0.95 ) ;
  L << QLineF ( 0.55 , 0.95 , 0.55 , 0.55 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C D   : Symmertic quad graphemes
void N::ClfShapes::Type19 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.45 , 0.05 ) ;
  L << QLineF ( 0.45 , 0.05 , 0.45 , 0.45 ) ;
  L << QLineF ( 0.45 , 0.45 , 0.05 , 0.45 ) ;
  L << QLineF ( 0.05 , 0.45 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.55 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.45 ) ;
  L << QLineF ( 0.95 , 0.45 , 0.55 , 0.45 ) ;
  L << QLineF ( 0.55 , 0.45 , 0.55 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.55 , 0.45 , 0.55 ) ;
  L << QLineF ( 0.45 , 0.55 , 0.45 , 0.95 ) ;
  L << QLineF ( 0.45 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.55 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.55 , 0.55 , 0.95 , 0.55 ) ;
  L << QLineF ( 0.95 , 0.55 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.55 , 0.95 ) ;
  L << QLineF ( 0.55 , 0.95 , 0.55 , 0.55 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A A A A   : Symmertic quad graphemes , but only A
void N::ClfShapes::Type20 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.45 , 0.05 ) ;
  L << QLineF ( 0.45 , 0.05 , 0.45 , 0.45 ) ;
  L << QLineF ( 0.45 , 0.45 , 0.05 , 0.45 ) ;
  L << QLineF ( 0.05 , 0.45 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.55 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.45 ) ;
  L << QLineF ( 0.95 , 0.45 , 0.55 , 0.45 ) ;
  L << QLineF ( 0.55 , 0.45 , 0.55 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.55 , 0.45 , 0.55 ) ;
  L << QLineF ( 0.45 , 0.55 , 0.45 , 0.95 ) ;
  L << QLineF ( 0.45 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.55 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.55 , 0.55 , 0.95 , 0.55 ) ;
  L << QLineF ( 0.95 , 0.55 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.55 , 0.95 ) ;
  L << QLineF ( 0.55 , 0.95 , 0.55 , 0.55 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C D E : Quadlet with additional center grapheme
void N::ClfShapes::Type21 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.40 , 0.05 ) ;
  L << QLineF ( 0.40 , 0.05 , 0.40 , 0.40 ) ;
  L << QLineF ( 0.40 , 0.40 , 0.05 , 0.40 ) ;
  L << QLineF ( 0.05 , 0.40 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.40 ) ;
  L << QLineF ( 0.95 , 0.40 , 0.60 , 0.40 ) ;
  L << QLineF ( 0.60 , 0.40 , 0.60 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.30 , 0.30 , 0.70 , 0.30 ) ;
  L << QLineF ( 0.70 , 0.30 , 0.70 , 0.70 ) ;
  L << QLineF ( 0.70 , 0.70 , 0.30 , 0.70 ) ;
  L << QLineF ( 0.30 , 0.70 , 0.30 , 0.30 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.60 , 0.40 , 0.60 ) ;
  L << QLineF ( 0.40 , 0.60 , 0.40 , 0.95 ) ;
  L << QLineF ( 0.40 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.60 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.60 , 0.95 , 0.60 ) ;
  L << QLineF ( 0.95 , 0.60 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.60 , 0.95 ) ;
  L << QLineF ( 0.60 , 0.95 , 0.60 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A A A A B : Quadlet with additional center grapheme , but only A,B
void N::ClfShapes::Type22 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.40 , 0.05 ) ;
  L << QLineF ( 0.40 , 0.05 , 0.40 , 0.40 ) ;
  L << QLineF ( 0.40 , 0.40 , 0.05 , 0.40 ) ;
  L << QLineF ( 0.05 , 0.40 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.40 ) ;
  L << QLineF ( 0.95 , 0.40 , 0.60 , 0.40 ) ;
  L << QLineF ( 0.60 , 0.40 , 0.60 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.60 , 0.40 , 0.60 ) ;
  L << QLineF ( 0.40 , 0.60 , 0.40 , 0.95 ) ;
  L << QLineF ( 0.40 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.60 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.60 , 0.95 , 0.60 ) ;
  L << QLineF ( 0.95 , 0.60 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.60 , 0.95 ) ;
  L << QLineF ( 0.60 , 0.95 , 0.60 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.30 , 0.30 , 0.70 , 0.30 ) ;
  L << QLineF ( 0.70 , 0.30 , 0.70 , 0.70 ) ;
  L << QLineF ( 0.70 , 0.70 , 0.30 , 0.70 ) ;
  L << QLineF ( 0.30 , 0.70 , 0.30 , 0.30 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : L shape , Body B sits on A
void N::ClfShapes::Type23 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.30 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.70 ) ;
  L << QLineF ( 0.95 , 0.70 , 0.30 , 0.70 ) ;
  L << QLineF ( 0.30 , 0.70 , 0.30 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.25 , 0.05 ) ;
  L << QLineF ( 0.25 , 0.05 , 0.25 , 0.75 ) ;
  L << QLineF ( 0.25 , 0.75 , 0.95 , 0.75 ) ;
  L << QLineF ( 0.95 , 0.75 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Reverse L shape , Body B sits on A
void N::ClfShapes::Type24 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.70 , 0.05 ) ;
  L << QLineF ( 0.70 , 0.05 , 0.70 , 0.70 ) ;
  L << QLineF ( 0.70 , 0.70 , 0.05 , 0.70 ) ;
  L << QLineF ( 0.05 , 0.70 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.75 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.75 ) ;
  L << QLineF ( 0.05 , 0.75 , 0.75 , 0.75 ) ;
  L << QLineF ( 0.75 , 0.75 , 0.75 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Body B wearing a coat A
void N::ClfShapes::Type25 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.30 , 0.30 , 0.95 , 0.30 ) ;
  L << QLineF ( 0.95 , 0.30 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.30 , 0.95 ) ;
  L << QLineF ( 0.30 , 0.95 , 0.30 , 0.30 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.25 ) ;
  L << QLineF ( 0.95 , 0.25 , 0.25 , 0.25 ) ;
  L << QLineF ( 0.25 , 0.25 , 0.25 , 0.95 ) ;
  L << QLineF ( 0.25 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Reverse Body shape
void N::ClfShapes::Type26 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.30 , 0.70 , 0.30 ) ;
  L << QLineF ( 0.70 , 0.30 , 0.70 , 0.95 ) ;
  L << QLineF ( 0.70 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.30 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.75 , 0.95 ) ;
  L << QLineF ( 0.75 , 0.95 , 0.75 , 0.25 ) ;
  L << QLineF ( 0.75 , 0.25 , 0.05 , 0.25 ) ;
  L << QLineF ( 0.05 , 0.25 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Notch to down
void N::ClfShapes::Type27 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.80 , 0.95 ) ;
  L << QLineF ( 0.80 , 0.95 , 0.80 , 0.20 ) ;
  L << QLineF ( 0.80 , 0.20 , 0.20 , 0.20 ) ;
  L << QLineF ( 0.20 , 0.20 , 0.20 , 0.95 ) ;
  L << QLineF ( 0.20 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.30 , 0.30 , 0.70 , 0.30 ) ;
  L << QLineF ( 0.70 , 0.30 , 0.70 , 0.95 ) ;
  L << QLineF ( 0.70 , 0.95 , 0.30 , 0.95 ) ;
  L << QLineF ( 0.30 , 0.95 , 0.30 , 0.30 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Notch to up
void N::ClfShapes::Type28 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.20 , 0.05 ) ;
  L << QLineF ( 0.20 , 0.05 , 0.20 , 0.80 ) ;
  L << QLineF ( 0.20 , 0.80 , 0.80 , 0.80 ) ;
  L << QLineF ( 0.80 , 0.80 , 0.80 , 0.05 ) ;
  L << QLineF ( 0.80 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.30 , 0.05 , 0.70 , 0.05 ) ;
  L << QLineF ( 0.70 , 0.05 , 0.70 , 0.70 ) ;
  L << QLineF ( 0.70 , 0.70 , 0.30 , 0.70 ) ;
  L << QLineF ( 0.30 , 0.70 , 0.30 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Notch to right
void N::ClfShapes::Type29 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.20 ) ;
  L << QLineF ( 0.95 , 0.20 , 0.20 , 0.20 ) ;
  L << QLineF ( 0.20 , 0.20 , 0.20 , 0.80 ) ;
  L << QLineF ( 0.20 , 0.80 , 0.95 , 0.80 ) ;
  L << QLineF ( 0.95 , 0.80 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.30 , 0.30 , 0.95 , 0.30 ) ;
  L << QLineF ( 0.95 , 0.30 , 0.95 , 0.70 ) ;
  L << QLineF ( 0.95 , 0.70 , 0.30 , 0.70 ) ;
  L << QLineF ( 0.30 , 0.70 , 0.30 , 0.30 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B       : Notch to left
void N::ClfShapes::Type30 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.80 ) ;
  L << QLineF ( 0.05 , 0.80 , 0.80 , 0.80 ) ;
  L << QLineF ( 0.80 , 0.80 , 0.80 , 0.20 ) ;
  L << QLineF ( 0.80 , 0.20 , 0.05 , 0.20 ) ;
  L << QLineF ( 0.05 , 0.20 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.30 , 0.70 , 0.30 ) ;
  L << QLineF ( 0.70 , 0.30 , 0.70 , 0.70 ) ;
  L << QLineF ( 0.70 , 0.70 , 0.05 , 0.70 ) ;
  L << QLineF ( 0.05 , 0.70 , 0.05 , 0.30 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : B and C hide inside Mountain A
void N::ClfShapes::Type31 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.95 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.05 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.50 , 0.05 , 0.50 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.05 , 0.40 , 0.05 ) ;
  L << QLineF ( 0.40 , 0.05 , 0.40 , 0.85 ) ;
  L << QLineF ( 0.40 , 0.85 , 0.15 , 0.85 ) ;
  L << QLineF ( 0.15 , 0.85 , 0.15 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.05 , 0.85 , 0.05 ) ;
  L << QLineF ( 0.85 , 0.05 , 0.85 , 0.85 ) ;
  L << QLineF ( 0.85 , 0.85 , 0.60 , 0.85 ) ;
  L << QLineF ( 0.60 , 0.85 , 0.60 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B B     : B and B hide inside Mountain A
void N::ClfShapes::Type32 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.95 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.05 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.50 , 0.05 , 0.50 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.15 , 0.05 , 0.40 , 0.05 ) ;
  L << QLineF ( 0.40 , 0.05 , 0.40 , 0.85 ) ;
  L << QLineF ( 0.40 , 0.85 , 0.15 , 0.85 ) ;
  L << QLineF ( 0.15 , 0.85 , 0.15 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.05 , 0.85 , 0.05 ) ;
  L << QLineF ( 0.85 , 0.05 , 0.85 , 0.85 ) ;
  L << QLineF ( 0.85 , 0.85 , 0.60 , 0.85 ) ;
  L << QLineF ( 0.60 , 0.85 , 0.60 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : Reverse Mountain
void N::ClfShapes::Type33 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.05 , 0.05 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.50 , 0.05 , 0.50 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.15 , 0.40 , 0.15 ) ;
  L << QLineF ( 0.40 , 0.15 , 0.40 , 0.95 ) ;
  L << QLineF ( 0.40 , 0.95 , 0.15 , 0.95 ) ;
  L << QLineF ( 0.15 , 0.95 , 0.15 , 0.15 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.15 , 0.85 , 0.15 ) ;
  L << QLineF ( 0.85 , 0.15 , 0.85 , 0.95 ) ;
  L << QLineF ( 0.85 , 0.95 , 0.60 , 0.95 ) ;
  L << QLineF ( 0.60 , 0.95 , 0.60 , 0.15 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B B     : Reverse Mountain , but only A,B
void N::ClfShapes::Type34 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.05 , 0.05 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.50 , 0.05 , 0.50 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.15 , 0.15 , 0.40 , 0.15 ) ;
  L << QLineF ( 0.40 , 0.15 , 0.40 , 0.95 ) ;
  L << QLineF ( 0.40 , 0.95 , 0.15 , 0.95 ) ;
  L << QLineF ( 0.15 , 0.95 , 0.15 , 0.15 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.15 , 0.85 , 0.15 ) ;
  L << QLineF ( 0.85 , 0.15 , 0.85 , 0.95 ) ;
  L << QLineF ( 0.85 , 0.95 , 0.60 , 0.95 ) ;
  L << QLineF ( 0.60 , 0.95 , 0.60 , 0.15 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : E shape
void N::ClfShapes::Type35 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.05 , 0.50 , 0.95 , 0.50 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.15 , 0.95 , 0.15 ) ;
  L << QLineF ( 0.95 , 0.15 , 0.95 , 0.40 ) ;
  L << QLineF ( 0.95 , 0.40 , 0.15 , 0.40 ) ;
  L << QLineF ( 0.15 , 0.40 , 0.15 , 0.15 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.60 , 0.95 , 0.60 ) ;
  L << QLineF ( 0.95 , 0.60 , 0.95 , 0.85 ) ;
  L << QLineF ( 0.95 , 0.85 , 0.15 , 0.85 ) ;
  L << QLineF ( 0.15 , 0.85 , 0.15 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B B     : E shape , but only A,B
void N::ClfShapes::Type36 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.05 , 0.50 , 0.95 , 0.50 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.15 , 0.15 , 0.95 , 0.15 ) ;
  L << QLineF ( 0.95 , 0.15 , 0.95 , 0.40 ) ;
  L << QLineF ( 0.95 , 0.40 , 0.15 , 0.40 ) ;
  L << QLineF ( 0.15 , 0.40 , 0.15 , 0.15 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.60 , 0.95 , 0.60 ) ;
  L << QLineF ( 0.95 , 0.60 , 0.95 , 0.85 ) ;
  L << QLineF ( 0.95 , 0.85 , 0.15 , 0.85 ) ;
  L << QLineF ( 0.15 , 0.85 , 0.15 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : Reverse E shape
void N::ClfShapes::Type37 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.05 , 0.50 , 0.95 , 0.50 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.15 , 0.85 , 0.15 ) ;
  L << QLineF ( 0.85 , 0.15 , 0.85 , 0.40 ) ;
  L << QLineF ( 0.85 , 0.40 , 0.05 , 0.40 ) ;
  L << QLineF ( 0.05 , 0.40 , 0.05 , 0.15 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.60 , 0.85 , 0.60 ) ;
  L << QLineF ( 0.85 , 0.60 , 0.85 , 0.85 ) ;
  L << QLineF ( 0.85 , 0.85 , 0.05 , 0.85 ) ;
  L << QLineF ( 0.05 , 0.85 , 0.05 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B B     : Reverse E shape , but only A,B
void N::ClfShapes::Type38 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.05 , 0.50 , 0.95 , 0.50 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.05 , 0.15 , 0.85 , 0.15 ) ;
  L << QLineF ( 0.85 , 0.15 , 0.85 , 0.40 ) ;
  L << QLineF ( 0.85 , 0.40 , 0.05 , 0.40 ) ;
  L << QLineF ( 0.05 , 0.40 , 0.05 , 0.15 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.60 , 0.85 , 0.60 ) ;
  L << QLineF ( 0.85 , 0.60 , 0.85 , 0.85 ) ;
  L << QLineF ( 0.85 , 0.85 , 0.05 , 0.85 ) ;
  L << QLineF ( 0.05 , 0.85 , 0.05 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : T shape
void N::ClfShapes::Type39 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.50 , 0.05 , 0.50 , 0.95 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.15 , 0.40 , 0.15 ) ;
  L << QLineF ( 0.40 , 0.15 , 0.40 , 0.95 ) ;
  L << QLineF ( 0.40 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.15 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.15 , 0.95 , 0.15 ) ;
  L << QLineF ( 0.95 , 0.15 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.60 , 0.95 ) ;
  L << QLineF ( 0.60 , 0.95 , 0.60 , 0.15 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B B     : T shape , but only A,B
void N::ClfShapes::Type40 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.50 , 0.05 , 0.50 , 0.95 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.05 , 0.15 , 0.40 , 0.15 ) ;
  L << QLineF ( 0.40 , 0.15 , 0.40 , 0.95 ) ;
  L << QLineF ( 0.40 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.15 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.15 , 0.95 , 0.15 ) ;
  L << QLineF ( 0.95 , 0.15 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.60 , 0.95 ) ;
  L << QLineF ( 0.60 , 0.95 , 0.60 , 0.15 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : Reverse T shape
void N::ClfShapes::Type41 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.50 , 0.05 , 0.50 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.40 , 0.05 ) ;
  L << QLineF ( 0.40 , 0.05 , 0.40 , 0.85 ) ;
  L << QLineF ( 0.40 , 0.85 , 0.05 , 0.85 ) ;
  L << QLineF ( 0.05 , 0.85 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.85 ) ;
  L << QLineF ( 0.95 , 0.85 , 0.60 , 0.85 ) ;
  L << QLineF ( 0.60 , 0.85 , 0.60 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B B     : Reverse T shape , but only A,B
void N::ClfShapes::Type42 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.50 , 0.05 , 0.50 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.05 , 0.05 , 0.40 , 0.05 ) ;
  L << QLineF ( 0.40 , 0.05 , 0.40 , 0.85 ) ;
  L << QLineF ( 0.40 , 0.85 , 0.05 , 0.85 ) ;
  L << QLineF ( 0.05 , 0.85 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.85 ) ;
  L << QLineF ( 0.95 , 0.85 , 0.60 , 0.85 ) ;
  L << QLineF ( 0.60 , 0.85 , 0.60 , 0.05 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : Right T
void N::ClfShapes::Type43 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.50 , 0.95 , 0.50 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.40 ) ;
  L << QLineF ( 0.95 , 0.40 , 0.15 , 0.40 ) ;
  L << QLineF ( 0.15 , 0.40 , 0.15 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.60 , 0.95 , 0.60 ) ;
  L << QLineF ( 0.95 , 0.60 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.15 , 0.95 ) ;
  L << QLineF ( 0.15 , 0.95 , 0.15 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B B     : Right T , but only A,B
void N::ClfShapes::Type44 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.50 , 0.95 , 0.50 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.15 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.40 ) ;
  L << QLineF ( 0.95 , 0.40 , 0.15 , 0.40 ) ;
  L << QLineF ( 0.15 , 0.40 , 0.15 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.60 , 0.95 , 0.60 ) ;
  L << QLineF ( 0.95 , 0.60 , 0.95 , 0.95 ) ;
  L << QLineF ( 0.95 , 0.95 , 0.15 , 0.95 ) ;
  L << QLineF ( 0.15 , 0.95 , 0.15 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : Left T
void N::ClfShapes::Type45 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.50 , 0.95 , 0.50 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.85 , 0.05 ) ;
  L << QLineF ( 0.85 , 0.05 , 0.85 , 0.40 ) ;
  L << QLineF ( 0.85 , 0.40 , 0.05 , 0.40 ) ;
  L << QLineF ( 0.05 , 0.40 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.60 , 0.85 , 0.60 ) ;
  L << QLineF ( 0.85 , 0.60 , 0.85 , 0.95 ) ;
  L << QLineF ( 0.85 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B B     : Left T , but only A,B
void N::ClfShapes::Type46 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.50 , 0.95 , 0.50 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.05 , 0.05 , 0.85 , 0.05 ) ;
  L << QLineF ( 0.85 , 0.05 , 0.85 , 0.40 ) ;
  L << QLineF ( 0.85 , 0.40 , 0.05 , 0.40 ) ;
  L << QLineF ( 0.05 , 0.40 , 0.05 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.60 , 0.85 , 0.60 ) ;
  L << QLineF ( 0.85 , 0.60 , 0.85 , 0.95 ) ;
  L << QLineF ( 0.85 , 0.95 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.05 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : Work shape
void N::ClfShapes::Type47 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.50 , 0.05 , 0.50 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.15 , 0.40 , 0.15 ) ;
  L << QLineF ( 0.40 , 0.15 , 0.40 , 0.85 ) ;
  L << QLineF ( 0.40 , 0.85 , 0.05 , 0.85 ) ;
  L << QLineF ( 0.05 , 0.85 , 0.05 , 0.15 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.15 , 0.95 , 0.15 ) ;
  L << QLineF ( 0.95 , 0.15 , 0.95 , 0.85 ) ;
  L << QLineF ( 0.95 , 0.85 , 0.60 , 0.85 ) ;
  L << QLineF ( 0.60 , 0.85 , 0.60 , 0.15 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B B     : Work shape , but only A,B
void N::ClfShapes::Type48 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.95 , 0.05 ) ;
  L << QLineF ( 0.50 , 0.05 , 0.50 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.95 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.05 , 0.15 , 0.40 , 0.15 ) ;
  L << QLineF ( 0.40 , 0.15 , 0.40 , 0.85 ) ;
  L << QLineF ( 0.40 , 0.85 , 0.05 , 0.85 ) ;
  L << QLineF ( 0.05 , 0.85 , 0.05 , 0.15 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.60 , 0.15 , 0.95 , 0.15 ) ;
  L << QLineF ( 0.95 , 0.15 , 0.95 , 0.85 ) ;
  L << QLineF ( 0.95 , 0.85 , 0.60 , 0.85 ) ;
  L << QLineF ( 0.60 , 0.85 , 0.60 , 0.15 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B C     : Rotated Work shape
void N::ClfShapes::Type49 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.50 , 0.95 , 0.50 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.05 , 0.85 , 0.05 ) ;
  L << QLineF ( 0.85 , 0.05 , 0.85 , 0.40 ) ;
  L << QLineF ( 0.85 , 0.40 , 0.15 , 0.40 ) ;
  L << QLineF ( 0.15 , 0.40 , 0.15 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.60 , 0.85 , 0.60 ) ;
  L << QLineF ( 0.85 , 0.60 , 0.85 , 0.95 ) ;
  L << QLineF ( 0.85 , 0.95 , 0.15 , 0.95 ) ;
  L << QLineF ( 0.15 , 0.95 , 0.15 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
}

// A B B     : Rotated Work shape , but only A,B
void N::ClfShapes::Type50 (QPainter & painter,QList<QPen> & pens,QSize size)
{
  QList<QLineF> L                           ;
  ///////////////////////////////////////////
  L << QLineF ( 0.05 , 0.05 , 0.05 , 0.95 ) ;
  L << QLineF ( 0.05 , 0.50 , 0.95 , 0.50 ) ;
  L << QLineF ( 0.95 , 0.05 , 0.95 , 0.95 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[0]             ) ;
  Lines             ( painter , size , L  ) ;
  ///////////////////////////////////////////
  L  . clear  (                           ) ;
  L << QLineF ( 0.15 , 0.05 , 0.85 , 0.05 ) ;
  L << QLineF ( 0.85 , 0.05 , 0.85 , 0.40 ) ;
  L << QLineF ( 0.85 , 0.40 , 0.15 , 0.40 ) ;
  L << QLineF ( 0.15 , 0.40 , 0.15 , 0.05 ) ;
  ///////////////////////////////////////////
  L << QLineF ( 0.15 , 0.60 , 0.85 , 0.60 ) ;
  L << QLineF ( 0.85 , 0.60 , 0.85 , 0.95 ) ;
  L << QLineF ( 0.85 , 0.95 , 0.15 , 0.95 ) ;
  L << QLineF ( 0.15 , 0.95 , 0.15 , 0.60 ) ;
  ///////////////////////////////////////////
  painter . setPen  ( pens[1]             ) ;
  Lines             ( painter , size , L  ) ;
}
