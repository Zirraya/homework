using System.Collections;
using System.Collections.Generic;
using UnityEngine;


// скрипт для ввызова диалога рядом с персонажем
public class DailogAnimator : MonoBehaviour
{
    public Animator startAnim;
    public DialogManager dm;


    // функция работает, когда игрок вхрдит в зону NPC

    public void OnTriggerEnter2D(Collider2D other)
    {
        startAnim.SetBool("StartOpen", true);

    }

    // функция закончить диалог
    public void OnTriggerExit2D(Collider2D other)
    {
        startAnim.SetBool("StartOpen", false);
        dm.EndDialog();
    }


}
