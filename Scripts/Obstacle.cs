using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Obstacle : MonoBehaviour
{


    public int hp = 4; // ��������
    public GameObject deathEffect;
    public void TakeDamage(int damage) // ������� ��� ��������� �����
    {
        hp -= damage;
        if (hp <= 0)
        {
            Die();
        }

    }

    void Die() // ������
    {
        Instantiate(deathEffect, transform.position, Quaternion.identity);
        Destroy(gameObject);
    }



    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject == Hero.Instance.gameObject)
        {
            Hero.Instance.GetDamage();
        }
    }
}
