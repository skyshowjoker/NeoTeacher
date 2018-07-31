//
// Created by karl on 18-7-29.
//

#ifndef NEOTEACHERCLIENT_SYSTEMCONTROLLER_H
#define NEOTEACHERCLIENT_SYSTEMCONTROLLER_H

#include <linux/input.h>
#include <cstdint>
#include <vector>
#include <opencv/cv.hpp>
#include "Setting.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XShm.h>

#include <sys/ipc.h>
#include <sys/shm.h>

class SystemController {
public:
    struct ScreenShot {
        ScreenShot(uint x, uint y, uint width, uint height) :
                x(x), y(y), width(width), height(height) {

            display = XOpenDisplay(nullptr);
            root = DefaultRootWindow(display);

            XGetWindowAttributes(display, root, &window_attributes);
            screen = window_attributes.screen;
            ximg = XShmCreateImage(display, DefaultVisualOfScreen(screen), DefaultDepthOfScreen(screen), ZPixmap, NULL,
                                   &shminfo, width, height);

            shminfo.shmid = shmget(IPC_PRIVATE, ximg->bytes_per_line * ximg->height, IPC_CREAT | 0777);
            shminfo.shmaddr = ximg->data = (char *) shmat(shminfo.shmid, 0, 0);
            shminfo.readOnly = False;
            if (shminfo.shmid < 0)
                puts("Fatal shminfo error!");;
            Status s1 = XShmAttach(display, &shminfo);
            printf("XShmAttach() %s\n", s1 ? "success!" : "failure!");

            init = true;
        }

        void operator>>(cv::Mat **cv_img) {
            if (init)
                init = false;

            XShmGetImage(display, root, ximg, 0, 0, 0x00ffffff);
            *cv_img = new cv::Mat(height, width, CV_8UC4, ximg->data);
        }

        ~ScreenShot() {
            if (!init)
                XDestroyImage(ximg);

            XShmDetach(display, &shminfo);
            shmdt(shminfo.shmaddr);
            XCloseDisplay(display);
        }

        Display *display;
        Window root;
        XWindowAttributes window_attributes;
        Screen *screen;
        XImage *ximg;
        XShmSegmentInfo shminfo;

        int x, y, width, height;

        bool init;
    };

private:
    ScreenShot *screen;

    int fileDescriptor[2];

    void sync(int fd);

public:
    static const int MOUSE = 0;
    static const int KEYBOARD = 1;

    explicit SystemController(Setting *setting);

    void click(int device, uint16_t keyValue);

    void press(int device, uint16_t keyValue);

    void release(int device, uint16_t keyValue);

    void shutdown();

    void reboot();

    void XScreenInit(uint width, uint height);

    ScreenShot *getScreenShotStream();

    ~SystemController();
};


#endif //NEOTEACHERCLIENT_SYSTEMCONTROLLER_H
