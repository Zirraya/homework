using UnityEngine;

public class MenuBar : MonoBehaviour
{
    public MenuPause menuPause;         // Pause Menu
    public CharacterMenu characterMenu; // Character
    public QuestBook questBook;         // Quests
    public CodexBook codexBook;
    public SpellBook spellBook;


    public void Update()
    {
        if(Input.GetKeyDown(KeyCode.Escape)) 
        {
            if (WindowManager.Instance.HaveOpenWindow)
            {
                WindowManager.Instance.Close();
            }
            else
            {
                OpenMenuPause();
            }
        }

      
    }

    public void OpenMenuPause()
    {
        WindowManager.Instance.Open(menuPause);
    }

    public void OpenCodexBook()
    {
        WindowManager.Instance.Open(codexBook);
    }

    public void OpenQuestBook()
    {

        WindowManager.Instance.Open(questBook);
    }

    public void OpenCharacterMenu()
    {
        WindowManager.Instance.Open(characterMenu);
    }

    public void OpenSkillBook()
    {
        WindowManager.Instance.Open(spellBook);


    }

    
}
