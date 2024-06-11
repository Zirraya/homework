using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Entity : MonoBehaviour
{
    protected int lives;
    public virtual void GetDamage()
    {
        lives--;
        if (lives <0 )
        {
            Die();
        }

    }

    public virtual void Die()
    {
        Destroy(this.gameObject);
    }
}
