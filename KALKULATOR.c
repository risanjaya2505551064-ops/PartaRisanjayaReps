#include <stdio.h>

void starting() {
    int i;
    int stip = 80;
    for (i = 0; i < stip; i++) {
        printf("*");
    }
    printf("\n======================= WELCOME TO KALKULATOR KELOMPOK 10 ======================\n");
    for (i = 0; i < stip; i++) {
        printf("*");
    }
}

void displayMenu() {
    int e;
    for (e = 0; e < 2; e++) {
        printf("\n");
    }
    printf("\n= SILAHKAN PILIH OPERASI YANG INGIN DIJALANKAN =\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulation\n");
    printf("6. Exit\n");
    printf("Pilih Operasi Yang diinginkan (1-6): ");
}

void getTwoNumbers(float* num1, float* num2) {
    printf("Masukkan Angka pertama  = ");
    while (scanf("%f", num1) != 1) {
        printf("== Invalid input. Please enter a number only ==.\n");
        while (getchar() != '\n');
        printf("Masukkan Angka pertama  = ");
    }
    while (getchar() != '\n'); 

    printf("Masukkan Angka kedua    = ");
    while (scanf("%f", num2) != 1) {
        printf("== Invalid input. Please enter a number only ==.\n");
        while (getchar() != '\n'); 
        printf("Masukkan Angka kedua    = ");
    }
    while (getchar() != '\n'); 
}

void addition() {
    float num1, num2, result;
    getTwoNumbers(&num1, &num2);
    result = num1 + num2;
    printf("Result= %.2f\n", result);
}

void subtraction() {
    float num1, num2, result;
    getTwoNumbers(&num1, &num2);
    result = num1 - num2;
    printf("Result= %.2f\n", result);
}

void multiplication() {
    float num1, num2, result;
    getTwoNumbers(&num1, &num2);
    result = num1 * num2;
    printf("Result= %.2f\n", result);
}

void division() {
    float num1, num2, result;
    getTwoNumbers(&num1, &num2);
    if (num2 != 0) {
        result = num1 / num2;
        printf("Result= %.2f\n", result);
    } else {
        printf("== Error ! Pembagian Ga bisa Pake 0 ==\n");
    }
}

void modulo() {
    int num1, num2, result;

    printf("Masukkan Angka pertama  = ");
    while (scanf("%d", &num1) != 1) {
        printf("== Error ! Tolong Input Integer Only ==.\n");
        while (getchar() != '\n');
        printf("Masukkan Angka pertama  = ");
    }
    while (getchar() != '\n');

    printf("Masukkan Angka kedua  = ");
    while (scanf("%d", &num2) != 1) {
        printf("== Error ! Tolong Input Integer Only ==.\n");
        while (getchar() != '\n');
        printf("Masukkan Angka kedua  = ");
    }
    while (getchar() != '\n');

    if (num2 != 0) {
        result = num1 % num2;
        printf("Result= %d\n", result);
    } else {
        printf("== Error ! Modulo Ga bisa Pake 0 ==\n");
    }
}

int main() {
    int choice;
    int cont; 
    char inputBuffer[100]; 
    starting();
    do {
        displayMenu();

        while (1) {
            if (!fgets(inputBuffer, sizeof(inputBuffer), stdin)) {
                choice = 6; 
                break;
            }

            if (inputBuffer[0] == '\n') {
                printf("\n== Error ! Input tidak boleh kosong. Tolong masukkan angka. ==\n");
                printf("Pilih Operasi Yang diinginkan (1-6): ");
                continue;
            }

            if (sscanf(inputBuffer, "%d", &choice) == 1) {
                break; 
            } else {
                printf("\n\n\n== Error ! Tolong Masukkan angka antara 1 - 6 ==\n");
                printf("Pilih Operasi Yang diinginkan (1-6): ");
            }
        }

        switch (choice) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                modulo();
                break;
            case 6:
                for (int i = 0; i < 80; i++) {
                    printf("*");
                }
                printf("\n        == TERIMAKASIH TELAH MENGGUNAKAN KALKULATOR INI. Adieu! ==\n");
                for (int i = 0; i < 80; i++) {
                    printf("*");
                }
                printf("\n");
                continue; 
            default:
                printf("\n\n\n        == Error ! Tolong masukkan angka antara 1 - 6 ==\n");
                continue; 
        }

        while (1) {
            printf("APAKAH KAMU INGIN MELAKUKAN OPERASI LAGI? (1=Yes / 2=No): ");

            if (!fgets(inputBuffer, sizeof(inputBuffer), stdin)) {
                cont = 2; 
                break;
            }

            if (inputBuffer[0] == '\n') {
                printf("== Error ! Tolong input '1' untuk Yes atau '2' untuk No ==\n");
                continue;
            }
            
            if (sscanf(inputBuffer, "%d", &cont) == 1 && (cont == 1 || cont == 2)) {
                 break; 
            } else {
                 printf("== Error ! Tolong input '1' untuk Yes atau '2' untuk No ==\n");
            }
        }

        if (cont == 2) {
            choice = 6;
            for (int i = 0; i < 80; i++) {
                printf("*");
            }
            printf("\n        == TERIMAKASIH TELAH MENGGUNAKAN KALKULATOR INI. Adieu! ==\n");
            for (int i = 0; i < 80; i++) {
                printf("*");
            }
            printf("\n");
        }

    } while (choice != 6);

    return 0;
}