using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Weapon : MonoBehaviour
{
   
    public Transform arrows;
    public GameObject arrowprefab;

    void Update()
    {
        if (Input.GetButtonDown("Fire1"))
        {

            Shoot();   // ��� ������� ������ ����� ���������� ����� ��������
            
        }

        void Shoot()  // ������ ��������
        {

            Instantiate(arrowprefab, arrows.position, arrows.rotation);

        }
    }
}
