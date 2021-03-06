/*
 * FILE:
 *   key_name.cpp
 *
 * AUTHOR:
 *   Stephen Thompson <stephen@solarflare.org.uk>
 *
 * COPYRIGHT:
 *   Copyright (C) Stephen Thompson, 2008 - 2009.
 *
 *   This file is part of the "Coercri" software library. Usage of "Coercri"
 *   is permitted under the terms of the Boost Software License, Version 1.0, 
 *   the text of which is displayed below.
 *
 *   Boost Software License - Version 1.0 - August 17th, 2003
 *
 *   Permission is hereby granted, free of charge, to any person or organization
 *   obtaining a copy of the software and accompanying documentation covered by
 *   this license (the "Software") to use, reproduce, display, distribute,
 *   execute, and transmit the Software, and to prepare derivative works of the
 *   Software, and to permit third-parties to whom the Software is furnished to
 *   do so, all subject to the following:
 *
 *   The copyright notices in the Software and this entire statement, including
 *   the above license grant, this restriction and the following disclaimer,
 *   must be included in all copies of the Software, in whole or in part, and
 *   all derivative works of the Software, unless such copies or derivative
 *   works are solely in the form of machine-executable object code generated by
 *   a source language processor.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 *   SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 *   FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *   DEALINGS IN THE SOFTWARE.
 *
 */

#include "key_code.hpp"

#include <map>

namespace Coercri {
    
    namespace {
        std::map<RawKey, const char *> names;

        void InitNames()
        {
            if (!names.empty()) return;
        
            names[RK_0] = "0";
            names[RK_1] = "1";
            names[RK_2] = "2";
            names[RK_3] = "3";
            names[RK_4] = "4";
            names[RK_5] = "5";
            names[RK_6] = "6";
            names[RK_7] = "7";
            names[RK_8] = "8";
            names[RK_9] = "9";
            names[RK_A] = "A";
            names[RK_AMPERSAND] = "&";
            names[RK_ASTERISK] = "*";
            names[RK_AT] = "@";
            names[RK_B] = "B";
            names[RK_BACKQUOTE] = "`";
            names[RK_BACKSLASH] = "\\";
            names[RK_BACKSPACE] = "BACKSPACE";
            names[RK_BREAK] = "BREAK";
            names[RK_C] = "C";
            names[RK_CAPS_LOCK] = "CAPS LOCK";
            names[RK_CARET] = "^";
            names[RK_CLEAR] = "CLEAR";
            names[RK_COLON] = ":";
            names[RK_COMMA] = ",";
            names[RK_COMPOSE] = "COMPOSE";
            names[RK_D] = "D";
            names[RK_DELETE] = "DELETE";
            names[RK_DOLLAR] = "$";
            names[RK_DOUBLE_QUOTE] = "\"";
            names[RK_DOWN] = "DOWN";
            names[RK_E] = "E";
            names[RK_END] = "END";
            names[RK_EQUALS] = "=";
            names[RK_ESCAPE] = "ESCAPE";
            names[RK_EURO] = "EURO";
            names[RK_EXCLAIM] = "!";
            names[RK_F] = "F";
            names[RK_F1] = "F1";
            names[RK_F2] = "F2";
            names[RK_F3] = "F3";
            names[RK_F4] = "F4";
            names[RK_F5] = "F5";
            names[RK_F6] = "F6";
            names[RK_F7] = "F7";
            names[RK_F8] = "F8";
            names[RK_F9] = "F9";
            names[RK_F10] = "F10";
            names[RK_F11] = "F11";
            names[RK_F12] = "F12";
            names[RK_F13] = "F13";
            names[RK_F14] = "F14";
            names[RK_F15] = "F15";
            names[RK_G] = "G";
            names[RK_GREATER] = ">";
            names[RK_H] = "H";
            names[RK_HASH] = "#";
            names[RK_HELP] = "HELP";
            names[RK_HOME] = "HOME";
            names[RK_I] = "I";
            names[RK_INSERT] = "INSERT";
            names[RK_J] = "J";
            names[RK_K] = "K";
            names[RK_KP_0] = "NUMPAD 0";
            names[RK_KP_1] = "NUMPAD 1";
            names[RK_KP_2] = "NUMPAD 2";
            names[RK_KP_3] = "NUMPAD 3";
            names[RK_KP_4] = "NUMPAD 4";
            names[RK_KP_5] = "NUMPAD 5";
            names[RK_KP_6] = "NUMPAD 6";
            names[RK_KP_7] = "NUMPAD 7";
            names[RK_KP_8] = "NUMPAD 8";
            names[RK_KP_9] = "NUMPAD 9";
            names[RK_KP_DIVIDE] = "NUMPAD /";
            names[RK_KP_ENTER] = "ENTER";
            names[RK_KP_EQUALS] = "NUMPAD =";
            names[RK_KP_MINUS] = "NUMPAD -";
            names[RK_KP_MULTIPLY] = "NUMPAD *";
            names[RK_KP_PERIOD] = "NUMPAD .";
            names[RK_KP_PLUS] = "NUMPAD +";
            names[RK_L] = "L";
            names[RK_LEFT] = "LEFT";
            names[RK_LEFT_ALT] = "LEFT ALT";
            names[RK_LEFT_BRACKET] = "[";
            names[RK_LEFT_CONTROL] = "LEFT CTRL";
            names[RK_LEFT_META] = "LEFT META";
            names[RK_LEFT_PAREN] = "LEFT (";
            names[RK_LEFT_SHIFT] = "LEFT SHIFT";
            names[RK_LEFT_WINDOWS] = "LEFT WINDOWS";
            names[RK_LESS] = "<";
            names[RK_M] = "M";
            names[RK_MENU] = "MENU";
            names[RK_MODE] = "MODE";
            names[RK_MINUS] = "-";
            names[RK_N] = "N";
            names[RK_NUM_LOCK] = "NUM LOCK";
            names[RK_O] = "O";
            names[RK_P] = "P";
            names[RK_PAGE_DOWN] = "PAGE DOWN";
            names[RK_PAGE_UP] = "PAGE UP";
            names[RK_PAUSE] = "PAUSE";
            names[RK_PERIOD] = ".";
            names[RK_PLUS] = "+";
            names[RK_POWER] = "POWER";
            names[RK_PRINT_SCREEN] = "PRINT SCREEN";
            names[RK_Q] = "Q";
            names[RK_QUESTION] = "?";
            names[RK_R] = "R";
            names[RK_RETURN] = "RETURN";
            names[RK_RIGHT] = "RIGHT";
            names[RK_RIGHT_ALT] = "RIGHT ALT";
            names[RK_RIGHT_BRACKET] = "]";
            names[RK_RIGHT_CONTROL] = "RIGHT CTRL";
            names[RK_RIGHT_META] = "RIGHT META";
            names[RK_RIGHT_PAREN] = ")";
            names[RK_RIGHT_SHIFT] = "RIGHT SHIFT";
            names[RK_RIGHT_WINDOWS] = "RIGHT WINDOWS";
            names[RK_S] = "S";
            names[RK_SCROLL_LOCK] = "SCROLL LOCK";
            names[RK_SEMICOLON] = ";";
            names[RK_SINGLE_QUOTE] = "'";
            names[RK_SLASH] = "/";
            names[RK_SPACE] = "SPACE";
            names[RK_SYSREQ] = "SYSREQ";
            names[RK_T] = "T";
            names[RK_TAB] = "TAB";
            names[RK_U] = "U";
            names[RK_UNDERSCORE] = "_";
            names[RK_UNDO] = "UNDO";
            names[RK_UP] = "UP";
            names[RK_V] = "V";
            names[RK_W] = "W";
            names[RK_X] = "X";
            names[RK_Y] = "Y";
            names[RK_Z] = "Z";
        }
    }

    std::string RawKeyName(RawKey rk)
    {
        InitNames();
        std::map<RawKey, const char *>::const_iterator it = names.find(rk);
        if (it == names.end()) {
            return "UNKNOWN";
        } else {
            return it->second;
        }
    }



}
