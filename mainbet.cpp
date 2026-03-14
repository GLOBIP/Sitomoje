#include <iostream>
#include "raylib.h"
using namespace std;




void  sitoerast(bool* ciag, int width, int height, int number, int dl_ciagu) {


    int first_width = width;




    int pluswidth = 0;

    int licznik_liczb = 0;

    for (int i = 0 ; i <= number ; i++) {
        if (i >= 1000) {
            pluswidth = 50;
            width += pluswidth;
        }
        if (ciag[i] == true) {
            DrawRectangle(width/2,height+100,50 + pluswidth,50,GREEN);
            DrawText(TextFormat("%d" , i),width/2 ,height+100 + 15,24,BLACK   );
        }
        else {
            DrawRectangle(width/2,height+100,50 + pluswidth,50,RED);
            DrawText(TextFormat("%d" , i),width/2 ,height+100 + 15,24,BLACK   );

        }
        licznik_liczb++;

        DrawLine(width/2,height + 100,width/2,height + 100 + 100,WHITE);
        width += 100;

        if (licznik_liczb%10 == 0) {

            DrawLine(first_width/2 + pluswidth/2,height + 100,width/2 + pluswidth,height + 100,WHITE);
            DrawLine(first_width/2 + pluswidth/2,height+ 150,width/2 + pluswidth,height + 150,WHITE);
            DrawLine(width/2 + pluswidth ,height + 100,width/2 + pluswidth ,height + 100 +100,WHITE);
            height += 50;
            width = first_width;

        }
        else if(i >= number - 1) {
            DrawLine(first_width/2 + pluswidth/2 ,height+ 100,width/2 + pluswidth,height + 100,WHITE);
            DrawLine(first_width/2 + pluswidth/2,height+ 150,width/2 + pluswidth,height + 150,WHITE);
            DrawLine(width/2,height + 100,width/2,height + 100 +100,WHITE);
        }




    }


}


int main() {

    InitWindow(1920, 1080, "sito");  // ← ta linijka do góry
    int width = GetScreenWidth();
    int height = GetScreenHeight();
    int scrollSpeed = 1000;
    int offsetY = 0;
    cout << height;
    SetTargetFPS(100);

    int liczba = 67676;



    while (!WindowShouldClose()) {

        bool* ciag = new bool[liczba + 1];
        for (int i = 0; i <= liczba; i++) ciag[i] = true;
        ciag[0] = ciag[1] = false;
        for (int i = 2; i*i <= liczba; i++) {
            if (ciag[i]) {
                for (int j = i+i; j <= liczba; j+=i) {
                    ciag[j] = false;
                }
            }
        }

        offsetY += (int)(GetMouseWheelMove()*scrollSpeed);
        BeginDrawing();
        ClearBackground(BLACK);
        sitoerast(ciag,width,offsetY,liczba,liczba+1);


        delete[] ciag;
        EndDrawing();


    }

    CloseWindow();



    return 0;
}