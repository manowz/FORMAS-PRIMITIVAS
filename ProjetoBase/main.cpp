#include <windows.h>
#include <gl.h>
#include <glu.h>
#include <glut.h>

//VARIAVEIS GLOBAIS
int win, seletor = 0;
int retornomenu, submenu1, submenu2;

void display(void){

glClear(GL_COLOR_BUFFER_BIT); //LIMPA A TELA A CADA REDESENHO

    if (seletor == 1){

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

    }else

    // QUADRADO
    if (seletor == 5){
        glBegin(GL_QUADS);
            glVertex2f(-0.5, -0.5);
            glVertex2f(-0.5, 0.5);
            glVertex2f(0.5, 0.5);
            glVertex2f(0.5, -0.5);
        glEnd();
    }else
    // TRIANGULO
    if (seletor == 6){
        glBegin(GL_TRIANGLES);
            glVertex2f(-0.5, -0.5);
            glVertex2f(0, 0.5);
            glVertex2f(0.5, -0.5);
        glEnd();
    }else
    // RETANGULO
    if (seletor == 7){
        glBegin(GL_QUADS);
            glVertex2f(-0.8, -0.5);
            glVertex2f(-0.8, 0.5);
            glVertex2f(0.8, 0.5);
            glVertex2f(0.8, -0.5);
        glEnd();
    }else
    //LOZANGO
    if (seletor == 8){
        glBegin(GL_TRIANGLE_STRIP);
            glVertex2f(0, 0.5);
            glVertex2f(-1, 0);
            glVertex2f(1, 0);
            glVertex2f(0, -0.5);
        glEnd();
    }else
    //PENTAGONO
    if (seletor == 9){
        glBegin(GL_POLYGON);
            glVertex2f(-0.5, 0.1);
            glVertex2f(0, 0.5);
            glVertex2f(0.5, 0.1);
            glVertex2f(0.3, -0.5);
            glVertex2f(-0.3, -0.5);
        glEnd();
    }
    if (seletor == 10){
        glBegin(GL_POLYGON);
            glVertex2f(-0.5,0);
            glVertex2f(-0.3, 0.5);
            glVertex2f(0.3, 0.5);
            glVertex2f(0.5, 0);
            glVertex2f(0.3, -0.5);
            glVertex2f(-0.3, -0.5);
        glEnd();
    }
    //COMPOSTA

    // CIRCULO
    if (seletor == 20){
                                                                //FALTA O CIRCULO
    }

    glutSwapBuffers();
}

//inicializador do menu
void menu(int n){
    if (n == 0){
        glutDestroyWindow(win);
        exit(0);
    } else {
        seletor = n;
    }
        glutPostRedisplay();
}

void createMenu(void){

        submenu1 = glutCreateMenu(menu);
        glutAddMenuEntry("QUADRADO", 5);// OK
        glutAddMenuEntry("TRIANGULO", 6); // OK
        glutAddMenuEntry("RETANGULO", 7); // OK
        glutAddMenuEntry("LOZANGO", 8); // OK
        glutAddMenuEntry("PENTAGONO", 9); // OK
        glutAddMenuEntry("HEXAGONO", 10); // OK



        submenu2 = glutCreateMenu(menu);
        glutAddMenuEntry("CIRCULO", 20); // AINDA NAO IMPLEMENTADO

        retornomenu = glutCreateMenu(menu); //POR SER UMA FUN플O VOID, ESSE VALOR IR� INFORMAR O QUE FOI SELECIONADO NO MENU

        glutAddSubMenu("PRIMITIVAS", submenu1); // PRIMITIVAS SIMPLES
        glutAddSubMenu("PRIMITIVAS COMPOSTAS", submenu2); // PRIMITIVAS COMPOSTAS
        glutAddMenuEntry("LIMPAR", 1); // LIMPA TELA
        glutAddMenuEntry("SAIR", 0); // SAI DO MENU

        glutAttachMenu(GLUT_RIGHT_BUTTON); //INVOCA O MENU COM O BOT홒 DIREITO
        glutAttachMenu(GLUT_LEFT_BUTTON); // E COM O ESQUERDO
}

int main(int argc, char **argv){

        glutInit(&argc, argv);        //INICIALIZA
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);        //PROPRIEDADES DO DESENHO
        glutInitWindowSize(600, 600);        //TAMANHO DA TELA
        glutInitWindowPosition(450, 200);        //POSI플O DA TELA QUE A JANELA SER� ABERTA
        win = glutCreateWindow("FORMAS PRIMITIVAS"); // NOME DA JANELA
        createMenu(); // CHAMADA DA FUN플O DE CRIA플O DO MENU
        glClearColor(0.0, 0.0, 0.0, 0.0); // LIMPA CORES
        glutDisplayFunc(display); // CHAMA FUN플O DESENHO
        glutMainLoop();

return 1;
}
