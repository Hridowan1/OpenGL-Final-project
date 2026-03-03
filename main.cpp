#include <windows.h>
#include <GL/glut.h>
#include <cmath>


float position = -1.2f,position2=-1.2,position3=-1.6;
float speed = 0.01f,speed2=0.001,speed3=0.015;


void update(int value){
        position+=speed;

    if(position > 1.2f)
        position = -1.2f;


    position2+=speed2;
    if(position2>1.2f)
        position2 = -1.2f;

    position3+=speed3;
    if(position3>1.6)
        position3=-1.1;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}







void drawCircle(float cx, float cy, float r, int segments = 50) {
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= segments; i++) {
        float angle = 2.0f * 3.1416f * i / segments;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
//-----------------------
void flowerTree(float x,float y)
{
        // ---- Tiny Flower Tree ----
    glPushMatrix();
    glTranslatef(x, y, 0);   // position for each tree
    glScalef(0.5f, 0.5f, 1); // size of tree

    // trunk
    glColor3f(0.4f, 0.2f, 0.05f);
    glBegin(GL_QUADS);
    glVertex2f(-0.02f, -0.10f);
    glVertex2f( 0.02f, -0.10f);
    glVertex2f( 0.02f,  0.00f);
    glVertex2f(-0.02f,  0.00f);
    glEnd();

    // flower 1
    glColor3f(1.0f, 0.4f, 0.6f);
    drawCircle(0.00f, 0.05f, 0.03f, 20);

    // flower 2
    glColor3f(1.0f, 0.8f, 0.3f);
    drawCircle(-0.04f, 0.02f, 0.02f, 20);

    // flower 3
    glColor3f(0.7f, 0.8f, 1.0f);
    drawCircle(0.04f, 0.02f, 0.02f, 20);

    glPopMatrix();


}
//mini flower tree------------------------------------
void drawFlower(float x , float y)
{
    glPushMatrix();
glTranslatef(x, y, 0);
glScalef(0.4f, 0.4f, 1);

// trunk
glColor3f(0.45f, 0.25f, 0.1f);
glBegin(GL_QUADS);
    glVertex2f(-0.015f, -0.10f);
    glVertex2f( 0.015f, -0.10f);
    glVertex2f( 0.015f, -0.02f);
    glVertex2f(-0.015f, -0.02f);
glEnd();

// petals
glColor3f(1.0f, 0.6f, 0.8f);
drawCircle(0.00f, 0.04f, 0.025f, 20);
drawCircle(0.03f, 0.02f, 0.025f, 20);
drawCircle(-0.03f, 0.02f, 0.025f, 20);
drawCircle(0.02f, 0.00f, 0.025f, 20);
drawCircle(-0.02f, 0.00f, 0.025f, 20);

// center
glColor3f(1.0f, 0.85f, 0.3f);
drawCircle(0.00f, 0.02f, 0.015f, 20);

glPopMatrix();

}

void drawSun(float x, float y, float radius) {
    glColor3f(1.0f, 0.9f, 0.0f); // yellow color
    drawCircle(x, y, radius);
}

//---------------------
void drawCloud(float x, float y, float scale) {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 0.08f * scale);
    drawCircle(x + 0.08f * scale, y + 0.03f * scale, 0.07f * scale);
    drawCircle(x - 0.08f * scale, y + 0.03f * scale, 0.07f * scale);
    drawCircle(x, y + 0.05f * scale, 0.06f * scale);
}
//------------------
void drawBird(float x, float y, float scale) {
    glColor3f(0.0f, 0.0f, 0.0f); // black bird
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x - 0.05f * scale, y + 0.03f * scale);

        glVertex2f(x, y);
        glVertex2f(x + 0.05f * scale, y + 0.03f * scale);
    glEnd();
}

void drawbuilding(float x )
{

// ===== Faraway City Skyline =====
float farBuildX = x;  // starting x position
float farBuildW = 0.08f;  // width of each building
float colors[5][3] = {
    {0.6f, 0.6f, 0.6f},
    {0.65f, 0.65f, 0.65f},
    {0.7f, 0.7f, 0.7f},
    {0.62f, 0.62f, 0.62f},
    {0.68f, 0.68f, 0.68f}
};
float heights[5] = {0.25f, 0.35f, 0.3f, 0.4f, 0.29f};

for(int i=0; i<5; i++){
    // Building
    glBegin(GL_QUADS);
    glColor3f(colors[i][0], colors[i][1], colors[i][2]);
    glVertex2f(farBuildX, -0.1f);
    glVertex2f(farBuildX + farBuildW, -0.1f);
    glVertex2f(farBuildX + farBuildW, -0.1f + heights[i]);
    glVertex2f(farBuildX, -0.1f + heights[i]);
    glEnd();

    // Windows (small, subtle)
    glColor3f(0.8f, 0.8f, 0.8f);
    float winX = farBuildX + 0.01f;
    float winY = -0.08f;
    float winW = 0.015f;
    float winH = 0.02f;
    for(int row=0; row<heights[i]/0.05f; row++){
        for(int col=0; col<2; col++){
            glBegin(GL_QUADS);
            glVertex2f(winX + col*0.03f, winY + row*0.05f);
            glVertex2f(winX + col*0.03f + winW, winY + row*0.05f);
            glVertex2f(winX + col*0.03f + winW, winY + row*0.05f + winH);
            glVertex2f(winX + col*0.03f, winY + row*0.05f + winH);
            glEnd();
        }
    }

    farBuildX += 0.12f;  // space to next building
}

}
void display()
{
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f); // skyblue
    glClear(GL_COLOR_BUFFER_BIT);

    // --- SCENE BACKGROUND ---
    // Green Ground
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f( 1.0f, -1.0f);
    glVertex2f( 1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();

    // Sky Blue (Top Half)
    glBegin(GL_QUADS);
    glColor3f(0.529f,0.808f,0.922f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f( 1.0f, -0.5f);
    glVertex2f( 1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();


    // Gray Border
    glBegin(GL_QUADS);
    glColor3f(0.5f,0.5f,0.5f);
    glVertex2f(-1.0f,-0.4f);
    glVertex2f(1.0f,-0.4f);
    glVertex2f(1.0f,-0.55f);
    glVertex2f(-1.0f,-0.55f);
    glEnd();


    drawbuilding(0.4);
    drawbuilding(-1.0);


    //building background--------------------
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.39f, 0.0f);  // dark green
     glVertex2f(-1.0f,-0.4f);
     glVertex2f(1.0f,-0.4f);
     glVertex2f(1.0f,-0.1f);
     glVertex2f(-1.0f,-0.1f);
    glEnd();



    //----------Building white outline--------
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-0.7f,-0.4f);
    glVertex2f(0.1f,-0.4f);
    glVertex2f(0.1f,0.4f);
    glVertex2f(-0.7f,0.4f);
    glEnd();

    //--------- 5th floor --------
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.5f);
    glVertex2f(-0.72f,0.4f);
    glVertex2f(0.12f,0.4f);
    glVertex2f(0.12f,0.52f);
    glVertex2f(-0.72f,0.52f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
// Set starting raster position inside the quad
    glRasterPos2f(-0.5f, 0.445f);

// Print text
    char text[] = "STAMFORD UNIVERSITY BANGLADESH";
    for(int i = 0; text[i] != '\0'; i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }

    //----------Building dark red--------
    glBegin(GL_QUADS);
    glColor3f(0.545f,0.0f,0.0f);
    glVertex2f(-0.69f,-0.39f);
    glVertex2f(0.09f,-0.39f);
    glVertex2f(0.09f,0.39f);
    glVertex2f(-0.69f,0.39f);
    glEnd();

    // ----------- 18 WHITE WINDOWS-----------------
    glColor3f(1.0f, 1.0f, 1.0f);

    // --- Row 1 ---
    glBegin(GL_QUADS);
    glVertex2f(-0.67f, -0.30f);
    glVertex2f(-0.59f, -0.30f);
    glVertex2f(-0.59f, -0.22f);
    glVertex2f(-0.67f, -0.22f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.55f, -0.30f);
    glVertex2f(-0.47f, -0.30f);
    glVertex2f(-0.47f, -0.22f);
    glVertex2f(-0.55f, -0.22f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.43f, -0.30f);
    glVertex2f(-0.35f, -0.30f);
    glVertex2f(-0.35f, -0.22f);
    glVertex2f(-0.43f, -0.22f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.31f, -0.30f);
    glVertex2f(-0.23f, -0.30f);
    glVertex2f(-0.23f, -0.22f);
    glVertex2f(-0.31f, -0.22f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.19f, -0.30f);
    glVertex2f(-0.11f, -0.30f);
    glVertex2f(-0.11f, -0.22f);
    glVertex2f(-0.19f, -0.22f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.07f, -0.30f);
    glVertex2f( 0.01f, -0.30f);
    glVertex2f( 0.01f, -0.22f);
    glVertex2f(-0.07f, -0.22f);
    glEnd();

    // --- Row 2 ---
    glBegin(GL_QUADS);
    glVertex2f(-0.67f, -0.04f);
    glVertex2f(-0.59f, -0.04f);
    glVertex2f(-0.59f,  0.04f);
    glVertex2f(-0.67f,  0.04f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.55f, -0.04f);
    glVertex2f(-0.47f, -0.04f);
    glVertex2f(-0.47f,  0.04f);
    glVertex2f(-0.55f,  0.04f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.43f, -0.04f);
    glVertex2f(-0.35f, -0.04f);
    glVertex2f(-0.35f,  0.04f);
    glVertex2f(-0.43f,  0.04f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.31f, -0.04f);
    glVertex2f(-0.23f, -0.04f);
    glVertex2f(-0.23f,  0.04f);
    glVertex2f(-0.31f,  0.04f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.19f, -0.04f);
    glVertex2f(-0.11f, -0.04f);
    glVertex2f(-0.11f,  0.04f);
    glVertex2f(-0.19f,  0.04f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.07f, -0.04f);
    glVertex2f( 0.01f, -0.04f);
    glVertex2f( 0.01f,  0.04f);
    glVertex2f(-0.07f,  0.04f);
    glEnd();

    // --- Row 3 ---
    glBegin(GL_QUADS); glVertex2f(-0.67f, 0.22f);
    glVertex2f(-0.59f, 0.22f);
    glVertex2f(-0.59f, 0.30f);
    glVertex2f(-0.67f, 0.30f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.55f, 0.22f);
    glVertex2f(-0.47f, 0.22f);
    glVertex2f(-0.47f, 0.30f);
    glVertex2f(-0.55f, 0.30f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.43f, 0.22f);
    glVertex2f(-0.35f, 0.22f);
    glVertex2f(-0.35f, 0.30f);
    glVertex2f(-0.43f, 0.30f);
    glEnd();
    glBegin(GL_QUADS);
     glVertex2f(-0.31f, 0.22f);
     glVertex2f(-0.23f, 0.22f);
     glVertex2f(-0.23f, 0.30f);
     glVertex2f(-0.31f, 0.30f);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.19f, 0.22f);
    glVertex2f(-0.11f, 0.22f);
    glVertex2f(-0.11f, 0.30f);
    glVertex2f(-0.19f, 0.30f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.07f, 0.22f);
    glVertex2f( 0.01f, 0.22f);
    glVertex2f( 0.01f, 0.30f);
    glVertex2f(-0.07f, 0.30f);
    glEnd();

    // =============== 18 RED INNER BOXES =================
    glColor3f(0.545f, 0.0f, 0.0f);

    // --- Row 1 ---
    glBegin(GL_QUADS);
    glVertex2f(-0.65f, -0.28f);
    glVertex2f(-0.61f, -0.28f);
    glVertex2f(-0.61f, -0.24f);
    glVertex2f(-0.65f, -0.24f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.53f, -0.28f);
    glVertex2f(-0.49f, -0.28f);
    glVertex2f(-0.49f, -0.24f);
    glVertex2f(-0.53f, -0.24f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.41f, -0.28f);
    glVertex2f(-0.37f, -0.28f);
    glVertex2f(-0.37f, -0.24f);
    glVertex2f(-0.41f, -0.24f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.29f, -0.28f);
    glVertex2f(-0.25f, -0.28f);
    glVertex2f(-0.25f, -0.24f);
    glVertex2f(-0.29f, -0.24f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.17f, -0.28f);
    glVertex2f(-0.13f, -0.28f);
    glVertex2f(-0.13f, -0.24f);
    glVertex2f(-0.17f, -0.24f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, -0.28f);
    glVertex2f(-0.01f, -0.28f);
    glVertex2f(-0.01f, -0.24f);
    glVertex2f(-0.05f, -0.24f);
    glEnd();

    // --- Row 2 ---
    glBegin(GL_QUADS);
    glVertex2f(-0.65f, -0.02f);
    glVertex2f(-0.61f, -0.02f);
    glVertex2f(-0.61f,  0.02f);
    glVertex2f(-0.65f,  0.02f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.53f, -0.02f);
    glVertex2f(-0.49f, -0.02f);
    glVertex2f(-0.49f,  0.02f);
    glVertex2f(-0.53f,  0.02f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.41f, -0.02f);
    glVertex2f(-0.37f, -0.02f);
    glVertex2f(-0.37f,  0.02f);
    glVertex2f(-0.41f,  0.02f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.29f, -0.02f);
    glVertex2f(-0.25f, -0.02f);
    glVertex2f(-0.25f,  0.02f);
    glVertex2f(-0.29f,  0.02f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.17f, -0.02f);
    glVertex2f(-0.13f, -0.02f);
    glVertex2f(-0.13f,  0.02f);
    glVertex2f(-0.17f,  0.02f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, -0.02f);
    glVertex2f(-0.01f, -0.02f);
    glVertex2f(-0.01f,  0.02f);
    glVertex2f(-0.05f,  0.02f);
    glEnd();

    // --- Row 3 ---
    glBegin(GL_QUADS);
    glVertex2f(-0.65f, 0.24f);
    glVertex2f(-0.61f, 0.24f);
    glVertex2f(-0.61f, 0.28f);
    glVertex2f(-0.65f, 0.28f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.53f, 0.24f);
    glVertex2f(-0.49f, 0.24f);
    glVertex2f(-0.49f, 0.28f);
    glVertex2f(-0.53f, 0.28f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.41f, 0.24f);
    glVertex2f(-0.37f, 0.24f);
    glVertex2f(-0.37f, 0.28f);
    glVertex2f(-0.41f, 0.28f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.29f, 0.24f);
    glVertex2f(-0.25f, 0.24f);
    glVertex2f(-0.25f, 0.28f);
    glVertex2f(-0.29f, 0.28f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.17f, 0.24f);
    glVertex2f(-0.13f, 0.24f);
    glVertex2f(-0.13f, 0.28f);
    glVertex2f(-0.17f, 0.28f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.24f);
    glVertex2f(-0.01f, 0.24f);
    glVertex2f(-0.01f, 0.28f);
    glVertex2f(-0.05f, 0.28f);
    glEnd();

    // ================= STRIPES =================
    glColor3f(1.0f,1.0f,1.0f);

    // Vertical Stripes
    glBegin(GL_QUADS);
    glVertex2f(-0.58f,-0.39f);
    glVertex2f(-0.56f,-0.39f);
    glVertex2f(-0.56f,0.39f);
    glVertex2f(-0.58f,0.39f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.46f,-0.39f);
    glVertex2f(-0.44f,-0.39f);
    glVertex2f(-0.44f,0.39f);
    glVertex2f(-0.46f,0.39f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.34f,-0.39f);
    glVertex2f(-0.32f,-0.39f);
    glVertex2f(-0.32f,0.39f);
    glVertex2f(-0.34f,0.39f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.22f,-0.39f);
    glVertex2f(-0.20f,-0.39f);
    glVertex2f(-0.20f,0.39f);
    glVertex2f(-0.22f,0.39f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.1f,-0.39f);
    glVertex2f(-0.08f,-0.39f);
    glVertex2f(-0.08f,0.39f);
    glVertex2f(-0.1f,0.39f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.03f,-0.39f);
    glVertex2f(0.05f,-0.39f);
    glVertex2f(0.05f,0.39f);
    glVertex2f(0.03f,0.39f);
    glEnd();

    // Horizontal Stripes
    glBegin(GL_QUADS);
    glVertex2f(-0.69f,-0.13f);
    glVertex2f(0.09f,-0.13f);
    glVertex2f(0.09f,-0.11f);
    glVertex2f(-0.69f,-0.11f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.69f, 0.13f);
    glVertex2f(0.09f, 0.13f);
    glVertex2f(0.09f, 0.15f);
    glVertex2f(-0.69f, 0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.69f, 0.37f);
    glVertex2f(0.09f, 0.37f);
    glVertex2f(0.09f, 0.39f);
    glVertex2f(-0.69f, 0.39f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.5f,0.5f);
    glVertex2f(-1.0f,-0.5f);
    glVertex2f(-0.8f,-0.5f);
    glVertex2f(-0.8f,-1.0f);
    glVertex2f(-1.0f,-1.0f);
    glEnd();


    //------------------TREEES-----------------------------------------------------

    //TREE1-------
    glColor3f(0.400f, 0.803f, 0.666f);

    drawCircle(0.3, -0.2889 + 0.05, 0.06);
    drawCircle(0.3 - 0.05, -0.2889, 0.05);
    drawCircle(0.3 + 0.05, -0.2889, 0.05);
    drawCircle(0.3, -0.2889 - 0.05, 0.06);


    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(0.3 - 0.015, -0.2889 - 0.125);
    glVertex2f(0.3 + 0.015, -0.2889 - 0.125);
    glVertex2f(0.3 + 0.015, -0.2889 - 0.05);
    glVertex2f(0.3 - 0.015, -0.2889 - 0.05);
    glEnd();


    //Tree2---------------
    glColor3f(0.400f, 0.803f, 0.666f);

    drawCircle(0.7, -0.2389, 0.06);
    drawCircle(0.65, -0.2889, 0.05);
    drawCircle(0.75, -0.2889, 0.05);
    drawCircle(0.7, -0.3389, 0.06);

    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(0.685, -0.4139);
    glVertex2f(0.715, -0.4139);
    glVertex2f(0.715, -0.3389);
    glVertex2f(0.685, -0.3389);
    glEnd();

    //TREE3--------------
    glColor3f(0.400f, 0.803f, 0.666f);

    drawCircle(-0.9, -0.2389, 0.06);

    drawCircle(-0.95, -0.2889, 0.05);
    drawCircle(-0.85, -0.2889, 0.05);
    drawCircle(-0.9, -0.3389, 0.06);

    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(-0.915, -0.4139);
    glVertex2f(-0.885, -0.4139);
    glVertex2f(-0.885, -0.3389);
    glVertex2f(-0.915, -0.3389);
    glEnd();


    //---------------------------------------------------------------------------
    drawSun(0.75f, 0.75f, 0.12f);

    glPushMatrix();
    glTranslatef(position2,0.0f,0.0f);
    drawCloud(-0.2f, 0.7f, 1.0f);
    drawCloud(-0.7f, 0.7f, 1.0f);
    drawCloud(0.6f, 0.6f, 1.0f);

    drawBird(0.3f, 0.75f, 0.5f);
    drawBird(0.5f, 0.76f, 0.5f);
    drawBird(-0.5f, 0.77f, 0.5f);
    glPopMatrix();

    //----------------bus-------------

    glPushMatrix();
    glTranslatef(position,0.0f,0.0f);
    // BUS BODY
    glColor3f(0.52f, 0.80f, 0.92f);   // sky blue
    glBegin(GL_QUADS);
    glVertex2f(-0.40f, -0.42f);
    glVertex2f(-0.20f, -0.42f);
    glVertex2f(-0.20f, -0.30f);
    glVertex2f(-0.40f, -0.30f);
    glEnd();

    // WINDOWS (inside the body)
    glColor3f(0.05f, 0.10f, 0.15f);

    // window 1
    glBegin(GL_QUADS);
    glVertex2f(-0.38f, -0.39f);
    glVertex2f(-0.33f, -0.39f);
    glVertex2f(-0.33f, -0.34f);
    glVertex2f(-0.38f, -0.34f);
    glEnd();

    // window 2
    glBegin(GL_QUADS);
    glVertex2f(-0.32f, -0.39f);
    glVertex2f(-0.27f, -0.39f);
    glVertex2f(-0.27f, -0.34f);
    glVertex2f(-0.32f, -0.34f);
    glEnd();

    // DOOR
    glBegin(GL_QUADS);
    glVertex2f(-0.26f, -0.42f);
    glVertex2f(-0.23f, -0.42f);
    glVertex2f(-0.23f, -0.33f);
    glVertex2f(-0.26f, -0.33f);
    glEnd();

    // WHEELS
    glColor3f(0.05f, 0.05f, 0.07f);
    drawCircle(-0.36f, -0.43f, 0.02f);   // left wheel
    drawCircle(-0.23f, -0.43f, 0.02f);   // right wheel

    glColor3f(0.6f, 0.6f, 0.6f);
    drawCircle(-0.36f, -0.43, 0.01);
    drawCircle(-0.23f, -0.43, 0.01);

    glPopMatrix();



    //--------------pond-------------

    glColor3f(0.5f,0.5f,0.5f);
    drawCircle(0.0f,-0.8f,0.22);//gray border
    glColor3f(0.52f, 0.80f, 0.92f);
    drawCircle(0.0f,-0.8f,0.2);//pond



    // ---- Small Pond Leaf ----
    glColor3f(0.0f, 0.39f, 0.0f);  // dark green
    glBegin(GL_POLYGON);
    // small round-ish leaf
    glVertex2f(0.00f, -0.78f);
    glVertex2f(0.015f, -0.78f);
    glVertex2f(0.025f, -0.79f);
    glVertex2f(0.03f, -0.80f);
    glVertex2f(0.025f, -0.81f);
    glVertex2f(0.015f, -0.82f);
    glVertex2f(0.00f, -0.82f);
    glVertex2f(-0.015f, -0.82f);
    glVertex2f(-0.025f, -0.81f);
    glVertex2f(-0.03f, -0.80f);
    glVertex2f(-0.025f, -0.79f);
    glVertex2f(-0.015f, -0.78f);
    glEnd();



    //-------------flowers---------------
    drawFlower(0.9f,  -0.52f);
    drawFlower(0.8f,  -0.52f);
    drawFlower(0.7f,  -0.52f);
    drawFlower(0.6f,  -0.52f);
    drawFlower(0.5f,  -0.52f);
    drawFlower(0.4f,  -0.52f);
    drawFlower(0.3f,  -0.52f);
    drawFlower(0.2f,  -0.52f);
    drawFlower(0.1f,  -0.52f);
    drawFlower(0.00f,  -0.52f);
    drawFlower(-0.1f,  -0.52f);
    drawFlower(-0.2f,  -0.52f);
    drawFlower(-0.3f,  -0.52f);
    drawFlower(-0.4f,  -0.52f);
    drawFlower(-0.5f,  -0.52f);
    drawFlower(-0.6f,  -0.52f);
    drawFlower(-0.7f,  -0.52f);

    flowerTree(0.95,-0.59);
    flowerTree(0.95,-0.6);
    flowerTree(0.95,-0.7);
    flowerTree(0.95,-0.8);
    flowerTree(0.95,-0.9);


    // ----- ZEBRA CROSSING STRIPES -----
    glColor3f(1.0f, 1.0f, 1.0f);   // white stripes


    // Stripe 1
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.55f);
    glVertex2f(-0.8f, -0.55f);
    glVertex2f(-0.8f, -0.60f);
    glVertex2f(-1.0f, -0.60f);
    glEnd();

    // Stripe 2
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.65f);
    glVertex2f(-0.8f, -0.65f);
    glVertex2f(-0.8f, -0.70f);
    glVertex2f(-1.0f, -0.70f);
    glEnd();

    // Stripe 3
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.75f);
    glVertex2f(-0.8f, -0.75f);
    glVertex2f(-0.8f, -0.80f);
    glVertex2f(-1.0f, -0.80f);
    glEnd();

    // Stripe 4
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.85f);
    glVertex2f(-0.8f, -0.85f);
    glVertex2f(-0.8f, -0.90f);
    glVertex2f(-1.0f, -0.90f);
    glEnd();

    // Stripe 5
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.95f);
    glVertex2f(-0.8f, -0.95f);
    glVertex2f(-0.8f, -1.00f);
    glVertex2f(-1.0f, -1.00f);
    glEnd();





    // ----- Small Simple Car -----

    glPushMatrix();
    glTranslatef(-0.6f, -0.43f, 0.0f);
    glTranslatef(position3,0.0f,0.0f);
    // ---- body ----
    glColor3f(0.2f, 0.6f, 0.9f); // car color (blue)
    glBegin(GL_QUADS);
    glVertex2f(-0.10f,  0.00f); // left-back
    glVertex2f( 0.10f,  0.00f); // right-back
    glVertex2f( 0.10f,  0.06f); // right-top
    glVertex2f(-0.10f,  0.06f); // left-top
    glEnd();

    glColor3f(0.05f, 0.12f, 0.18f);
    glBegin(GL_QUADS);
    glVertex2f(-0.04f, 0.06f);
    glVertex2f( 0.03f, 0.06f);
    glVertex2f( 0.03f, 0.095f);
    glVertex2f(-0.04f, 0.095f);
    glEnd();

    // ---- wheels ----
    glColor3f(0.02f, 0.02f, 0.02f); // tire
    drawCircle(-0.06f, -0.01f, 0.025f, 20); // left wheel
    drawCircle( 0.06f, -0.01f, 0.025f, 20); // right wheel

    // hubs
    glColor3f(0.6f, 0.6f, 0.6f);
    drawCircle(-0.06f, -0.01f, 0.010f, 20);
    drawCircle( 0.06f, -0.01f, 0.010f, 20);

    glPopMatrix();

    glFlush();
}

// Handle mouse click events
void handleMouse(int button, int state, int x, int y) {
    // increase speed
    if (button == GLUT_LEFT_BUTTON) {
        speed += 0.1f;
        speed3 +=0.1f;
    }

    // decrease speed
    if (button == GLUT_RIGHT_BUTTON) {
        speed -= 0.1f;
        speed3 -= 0.1f;
    }
        glutPostRedisplay();

}


// Handle keyboard input (ASCII keys)
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 's':
            speed = 0.0f;
            speed3= 0.0f;
            break;
        case 'r':
            speed = 0.01f;
            speed3 = 0.015;
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("scene");
    glutInitWindowSize(400, 400);
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(handleKeypress);              // Handle keyboard input
    glutMouseFunc(handleMouse);                    // Handle mouse input
    glutMainLoop();
    return 0;
}
