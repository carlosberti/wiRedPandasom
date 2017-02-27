#include "led.h"
#include <QDebug>
#include <QGraphicsSceneDragDropEvent>

Led::Led( QGraphicsItem *parent ) : GraphicElement( 1, 4, 0, 0, parent ) {
    setOutputsOnTop( true );
    setRotatable( false );
    setHasColors( true);
    setHasSound( true );
    setSound( true );
    setColor( "White" );
    setPixmap( ":/output/" +getColor()+ "LedOff.png" );
    updatePorts( );
    setHasLabel( true);
    setPortName( "Led" );
    som= new QSound(":/output/audio/som.wav");
    som->setLoops(1);
}

Led::~Led( ) {

}

void Led::updateLogic( ) {
    if( isValid( ) ) {

        switch (inputSize()){
        case 1: //1 bit
            if( input(0)->value() == 1 ) {
                setPixmap( ":/output/" + getColor( ) + "LedOn.png" );
                playSound();
            }
            else {
                setPixmap( ":/output/" + getColor( ) + "LedOff.png" );
                toca=0;
            }
            break;
        case 2: //2 bits
            switch(input(0)->value()){
            case 1:
                switch(input(1)->value()){
                case 1:
                    setPixmap( ":/output/16cores/RoyalLedOn.png" );
                    break;
                case 0:
                    setPixmap( ":/output/16cores/GreenLedOn.png" );
                    break;
                }
                break;
            case 0:
                switch(input(1)->value()){
                case 1:
                    setPixmap( ":/output/16cores/RedLedOn.png" );
                    break;
                case 0:
                    setPixmap( ":/output/16cores/BlackLedOn.png" );
                    break;
                }
                break;
            }
            break;
        case 3:  //3 bits
            switch(input(0)->value()){
            case 1:
                switch(input(1)->value()){
                case 1:
                    switch(input(2)->value()){
                    case 1:
                        setPixmap( ":/output/16cores/YellowLedOn.png" );
                        break;
                    case 0:
                        setPixmap( ":/output/16cores/MagentaLedOn.png" );
                        break;
                    }
                    break;
                case 0:
                    switch(input(2)->value()){
                    case 1:
                        setPixmap( ":/output/16cores/AquaLightLedOn.png" );
                        break;
                    case 0:
                        setPixmap( ":/output/16cores/RoyalLedOn.png" );
                        break;
                    }
                    break;
                }
                break;
            case 0:
                switch(input(1)->value()){
                case 1:
                    switch(input(2)->value()){
                    case 1:
                        setPixmap( ":/output/16cores/GreenLedOn.png" );
                        break;
                    case 0:
                        setPixmap( ":/output/16cores/RedLedOn.png" );
                        break;
                    }
                    break;
                case 0:
                    switch(input(2)->value()){
                    case 1:
                        setPixmap( ":/output/16cores/BlackLedOn.png" );
                        break;
                    case 0:
                        setPixmap( ":/output/16cores/WhiteLedOn.png" );
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 4: //4 bits
            switch (input(0)->value()){
            case 1:
                switch(input(1)->value()){
                case 1:
                    switch(input(2)->value()){
                    case 1:
                        switch(input(3)->value()){
                        case 1:
                            setPixmap( ":/output/16cores/LightGrayLedOn.png" );
                            break;
                        case 0:
                            setPixmap( ":/output/16cores/DarkGrayLedOn.png" );
                            break;
                        }
                        break;
                    case 0:
                        switch(input(3)->value()){
                        case 1:
                            setPixmap( ":/output/16cores/HotPinkLedOn.png" );
                            break;
                        case 0:
                            setPixmap( ":/output/16cores/RoyalLedOn.png" );
                            break;
                        }
                        break;
                    }
                    break;
                case 0:
                    switch(input(2)->value()){
                    case 1:
                        switch(input(3)->value()){
                        case 1:
                            setPixmap( ":/output/16cores/AquaLightLedOn.png" );
                            break;
                        case 0:
                            setPixmap( ":/output/16cores/TealLedOn.png" );
                            break;
                        }
                        break;
                    case 0:
                        switch(input(3)->value()){
                        case 1:
                            setPixmap( ":/output/16cores/LimeGreenLedOn.png" );
                            break;
                        case 0:
                            setPixmap( ":/output/16cores/YellowLedOn.png" );
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            case 0:
                switch(input(1)->value()){
                case 1:
                    switch(input(2)->value()){
                    case 1:
                        switch(input(3)->value()){
                        case 1:
                            setPixmap( ":/output/16cores/OrangeLedOn.png" );
                            break;
                        case 0:
                            setPixmap( ":/output/16cores/PurpleLedOn.png" );
                            break;
                        }
                        break;
                    case 0:
                        switch(input(3)->value()){
                        case 1:
                            setPixmap( ":/output/16cores/DarkRedLedOn.png" );
                            break;
                        case 0:
                            setPixmap( ":/output/16cores/RedLedOn.png" );
                            break;
                        }
                        break;
                    }
                    break;
                case 0:
                    switch(input(2)->value()){
                    case 1:
                        switch(input(3)->value()){
                        case 1:
                            setPixmap( ":/output/16cores/GreenLedOn.png" );
                            break;
                        case 0:
                            setPixmap( ":/output/16cores/NavyBlueLedOn.png" );
                            break;
                        }
                        break;
                    case 0:
                        switch(input(3)->value()){
                        case 1:
                            setPixmap( ":/output/16cores/BlackLedOn.png" );
                            break;
                        case 0:
                            setPixmap( ":/output/16cores/WhiteLedOn.png" );
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }

    }else {
        setPixmap( ":/output/WhiteLedOff.png" );
    }
}
void Led::setColor( QString color ) {
    m_color = color;
    if(inputSize()==1)
        input( 0 )->setRequired( false );

    updateLogic( );

}

QString Led::getColor( ) {
    return( m_color );
}

void Led::save( QDataStream &ds) {
    GraphicElement::save( ds );
    ds << getSound( );
    ds << getColor( );

}


void Led::load( QDataStream &ds, QMap< quint64, QNEPort* > &portMap, double version ) {
    GraphicElement::load( ds, portMap, version );
    if( version >= 1.1 ) {
        QString clr;
        bool chk;
        ds >> chk;
        setSound( chk );
        ds >> clr;
        setColor( clr );

    }
}

bool Led::getSound( ){
    return( m_sound );
}

void Led::setSound(bool Sound ) {
    m_sound= Sound;
    updateLogic( );
}

void Led::playSound( ){
    if(getSound()){
        if( input(0)->value() == 1 ) {
            if(toca==0) som->play();
            toca=1;
        }
    }
}


QString Led::genericProperties( ) {
    return( getColor( ) );
}
