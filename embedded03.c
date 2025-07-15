// Include the LiquidCrystal library for LCD
#include <LiquidCrystal.h>

// Initialize the LCD with the pins it's connected to.
// RS, Enable, D4, D5, D6, D7
// Standard Tinkercad LCD wiring often uses these pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// We'll still connect the LM35 to A0 in Tinkercad for visual setup,
// but its reading won't be used for the temperature value in this code.
const int lm35Pin = A0; // This pin is connected but not read for temperature here

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print an initial message to the LCD.
  lcd.print("Random Temp:");

  // Initialize random number generator with a "seed"
  // analogRead(A0) provides a somewhat random seed if A0 is floating
  // or connected to the LM35 which might have slight fluctuations.
  // In simulation, it might be more predictable, but it's good practice.
  randomSeed(analogRead(lm35Pin)); // Using the sensor pin for a "seed"
}

void loop() {
  // Generate a random float temperature within a reasonable range (e.g., 20.0 to 35.0 C)
  // random(min, max) for integers, so we'll scale it for floats.
  // To get floats, we'll generate a larger integer range and divide.
  // Example: random 200 to 350, then divide by 10 for 20.0 to 35.0
  float celsius = random(200, 351) / 10.0;

  // Convert Celsius to Fahrenheit (optional, for display)
  float fahrenheit = (celsius * 9 / 5) + 32;

  // Set the cursor to column 0, line 1 (the second line)
  lcd.setCursor(0, 1);

  // Print the random temperature in Celsius
  lcd.print(celsius);
  lcd.print((char)223); // Degree symbol
  lcd.print("C  "); // Spaces to clear previous values

  // You can also display Fahrenheit if you wish, uncomment the lines below
  /*
  lcd.print(" "); // Add a space for separation if showing both
  lcd.print(fahrenheit);
  lcd.print((char)223); // Degree symbol
  lcd.print("F");
  */

  delay(2000); // Wait for 2 seconds before generating a new random reading
}
