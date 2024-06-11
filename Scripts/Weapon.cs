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

            Shoot();   // при нажатие кнопки будет выполнятся метод стрельба
            
        }

        void Shoot()  // логика стрельбы
        {

            Instantiate(arrowprefab, arrows.position, arrows.rotation);

        }
    }
}
