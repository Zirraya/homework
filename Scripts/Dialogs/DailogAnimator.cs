using System.Collections;
using System.Collections.Generic;
using UnityEngine;


// ������ ��� ������� ������� ����� � ����������
public class DailogAnimator : MonoBehaviour
{
    public Animator startAnim;
    public DialogManager dm;


    // ������� ��������, ����� ����� ������ � ���� NPC

    public void OnTriggerEnter2D(Collider2D other)
    {
        startAnim.SetBool("StartOpen", true);

    }

    // ������� ��������� ������
    public void OnTriggerExit2D(Collider2D other)
    {
        startAnim.SetBool("StartOpen", false);
        dm.EndDialog();
    }


}
