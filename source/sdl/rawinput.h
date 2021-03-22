/*
    rawinput
    by Luka Aleksic

    The license is Zero-Clause BSD (0BSD), a public-domain-equivalent license.
    See bottom of file for full license text.
*/

#ifndef RAWINPUT_H
#define RAWINPUT_H
#ifdef __cplusplus
extern "C" {
#endif

typedef enum Raw_Axis {
    RA_UNKNOWN,

    RA_X,
    RA_Y,
    RA_WHEEL,

    RA_COUNT = 64 /* Enough space for axes added in future */
} Raw_Axis;

typedef enum Raw_Key {

    RK_UNKNOWN,

    /* Standard 3-button mouse */

    RK_LMB,
    RK_RMB,
    RK_MMB,

    /* ANSI standard keyboard - full form factor */

    RK_BACKSPACE,
    RK_TAB,
    RK_ENTER,
    RK_PAUSE,
    RK_CAPS_LOCK,
    RK_ESC,
    RK_SPACE,
    RK_PAGE_UP,
    RK_PAGE_DOWN,
    RK_END,
    RK_HOME,
    RK_LEFT,
    RK_UP,
    RK_RIGHT,
    RK_DOWN,
    RK_PRINT_SCR,
    RK_INSERT,
    RK_DELETE,
    RK_0,
    RK_1,
    RK_2,
    RK_3,
    RK_4,
    RK_5,
    RK_6,
    RK_7,
    RK_8,
    RK_9,
    RK_A,
    RK_B,
    RK_C,
    RK_D,
    RK_E,
    RK_F,
    RK_G,
    RK_H,
    RK_I,
    RK_J,
    RK_K,
    RK_L,
    RK_M,
    RK_N,
    RK_O,
    RK_P,
    RK_Q,
    RK_R,
    RK_S,
    RK_T,
    RK_U,
    RK_V,
    RK_W,
    RK_X,
    RK_Y,
    RK_Z,
    RK_NUMPAD_0,
    RK_NUMPAD_1,
    RK_NUMPAD_2,
    RK_NUMPAD_3,
    RK_NUMPAD_4,
    RK_NUMPAD_5,
    RK_NUMPAD_6,
    RK_NUMPAD_7,
    RK_NUMPAD_8,
    RK_NUMPAD_9,
    RK_NUMPAD_STAR,
    RK_NUMPAD_PLUS,
    RK_NUMPAD_MINUS,
    RK_NUMPAD_SLASH,
    RK_NUMPAD_DOT,
    RK_NUM_LOCK,
    RK_F1,
    RK_F2,
    RK_F3,
    RK_F4,
    RK_F5,
    RK_F6,
    RK_F7,
    RK_F8,
    RK_F9,
    RK_F10,
    RK_F11,
    RK_F12,
    RK_SCROLL_LOCK,
    RK_LSHIFT,
    RK_RSHIFT,
    RK_LCTRL,
    RK_RCTRL,
    RK_LALT,
    RK_RALT,
    RK_LWIN,
    RK_RWIN,
    RK_MENU,
    RK_COMMA,
    RK_DOT,
    RK_MINUS,
    RK_EQUALS,
    RK_SLASH,
    RK_BACKTICK,
    RK_LBRACKET,
    RK_RBRACKET,
    RK_BACKSLASH,
    RK_SEMICOLON,
    RK_QUOTE,

    RK_COUNT = 512  /* Enough space for virtual keys added in future */

} Raw_Key;

typedef void (*Raw_On_Key_Up)(void* tag, Raw_Key key, void *user_data);
typedef void (*Raw_On_Key_Down)(void* tag, Raw_Key key, void *user_data);
typedef void (*Raw_On_Rel)(void* tag, Raw_Axis axis, int delta, void *user_data);
typedef void (*Raw_On_Unplug)(void* tag, void *user_data);
typedef void (*Raw_On_Plug)(int idx, void *user_data);

void raw_init();
void raw_quit();

int  raw_dev_cnt();
void raw_open(int idx, void* tag);
void raw_close(void* tag);

void raw_poll();

const char* raw_key_str(Raw_Key key);
const char* raw_axis_str(Raw_Axis axis);

void raw_on_key_up(Raw_On_Key_Up on_key_up, void* user_data);
void raw_on_key_down(Raw_On_Key_Down on_key_down, void* user_data);
void raw_on_rel(Raw_On_Rel on_rel, void* user_data);
void raw_on_plug(Raw_On_Plug on_plug, void* user_data);
void raw_on_unplug(Raw_On_Unplug on_unplug, void* user_data);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* RAWINPUT_H */

#ifdef RAWINPUT_IMPL
const char* raw_axis_str(Raw_Axis axis) {
    switch (axis) {
    case RA_X: return "X";
    case RA_Y: return "Y";
    case RA_WHEEL: return "WHEEL";
    default: return "UNKNOWN";
    }
}

const char* raw_key_str(Raw_Key key) {

    switch (key) {
    case RK_LMB: return "LMB";
    case RK_RMB: return "RMB";
    case RK_MMB: return "MMB";
    case RK_BACKSPACE: return "BACKSPACE";
    case RK_TAB: return "TAB";
    case RK_ENTER: return "ENTER";
    case RK_PAUSE: return "PAUSE";
    case RK_CAPS_LOCK: return "CAPS_LOCK";
    case RK_ESC: return "ESC";
    case RK_SPACE: return "SPACE";
    case RK_PAGE_UP: return "PAGE_UP";
    case RK_PAGE_DOWN: return "PAGE_DOWN";
    case RK_END: return "END";
    case RK_HOME: return "HOME";
    case RK_LEFT: return "LEFT";
    case RK_UP: return "UP";
    case RK_RIGHT: return "RIGHT";
    case RK_DOWN: return "DOWN";
    case RK_PRINT_SCR: return "PRINT_SCR";
    case RK_INSERT: return "INSERT";
    case RK_DELETE: return "DELETE";
    case RK_0: return "0";
    case RK_1: return "1";
    case RK_2: return "2";
    case RK_3: return "3";
    case RK_4: return "4";
    case RK_5: return "5";
    case RK_6: return "6";
    case RK_7: return "7";
    case RK_8: return "8";
    case RK_9: return "9";
    case RK_A: return "A";
    case RK_B: return "B";
    case RK_C: return "C";
    case RK_D: return "D";
    case RK_E: return "E";
    case RK_F: return "F";
    case RK_G: return "G";
    case RK_H: return "H";
    case RK_I: return "I";
    case RK_J: return "J";
    case RK_K: return "K";
    case RK_L: return "L";
    case RK_M: return "M";
    case RK_N: return "N";
    case RK_O: return "O";
    case RK_P: return "P";
    case RK_Q: return "Q";
    case RK_R: return "R";
    case RK_S: return "S";
    case RK_T: return "T";
    case RK_U: return "U";
    case RK_V: return "V";
    case RK_W: return "W";
    case RK_X: return "X";
    case RK_Y: return "Y";
    case RK_Z: return "Z";
    case RK_NUMPAD_0: return "NUMPAD_0";
    case RK_NUMPAD_1: return "NUMPAD_1";
    case RK_NUMPAD_2: return "NUMPAD_2";
    case RK_NUMPAD_3: return "NUMPAD_3";
    case RK_NUMPAD_4: return "NUMPAD_4";
    case RK_NUMPAD_5: return "NUMPAD_5";
    case RK_NUMPAD_6: return "NUMPAD_6";
    case RK_NUMPAD_7: return "NUMPAD_7";
    case RK_NUMPAD_8: return "NUMPAD_8";
    case RK_NUMPAD_9: return "NUMPAD_9";
    case RK_NUMPAD_STAR: return "NUMPAD_STAR";
    case RK_NUMPAD_PLUS: return "NUMPAD_PLUS";
    case RK_NUMPAD_MINUS: return "NUMPAD_MINUS";
    case RK_NUMPAD_SLASH: return "NUMPAD_SLASH";
    case RK_NUMPAD_DOT: return "NUMPAD_DOT";
    case RK_NUM_LOCK: return "NUM_LOCK";
    case RK_F1: return "F1";
    case RK_F2: return "F2";
    case RK_F3: return "F3";
    case RK_F4: return "F4";
    case RK_F5: return "F5";
    case RK_F6: return "F6";
    case RK_F7: return "F7";
    case RK_F8: return "F8";
    case RK_F9: return "F9";
    case RK_F10: return "F10";
    case RK_F11: return "F11";
    case RK_F12: return "F12";
    case RK_SCROLL_LOCK: return "SCROLL_LOCK";
    case RK_LSHIFT: return "LSHIFT";
    case RK_RSHIFT: return "RSHIFT";
    case RK_LCTRL: return "LCTRL";
    case RK_RCTRL: return "RCTRL";
    case RK_LALT: return "LALT";
    case RK_RALT: return "RALT";
    case RK_LWIN: return "LWIN";
    case RK_RWIN: return "RWIN";
    case RK_MENU: return "MENU";
    case RK_COMMA: return "COMMA";
    case RK_DOT: return "DOT";
    case RK_MINUS: return "MINUS";
    case RK_EQUALS: return "EQUALS";
    case RK_SLASH: return "SLASH";
    case RK_BACKTICK: return "BACKTICK";
    case RK_LBRACKET: return "LBRACKET";
    case RK_RBRACKET: return "RBRACKET";
    case RK_BACKSLASH: return "BACKSLASH";
    case RK_SEMICOLON: return "SEMICOLON";
    case RK_QUOTE: return "QUOTE";
    default: return "UNKNOWN";
    }

}

#ifdef _WIN32
#   undef UNICODE
#   include <windows.h>
    typedef UINT u32;
    typedef SHORT i16;
    typedef ULONG u64;
    typedef USHORT u16;
#elif __linux__
#include <linux/limits.h>
#else
#   error "Unsupported platform."
#endif

#ifndef NDEBUG
#   include <stdio.h>
#   define dbg(...) fprintf(stderr, __VA_ARGS__);
#   ifdef _WIN32
#       include <debugapi.h>
#       define breakpoint() DebugBreak();
#   elif __linux__
#       include <signal.h>
#       define breakpoint() raise(SIGTRAP);
#   endif
#else
#   define dbg(...)
#   define breakpoint()
#endif

#ifndef __cplusplus
#include <stdbool.h>
#endif

static bool inited = false;


static Raw_On_Key_Up   on_key_up = 0;
static Raw_On_Key_Down on_key_down = 0;
static Raw_On_Rel      on_rel = 0;
static Raw_On_Plug     on_plug = 0;
static Raw_On_Unplug   on_unplug = 0;

static void* on_key_up_user_data;
static void* on_key_down_user_data;
static void* on_rel_user_data;
static void* on_plug_user_data;
static void* on_unplug_user_data;

static void emit_key_up(void* tag, Raw_Key key) {
    if (on_key_up) {
        on_key_up(tag, key, on_key_up_user_data);
    }
}

static void emit_key_down(void* tag, Raw_Key key) {
    if (on_key_down) {
        on_key_down(tag, key, on_key_down_user_data);
    }
}

static void emit_rel(void* tag, Raw_Axis axis, int delta) {
    if (on_rel) {
        on_rel(tag, axis, delta, on_rel_user_data);
    }
}

static void emit_plug(int idx) {
    if (on_plug) {
        on_plug(idx, on_plug_user_data);
    }
}

static void emit_unplug(void* tag) {
    if (on_unplug) {
        on_unplug(tag, on_unplug_user_data);
    }
}

void raw_on_key_up(Raw_On_Key_Up _on_key_up, void* user_data) {
    on_key_up = _on_key_up;
    on_key_up_user_data = user_data;
}

void raw_on_key_down(Raw_On_Key_Down _on_key_down, void* user_data) {
    on_key_down = _on_key_down;
    on_key_down_user_data = user_data;
}

void raw_on_rel(Raw_On_Rel _on_rel, void* user_data) {
    on_rel = _on_rel;
    on_rel_user_data = user_data;
}

void raw_on_plug(Raw_On_Plug _on_plug, void* user_data) {
    on_plug = _on_plug;
    on_plug_user_data = user_data;
}

void raw_on_unplug(Raw_On_Unplug _on_unplug, void* user_data) {
    on_unplug = _on_unplug;
    on_unplug_user_data = user_data;
}


typedef
struct Device {
#ifdef _WIN32
    RAWINPUTDEVICELIST ridl;
    /*
        NOTE: I'm not gonna bother with this, the info I get in RID_DEVICE_INFO
        was flat out wrong for most (all?) of my devices I tested it with...
    */
    /* RID_DEVICE_INFO info; */
#elif __linux__
    int handle; // The number * in /dev/input/event*
    int fd;
#endif

    bool is_open;
    void* tag;
} Device;

#define MAX_DEVICES 32
static Device devices[MAX_DEVICES];
static int device_count;

int raw_dev_cnt() {
    return device_count;
}

static void delete_device(int idx) {
    /* Swap & pop (quick unstable remove) */
    devices[idx] = devices[device_count-1];
    device_count--;
}

static int find_device_by_tag(void *tag) {
    int i;
    for (i=0; i<device_count; ++i) {
        Device *d = &devices[i];

        if (d->is_open && d->tag == tag) {
            return i;
        }
    }

    return -1;
}

void raw_open(int idx, void* tag) {
    Device *d;

    if (find_device_by_tag(tag) >= 0) {
        /* Tag already used */
        return;
    }

    if (idx < 0 || idx >= device_count) {
        /* Bad device index */
        return;
    }

    d = &devices[idx];
    if (d->is_open) {
        /* Device already open */
        return;
    }

    d->is_open = true;
    d->tag = tag;
}

void raw_close(void* tag) {
    int idx = find_device_by_tag(tag);
    if (idx >= 0) {
        devices[idx].is_open = false;
    }
}

#ifdef _WIN32
static HWND msg_window = NULL;

static int find_device_by_handle(HANDLE h) {
    int i;
    for (i=0; i<device_count; ++i) {
        Device *d = &devices[i];

        if (d->ridl.hDevice == h) {
            return i;
        }
    }

    return -1;
}

static int scan_devices(Device *devices) {
    /*
        NOTE: GetRawInputDeviceList will report some "extra" devices. I.e. when I have just a
        keyboard and mouse plugged in, it reports 2 mice and 2 keyboards for some reason...
        I guess it is detecting some other device as a keyboard; in any case
        these extra devices can be safely ignored.
    */

    RAWINPUTDEVICELIST ridls[MAX_DEVICES];
    u32 n;
    int i;

    if (0 != GetRawInputDeviceList(0, &n, sizeof(ridls[0]))) {
        return 0;
    }
    n = n>MAX_DEVICES? MAX_DEVICES: n;
    GetRawInputDeviceList(ridls, &n, sizeof(ridls[0]));

    for (i = 0; i < (int)n; ++i) {
        Device* d = &devices[i];

        d->ridl = ridls[i];
        d->is_open = false;
        d->tag = 0;
    }

    return n;
}

static Raw_Key translate_windows_vk(u16 vk) {

    switch (vk) {
        /* Standard 3-button mouse */

    case VK_LBUTTON: return RK_LMB;
    case VK_RBUTTON: return RK_RMB;
    case VK_MBUTTON: return RK_MMB;

        /* ANSI standard keyboard - full form factor */

    case VK_BACK: return RK_BACKSPACE;
    case VK_TAB: return RK_TAB;
    case VK_RETURN: return RK_ENTER;
    case VK_PAUSE: return RK_PAUSE;
    case VK_CAPITAL: return RK_CAPS_LOCK;
    case VK_ESCAPE: return RK_ESC;
    case VK_SPACE: return RK_SPACE;
    case VK_PRIOR: return RK_PAGE_UP;
    case VK_NEXT: return RK_PAGE_DOWN;
    case VK_END: return RK_END;
    case VK_HOME: return RK_HOME;
    case VK_LEFT: return RK_LEFT;
    case VK_UP: return RK_UP;
    case VK_RIGHT: return RK_RIGHT;
    case VK_DOWN: return RK_DOWN;
    case VK_SNAPSHOT: return RK_PRINT_SCR;
    case VK_INSERT: return RK_INSERT;
    case VK_DELETE: return RK_DELETE;
    case '0': return RK_0;
    case '1': return RK_1;
    case '2': return RK_2;
    case '3': return RK_3;
    case '4': return RK_4;
    case '5': return RK_5;
    case '6': return RK_6;
    case '7': return RK_7;
    case '8': return RK_8;
    case '9': return RK_9;
    case 'A': return RK_A;
    case 'B': return RK_B;
    case 'C': return RK_C;
    case 'D': return RK_D;
    case 'E': return RK_E;
    case 'F': return RK_F;
    case 'G': return RK_G;
    case 'H': return RK_H;
    case 'I': return RK_I;
    case 'J': return RK_J;
    case 'K': return RK_K;
    case 'L': return RK_L;
    case 'M': return RK_M;
    case 'N': return RK_N;
    case 'O': return RK_O;
    case 'P': return RK_P;
    case 'Q': return RK_Q;
    case 'R': return RK_R;
    case 'S': return RK_S;
    case 'T': return RK_T;
    case 'U': return RK_U;
    case 'V': return RK_V;
    case 'W': return RK_W;
    case 'X': return RK_X;
    case 'Y': return RK_Y;
    case 'Z': return RK_Z;
    case VK_NUMPAD0: return RK_NUMPAD_0;
    case VK_NUMPAD1: return RK_NUMPAD_1;
    case VK_NUMPAD2: return RK_NUMPAD_2;
    case VK_NUMPAD3: return RK_NUMPAD_3;
    case VK_NUMPAD4: return RK_NUMPAD_4;
    case VK_NUMPAD5: return RK_NUMPAD_5;
    case VK_NUMPAD6: return RK_NUMPAD_6;
    case VK_NUMPAD7: return RK_NUMPAD_7;
    case VK_NUMPAD8: return RK_NUMPAD_8;
    case VK_NUMPAD9: return RK_NUMPAD_9;
    case VK_MULTIPLY: return RK_NUMPAD_STAR;
    case VK_ADD: return RK_NUMPAD_PLUS;
    case VK_SUBTRACT: return RK_NUMPAD_MINUS;
    case VK_DIVIDE: return RK_NUMPAD_SLASH;
    case VK_DECIMAL: return RK_NUMPAD_DOT;
    case VK_NUMLOCK: return RK_NUM_LOCK;
    case VK_F1: return RK_F1;
    case VK_F2: return RK_F2;
    case VK_F3: return RK_F3;
    case VK_F4: return RK_F4;
    case VK_F5: return RK_F5;
    case VK_F6: return RK_F6;
    case VK_F7: return RK_F7;
    case VK_F8: return RK_F8;
    case VK_F9: return RK_F9;
    case VK_F10: return RK_F10;
    case VK_F11: return RK_F11;
    case VK_F12: return RK_F12;
    case VK_SCROLL: return RK_SCROLL_LOCK;

    case VK_LSHIFT: return RK_LSHIFT;
    case VK_RSHIFT: return RK_RSHIFT;
    case VK_LCONTROL: return RK_LCTRL;
    case VK_RCONTROL: return RK_RCTRL;
    case VK_LMENU: return RK_LALT;
    case VK_RMENU: return RK_RALT;

    /* Looks like windows can't tell the difference between
    left/right ctrl/shift/alt on (some?) keyboards.*/
    case VK_SHIFT: return RK_LSHIFT;
    case VK_CONTROL: return RK_LCTRL;
    case VK_MENU: return RK_LALT;

    case VK_LWIN: return RK_LWIN;
    case VK_RWIN: return RK_RWIN;
    case VK_APPS: return RK_MENU;
    case VK_OEM_COMMA: return RK_COMMA;
    case VK_OEM_PERIOD: return RK_DOT;
    case VK_OEM_MINUS: return RK_MINUS;
    case VK_OEM_PLUS: return RK_EQUALS;
    case VK_OEM_2: return RK_SLASH;
    case VK_OEM_3: return RK_BACKTICK;
    case VK_OEM_4: return RK_LBRACKET;
    case VK_OEM_6: return RK_RBRACKET;
    case VK_OEM_5: return RK_BACKSLASH;
    case VK_OEM_1: return RK_SEMICOLON;
    case VK_OEM_7: return RK_QUOTE;

    default: return RK_UNKNOWN;
    }

}

void raw_init() {
    HINSTANCE instance = 0;
    HWND hwnd = 0;

    if (inited) {
        return;
    }
    inited = true;

    device_count = scan_devices(devices);

    /* Register a window class */
    WNDCLASS wc;
    memset(&wc, 0, sizeof(wc));
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = instance;
    wc.lpszClassName = "dummy_class";
    RegisterClass(&wc);

    /* Message-only window */
    msg_window = CreateWindow("dummy_class", "dummy", 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, instance, NULL);
    if (!msg_window) {
        return;
    }
    hwnd = msg_window;

    /* Register what type of rawinput we're interested in */
    RAWINPUTDEVICE rids[4];
    u64 flags = 0;
    rids[0].usUsagePage = 0x01;
    rids[0].usUsage = 0x06; /* Keyboards */
    rids[0].hwndTarget = hwnd;
    rids[0].dwFlags = flags;
    rids[1].usUsagePage = 0x01;
    rids[1].usUsage = 0x07; /* Keyboards */
    rids[1].hwndTarget = hwnd;
    rids[1].dwFlags = flags;
    rids[2].usUsagePage = 0x01;
    rids[2].usUsage = 0x02; /* Mice */
    rids[2].hwndTarget = hwnd;
    rids[2].dwFlags = flags;
    rids[3].usUsagePage = 0x01;
    rids[3].usUsage = 0x03; /* Mice */
    rids[3].hwndTarget = hwnd;
    rids[3].dwFlags = flags;
    RegisterRawInputDevices(&rids[0], 4, (UINT)sizeof(rids[0]));

}

void raw_quit() {
    if(!inited) {
        return;
    }

    device_count = 0;

    if (msg_window) {
        CloseWindow(msg_window);
        msg_window = NULL;
    }
}

static void handle_msg(const MSG *msg) {
    HRAWINPUT raw_input_handle = (HRAWINPUT)msg->lParam;
    RAWINPUT input;
    u32 size = sizeof(RAWINPUT);

    if ((u32)-1 == GetRawInputData(raw_input_handle, RID_INPUT, &input, &size, sizeof(RAWINPUTHEADER))) {
        return;
    }

    if (msg->message != WM_INPUT) {
        return;
    }

    int idx = find_device_by_handle(input.header.hDevice);
    if (idx < 0) {
        /*
            Error: If we are receiving messages about
            this device, we must have it in the devices
            array.
        */
        breakpoint();
        return;
    }
    if (!devices[idx].is_open) {
        return; /* Not open -> Not emitting event */
    }

    void *tag = devices[idx].tag;

    switch (input.header.dwType) {
    case RIM_TYPEKEYBOARD:
        /*
            TODO: I should switch to using MakeCode here
            instead of VKey, since the latter seems to be
            affected by keyboard layout and other "software"
            things.
        */
        if (input.data.keyboard.Flags & RI_KEY_BREAK) {
            emit_key_up(tag, translate_windows_vk(input.data.keyboard.VKey));
        }
        else {
            emit_key_down(tag, translate_windows_vk(input.data.keyboard.VKey));
        }
        break;
    case RIM_TYPEMOUSE:
        if (input.data.mouse.usFlags == MOUSE_MOVE_RELATIVE) {
            if (input.data.mouse.lLastX) {
                emit_rel(tag, RA_X, input.data.mouse.lLastX);
            }
            if (input.data.mouse.lLastY) {
                emit_rel(tag, RA_Y, input.data.mouse.lLastY);
            }
        }
        if (input.data.mouse.usButtonFlags & RI_MOUSE_LEFT_BUTTON_DOWN) {
            emit_key_down(tag, RK_LMB);
        }
        if (input.data.mouse.usButtonFlags & RI_MOUSE_LEFT_BUTTON_UP) {
            emit_key_up(tag, RK_LMB);
        }
        if (input.data.mouse.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_DOWN) {
            emit_key_down(tag, RK_RMB);
        }
        if (input.data.mouse.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_UP) {
            emit_key_up(tag, RK_RMB);
        }
        if (input.data.mouse.usButtonFlags & RI_MOUSE_MIDDLE_BUTTON_DOWN) {
            emit_key_down(tag, RK_MMB);
        }
        if (input.data.mouse.usButtonFlags & RI_MOUSE_MIDDLE_BUTTON_UP) {
            emit_key_up(tag, RK_MMB);
        }
        if (input.data.mouse.usButtonFlags & RI_MOUSE_WHEEL) {
            emit_rel(tag, RA_WHEEL, (i16)(input.data.mouse.usButtonData) / WHEEL_DELTA);
        }
        break;
    default:
        break;
    }
}

static void handle_plug() {
    /*
        I am aware of RIDEV_DEVNOTIFY, but that says on MSDN that
        it doesn't support XP so we do it like this:
        Rescan devices and compare with old device array to detect
        when a device is (un)plugged.
    */

    int rescan_count;
    Device rescan[MAX_DEVICES];
    int n = device_count;
    int i, j;

    rescan_count = scan_devices(rescan);

    /* Iterate in reverse here because we'll be deleting */
    for (i = n - 1; i >= 0; --i) {
        Device* dold = &devices[i];
        int is_unplug = 1;
        for (j=0; j<rescan_count; ++j) {
            if(rescan[j].ridl.hDevice == dold->ridl.hDevice) {
                is_unplug = 0;
                break;
            }
        }
        if (is_unplug) {
            emit_unplug(dold->tag);
            delete_device(i);
        }
    }

    for (i=0; i<rescan_count; ++i) {
        Device *dnew = &rescan[i];
        int idx = find_device_by_handle(dnew->ridl.hDevice);
        if (idx < 0) {
            int newi = device_count;
            if (newi < MAX_DEVICES) {
                /* New device plugged in */
                devices[newi] = *dnew;
                device_count++;
                emit_plug(newi);
            } else {
                /* No more room for new devices */
                ;
            }
        }
    }
}

void raw_poll() {
    MSG msg;

    if (!inited)
        return;

    while (PeekMessage(&msg, msg_window, WM_INPUT, WM_INPUT, PM_REMOVE)) {
        handle_msg(&msg);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    handle_plug();
}

#endif /* _WIN32 */
#ifdef __linux__

#include <linux/input.h>
#include <sys/poll.h>
#include <sys/stat.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void raw_init();
void raw_quit();
void raw_poll();

static struct pollfd pfds[MAX_DEVICES];

static int inotify_fd;
static struct pollfd inotify_pfd;

static int scan_devices(Device *devices);
static void handle_plug();
static void handle_evt(const struct input_event *evt, void *tag);

static int find_device_by_fd(int fd) {
    int i;
    for (i=0; i<device_count; ++i) {
        Device *d = &devices[i];

        if (d->fd == fd) {
            return i;
        }
    }

    return -1;
}

static int find_device_by_handle(int handle) {
    int i;
    for (i=0; i<device_count; ++i) {
        Device *d = &devices[i];

        if (d->handle == handle) {
            return i;
        }
    }

    return -1;
}

void raw_init() {
    device_count = scan_devices(devices);

    for (int i=0; i<device_count; ++i) {
        pfds[i].fd = devices[i].fd;
        pfds[i].events = POLLIN;
    }

    inotify_fd = inotify_init();
    inotify_add_watch(inotify_fd, "/dev/input/", IN_CREATE);

    inotify_pfd.fd = inotify_fd;
    inotify_pfd.events = POLLIN;
}

void raw_quit() {
    for (int i=0; i<device_count; ++i) {
        close(devices[i].fd);
    }
    close(inotify_fd);
    device_count = 0;
}

void raw_poll() {
    poll(&pfds[0], device_count, 0);
    for (int i=device_count-1; i>=0; --i) {

        if (pfds[i].revents & POLLIN) {
            int idx = find_device_by_fd(pfds[i].fd);
            if (idx < 0) {
//                breakpoint();
                continue;
            }


            if (!devices[idx].is_open) {
                continue;
            }


            void *tag = devices[idx].tag;

            struct input_event evts[64];
            ssize_t rb;
            rb = read(pfds[i].fd, &evts[0], sizeof(evts[0]) * 64);
            if (rb > 0) {
                size_t evt_cnt = rb / sizeof(evts[0]);
                for (int i=0; i<evt_cnt; ++i) {
                    handle_evt(&evts[i], tag);
                }
            }
        }
        else if (pfds[i].revents != 0) {
            // Device unplugged
            if (devices[i].is_open) {
                emit_unplug(devices[i].tag);
            }

            close(pfds[i].fd);
            pfds[i] = pfds[device_count-1];
            delete_device(i);

            //~ breakpoint();
        }
    }

    handle_plug();
}

static int scan_devices(Device *devices) {
    // We scan the devices by listing the contents of /dev/input
    DIR *dirp = opendir("/dev/input/");

    if (!dirp) {
        return 0;
    }

    struct dirent *d = 0;
    int i = 0;
    while ((d = readdir(dirp))) {
        if (i >= MAX_DEVICES) {
            // No more room for new devices
            break;
        }

        // Consider only character devices whose name starts with event
        if (d->d_type == DT_CHR && strncmp(d->d_name, "event", strlen("event")) == 0) {
            char path[PATH_MAX];
            snprintf(path, PATH_MAX, "/dev/input/%s", d->d_name);
            int fd = open(path, O_RDONLY);

            if (fd < 0) {
                continue;
            }

            // Get the number * in /dev/input/event*
            int handle = strtol(d->d_name + strlen("event"), NULL, 10);
            //dbg("opened path:%s fd:%d handle:%d\n", path, fd, handle);

            Device *d = &devices[i];
            d->fd = fd;
            d->handle = handle;

            d->is_open = false;
            d->tag = 0;
            ++i;
        }
    }

    closedir(dirp);
    return i;
}

static void handle_plug() {
    static char queue[MAX_DEVICES][PATH_MAX];
    static int queue_cnt = 0;

    // We use inotify to detect plugging new devices
    // (corresponds to creation of new event file in /dev/input)
    poll(&inotify_pfd, 1, 0);
    if (inotify_pfd.revents & POLLIN) {
        // Buffered read
        struct inotify_event events[64];
        ssize_t rb = read(inotify_fd, events, 64 * sizeof(events[0]));
        if (rb < 0) {
            ;
        }
        else {
            size_t event_cnt = rb / sizeof(events[0]);
            for (int i=0; i<event_cnt; ++i) {
                if (strncmp(events[i].name, "event", strlen("event")) != 0) {
                    continue;
                }

                if (events[i].mask & IN_CREATE) {
                    // If register_device fails because of a permission error, we need to keep
                    // retrying-- my guess is that is because of the lag between the moment
                    // when the input subsystem creates the character device and the moment
                    // it sets the proper permissions.
                    //
                    // This retry loop can take a long while !!

                    // To prevent lag spikes we enqueue the device for registration and try to
                    // register devices from there only once during the poll loop iteration.
                    if (queue_cnt < MAX_DEVICES) {
                        snprintf(&queue[queue_cnt++][0], 512, "/dev/input/%s", events[i].name);
                        //~ breakpoint();
                    }
                }
            }
        }
    } else if (inotify_pfd.revents != 0) {
        ;
    }

    // Try to get one new device from queue
    // ((( Even though I named this a queue, I actually use it like a stack )))

    if (queue_cnt > 0 && device_count < MAX_DEVICES) {
        const char *path = &queue[queue_cnt-1][0];
        int fd = open(path, O_RDONLY);

        if (fd < 0) {
            return;
        }

        // Get the number * in /dev/input/event*
        int handle = strtol(path + strlen("/dev/input/event"), NULL, 10);
        if (find_device_by_handle(handle) >= 0) {
            queue_cnt--;
            return;
        }

        int nexti = device_count;

        Device *d = &devices[nexti];
        d->fd = fd;
        d->handle = handle;

        d->is_open = false;
        d->tag = 0;

        pfds[nexti].fd = fd;
        pfds[nexti].events = POLLIN;

        device_count++;
        queue_cnt--;

        emit_plug(nexti);

        //breakpoint();
    }
}

static Raw_Key translate_linux_vk(__u16 vk) {
    //~ dbg("linux key: %u\n", vk);

    switch (vk) {
        /* Standard 3-button mouse */

    case BTN_LEFT: return RK_LMB;
    case BTN_RIGHT: return RK_RMB;
    case BTN_MIDDLE: return RK_MMB;

        /* ANSI standard keyboard - full form factor */

    case KEY_BACKSPACE: return RK_BACKSPACE;
    case KEY_TAB: return RK_TAB;
    case KEY_ENTER: return RK_ENTER;
    case KEY_PAUSE: return RK_PAUSE;
    case KEY_CAPSLOCK: return RK_CAPS_LOCK;
    case KEY_ESC: return RK_ESC;
    case KEY_SPACE: return RK_SPACE;
    case KEY_PAGEUP: return RK_PAGE_UP;
    case KEY_PAGEDOWN: return RK_PAGE_DOWN;
    case KEY_END: return RK_END;
    case KEY_HOME: return RK_HOME;
    case KEY_LEFT: return RK_LEFT;
    case KEY_UP: return RK_UP;
    case KEY_RIGHT: return RK_RIGHT;
    case KEY_DOWN: return RK_DOWN;
    case KEY_SYSRQ: return RK_PRINT_SCR;
    case KEY_INSERT: return RK_INSERT;
    case KEY_DELETE: return RK_DELETE;
    case KEY_0: return RK_0;
    case KEY_1: return RK_1;
    case KEY_2: return RK_2;
    case KEY_3: return RK_3;
    case KEY_4: return RK_4;
    case KEY_5: return RK_5;
    case KEY_6: return RK_6;
    case KEY_7: return RK_7;
    case KEY_8: return RK_8;
    case KEY_9: return RK_9;
    case KEY_A: return RK_A;
    case KEY_B: return RK_B;
    case KEY_C: return RK_C;
    case KEY_D: return RK_D;
    case KEY_E: return RK_E;
    case KEY_F: return RK_F;
    case KEY_G: return RK_G;
    case KEY_H: return RK_H;
    case KEY_I: return RK_I;
    case KEY_J: return RK_J;
    case KEY_K: return RK_K;
    case KEY_L: return RK_L;
    case KEY_M: return RK_M;
    case KEY_N: return RK_N;
    case KEY_O: return RK_O;
    case KEY_P: return RK_P;
    case KEY_Q: return RK_Q;
    case KEY_R: return RK_R;
    case KEY_S: return RK_S;
    case KEY_T: return RK_T;
    case KEY_U: return RK_U;
    case KEY_V: return RK_V;
    case KEY_W: return RK_W;
    case KEY_X: return RK_X;
    case KEY_Y: return RK_Y;
    case KEY_Z: return RK_Z;
    case KEY_KP0: return RK_NUMPAD_0;
    case KEY_KP1: return RK_NUMPAD_1;
    case KEY_KP2: return RK_NUMPAD_2;
    case KEY_KP3: return RK_NUMPAD_3;
    case KEY_KP4: return RK_NUMPAD_4;
    case KEY_KP5: return RK_NUMPAD_5;
    case KEY_KP6: return RK_NUMPAD_6;
    case KEY_KP7: return RK_NUMPAD_7;
    case KEY_KP8: return RK_NUMPAD_8;
    case KEY_KP9: return RK_NUMPAD_9;
    case KEY_KPASTERISK: return RK_NUMPAD_STAR;
    case KEY_KPPLUS: return RK_NUMPAD_PLUS;
    case KEY_KPMINUS: return RK_NUMPAD_MINUS;
    case KEY_KPSLASH: return RK_NUMPAD_SLASH;
    case KEY_KPDOT: return RK_NUMPAD_DOT;
    case KEY_NUMLOCK: return RK_NUM_LOCK;
    case KEY_F1: return RK_F1;
    case KEY_F2: return RK_F2;
    case KEY_F3: return RK_F3;
    case KEY_F4: return RK_F4;
    case KEY_F5: return RK_F5;
    case KEY_F6: return RK_F6;
    case KEY_F7: return RK_F7;
    case KEY_F8: return RK_F8;
    case KEY_F9: return RK_F9;
    case KEY_F10: return RK_F10;
    case KEY_F11: return RK_F11;
    case KEY_F12: return RK_F12;
    case KEY_SCROLLLOCK: return RK_SCROLL_LOCK;

    case KEY_LEFTSHIFT: return RK_LSHIFT;
    case KEY_RIGHTSHIFT: return RK_RSHIFT;
    case KEY_LEFTCTRL: return RK_LCTRL;
    case KEY_RIGHTCTRL: return RK_RCTRL;
    case KEY_LEFTALT: return RK_LALT;
    case KEY_RIGHTALT: return RK_RALT;

    case KEY_LEFTMETA: return RK_LWIN;
    case KEY_RIGHTMETA: return RK_RWIN;
    case KEY_COMPOSE: return RK_MENU;
    case KEY_COMMA: return RK_COMMA;
    case KEY_DOT: return RK_DOT;
    case KEY_MINUS: return RK_MINUS;
    case KEY_EQUAL: return RK_EQUALS;
    case KEY_SLASH: return RK_SLASH;
    case KEY_GRAVE: return RK_BACKTICK;
    case KEY_LEFTBRACE: return RK_LBRACKET;
    case KEY_RIGHTBRACE: return RK_RBRACKET;
    case KEY_BACKSLASH: return RK_BACKSLASH;
    case KEY_SEMICOLON: return RK_SEMICOLON;
    case KEY_APOSTROPHE: return RK_QUOTE;

    default: return RK_UNKNOWN;
    }

}

Raw_Axis translate_linux_axis(__u16 axis) {
    switch (axis) {
        case REL_X: return RA_X;
        case REL_Y: return RA_Y;
        case REL_WHEEL: return RA_WHEEL;
        default: return RA_UNKNOWN;
    }
}

static void handle_evt(const struct input_event *evt, void *tag) {
    switch (evt->type) {
        case EV_KEY:
            if (evt->value) {
                emit_key_down(tag, translate_linux_vk(evt->code));
            } else {
                emit_key_up(tag, translate_linux_vk(evt->code));
            }
            break;
        case EV_REL:
            emit_rel(tag, translate_linux_axis(evt->code), evt->value);
            break;
        default:
            return;
    }
}

#endif // __linux__
#endif // RAWINPUT_IMPL

#ifdef RAWINPUT_SAMPLE
#include <stdio.h>

#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"

/* Event handling callbacks */
void sample_on_key_down(void *tag, Raw_Key key, void *_) {
    printf("Device %d: Key %s was pressed.\n", (int)tag, raw_key_str(key));
}

void sample_on_key_up(void *tag, Raw_Key key, void *_) {
    printf("Device %d: Key %s was released.\n", (int)tag, raw_key_str(key));
}

void sample_on_rel(void *tag, Raw_Axis axis, int delta, void *_) {
    printf("Device %d: Movement %d on axis %s.\n", (int)tag, delta, raw_axis_str(axis));
}

void sample_on_plug(int idx, void *_) {
    // Use a counter to assign a unique id to each device as it's plugged in
    int *next_tag = (int*)_;
    int tag = *next_tag;
    *next_tag = tag + 1;

    raw_open(idx, (void*)tag);
    printf("Device %d at idx %d plugged.\n", (int)tag, idx);
}

void sample_on_unplug(void *tag, void *_) {
    raw_close(tag);
    printf("Device %d unplugged.\n", (int)tag);
}
/**/

int main (int argc, char **argv) {
    // Initialize library
    raw_init();

    // Count available devices
    int dev_cnt = raw_dev_cnt();
    printf("Detected %d devices.\n", dev_cnt);

    #ifdef __linux__
    if (dev_cnt == 0) {
        /* Linux receives raw input events from all windows, however
         * the price is that the user that runs the program has to do
         * some system administration to make sure the /dev/input/event*
         * files are readable. Usually the simplest way is to just run
         * the program as root. */
        puts("Did you make sure that /dev/input/event* files are readable by this user?");
    }
    #endif

    // Open all available devices
    int next_tag = 0;
    for (int i=0; i<dev_cnt; ++i) {
        raw_open(i, (void*)(next_tag++));
    }

    // Register event handlers
    raw_on_key_down(sample_on_key_down, 0);
    raw_on_key_up(sample_on_key_up, 0);
    raw_on_rel(sample_on_rel, 0);
    raw_on_unplug(sample_on_unplug, 0);
    raw_on_plug(sample_on_plug, &next_tag);

    #ifdef _WIN32
    /* Windows requires us to have a window open to receive raw input events,
     * and we only receive events from windows owned by our process.
     *
     * Usually you'd open a window anyway and use a cross-platform library
     * like SDL, but here for simplicity we use win32 and only open a window
     * when running on windows. */
    WNDCLASS wc;
    HINSTANCE instance = 0;
    memset(&wc, 0, sizeof(wc));
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = instance;
    wc.lpszClassName = "sample_class";
    RegisterClass(&wc);

    HWND hwnd = CreateWindow("sample_class", "sample", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 0, 0, HWND_DESKTOP, NULL, instance, NULL);
    #endif

    puts("Entering event loop.");
    #ifdef _WIN32
    puts("Close the window to terminate.");
    #else
    puts("Press Control+C to terminate.");
    #endif

    #ifdef _WIN32
    /* Here we handle the "windowing" events that rawinput doesn't handle;
     * Again usually you'd use cross-platform SDL code here instead of win32 */
    MSG msg;
    while (GetMessage(&msg, hwnd, 0, 0) >= 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        // Check for raw input and call event handlers
        raw_poll();
    }
    #elif __linux__
    for (;;) {
        // Check for raw input and call event handlers
        raw_poll();
    }
    #endif

    // Clean up
    raw_quit();
}

#endif // RAWINPUT_SAMPLE

/*
    Copyright (c) 2021 Luka Aleksic

    Permission to use, copy, modify, and/or distribute this software for any
    purpose with or without fee is hereby granted.

    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
    REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
    AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
    INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
    LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
    OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
    PERFORMANCE OF THIS SOFTWARE.
*/
