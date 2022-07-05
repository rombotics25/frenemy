#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>


const int r_val = 224;
const int g_val = 236;
const int b_val = 255;
const int a_val = 255;

unsigned char r = r_val;
unsigned char g = g_val;
unsigned char b = b_val;
unsigned char a = a_val;

Camera2D camera = { 0 };

Color light_blue = {r_val, g_val, b_val, a_val};




static void UpdateDrawFrame(void);
static void UpdateLogic(void);
static void init();

int main(){
    //init
    //-------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "game");

    Image map1 = LoadImage("assets/textures/map1.png");
    Texture2D map1_texture = LoadTextureFromImage(map1);
    UnloadImage(map1);


    camera.offset = (Vector2){100.0f, -600.0f};
    camera.target = (Vector2){0.0f, 0.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;



    SetTargetFPS(60);




    while(!WindowShouldClose()){
        //UpdateLogic();
        //UpdateDrawFrame();
    



    //Update
    //------------------
    if(IsKeyDown(KEY_A)) camera.target.x -= 7.0f;
    if(IsKeyDown(KEY_D)) camera.target.x += 7.0f;
    if(IsKeyDown(KEY_W)) camera.target.y -= 7.0f;
    if(IsKeyDown(KEY_S)) camera.target.y += 7.0f;
    if(IsKeyDown(KEY_Q)) camera.zoom += 0.05f;
    if(IsKeyDown(KEY_E)) camera.zoom -= 0.05f;
    

    //draw

    
    //-----------------
    BeginDrawing();

        ClearBackground(light_blue);

        BeginMode2D(camera);

            DrawRectangle(400, 200, 20, 20, BLUE);

            DrawTexture(map1_texture, 0, 0, WHITE);


            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) DrawRectangle(GetMouseX(), GetMouseY(), 2, 2, BLACK);

        EndMode2D();
    
    EndDrawing();
    }

    CloseWindow();

    return 0;

}

