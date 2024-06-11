using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI; // библиотека нужна, что бы диалог видел текст, который указывается

public class DialogManager : MonoBehaviour
{
    public Text dialogueText;
    public Text nameText;

    public Animator boxAnim;
    public Animator startAnim;


    private Queue<string> senteces;


    private void Start()
    {
        senteces = new Queue<string>();
    }

    // функция вызова диалога
    public void StartDialog(Dialog dialog)
    {
        boxAnim.SetBool("DialogBox", true); 
        startAnim.SetBool("StartOpen", false); // окно начать диалог закрыть

        nameText.text = dialog.name;
        senteces.Clear(); // очитска приложения

        foreach(string sentence in dialog.sentences)
        {
            senteces.Enqueue(sentence); // ставим в очередь предложения
        }

        DisplayNextSentence();
    }


    public void DisplayNextSentence()
    {

        if (senteces.Count == 0)
        {
            EndDialog();
            return;
        }
        string sentence = senteces.Dequeue(); // строка/предолежние удаляется из очереди
        StopAllCoroutines();
        StartCoroutine(TypeSentence(sentence));
    }


    // интерфейс для последовательного появления букв

    IEnumerator TypeSentence(string sentence)
    {
        dialogueText.text = ""; // текст диалога

        // цикл для каждой буквы в предложении
        foreach(char letter in sentence.ToCharArray())
        {
            dialogueText.text += letter;
            yield return null;

        }
    }

    // функция закрытия диалогового окна
    public void EndDialog()
    {
        boxAnim.SetBool("DialogBox", false);
    }

}
