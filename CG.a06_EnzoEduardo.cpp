/*
 * Atividade 06 - Computacao Grafica
 * Codigo OpenGL/GLUT que desenha um trem 2D
 * Autor: Enzo Eduardo Cassiano Ibiapina
 * Data: 25/12/2022
*/





// Diretiva que garante compatibilidade do código para Windows/Linux/Mac OS
#ifdef __APPLE__                                    // Mac OS
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else                                               // Windows/Linux
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif


// Bibliotecas
#include <cstdlib>
#include <cmath>
#include "extras.h"


// Variaveis globais que definem as cores
float R, G, B;                                      // Definem as cores
int qtdTriangulos;                                  // Define a quantidade de triangulos criados pro circulo
GLfloat angulo;                                     // Define o angulo baseado na qtdTriangulos


// Prototipos das auxiliares usadas nas funcoes callback do OpenGL
void init(void);
void reshape(int w, int h);
void display(void);





// Funcao principal
int main (int argc, char** argv) {
    glutInit(&argc, argv);                          // Passagem de parametros C para o glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Selecao do modo do Display e do Sistema de cor utilizado
    glutInitWindowSize(768, 512);                   // Tamanho da janela do OpenGL
    glutInitWindowPosition(100, 100);               // Posicao inicial da janela do OpenGL
    glutCreateWindow("Trem2D_Enzo");                // Da nome para uma janela OpenGL

    init();                                         // Chama a funcao init()

    glutReshapeFunc(reshape);                       // Funcao callback para redesenhar a tela
    glutDisplayFunc(display);                       // Funcao callback de desenho
    glutMainLoop();                                 // Executa o loop do OpenGL

    return EXIT_SUCCESS;                            // Retorna 0 para o tipo inteiro da funcao main()
}





/*
 * Inicializa alguns parametros do GLUT
 */
void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);               // Limpa a tela com a cor branca

    R = 0.0; G = 0.0; B = 0.0;                      // "Inicializa" as variaveis globais de cores

    qtdTriangulos = 30;                             // Qtd de triangulos para um circulo

    angulo = (2 * M_PI) / qtdTriangulos;            // Calculo do angulo
}



/*
 * Ajusta a projecao para o redesenho da janela
 */
void reshape(int w, int h) {

    // Reinicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    // Definindo o Viewport para o tamanho da janela
	glViewport(0, 0, w, h);

    // Define as coordenadas dos eixos x, y e z
    glOrtho (-(w/2), (w/2), -(h/2), (h/2), -1 ,1);      // O centro dos eixos x e y no centro da tela,
                                                        // enquanto ainda dependente do tamanho da tela.

    // muda para o modo GL_MODELVIEW (nao pretendemos alterar a projecao
    // quando estivermos desenhando na tela)
	glMatrixMode(GL_MODELVIEW);
}



/*
 * Funcao usada na funcao callback para desenhar na tela
*/
void display(void){

    /* Desenhando nessa orientacao
      /     
     (      ^
      \    /
       `__´
    */

    // Limpa o buffer de cores, e reinicia a matriz
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Variaveis que pegam medidas atuais da janela
    float w = glutGet(GLUT_WINDOW_WIDTH) / 2;
    float h = glutGet(GLUT_WINDOW_HEIGHT) / 2;

    // Carrega o background da imagem
    desenhaExtras(w, h, qtdTriangulos, angulo);


    // Desenha o vagao
        // Carga (parte vermelha)
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_TRIANGLES);
            glVertex2f(-w +  34, -h + 136);
            glVertex2f(-w + 284, -h + 136);
            glVertex2f(-w +  34, -h + 256);
        glEnd();

        // Carga (parte verde)
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_TRIANGLES);
            glVertex2f(-w + 284, -h + 136);
            glVertex2f(-w + 284, -h + 256);
            glVertex2f(-w +  34, -h + 256);
        glEnd();

        // Teto (amarelo)
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_TRIANGLES);
            glVertex2f(-w +  46, -h + 256);
            glVertex2f(-w + 272, -h + 256);
            glVertex2f(-w + 164, -h + 336);
        glEnd();


    // Desenha o engate ferroviario (preto)
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(-w + 284, -h + 154);
        glVertex2f(-w + 314, -h + 154);
        glVertex2f(-w + 314, -h + 174);
        glVertex2f(-w + 284, -h + 174);
    glEnd();


    // Desenha a locomotiva
        // Cabine
            // Parte inferior (azul)
            glColor3f(0.0, 0.0, 1.0);
            glBegin(GL_QUADS);
                glVertex2f(-w + 314, -h + 136);
                glVertex2f(-w + 434, -h + 136);
                glVertex2f(-w + 434, -h + 256);
                glVertex2f(-w + 314, -h + 256);
            glEnd();

            // Parte superior (vermelha)
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_QUADS);
                glVertex2f(-w + 314, -h + 256);
                glVertex2f(-w + 434, -h + 256);
                glVertex2f(-w + 434, -h + 376);
                glVertex2f(-w + 314, -h + 376);
            glEnd();

            // Janela (azul claro)
            glColor3f(0.0, 1.0, 1.0);
            glBegin(GL_QUADS);
                glVertex2f(-w + 324, -h + 266);
                glVertex2f(-w + 424, -h + 266);
                glVertex2f(-w + 424, -h + 366);
                glVertex2f(-w + 324, -h + 366);
            glEnd();

            // Teto (azul escuro)
            glColor3f(0.0, 0.0, 1.0);
            glBegin(GL_QUADS);
                glVertex2f(-w + 304, -h + 376);
                glVertex2f(-w + 444, -h + 376);
                glVertex2f(-w + 444, -h + 388);
                glVertex2f(-w + 304, -h + 388);
            glEnd();


        // Motor
            // "Capo" do trem (amarelo)
            glColor3f(1.0, 1.0, 0.0);
            glBegin(GL_QUADS);
                glVertex2f(-w + 434, -h + 136);
                glVertex2f(-w + 554, -h + 136);
                glVertex2f(-w + 554, -h + 256);
                glVertex2f(-w + 434, -h + 256);
            glEnd();

            // Chamine (vermelho)
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_QUADS);
                glVertex2f(-w + 484, -h + 256);
                glVertex2f(-w + 529, -h + 256);
                glVertex2f(-w + 529, -h + 376);
                glVertex2f(-w + 484, -h + 376);
            glEnd();

            // Teto da chamine (azul escuro)
            glColor3f(0.0, 0.0, 1.0);
            glBegin(GL_QUADS);
                glVertex2f(-w + 474, -h + 376);
                glVertex2f(-w + 539, -h + 376);
                glVertex2f(-w + 539, -h + 390);
                glVertex2f(-w + 474, -h + 390);
            glEnd();

            // Cowcatcher (vermelho)
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_TRIANGLES);
                glVertex2f(-w + 554, -h + 136);
                glVertex2f(-w + 634, -h + 136);
                glVertex2f(-w + 554, -h + 256);
            glEnd();


        // Rodas
            // Vagao
                // Traseira (preta)
                glColor3f(0.0, 0.0, 0.0);        
                glPushMatrix();
                    glTranslatef(-w +  85, -h +  97, 0.0);
                    glBegin(GL_TRIANGLE_FAN);
                        for (int i = 1; i <= qtdTriangulos; i++) {
                            glVertex2f(30*cos(i*angulo) - 25*sin(i*angulo), 30*sin(i*angulo) + 25*cos(i*angulo));
                        }
                    glEnd();
                glPopMatrix();

                // Frontal (preta)
                glColor3f(0.0, 0.0, 0.0);
                glPushMatrix();
                    glTranslatef(-w + 245, -h +  97, 0.0);
                    glBegin(GL_TRIANGLE_FAN);
                        for (int i = 1; i <= qtdTriangulos; i++) {
                            glVertex2f(30*cos(i*angulo) - 25*sin(i*angulo), 30*sin(i*angulo) + 25*cos(i*angulo));
                        }
                    glEnd();
                glPopMatrix();

            // Locomotiva
                // Traseira (preta)
                glColor3f(0.0, 0.0, 0.0);
                glPushMatrix();
                    glTranslatef(-w + 390, -h + 119, 0.0);
                    glBegin(GL_TRIANGLE_FAN);
                        for (int i = 1; i <= qtdTriangulos; i++) {
                            glVertex2f(50*cos(i*angulo) - 35*sin(i*angulo), 50*sin(i*angulo) + 35*cos(i*angulo));
                        }
                    glEnd();
                glPopMatrix();

                // Calota (amarela)
                glColor3f(1.0, 1.0, 0.0);
                glPushMatrix();
                    glTranslatef(-w + 390.5, -h + 118, 0.0);
                    glBegin(GL_TRIANGLE_FAN);
                        for (int i = 1; i <= qtdTriangulos; i++) {
                            glVertex2f(25*cos(i*angulo) - 30*sin(i*angulo), 25*sin(i*angulo) + 30*cos(i*angulo));
                        }
                    glEnd();
                glPopMatrix();

                // Frontal (preta)
                glColor3f(0.0, 0.0, 0.0);
                glPushMatrix();
                    glTranslatef(-w + 530, -h +  97, 0.0);
                    glBegin(GL_TRIANGLE_FAN);
                        for (int i = 1; i <= qtdTriangulos; i++) {
                            glVertex2f(30*cos(i*angulo) - 25*sin(i*angulo), 30*sin(i*angulo) + 25*cos(i*angulo));
                        }
                    glEnd();
                glPopMatrix();

    glFlush();
}
