
// Global Solution - EDGE
//---------------------------------------//
/*
RM99849  - Carlos Eduardo de Queiroz Menezes
RM97648  - Cauã Gonçalves de Jesus
RM551605 - Davi Passanha de Sousa Guerra
RM98047  - Luigi Ferrara Sinno
RM98436  - Rui Amorim Siqueira
*/
// Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

// Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

// difinição de variaveis
const int analogIn = A0;
int RawValue = 0;
double Voltage = 0;
double tempC = 0;
int Temperatura = 0;

void setup()
{
    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop()
{
   

    //---------------- TMP36 -------------//
    RawValue = analogRead(analogIn);
    tempC = (((RawValue / 1023.0) * 5000) - 500) * 0.1; // 500 is the offset
    Serial.print("\t Temperature in C = ");
    Serial.print(tempC, 1);
    Serial.println("");

    // ---------- Término do TMP36 --------//
    Temperatura = tempC;

    //--------------------------------------------------------------------------//
    // -------------------------------- Germinação -----------------------------//
    //--------------------------------------------------------------------------//

    if ((Temperatura >= 20 && Temperatura <= 35)) // Ótimo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Germinacao");
        lcd.setCursor(0, 1);
        lcd.print("Otimo");
        delay(5000);
    }

    if ((Temperatura > 35 || Temperatura <= 10)) // Minimo e Máximo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Germinacao");
        lcd.setCursor(0, 1);
        lcd.print("Ajuste Temp:");
        lcd.print(tempC);
        //-------Releitura dos sensores --------------------------------------------//
        RawValue = analogRead(analogIn);
        tempC = (((RawValue / 1023.0) * 5000) - 500) * 0.1;
        Temperatura = tempC;
        //-------Acompanhamento pelo monitor Serial---------------------------------//
        Serial.print(tempC, 1);
        Serial.println("");
        delay(5000);
    }

    //--------------------------------------------------------------------------//
    // ------------- Emergência e estabelecimento da plântula ------------------//
    //--------------------------------------------------------------------------//

    if ((Temperatura >= 25 && Temperatura <= 30)) // Ótimo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Plantula");
        lcd.setCursor(0, 1);
        lcd.print("Otimo");
        delay(5000);
    }
    if ((Temperatura >= 35 || (Temperatura >= 12 && Temperatura <= 13))) // Minimo e Máximo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Plantula");
        lcd.setCursor(0, 1);
        lcd.print("Ajuste Temp:");
        lcd.print(tempC);
        //-------Releitura dos sensores --------------------------------------------//
        RawValue = analogRead(analogIn);
        tempC = (((RawValue / 1023.0) * 5000) - 500) * 0.1;
        Temperatura = tempC;
        //-------Acompanhamento pelo monitor Serial---------------------------------//
        Serial.print(tempC, 1);
        Serial.println("");
        delay(5000);
    }

    //--------------------------------------------------------------------------//
    // ----------------------- Desenvolvimento da Raiz  ------------------------//
    //--------------------------------------------------------------------------//
    if ((Temperatura >= 25 && Temperatura <= 28)) // Ótimo
    {
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Raiz");
        lcd.setCursor(0, 1);
        lcd.print("Otimo");
        delay(5000);
    }
    if ((Temperatura > 28 || (Temperatura < 25))) // Minimo e Máximo
    {
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Raiz");
        lcd.setCursor(0, 1);
        lcd.print("Ajuste Temp:");
        lcd.print(tempC);
        //-------Releitura dos sensores --------------------------------------------//
        RawValue = analogRead(analogIn);
        tempC = (((RawValue / 1023.0) * 5000) - 500) * 0.1;
        Temperatura = tempC;
        //-------Acompanhamento pelo monitor Serial---------------------------------//
        Serial.print(tempC, 1);
        Serial.println("");
        delay(5000);
    }

    //--------------------------------------------------------------------------//
    // ------------------------ Alongamento da folha  --------------------------//
    //--------------------------------------------------------------------------//
    if ((Temperatura == 31)) // Ótimo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Alongamento");
        lcd.setCursor(0, 1);
        lcd.print("Otimo");
        delay(5000);
    }
    if ((Temperatura != 31)) // Minimo e Máximo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Alongamento");
        lcd.setCursor(0, 1);
        lcd.print("Ajuste Temp:");
        lcd.print(tempC);
        //-------Releitura dos sensores --------------------------------------------//
        RawValue = analogRead(analogIn);
        tempC = (((RawValue / 1023.0) * 5000) - 500) * 0.1;
        Temperatura = tempC;
        //-------Acompanhamento pelo monitor Serial---------------------------------//
        Serial.print(tempC, 1);
        Serial.println("");
        delay(5000);
    }

    //--------------------------------------------------------------------------//
    // ----------------------- Perfihamento ------------------------------------//
    //--------------------------------------------------------------------------//
    if ((Temperatura >= 25 && Temperatura <= 31)) // Ótimo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Perfihamento");
        lcd.setCursor(0, 1);
        lcd.print("Otimo");
        delay(5000);
    }
    if ((Temperatura < 25 || Temperatura > 31)) // Minimo e Máximo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Perfihamento");
        lcd.setCursor(0, 1);
        lcd.print("Ajuste Temp:");
        lcd.print(tempC);
        //-------Releitura dos sensores --------------------------------------------//
        RawValue = analogRead(analogIn);
        tempC = (((RawValue / 1023.0) * 5000) - 500) * 0.1;
        Temperatura = tempC;
        //-------Acompanhamento pelo monitor Serial---------------------------------//
        Serial.print(tempC, 1);
        Serial.println("");

        delay(5000);
    }

    //--------------------------------------------------------------------------//
    // ------------------- Iniciação do primórdio floral -----------------------//
    //--------------------------------------------------------------------------//
    if ((Temperatura >= 25 && Temperatura <= 30)) // Ótimo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("primordio floral");
        lcd.setCursor(0, 1);
        lcd.print("Otimo");
        delay(5000);
    }
    if ((Temperatura < 25 || Temperatura > 30)) // Minimo e Máximo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("primordio floral");
        lcd.setCursor(0, 1);
        lcd.print("Ajuste Temp:");
        lcd.print(tempC);
        //-------Releitura dos sensores --------------------------------------------//
        RawValue = analogRead(analogIn);
        tempC = (((RawValue / 1023.0) * 5000) - 500) * 0.1;
        Temperatura = tempC;
        //-------Acompanhamento pelo monitor Serial---------------------------------//
        Serial.print(tempC, 1);
        Serial.println("");
        delay(5000);
    }

    //--------------------------------------------------------------------------//
    // ---------------------- Emergência da panícula  --------------------------//
    //--------------------------------------------------------------------------//
    if ((Temperatura >= 25 && Temperatura <= 28)) // Ótimo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("panicula");
        lcd.setCursor(0, 1);
        lcd.print("Otimo");
        delay(5000);
    }
    if ((Temperatura < 25 || Temperatura > 28)) // Minimo e Máximo
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("panicula");
        lcd.setCursor(0, 1);
        lcd.print("Ajuste Temp:");
        lcd.print(tempC);
        //-------Releitura dos sensores --------------------------------------------//
        RawValue = analogRead(analogIn);
        tempC = (((RawValue / 1023.0) * 5000) - 500) * 0.1;
        Temperatura = tempC;
        //-------Acompanhamento pelo monitor Serial---------------------------------//
        Serial.print(tempC, 1);
        Serial.println("");
        delay(5000);
    }

    //--------------------------------------------------------------------------//
    // ---------------------------- Antese  ------------------------------------//
    //--------------------------------------------------------------------------//
    if ((Temperatura >= 30 && Temperatura <= 33)) // Ótimo
    {
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Antese");
        lcd.setCursor(0, 1);
        lcd.print("Otimo");
        delay(5000);
    }

    if ((Temperatura < 30 || Temperatura > 33)) // Minimo e Máximo
    {
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Antese");
        lcd.setCursor(0, 1);
        lcd.print("Ajuste Temp:");
        lcd.print(tempC);
        //-------Releitura dos sensores --------------------------------------------//
        RawValue = analogRead(analogIn);
        tempC = (((RawValue / 1023.0) * 5000) - 500) * 0.1;
        Temperatura = tempC;
        //-------Acompanhamento pelo monitor Serial---------------------------------//
        Serial.print(tempC, 1);
        Serial.println("");
        delay(5000);
    }

    //--------------------------------------------------------------------------//
    // ---------------------------- Maturação  ---------------------------------//
    //--------------------------------------------------------------------------//
    if ((Temperatura >= 20 && Temperatura <= 25)) // Ótimo
    {
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("Maturacao");
        lcd.setCursor(0, 1);
        lcd.print("Otimo");
        delay(5000);
    }

    if ((Temperatura < 20 || Temperatura > 25)) // Minimo e Máximo
    {
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("Maturacao");
        lcd.setCursor(0, 1);
        lcd.print("Ajuste Temp:");
        lcd.print(tempC);
        //-------Releitura dos sensores --------------------------------------------//
        RawValue = analogRead(analogIn);
        tempC = (((RawValue / 1023.0) * 5000) - 500) * 0.1;
        Temperatura = tempC;
        //-------Acompanhamento pelo monitor Serial---------------------------------//
        Serial.print(tempC, 1);
        Serial.println("");
        delay(5000);
    }
}
