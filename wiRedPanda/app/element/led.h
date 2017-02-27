#ifndef LED_H
#define LED_H

#include "graphicelement.h"
#include <QSound>

class Led : public GraphicElement {
public:
  bool m_sound;
  explicit Led( QGraphicsItem *parent = 0 );
  virtual ~Led( );
public:
   int toca=0;
  /* GraphicElement interface */
  virtual ElementType elementType( ) {
    return( ElementType::LED );
  }
  virtual ElementGroup elementGroup( ) {
    return( ElementGroup::OUTPUT );
  }
  void updateLogic( );
  void setColor( QString getColor );
  QString getColor( );

private:
  QString m_color;
private:
  QSound *som;



  /* GraphicElement interface */
public:
  void setSound( bool getSound );
  bool getSound( );
  void playSound( );
  void save( QDataStream &ds);
  void load( QDataStream &ds, QMap< quint64, QNEPort* > &portMap, double version );
  QString genericProperties( );
};

#endif /* LED_H */
