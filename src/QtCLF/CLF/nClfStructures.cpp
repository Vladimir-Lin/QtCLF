#include <qtclf.h>

#define CLFUUID 7865000000000000000LL
#define CLFC    PlanTable(ClfCompositions)

N::ClfStructures:: ClfStructures ( QWidget * parent , Plan * p )
                 : ListDock      (           parent ,        p )
                 , ClfShapes     (                             )
                 , dropAction    ( false                       )
{
  Configure ( ) ;
}

N::ClfStructures::~ClfStructures(void)
{
}

QSize N::ClfStructures::sizeHint(void) const
{
  if ( plan  -> Booleans [ "Desktop" ] ) {
    return QSize (  640 ,  480 )         ;
  } else
  if ( plan  -> Booleans [ "Pad"     ] ) {
    return QSize ( 1024 ,  720 )         ;
  } else
  if ( plan  -> Booleans [ "Phone"   ] ) {
    return QSize (  320 ,  480 )         ;
  }                                      ;
  return   QSize ( 1024 ,  720 )         ;
}

void N::ClfStructures::Configure(void)
{
  setWindowTitle ( tr("Chinese Language Formula Conformations") ) ;
  setViewMode                  (IconMode             ) ;
  setIconSize                  (QSize(64,64)         ) ;
  setGridSize                  (QSize(72,72)         ) ;
  setMovement                  (Snap                 ) ;
  setResizeMode                (Adjust               ) ;
  setSelectionMode             (SingleSelection      ) ;
  setWordWrap                  (true                 ) ;
  setMouseTracking             (true                 ) ;
  setWrapping                  (true                 ) ;
  setTextElideMode             (Qt::ElideNone        ) ;
  setHorizontalScrollBarPolicy (Qt::ScrollBarAsNeeded) ;
  setVerticalScrollBarPolicy   (Qt::ScrollBarAsNeeded) ;
  setMinimumSize               (QSize(128,200)       ) ;
  setDragDropMode              (DropOnly             ) ;
  plan -> setFont              (this                 ) ;
  //////////////////////////////////////////////////////
  setDropFlag                  ( DropFont    , true  ) ;
  setDropFlag                  ( DropPen     , true  ) ;
  setDropFlag                  ( DropBrush   , true  ) ;
  setDropFlag                  ( DropKeyword , true  ) ;
  PassDragDrop = false                                 ;
  //////////////////////////////////////////////////////
  Lists                        (                     ) ;
}

bool N::ClfStructures::acceptDrop(QWidget * source,const QMimeData * mime)
{
  return dropHandler ( mime ) ;
}

bool N::ClfStructures::dropNew(QWidget * source,const QMimeData * mime,QPoint pos)
{
  return true ;
}

bool N::ClfStructures::dropMoving(QWidget * source,const QMimeData * mime,QPoint pos)
{
  nKickOut ( dropAction   , false ) ;
  nKickOut ( source==this , false ) ;
  return true                       ;
}

bool N::ClfStructures::dropAppend(QWidget * source,const QMimeData * mime,QPoint pos)
{
  if (dropAction) return false             ;
  return dropItems ( source , mime , pos ) ;
}

bool N::ClfStructures::removeDrop(void)
{
  return true ;
}

bool N::ClfStructures::FocusIn(void)
{
  AssignAction ( Label   , tr("Chinese Language Formula Conformations") ) ;
  LinkAction   ( Paste   , Paste           ( )                          ) ;
  return true                                                             ;
}

void N::ClfStructures::Lists(void)
{
  QList<QPen> P                               ;
  QImage B(64,64,QImage::Format_ARGB32)       ;
  QImage I(64,64,QImage::Format_ARGB32)       ;
  QPen   Blue  ( QColor (   0 ,   0 , 255 ) ) ;
  QPen   Red   ( QColor ( 255 ,   0 ,   0 ) ) ;
  QIcon  icon                                 ;
  Blue . setStyle ( Qt::DashLine            ) ;
  Blue . setStyle ( Qt::DotLine             ) ;
  Red  . setStyle ( Qt::DashLine            ) ;
  Red  . setStyle ( Qt::DotLine             ) ;
  P << Blue                                   ;
  P << Red                                    ;
  B . fill     ( QColor ( 255 , 255 , 255 ) ) ;
  clear        (                            ) ;
  for (int i=1;i<=50;i++)                     {
    I = B                                     ;
    Conformation(I,P,(enum N::CLF::Types)i)   ;
    icon = QIcon ( QPixmap::fromImage ( I ) ) ;
    addItem (((SUID)i)+CLFUUID,"",icon )      ;
  }                                           ;
}

bool N::ClfStructures::dropKeywords (
       QWidget       * source       ,
       QPoint          pos          ,
       const UUIDs   & Uuids        )
{
  QListWidgetItem * item = itemAt(pos) ;
  if (IsNull(item))                    {
    Alert ( Error )                    ;
    return false                       ;
  }                                    ;
  int  type = 0                        ;
  SUID xuid = nListUuid(item)          ;
  type = (int)(xuid - CLFUUID)         ;
  if (type<1)                          {
    Alert ( Error )                    ;
    return false                       ;
  }                                    ;
  dropAction = true                    ;
  EnterSQL ( SC , plan->sql )          ;
    QStringList N                      ;
    QString     Q                      ;
    SUID        uuid                   ;
    SUID        nuid                   ;
    foreach (uuid,Uuids)               {
      Q = SC.sql.SelectFrom            (
            "name"                     ,
            PlanTable(KeywordNames)    ,
            SC.WhereUuid(uuid)       ) ;
      if (SC.Fetch(Q))                 {
        nuid = SC . Uuid ( 0 )         ;
      } else nuid = 0                  ;
      Q = SC.sql.SelectFrom            (
            "name"                     ,
            PlanTable(Names)           ,
            SC.WhereUuid(nuid)       ) ;
      if ( ( nuid>0 ) && SC.Fetch(Q) ) {
        QString name = SC . String (0) ;
        if (!N.contains(name))         {
          N << name                    ;
        }                              ;
      }                                ;
    }                                  ;
    for (int i=0;i<N.count();i++)      {
      assureCLF ( SC , type , N[i] )   ;
    }                                  ;
  LeaveSQL ( SC , plan->sql )          ;
  Alert    ( Done           )          ;
  dropAction = false                   ;
  return true                          ;
}

bool N::ClfStructures::assureCLF (
       SqlConnection & SC        ,
       int             type      ,
       QString         script    )
{
  QString Q                             ;
  int     id   = 1                      ;
  int     code = 0                      ;
  ///////////////////////////////////////
  Q = SC.sql.SelectFrom                 (
        "id"                            ,
        CLFC                            ,
        SC.sql.Where(1,"utf")  )        ;
  SC.Prepare(Q)                         ;
  SC.Bind("utf",script.toUtf8())        ;
  IfSqlExec ( SC )                      {
    id = SC . Int ( 0 )                 ;
    Q = SC.sql.Update                   (
          CLFC                          ,
          SC.sql.Where(1,"id")          ,
          1                             ,
          "type"              )         ;
    SC . Prepare ( Q          )         ;
    SC . Bind    ( "id"  ,id  )         ;
    SC . Bind    ( "type",type)         ;
    return SC.Exec (          )         ;
  }                                     ;
  ///////////////////////////////////////
  Q = SC.sql.SelectFrom                 (
        "code"                          ,
        CLFC                            ,
        QString ( "%1 %2"               )
        .arg( SC.OrderByDesc("code")    )
        .arg( SC.sql.Limit(0,1)     ) ) ;
  if (SC.Fetch(Q))                      {
    code = SC.Int(0)                    ;
  }                                     ;
  code++                                ;
  ///////////////////////////////////////
  Q = SC.sql.InsertInto                 (
        CLFC                            ,
        3                               ,
        "code"                          ,
        "type"                          ,
        "utf"                         ) ;
  SC . Prepare  (Q                    ) ;
  SC . Bind     ("code",code          ) ;
  SC . Bind     ("type",type          ) ;
  SC . Bind     ("utf",script.toUtf8()) ;
  return SC.Exec()                      ;
}

void N::ClfStructures::Paste(void)
{
  QListWidgetItem * it = currentItem() ;
  int               Type = 0           ;
  if (NotNull(it))                     {
    SUID uuid = nListUuid(it)          ;
    Type = (int)( uuid - CLFUUID )     ;
  }                                    ;
  if (Type<=0) return                  ;
  QString S = nClipboardText           ;
  if (S.length()<=0) return            ;
  QStringList L = S . split ( '\n' )   ;
  if (L.count()<=0) return             ;
  QStringList N                        ;
  QString     Q                        ;
  foreach (Q,L)                        {
    Q = Q . replace ( "\r" , "" )      ;
    Q = Q . replace ( "\n" , "" )      ;
    if (Q.length()>0)                  {
      if (!N.contains(Q)) N << Q       ;
    }                                  ;
  }                                    ;
  if (N.count()<=0) return             ;
  dropAction = true                    ;
  EnterSQL ( SC , plan->sql )          ;
    for (int i=0;i<N.count();i++)      {
      assureCLF ( SC , Type , N[i] )   ;
    }                                  ;
  LeaveSQL ( SC , plan->sql )          ;
  Alert    ( Done           )          ;
  dropAction = false                   ;
}

bool N::ClfStructures::Menu (QPoint pos)
{
  MenuManager       mm ( this )      ;
  QAction         * aa               ;
  QListWidgetItem * it = itemAt(pos) ;
  int               Type = 0         ;
  if (NotNull(it))                   {
    SUID uuid = nListUuid(it)        ;
    Type = (int)( uuid - CLFUUID )   ;
  }                                  ;
  ////////////////////////////////////
  mm.add(501,tr("Edit characters"))  ;
  if (NotNull(it))                   {
    mm.add(601,tr("Paste")         ) ;
  }                                  ;
  ////////////////////////////////////
  DockingMenu ( mm )                 ;
  mm.setFont(plan)                   ;
  aa = mm.exec()                     ;
  if (IsNull(aa)) return true        ;
  ////////////////////////////////////
  switch (mm[aa])                    {
    case 501                         :
      emit Maps ( Type )             ;
    break                            ;
    case 601                         :
      Paste     (      )             ;
    break                            ;
    default                          :
      if (RunDocking(mm,aa))         {
        return true                  ;
      }                              ;
    break                            ;
  }                                  ;
  return true                        ;
}
