#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Menggambar bola pertama
    glColor3f(1.0, 0.0, 0.0); // Warna merah
    glPushMatrix();
    glTranslatef(-0.5, 0.0, 0.0);
    glutSolidSphere(0.3, 50, 50);
    glPopMatrix();

    // Menggambar bola kedua
    glColor3f(0.0, 0.0, 1.0); // Warna biru
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glutSolidSphere(0.3, 50, 50);
    glPopMatrix();

    // Menggunakan teknik boolean untuk menggabungkan kedua bola
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glColor3f(0.0, 1.0, 0.0); // Warna hijau untuk hasil gabungan
    glutSolidSphere(0.4, 50, 50);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Contoh Pemodelan Boolean");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Warna background putih

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

