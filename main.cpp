#include<raylib.h>

int main(){

        InitWindow(800,600,"Pong");
        SetWindowState(FLAG_VSYNC_HINT);
        
        const int midwidhscreen=GetScreenWidth()/2;
        const int midheightscreen=GetScreenHeight()/2;

        int rec1_height = 100;
        int rec1_witdh = 10; 
        int rec2_height = 100;
        int rec2_witdh = 10; 

        float rec1X = 30.0f;
        float rec2X = GetScreenWidth()-30;

        float rec1Y = midheightscreen-50;
        float rec2Y = midheightscreen-50;
        float recSpeed = 150;

        float BallX = midwidhscreen;
        float BallY = midheightscreen;
        float BallSpeedX = 200.0f;
        float BallSpeedY = 200.0f;
        float BallRadius = 10.0f;

        while (!WindowShouldClose())
        {

                BallX += BallSpeedX*GetFrameTime();
                BallY += BallSpeedY*GetFrameTime();

                if (IsKeyDown(KEY_W)) rec1Y -= 10.0f;
                if (IsKeyDown(KEY_S)) rec1Y += 10.0f;

                if (IsKeyDown(KEY_UP)) rec2Y -= 10.0f;
                if (IsKeyDown(KEY_DOWN)) rec2Y += 10.0f;

                if ((rec1Y + rec1_height) >= GetScreenHeight()) rec1Y = GetScreenHeight() - rec1_height;
                else if (rec1Y <= 0) rec1Y = 0;

                if ((rec2Y + rec2_height) >= GetScreenHeight()) rec2Y = GetScreenHeight() - rec2_height;
                else if (rec2Y <= 0) rec2Y = 0;
                
                if(CheckCollisionCircleRec({BallX,BallY} ,BallRadius, Rectangle{rec1X,rec1Y,10,100})){
                        BallSpeedX *= -1.1f;     
                }

                if(CheckCollisionCircleRec({BallX,BallY} ,BallRadius, Rectangle{rec2X,rec2Y,10,100})){
                        BallSpeedX *= -1.1f;
                }

                if(BallY < 0){
                        BallY = 0;
                        BallSpeedY *= -1;
                }

                if(BallY >= GetScreenHeight()){
                        BallY = GetScreenHeight();
                        BallSpeedY *= -1;
                }
                
                if(BallX > GetScreenWidth()){
                        DrawText("Left Player",midwidhscreen-120,midheightscreen-30,40, RED);
                        DrawText("Press Enter To Play Again",midwidhscreen-145,midheightscreen+20,20, BLUE);
                }

                if(BallX < 0){
                        DrawText("Right Player",midwidhscreen-120,midheightscreen-30,40, RED);
                        DrawText("Press Enter To Play Again",midwidhscreen-145,midheightscreen+20,20, BLUE);
                }

                if (IsKeyDown(KEY_ENTER)){
                        ((BallX = midwidhscreen) && (BallY = midwidhscreen));
                        BallSpeedX = 200;
                }
                
                BeginDrawing();
                        ClearBackground(BLACK);
                        DrawCircle(BallX,BallY,BallRadius,WHITE);
                        DrawRectangle(rec1X,rec1Y,rec1_witdh,rec1_height,WHITE);
                        DrawRectangle(rec2X,rec2Y,rec2_witdh,rec2_height,WHITE);
                        DrawFPS(10,10);
                EndDrawing();    

        }
        
        CloseWindow();
        return 0;
}