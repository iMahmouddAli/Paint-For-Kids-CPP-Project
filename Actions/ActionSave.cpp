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
    pGUI->PrintMessage("Enter a Valid Name For the file then press Enter.. ^_^");
    fileName = pGUI->GetSrting();
    ofstream savedFile;

    savedFile.open(("saved_Drawing_files/" + fileName + ".txt"), ios::out);


    bool flag = false;
    if (savedFile.fail()) {
        flag = true;
    }


    while (flag)
    {
        pGUI->PrintMessage("Enter a Valid Name For the file then press Enter.. ^_^");
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
    pGUI->PrintMessage("You Drawing in a Good Hand Don't Worry ..^_^");

}
