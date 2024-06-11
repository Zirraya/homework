using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Attack_Player : MonoBehaviour
{
    public Animator anim;

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Mouse0))
        {
            Attack();
        }
    }
     void Attack()
    {
        anim.SetTrigger("attack");

    }
}
