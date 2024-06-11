using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DialogTrigger : MonoBehaviour
{

    public Dialog dialog;

    // функция вызывающая диалог

    public void DialogueTrigger()
    {
        FindObjectOfType<DialogManager>().StartDialog(dialog);
    }
}
