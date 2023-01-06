/*
 * Atividade 06 - Computacao Grafica
 * Codigo OpenGL responsavel pelo plano de fundo e outros extras
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Data: 22/12/2022
*/

#ifndef extras_h
#define extras_h

#include <cmath>


void desenhaFumaca(int w, int h, int qtdTriangulos, GLfloat angulo) 
{
    glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);

        glPushMatrix();
            glTranslatef(-w + 211, -h + 472, 0.0);
            glBegin(GL_TRIANGLE_FAN);
                for (int i = 1; i <= qtdTriangulos; i++) {
                    glVertex2f(15*cos(i*angulo) - 12*sin(i*angulo), 15*sin(i*angulo) + 12*cos(i*angulo));
                }
            glEnd();
        glPopMatrix();

        for (int i = 1; i < 14; i++) {
            glPushMatrix();
                glTranslatef(-w + 207+(20*i), -h + 475, 0.0);
                glBegin(GL_TRIANGLE_FAN);
                    for (int i = 1; i <= qtdTriangulos; i++) {
                        glVertex2f(20*cos(i*angulo) - 15*sin(i*angulo), 20*sin(i*angulo) + 15*cos(i*angulo));
                    }
                glEnd();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-w + 227+(18*i), -h + 475, 0.0);
                glBegin(GL_TRIANGLE_FAN);
                    for (int i = 1; i <= qtdTriangulos; i++) {
                        glVertex2f(20*cos(i*angulo) - 12*sin(i*angulo), 20*sin(i*angulo) + 12*cos(i*angulo));
                    }
                glEnd();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-w + 245+(12*i), -h + 475, 0.0);
                glBegin(GL_TRIANGLE_FAN);
                    for (int i = 1; i <= qtdTriangulos; i++) {
                        glVertex2f(15*cos(i*angulo) - 10*sin(i*angulo), 15*sin(i*angulo) + 10*cos(i*angulo));
                    }
                glEnd();
            glPopMatrix();
        }


        for (int i = 1; i < 4; i++) {
            glPushMatrix();
                glTranslatef(-w + 506, -h + 393+(14*i), 0.0);
                glBegin(GL_TRIANGLE_FAN);
                    for (int i = 0; i < qtdTriangulos; i++) {
                        glVertex2f(20*cos(i*angulo) - 15*sin(i*angulo), 20*sin(i*angulo) + 15*cos(i*angulo));
                    }
                glEnd();
            glPopMatrix();
        }

        glPushMatrix();
            glTranslatef(-w + 488, -h + 473, 0.0);
            glBegin(GL_TRIANGLE_FAN);
                for (int i = 1; i < qtdTriangulos; i++) {
                    glVertex2f(15*cos(i*angulo) - 10*sin(i*angulo), 15*sin(i*angulo) + 10*cos(i*angulo));
                }
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-w + 495, -h + 458, 0.0);
            glBegin(GL_TRIANGLE_FAN);
                for (int i = 1; i < qtdTriangulos; i++) {
                    glVertex2f(20*cos(i*angulo) - 15*sin(i*angulo), 20*sin(i*angulo) + 15*cos(i*angulo));
                }
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-w + 511, -h + 450, 0.0);
            glBegin(GL_TRIANGLE_FAN);
                for (int i = 1; i < qtdTriangulos; i++) {
                    glVertex2f(15*cos(i*angulo) - 10*sin(i*angulo), 15*sin(i*angulo) + 10*cos(i*angulo));
                }
            glEnd();
        glPopMatrix();

    glPopMatrix();
}


void desenhaDegrade(int w, int h, int camada)
{
    glColor3f(0.06 + (0.005)*camada, 0.11 + (0.005)*camada, 0.23 + (0.005)*camada);
    glBegin(GL_QUAD_STRIP);

        // Desenha as montanhas com base no comprimento da janela
        int qtdElevacoes = 0, incAltura = 30;

        while (-w + (30*qtdElevacoes) < w+20) {
            glVertex2f(-w + (30*qtdElevacoes), -h + 58);
            glVertex2f(-w + (30*qtdElevacoes), -h + 300-(10*camada) + incAltura);

            if (incAltura == 30) {
                incAltura += 10;
            } else if (incAltura == 50) {
                incAltura -= 10; 
            } else {
                if (qtdElevacoes % 2 != 0) {
                    incAltura += 10;
                } else {
                    incAltura -= 10;
                }
            }

            qtdElevacoes++;
        }
    glEnd();
}


void desenhaExtras(int w, int h, int qtdTriangulos, GLfloat angulo) 
{
    // Background
    glColor3f(0.06, 0.11, 0.23);
    glBegin(GL_QUADS);
        glVertex2f(-w, -h);
        glVertex2f( w, -h);
        glVertex2f( w,  h);
        glVertex2f(-w,  h);
    glEnd();

    // Degrade do ceu
    for (int i = 1; i < 10; i++) {
        desenhaDegrade(w, h, i);
    }

    // Lua
    glColor3f(0.81, 0.81, 0.81);
    glPushMatrix();
        glTranslatef(w - 80, h - 60, 0.0);
        glBegin(GL_TRIANGLE_FAN);
            for (int i = 1; i <= qtdTriangulos; i++) {
                glVertex2f(50*cos(i*angulo) - 35*sin(i*angulo), 50*sin(i*angulo) + 35*cos(i*angulo));
            }
        glEnd();
    glPopMatrix();

    // Estrada de terra
    glColor3f(0.43, 0.09, 0.02);
    glBegin(GL_QUADS);
        glVertex2f(-w, -h);
        glVertex2f( w, -h);
        glVertex2f( w, -h + 58);
        glVertex2f(-w, -h + 58);
    glEnd();
    
    // Trilhos
    glColor3f(0.55, 0.55, 0.55);
    glBegin(GL_QUADS);
        glVertex2f(-w, -h + 56);
        glVertex2f( w, -h + 56);
        glVertex2f( w, -h + 58);
        glVertex2f(-w, -h + 58);
    glEnd();
    
    // Fumaca da chamine
    desenhaFumaca(w, h, qtdTriangulos, angulo);

    // Farol?
    glColor3f(0.63, 0.67, 0.23);
    glBegin(GL_TRIANGLES);
        glVertex2f(-w + 551, -h + 255);
        glVertex2f( w, -h + 275);
        glVertex2f( w, -h + 235);
    glEnd();

    glColor3f(0.79, 0.85, 0.32);
    glBegin(GL_TRIANGLES);
        glVertex2f(-w + 550, -h + 255);
        glVertex2f( w, -h + 275);
        glVertex2f( w, -h + 255);
    glEnd();
}


#endif