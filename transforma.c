//Desenvolvido por Andressa Sias
//Desenvolvido em Linux Ubuntu

        #include <GL/glut.h>

           GLint tx=0, ty=0, angulo=0;
           GLfloat ex=1,ey=1;
            void DesenhaQuadrado(int xi, int yi, int xs, int ys) 
                { 
                glClear(GL_COLOR_BUFFER_BIT); 
                glColor3f(0.8f, 0.3f, 0.5f); // rosa
                glRectf(xi, yi, xs, ys);
                glEnd();
            }

            void DesenhaTriangulo(int xt, int yt, int xt1, int yt1, int cumex, int cumey){
                glBegin(GL_TRIANGLES);
                glColor3f(0.0f, 0.8f, 0.5f); // verde
                glVertex2f(xt, yt);
                glVertex2f(cumex, cumey);
                glVertex2f(xt1, yt1);
                    
                glEnd();
            }
            void DesenhaPoligono(){
                glBegin(GL_POLYGON);
                glColor3f(0.9f, 0.9f, 0.0f);//amarelo
                glVertex2f(600, 50);
                glVertex2f(500, 175);
                glVertex2f(600, 300);
                glVertex2f(700, 300);
                glVertex2f(800, 175);
                glVertex2f(700, 50);
                glEnd();
                
            }
                
            void DesenhaCoracao(){
                glBegin(GL_POLYGON);
                glColor3f(0.7f, 0.3f, 0.9f);//roxo
                glVertex2f(400, 200);
                glVertex2f(300, 300);
                glVertex2f(325, 400);
                glVertex2f(375, 400);
                glVertex2f(400, 350);
                glVertex2f(425 , 400);
                glVertex2f(475, 400);
                glVertex2f(500, 300);
                glEnd();
            }

           //Chamada para desenhar
           void RenderScene(void)
           {
                //variáveis do quadrado
                int xi=50, yi=50, xs=200, ys=200;
                //variáveis do triangulo
                int cumex=150, cumey=600, xt=50, yt=450, xt1=250, yt1=450;

				glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glClear(GL_COLOR_BUFFER_BIT);
                glColor3f(1.0f, 1.0f, 1.0f);

                glPushMatrix( );
                angulo=90;
                //Translação do quadrado
                glTranslatef(tx+200, ty+300, 0);
                DesenhaQuadrado(xi-50,yi-50,xs-50,ys-50);

                //desenha coração
                DesenhaCoracao();

                //escala do triangulo
                glScalef(ex-0.5,ey-0.5,1);
                DesenhaTriangulo(xt-50, yt-50, xt1-50, yt1-50, cumex-50, cumey-50);
                    
                //rotação do poligono
                glRotatef(angulo, 0, 0, 1);
                DesenhaPoligono();
	            glPopMatrix( );

                glFlush();
           }

           void SetupRC(void)
           {
               glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
           }
           void ChangeSize(GLsizei w, GLsizei h)
           {
                   if(h == 0)
                           h = 1;
                           
                   glViewport(0, 0, w, h);

                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                  
                   gluOrtho2D (0, 1000, 0, 900);
                   glMatrixMode(GL_MODELVIEW);
                   glLoadIdentity();
           }

           int main(int argc, char** argv) 
           {
                    glutInit(&argc,argv); 
                   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
                   glutInitWindowSize(450,500);
                   glutInitWindowPosition(10,10);
                   glutCreateWindow("Transformacoes Computaco Grafica");
                   glutDisplayFunc(RenderScene);
                   glutReshapeFunc(ChangeSize);
                   SetupRC();
                   glutMainLoop();
           }
