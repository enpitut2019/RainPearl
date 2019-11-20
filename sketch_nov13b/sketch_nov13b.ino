// vibration_motor_sample1

const int vib_motor_pin = 9;
const int vib_motor_pin2 = 8;

void setup() {
}

void loop()
{
    analogWrite( vib_motor_pin, 250 );
    analogWrite( vib_motor_pin2, 250 );

}
