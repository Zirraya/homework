using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI; // ���������� �����, ��� �� ������ ����� �����, ������� �����������

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

    // ������� ������ �������
    public void StartDialog(Dialog dialog)
    {
        boxAnim.SetBool("DialogBox", true); 
        startAnim.SetBool("StartOpen", false); // ���� ������ ������ �������

        nameText.text = dialog.name;
        senteces.Clear(); // ������� ����������

        foreach(string sentence in dialog.sentences)
        {
            senteces.Enqueue(sentence); // ������ � ������� �����������
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
        string sentence = senteces.Dequeue(); // ������/����������� ��������� �� �������
        StopAllCoroutines();
        StartCoroutine(TypeSentence(sentence));
    }


    // ��������� ��� ����������������� ��������� ����

    IEnumerator TypeSentence(string sentence)
    {
        dialogueText.text = ""; // ����� �������

        // ���� ��� ������ ����� � �����������
        foreach(char letter in sentence.ToCharArray())
        {
            dialogueText.text += letter;
            yield return null;

        }
    }

    // ������� �������� ����������� ����
    public void EndDialog()
    {
        boxAnim.SetBool("DialogBox", false);
    }

}
