using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Camera : MonoBehaviour
{


    public float FollowSpeed = 2f;
    public float yOffset = 1f;
    public Transform target;

    // Update is called once per frame
    void Update()
    {
        Vector3 newPos = new Vector3(target.position.x, target.position.y + yOffset, -10f);
        transform.position = Vector3.Slerp(transform.position, newPos, FollowSpeed * Time.deltaTime);
    }



    /* [SerializeField] private Transform player;
     private Vector3 pos; // координаты движения

     private void Awake() // в этом методе ищем игрока
     {
         if (!player)
         {
             player = FindObjectOfType<Hero>().transform;
         }
     }
     private void Update() // в этом методе мы получаем координаты игрока
     {
         pos = player.position;
         pos.z = -10f; // фиксация координаты для того чтобы камера не находилась в одной плосоксти с игроком


         transform.position = Vector3.Lerp(transform.position, pos, Time.deltaTime);
     }
    */
}
