#include <stdio.h>
#include <math.h>

#define GRAVITY 9.8
#define PI 3.14159265

double to_degrees(double radians) {
    return radians * (180.0 / PI);
}

float waktu(float jarak, float kecepatan, float derajat) {
    float elevasi = to_degrees(derajat);
    return jarak / (kecepatan * cos(elevasi * PI / 180.0));
}

float tinggi(float kecepatan, float derajat, float waktu) {
    float elevasi = to_degrees(derajat);
    return (kecepatan * sin(elevasi * PI / 180.0) * waktu) - (GRAVITY * pow(waktu, 2) / 2);
}

int main() {
    float jarak, kecepatan, derajat;
    float waktu_temp, tinggi_temp;

    printf("Selamat datang di kalkulator penghitung waktu bagi objek untuk mencapai target dan tingginya\n");

    printf("Masukkan jaraknya (meter): ");
    if (scanf("%f", &jarak) != 1) {
        printf("Input salah\n");
        return 1;
    }

    printf("Masukkan kecepatannya (meter/detik): ");
    if (scanf("%f", &kecepatan) != 1) {
        printf("Input salah\n");
        return 1;
    }

    printf("Masukkan sudutnya (derajat): ");
    if (scanf("%f", &derajat) != 1) {
        printf("Input salah\n");
        return 1;
    }

    waktu_temp = waktu(jarak, kecepatan, derajat);
    printf("Waktu yang dibutuhkan objek untuk mencapai target adalah %.2f detik\n", waktu_temp);

    tinggi_temp = tinggi(kecepatan, derajat, waktu_temp);
    printf("Tinggi objek saat mencapai target adalah %.2f meter\n", tinggi_temp);

    return 0;
}
