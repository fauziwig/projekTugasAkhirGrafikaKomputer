/*Keterangan 
Posisi : up = atas, bot = bawah, front = depan, back = belakang, l = kiri(left), r = kanan(right)
face = sisi
*/
#include <GL/glut.h>
#include <cmath>

// Camera position and rotation
float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = 5.0f;
float cameraRotationX = 0.0f;
float cameraRotationY = 0.0f;

float minorRadius = 0.28f; // Jari-jari dalam donat
float majorRadius = 0.5f; // Jari-jari luar donat
float minorRadiusLampu = 0.2f; //Jari jari dalam bentuk donat -> lampu
float majorRadiusLampu = 0.05f; 
//GLfloat torusRotation = 0.0f; //variabel untuk rotasi sekian derajat 

// Zoom level
float zoom = 1.0f;


void drawCube() {
    // Example: Draw a cube with six different colored faces
    glBegin(GL_QUADS);
//	glBegin(GL_POLYGON);

    // face (blue)
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-5.0f, -0.5f, -1.4f);
    glVertex3f(2.0f, -0.5f, -1.4f);
    glVertex3f(2.0f, 2.0f, -1.4f);
    glVertex3f(-5.0f, 2.0f, -1.4f);

    // face (green)
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-5.0f, -0.5f, 0.5f); //bot l
    glVertex3f(2.0f, -0.5f, 0.5f); //bot r
    glVertex3f(2.0f, 2.0f, 0.5f); //up r
    glVertex3f(-5.0f, 2.0f, 0.5f); //up l

//PINTU BUS 
    // Pintu di face green 
    glColor3f(0.1f, 0.1f, 0.38f);
    glVertex3f(-5.0f, -0.5f, 0.519f); //bot l
    glVertex3f(-4.0f, -0.5f, 0.519f); //bot r
    glVertex3f(-4.0f, 2.0f, 0.519f); //up r
    glVertex3f(-5.0f, 2.0f, 0.519f); //up l
    
    // Pintu di face blue
    glColor3f(0.1f, 0.1f, 0.38f);
    glVertex3f(-5.0f, -0.5f, -1.419f); //bot l
    glVertex3f(-4.0f, -0.5f, -1.419f); //bot r
    glVertex3f(-4.0f, 2.0f, -1.419f); //up r
    glVertex3f(-5.0f, 2.0f, -1.419f); //up l
    
//JENDELA BUS
    //jendela 1 di sisi green
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-4.0f, 1.0f, 0.51f); //bot l
    glVertex3f(-3.0f, 1.0f, 0.51f); //bot r
    glVertex3f(-3.0f, 1.7f, 0.51f); //up r
    glVertex3f(-4.0f, 1.7f, 0.51f); //up l
    
    //jendela 2 di sisi green
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-2.8f, 1.0f, 0.51f); //bot l
    glVertex3f(-1.8f, 1.0f, 0.51f); //bot r
    glVertex3f(-1.8f, 1.7f, 0.51f); //up r
    glVertex3f(-2.8f, 1.7f, 0.51f); //up l
    
    //jendela 3 di sisi green
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.6f, 1.0f, 0.51f); //bot l
    glVertex3f(-0.6f, 1.0f, 0.51f); //bot r
    glVertex3f(-0.6f, 1.7f, 0.51f); //up r
    glVertex3f(-1.6f, 1.7f, 0.51f); //up l
    
    //jendela 4 di sisi green
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.4f, 1.0f, 0.51f); //bot l
    glVertex3f(0.55f, 1.0f, 0.51f); //bot r
    glVertex3f(0.55f, 1.7f, 0.51f); //up r
    glVertex3f(-0.4f, 1.7f, 0.51f); //up l
    
    //jendela 5 di sisi green
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.77f, 1.0f, 0.51f); //bot l
    glVertex3f(1.77f, 1.0f, 0.51f); //bot r
    glVertex3f(1.77f, 1.7f, 0.51f); //up r
    glVertex3f(0.77f, 1.7f, 0.51f); //up l
    
     //jendela 1 di sisi blue
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-4.0f, 1.0f, -1.41f); //bot l
    glVertex3f(-3.0f, 1.0f, -1.41f); //bot r
    glVertex3f(-3.0f, 1.7f, -1.41f); //up r
    glVertex3f(-4.0f, 1.7f, -1.41f); //up l

	//jendela 2 di sisi blue
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-2.8f, 1.0f, -1.41f); //bot l
    glVertex3f(-1.8f, 1.0f, -1.41f); //bot r
    glVertex3f(-1.8f, 1.7f, -1.41f); //up r
    glVertex3f(-2.8f, 1.7f, -1.41f); //up l
    
    //jendela 3 di sisi blue
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.6f, 1.0f, -1.41f); //bot l
    glVertex3f(-0.6f, 1.0f, -1.41f); //bot r
    glVertex3f(-0.6f, 1.7f, -1.41f); //up r
    glVertex3f(-1.6f, 1.7f, -1.41f); //up l
    
    //jendela 4 di sisi blue
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.4f, 1.0f, -1.41f); //bot l
    glVertex3f(0.55f, 1.0f, -1.41f); //bot r
    glVertex3f(0.55f, 1.7f, -1.41f); //up r
    glVertex3f(-0.4f, 1.7f, -1.41f); //up l
    
    //jendela 5 di sisi blue
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.77f, 1.0f, -1.41f); //bot l
    glVertex3f(1.77f, 1.0f, -1.41f); //bot r
    glVertex3f(1.77f, 1.7f, -1.41f); //up r
    glVertex3f(0.77f, 1.7f, -1.41f); //up l
    
    //Left face (red)
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-5.0f, -0.5f, -1.4f);
    glVertex3f(-5.0f, -0.5f, 0.5f);
    glVertex3f(-5.0f, 2.0f, 0.5f);
    glVertex3f(-5.0f, 2.0f, -1.4f);

	//jendela kaca di sisi red
    glColor3f(0.6f, 0.6f, 0.8f);
    glVertex3f(-5.0001f, 0.5f, -1.4f); //bot l
    glVertex3f(-5.0001f, 0.5f, 0.5f); //bot r
    glVertex3f(-5.0001f, 2.0f, 0.5f); //up r
    glVertex3f(-5.0001f, 2.0f, -1.4f); //up l
	
	//jendela kaca di sisi red (lampu sen l)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-5.001f, -0.4f, -1.2f); //bot l
    glVertex3f(-5.001f, -0.4f, -0.7f); //bot r
    glVertex3f(-5.001f, -0.3f, -0.7f); //up r
    glVertex3f(-5.001f, -0.3f, -1.2f); //up l
	
	//jendela kaca di sisi red (lampu sen r)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-5.001f, -0.4f, -0.2f); //bot l
    glVertex3f(-5.001f, -0.4f, 0.3f); //bot r
    glVertex3f(-5.001f, -0.3f, 0.3f); //up r
    glVertex3f(-5.001f, -0.3f, -0.2f); //up l
	
    // Right face (yellow)
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(2.0f, -0.5f, -1.4f);
    glVertex3f(2.0f, -0.5f, 0.5f);
    glVertex3f(2.0f, 2.0f, 0.5f);
    glVertex3f(2.0f, 2.0f, -1.4f);

	//jendela kaca di sisi kuning
    glColor3f(0.6f, 0.6f, 0.8f);
    glVertex3f(2.0001f, 0.8f, -1.4f); //bot l
    glVertex3f(2.0001f, 0.8f, 0.5f); //bot r
    glVertex3f(2.0001f, 2.0f, 0.5f); //up r
    glVertex3f(2.0001f, 2.0f, -1.4f); //up l

	//jendela kaca di sisi red (lampu stop r)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(2.001f, -0.3f, -1.2f); //bot l
    glVertex3f(2.001f, -0.3f, -0.7f); //bot r
    glVertex3f(2.001f, -0.1f, -0.8f); //up r
    glVertex3f(2.001f, -0.1f, -1.2f); //up l
	
	//jendela kaca di sisi red (lampu stop l)
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex3f(2.001f, -0.3f, -0.2f); //bot l
    glVertex3f(2.001f, -0.3f, 0.3f); //bot r
    glVertex3f(2.001f, -0.1f, 0.3f); //up r
    glVertex3f(2.001f, -0.1f, -0.1f); //up l

    // Top face (cyan)
    glColor3f(0.1f, 0.1f, 0.35f);
    glVertex3f(-5.0f, 2.0f, -1.4f);
    glVertex3f(2.0f, 2.0f, -1.4f);
    glVertex3f(2.0f, 2.0f, 0.5f);
    glVertex3f(-5.0f, 2.0f, 0.5f);

    // Bottom face (magenta)
    glColor3f(0.1f, 0.1f, 0.35f);
    glVertex3f(-5.0f, -0.5f, -1.4f);
    glVertex3f(2.0f, -0.5f, -1.4f);
    glVertex3f(2.0f, -0.5f, 0.5f);
    glVertex3f(-5.0f, -0.5f, 0.5f);
    
    glEnd();
}

void drawSolidCylinder(float baseRadius, float topRadius, float height, int slices, int stacks) {
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    
    // Draw the body of the cylinder
    gluCylinder(quadric, baseRadius, topRadius, height, slices, stacks);

    // Draw the top cap of the cylinder
    gluQuadricOrientation(quadric, GLU_INSIDE);
    gluDisk(quadric, 0, topRadius, slices, 1);

    // Draw the bottom cap of the cylinder
    gluQuadricOrientation(quadric, GLU_OUTSIDE);
    glTranslatef(0, 0, height);
    gluDisk(quadric, 0, baseRadius, slices, 1);

    gluDeleteQuadric(quadric);	
}

void drawWheel() {
    // Example: Draw a wheel as a cylinder
    glColor3f(0.2f, 0.2f, 0.2f); // Black color
    drawSolidCylinder(0.5f, 0.5f, 0.5f, 20, 20);
}

//objek ban wheels luar yang warna hitam
void drawWheelLuar(){
	glColor3f(0.1, 0.1, 0.1); // Warna abu abu gelap
	glutSolidTorus(minorRadius, majorRadius, 50, 50);
}

//objek lampu bus
void drawLampu(){
	glColor3f(1.0, 1.0, 1.0); // Warna abu abu gelap
	glutSolidTorus(minorRadiusLampu, majorRadiusLampu, 50, 50);
}

//objek silinder untuk wheels dalam
void drawCylinder(float radius, float height, int numSegments) {
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= numSegments; ++i) {
        float angle = static_cast<float>(i) / numSegments * 2.0f * 3.14159f;
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        // Top vertex
        glVertex3f(x, y, height / 2.0f);

        // Bottom vertex
        glVertex3f(x, y, -height / 2.0f);
    }
    glEnd();
}

void drawTree() {
    // Draw the trunk of the tree
    glColor3f(0.65f, 0.16f, 0.16f); // Brown color
    glPushMatrix();
    glScalef(0.5f, 4.0f, 0.5f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw the leaves of the tree
    glColor3f(0.0f, 0.5f, 0.0f); // Green color
    glPushMatrix();
    glTranslatef(0.0f, 2.6f, 0.0f);
    glutSolidDodecahedron();
    glPopMatrix();
}

void drawJalan(){
	glBegin(GL_QUADS);
	
	// Road Jalan Raya
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex3f(-9.0f, -1.27f, -3.4f);
    glVertex3f(6.0f, -1.27f, -3.4f);
    glVertex3f(6.0f, -1.27f, 2.5f);
    glVertex3f(-9.0f, -1.27f, 2.5f);
	
	// Marka jalan putih putus putus 4 (dari r)(dari back bus)
    glColor3f(1.0f, 1.0f, 1.0f); 
    glVertex3f(6.0f, -1.26f, -0.6f); //up r
    glVertex3f(4.5f, -1.26f, -0.6f); //up l
    glVertex3f(4.5f, -1.26f, -0.3f); //bot l
    glVertex3f(6.0f, -1.26f, -0.3f); //bot r
	
	// Marka jalan putih putus putus
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(3.0f, -1.26f, -0.6f); //up r
    glVertex3f(1.0f, -1.26f, -0.6f); //up l
    glVertex3f(1.0f, -1.26f, -0.3f); //bot l
    glVertex3f(3.0f, -1.26f, -0.3f); //bot r
    
    // Marka jalan putih putus putus
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.5f, -1.26f, -0.6f); //up r
    glVertex3f(-2.5f, -1.26f, -0.6f); //up l
    glVertex3f(-2.5f, -1.26f, -0.3f); //bot l
    glVertex3f(-0.5f, -1.26f, -0.3f); //bot r

	// Marka jalan putih putus putus
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-4.0f, -1.26f, -0.6f); //up r
    glVertex3f(-6.0f, -1.26f, -0.6f); //up l
    glVertex3f(-6.0f, -1.26f, -0.3f); //bot l
    glVertex3f(-4.0f, -1.26f, -0.3f); //bot r
	
	// Marka jalan putih putus putus
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-8.0f, -1.26f, -0.6f); //up r
    glVertex3f(-9.0f, -1.26f, -0.6f); //up l
    glVertex3f(-9.0f, -1.26f, -0.3f); //bot l
    glVertex3f(-8.0f, -1.26f, -0.3f); //bot r
	
	glEnd();
}

void drawTrotoar(){
    glBegin(GL_QUADS);
    
    // Trotoar (bot)
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-9.0f, -1.27f, 2.5f);
    glVertex3f(6.0f, -1.27f, 2.5f);
    glVertex3f(6.0f, -1.27f, 4.0f);
    glVertex3f(-9.0f, -1.27f, 4.0f);
	
	// Trotoar (up)
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-9.0f, -1.0f, 2.5f);
    glVertex3f(6.0f, -1.0f, 2.5f);
    glVertex3f(6.0f, -1.0f, 4.0f);
    glVertex3f(-9.0f, -1.0f, 4.0f);
	
	// Trotoar (r)
    glColor3f(0.13f, 0.13f, 0.13f);
    glVertex3f(6.0f, -1.27f, 2.5f); //back bot
    glVertex3f(6.0f, -1.27f, 4.0f); //front bot
    glVertex3f(6.0f, -1.0f, 4.0f); //front up
    glVertex3f(6.0f, -1.0f, 2.5f); //back up
	
	// Trotoar (l)
    glColor3f(0.13f, 0.13f, 0.13f);
    glVertex3f(-9.0f, -1.27f, 2.5f); //back bot
    glVertex3f(-9.0f, -1.27f, 4.0f); //front bot
    glVertex3f(-9.0f, -1.0f, 4.0f); //front up
    glVertex3f(-9.0f, -1.0f, 2.5f); //back up
	
	// Trotoar (front)
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-9.0f, -1.27f, 4.0f); //back bot
    glVertex3f(6.0f, -1.27f, 4.0f); //front bot
    glVertex3f(6.0f, -1.0f, 4.0f); //front up
    glVertex3f(-9.0f, -1.0f, 4.0f); //back up
	
	// Trotoar (back)
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-9.0f, -1.27f, 2.5f); //back bot
    glVertex3f(6.0f, -1.27f, 2.5f); //front bot
    glVertex3f(6.0f, -1.0f, 2.5f); //front up
    glVertex3f(-9.0f, -1.0f, 2.5f); //back up
    
    glEnd();
}

void drawKota(){
	glBegin(GL_QUADS);
	
	// face (blue)
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex3f(-5.0f, -0.5f, -1.4f);
    glVertex3f(-1.0f, -0.5f, -1.4f);
    glVertex3f(-1.0f, 5.0f, -1.4f);
    glVertex3f(-5.0f, 5.0f, -1.4f);

    // face (green)
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex3f(-5.0f, -0.5f, 0.5f); //bot l
    glVertex3f(-1.0f, -0.5f, 0.5f); //bot r
    glVertex3f(-1.0f, 5.0f, 0.5f); //up r
    glVertex3f(-5.0f, 5.0f, 0.5f); //up l
    
    // Top face (cyan)
    glColor3f(0.33f, 0.33f, 0.33f);
    glVertex3f(-5.0f, 5.0f, -1.4f);
    glVertex3f(-1.0f, 5.0f, -1.4f);
    glVertex3f(-1.0f, 5.0f, 0.5f);
    glVertex3f(-5.0f, 5.0f, 0.5f);

    // Bottom face (magenta)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-5.0f, -0.5f, -1.4f);
    glVertex3f(-1.0f, -0.5f, -1.4f);
    glVertex3f(-1.0f, -0.5f, 0.5f);
    glVertex3f(-5.0f, -0.5f, 0.5f);
    
    // Left face (red)
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-5.0f, -0.5f, -1.4f);
    glVertex3f(-5.0f, -0.5f, 0.5f);
    glVertex3f(-5.0f, 5.0f, 0.5f);
    glVertex3f(-5.0f, 5.0f, -1.4f);
    
    // Right face (yellow)
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-1.0f, -0.5f, -1.4f);
    glVertex3f(-1.0f, -0.5f, 0.5f);
    glVertex3f(-1.0f, 5.0f, 0.5f);
    glVertex3f(-1.0f, 5.0f, -1.4f);
	
	glEnd();
}

void drawKota2(){
	glBegin(GL_QUADS);
	
	// face (blue)
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-5.0f, -0.5f, -1.4f);
    glVertex3f(-1.0f, -0.5f, -1.4f);
    glVertex3f(-1.0f, 6.5f, -1.4f);
    glVertex3f(-5.0f, 6.5f, -1.4f);

    // face (green)
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-5.0f, -0.5f, 0.5f); //bot l
    glVertex3f(-1.0f, -0.5f, 0.5f); //bot r
    glVertex3f(-1.0f, 6.5f, 0.5f); //up r
    glVertex3f(-5.0f, 6.5f, 0.5f); //up l
    
    // Top face (cyan)
    glColor3f(0.44f, 0.44f, 0.44f);
    glVertex3f(-5.0f, 6.5f, -1.4f);
    glVertex3f(-1.0f, 6.5f, -1.4f);
    glVertex3f(-1.0f, 6.5f, 0.5f);
    glVertex3f(-5.0f, 6.5f, 0.5f);

    // Bottom face (magenta)
    glColor3f(0.44f, 0.44f, 0.44f);
    glVertex3f(-5.0f, -0.5f, -1.4f);
    glVertex3f(-1.0f, -0.5f, -1.4f);
    glVertex3f(-1.0f, -0.5f, 0.5f);
    glVertex3f(-5.0f, -0.5f, 0.5f);
    
    // Left face (red)
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(-5.0f, -0.5f, -1.4f);
    glVertex3f(-5.0f, -0.5f, 0.5f);
    glVertex3f(-5.0f, 6.5f, 0.5f);
    glVertex3f(-5.0f, 6.5f, -1.4f);
    
    // Right face (yellow)
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(-1.0f, -0.5f, -1.4f);
    glVertex3f(-1.0f, -0.5f, 0.5f);
    glVertex3f(-1.0f, 6.5f, 0.5f);
    glVertex3f(-1.0f, 6.5f, -1.4f);
	
	glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

//	gluLookAt(cameraX, cameraY, cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Set the camera position and rotation
    glTranslatef(0.0f, 0.0f, -cameraZ);
    glRotatef(cameraRotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(cameraRotationY, 0.0f, 1.0f, 0.0f);

    // Apply zoom level
    glScalef(zoom, zoom, zoom);

    // Draw the cube
    drawCube();
    
    //draw trotoar front r
    glPushMatrix(); 
    glTranslatef(0.1f, 0.0f, -0.1f);
    drawTrotoar();
    glPopMatrix();
    
    //draw trotoar front l
    glPushMatrix(); 
    glTranslatef(-14.8f, 0.0f, -0.1f);
    drawTrotoar();
    glPopMatrix();
    
    //draw trotoar back r
    glPushMatrix(); 
    glTranslatef(0.1f, 0.0f, -7.3f);
    drawTrotoar();
    glPopMatrix();
    
    //draw trotoar back l
    glPushMatrix(); 
    glTranslatef(-14.8f, 0.0f, -7.3f);
    drawTrotoar();
    glPopMatrix();
    
    //draw jalan raya
    glPushMatrix(); 
    glTranslatef(0.1f, 0.0f, 0.1f);
    drawJalan();
    glPopMatrix();
	
	//draw jalan raya
    glPushMatrix(); 
    glTranslatef(-14.8f, 0.0f, 0.1f);
    drawJalan();
    glPopMatrix();
    
    //draw kota
    glPushMatrix();
    glTranslatef(-14.8f, -1.0f, -6.1f);
	drawKota();
	glPopMatrix();
	
	//draw kota 2
    glPushMatrix();
    glTranslatef(-9.8f, -1.0f, -6.1f);
	drawKota2();
	glPopMatrix();
	
	//draw kota
    glPushMatrix();
    glTranslatef(-4.8f, -1.0f, -6.1f);
	drawKota();
	glPopMatrix();
	
    // Draw the wheels dalem abu abu
    glPushMatrix(); //back r
    glTranslatef(0.5f, -0.5f, -1.74f);
    drawWheel();
    glPopMatrix();

    glPushMatrix(); //back l
    glTranslatef(-3.5f, -0.5f, -1.74f);
    drawWheel();
    glPopMatrix();

    glPushMatrix(); //front r
    glTranslatef(0.5f, -0.5f, 0.34f);
    drawWheel();
    glPopMatrix();

    glPushMatrix(); //front l
    glTranslatef(-3.5f, -0.5f, 0.34f);
    drawWheel();
    glPopMatrix();

	//wheel luar hitam
	glPushMatrix();  //back r
    glTranslatef(0.5f, -0.5f, -1.5f);
    drawWheelLuar();
    glPopMatrix();
    
    glPushMatrix();  //back l
    glTranslatef(-3.6f, -0.5f, -1.5f);
    drawWheelLuar();
    glPopMatrix();
    
    glPushMatrix();  //front l
    glTranslatef(-3.6f, -0.5f, 0.6f);
    drawWheelLuar();
    glPopMatrix();
    
    glPushMatrix();  //front r
    glTranslatef(0.5f, -0.5f, 0.6f);
    drawWheelLuar();
    glPopMatrix();
	

	//lampu bis 
	glPushMatrix();  
    glTranslatef(-4.95f, 0.1f, -0.9f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawLampu();
    glPopMatrix();
    
    //lampu bis 2
	glPushMatrix();  
    glTranslatef(-4.95f, 0.1f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawLampu();
    glPopMatrix();
    
    //lowpoly tree
	glPushMatrix();  
    glTranslatef(-5.95f, 0.5f, 3.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawTree();
    glPopMatrix();
	
	//lowpoly tree
	glPushMatrix();  
    glTranslatef(2.95f, 0.5f, 3.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawTree();
    glPopMatrix();
	
    glFlush();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'z':
            zoom += 0.1f;
            break;
        case 'x':
            zoom -= 0.1f;
            break;
        case 'w':
            cameraRotationX += 5.0f;
            break;
        case 's':
            cameraRotationX -= 5.0f;
            break;
        case 'a':
            cameraRotationY += 5.0f;
            break;
        case 'd':
            cameraRotationY -= 5.0f;
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Representasi Objek Transportasi");
    glEnable(GL_DEPTH_TEST);
    
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
//    glutIdleFunc(rotateTorus); // Rotate the torus during idle time
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}

