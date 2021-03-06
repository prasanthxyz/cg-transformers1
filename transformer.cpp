#include "transformer.hpp"
#include <iostream>
using namespace std;
void displayWorld();

Transformer::Transformer()
{
    camFlag = false;
    cam2Flag = false;
    hdLights = false;
    GLfloat dirn[] = {1,0,0};
    hdL1 = Light(GL_LIGHT3, 0,0,0, true);
    hdL2 = Light(GL_LIGHT4, 0,0,0, true);

    flag = 0;
    hd1=0;
    hd2=0;

    fullx=0;
    fully=0;
    fullz=0;
    bend=0;
    walkflag=1;
    headside=0;
    headforward=0;
    headcurve=0;

    rshoulderside=-135;
    rshoulderforward=0;
    rshouldercurve=0;
    relbow=90;
    rfootrot=0.0;
    lshoulderside=-45;
    lshoulderforward=0;
    lshouldercurve=0;
    lelbow=-90;
    lfootrot=0.0;

    rltside=-90;
    rltforward=0;
    rltcurve=0;
    rlbforward=0;
    lltside=-90;
    lltforward=0;
    lltcurve=0;
    llbforward=0;

    move=0.0;
    backtyretrans=0.0;
    fronttyretrans=0.0;
    lftyreshift=0.0;
    rftyreshift=0.0;
    vehicleback=0;
    carback=0;
    down=0.0;

    carfront=0.0;
    carfrontshift=0.0;
    carfrontinsert=0.0;

    car_x=0.0;
    car_y=-5.0;
    car_z=0.0;
    wheelrot=0;
    wheelturn=0;

    list_left_shoulder();
    list_left_arm();
    list_left_elbow();
    list_left_forearm();
    list_left_palm();
    list_right_shoulder();
    list_right_arm();
    list_right_elbow();
    list_right_forearm();
    list_right_palm();
    list_hip();
    list_torso();
    list_head();
    list_back();
    list_neck();

    list_left_butt();
    list_left_thigh();
    list_left_knee();
    list_left_calf();
    list_left_foot();
    list_right_butt();
    list_right_thigh();
    list_right_knee();
    list_right_calf();
    list_right_foot();

}

void Transformer::rotateX(int angle)
{
    fullx = (fullx + angle) % 360;
}
void Transformer::rotateY(int angle)
{
    fully = (fully + angle) % 360;
}
void Transformer::rotateZ(int angle)
{
    fullz = (fullz + angle) % 360;
}


void Transformer::tiltHeadSide(int angle)
{
    headside = (headside + angle) % 360;
}
void Transformer::tiltHeadFB(int angle)
{
    headforward = (headforward + angle) % 360;
}
void Transformer::turnHead(int angle)
{
    headcurve = (headcurve + angle) % 360;
}

void Transformer::bendForward(int angle)
{
    bend = (bend + angle) % 360;
}
void Transformer::bendBack(int angle)
{
    bend = (bend + angle) % 360;
}


void Transformer::rShoulderSide(int angle)
{
    rshoulderside = (rshoulderside + angle) % 360;
}
void Transformer::rShoulderFB(int angle)
{
    rshoulderforward = (rshoulderforward + angle) % 360;
}
void Transformer::rShoulderCurve(int angle)
{
    rshouldercurve = (rshouldercurve + angle) % 360;
}
void Transformer::rElbowBend(int angle)
{
    relbow = (relbow + angle) % 360;
}

void Transformer::lShoulderSide(int angle)
{
    lshoulderside = (lshoulderside + angle) % 360;
}
void Transformer::lShoulderFB(int angle)
{
    lshoulderforward = (lshoulderforward + angle) % 360;
}
void Transformer::lShoulderCurve(int angle)
{
    lshouldercurve = (lshouldercurve + angle) % 360;
}
void Transformer::lElbowBend(int angle)
{
    lelbow = (lelbow + angle) % 360;
}

void Transformer::rLegSide(int angle)
{
    rltside = (rltside + angle) % 360;
}
void Transformer::rLegFB(int angle)
{
    rltforward = (rltforward + angle) % 360;
}
void Transformer::rLegCurve(int angle)
{
    rltcurve = (rltcurve + angle) % 360;
}
void Transformer::rCalfFB(int angle)
{
    rlbforward = (rlbforward + angle) % 360;
}

void Transformer::lLegSide(int angle)
{
    lltside = (lltside + angle) % 360;
}
void Transformer::lLegFB(int angle)
{
    lltforward = (lltforward + angle) % 360;
}
void Transformer::lLegCurve(int angle)
{
    lltcurve = (lltcurve + angle) % 360;
}
void Transformer::lCalfFB(int angle)
{
    llbforward = (llbforward + angle) % 360;
}

void Transformer::list_left_shoulder()
{
    extern Texture Tex;
    left_shoulder = glGenLists(1);
    glNewList(left_shoulder, GL_COMPILE);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.35,0.4,36,36,Tex.textures[Tex.TYRE],Tex.textures[Tex.TYRE],Tex.textures[Tex.TYRETEX]);
    glEndList();
}
void Transformer::list_left_arm()
{
    extern Texture Tex;
    left_arm=glGenLists(1);
    glNewList(left_arm,GL_COMPILE);

    glTranslatef (0.5, 0.0, 0.0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.3,1.2,36,36,Tex.textures[Tex.SPARETYRE],Tex.textures[Tex.SPARETYRE],Tex.textures[Tex.MILITARY]);

    glEndList();
}
void Transformer::list_left_elbow()
{
    left_elbow=glGenLists(1);
    glNewList(left_elbow,GL_COMPILE);
    glScalef(0.2,0.2,0.2);
    draw.drawSphere(36,36);
    glEndList();
}
void Transformer::list_left_forearm()
{
    extern Texture Tex;
    left_forearm = glGenLists(1);
    glNewList(left_forearm,GL_COMPILE);
    glTranslatef(0.65,0.0,0.0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.2,1.2,36,36,Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY]);
    glEndList();
}
void Transformer::list_left_palm()
{
    extern Texture Tex;
    left_palm = glGenLists(1);
    glNewList(left_palm,GL_COMPILE);
    glTranslatef(1.5,0.0,0.0);
    glScalef(0.6,0.5,0.2);
    draw.drawCube(Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY]);
    glEndList();
}



void Transformer::list_right_elbow()
{
    right_elbow = glGenLists(1);
    glNewList(right_elbow, GL_COMPILE);
    glScalef(0.2,0.2,0.2);
    draw.drawSphere(36,36);
    glEndList();
}
void Transformer::list_right_shoulder()
{
    extern Texture Tex;
    right_shoulder = glGenLists(1);
    glNewList(right_shoulder, GL_COMPILE);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.35,0.4,36,36,Tex.textures[Tex.TYRE],Tex.textures[Tex.TYRE],Tex.textures[Tex.TYRETEX]);
    glEndList();
}
void Transformer::list_right_arm()
{
    extern Texture Tex;
    right_arm = glGenLists(1);
    glNewList(right_arm, GL_COMPILE);
    glTranslatef (0.5, 0.0, 0.0);
    glRotatef(90.0f, 0.0f,1.0f, 0.0f);
    draw.drawCylinder(0.3,1.2,36,36,Tex.textures[Tex.SPARETYRE],Tex.textures[Tex.SPARETYRE],Tex.textures[Tex.MILITARY]);
    glEndList();
}
void Transformer::list_right_forearm()
{
    extern Texture Tex;
    right_forearm = glGenLists(1);
    glNewList(right_forearm, GL_COMPILE);
    glTranslatef(0.65,0.0,0.0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.2,1.2,36,36,Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY]);
    glEndList();
}
void Transformer::list_right_palm()
{
    extern Texture Tex;
    right_palm = glGenLists(1);
    glNewList(right_palm,GL_COMPILE);
    glTranslatef(1.5,0.0,0.0);
    glScalef(0.6,0.5,0.2);
    draw.drawCube(Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY]);
    glEndList();
}

void Transformer::list_hip()
{
    extern Texture Tex;
    hip = glGenLists(1);
    glNewList(hip, GL_COMPILE);
    glTranslatef(0.0,-1.1,0.0);
    glScalef(1.6,0.3,1.25);
    draw.drawCube(Tex.textures[Tex.MILITARY],Tex.textures[Tex.FRONTPANE],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.HIPRSIDE],Tex.textures[Tex.HIPLSIDE]);
    glEndList();
}
void Transformer::list_torso()
{
    extern Texture Tex;
    torso = glGenLists(1);
    glNewList(torso, GL_COMPILE);
    glScalef(1.6,2.0,1.25);
    draw.drawCube(Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.MILITARY],Tex.textures[Tex.RSIDE],Tex.textures[Tex.LSIDE]);
    glEndList();
}

void Transformer::list_head()
{
    extern Texture Tex;
    head = glGenLists(1);
    glNewList(head, GL_COMPILE);
    draw.drawCube(Tex.textures[Tex.MILITARY],Tex.textures[Tex.VEHBACK],Tex.textures[Tex.MILITARY],Tex.textures[Tex.HDFRONT],Tex.textures[Tex.FACELEFT], Tex.textures[Tex.FACERIGHT]);
    glEndList();
}

void Transformer::list_back()
{
    extern Texture Tex;
    back = glGenLists(1);
    glNewList(back,GL_COMPILE);
    draw.drawCube(Tex.textures[Tex.MILITARY],Tex.textures[Tex.VEHBACK],Tex.textures[Tex.MILITARY],Tex.textures[Tex.HDFRONT],Tex.textures[Tex.BACKLEFT], Tex.textures[Tex.BACKRIGHT]);
    glEndList();
}

void Transformer::list_neck()
{
    neck = glGenLists(1);
    glNewList(neck, GL_COMPILE);
    glTranslatef (0.0, 1.15, 0.0);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    draw.drawCylinder(0.35,0.3,36,36);
    glEndList();
}

void Transformer::list_right_butt()
{
    extern Texture Tex;
    right_butt = glGenLists(1);
    glNewList(right_butt, GL_COMPILE);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    draw.drawCylinder(0.35,0.6,36,36, Tex.textures[Tex.TYRE],Tex.textures[Tex.TYRE],Tex.textures[Tex.TYRETEX]);
    glEndList();
}
void Transformer::list_right_thigh()
{
    extern Texture Tex;
    right_thigh = glGenLists(1);
    glNewList(right_thigh, GL_COMPILE);
    glTranslatef(0.6,0.0,0.0);
    glRotatef(90.0f, 0.0f,1.0f, 0.0f);
    glScalef(0.6,0.6,1.0);
    draw.drawCube(Tex.textures[Tex.FRONTRIGHT],Tex.textures[Tex.FRONTRIGHT],Tex.textures[Tex.FRONTRIGHT],Tex.textures[Tex.LIGHTFRONT],Tex.textures[Tex.BONNETRIGHT],Tex.textures[Tex.FRONTRIGHT]);
    glEndList();
}
void Transformer::list_right_knee()
{
    right_knee = glGenLists(1);
    glNewList(right_knee, GL_COMPILE);
    glScalef(0.3,0.3,0.3);
    draw.drawSphere(36,36);
    glEndList();
}
void Transformer::list_right_calf()
{
    extern Texture Tex;
    right_calf = glGenLists(1);
    glNewList(right_calf, GL_COMPILE);
    glTranslatef(0.65,0.0,0.0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.3,1.2,36,36,Tex.textures[Tex.GRILL],Tex.textures[Tex.GRILL],Tex.textures[Tex.BONNETMID]);
    glEndList();
}
void Transformer::list_right_foot()
{
    extern Texture Tex;
    right_foot = glGenLists(1);
    glNewList(right_foot, GL_COMPILE);
    glTranslatef(1.3,0.0,0.2);
    glScalef(0.2,0.6,0.8);
    draw.drawCube(Tex.textures[Tex.RFOOT],Tex.textures[Tex.RFOOT],Tex.textures[Tex.RFOOT],Tex.textures[Tex.RFOOT],Tex.textures[Tex.RFOOT],Tex.textures[Tex.RFOOT]);
    glEndList();
}

void Transformer::list_left_butt()
{
    extern Texture Tex;
    left_butt = glGenLists(1);
    glNewList(left_butt, GL_COMPILE);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    draw.drawCylinder(0.35,0.6,36,36,Tex.textures[Tex.TYRE],Tex.textures[Tex.TYRE],Tex.textures[Tex.TYRETEX]);
    glEndList();
}
void Transformer::list_left_thigh()
{
    extern Texture Tex;
    left_thigh = glGenLists(1);
    glNewList(left_thigh, GL_COMPILE);
    glTranslatef(0.6,0.0,0.0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.6,0.6,1.0);
    draw.drawCube(Tex.textures[Tex.FRONTLEFT],Tex.textures[Tex.FRONTLEFT],Tex.textures[Tex.FRONTLEFT],Tex.textures[Tex.LIGHTFRONT],Tex.textures[Tex.BONNETLEFT],Tex.textures[Tex.FRONTRIGHT]);
    glEndList();
}
void Transformer::list_left_knee()
{
    left_knee = glGenLists(1);
    glNewList(left_knee, GL_COMPILE);
    glScalef(0.3,0.3,0.3);
    draw.drawSphere(36,36);
    glEndList();
}
void Transformer::list_left_calf()
{
    extern Texture Tex;
    left_calf = glGenLists(1);
    glNewList(left_calf, GL_COMPILE);
    glTranslatef(0.65,0.0,0.0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.3,1.2,36,36,Tex.textures[Tex.GRILL],Tex.textures[Tex.GRILL],Tex.textures[Tex.BONNETMID]);
    glEndList();
}
void Transformer::list_left_foot()
{
    extern Texture Tex;
    left_foot = glGenLists(1);
    glNewList(left_foot, GL_COMPILE);
    glTranslatef(1.3,0.0,0.2);
    glScalef(0.2,0.6,0.8);
    draw.drawCube(Tex.textures[Tex.LFOOT],Tex.textures[Tex.LFOOT],Tex.textures[Tex.LFOOT],Tex.textures[Tex.LFOOT],Tex.textures[Tex.LFOOT],Tex.textures[Tex.LFOOT]);
    glEndList();
}

void Transformer::tocar()
{
    while(1)
    {
        if(rftyreshift<=-0.25&&lftyreshift>=0.25&&down<=-0.9&&carfront<=-0.3&&carfrontshift>=0.5&&carfrontinsert<=-0.3&&rfootrot==-90&&lfootrot==90&&fronttyretrans<=-0.7&&backtyretrans<=-0.7&&fullx==-90&&fully==0&&fullz==90&&bend==0&&headside==0&&headforward==0&&headcurve==0&&rshoulderside==0&&rshoulderforward==0&&rshouldercurve==0&&relbow==-90&&lshoulderside==-180&&lshoulderforward==0&&lshouldercurve==0&&lelbow==90&&rltside==-90&&rltforward==0&&rltcurve==0&&rlbforward==180&&lltside==-90&&lltforward==0&&lltcurve==0&&llbforward==180&&vehicleback==90&&carback==90)
        {
            move=-0.5;
            backtyretrans=-0.7;
            fronttyretrans=-0.7;
            lftyreshift=0.25;
            rftyreshift=-0.25;
            down=-0.9;
            car_y=-5.0;
            carfront=-0.3;
            carfrontshift=0.5;
            carfrontinsert=-0.3;
            walkflag=0;
            flag = 1;


            break;
        }
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        transform();
        GLFWwindow * win=glfwGetCurrentContext();

        displayWorld();
        glfwSwapBuffers(win);
        usleep(5000);
    }


}

void Transformer::tohuman()
{
    while(1)
    {
        if(lftyreshift<=0.025&&rftyreshift>=-0.025&&down>=-0.05&&carfront>=-0.05&&carfrontshift<=0.05&&carfrontinsert>=-0.05&&rfootrot==0.0&&lfootrot==0.0&&fronttyretrans>=-0.5&&backtyretrans>=-0.5&&fullx==0&&fully==0&&fullz==0&&bend==0&&headside==0&&headforward==0&&headcurve==0&&rshoulderside==-135&&rshoulderforward==0&&rshouldercurve==0&&relbow==90&&lshoulderside==-45&&lshoulderforward==0&&lshouldercurve==0&&lelbow==-90&&rltside==-90&&rltforward==0&&rltcurve==0&&rlbforward==0&&lltside==-90&&lltforward==0&&lltcurve==0&&llbforward==0&&vehicleback==0&&carback==0)
        {
            move=0.0;
            backtyretrans=0.0;
            fronttyretrans=0.0;
            lftyreshift=0.0;
            rftyreshift=0.0;
            down=0.0;
            car_y=-5.0;
            carfront=0.0;
            carfrontshift=0.0;
            carfrontinsert=0.0;
            walkflag=1;
            flag = 0;

            break;
        }
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        transform();
        GLFWwindow * win=glfwGetCurrentContext();
        displayWorld();
        glfwSwapBuffers(win);
        usleep(5000);

    }

}

void Transformer::transform()
{
    if(flag==0)
    {
        wheelturn=0;
        if(bend>0)
        {
            bend=(bend-5)%360;
            return;
        }
        else if(bend<0)
        {
            bend=(bend+5)%360;
            return;
        }
        if(headside>0)
        {
            headside=(headside-5)%360;

            return;
        }
        else if(headside<0)
        {
            headside=(headside+5)%360;
            return;
        }
        if(headforward>0)
        {
            headforward=(headforward-5)%360;

            return;
        }
        else if(headforward<0)
        {
            headforward=(headforward+5)%360;
            return;
        }
        if(headcurve>0)
        {
            headcurve=(headcurve-5)%360;

            return;
        }
        else if(headcurve<0)
        {
            headcurve=(headcurve+5)%360;
            return;
        }
        if(relbow>-90)
        {
            relbow=(relbow-5)%360;
        }
        else if(relbow<-90)
        {
            relbow=(relbow+5)%360;
        }
        if(lelbow>90)
        {
            lelbow=(lelbow-5)%360;

            return;
        }
        else if(lelbow<90)
        {
            lelbow=(lelbow+5)%360;
            return;
        }
        if(rshoulderside>0)
        {
            rshoulderside=(rshoulderside-5)%360;
        }
        else if(rshoulderside<0)
        {
            rshoulderside=(rshoulderside+5)%360;
        }
        if(lshoulderside>-180)
        {
            lshoulderside=(lshoulderside-5)%360;

            return;
        }
        else if(lshoulderside<-180)
        {
            lshoulderside=(lshoulderside+5)%360;
            return;
        }
        if(rshoulderforward>0)
        {
            rshoulderforward=(rshoulderforward-5)%360;
        }
        else if(rshoulderforward<0)
        {
            rshoulderforward=(rshoulderforward+5)%360;
        }
        if(lshoulderforward>0)
        {
            lshoulderforward=(lshoulderforward-5)%360;

            return;
        }
        else if(lshoulderforward<0)
        {
            lshoulderforward=(lshoulderforward+5)%360;
            return;
        }
        if(rshouldercurve>0)
        {
            rshouldercurve=(rshouldercurve-5)%360;
        }
        else if(rshouldercurve<0)
        {
            rshouldercurve=(rshouldercurve+5)%360;
        }
        if(lshouldercurve>0)
        {
            lshouldercurve=(lshouldercurve-5)%360;

            return;
        }
        else if(lshouldercurve<0)
        {
            lshouldercurve=(lshouldercurve+5)%360;
            return;
        }
        if(down>-0.9)
        {
            down=down-0.1;
            return;
        }
        if(rlbforward>180)
        {
            rlbforward=(rlbforward-5)%360;
        }
        else if(rlbforward<180)
        {
            rlbforward=(rlbforward+5)%360;
        }
        if(llbforward>180)
        {
            llbforward=(llbforward-5)%360;

            return;
        }
        else if(llbforward<180)
        {
            llbforward=(llbforward+5)%360;
            return;
        }
        if(rltside>-90)
        {
            rltside=(rltside-5)%360;
        }
        else if(rltside<-90)
        {
            rltside=(rltside+5)%360;
        }
        if(lltside>-90)
        {
            lltside=(lltside-5)%360;

            return;
        }
        else if(lltside<-90)
        {
            lltside=(lltside+5)%360;
            return;
        }
        if(rltforward>0)
        {
            rltforward=(rltforward-5)%360;
        }
        else if(rltforward<0)
        {
            rltforward=(rltforward+5)%360;
        }

        if(lltforward>0)
        {
            lltforward=(lltforward-5)%360;

            return;
        }
        else if(lltforward<0)
        {
            lltforward=(lltforward+5)%360;
            return;
        }
        if(rltcurve>0)
        {
            rltcurve=(rltcurve-5)%360;
        }
        else if(rltcurve<0)
        {
            rltcurve=(rltcurve+5)%360;
        }
        if(lltcurve>0)
        {
            lltcurve=(lltcurve-5)%360;

            return;
        }
        else if(lltcurve<0)
        {
            lltcurve=(lltcurve+5)%360;
            return;
        }
        move=-0.5;
        if(vehicleback>90)
        {
            vehicleback=(vehicleback-5)%360;

            return;
        }
        else if(vehicleback<90)
        {
            vehicleback=(vehicleback+5)%360;
            return;
        }
        if(rftyreshift>-0.25)
        {
            rftyreshift=rftyreshift-0.05;
        }

        if(lftyreshift<0.25)
        {
            lftyreshift=lftyreshift+0.05;
            return;
        }
        if(fullz>90)
        {
            fullz=(fullz-5)%360;
            return;
        }
        else if(fullz<90)
        {
            fullz=(fullz+5)%360;
            return;
        }

        if(fullx>-90)
        {

            fullx=(fullx-5)%360;
            return;
        }
        else if(fullx<-90)
        {
            fullx=(fullx+5)%360;
            return;
        }
        if(fully>0)
        {
            fully=(fully-5)%360;

            return;
        }
        else if(fully<0)
        {
            fully=(fully+5)%360;
            return;
        }

        if(fronttyretrans>-0.7)
        {
            fronttyretrans=fronttyretrans-0.1;
        }
        if(backtyretrans>-0.7)
        {
            backtyretrans=backtyretrans-0.1;
            return;
        }
        if(carback>90)
        {
            carback=(carback-5)%360;

            return;
        }
        else if(carback<90)
        {
            carback=(carback+5)%360;
            return;
        }
        if(rfootrot>-90)
        {
            rfootrot=(rfootrot-5)%360;

            return;
        }
        else if(rfootrot<-90)
        {
            rfootrot=(rfootrot+5)%360;
            return;
        }
        if(lfootrot>90)
        {
            lfootrot=(lfootrot-5)%360;

            return;
        }
        else if(lfootrot<90)
        {
            lfootrot=(lfootrot+5)%360;
            return;
        }
        if(carfront>-0.3)
        {
            carfront=carfront-0.1;
            return;

        }
        if(carfrontshift<0.5)
        {
            carfrontshift=carfrontshift+0.1;
            return;
        }
        if(carfrontinsert>-0.3)
        {
            carfrontinsert=carfrontinsert-0.1;
            return;
        }

    }
    else
    {
        wheelturn=0;
        if(carfrontinsert<-0.05)
        {
            carfrontinsert=carfrontinsert+0.1;
            return;
        }
        if(carfrontshift>0.05)
        {
            carfrontshift=carfrontshift-0.1;
            return;
        }

        if(carfront<-0.05)
        {
            carfront=carfront+0.1;
            return;

        }
        if(lfootrot>0)
        {
            lfootrot=(lfootrot-5)%360;

            return;
        }
        else if(lfootrot<0)
        {
            lfootrot=(lfootrot+5)%360;
            return;
        }


        if(rfootrot>0)
        {
            rfootrot=(rfootrot-5)%360;

            return;
        }
        else if(rfootrot<0)
        {
            rfootrot=(rfootrot+5)%360;
            return;
        }

        if(carback>0)
        {
            carback=(carback-5)%360;

            return;
        }
        else if(carback<0)
        {
            carback=(carback+5)%360;
            return;
        }


        if(backtyretrans<-0.05)
        {
            backtyretrans=backtyretrans+0.1;
        }
        if(fronttyretrans<-0.05)
        {
            fronttyretrans=fronttyretrans+0.1;
            return;
        }
        if(fullz>0)
        {
            fullz=(fullz-5)%360;

            return;
        }
        else if(fullz<0)
        {
            fullz=(fullz+5)%360;
            return;
        }
        if(fullx>0)
        {
            fullx=(fullx-5)%360;
            return;
        }
        else if(fullx<0)
        {
            fullx=(fullx+5)%360;
            return;
        }
        if(fully>0)
        {
            fully=(fully-5)%360;
            return;
        }
        else if(fully<0)
        {
            fully=(fully+5)%360;
            return;
        }
        if(lftyreshift>0.025)
        {
            lftyreshift=lftyreshift-0.05;
        }
        if(rftyreshift<-0.025)
        {
            rftyreshift=rftyreshift+0.05;
            return;
        }
        move=0.0;
        if(vehicleback>0)
        {
            vehicleback=(vehicleback-5)%360;
            return;
        }
        else if(vehicleback<0)
        {
            vehicleback=(vehicleback+5)%360;
            return;
        }

        if(lltcurve>0)
        {
            lltcurve=(lltcurve-5)%360;
        }
        else if(lltcurve<0)
        {
            lltcurve=(lltcurve+5)%360;
        }
        if(rltcurve>0)
        {
            rltcurve=(rltcurve-5)%360;

            return;
        }
        else if(rltcurve<0)
        {
            rltcurve=(rltcurve+5)%360;
            return;
        }
        if(lltforward>0)
        {
            lltforward=(lltforward-5)%360;
        }
        else if(lltforward<0)
        {
            lltforward=(lltforward+5)%360;
        }



        if(rltforward>0)
        {
            rltforward=(rltforward-5)%360;
            return;
        }
        else if(rltforward<0)
        {
            rltforward=(rltforward+5)%360;
            return;
        }
        if(lltside>-90)
        {
            lltside=(lltside-5)%360;
        }
        else if(lltside<-90)
        {
            lltside=(lltside+5)%360;
        }
        if(rltside>-90)
        {
            rltside=(rltside-5)%360;
            return;
        }
        else if(rltside<-90)
        {
            rltside=(rltside+5)%360;
            return;
        }
        if(llbforward>0)
        {
            llbforward=(llbforward-5)%360;
        }
        else if(llbforward<0)
        {
            llbforward=(llbforward+5)%360;
        }

        if(rlbforward>0)
        {
            rlbforward=(rlbforward-5)%360;
            return;
        }
        else if(rlbforward<0)
        {
            rlbforward=(rlbforward+5)%360;
            return;

        }

        if(down<-0.05)
        {
            down=down+0.1;
            return;
        }

        if(lshouldercurve>0)
        {
            lshouldercurve=(lshouldercurve-5)%360;
        }
        else if(lshouldercurve<0)
        {
            lshouldercurve=(lshouldercurve+5)%360;
        }


        if(rshouldercurve>0)
        {
            rshouldercurve=(rshouldercurve-5)%360;
            return;
        }
        else if(rshouldercurve<0)
        {
            rshouldercurve=(rshouldercurve+5)%360;
            return;
        }
        if(lshoulderforward>0)
        {
            lshoulderforward=(lshoulderforward-5)%360;
        }
        else if(lshoulderforward<0)
        {
            lshoulderforward=(lshoulderforward+5)%360;
        }
        if(rshoulderforward>0)
        {
            rshoulderforward=(rshoulderforward-5)%360;
            return;
        }
        else if(rshoulderforward<0)
        {
            rshoulderforward=(rshoulderforward+5)%360;
            return;
        }

        if(lshoulderside>-45)
        {
            lshoulderside=(lshoulderside-5)%360;
        }
        else if(lshoulderside<-45)
        {
            lshoulderside=(lshoulderside+5)%360;
        }
        if(rshoulderside>-135)
        {
            rshoulderside=(rshoulderside-5)%360;
            return;
        }
        else if(rshoulderside<-135)
        {
            rshoulderside=(rshoulderside+5)%360;
            return;
        }

        if(lelbow>-90)
        {
            lelbow=(lelbow-5)%360;
        }
        else if(lelbow<-90)
        {
            lelbow=(lelbow+5)%360;
        }


        if(relbow>90)
        {
            relbow=(relbow-5)%360;
            return;
        }
        else if(relbow<90)
        {
            relbow=(relbow+5)%360;
            return;
        }



        if(headcurve>0)
        {
            headcurve=(headcurve-5)%360;
            return;
        }
        else if(headcurve<0)
        {
            headcurve=(headcurve+5)%360;
            return;
        }

        if(headforward>0)
        {

            headforward=(headforward-5)%360;
            return;
        }
        else if(headforward<0)
        {
            headforward=(headforward+5)%360;
            return;
        }

        if(headside>0)
        {
            headside=(headside-5)%360;
            return;
        }
        else if(headside<0)
        {
            headside=(headside+5)%360;
            return;
        }

        if(bend>0)
        {
            bend=(bend-5)%360;
            return;
        }
        else if(bend<0)
        {
            bend=(bend+5)%360;
            return;
        }
    }
}

float Transformer::getFront(float *X, float *Y, float *Z, float adder, float theta)
{
    if(theta == 1000)
        theta = fully;
    theta = theta*M_PI/180;
    *X = car_x + adder*cos(theta);
    *Z = car_z - adder*sin(theta);
}

void Transformer::setLights()
{
    float hl1x, hl1y, hl1z;
    float hl2x, hl2y, hl2z;
    float hld1x, hld1y, hld1z;
    float hld2x, hld2y, hld2z;

    hl1y = -5;
    hl2y = -5;

    getFront(&hl1x,&hl1y,&hl1z, 2, fully+10);
    getFront(&hld1x,&hld1y,&hld1z, 4, fully+5);

    getFront(&hl2x,&hl2y,&hl2z, 2, fully-10);
    getFront(&hld2x,&hld2y,&hld2z, 4, fully-5);

    hdL1.setPos(hl1x, -5, hl1z);
    hdL1.setDirn(hld1x-hl1x, 0, hld1z-hl1z);

    hdL2.setPos(hl2x, -5, hl2z);
    hdL2.setDirn(hld2x-hl2x, 0, hld2z-hl2z);

}

