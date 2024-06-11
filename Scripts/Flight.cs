using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Flight : Entity
{
    [SerializeField] private int lives = 3;

    private void OnCollisionEnter2D(Collision2D collision) // при столкнавение с игроком будет сам домажить и сам терять хп
    {
        if(collision.gameObject==Hero.Instance.gameObject)
        {
            Hero.Instance.GetDamage();
            lives--;
            Debug.Log("У глазика" + lives);
        }
        if (lives<1)
            Die();
    }
}
