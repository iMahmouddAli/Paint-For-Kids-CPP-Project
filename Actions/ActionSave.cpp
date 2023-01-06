#include "ActionSave.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <fstream>

ActionSave::ActionSave(ApplicationManager* pApp, int _figcount) :Action(pApp)
{
    //fileName = "testFirst";
    count = _figcount;
}

void ActionSave::Execute()
{

    GUI* pGUI = pManager->GetGUI();
    pGUI->PrintMessage("PLZ enter file name");
    fileName = pGUI->GetSrting();
    ofstream savedFile;

    savedFile.open((fileName + ".txt"), ios::out);


    bool flag = false;
    if (savedFile.fail()) {
        flag = true;
    }


    while (flag)
    {
        pGUI->PrintMessage("Please write a valid name then press ENTER");
        fileName = pGUI->GetSrting();
        savedFile.open(fileName + ".txt", ios::out);
        if (savedFile.good())//true if i opened file
            flag = false;
    }


    savedFile << pManager->colorToString(UI.DrawColor) << "\t";//-------
    savedFile << pManager->colorToString(UI.FillColor) << "\t";
    savedFile << pManager->colorToString(UI.BkGrndColor) << "\t";
    //  pGUI->ClearStatusBar();
    savedFile << "\n" << count << "\n";
    pManager->SaveFile(savedFile);
    savedFile.close();
    pGUI->PrintMessage("Your data has been seved successfully...");








}
