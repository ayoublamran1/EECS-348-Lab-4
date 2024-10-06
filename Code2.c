#include <stdio.h>

// Function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);


int main() {
    float temperature, converted_temp;
    int current_scale, target_scale;

    // Input temperature and scale
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &current_scale);

    // Input validation for current scale
    if (current_scale < 1 || current_scale > 3) {
        printf("Invalid scale selection. Please restart and try again.\n");
        return 1;
    }

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target_scale);

    // Input validation for target scale
    if (target_scale < 1 || target_scale > 3) {
        printf("Invalid target scale selection. Please restart and try again.\n");
        return 1;
    }

    // Check for invalid conversion 
    if (current_scale == target_scale) {
        printf("Invalid conversion: Cannot convert to the same scale. Please try again.\n");
        return 1;
    }

    // Perform the conversion based on input
    switch (current_scale) {
        case 1: // Celsius
            if (target_scale == 2)
                converted_temp = celsius_to_fahrenheit(temperature);
            else if (target_scale == 3)
                converted_temp = celsius_to_kelvin(temperature);
            break;
        case 2: // Fahrenheit
            if (target_scale == 1)
                converted_temp = fahrenheit_to_celsius(temperature);
            else if (target_scale == 3)
                converted_temp = fahrenheit_to_kelvin(temperature);
            break;
        case 3: // Kelvin
            if (target_scale == 1)
                converted_temp = kelvin_to_celsius(temperature);
            else if (target_scale == 2)
                converted_temp = kelvin_to_fahrenheit(temperature);
            break;
    }

    // Display the converted temperature
    if (target_scale == 1) {
        printf("Converted temperature: %.2f°C\n", converted_temp);
        categorize_temperature(converted_temp);  // Use Celsius for categorization
    } else if (target_scale == 2) {
        printf("Converted temperature: %.2f°F\n", converted_temp);
        categorize_temperature(fahrenheit_to_celsius(converted_temp));  // Convert to Celsius for categorization
    } else if (target_scale == 3) {
        printf("Converted temperature: %.2fK\n", converted_temp);
        categorize_temperature(kelvin_to_celsius(converted_temp));  // Convert to Celsius for categorization
    }

    return 0;
}

// Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Fahrenheit to Kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

// Kelvin to Fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// Categorize temperature based on Celsius value
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Beware of freezing temperatures. Stay warm.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Avoid exposure to heat.\n");
    }
}