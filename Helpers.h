#include "DEFS.h"
#include "GUI/GUI.h"
class Helpers
{
public:
    static Point getMidPoint(Point p1, Point p2) {
        Point p;
        p.x = (p2.x + p1.x) / 2;
        p.y = (p2.y + p1.y) / 2;
        return p;
    }
    static string getColorName(color c) {
        if (c == NULL)      return "UNFILLED";
        if (c == BURLYWOOD)       return "BURLYWOOD";
        if (c == LIGHTGREEN)       return "LIGHTGREEN";
        if (c == LIGHTYELLOW)       return "LIGHTYELLOW";
        if (c == THISTLE)       return "THISTLE";
        if (c == WHEAT)       return "WHEAT";
        if (c == DARKCYAN)       return "DARKCYAN";
        if (c == DARKMAGENTA)       return "DARKMAGENTA";
        if (c == GREEN)       return "GREEN";
        if (c == HOTPINK)       return "HOTPINK";
        if (c == INDIAN)       return "INDIAN";
        if (c == LIGHTCORAL)       return "LIGHTCORAL";
        if (c == PERU)       return "PERU";
        if (c == SIENNA)       return "SIENNA";
        if (c == TOMATO)       return "TOMATO";
        if (c == BLACK)       return "BLACK";
        if (c == RED)       return "RED";
        if (c == CHOCOLATE)       return "CHOCOLATE";
        if (c == DARKGOLDENROD)       return "DARKGOLDENROD";
        if (c == DARKRED)       return "DARKRED";
        if (c == DEEPPINK)       return "DEEPPINK";
        if (c == OLIVEDRAB)       return "OLIVEDRAB";
        return "Unknown Color";
    }
    static color getColorFromString(string c) {
        if (c == "BURLYWOOD")       return BURLYWOOD;
        if (c == "LIGHTGREEN")       return LIGHTGREEN;
        if (c == "LIGHTYELLOW")       return LIGHTYELLOW;
        if (c == "THISTLE")       return THISTLE;
        if (c == "WHEAT")       return WHEAT;
        if (c == "DARKCYAN")       return DARKCYAN;
        if (c == "DARKMAGENTA")       return DARKMAGENTA;
        if (c == "GREEN")       return GREEN;
        if (c == "HOTPINK")       return HOTPINK;
        if (c == "INDIAN")       return INDIAN;
        if (c == "LIGHTCORAL")       return LIGHTCORAL;
        if (c == "PERU")       return PERU;
        if (c == "SIENNA")       return SIENNA;
        if (c == "TOMATO")       return TOMATO;
        if (c == "BLACK")       return BLACK;
        if (c == "RED")       return RED;
        if (c == "CHOCOLATE")       return CHOCOLATE;
        if (c == "DARKGOLDENROD")       return DARKGOLDENROD;
        if (c == "DARKRED")       return DARKRED;
        if (c == "DEEPPINK")       return DEEPPINK;
        if (c == "OLIVEDRAB")       return OLIVEDRAB;
        return BLACK;
    }
    static bool checkPointInsideDrawArea(int x, int y) {
        if (y < UI.ToolBarHeight || y > UI.height - UI.StatusBarHeight || x > UI.width || x < 0) {
            return false;
        }
        return true;
    }
};

