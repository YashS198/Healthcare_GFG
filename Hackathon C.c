#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float weight, height, bmi, dailyCalories;
    int workoutFrequency, choice, unitChoice, riskAssessmentChoice;

    const char *quotes[] = {
        "Believe in yourself and all that you are.",
        "You are braver than you believe, stronger than you seem, and smarter than you think.",
        "Success is not the key to happiness. Happiness is the key to success.",
        "The only way to achieve the impossible is to believe it is possible.",
        "What lies behind us and what lies before us are tiny matters compared to what lies within us."
    };
    int numQuotes = sizeof(quotes) / sizeof(quotes[0]);

    srand((unsigned)time(NULL));

    while (1) {
        printf("\nBMI and Health Assessment Program\n");
        printf("1. Calculate BMI\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Choose your weight unit:\n");
                printf("1. Kilograms (kg)\n");
                printf("2. Pounds (lbs)\n");
                printf("Enter your choice: ");
                scanf("%d", &unitChoice);
                if (unitChoice == 1) {
                    printf("Enter your weight (kg): ");
                    scanf("%f", &weight);
                } else {
                    printf("Enter your weight (lbs): ");
                    scanf("%f", &weight);
                    weight *= 0.453592; // Convert pounds to kilograms
                }

                printf("Choose your height unit:\n");
                printf("1. Meters (m)\n");
                printf("2. Centimeters (cm)\n");
                printf("3. Inches (in)\n");
                printf("Enter your choice: ");
                scanf("%d", &unitChoice);
                if (unitChoice == 1) {
                    printf("Enter your height (m): ");
                    scanf("%f", &height);
                } else if (unitChoice == 2) {
                    printf("Enter your height (cm): ");
                    scanf("%f", &height);
                    height /= 100; // Convert centimeters to meters
                } else {
                    printf("Enter your height (in): ");
                    scanf("%f", &height);
                    height *= 0.0254; // Convert inches to meters
                }

                bmi = weight / (height * height);
                printf("Your BMI is: %.2f\n", bmi);
                printf("How often do you work out per week? (0 for none, 1-7 for days): ");
                scanf("%d", &workoutFrequency);

                if (bmi < 18.5) {
                    printf("You are classified as Underweight.\n");
                    dailyCalories = 3000;
                    printf("Recommendation: Focus on strength training and consume a calorie surplus.\n");
                    printf("Workout Type: Weight lifting, 3-4 times a week, 45-60 minutes.\n");
                } else if (bmi >= 18.5 && bmi < 24.9) {
                    printf("You are classified as Normal weight.\n");
                    dailyCalories = 2500;
                    printf("Recommendation: Maintain your weight with a balanced routine.\n");
                    printf("Workout Type: Combination of cardio and strength training, 4-5 times a week, 30-45 minutes.\n");
                } else if (bmi >= 25 && bmi < 29.9) {
                    printf("You are classified as Overweight.\n");
                    dailyCalories = 2200;
                    printf("Recommendation: Incorporate more cardio and monitor caloric intake.\n");
                    printf("Workout Type: Cardio (running, cycling) and strength training, 5-6 times a week, 45-60 minutes.\n");
                } else {
                    printf("You are classified as Obese.\n");
                    dailyCalories = 2000;
                    printf("Recommendation: Focus on weight loss through diet and regular exercise.\n");
                    printf("Workout Type: Low-impact cardio and strength training, 5-6 times a week, starting with 30-45 minutes.\n");
                }
                printf("Daily Calorie Intake: ~%.0f calories\n", dailyCalories);
                printf("Nutrient Focus: Adjust according to your classification.\n");
                printf("Water Intake: At least 2-3 liters per day.\n");
                printf("%s\n", quotes[rand() % numQuotes]);

                printf("\nBMI Chart Reference:\n");
                printf("Underweight: < 18.5\n");
                printf("Normal weight: 18.5 - 24.9\n");
                printf("Overweight: 25 - 29.9\n");
                printf("Obese: ≥ 30\n");

                // Health Risk Assessment
                printf("Would you like to perform a Health Risk Assessment? (1 for Yes, 0 for No): ");
                scanf("%d", &riskAssessmentChoice);
                if (riskAssessmentChoice == 1) {
                    int riskScore = 0;
                    char answer[4];

                    printf("Do you smoke? (yes/no): ");
                    scanf("%s", answer);
                    if (strcmp(answer, "yes") == 0) riskScore++;

                    printf("Do you have a family history of heart disease? (yes/no): ");
                    scanf("%s", answer);
                    if (strcmp(answer, "yes") == 0) riskScore++;

                    printf("Do you exercise regularly? (yes/no): ");
                    scanf("%s", answer);
                    if (strcmp(answer, "no") == 0) riskScore++;

                    printf("Do you have high blood pressure? (yes/no): ");
                    scanf("%s", answer);
                    if (strcmp(answer, "yes") == 0) riskScore++;

                    printf("Do you have diabetes? (yes/no): ");
                    scanf("%s", answer);
                    if (strcmp(answer, "yes") == 0) riskScore++;

                    printf("Health Risk Assessment Results:\n");
                    if (riskScore == 0) {
                        printf("Low risk. Keep maintaining a healthy lifestyle!\n");
                    } else if (riskScore <= 2) {
                        printf("Moderate risk. Consider making some lifestyle changes.\n");
                    } else {
                        printf("High risk. It's advisable to consult a healthcare professional.\n");
                    }
                }
                break;

            case 2:
                printf("Exiting the program. Stay healthy!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}