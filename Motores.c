#include "Motores.h"

//FUNCIÓN QUE CONTROLA EL SENTIDO DE GIRO DE LOS MOTORES
void MotoresDir(uint8_t DirInd){

    GPIO_PORTQ_DATA_R |= DirInd;

}

//FUNCIÓN QUE ENVIA O DEJA DE ENVIAR EL PASO AL MOTOR CORRESPONDIENTE
void MotoresStep(char MOTOR, uint8_t Step){

    if(MOTOR == 'A'){

        GPIO_PORTQ_DATA_R ^= Step;
    }
    if(MOTOR == 'B'){

    }
    if(MOTOR == 'C'){

    }
    if(MOTOR == 'D'){

    }
}
